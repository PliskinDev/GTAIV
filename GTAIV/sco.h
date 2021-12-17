#include <stdint.h>
#include <ctype.h>
#include "scrprogram.h"
#include "scrthread.h"

struct OpcodeDesc
{
	const char* InstructionName;
	uint32_t InstructionLength;

} ops[156] = {
	{ "nop", 1 }, //0 - skip command, switch page if necessary
	{ "iadd", 1 }, //1 - integer +, stack operands
	{ "isub", 1 }, //2 - integer - , stack operands
	{ "imul", 1 }, //3 - integer *, stack operands
	{ "idiv", 1 }, //4 - integer /, stack operands
	{ "imod", 1 }, //5 - integer %, stack operands
	{ "inot", 1 }, //6 - checks the first item on the stack to see if it equals 0
	{ "ineg", 1 }, //7 - reverses the sign on the item on the top of the stack
	{ "ieq", 1 }, //8 - compares the top 2 integers on the stack to see if they are equal 
	{ "ine", 1 }, //9 - compares the top 2 integers on the stack to see if they are not equal 
	{ "igt", 1 }, //10 - compares the top 2 integers on the stack to see if the first one is greater than the second one
	{ "ige", 1 }, //11 - Compares the top 2 integers on the stack to see if the first one is greater than or equal to the second one
	{ "ilt", 1 }, //12 - compares the top 2 integers on the stack to see if the first one is less than the second one
	{ "ile", 1 }, //13 - compares the top 2 integers on the stack to see if the first one is less than or equal to the second one
	{ "fadd", 1 }, //14 - adds the top 2 floats on the stack 
	{ "fsub", 1 }, //15 - subtracts the top 2 floats on the stack
	{ "fmul", 1 }, //16 - multiplies the top 2 floats on the stack
	{ "fdiv", 1 }, //17 - divides the top 2 floats on the stack 
	{ "fmod", 1 }, //18 - mods the top 2 floats on the stack 
	{ "fneg", 1 }, //19 - reverses the sign on the first float on the stack 
	{ "feq", 1 }, //20 - compares the top 2 floats on the stack to see if they are equal 
	{ "fne", 1 }, //21 - compares the top 2 floats on the stack to see if they are not equal
	{ "fgt", 1 }, //22 - compares the top 2 floats on the stack to see if the first one is greater than the second one
	{ "fge", 1 }, //23 - compares the top 2 floats on the stack to see if the first one is greater than or equal to the second one
	{ "flt", 1 }, //24 - compares the top 2 floats on the stack to see if the first one is less than the second one 
	{ "fle", 1 }, //25 - compares the top 2 floats on the stack to see if the first one is less than or equal to the second one 
	{ "vadd", 1 }, //26 - adds the top 2 vectors[1] on the stack
	{ "vsub", 1 }, //27 - subtracts the top 2 vectors[1] on the stack 
	{ "vmul", 1 }, //28 - multiplies the top 2 vectors[1] on the stack
	{ "vdiv", 1 }, //29 - divides the top 2 vectors[1] on the stack
	{ "vneg", 1 }, //30 - reverses the sign on the first vector[1] on the stack 
	{ "iand", 1 }, //31 - performs an And operation to the first 2 integers on the stack
	{ "ior", 1 }, //32 - performs an Or operation to the first 2 integers on the stack
	{ "ixor", 1 }, //33 - performs a Xor operation to the first 2 integers on the stack
	{ "j", 5 }, //34 - jumps to a section of code, using the next 4 bytes after the opcode as a placemen
	{ "jz", 5 }, //35 - jumps to a section of code if the top of the stack is 0, using the next 4 bytes after the opcode as a placement
	{ "jnz", 5 }, //36 - jumps to a section of code if the top of the stack is 1, using the next 4 bytes after the opcode as a placement
	{ "i2f", 1 }, //37 - converts the top integer on the stack to a float, and puts that float on the stack 
	{ "f2i", 1 }, //38 - converts the top float on the stack to an integer, and puts that integer on the stack 
	{ "f2v", 1 }, //39 - converts the top float into a vector[1] containing 3 instances of the same float, and pushes the pointer to that Vector[1] onto the top of the stack
	{ "push_const_u16", 3 }, //40 - pushes a short onto the stack, the short is defined in the next 2 bytes after the opcode 
	{ "push_const_u32", 5 }, //41 - pushes an int onto the stack, the integer is defined in the next 4 bytes after the opcode  
	{ "push_const_f", 5 }, //42 - pushes a float onto the stack, the float is defined in the next 4 bytes after the opcode. performs exactly the same as push
	{ "dup", 1 }, //43 - duplicates the first item on the stack, and pushes it back onto the stack
	{ "drop", 1 }, //44 - pops the top item off the stack 
	{ "native", 7 }, //45 - calls a native function. the number of arguments for the native to take is defined in the next byte after the opcode.the number of return values is defined in the byte after that(it is always 1 or 0).The next 4 bytes are the hash of the native's name
	{ "call", 5 }, //46 - calls a function within the script, and puts the return address on top of the stack. the location of the function is defined in the next 4 bytes after the opcode
	{ "enter", 4 }, //47 - calls a function within the script, and puts the return address on top of the stack. the location of the function is defined in the next 4 bytes after the opcode
	{ "leave", 3 }, //48
	{ "load", 1 }, //49 pops a pointer off the stack and pushes the value stored in that pointer back onto the stack
	{ "store", 1 }, //50 pops 2 items off the stack and stores the second item at the location of the first item (the first item being a pointer)
	{ "store_rev", 1 }, //51 - pops the first item off the stack and peeks at the second item on the stack
	{ "array_load", 1 }, //52 - pops 2 items off the stack
	{ "array_store ", 1 }, //53 - pops 2 items off the stack
	{ "loacal_0 ", 1 }, //54 - pushes the pointer to the first function local variable onto the stack.
	{ "loacal_1 ", 1 }, //55 - pushes the pointer to the second function local variable onto the stack.
	{ "loacal_2 ", 1 }, //56 - pushes the pointer to the third function local variable onto the stack.
	{ "loacal_3 ", 1 }, //57 - pushes the pointer to the fourth function local variable onto the stack.
	{ "loacal_4 ", 1 }, //58 - pushes the pointer to the fifth function local variable onto the stack.
	{ "loacal_5 ", 1 }, //59 - pushes the pointer to the sixth function local variable onto the stack.
	{ "loacal_6 ", 1 }, //60 - pushes the pointer to the seventh function local variable onto the stack.
	{ "loacal_7 ", 1 }, //61 - pushes the pointer to the eigth function local variable onto the stack.
	{ "loacal ", 1 }, //62 - pushes the pointer to a function local variable onto the stack where the index is above or equal to 8
	{ "static ", 1 }, //63 - pops the index of the static variable off the stack
	{ "global ", 1 }, //64 - pops the index of the global variable off the stack
	{ "array ", 1 }, //65 - pops the array location, element size and index off the stack
	{ "switch ", 8 }, //66 - pops the item to compare off the stack
	{ "string ", 3 }, //67 - pshes a string onto the stack
	{ "null ", 3 }, //68 - pshes a string onto the stack
	{ "text_label_assign_string ", 1 }, //69 - pops 2 pointers off the stack and copies the second item to the first item
	{ "text_label_assign_int", 1 }, //70 - pops an integer off the stack and pushes an array to a string representation of that integer onto the stack
	{ "text_label_append_string", 1 }, //71 - pops 2 pointers off the stack, and appends the second item to the first item 
	{ "text_label_append_int", 1 }, //72 - pops 2 items off the stack, and performs a IntToStr on the second item (the integer), then appends that string representation to the first item 
	{ "catch ", 1 }, //73 - sets up a safe area that has the ability to catch errors
	{ "throw ", 1 }, //74 - indicates an area that handles a script error relative to the catch opcode 
	{ "text_label_copy ", 1 }, //75 - pops 3 items off the stack
	{ "exit ", 1 }, //76 - terminates the script under an error condition
	{ "push_const_u8 ", 1 } //77 - pushes an integer onto the stac	
};

