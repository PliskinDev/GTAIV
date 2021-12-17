/*credit mizdx*/
/*Special thanks to therouletteboi <3*/

#include "stdafx.h"
#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/process.h>
#include <cell/cell_fs.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <string.h>
#include "enums.h"
#include "natives.h"
#include "sco.h"

#pragma region System
SYS_MODULE_INFO( GTAIV, 0, 1, 1);
SCE_MODULE_START(PRX_START);
SYS_MODULE_STOP(PRX_STOP);
#pragma endregion

#pragma region Internals
int32_t write_process(void* des, const void* data, size_t size)
{
	system_call_6(8, 30583, 50, (uint64_t)sys_process_getpid(), (uint64_t)des, (uint64_t)data, (uint64_t)size);
	return_to_user_prog(int32_t);	
}

void PatchProcess(uint64_t Address, int Destination, bool Linked)
{
	int FuncBytes[4];													
	Destination = *(int*)Destination;									
	FuncBytes[0] = 0x3D600000 + ((Destination >> 16) & 0xFFFF);			
	if (Destination & 0x8000)											
		FuncBytes[0] += 1;
	FuncBytes[1] = 0x396B0000 + (Destination & 0xFFFF);					
	FuncBytes[2] = 0x7D6903A6;											
	FuncBytes[3] = 0x4E800420;											
	if (Linked)
		FuncBytes[3] += 1;												
	write_process((void*)Address, FuncBytes, 4 * 4);
	memcpy((void*)Address, FuncBytes, 4 * 4);
}
#pragma endregion

#pragma region Sleep
void usleep(usecond_t time)
{
	sys_timer_usleep(time);
}

void sleep(second_t time)
{
	sys_timer_sleep(time);
}
#pragma endregion


#pragma region Print
void print(const char* fmt, int sec, ...)
{
	char buffer[256];
	va_list args;
	va_start(args, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);
	UI::PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", buffer, 5000, true);
	SYSTEM::WAIT(sec);
}
#pragma endregion

#pragma region Setup
bool Setup()
{
	//test native 
	if (CONTROLS::IS_BUTTON_PRESSED(0, BUTTON_X) && CONTROLS::IS_BUTTON_JUST_PRESSED(0, DPAD_LEFT))
	{
		print("Hello World From Sprx!", 30000);
	}
	return true;
}
#pragma endregion

void Thread()
{
	usleep(30000);
	PatchProcess(0x745490, (int)Setup, false);//iS_CHAR_ARMED
	sys_ppu_thread_exit(0);
}

#pragma region Thread
sys_ppu_thread_t ThreadID = SYS_PPU_THREAD_ID_INVALID;
CDECL_BEGIN 
int PRX_START(int argc, char* argv[])
{
	sys_ppu_thread_create(&ThreadID, [](uint64_t PRX_RUN)
	{
		sys_ppu_thread_get_id(&ThreadID);
		Thread();
	}, 0, 10, 0x10, SYS_PPU_THREAD_CREATE_JOINABLE, "GTAIV");
	return 0;
}

int PRX_STOP(int argc, char* argv[])
{
	uint64_t PRX_EXIT;
	sys_ppu_thread_join(ThreadID, &PRX_EXIT);
	sys_ppu_thread_exit(PRX_EXIT);
	return 0;
}
CDECL_END
#pragma endregion