enum opCodes
{
	nop = 0,
	iadd = 1,
	isub = 2,
	imul = 3,
	idiv = 4,
	imod = 5,
	inot = 6,
	ineg = 7,
	ieq = 8,
	ine = 9,
	igt = 10,
	ige = 11,
	ilt = 12,
	ile = 13,
	fadd = 14,
	fsub = 15,
	fmul = 16,
	fdiv = 17,
	fmod = 18,
	fneg = 19,
	feq = 20,
	fne = 21,
	fgt = 22,
	fge = 23,
	flt = 24,
	fle = 25,
	vadd = 26,
	vsub = 27,
	vmul = 28,
	vdiv = 29,
	vneg = 30,
	iand = 31,
	ior = 32,
	ixor = 33,
	_j = 34,
	jz = 35,
	jnz = 36,
	i2f = 37,
	f2i = 38,
	f2v = 39,
	push_const_u16 = 40,
	push_const_u32 = 41,
	push_const_f = 42,
	_dup = 43,
	_drop = 44,
	_native = 45,
	_call = 46,
	_enter = 47,
	_Leave = 48,
	_load = 49,
	_store = 50,
	store_rev = 51,
	array_load = 52,
	array_store = 53,
	loacal_0 = 54,
	loacal_1 = 55,
	loacal_2 = 56,
	loacal_3 = 57,
	loacal_4 = 58,
	loacal_5 = 59,
	loacal_6 = 60,
	loacal_7 = 61,
	loacal = 62,
	_static = 63,
	_global = 64,
	_array = 65,
	_switch = 66,
	_string = 67,
	_Null = 68,
	_text_label_assign_string = 69,
	_text_label_assign_int = 70,
	_text_label_append_string = 71,
	_text_label_append_int = 72,
	_catch = 73,
	_throw = 74,
	text_label_copy = 75,
	_exit = 76,
	_push_const_u8 = 77
};