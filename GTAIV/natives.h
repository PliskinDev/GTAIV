#pragma once
#include "exports.h"

typedef struct Scrvec_t
{
	float x, y, z, h;
}Scrvec_t;

struct ScrArgs_t
{
	int* ReturnValue;
	uint32_t ArgCount;
	int* ArgValues;
	uint32_t ReadCount;
	float* f[4];
	Scrvec_t sc[4];
};

void ScrContext(ScrArgs_t* NativeContext)
{
	if (NativeContext->ReadCount != 0)
	{
		while (NativeContext->ReadCount != 0)
		{
			int vectorCount = NativeContext->ReadCount - 1;
			NativeContext->ReadCount--;
			NativeContext->f[vectorCount][0] = NativeContext->sc[vectorCount].x;
			NativeContext->f[vectorCount][1] = NativeContext->sc[vectorCount].y;
			NativeContext->f[vectorCount][2] = NativeContext->sc[vectorCount].z;
		}
	}
	NativeContext->ReadCount--;
}

static ScrArgs_t ScrArgs;

void ResetArgs()
{
	ScrArgs.ArgCount = 0;
	ScrArgs.ReadCount = 0;
	ScrArgs.ArgValues = (int*)0x10080000;
	ScrArgs.ReturnValue = ScrArgs.ArgValues;
}

template<typename T>
void PushArg(T Value)
{
	if (sizeof(T) <= 4)
	{
		*(T*)&ScrArgs.ArgValues[ScrArgs.ArgCount] = Value;
		ScrArgs.ArgCount++;
	}
}

template<typename R>
R GetReturn()
{
	R* Result;
	Result = (R*)&ScrArgs.ReturnValue[0];
	return *(R*)Result;
}

uint32_t ScrTable(uint32_t hash)
{
	uint32_t htp = 0x17D1438;
	uint32_t m = *(uint32_t*)0x17D143C;
	int ind = hash % m;
	uint32_t hta = *(uint32_t*)htp;
	uint32_t nh = hash;
	if (m == 0)
		return 0;
	for (uint32_t i = *(uint32_t*)(hta + 8 * ind); i > 1; i = *(uint32_t*)(hta + 8 * ind))
	{
		if (i == hash)
			break;
		nh = (nh >> 1) + 1;
		ind = (nh + ind) % m;
	}
	if (*(uint32_t*)(hta + 8 * ind + 4) != 0 && *(uint32_t*)(hta + 8 * ind + 4) != 0xCDCDCDCD)
		return *(uint32_t*)(hta + 8 * ind + 4);
	else
		return 0;
}

void ScrHash(uint32_t hash, ScrArgs_t* pArg)
{
	uint32_t i = ScrTable(hash);
	while (i != 0)
	{
		((void(*)(ScrArgs_t*))i)(pArg);
		ScrContext(pArg);
		return;
	}
}

template<typename T>
T invoke(uint32_t NativeHash)
{
	ResetArgs();
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1>
T invoke(uint32_t NativeHash, P1 p0)
{
	ResetArgs();
	PushArg(p0);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2>
T invoke(uint32_t NativeHash, P1 p0, P2 p1)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	PushArg(p17);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	PushArg(p17);
	PushArg(p18);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	PushArg(p17);
	PushArg(p18);
	PushArg(p19);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	PushArg(p17);
	PushArg(p18);
	PushArg(p19);
	PushArg(p20);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	PushArg(p17);
	PushArg(p18);
	PushArg(p19);
	PushArg(p20);
	PushArg(p21);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	PushArg(p17);
	PushArg(p18);
	PushArg(p19);
	PushArg(p20);
	PushArg(p21);
	PushArg(p22);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	PushArg(p17);
	PushArg(p18);
	PushArg(p19);
	PushArg(p20);
	PushArg(p21);
	PushArg(p22);
	PushArg(p23);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	PushArg(p17);
	PushArg(p18);
	PushArg(p19);
	PushArg(p20);
	PushArg(p21);
	PushArg(p22);
	PushArg(p23);
	PushArg(p24);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25, typename P26>
T invoke(uint32_t NativeHash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24, P26 p25)
{
	ResetArgs();
	PushArg(p0);
	PushArg(p1);
	PushArg(p2);
	PushArg(p3);
	PushArg(p4);
	PushArg(p5);
	PushArg(p6);
	PushArg(p7);
	PushArg(p8);
	PushArg(p9);
	PushArg(p10);
	PushArg(p11);
	PushArg(p12);
	PushArg(p13);
	PushArg(p14);
	PushArg(p15);
	PushArg(p16);
	PushArg(p17);
	PushArg(p18);
	PushArg(p19);
	PushArg(p20);
	PushArg(p21);
	PushArg(p22);
	PushArg(p23);
	PushArg(p24);
	PushArg(p25);
	ScrHash(NativeHash, &ScrArgs);
	return GetReturn<T>();
}



namespace SYSTEM
{
	static int TIMERA() { return invoke<int>(0x45C8C188); }
	static int TIMERB() { return invoke<int>(0x330A9C0C); }
	static void SETTIMERA(int value) { invoke<Void>(0x35785333, value); }
	static void SETTIMERB(int value) { invoke<Void>(0x27C1B7C6, value); }
	static float TIMESTEP() { return invoke<float>(0x50597EE2); }
	static float TIMESTEPUNWARPED() { return invoke<float>(0x99B02B53); }
	static void WAIT(int time) { invoke<Void>(0x7715C03B, time); }
	static void WAITUNWARPED(int time) { invoke<Void>(0x01185F9B, time); }
	static void WAITUNPAUSED(int time) { invoke<Void>(0x7C496803, time); }
	static void PRINTSTRING(const char* str) { invoke<Void>(0xECF8EB5F, str); }
	static void PRINTFLOAT(float value) { invoke<Void>(0xD48B90B6, 1, value); }
	static void PRINTFLOAT2(int num, int dec, float value) { invoke<Void>(0x3983593A, num, dec, value); }
	static void PRINTINT(int value) { invoke<Void>(0x63651F03, value); }
	static void PRINTINT2(int places, int value) { invoke<Void>(0x83B2E331, places, value); }
	static void PRINTNL() { invoke<Void>(0x868997DA, 0); }
	static void PRINTVECTOR(float x, float y, float z) { invoke<Void>(0x085F31FB, x, y, z); }
	static void BREAKPOINT() { invoke<Void>(0xEFEAFB91); }
	static float ABSF(float value) { return invoke<float>(0xAF6F6E0B, value); }
	static float ABSI(float value) { return invoke<float>(0xB44677C5, value); }
	static float ACOS(float p0) { return invoke<float>(0xF4038776, p0); }
	static float ATAN(float value) { return invoke<float>(0x7A03CC8E, value); }
	static int SHIFT_LEFT(int value, int bitShift) { return invoke<int>(0x314CC6CD, value, bitShift); }
	static int SHIFT_RIGHT(int value, int bitShift) { return invoke<int>(0x352633CA, value, bitShift); }
	static int START_NEW_SCRIPT(char* ScriptName, int StackSize) { return invoke<int>(0x3F166D0E, ScriptName, StackSize); }
	static int START_NEW_SCRIPT_WITH_ARGS(char* ScriptName, Any* Args, int Count, int Stacksize) { return invoke<int>(0x4A2100E4, ScriptName, Args, Count, Stacksize); }
	static int FLOOR(float value) { return invoke<int>(0x32E9BE04, value); }
	static int CEIL(float value) { return invoke<int>(0xD536A1DF, value); }
	static int ROUND(float value) { return invoke<int>(0x323B0E24, value); }
	static float TO_FLOAT(int value) { return invoke<float>(0x67116627, value); }
	static void CLEAR_TEXT_LABEL(const char* Textlabel) { invoke<Void>(0xA66AAE8F, Textlabel); }
	static int GET_LATEST_CONSOLE_COMMAND() { return invoke<int>(0x2B547FE6); }
	static void RESET_LATEST_CONSOLE_COMMAND() { invoke<Void>(0xAA3EC981); }
	static int GET_CONSOLE_COMMAND_TOKEN() { return invoke<int>(0x9DE3DE24); }
	static int GET_NUM_CONSOLE_COMMAND_TOKENS() { return invoke<int>(0x608F5BC6); }

	
}

namespace CHAR
{
	static BOOL ARE_ANY_CHARS_NEAR_CHAR(Ped ped, float radius) { return invoke<BOOL>(0x246D0C7B, ped, radius); }
	static BOOL CAN_CHAR_SEE_DEAD_CHAR(Ped ped, Ped pednext) { return invoke<BOOL>(0x314D38E0, ped, pednext); }
	static BOOL CELL_CAM_IS_CHAR_VISIBLE(Ped ped) { return invoke<BOOL>(0x1FD07F61, ped); }
	static BOOL CELL_CAM_IS_CHAR_VISIBLE_NO_FACE_CHECK(Ped ped) { return invoke<BOOL>(0xBEA88097, ped); }
	static BOOL DOES_CHAR_EXIST(Ped ped) { return invoke<BOOL>(0xBBD7272C, ped); }
	static BOOL GET_CHAR_ALLOWED_TO_RUN_ON_BOATS(Ped ped) { return invoke<BOOL>(0xA1EED2EB, ped); }
	static BOOL GET_CHAR_ANIM_IS_EVENT(Ped ped, const char* AnimName0, const char* AnimName1, BOOL flag) { return invoke<BOOL>(0xF1EB1F61, ped, AnimName0, AnimName1, flag); }
	static BOOL GET_CHAR_MELEE_ACTION_FLAG0(Ped ped) { return invoke<BOOL>(0x06254A30, ped); }
	static BOOL GET_CHAR_MELEE_ACTION_FLAG1(Ped ped) { return invoke<BOOL>(0x13EC65BE, ped); }
	static BOOL GET_CHAR_MELEE_ACTION_FLAG2(Ped ped) { return invoke<BOOL>(0x29AA1139, ped); }
	static BOOL GET_CHAR_MOVEMENT_ANIMS_BLOCKED(Ped ped) { return invoke<BOOL>(0xD6B1D03C, ped); }
	static BOOL GET_CHAR_READY_TO_BE_EXECUTED(Ped ped) { return invoke<BOOL>(0xAC5A20AE, ped); }
	static BOOL GET_CHAR_READY_TO_BE_STUNNED(Ped ped) { return invoke<BOOL>(0xBAED4873, ped); }
	static BOOL GET_CHAR_SWIM_STATE(Ped ped, int* state) { return invoke<BOOL>(0xB07D365C, ped, state); }
	static BOOL GET_CHAR_WALK_ALONGSIDE_LEADER_WHEN_APPROPRIATE(Ped ped) { return invoke<BOOL>(0x3CEF9E7B, ped); }
	static BOOL GET_CHAR_WILL_COWER_INSTEAD_OF_FLEEING(Ped ped) { return invoke<BOOL>(0x1EE1EB44, ped); }
	static BOOL GET_CHAR_WILL_TRY_TO_LEAVE_BOAT_AFTER_LEADER(Ped ped) { return invoke<BOOL>(0x75834B75, ped); }
	static BOOL GET_CHAR_WILL_TRY_TO_LEAVE_WATER(Ped ped) { return invoke<BOOL>(0xA2984974, ped); }
	static BOOL GET_CLOSEST_CHAR(float x, float y, float z, float radius, BOOL unknown1, BOOL unknown2, Ped* ped) { return invoke<BOOL>(0x19EAD428, x, y, z, radius, unknown1, unknown2, ped); }
	static BOOL GET_GROUP_CHAR_DUCKS_WHEN_AIMED_AT(Ped ped) { return invoke<BOOL>(0x090E9103, ped); }
	static BOOL HAS_CAR_BEEN_DAMAGED_BY_CHAR(Vehicle vehicle, Ped ped) { return invoke<BOOL>(0xA07E4E19, vehicle, ped); }
	static BOOL HAS_CHAR_ANIM_FINISHED(Ped ped, const char* AnimName0, const char* AnimName1) { return invoke<BOOL>(0x100BC2C0, ped, AnimName0, AnimName1); }
	static BOOL HAS_CHAR_BEEN_ARRESTED(Ped ped) { return invoke<BOOL>(0xE01AB5E0, ped); }
	static BOOL HAS_CHAR_BEEN_DAMAGED_BY_CHAR(Ped ped, Ped otherChar, BOOL unknownFalse) { return invoke<BOOL>(0xFECBA916, ped, otherChar, unknownFalse); }
	static BOOL HAS_CHAR_BEEN_PHOTOGRAPHED(Ped ped) { return invoke<BOOL>(0x23B55D72, ped); }
	static BOOL HAS_CHAR_SPOTTED_CHAR(Ped ped, Ped otherChar) { return invoke<BOOL>(0xFFF5F5E3, ped, otherChar); }
	static BOOL HAS_CHAR_SPOTTED_CHAR_IN_FRONT(Ped ped, Ped otherChar) { return invoke<BOOL>(0x57723144, ped, otherChar); }
	static BOOL IS_ANY_CHAR_SHOOTING_IN_AREA(float x0, float y0, float z0, float x1, float y1, float z1, BOOL flag) { return invoke<BOOL>(0x99E5D601, x0, y0, z0, x1, y1, z1, flag); }
	static BOOL IS_CHAR_ARMED(Ped ped, int slot) { return invoke<BOOL>(0x1883D91E, ped, slot); }
	static BOOL IS_CHAR_DEAD(Ped ped) { return invoke<BOOL>(0x931F73A2, ped); }
	static BOOL IS_CHAR_DUCKING(Ped ped) { return invoke<BOOL>(0x6EE9A4B7, ped); }
	static BOOL IS_CHAR_FACING_CHAR(Ped ped, Ped otherChar, float angle) { return invoke<BOOL>(0x10C14E5B, ped, otherChar, angle); }
	static BOOL IS_CHAR_FATALLY_INJURED(Ped ped) { return invoke<BOOL>(0x3305879E, ped); }
	static BOOL IS_CHAR_GESTURING(Ped ped) { return invoke<BOOL>(0x7B6EE700, ped); }
	static BOOL IS_CHAR_GETTING_IN_TO_A_CAR(Ped ped) { return invoke<BOOL>(0x9002C89C, ped); }
	static BOOL IS_CHAR_GETTING_UP(Ped ped) { return invoke<BOOL>(0x815E1C7B, ped); }
	static BOOL IS_CHAR_HEALTH_GREATER(Ped ped, int health) { return invoke<BOOL>(0xB443F023, ped, health); }
	static BOOL IS_CHAR_INJURED(Ped ped) { return invoke<BOOL>(0x08A5BAD7, ped); }
	static BOOL IS_CHAR_IN_AIR(Ped ped) { return invoke<BOOL>(0x19570E25, ped); }
	static BOOL IS_CHAR_IN_ANGLED_AREA_2D(Ped ped, float x1, float y1, float x2, float y2, float unknown, BOOL unknownFalse) { return invoke<BOOL>(0x1BC6F044, ped, x1, y1, x2, y2, unknown, unknownFalse); }
	static BOOL IS_CHAR_IN_ANGLED_AREA_3D(Ped ped, float x1, float y1, float z1, float x2, float y2, float z2, float unknown, BOOL unknownFalse) { return invoke<BOOL>(0x8CDB510B, ped, x1, y1, z1, x2, y2, z2, unknown, unknownFalse); }
	static BOOL IS_CHAR_IN_ANY_BOAT(Ped ped) { return invoke<BOOL>(0xAA21C658, ped); }
	static BOOL IS_CHAR_IN_ANY_CAR(Ped ped) { return invoke<BOOL>(0x74C3E7A5, ped); }
	static BOOL IS_CHAR_IN_ANY_HELI(Ped ped) { return invoke<BOOL>(0x55977AE5, ped); }
	static BOOL IS_CHAR_IN_ANY_PLANE(Ped ped) { return invoke<BOOL>(0x0E089AA2, ped); }
	static BOOL IS_CHAR_IN_ANY_TRAIN(Ped ped) { return invoke<BOOL>(0xBA300A2C, ped); }
	static BOOL IS_CHAR_IN_AREA_2D(Ped ped, float x1, float y1, float x2, float y2, BOOL unknownFalse) { return invoke<BOOL>(0xD52BF398, ped, x1, y1, x2, y2, unknownFalse); }
	static BOOL IS_CHAR_IN_AREA_3D(Ped ped, float x1, float y1, float z1, float x2, float y2, float z2, BOOL unknownFalse) { return invoke<BOOL>(0x2AE68B0F, ped, x1, y1, z1, x2, y2, z2, unknownFalse); }
	static BOOL IS_CHAR_IN_AREA_ON_FOOT_2D(Ped ped, float x1, float y1, float x2, float y2, BOOL unknownFalse) { return invoke<BOOL>(0xC6655FF6, ped, x1, y1, x2, y2, unknownFalse); }
	static BOOL IS_CHAR_IN_FLYING_VEHICLE(Ped ped) { return invoke<BOOL>(0xB1E15F0A, ped); }
	static BOOL IS_CHAR_IN_MELEE_COMBAT(Ped ped) { return invoke<BOOL>(0x6258D814, ped); }
	static BOOL IS_CHAR_IN_TAXI(Ped ped) { return invoke<BOOL>(0x7C705F01, ped); }
	static BOOL IS_CHAR_IN_WATER(Ped ped) { return invoke<BOOL>(0xFFD4D14E, ped); }
	static BOOL IS_CHAR_MALE(Ped ped) { return invoke<BOOL>(0xAB2069FC, ped); }
	static BOOL IS_CHAR_MODEL(Ped ped, int model) { return invoke<BOOL>(0x5573709A, ped, model); }
	static BOOL IS_CHAR_ON_ANY_BIKE(Ped ped) { return invoke<BOOL>(0xCC7CEA5F, ped); }
	static BOOL IS_CHAR_ON_FIRE(Ped ped) { return invoke<BOOL>(0xEE1AD133, ped); }
	static BOOL IS_CHAR_ON_FOOT(Ped ped) { return invoke<BOOL>(0x84BD7342, ped); }
	static BOOL IS_CHAR_ON_SCREEN(Ped ped) { return invoke<BOOL>(0xABCF8B91, ped); }
	static BOOL IS_CHAR_PLAYING_ANIM(Ped ped, const char* animSet, const char* animName) { return invoke<BOOL>(0x07F23D94, ped, animSet, animName); }
	static BOOL IS_CHAR_RESPONDING_TO_ANY_EVENT(Ped ped) { return invoke<BOOL>(0xAC44BAEA, ped); }
	static BOOL IS_CHAR_RESPONDING_TO_EVENT(Ped ped, int eventid) { return invoke<BOOL>(0xEA839600, ped, eventid); }
	static BOOL IS_CHAR_SHOOTING(Ped ped) { return invoke<BOOL>(0x3FAB229B, ped); }
	static BOOL IS_CHAR_SHOOTING_IN_AREA(Ped ped, float x1, float y1, float x2, float y2, BOOL unknownFalse) { return invoke<BOOL>(0xF8DC76D9, ped, x1, y1, x2, y2, unknownFalse); }
	static BOOL IS_CHAR_SITTING_IDLE(Ped ped) { return invoke<BOOL>(0x49CBFA86, ped); }
	static BOOL IS_CHAR_SITTING_IN_ANY_CAR(Ped ped) { return invoke<BOOL>(0x94F78256, ped); }
	static BOOL IS_CHAR_SITTING_IN_CAR(Ped ped, Vehicle vehicle) { return invoke<BOOL>(0x12A0C9C2, ped, vehicle); }
	static BOOL IS_CHAR_STOPPED(Ped ped) { return invoke<BOOL>(0xEB4BE0F9, ped); }
	static BOOL IS_CHAR_STUCK_UNDER_CAR(Ped ped) { return invoke<BOOL>(0xB5C5016B, ped); }
	static BOOL IS_CHAR_SWIMMING(Ped ped) { return invoke<BOOL>(0xDD89EEE8, ped); }
	static BOOL IS_CHAR_TOUCHING_CHAR(Ped ped, Ped otherChar) { return invoke<BOOL>(0xB54E000C, ped, otherChar); }
	static BOOL IS_CHAR_TOUCHING_OBJECT(Ped ped, Object obj) { return invoke<BOOL>(0xFEFBD10A, ped, obj); }
	static BOOL IS_CHAR_TOUCHING_OBJECT_ON_FOOT(Ped ped, Object obj) { return invoke<BOOL>(0xF423C94D, ped, obj); }
	static BOOL IS_CHAR_TRYING_TO_ENTER_A_LOCKED_CAR(Ped ped) { return invoke<BOOL>(0x1932B71E, ped); }
	static BOOL IS_CHAR_USING_ANY_SCENARIO(Ped ped) { return invoke<BOOL>(0x85018DC2, ped); }
	static BOOL IS_CHAR_USING_MAP_ATTRACTOR(Ped ped) { return invoke<BOOL>(0x4DC5A039, ped); }
	static BOOL IS_CHAR_USING_SCENARIO(Ped ped, const char* scenarioName) { return invoke<BOOL>(0xB74C04F3, ped, scenarioName); }
	static BOOL IS_CHAR_VISIBLE(Ped ped) { return invoke<BOOL>(0xB632F152, ped); }
	static BOOL IS_CHAR_WAITING_FOR_WORLD_COLLISION(Ped ped) { return invoke<BOOL>(0x6919BEC0, ped); }
	static BOOL LOCATE_CHAR_ANY_MEANS_2D(Ped ped, float x0, float y0, float x1, float y1, BOOL flag) { return invoke<BOOL>(0xCECE7668, ped, x0, y0, x1, y1, flag); }
	static BOOL LOCATE_CHAR_ANY_MEANS_3D(Ped ped, float x0, float y0, float z0, float x1, float y1, float z1, BOOL flag) { return invoke<BOOL>(0x9D579293, ped, x0, y0, z0, x1, y1, z1, flag); }
	static BOOL LOCATE_CHAR_ANY_MEANS_CAR_2D(Ped ped, Vehicle car, float x, float y, BOOL flag) { return invoke<BOOL>(0x6B19C505, ped, car, x, y, flag); }
	static BOOL LOCATE_CHAR_ANY_MEANS_CAR_3D(Ped ped, Vehicle car, float x, float y, float z, BOOL flag) { return invoke<BOOL>(0x0C048594, ped, car, x, y, z, flag); }
	static BOOL LOCATE_CHAR_ANY_MEANS_OBJECT_2D(Ped ped, Object obj, float x, float y, BOOL flag) { return invoke<BOOL>(0xCADE3513, ped, obj, x, y, flag); }
	static BOOL LOCATE_CHAR_ANY_MEANS_OBJECT_3D(Ped ped, Object obj, float x, float y, float z, BOOL flag) { return invoke<BOOL>(0xAB5E74D0, ped, obj, x, y, z, flag); }
	static BOOL LOCATE_CHAR_IN_CAR_2D(Ped ped, float x0, float y0, float x1, float y1, BOOL flag) { return invoke<BOOL>(0x3B36C8CA, ped, x0, y0, x1, y1, flag); }
	static BOOL LOCATE_CHAR_IN_CAR_3D(Ped ped, float x0, float y0, float z0, float x1, float y1, float z, BOOL flag) { return invoke<BOOL>(0x653B9B9F, ped, x0, y0, z0, x1, y1, z, flag); }
	static BOOL LOCATE_CHAR_IN_CAR_CAR_2D(Ped ped, Vehicle car, float x, float y, BOOL flag) { return invoke<BOOL>(0x3D622186, ped, car, x, y, flag); }
	static BOOL LOCATE_CHAR_IN_CAR_CAR_3D(Ped ped, Vehicle car, float x, float y, float z, BOOL flag) { return invoke<BOOL>(0x4E3A44AE, ped, car, x, y, z, flag); }
	static BOOL LOCATE_CHAR_IN_CAR_CHAR_2D(Ped ped, Ped pednext, float x, float y, BOOL flag) { return invoke<BOOL>(0x84C30447, ped, pednext, x, y, flag); }
	static BOOL LOCATE_CHAR_IN_CAR_CHAR_3D(Ped ped, Vehicle pednext, float x, float y, float z, BOOL flag) { return invoke<BOOL>(0x2E3B5675, ped, pednext, x, y, z, flag); }
	static BOOL LOCATE_CHAR_IN_CAR_OBJECT_2D(Ped ped, Object obj, float x, float y, BOOL flag) { return invoke<BOOL>(0x3731AB0B, ped, obj, x, y, flag); }
	static BOOL LOCATE_CHAR_IN_CAR_OBJECT_3D(Ped ped, Object obj, float x, float y, float z, BOOL flag) { return invoke<BOOL>(0xCD395628, ped, obj, x, y, z, flag); }
	static BOOL LOCATE_CHAR_ON_FOOT_2D(Ped ped, float x0, float y0, float x1, float y1, BOOL flag) { return invoke<BOOL>(0xC7A21F12, ped, x0, y0, x1, y1, flag); }
	static BOOL LOCATE_CHAR_ON_FOOT_3D(Ped ped, float x0, float y0, float z0, float x1, float y1, float z1, BOOL flag) { return invoke<BOOL>(0x6F4E6448, ped, x0, y0, z0, x1, y1, z1, flag); }
	static BOOL LOCATE_CHAR_ON_FOOT_CAR_2D(Ped ped, Vehicle car, float x, float y, BOOL flag) { return invoke<BOOL>(0x8C1F0706, ped, car, x, y, flag); }
	static BOOL LOCATE_CHAR_ON_FOOT_CAR_3D(Ped ped, Vehicle car, float x, float y, float z, BOOL flag) { return invoke<BOOL>(0xAD774B26, ped, car, x, y, z, flag); }
	static BOOL LOCATE_CHAR_ON_FOOT_CHAR_2D(Ped ped, Ped pednext, float x, float y, BOOL flag) { return invoke<BOOL>(0x0BBBA114, ped, pednext, x, y, flag); }
	static BOOL LOCATE_CHAR_ON_FOOT_CHAR_3D(Ped ped, Ped pednext, float x, float y, float z, BOOL flag) { return invoke<BOOL>(0x70FF77E6, ped, pednext, x, y, z, flag); }
	static BOOL LOCATE_CHAR_ON_FOOT_OBJECT_2D(Ped ped, Object obj, float x, float y, BOOL flag) { return invoke<BOOL>(0xC3048EA7, ped, obj, x, y, flag); }
	static BOOL LOCATE_CHAR_ON_FOOT_OBJECT_3D(Ped ped, Object obj, float x, float y, float z, BOOL flag) { return invoke<BOOL>(0xB75DF3EA, ped, obj, x, y, z, flag); }
	static BOOL SET_CHAR_ANIM_PLAYING_FLAG(Ped ped, const char* AnimName0, const char* AnimName1, BOOL flag) { return invoke<BOOL>(0xE15F39A7, ped, AnimName0, AnimName1, flag); }
	static const char* GET_ANIM_GROUP_FROM_CHAR(Ped ped) { return invoke<const char*>(0xF547F9B8, ped); }
	static float GET_CHAR_MAX_MOVE_BLEND_RATIO(Ped ped) { return invoke<float>(0xEC13B27E, ped); }
	static int GET_CHAR_GRAVITY(Ped ped) { return invoke<int>(0xE67D2A53, ped); }
	static Any GET_CHAR_LAST_DAMAGE_BONE(Ped ped, uint32_t* pBone) { return invoke<Any>(0x35113CCC, ped, pBone); }
	static Any SET_CHAR_DUCKING(Ped ped, BOOL set) { return invoke<Any>(0xA7F1CD29, ped, set); }
	static Any TOGGLE_CHAR_DUCKING(Ped ped) { return invoke<Any>(0x3963EE08, ped); } 
	static uint32_t GET_CHAR_DRAWABLE_VARIATION(Ped ped, uint32_t component) { return invoke<uint32_t>(0xE03F58DC, ped, component); }
	static uint32_t GET_CHAR_MONEY(Ped ped) { return invoke<uint32_t>(0xFF316392, ped); }
	static uint32_t GET_CHAR_TEXTURE_VARIATION(Ped ped, uint32_t component) { return invoke<uint32_t>(0x99D0E550, ped, component); }
	static uint32_t GET_NUMBER_OF_CHAR_DRAWABLE_VARIATIONS(Ped ped, uint32_t component) { return invoke<uint32_t>(0xCBBB053E, ped, component); }
	static uint32_t GET_NUMBER_OF_CHAR_TEXTURE_VARIATIONS(Ped ped, uint32_t component, uint32_t unknown1) { return invoke<uint32_t>(0xC50F3611, ped, component, unknown1); }
	static void ADD_ARMOUR_TO_CHAR(Ped ped, uint32_t amount) { invoke<Void>(0xD74C40DD, ped, amount); }
	static void ATTACH_ANIMS_TO_MODEL(uint32_t model, const char* anims) { invoke<Void>(0xA1A55199, model, anims); }
	static void BEGIN_CHAR_SEARCH_CRITERIA() { invoke<Void>(0xC9ABF675); }
	static void BLEND_FROM_NM_WITH_ANIM(Ped ped, const char* AnimName0, const char* AnimName1, int Unk1, float x, float y, float z) { invoke<Void>(0x20840C07, ped, AnimName0, AnimName1, Unk1, x, y, z); }
	static void BLEND_OUT_CHAR_MOVE_ANIMS(Ped ped) { invoke<Void>(0xF7764CEC, ped); }
	static void BLOCK_CHAR_AMBIENT_ANIMS(Ped ped, BOOL block) { invoke<Void>(0x73FDA4F4, ped, block); }
	static void BLOCK_CHAR_GESTURE_ANIMS(Ped ped, BOOL value) { invoke<Void>(0xA14A7490, ped, value); }
	static void BLOCK_CHAR_HEAD_IK(Ped ped, BOOL block) { invoke<Void>(0x420E9796, ped, block); }
	static void BLOCK_CHAR_VISEME_ANIMS(Ped ped, BOOL block) { invoke<Void>(0x9B363732, ped, block); }
	static void CANCEL_CURRENTLY_PLAYING_AMBIENT_SPEECH(Ped ped) { invoke<Void>(0x4DBD473B, ped); }
	static void CHANGE_CHAR_SIT_IDLE_ANIM(Ped ped, Any Unk2, Any Unk3, Any Unk4) { invoke<Void>(0x2D56A131, ped, Unk2, Unk3, Unk4); }
	static void CLEAR_ALL_CHAR_PROPS(Ped ped) { invoke<Void>(0x34E7718E, ped); }
	static void CLEAR_ALL_CHAR_RELATIONSHIPS(Ped ped, int relgroup) { invoke<Void>(0xACF03FCE, ped, relgroup); }
	static void CLEAR_CHAR_LAST_DAMAGE_BONE(Ped ped) { invoke<Void>(0xB9C43E78, ped); }
	static void CLEAR_CHAR_LAST_DAMAGE_ENTITY(Ped ped) { invoke<Void>(0xA2544879, ped); }
	static void CLEAR_CHAR_LAST_WEAPON_DAMAGE(Ped ped) { invoke<Void>(0xE0586999, ped); }
	static void CLEAR_CHAR_PROP(Ped ped, BOOL unknown) { invoke<Void>(0xF7B017D7, ped, unknown); }
	static void CLEAR_CHAR_RELATIONSHIP(Ped ped, int reltype, int relgroup) { invoke<Void>(0xB4A1647B, ped, reltype, relgroup); }
	static void CLEAR_CHAR_SECONDARY_TASK(Ped ped) { invoke<Void>(0x14A1C15C, ped); }
	static void CLEAR_CHAR_TASKS(Ped ped) { invoke<Void>(0x91D81ADB, ped); }
	static void CLEAR_CHAR_TASKS_IMMEDIATELY(Ped ped) { invoke<Void>(0xB5087D44, ped); }
	static void CLEAR_RELATIONSHIP(int p0, int p1, int p2) { invoke<Void>(0x642A9FED, p0, p1, p2); }
	static void CLEAR_ROOM_FOR_CHAR(Ped ped) { invoke<Void>(0x91857B2B, ped); }
	static void CREATE_CHAR(eRelationshipGroup type, uint32_t model, float x, float y, float z, Ped *pPed, BOOL unknownTrue) { invoke<Void>(0x25646B4E, type, model, x, y, z, pPed, unknownTrue); }
	static void CREATE_CHAR_AS_PASSENGER(Vehicle vehicle, uint32_t charType, uint32_t model, uint32_t passengerIndex, Ped *pPed) { invoke<Void>(0x0C3394EA, vehicle, charType, model, passengerIndex, pPed); }
	static void CREATE_CHAR_INSIDE_CAR(Vehicle vehicle, uint32_t charType, uint32_t model, Ped *pPed) { invoke<Void>(0xCF2E377D, vehicle, charType, model, pPed); }
	static void CREATE_RANDOM_CHAR(float x, float y, float z, Ped *pPed) { invoke<Void>(0xE71EDE84, x, y, z, pPed); }
	static void CREATE_RANDOM_CHAR_AS_PASSENGER(Vehicle vehicle, uint32_t seat, Ped *pPed) { invoke<Void>(0xEB333516, vehicle, seat, pPed); }
	static void CREATE_RANDOM_FEMALE_CHAR(float x, float y, float z, Ped *pPed) { invoke<Void>(0x35247A8F, x, y, z, pPed); }
	static void CREATE_RANDOM_MALE_CHAR(float x, float y, float z, Ped *pPed) { invoke<Void>(0x9D0AA54A, x, y, z, pPed); }
	static void DAMAGE_CHAR(Ped ped, uint32_t hitPoints, BOOL unknown) { invoke<Void>(0xA8C84A28, ped, hitPoints, unknown); }
	static void DELETE_CHAR(Ped *pPed) { invoke<Void>(0xB99B8A04, pPed); }
	static void DONT_REMOVE_CHAR(Ped ped) { invoke<Void>(0x102EEAD5, ped); }
	static void END_CHAR_SEARCH_CRITERIA() { invoke<Void>(0x54F5474F); }
	static void EXPLODE_CHAR_HEAD(Ped ped) { invoke<Void>(0x6862B5AE, ped); }
	static void EXTINGUISH_CHAR_FIRE(Ped ped) { invoke<Void>(0x001F5DA5, ped); }
	static void FREEZE_CHAR_POSITION(Ped ped, BOOL frozen) { invoke<Void>(0x6410A13F, ped, frozen); }
	static void FREEZE_CHAR_POSITION_AND_DONT_LOAD_COLLISION(Ped ped, BOOL frozen) { invoke<Void>(0xD17D4854, ped, frozen); }
	static void GET_CHAR_ANIM_BLEND_AMOUNT(Ped ped, const char* AnimName0, const char* AnimName1, float* amount) { invoke<Void>(0xFE64EC90, ped, AnimName0, AnimName1, amount); }
	static void GET_CHAR_ANIM_CURRENT_TIME(Ped ped, const char* animGroup, const char* animName, float* pValue) { invoke<Void>(0x6AE57D9B, ped, animGroup, animName, pValue); }
	static void GET_CHAR_ANIM_TOTAL_TIME(Ped ped, const char* animGroup, const char* animName, float* pValue) { invoke<Void>(0x2B6EF5C9, ped, animGroup, animName, pValue); }
	static void GET_CHAR_ARMOUR(Ped ped, uint32_t* pArmour) { invoke<Void>(0x7FF4E3CE, ped, pArmour); }
	static void GET_CHAR_COORDINATES(Ped ped, float* pX, float* pY, float* pZ) { invoke<Void>(0xC5892F5F, ped, pX, pY, pZ); }
	static void GET_CHAR_EXTRACTED_DISPLACEMENT(Ped ped, BOOL unknown, float* pX, float* pY, float* pZ) { invoke<Void>(0xFF1CA4E4, ped, unknown, pX, pY, pZ); }
	static void GET_CHAR_EXTRACTED_VELOCITY(Ped ped, BOOL Unk5, float* x, float* y, float* z) { invoke<Void>(0xEA8D828C, ped, Unk5, x, y, z); }
	static void GET_CHAR_HEADING(Ped ped, float* pValue) { invoke<Void>(0x96843575, ped, pValue); }
	static void GET_CHAR_HEALTH(Ped ped, uint32_t* pHealth) { invoke<Void>(0xA1DFED67, ped, pHealth); }
	static void GET_CHAR_HEIGHT_ABOVE_GROUND(Ped ped, float* pValue) { invoke<Void>(0x3852A468, ped, pValue); }
	static void GET_CHAR_HIGHEST_PRIORITY_EVENT(Ped ped, int* event) { invoke<Void>(0xC7FACF9E, ped, event); }
	static void GET_CHAR_IN_CAR_PASSENGER_SEAT(Vehicle vehicle, uint32_t seatIndex, Ped *pPed) { invoke<Void>(0x2A0C5EE7, vehicle, seatIndex, pPed); }
	static void GET_CHAR_MODEL(Ped ped, uint32_t* pModel) { invoke<Void>(0x456B3E3A, ped, pModel); }
	static void GET_CHAR_MOVE_ANIM_SPEED_MULTIPLIER(Ped ped, float* multiplier) { invoke<Void>(0x47A9CCC3, ped, multiplier); }
	static void GET_CHAR_PROP_INDEX(Ped ped, BOOL unknown, uint32_t* pIndex) { invoke<Void>(0xCE1F5012, ped, unknown, pIndex); }
	static void GET_CHAR_SPEED(Ped ped, float* pValue) { invoke<Void>(0xA570E742, ped, pValue); }
	static void GET_CHAR_VELOCITY(Ped ped, float* pX, float* pY, float* pZ) { invoke<Void>(0xAFA40D33, ped, pX, pY, pZ); }
	static void GET_DEAD_CHAR_COORDINATES(Ped ped, float* pX, float* pY, float* pZ) { invoke<Void>(0x1298F033, ped, pX, pY, pZ); }
	static void GET_DEAD_CHAR_PICKUP_COORDS(Ped ped, float* pX, float* pY, float* pZ) { invoke<Void>(0x90DA4404, ped, pX, pY, pZ); }
	static void GET_KEY_FOR_CHAR_IN_ROOM(Ped ped, uint32_t* pKey) { invoke<Void>(0x41C87342, ped, pKey); }
	static void GET_OFFSET_FROM_CHAR_IN_WORLD_COORDS(Ped ped, float x, float y, float z, float* pOffX, float* pOffY, float* pOffZ) { invoke<Void>(0x9D90D752, ped, x, y, z, pOffX, pOffY, pOffZ); }
	static void MARK_CHAR_AS_NO_LONGER_NEEDED(Ped *pPed) { invoke<Void>(0xC808F143, pPed); }
	static void MODIFY_CHAR_MOVE_BLEND_RATIO(Ped ped, Any Unk6) { invoke<Void>(0x9A7B0ABE, ped, Unk6); }
	static void MODIFY_CHAR_MOVE_STATE(Ped ped, uint32_t state) { invoke<Void>(0x4874642A, ped, state); }
	static void REMOVE_CHAR_DEFENSIVE_AREA(Ped ped) { invoke<Void>(0x0F82A06E, ped); }
	static void REMOVE_CHAR_ELEGANTLY(Ped ped) { invoke<Void>(0x18604C77, ped); }
	static void REMOVE_CHAR_FROM_CAR_MAINTAIN_POSITION(Ped ped, Vehicle car) { invoke<Void>(0xD21FA802, ped, car); }
	static void REMOVE_CHAR_FROM_GROUP(Ped ped) { invoke<Void>(0x6A44A7D4, ped); }
	static void SET_ANIM_GROUP_FOR_CHAR(Ped ped, const char* grname) { invoke<Void>(0x3CBAA102, ped, grname); }
	static void SET_CHAR_ACCURACY(Ped ped, uint32_t value) { invoke<Void>(0x5EDBF9ED, ped, value); }
	static void SET_CHAR_ALLOWED_TO_DUCK(Ped ped, BOOL set) { invoke<Void>(0x9D64E554, ped, set); }
	static void SET_CHAR_ALLOWED_TO_RUN_ON_BOATS(Ped ped, BOOL set) { invoke<Void>(0x3C4CFB32, ped, set); }
	static void SET_CHAR_ALL_ANIMS_SPEED(Ped ped, float speed) { invoke<Void>(0x159681A4, ped, speed); }
	static void SET_CHAR_ANGLED_DEFENSIVE_AREA(Ped ped, float x0, float y0, float z0, float x1, float y1, float z1, float angle) { invoke<Void>(0xA5BE26B3, ped, x0, y0, z0, x1, y1, z1, angle); }
	static void SET_CHAR_ANIM_BLEND_OUT_DELTA(Ped ped, const char* AnimName0, const char* AnimName1, float delta) { invoke<Void>(0x8F5B9E73, ped, AnimName0, AnimName1, delta); }
	static void SET_CHAR_ANIM_CURRENT_TIME(Ped ped, const char* AnimName0, const char* AnimName1, float time) { invoke<Void>(0x05CE61F0, ped, AnimName0, AnimName1, time); }
	static void SET_CHAR_ANIM_SPEED(Ped ped, const char* AnimName0, const char* AnimName1, float speed) { invoke<Void>(0x8236E8E0, ped, AnimName0, AnimName1, speed); }
	static void SET_CHAR_AS_ENEMY(Ped ped, BOOL value) { invoke<Void>(0x7FED5FF2, ped, value); }
	static void SET_CHAR_AS_MISSION_CHAR(Ped ped) { invoke<Void>(0x4B2F3CE0, ped); }
	static void SET_CHAR_BLEEDING(Ped ped, BOOL set) { invoke<Void>(0x5C498407, ped, set); }
	static void SET_CHAR_BULLETPROOF_VEST(Ped ped, BOOL set) { invoke<Void>(0x65C99BAF, ped, set); }
	static void SET_CHAR_CANT_BE_DRAGGED_OUT(Ped ped, BOOL enabled) { invoke<Void>(0x00594267, ped, enabled); }
	static void SET_CHAR_CAN_BE_KNOCKED_OFF_BIKE(Ped ped, BOOL value) { invoke<Void>(0xB856EF1C, ped, value); }
	static void SET_CHAR_CAN_BE_SHOT_IN_VEHICLE(Ped ped, BOOL enabled) { invoke<Void>(0xC500437A, ped, enabled); }
	static void SET_CHAR_CAN_SMASH_GLASS(Ped ped, BOOL set) { invoke<Void>(0xEEA0468F, ped, set); }
	static void SET_CHAR_CLIMB_ANIM_RATE(Ped ped, float rate) { invoke<Void>(0xF0BFDE7F, ped, rate); }
	static void SET_CHAR_COLLISION(Ped ped, BOOL set) { invoke<Void>(0xB1898130, ped, set); }
	static void SET_CHAR_COMPONENT_VARIATION(Ped ped, uint32_t component, uint32_t modelVariation, uint32_t textureVariation) { invoke<Void>(0x4937EBF1, ped, component, modelVariation, textureVariation); }
	static void SET_CHAR_COORDINATES(Ped ped, float x, float y, float z) { invoke<Void>(0x049727E0, ped, x, y, z); }
	static void SET_CHAR_COORDINATES_DONT_CLEAR_PLAYER_TASKS(Ped ped, float x, float y, float z) { invoke<Void>(0x908016FB, ped, x, y, z); }
	static void SET_CHAR_COORDINATES_DONT_WARP_GANG(Ped ped, float x, float y, float z) { invoke<Void>(0x3BC940E2, ped, x, y, z); }
	static void SET_CHAR_COORDINATES_DONT_WARP_GANG_NO_OFFSET(Ped ped, float x, float y, float z) { invoke<Void>(0x73487867, ped, x, y, z); }
	static void SET_CHAR_COORDINATES_NO_OFFSET(Ped ped, float x, float y, float z) { invoke<Void>(0x4CEB5FC3, ped, x, y, z); }
	static void SET_CHAR_DEFAULT_COMPONENT_VARIATION(Ped ped) { invoke<Void>(0xF0FBEF4B, ped); }
	static void SET_CHAR_DEFENSIVE_AREA_ATTACHED_TO_PED(Ped ped, Ped pednext, float x0, float y0, float z0, float x1, float y1, float z1, int Unk7, int Unk8) { invoke<Void>(0x84407447, ped, pednext, x0, y0, z0, x1, y1, z1, Unk7, Unk8); }
	static void SET_CHAR_DESIRED_HEADING(Ped ped, float heading) { invoke<Void>(0x7B0BFD93, ped, heading); }
	static void SET_CHAR_DIES_INSTANTLY_IN_WATER(Ped ped, BOOL allow) { invoke<Void>(0xF3824C5D, ped, allow); }
	static void SET_CHAR_DROPS_WEAPONS_WHEN_DEAD(Ped ped, BOOL value) { invoke<Void>(0x5550AF04, ped, value); }
	static void SET_CHAR_DROWNS_IN_SINKING_VEHICLE(Ped ped, BOOL set) { invoke<Void>(0x017AD3C3, ped, set); }
	static void SET_CHAR_DROWNS_IN_WATER(Ped ped, BOOL set) { invoke<Void>(0x07622F98, ped, set); }
	static void SET_CHAR_DRUGGED_UP(Ped ped, BOOL drugged) { invoke<Void>(0x500FF2AB, ped, drugged); }
	static void SET_CHAR_DUCKING_TIMED(Ped ped, int timed) { invoke<Void>(0xDC759F24, ped, timed); }
	static void SET_CHAR_FIRE_DAMAGE_MULTIPLIER(Ped ped, float multiplier) { invoke<Void>(0xD7BF444B, ped, multiplier); }
	static void SET_CHAR_FORCE_DIE_IN_CAR(Ped ped, BOOL set) { invoke<Void>(0xE7B79D67, ped, set); }
	static void SET_CHAR_GESTURE_GROUP(Ped ped, const char* AnimGroup) { invoke<Void>(0x5D9136C3, ped, AnimGroup); }
	static void SET_CHAR_GET_OUT_UPSIDE_DOWN_CAR(Ped ped, BOOL set) { invoke<Void>(0x6D60E68D, ped, set); }
	static void SET_CHAR_GRAVITY(Ped ped, float value) { invoke<Void>(0x252DE038, ped, value); }
	static void SET_CHAR_HEADING(Ped ped, float heading) { invoke<Void>(0x9D0E2598, ped, heading); }
	static void SET_CHAR_HEALTH(Ped ped, uint32_t health) { invoke<Void>(0x5BC562BF, ped, health); }
	static void SET_CHAR_INVINCIBLE(Ped ped, BOOL enable) { invoke<Void>(0x6677FA86, ped, enable); }
	static void SET_CHAR_IN_CUTSCENE(Ped ped, BOOL set) { invoke<Void>(0x0E3659E6, ped, set); }
	static void SET_CHAR_IS_TARGET_PRIORITY(Ped ped, BOOL enable) { invoke<Void>(0x6486FFEA, ped, enable); }
	static void SET_CHAR_KEEP_TASK(Ped ped, BOOL value) { invoke<Void>(0xA7B69843, ped, value); }
	static void SET_CHAR_MAX_HEALTH(Ped ped, uint32_t value) { invoke<Void>(0x4FFAA9E8, ped, value); }
	static void SET_CHAR_MAX_MOVE_BLEND_RATIO(Ped ped, float ratio) { invoke<Void>(0x644F4798, ped, ratio); }
	static void SET_CHAR_MAX_TIME_IN_WATER(Ped ped, float time) { invoke<Void>(0x1FCFF460, ped, time); }
	static void SET_CHAR_MAX_TIME_UNDERWATER(Ped ped, float time) { invoke<Void>(0xBA35FE09, ped, time); }
	static void SET_CHAR_MELEE_ACTION_FLAG0(Ped ped, BOOL set) { invoke<Void>(0x32FA325D, ped, set); }
	static void SET_CHAR_MELEE_ACTION_FLAG1(Ped ped, BOOL set) { invoke<Void>(0x07A6DBB7, ped, set); }
	static void SET_CHAR_MELEE_ACTION_FLAG2(Ped ped, BOOL set) { invoke<Void>(0x15F0784A, ped, set); }
	static void SET_CHAR_MELEE_MOVEMENT_CONSTAINT_BOX(Ped ped, float x0, float y0, float z0, float x1, float y1, float z1) { invoke<Void>(0xCBEF0B60, ped, x0, y0, z0, x1, y1, z1); }
	static void SET_CHAR_MONEY(Ped ped, uint32_t amount) { invoke<Void>(0x37504EAB, ped, amount); }
	static void SET_CHAR_MOVEMENT_ANIMS_BLOCKED(Ped ped, BOOL set) { invoke<Void>(0x6B8D69F7, ped, set); }
	static void SET_CHAR_MOVE_ANIM_SPEED_MULTIPLIER(Ped ped, float multiplier) { invoke<Void>(0x09A48126, ped, multiplier); }
	static void SET_CHAR_NEVER_LEAVES_GROUP(Ped ped, BOOL value) { invoke<Void>(0xC62AB646, ped, value); }
	static void SET_CHAR_NEVER_TARGETTED(Ped ped, BOOL set) { invoke<Void>(0x10DE46EC, ped, set); }
	static void SET_CHAR_NOT_DAMAGED_BY_RELATIONSHIP_GROUP(Ped ped, eRelationshipGroup relationshipGroup, BOOL enable) { invoke<Void>(0x880FC806, ped, relationshipGroup, enable); }
	static void SET_CHAR_ONLY_DAMAGED_BY_PLAYER(Ped ped, BOOL set) { invoke<Void>(0x263644EA, ped, set); }
	static void SET_CHAR_ONLY_DAMAGED_BY_RELATIONSHIP_GROUP(Ped ped, BOOL set, int relgroup) { invoke<Void>(0x12CFD4F9, ped, set, relgroup); }
	static void SET_CHAR_PROOFS(Ped ped, BOOL unknown0, BOOL fallingDamage, BOOL unknown1, BOOL unknown2, BOOL unknown3) { invoke<Void>(0xBF7C253D, ped, unknown0, fallingDamage, unknown1, unknown2, unknown3); }
	static void SET_CHAR_PROP_INDEX(Ped ped, uint32_t propType, uint32_t index) { invoke<Void>(0xB710A863, ped, propType, index); }
	static void SET_CHAR_PROP_INDEX_TEXTURE(Ped ped, int Unk9, int Unk10, int Unk11) { invoke<Void>(0x77F7BE3C, ped, Unk9, Unk10, Unk11); }
	static void SET_CHAR_PROVIDE_COVERING_FIRE(Ped ped, BOOL set) { invoke<Void>(0xFDD1B30B, ped, set); }
	static void SET_CHAR_RANDOM_COMPONENT_VARIATION(Ped ped) { invoke<Void>(0xD962C873, ped); }
	static void SET_CHAR_READY_TO_BE_EXECUTED(Ped ped, BOOL set) { invoke<Void>(0x7E59848E, ped, set); }
	static void SET_CHAR_READY_TO_BE_STUNNED(Ped ped, BOOL set) { invoke<Void>(0x57D04BF3, ped, set); }
	static void SET_CHAR_RELATIONSHIP(Ped ped, uint32_t relationshipLevel, eRelationshipGroup relationshipGroup) { invoke<Void>(0x2274066D, ped, relationshipLevel, relationshipGroup); }
	static void SET_CHAR_RELATIONSHIP_GROUP(Ped ped, eRelationshipGroup relationshipGroup) { invoke<Void>(0x1DDD858E, ped, relationshipGroup); }
	static void SET_CHAR_ROTATION(Ped ped, float xr, float yr, float zr) { invoke<Void>(0xFB3DF112, ped, xr, yr, zr); }
	static void SET_CHAR_SHOOT_RATE(Ped ped, int rate) { invoke<Void>(0x16BC65AC, ped, rate); }
	static void SET_CHAR_SIGNAL_AFTER_KILL(Ped ped, BOOL set) { invoke<Void>(0x45770A6F, ped, set); }
	static void SET_CHAR_SPHERE_DEFENSIVE_AREA(Ped ped, float x, float y, float z, float radius) { invoke<Void>(0x66481957, ped, x, y, z, radius); }
	static void SET_CHAR_STAY_IN_CAR_WHEN_JACKED(Ped ped, BOOL set) { invoke<Void>(0x6B1F6703, ped, set); }
	static void SET_CHAR_SUFFERS_CRITICAL_HITS(Ped ped, BOOL value) { invoke<Void>(0x6D0EDBC8, ped, value); }
	static void SET_CHAR_USES_DEAFULT_ANIM_GROUP_WHEN_FLEEING(Ped ped, BOOL set) { invoke<Void>(0x8BC4DC20, ped, set); }
	static void SET_CHAR_USES_UPPERBODY_DAMAGE_ANIMS_ONLY(Ped ped, BOOL set) { invoke<Void>(0xF3FD6253, ped, set); }
	static void SET_CHAR_VELOCITY(Ped ped, float x, float y, float z) { invoke<Void>(0xA43F97D0, ped, x, y, z); }
	static void SET_CHAR_VISIBLE(Ped ped, BOOL value) { invoke<Void>(0x792360DC, ped, value); }
	static void SET_CHAR_WALK_ALONGSIDE_LEADER_WHEN_APPROPRIATE(Ped ped, BOOL set) { invoke<Void>(0x05152D38, ped, set); }
	static void SET_CHAR_WATCH_MELEE(Ped ped, BOOL set) { invoke<Void>(0xE45BCAEF, ped, set); }
	static void SET_CHAR_WILL_COWER_INSTEAD_OF_FLEEING(Ped ped, BOOL set) { invoke<Void>(0x3ADB74B6, ped, set); }
	static void SET_CHAR_WILL_DO_DRIVEBYS(Ped ped, BOOL value) { invoke<Void>(0xD0837ECB, ped, value); }
	static void SET_CHAR_WILL_FLY_THROUGH_WINDSCREEN(Ped ped, BOOL value) { invoke<Void>(0xD2F6651D, ped, value); }
	static void SET_CHAR_WILL_LEAVE_CAR_IN_COMBAT(Ped ped, BOOL set) { invoke<Void>(0x6EA3AB85, ped, set); }
	static void SET_CHAR_WILL_MOVE_WHEN_INJURED(Ped ped, BOOL value) { invoke<Void>(0xB235CFF8, ped, value); }
	static void SET_CHAR_WILL_ONLY_FIRE_WITH_CLEAR_LOS(Ped ped, BOOL set) { invoke<Void>(0x9C4D8EF0, ped, set); }
	static void SET_CHAR_WILL_REMAIN_ON_BOAT_AFTER_MISSION_ENDS(Ped ped, BOOL set) { invoke<Void>(0x22E6BD35, ped, set); }
	static void SET_CHAR_WILL_TRY_TO_LEAVE_BOAT_AFTER_LEADER(Ped ped, BOOL set) { invoke<Void>(0x741E9854, ped, set); }
	static void SET_CHAR_WILL_TRY_TO_LEAVE_WATER(Ped ped, BOOL set) { invoke<Void>(0x4317FFB7, ped, set); }
	static void SET_CHAR_WILL_USE_CARS_IN_COMBAT(Ped ped, BOOL value) { invoke<Void>(0xA163A070, ped, value); }
	static void SET_CHAR_WILL_USE_COVER(Ped ped, BOOL value) { invoke<Void>(0xF077736E, ped, value); }
	static void SET_DEAD_CHAR_COORDINATES(Ped ped, float x, float y, float z) { invoke<Void>(0x584A72C5, ped, x, y, z); }
	static void SET_GROUP_CHAR_DUCKS_WHEN_AIMED_AT(Ped ped, BOOL value) { invoke<Void>(0x8FD75169, ped, value); }
	static void SET_LOAD_COLLISION_FOR_CHAR_FLAG(Ped ped, BOOL set) { invoke<Void>(0x63847A71, ped, set); }
	static void SET_ROOM_FOR_CHAR_BY_KEY(Ped ped, uint32_t key) { invoke<Void>(0xDB13AD1B, ped, key); }
	static void SET_ROOM_FOR_CHAR_BY_NAME(Ped ped, const char* roomname) { invoke<Void>(0x868589E4, ped, roomname); }
	static void UNSET_CHAR_MELEE_MOVEMENT_CONSTAINT_BOX(Ped ped) { invoke<Void>(0x962C6074, ped); }
}

namespace PLAYER
{
	static BOOL CAN_PLAYER_START_MISSION(int player) { return invoke<BOOL>(0x39E3CB3F, player); }
	static BOOL GET_PLAYER_HAS_TRACKS() { return invoke<BOOL>(0xC6621B28); }
	static BOOL HAS_ACHIEVEMENT_BEEN_PASSED(uint32_t achievement) { return invoke<BOOL>(0x136A5BE9, achievement); }
	static BOOL HAS_PLAYER_COLLECTED_PICKUP(Player playerIndex, Pickup pikcup) { return invoke<BOOL>(0x2BCBA429, playerIndex, pikcup); }
	static BOOL HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED(Player playerIndex) { return invoke<BOOL>(0x14F52453, playerIndex); }
	static BOOL HAS_PLAYER_DAMAGED_AT_LEAST_ONE_VEHICLE(Player playerIndex) { return invoke<BOOL>(0x7E99E4FE, playerIndex); }
	static BOOL IS_PLACE_CAR_BOMB_ACTIVE() { return invoke<BOOL>(0x7057B1C6); }
	static BOOL IS_PLAYER_BEING_ARRESTED() { return invoke<BOOL>(0x7F6A60D3); }
	static BOOL IS_PLAYER_CLIMBING(Player playerIndex) { return invoke<BOOL>(0x4A9E9AE0, playerIndex); }
	static BOOL IS_PLAYER_CONTROL_ON(Player playerIndex) { return invoke<BOOL>(0x618857F2, playerIndex); }
	static BOOL IS_PLAYER_DEAD(Player playerIndex) { return invoke<BOOL>(0x140CA5A8, playerIndex); }
	static BOOL IS_PLAYER_FREE_AIMING_AT_CHAR(Player playerIndex, Ped ped) { return invoke<BOOL>(0xC9147BA8, playerIndex, ped); }
	static BOOL IS_PLAYER_FREE_FOR_AMBIENT_TASK(Player playerIndex) { return invoke<BOOL>(0x85C7E232, playerIndex); }
	static BOOL IS_PLAYER_IN_REMOTE_MODE(int player) { return invoke<BOOL>(0x8E263263, player); }
	static BOOL IS_PLAYER_ONLINE() { return invoke<BOOL>(0x9FAB6729); }
	static BOOL IS_PLAYER_PERFORMING_STOPPIE(int player) { return invoke<BOOL>(0x9FF4A9A1, player); }
	static BOOL IS_PLAYER_PERFORMING_WHEELIE(int player) { return invoke<BOOL>(0x6C82DFCF, player); }
	static BOOL IS_PLAYER_PLAYING(Player playerIndex) { return invoke<BOOL>(0xE15D777F, playerIndex); }
	static BOOL IS_PLAYER_PRESSING_HORN(Player playerIndex) { return invoke<BOOL>(0xED1D1662, playerIndex); }
	static BOOL IS_PLAYER_READY_FOR_CUTSCENE(int player) { return invoke<BOOL>(0xBB77E9CD, player); }
	static BOOL IS_PLAYER_SCRIPT_CONTROL_ON(int player) { return invoke<BOOL>(0x61B00A84, player); }
	static BOOL IS_PLAYER_SIGNED_IN_LOCALLY() { return invoke<BOOL>(0xE95A4DCA); }
	static BOOL IS_PLAYER_TARGETTING_ANYTHING(Player playerIndex) { return invoke<BOOL>(0x456DB50D, playerIndex); }
	static BOOL IS_PLAYER_TARGETTING_CHAR(Player playerIndex, Ped ped) { return invoke<BOOL>(0xF3CBB110, playerIndex, ped); }
	static BOOL IS_PLAYER_TARGETTING_OBJECT(Player playerIndex, Object obj) { return invoke<BOOL>(0x622796D5, playerIndex, obj); }
	static BOOL IS_PLAYER_VEHICLE_ENTRY_DISABLED(int player) { return invoke<BOOL>(0x7D6D5FF8, player); }
	static BOOL IS_SCORE_GREATER(Player playerIndex, uint32_t score) { return invoke<BOOL>(0x5E183F8E, playerIndex, score); }
	static BOOL PLAYER_HAS_CHAR(Player playerIndex) { return invoke<BOOL>(0x6FF7A2D3, playerIndex); }
	static BOOL PLAYER_HAS_FLASHING_STARS_ABOUT_TO_DROP(Player playerIndex) { return invoke<BOOL>(0x25798938, playerIndex); }
	static BOOL PLAYER_HAS_GREYED_OUT_STARS(Player playerIndex) { return invoke<BOOL>(0x89AF0283, playerIndex); }
	static BOOL PLAYER_IS_INTERACTING_WITH_GARAGE() { return invoke<BOOL>(0x2136FA65); }
	static BOOL PLAYER_IS_NEAR_FIRST_PIGEON(float x, float y, float z) { return invoke<BOOL>(0xA7CBCDF9, x, y, z); }
	static BOOL PLAYER_IS_PISSED_OFF(int player) { return invoke<BOOL>(0x38641279, player); }
	static const char* GET_PLAYER_RADIO_STATION_NAME() { return invoke<const char*>(0xD909C107); }
	static const char* GET_PLAYER_RADIO_STATION_NAME_ROLL() { return invoke<const char*>(0x7ABCAD40); }
	static char* GET_PLAYER_NAME(Player playerIndex) { return invoke<char*>(0x406B4B20, playerIndex); }
	static int GET_LOCAL_PLAYER_MP_CASH() { return invoke<int>(0x75A3813A); }
	static int GET_NO_LAW_VEHICLES_DESTROYED_BY_LOCAL_PLAYER() { return invoke<int>(0x88E1A361); }
	static int GET_PLAYER_ID_FOR_THIS_PED(Ped ped) { return invoke<int>(0xCD2E5D25, ped); }
	static int GET_PLAYER_RADIO_MODE() { return invoke<int>(0x89C29D95); }
	static Player CONVERT_INT_TO_PLAYERINDEX(uint32_t playerId) { return invoke<Player>(0x8035E327, playerId); }
	static Any GET_PLAYER_TO_PLACE_BOMB_IN_CAR(Vehicle vehicle) { return invoke<Any>(0x61582290, vehicle); }
	static uint32_t GET_LEFT_PLAYER_CASH_TO_REACH_LEVEL(uint32_t playerRank) { return invoke<uint32_t>(0x5BD77188, playerRank); }
	static uint32_t GET_PLAYERSETTINGS_MODEL_CHOICE() { return invoke<uint32_t>(0xEABA1F08); }
	static uint32_t GET_PLAYER_ID() { return invoke<uint32_t>(0x1CC648EA); }
	static uint32_t GET_PLAYER_RADIO_STATION_INDEX() { return invoke<uint32_t>(0x1C4946AC); }
	static uint32_t GET_TIME_SINCE_PLAYER_DROVE_AGAINST_TRAFFIC(Player playerIndex) { return invoke<uint32_t>(0x9F27D00E, playerIndex); }
	static uint32_t GET_TIME_SINCE_PLAYER_DROVE_ON_PAVEMENT(Player playerIndex) { return invoke<uint32_t>(0x8836E732, playerIndex); }
	static uint32_t GET_TIME_SINCE_PLAYER_HIT_BUILDING(Player playerIndex) { return invoke<uint32_t>(0xE8C58D94, playerIndex); }
	static uint32_t GET_TIME_SINCE_PLAYER_HIT_CAR(Player playerIndex) { return invoke<uint32_t>(0xC5A5C559, playerIndex); }
	static uint32_t GET_TIME_SINCE_PLAYER_HIT_OBJECT(Player playerIndex) { return invoke<uint32_t>(0x3CFDA2AE, playerIndex); }
	static uint32_t GET_TIME_SINCE_PLAYER_HIT_PED(Player playerIndex) { return invoke<uint32_t>(0xB6209195, playerIndex); }
	static uint32_t GET_TIME_SINCE_PLAYER_RAN_LIGHT(Player playerIndex) { return invoke<uint32_t>(0x77E9FF3E, playerIndex); }
	static void ADD_SCORE(Player playerIndex, int score) { invoke<Void>(0xAC14689F, playerIndex, score); }
	static void ALLOW_LOCKON_TO_RANDOM_PEDS(int player, BOOL allow) { invoke<Void>(0xA5D3BC34, player, allow); }
	static void ALLOW_PLAYER_TO_CARRY_NON_MISSION_OBJECTS(Player playerIndex, BOOL allow) { invoke<Void>(0x457ECD86, playerIndex, allow); }
	static void AWARD_PLAYER_MISSION_RESPECT(float respect) { invoke<Void>(0xD381CE87, respect); }
	static void BLOCK_STATS_MENU_ACTIONS(int player) { invoke<Void>(0x23CBAD60, player); }
	static void CHANGE_PLAYER_MODEL(Player playerIndex, uint32_t model) { invoke<Void>(0x29254BEE, playerIndex, model); }
	static void CHANGE_PLAYER_PHONE_MODEL(int player, uint32_t model) { invoke<Void>(0xE3D97806, player, model); }
	static void CHANGE_PLAYER_PHONE_MODEL_OFFSETS(int player, float x0, float y0, float z0, float x1, float y1, float z1) { invoke<Void>(0xC102C33A, player, x0, y0, z0, x1, y1, z1); }
	static void CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED(Player playerIndex) { invoke<Void>(0x1D31CBBD, playerIndex); }
	static void CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_VEHICLE(int player) { invoke<Void>(0xE533B795, player); }
	static void CREATE_PLAYER(uint32_t playerId, float x, float y, float z, Player* pPlayerIndex) { invoke<Void>(0x584BA966, playerId, x, y, z, pPlayerIndex); }
	static void DELETE_PLAYER() { invoke<Void>(0xB7D1D73B); }
	static void DISABLE_LOCAL_PLAYER_PICKUPS(BOOL disable) { invoke<Void>(0x35DA410D, disable); }
	static void DISABLE_PLAYER_AUTO_VEHICLE_EXIT(Ped ped, BOOL disable) { invoke<Void>(0x4B9CB0CD, 2, ped, disable); }
	static void DISABLE_PLAYER_LOCKON(Player playerIndex, BOOL disabled) { invoke<Void>(0x3D69E524, playerIndex, disabled); }
	static void DISABLE_PLAYER_SPRINT(Player playerIndex, BOOL disabled) { invoke<Void>(0x2B00E197, playerIndex, disabled); }
	static void DISABLE_PLAYER_VEHICLE_ENTRY(int player, BOOL disable) { invoke<Void>(0x88464960, player, disable); }
	static void FAKE_DEATHARREST() { invoke<Void>(0xDAE906B1); }
	static void FORCE_AIR_DRAG_MULT_FOR_PLAYERS_CAR(int player, float multiplier) { invoke<Void>(0xF4DA8F96, player, multiplier); }
	static void FORCE_INTERIOR_LIGHTING_FOR_PLAYER(int player, BOOL force) { invoke<Void>(0x62407179, player, force); }
	static void GET_NUM_OF_MODELS_KILLED_BY_PLAYER(int player, uint32_t model, int* num) { invoke<Void>(0xA2CBAA96, player, model, num); }
	static void GET_PLAYERS_LAST_CAR_NO_SAVE(Vehicle* pVehicle) { invoke<Void>(0xB942887B, pVehicle); }
	static void GET_PLAYER_CHAR(Player playerIndex, Ped* pPed) { invoke<Void>(0x6B86410E, playerIndex, pPed); }
	static void GET_PLAYER_GROUP(Player playerIndex, Group* pGroup) { invoke<Void>(0xA5EDCDE8, playerIndex, pGroup); }
	static void GET_PLAYER_MAX_ARMOUR(Player playerIndex, uint32_t* pMaxArmour) { invoke<Void>(0x02A50657, playerIndex, pMaxArmour); }
	static void GET_PLAYER_MAX_HEALTH(int player, int* maxhealth) { invoke<Void>(0x8154E470, player, maxhealth); }
	static void GIVE_PLAYER_RAGDOLL_CONTROL(int player, BOOL give) { invoke<Void>(0xC7B4D7AC, player, give); }
	static void INCREASE_PLAYER_MAX_ARMOUR(int player, float armour) { invoke<Void>(0x5B60B6C7, player, armour); }
	static void INCREASE_PLAYER_MAX_HEALTH(int player, int maxhealth) { invoke<Void>(0xA834B934, player, maxhealth); }
	static void LISTEN_TO_PLAYER_GROUP_COMMANDS(Ped ped, BOOL set) { invoke<Void>(0x44D69EC1, ped, set); }
	static void MAKE_PLAYER_FIRE_PROOF(int player, BOOL proof) { invoke<Void>(0x2D9CDFC5, player, proof); }
	static void MAKE_PLAYER_GANG_DISAPPEAR() { invoke<Void>(0x29A23EDB); }
	static void MAKE_PLAYER_GANG_REAPPEAR() { invoke<Void>(0x11589FEE); }
	static void MAKE_PLAYER_SAFE_FOR_CUTSCENE(int player) { invoke<Void>(0xFC90AC18, player); }
	static void REGISTER_PLAYER_RESPAWN_COORDS(Player playerIndex, float x, float y, float z) { invoke<Void>(0x7AC5FEDC, playerIndex, x, y, z); }
	static void REMOVE_PLAYER_HELMET(Player playerIndex, BOOL remove) { invoke<Void>(0x6255F3B4, playerIndex, remove); }
	static void RESET_NO_LAW_VEHICLES_DESTROYED_BY_LOCAL_PLAYER() { invoke<Void>(0x01295F22); }
	static void RESET_NUM_OF_MODELS_KILLED_BY_PLAYER(uint32_t model) { invoke<Void>(0x1708E0B9, model); }
	static void SET_ALL_RANDOM_PEDS_FLEE(int player, BOOL set) { invoke<Void>(0x49EAE968, player, set); }
	static void SET_DISABLE_PLAYER_SHOVE_ANIMATION(Ped ped, BOOL disable) { invoke<Void>(0xABC6DFF8, ped, disable); }
	static void SET_DONT_ACTIVATE_RAGDOLL_FROM_PLAYER_IMPACT(Ped ped, BOOL set) { invoke<Void>(0xAE3F53BA, ped, set); }
	static void SET_DRAW_PLAYER_COMPONENT(int component, BOOL set) { invoke<Void>(0x076F4216, component, set); }
	static void SET_EVERYONE_IGNORE_PLAYER(Player playerIndex, BOOL value) { invoke<Void>(0xC915285E, playerIndex, value); }
	static void SET_FORCE_LOOK_BEHIND(BOOL set) { invoke<Void>(0x8023A6B0, set); }
	static void SET_FORCE_PLAYER_TO_ENTER_THROUGH_DIRECT_DOOR(Ped ped, BOOL set) { invoke<Void>(0x693122C4, ped, set); }
	static void SET_FREE_HEALTH_CARE(int player, BOOL set) { invoke<Void>(0x00AD880E, player, set); }
	static void SET_LOCAL_PLAYER_PAIN_VOICE(const char* name) { invoke<Void>(0x33BD1A80, name); }
	static void SET_LOCAL_PLAYER_VOICE(const char* name) { invoke<Void>(0xF0D28043, name); }
	static void SET_PLAYERSETTINGS_MODEL_VARIATIONS_CHOICE(Player playerIndex) { invoke<Void>(0x9EF2997A, playerIndex); }
	static void SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(Player playerIndex, BOOL value) { invoke<Void>(0x71B305BB, playerIndex, value); }
	static void SET_PLAYER_CAN_DO_DRIVE_BY(Player playerIndex, BOOL value) { invoke<Void>(0xF4D99685, playerIndex, value); }
	static void SET_PLAYER_CAN_DROP_WEAPONS_IN_CAR(BOOL set) { invoke<Void>(0xD8E74749, set); }
	static void SET_PLAYER_CAN_USE_COVER(Player playerIndex, BOOL value) { invoke<Void>(0x13CAFAFA, playerIndex, value); }
	static void SET_PLAYER_CONTROL(Player playerIndex, BOOL value) { invoke<Void>(0xD17AFCD8, playerIndex, value); }
	static void SET_PLAYER_CONTROL_ADVANCED(Player playerIndex, BOOL p1, BOOL p2, BOOL p3) { invoke<Void>(0x4261BF11, playerIndex, p1, p2, p3); }
	static void SET_PLAYER_CONTROL_FOR_AMBIENT_SCRIPT(int player, BOOL flag0, BOOL flag1) { invoke<Void>(0xFBD342F5, player, flag0, flag1); }
	static void SET_PLAYER_CONTROL_FOR_TEXT_CHAT(int player, BOOL set) { invoke<Void>(0x35C99B17, player, set); }
	static void SET_PLAYER_CONTROL_ON_IN_MISSION_CLEANUP(BOOL set) { invoke<Void>(0xE886E2C5, set); }
	static void SET_PLAYER_DISABLE_CROUCH(int player, BOOL set) { invoke<Void>(0x2CE0A328, player, set); }
	static void SET_PLAYER_DISABLE_JUMP(int player, BOOL set) { invoke<Void>(0xD1BAD4C7, player, set); }
	static void SET_PLAYER_FAST_RELOAD(Player playerIndex, BOOL value) { invoke<Void>(0x38A0D835, playerIndex, value); }
	static void SET_PLAYER_FORCED_AIM(int player, BOOL set) { invoke<Void>(0x94E42E2E, player, set); }
	static void SET_PLAYER_GROUP_RECRUITMENT(int player, BOOL set) { invoke<Void>(0x92A01102, player, set); }
	static void SET_PLAYER_GROUP_TO_FOLLOW_ALWAYS(Player playerIndex, BOOL value) { invoke<Void>(0xBC31136A, playerIndex, value); }
	static void SET_PLAYER_GROUP_TO_FOLLOW_NEVER(int player, BOOL set) { invoke<Void>(0x8EE333A9, player, set); }
	static void SET_PLAYER_ICON_COLOUR(int colour) { invoke<Void>(0x1630B64C, colour); }
	static void SET_PLAYER_INVINCIBLE(Player playerIndex, BOOL value) { invoke<Void>(0xDFB9A2A2, playerIndex, value); }
	static void SET_PLAYER_INVISIBLE_TO_AI(BOOL set) { invoke<Void>(0xD022F783, set); }
	static void SET_PLAYER_IS_IN_STADIUM(BOOL set) { invoke<Void>(0x559B48D5, set); }
	static void SET_PLAYER_KEEPS_WEAPONS_WHEN_RESPAWNED(BOOL set) { invoke<Void>(0xD10FC340, set); }
	static void SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE(int player, Vehicle veh) { invoke<Void>(0xA454DD29, player, veh); }
	static void SET_PLAYER_MOOD_NORMAL(Player playerIndex) { invoke<Void>(0xB1FF6041, playerIndex); }
	static void SET_PLAYER_MOOD_PISSED_OFF(Player playerIndex, uint32_t p1) { invoke<Void>(0x6F60E94E, playerIndex, p1); }
	static void SET_PLAYER_MP_MODIFIER(int player, int p1, float modifier) { invoke<Void>(0x9327F5B2, player, p1, modifier); }
	static void SET_PLAYER_NEVER_GETS_TIRED(Player playerIndex, BOOL value) { invoke<Void>(0x6DD90C30, playerIndex, value); }
	static void SET_PLAYER_PAIN_ROOT_BANK_NAME(const char* name) { invoke<Void>(0xE7B8A712, name); }
	static void SET_PLAYER_PLAYER_TARGETTING(BOOL set) { invoke<Void>(0xF12A7F7D, set); }
	static void SET_PLAYER_SETTINGS_GENRE(Ped ped) { invoke<Void>(0xC9751ADF, ped); }
	static void SET_USE_LEG_IK(int player, BOOL set) { invoke<Void>(0xEDB40066, player, set); }
	static void STORE_SCORE(Player playerIndex, uint32_t* value) { invoke<Void>(0x77F7D38E, playerIndex, value); }
	static void ALLOW_LOCKON_TO_FRIENDLY_PLAYERS(int player, BOOL allow) { invoke<Void>(0x51A7743F, player, allow); }

}

namespace PED
{
	static BOOL ARE_ENEMY_PEDS_IN_AREA(Ped ped, float x, float y, float z, float radius) { return invoke<BOOL>(0xE3CDF209, ped, x, y, z, radius); }
	static BOOL CAN_PED_SHIMMY_IN_DIRECTION(Ped ped, int direction) { return invoke<BOOL>(0x568FB0B9, ped, direction); }
	static BOOL CHECK_NM_FEEDBACK(Ped ped, int id, BOOL p2) { return invoke<BOOL>(0x36BDA8CB, ped, id, p2); }
	static BOOL DOES_GROUP_EXIST(Group group) { return invoke<BOOL>(0x935C978D, group); }
	static BOOL GET_PED_PATH_MAY_DROP_FROM_HEIGHT(Ped ped) { return invoke<BOOL>(0x447B9C20, ped); }
	static BOOL GET_PED_PATH_MAY_USE_CLIMBOVERS(Ped ped) { return invoke<BOOL>(0xDE6ED972, ped); }
	static BOOL GET_PED_PATH_MAY_USE_LADDERS(Ped ped) { return invoke<BOOL>(0x2A5D4C57, ped); }
	static BOOL GET_PED_PATH_WILL_AVOID_DYNAMIC_OBJECTS(Ped ped) { return invoke<BOOL>(0xB8E7670C, ped); }
	static BOOL GET_PED_STEERS_AROUND_OBJECTS(Ped ped) { return invoke<BOOL>(0xE4E47CBF, ped); }
	static BOOL GET_PED_STEERS_AROUND_PEDS(Ped ped) { return invoke<BOOL>(0x3FEB6AB3, ped); }
	static BOOL GET_TASK_PLACE_CAR_BOMB_UNSUCCESSFUL() { return invoke<BOOL>(0xA99B76A1); }
	static BOOL HAS_OVERRIDEN_SIT_IDLE_ANIM_FINISHED(Ped ped) { return invoke<BOOL>(0xD8A5D041, ped); }
	static BOOL IS_GROUP_LEADER(Ped ped, Group group) { return invoke<BOOL>(0xF95FF468, ped, group); }
	static BOOL IS_GROUP_MEMBER(Ped ped, Group group) { return invoke<BOOL>(0x947966A8, ped, group); }
	static BOOL IS_PEDS_VEHICLE_HOT(Ped ped) { return invoke<BOOL>(0x5A0FB593, ped); }
	static BOOL IS_PED_ATTACHED_TO_ANY_CAR(Ped ped) { return invoke<BOOL>(0x566E69D1, ped); }
	static BOOL IS_PED_ATTACHED_TO_OBJECT(Ped ped, Object obj) { return invoke<BOOL>(0xEA085F14, ped, obj); }
	static BOOL IS_PED_A_MISSION_PED(Ped ped) { return invoke<BOOL>(0xB653748D, ped); }
	static BOOL IS_PED_BEING_JACKED(Ped ped) { return invoke<BOOL>(0xD45D605C, ped); }
	static BOOL IS_PED_CLIMBING(Ped ped) { return invoke<BOOL>(0xBCE03D35, ped); }
	static BOOL IS_PED_DOING_DRIVEBY(Ped ped) { return invoke<BOOL>(0xAC3CEB9C, ped); }
	static BOOL IS_PED_FLEEING(Ped ped) { return invoke<BOOL>(0x85D813C6, ped); }
	static BOOL IS_PED_HOLDING_AN_OBJECT(Ped ped) { return invoke<BOOL>(0xD502986D, ped); }
	static BOOL IS_PED_IN_COMBAT(Ped ped) { return invoke<BOOL>(0xFE027CB5, ped); }
	static BOOL IS_PED_IN_COVER(Ped ped) { return invoke<BOOL>(0x972C5A8B, ped); }
	static BOOL IS_PED_IN_CUTSCENE_BLOCKING_BOUNDS(Ped ped) { return invoke<BOOL>(0x8026F695, ped); }
	static BOOL IS_PED_IN_GROUP(Ped ped) { return invoke<BOOL>(0x836D9795, ped); }
	static BOOL IS_PED_JACKING(Ped ped) { return invoke<BOOL>(0x3B321816, ped); }
	static BOOL IS_PED_LOOKING_AT_CAR(Ped ped, Vehicle car) { return invoke<BOOL>(0x708E1881, ped, car); }
	static BOOL IS_PED_LOOKING_AT_OBJECT(Ped ped, Object obj) { return invoke<BOOL>(0x449D449E, ped, obj); }
	static BOOL IS_PED_LOOKING_AT_PED(Ped ped, Ped otherChar) { return invoke<BOOL>(0xA114B530, ped, otherChar); }
	static BOOL IS_PED_PINNED_DOWN(Ped ped) { return invoke<BOOL>(0x34F55BF4, ped); }
	static BOOL IS_PED_RAGDOL(Ped ped) { return invoke<BOOL>(0xEC413789, ped); }
	static BOOL IS_PED_RETREATING(Ped ped) { return invoke<BOOL>(0x27240BFE, ped); }
	static BOOL S_THIS_PED_A_PLAYER(Ped ped) { return invoke<BOOL>(0x3C926C48, ped); }
	static BOOL SWITCH_PED_TO_RAGDOLL(Ped ped, int Unk14, int time, BOOL flag0, BOOL flag1, BOOL flag2, BOOL flag3) { return invoke<BOOL>(0xC5DCC21B, ped, Unk14, time, flag0, flag1, flag2, flag3); }
	static BOOL SWITCH_PED_TO_RAGDOLL_WITH_FALL(Ped ped, int p1, int p2, int p3, float p4, float p5, int p6, float p7, float p8, float p9, float p10, float p11, float p12, float p13) { return invoke<BOOL>(0x00C566B0, ped, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); }
	static BOOL WAS_PED_KILLED_BY_HEADSHOT(Ped ped) { return invoke<BOOL>(0x23FD0A00, ped); }
	static BOOL WAS_PED_SKELETON_UPDATED(Ped ped) { return invoke<BOOL>(0xF7E2FBAD, ped); }
	static int FIND_MAX_NUMBER_OF_GROUP_MEMBERS() { return invoke<int>(0x889DF868); }
	static int GET_NUMBER_OF_ACTIVE_STICKY_BOMBS_OWNED_BY_PED(Ped ped) { return invoke<int>(0x63C82020, ped); }
	static int GET_NUMBER_OF_INJURED_PEDS_IN_RANGE(float x, float y, float z, float radius) { return invoke<int>(0x095916C5, x, y, z, radius); }
	static Ped GET_PED_OBJECT_IS_ATTACHED_TO(Object obj) { return invoke<Ped>(0x72ADF3FC, obj); }
	static uint32_t GET_DAMAGE_TO_PED_BODY_PART(Ped ped, uint32_t part) { return invoke<uint32_t>(0x54FEB2B4, ped, part); }
	static uint32_t GET_PED_CLIMB_STATE(Ped ped) { return invoke<uint32_t>(0xA282D424, ped); }
	static uint32_t GET_PED_MODEL_FROM_INDEX(int index) { return invoke<uint32_t>(0xC4765BEE, index); }
	static void ADD_PED_TO_CINEMATOGRAPHY_AI(int p0, Ped ped) { invoke<Void>(0x0049AC10, p0, ped); }
	static void ADD_PED_TO_MISSION_DELETION_LIST(Ped ped, BOOL p1) { invoke<Void>(0x302E8AC8, ped, p1); }
	static void ALLOW_TARGET_WHEN_INJURED(Ped ped, BOOL allow) { invoke<Void>(0xDE11760C, ped, allow); }
	static void ALWAYS_USE_HEAD_ON_HORN_ANIM_WHEN_DEAD_IN_CAR(Ped ped, BOOL use) { invoke<Void>(0xCDE92D9F, ped, use); }
	static void APPLY_FORCE_TO_PED(Ped ped, uint32_t p1, float x, float y, float z, float spinX, float spinY, float spinZ, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5) { invoke<Void>(0x343ABB0E, ped, p1, x, y, z, spinX, spinY, spinZ, p2, p3, p4, p5); }
	static void ATTACH_PED_TO_CAR_PHYSICALLY(Ped ped, Vehicle car, int pedbone, float x, float y, float z, float angle, float p7, BOOL p8, BOOL p9) { invoke<Void>(0x5F2019C3, ped, car, pedbone, x, y, z, angle, p7, p8, p9); }
	static void ATTACH_PED_TO_OBJECT(Ped ped, Object obj, int pedbone, float x, float y, float z, float angle, float p7, BOOL p8, BOOL p9) { invoke<Void>(0x107FDC53, ped, obj, pedbone, x, y, z, angle, p7, p8, p9); }
	static void ATTACH_PED_TO_OBJECT_PHYSICALLY(Ped ped, Object obj, int pedbone, float x, float y, float z, float angle, float p7, BOOL p8, BOOL p9) { invoke<Void>(0x37F17899, ped, obj, pedbone, x, y, z, angle, p7, p8, p9); }
	static void ATTACH_PED_TO_SHIMMY_EDGE(Ped ped, float x, float y, float z, float p4) { invoke<Void>(0x09E6B0C0, ped, x, y, z, p4); }
	static void CLOSE_MIC_PED(int id, Ped ped) { invoke<Void>(0x64407CDC, id, ped); }
	static void COPY_ANIMATIONS(Ped ped, Ped pednext, float speed) { invoke<Void>(0x2ED971A5, ped, pednext, speed); }
	static void CREATE_GROUP(BOOL ufalse, Group* pGroup, BOOL utrue) { invoke<Void>(0x8DC0368D, ufalse, pGroup, utrue); }
	static void CREATE_NM_MESSAGE(BOOL p0, int id) { invoke<Void>(0x1CFBFD4B, p0, id); }
	static void DAMAGE_PED_BODY_PART(Ped ped, uint32_t part, uint32_t hitPoints) { invoke<Void>(0xA9867E62, ped, part, hitPoints); }
	static void DEFINE_PED_GENERATION_CONSTRAINT_AREA(float x, float y, float z, float radius) { invoke<Void>(0xA8C04972, x, y, z, radius); }
	static void DESTROY_PED_GENERATION_CONSTRAINT_AREA() { invoke<Void>(0xCD5687A7); }
	static void DETACH_PED(Ped ped, BOOL unknown) { invoke<Void>(0xB65BD564, ped, unknown); }
	//void DETACH_PED_FROM_WITHIN_CAR(Ped ped, bool unknown)
	static void DONT_SUPPRESS_ANY_PED_MODELS() { invoke<Void>(0x3AE27BC9); }
	static void DONT_SUPPRESS_PED_MODEL(uint32_t model) { invoke<Void>(0x87038C38, model); }
	static void ENABLE_ALL_PED_HELMETS(BOOL enable) { invoke<Void>(0xFDEAD03B, enable); }
	static void ENABLE_PED_HELMET(Ped ped, BOOL enable) { invoke<Void>(0xC5F7BAD0, ped, enable); }
	static void FORCE_FULL_VOICE(Ped ped) { invoke<Void>(0x068485D6, ped); }
	static void FORCE_PED_PINNED_DOWN(Ped ped, BOOL force, uint32_t timerMaybe) { invoke<Void>(0x07130AAA, ped, force, timerMaybe); }
	static void FORCE_PED_TO_FLEE_WHILST_DRIVING_VEHICLE(Ped ped, Vehicle vehicle) { invoke<Void>(0xA2C145AA, ped, vehicle); }
	static void FORCE_PED_TO_LOAD_COVER(Ped ped, BOOL force) { invoke<Void>(0x89029959, ped, force); }
	static void FORCE_RANDOM_PED_TYPE(uint32_t type) { invoke<Void>(0x87E547D9, type); }
	static void FORCE_SPAWN_SCENARIO_PEDS_IN_AREA(float x, float y, float z, float radius, int p4) { invoke<Void>(0x733089E7, x, y, z, radius, p4); }
	static void GET_CUTSCENE_PED_POSITION(int unkped, ScrVector* pos) { invoke<Void>(0xA12A1645, unkped, pos); }
	static void GET_DRIVER_OF_CAR(Vehicle vehicle, Ped* pPed) { invoke<Void>(0xA73CE2DA, vehicle, pPed); }
	static void GET_GROUP_FORMATION(int group, int* formation) { invoke<Void>(0x442C9C70, group, formation); }
	static void GET_GROUP_FORMATION_SPACING(int group, float* spacing) { invoke<Void>(0xB312E0FC, group, spacing); }
	static void GET_GROUP_LEADER(Group group, Ped* pPed) { invoke<Void>(0xD4ADDB85, group, pPed); }
	static void GET_GROUP_MEMBER(Group group, uint32_t index, Ped* pPed) { invoke<Void>(0x301EC367, group, index, pPed); }
	static void GET_GROUP_SIZE(Group group, uint32_t* pStartIndex, uint32_t* pCount) { invoke<Void>(0xF7E1A691, group, pStartIndex, pCount); }
	static void GET_NTH_GROUP_MEMBER(int group, int n, Ped* ped) { invoke<Void>(0x3B70C0DE, group, n, ped); }
	static void GET_NUMBER_OF_FOLLOWERS(Ped ped, int* followers) { invoke<Void>(0xCCD6E5B7, ped, followers); }
	static void GET_PED_BONE_POSITION(Ped ped, uint32_t bone, float x, float y, float z, ScrVector *pPosition) { invoke<Void>(0xC8395A2C, ped, bone, x, y, z, pPosition); }
	static void GET_PED_GROUP_INDEX(Ped ped, uint32_t* pIndex) { invoke<Void>(0x134E0785, ped, pIndex); }
	static void GET_PED_TYPE(Ped ped, uint32_t* pType) { invoke<Void>(0xB1460D43, ped, pType); }
	static void GET_SCRIPT_TASK_STATUS(Ped ped, int task, int* status) { invoke<Void>(0xB2477B23, ped, task, status); }
	static void GIVE_PED_AMBIENT_OBJECT(Ped ped, uint32_t model) { invoke<Void>(0xB4140A3C, ped, model); }
	static void GIVE_PED_FAKE_NETWORK_NAME(Ped ped, const char* name, int r, int g, int b, int a) { invoke<Void>(0xBA223E7B, ped, name, r, g, b, a); }
	static void GIVE_PED_HELMET(Ped ped) { invoke<Void>(0x1862A461, ped); }
	static void GIVE_PED_HELMET_WITH_OPTS(Ped ped, BOOL p1) { invoke<Void>(0x0BEC2729, ped, p1); }
	static void GIVE_PED_PICKUP_OBJECT(Ped ped, Object obj, BOOL flag) { invoke<Void>(0x3B653867, ped, obj, flag); }
	static void KNOCK_PED_OFF_BIKE(Vehicle vehicle) { invoke<Void>(0x98200D3C, vehicle); }
	static void PED_QUEUE_CONSIDER_PEDS_WITH_FLAG_FALSE(int flagid) { invoke<Void>(0x1B01F931, flagid); }
	static void PED_QUEUE_CONSIDER_PEDS_WITH_FLAG_TRUE(int flagid) { invoke<Void>(0x4D2F2888, flagid); }
	static void PED_QUEUE_REJECT_PEDS_WITH_FLAG_FALSE(int flagid) { invoke<Void>(0xA80135AB, flagid); }
	static void PED_QUEUE_REJECT_PEDS_WITH_FLAG_TRUE(int flagid) { invoke<Void>(0xBA0856C7, flagid); }
	static void REGISTER_HATED_TARGETS_AROUND_PED(Ped ped, float radius) { invoke<Void>(0x7F87559E, ped, radius); }
	static void REGISTER_HATED_TARGETS_IN_AREA(Ped ped, float x, float y, float z, float radius) { invoke<Void>(0x53CEFAA1, ped, x, y, z, radius); }
	static void REGISTER_TARGET(Ped ped, Ped target) { invoke<Void>(0x50A95442, ped, target); }
	static void REMOVE_CLOSE_MIC_PED(Ped ped) { invoke<Void>(0x3976C9B6, ped); }
	static void REMOVE_FAKE_NETWORK_NAME_FROM_PED(Ped ped) { invoke<Void>(0xAB07F041, ped); }
	static void REMOVE_GROUP(Group group) { invoke<Void>(0x48D72B88, group); }
	static void REMOVE_PED_HELMET(Ped ped, BOOL removed) { invoke<Void>(0x2086B1F0, ped, removed); }
	static void RESET_VISIBLE_PED_DAMAGE(Ped ped) { invoke<Void>(0xFA19568C, ped); }
	static void REVIVE_INJURED_PED(Ped ped) { invoke<Void>(0x14D3E6E3, ped); }
	static void SEARCH_CRITERIA_CONSIDER_PEDS_WITH_FLAG_FALSE(int flagid) { invoke<Void>(0x38151144, flagid); }
	static void SEARCH_CRITERIA_CONSIDER_PEDS_WITH_FLAG_TRUE(uint32_t flagId) { invoke<Void>(0x611870D2, flagId); }
	static void SEARCH_CRITERIA_REJECT_PEDS_WITH_FLAG_FALSE(int flagid) { invoke<Void>(0x7659E4DA, flagid); }
	static void SEARCH_CRITERIA_REJECT_PEDS_WITH_FLAG_TRUE(uint32_t flagId) { invoke<Void>(0x044EC539, flagId); }
	static void SEND_NM_MESSAGE(Ped ped) { invoke<Void>(0x13DEBC94, ped); }
	static void SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Ped ped, BOOL value) { invoke<Void>(0xDFE34E4A, ped, value); }
	static void SET_BRIANS_MOOD(int mood) { invoke<Void>(0x7FF92CD4, mood); }
	static void SET_COLLIDE_WITH_PEDS(BOOL set) { invoke<Void>(0x2F086A44, set); }
	static void SET_DEAD_PEDS_DROP_WEAPONS(BOOL set) { invoke<Void>(0x197472B9, set); }
	static void SET_DEATH_WEAPONS_PERSIST(Ped ped, BOOL set) { invoke<Void>(0xA07E10C8, ped, set); }
	static void SET_GROUP_FOLLOW_STATUS(Group group, uint32_t status) { invoke<Void>(0x865B9DAC, group, status); }
	static void SET_GROUP_FORMATION(Group group, uint32_t formation) { invoke<Void>(0x08FAC739, group, formation); }
	static void SET_GROUP_FORMATION_SPACING(Group group, float space) { invoke<Void>(0xB1E086FF, group, space); }
	static void SET_GROUP_LEADER(Group group, Ped leader) { invoke<Void>(0x2F3C5E08, group, leader); }
	static void SET_GROUP_MEMBER(Group group, Ped member) { invoke<Void>(0x0D3DDA88, group, member); }
	static void SET_GROUP_SEPARATION_RANGE(Group group, float seperation) { invoke<Void>(0x7B820CD5, group, seperation); }
	static void SET_HEADING_LIMIT_FOR_ATTACHED_PED(Ped ped, float heading0, float heading1) { invoke<Void>(0xA7813774, ped, heading0, heading1); }
	static void SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(Ped ped, BOOL value) { invoke<Void>(0xA3D675ED, ped, value); }
	static void SET_INFORM_RESPECTED_FRIENDS(Ped ped, int p1, int p2) { invoke<Void>(0x8040FEE5, ped, p1, p2); }
	static void SET_MIN_MAX_PED_ACCURACY(Ped ped, float min, float max) { invoke<Void>(0xFEB28C0B, ped, min, max); }
	static void SET_MONEY_CARRIED_BY_ALL_NEW_PEDS(int money) { invoke<Void>(0x1F6B807E, money); }
	static void SET_MONEY_CARRIED_BY_PED_WITH_MODEL(uint32_t model, int m0, int m1) { invoke<Void>(0x1DFEFF51, model, m0, m1); }
	static void SET_NM_ANIM_POSE(Ped ped, const char* AnimName0, const char* AnimName1, float pose) { invoke<Void>(0xF08CE199, ped, AnimName0, AnimName1, pose); }
	static void SET_NM_MESSAGE_BOOL(int id, BOOL value) { invoke<Void>(0xAEF25DC5, id, value); }
	static void SET_NM_MESSAGE_FLOAT(int id, float value) { invoke<Void>(0xE2959702, id, value); }
	static void SET_NM_MESSAGE_INSTANCE_INDEX(int id, Ped ped, Vehicle car, Object obj) { invoke<Void>(0xC8B5DFE3, id, ped, car, obj); }
	static void SET_NM_MESSAGE_INT(int id, int value) { invoke<Void>(0x7FA76EE4, id, value); }
	static void SET_NM_MESSAGE_STRING(int id, const char* string) { invoke<Void>(0x7A0DF013, id, string); }
	static void SET_NM_MESSAGE_VEC3(int id, float x, float y, float z) { invoke<Void>(0x535F6DCE, id, x, y, z); }
	static void SET_PED_ALLOW_MISSION_ONLY_DRIVEBY_USE(Ped ped, BOOL set) { invoke<Void>(0xFF94F468, ped, set); }
	static void SET_PED_ALPHA(Ped ped, int alpha) { invoke<Void>(0xB94DA9B3, ped, alpha); }
	static void SET_PED_DENSITY_MULTIPLIER(float density) { invoke<Void>(0x87FDB5D1, density); }
	static void SET_PED_DIES_WHEN_INJURED(Ped ped, BOOL value) { invoke<Void>(0xE94E24D4, ped, value); }
	static void SET_PED_DONT_DO_EVASIVE_DIVES(Ped ped, BOOL value) { invoke<Void>(0xF708995B, ped, value); }
	static void SET_PED_DONT_USE_VEHICLE_SPECIFIC_ANIMS(Ped ped, BOOL set) { invoke<Void>(0x23108373, ped, set); }
	static void SET_PED_ENABLE_LEG_IK(Ped ped, BOOL set) { invoke<Void>(0xBFFB6621, ped, set); }
	static void SET_PED_FALL_OFF_BIKES_WHEN_SHOT(Ped ped, BOOL set) { invoke<Void>(0xC92C80C5, ped, set); }
	static void SET_PED_FIRE_FX_LOD_SCALER(float scale) { invoke<Void>(0xDEEDEF2A, scale); }
	static void SET_PED_FORCE_FLY_THROUGH_WINDSCREEN(Ped ped, BOOL set) { invoke<Void>(0xF7FDD0F1, ped, set); }
	static void SET_PED_FORCE_VISUALISE_HEAD_DAMAGE_FROM_BULLETS(Ped ped, BOOL set) { invoke<Void>(0x51CE8949, ped, set); }
	static void SET_PED_GENERATES_DEAD_BODY_EVENTS(Ped ped, BOOL set) { invoke<Void>(0xE9B97A2B, ped, set); }
	static void SET_PED_HEEDS_THE_EVERYONE_IGNORE_PLAYER_FLAG(Ped ped, BOOL set) { invoke<Void>(0x31A06AF4, ped, set); }
	static void SET_PED_HELI_PILOT_RESPECTS_MINIMUMM_HEIGHT(Ped ped, BOOL set) { invoke<Void>(0x9BDDB55E, ped, set); }
	static void SET_PED_HELMET_TEXTURE_INDEX(Ped ped, int index) { invoke<Void>(0x5F6C3328, ped, index); }
	static void SET_PED_INSTANT_BLENDS_WEAPON_ANIMS(Ped ped, BOOL set) { invoke<Void>(0x53D1E327, ped, set); }
	static void SET_PED_IS_BLIND_RAGING(Ped ped, BOOL value) { invoke<Void>(0x724A81BF, ped, value); }
	static void SET_PED_IS_DRUNK(Ped ped, BOOL value) { invoke<Void>(0xD2EA77A3, ped, value); }
	static void SET_PED_MOBILE_RING_TYPE(Ped ped, int RingtoneId) { invoke<Void>(0x98EACA79, ped, RingtoneId); }
	static void SET_PED_MOTION_BLUR(Ped ped, BOOL set) { invoke<Void>(0xA211A128, ped, set); }
	static void SET_PED_NON_CREATION_AREA(float x0, float y0, float z0, float x1, float y1, float z1) { invoke<Void>(0x7A97283F, x0, y0, z0, x1, y1, z1); }
	static void SET_PED_NON_REMOVAL_AREA(float x0, float y0, float z0, float x1, float y1, float z1) { invoke<Void>(0x599D82E7, x0, y0, z0, x1, y1, z1); }
	static void SET_PED_PATH_MAY_DROP_FROM_HEIGHT(Ped ped, BOOL value) { invoke<Void>(0x11D93DA1, ped, value); }
	static void SET_PED_PATH_MAY_USE_CLIMBOVERS(Ped ped, BOOL value) { invoke<Void>(0xEF821257, ped, value); }
	static void SET_PED_PATH_MAY_USE_LADDERS(Ped ped, BOOL value) { invoke<Void>(0x45F69AC1, ped, value); }
	static void SET_PED_PATH_WILL_AVOID_DYNAMIC_OBJECTS(Ped ped, BOOL set) { invoke<Void>(0x48E5A279, ped, set); }
	static void SET_PED_SKIPS_COMPLEX_COVER_COLLISION_CHECKS(Ped ped, BOOL set) { invoke<Void>(0xA673B7C6, ped, set); }
	static void SET_PED_STEERS_AROUND_OBJECTS(Ped ped, BOOL set) { invoke<Void>(0x3BD9B0A6, ped, set); }
	static void SET_PED_STEERS_AROUND_PEDS(Ped ped, BOOL set) { invoke<Void>(0x797CAE4F, ped, set); }
	static void SET_PED_WINDY_CLOTHING_SCALE(Ped ped, float scale) { invoke<Void>(0x1BDC74F9, ped, scale); }
	static void SET_PED_WITH_BRAIN_CAN_BE_CONVERTED_TO_DUMMY_PED(Ped ped, BOOL set) { invoke<Void>(0x71060A53, ped, set); }
	static void SET_REDUCE_PED_MODEL_BUDGET(BOOL set) { invoke<Void>(0xAFCB2B86, set); }
	static void SET_RELATIONSHIP(uint32_t relationshipLevel, eRelationshipGroup relationshipGroup1, eRelationshipGroup relationshipGroup2) { invoke<Void>(0xC94B8622, relationshipLevel, relationshipGroup1, relationshipGroup2); }
	static void SET_ROMANS_MOOD(int moood) { invoke<Void>(0x6ADFBD5D, moood); }
	static void SET_ROTATION_FOR_ATTACHED_PED(Ped ped, float xr, float yr, float zr) { invoke<Void>(0xF85CE5FB, ped, xr, yr, zr); }
	static void SET_SCENARIO_PED_DENSITY_MULTIPLIER(float density, float densitynext) { invoke<Void>(0x874B05BE, density, densitynext); }
	static void SET_SCRIPTED_ANIM_SEAT_OFFSET(Ped ped, float offset) { invoke<Void>(0x7CEFFA45, ped, offset); }
	static void SET_SENSE_RANGE(Ped ped, float value) { invoke<Void>(0xE0FA2400, ped, value); }
	static void SET_SPECIFIC_PASSENGER_INDEX_TO_USE_IN_GROUPS(Ped ped, int index) { invoke<Void>(0x6BE47B20, ped, index); }
	static void SET_SWIM_SPEED(Ped ped, float speed) { invoke<Void>(0x00CE7C16, ped, speed); }
	static void STOP_PED_DOING_FALL_OFF_TESTS_WHEN_SHOT(Ped ped) { invoke<Void>(0x5B01902A, ped); }
	static void STOP_PED_MOBILE_RINGING(Ped ped) { invoke<Void>(0x7B89BCC9, ped); }
	static void STOP_PED_SPEAKING(Ped ped, BOOL stopspeaking) { invoke<Void>(0xFF92B49D, ped, stopspeaking); }
	static void STOP_PED_WEAPON_FIRING_WHEN_DROPPED(Ped ped) { invoke<Void>(0x4AC3421E, ped); }
	static void SUPPRESS_PED_MODEL(uint32_t model) { invoke<Void>(0x52B0F091, model); }
	static void SWITCH_PED_TO_ANIMATED(Ped ped, BOOL unknownTrue) { invoke<Void>(0x02FA5C99, ped, unknownTrue); }
	static void UNLOCK_RAGDOLL(Ped ped, BOOL value) { invoke<Void>(0x860B7F20, ped, value); }
	static void UPDATE_PED_PHYSICAL_ATTACHMENT_POSITION(Ped ped, float x0, float y0, float z0, float x1, float y1) { invoke<Void>(0x9C91B2FF, ped, x0, y0, z0, x1, y1); }
}

namespace VEHICLE
{
	static BOOL ARE_TAXI_LIGHTS_ON(Vehicle vehicle) { return invoke<BOOL>(0xE4518021, vehicle); }
	static BOOL CAN_BE_DESCRIBED_AS_A_CAR(Vehicle veh) { return invoke<BOOL>(0xA7A49DAD, veh); }
	static BOOL CHECK_STUCK_TIMER(Vehicle car, int timernum, int timeout) { return invoke<BOOL>(0x6EEE10DA, car, timernum, timeout); }
	static BOOL CREATE_EMERGENCY_SERVICES_CAR(uint32_t model, float x, float y, float z) { return invoke<BOOL>(0x72625256, model, x, y, z); }
	static BOOL CREATE_EMERGENCY_SERVICES_CAR_RETURN_DRIVER(uint32_t model, float x, float y, float z, Vehicle* car, Ped* cardriver, Ped* carpass) { return invoke<BOOL>(0x42825C00, model, x, y, z, car, cardriver, carpass); }
	static BOOL CREATE_EMERGENCY_SERVICES_CAR_THEN_WALK(uint32_t model, float x, float y, float z) { return invoke<BOOL>(0x53E5166C, model, x, y, z); }
	static BOOL DOES_CAR_HAVE_HYDRAULICS(Vehicle car) { return invoke<BOOL>(0xA511F94D, car); }
	static BOOL DOES_CAR_HAVE_ROOF(Vehicle vehicle) { return invoke<BOOL>(0x5847F769, vehicle); }
	static BOOL DOES_CAR_HAVE_STUCK_CAR_CHECK(Vehicle vehicle) { return invoke<BOOL>(0x818BF53E, vehicle); }
	static BOOL DOES_VEHICLE_EXIST(Vehicle vehicle) { return invoke<BOOL>(0x8737CC23, vehicle); }
	static BOOL GET_IS_STICKY_BOMB_STUCK_TO_VEHICLE(Vehicle veh) { return invoke<BOOL>(0x8363AB28, veh); }
	static BOOL GET_VEHICLE_COMPONENT_INFO(Vehicle veh, int component_id, ScrVector* p2, ScrVector* p3, int* p4, BOOL flag) { return invoke<BOOL>(0xD4AF8E35, veh, component_id, p2, p3, p4, flag); }
	static BOOL HAS_CAR_BEEN_DAMAGED_BY_CAR(Vehicle vehicle, Vehicle otherCar) { return invoke<BOOL>(0x7887012B, vehicle, otherCar); }
	static BOOL HAS_CAR_BEEN_DAMAGED_BY_WEAPON(Vehicle vehicle, uint32_t weapon) { return invoke<BOOL>(0x05C65189, vehicle, weapon); }
	static BOOL HAS_CAR_BEEN_DROPPED_OFF(Vehicle car) { return invoke<BOOL>(0x2E9F07FF, car); }
	static BOOL HAS_CAR_BEEN_RESPRAYED(Vehicle vehicle) { return invoke<BOOL>(0xCF8019C1, vehicle); }
	static BOOL HAS_CAR_RECORDING_BEEN_LOADED(int CarRec) { return invoke<BOOL>(0xC147DD7E, CarRec); }
	static BOOL HAS_CAR_STOPPED_BECAUSE_OF_LIGHT(Vehicle car) { return invoke<BOOL>(0xBF167F23, car); }
	static BOOL HAS_CHAR_BEEN_DAMAGED_BY_CAR(Ped ped, Vehicle vehicle) { return invoke<BOOL>(0x471A674E, ped, vehicle); }
	static BOOL HAS_OBJECT_BEEN_DAMAGED_BY_CAR(Object obj, Vehicle vehicle) { return invoke<BOOL>(0xB3EF3F52, obj, vehicle); }
	static BOOL HAS_RESPRAY_HAPPENED() { return invoke<BOOL>(0x6755EAED); }
	static BOOL IS_BIG_VEHICLE(Vehicle vehicle) { return invoke<BOOL>(0x9CDBA8DE, vehicle); }
	static BOOL IS_CAR_ATTACHED(Vehicle vehicle) { return invoke<BOOL>(0xA2C118A0, vehicle); }
	static BOOL IS_CAR_A_MISSION_CAR(Vehicle vehicle) { return invoke<BOOL>(0xD5E5FDF7, vehicle); }
	static BOOL IS_CAR_DEAD(Vehicle vehicle) { return invoke<BOOL>(0xA9D6179F, vehicle); }
	static BOOL IS_CAR_DOOR_DAMAGED(Vehicle vehicle, uint32_t door) { return invoke<BOOL>(0xB1208711, vehicle, door); }
	static BOOL IS_CAR_DOOR_FULLY_OPEN(Vehicle vehicle, uint32_t door) { return invoke<BOOL>(0xAA0D97B5, vehicle, door); }
	static BOOL IS_CAR_HEALTH_GREATER(Vehicle car, float health) { return invoke<BOOL>(0x76833DC3, car, health); }
	static BOOL IS_CAR_IN_AIR_PROPER(Vehicle vehicle) { return invoke<BOOL>(0xE6A991DF, vehicle); }
	static BOOL IS_CAR_IN_AREA_2D(Vehicle vehicle, float x1, float y1, float x2, float y2, BOOL p5) { return invoke<BOOL>(0x49CB1827, vehicle, x1, y1, x2, y2, p5); }
	static BOOL IS_CAR_IN_AREA_3D(Vehicle vehicle, float x1, float y1, float z1, float x2, float y2, float z2, uint32_t unknownFalse) { return invoke<BOOL>(0xAEE6613C, vehicle, x1, y1, z1, x2, y2, z2, unknownFalse); }
	static BOOL IS_CAR_IN_GARAGE_AREA(const char* garageName, Vehicle vehicle) { return invoke<BOOL>(0xF7C3F8C9, garageName, vehicle); }
	static BOOL IS_CAR_IN_WATER(Vehicle vehicle) { return invoke<BOOL>(0x663B8371, vehicle); }
	static BOOL IS_CAR_LOW_RIDER(Vehicle car) { return invoke<BOOL>(0x58560132, car); }
	static BOOL IS_CAR_MODEL(Vehicle vehicle, uint32_t model) { return invoke<BOOL>(0x02A4AE3B, vehicle, model); }
	static BOOL IS_CAR_ON_FIRE(Vehicle vehicle) { return invoke<BOOL>(0xBED4EC63, vehicle); }
	static BOOL IS_CAR_ON_SCREEN(Vehicle vehicle) { return invoke<BOOL>(0xBDA8E007, vehicle); }
	static BOOL IS_CAR_PASSENGER_SEAT_FREE(Vehicle vehicle, uint32_t seatIndex) { return invoke<BOOL>(0x42758AD2, vehicle, seatIndex); }
	static BOOL IS_CAR_PLAYING_ANIM(Vehicle car, const char* animname0, const char* animname1) { return invoke<BOOL>(0x4BF743CD, car, animname0, animname1); }
	static BOOL IS_CAR_SIREN_ON(Vehicle vehicle) { return invoke<BOOL>(0xCAC9CF68, vehicle); }
	static BOOL IS_CAR_STOPPED(Vehicle vehicle) { return invoke<BOOL>(0x15F1C152, vehicle); }
	static BOOL IS_CAR_STOPPED_AT_TRAFFIC_LIGHTS(Vehicle vehicle) { return invoke<BOOL>(0x69BE8C73, vehicle); }
	static BOOL IS_CAR_STREET_RACER(Vehicle car) { return invoke<BOOL>(0x8FF76282, car); }
	static BOOL IS_CAR_STUCK(Vehicle car) { return invoke<BOOL>(0x204D61FB, car); }
	static BOOL IS_CAR_STUCK_ON_ROOF(Vehicle vehicle) { return invoke<BOOL>(0x6BE03428, vehicle); }
	static BOOL IS_CAR_TOUCHING_CAR(Vehicle vehicle, Vehicle otherCar) { return invoke<BOOL>(0x236FC815, vehicle, otherCar); }
	static BOOL IS_CAR_TYRE_BURST(Vehicle vehicle, uint32_t tyre) { return invoke<BOOL>(0xCE670FF4, vehicle, tyre); }
	static BOOL IS_CAR_UPRIGHT(Vehicle vehicle) { return invoke<BOOL>(0x6705B8B8, vehicle); }
	static BOOL IS_CAR_UPSIDEDOWN(Vehicle vehicle) { return invoke<BOOL>(0x4CCF1871, vehicle); }
	static BOOL IS_CAR_WAITING_FOR_WORLD_COLLISION(Vehicle vehicle) { return invoke<BOOL>(0xF718F943, vehicle); }
	static BOOL IS_CHAR_IN_CAR(Ped ped, Vehicle vehicle) { return invoke<BOOL>(0xD60A5A37, ped, vehicle); }
	static BOOL IS_CHAR_IN_MODEL(Ped ped, uint32_t model) { return invoke<BOOL>(0x04036010, ped, model); }
	static BOOL IS_CHAR_TOUCHING_VEHICLE(Ped ped, Vehicle vehicle) { return invoke<BOOL>(0x226A7914, ped, vehicle); }
	static BOOL IS_EMERGENCY_SERVICES_VEHICLE(Vehicle veh) { return invoke<BOOL>(0x6FAF6F0C, veh); }
	static BOOL IS_HELI_PART_BROKEN(Vehicle heli, BOOL flag0, BOOL flag1, BOOL flag2) { return invoke<BOOL>(0xF4E4C439, heli, flag0, flag1, flag2); }
	static BOOL IS_NEXT_STATION_ALLOWED(Vehicle veh) { return invoke<BOOL>(0x9C481718, veh); }
	static BOOL IS_PLAYBACK_GOING_ON_FOR_CAR(Vehicle car) { return invoke<BOOL>(0x70C8D82C, car); }
	static BOOL IS_THIS_MODEL_A_BIKE(uint32_t model) { return invoke<BOOL>(0x7E702CDD, model); }
	static BOOL IS_THIS_MODEL_A_BOAT(uint32_t model) { return invoke<BOOL>(0x10F6085C, model); }
	static BOOL IS_THIS_MODEL_A_CAR(uint32_t model) { return invoke<BOOL>(0x60E4C22F, model); }
	static BOOL IS_THIS_MODEL_A_HELI(uint32_t model) { return invoke<BOOL>(0x8AF7F568, model); }
	static BOOL IS_THIS_MODEL_A_PED(uint32_t model) { return invoke<BOOL>(0x73AA3B44, model); }
	static BOOL IS_THIS_MODEL_A_PLANE(uint32_t model) { return invoke<BOOL>(0x3B3907BB, model); }
	static BOOL IS_THIS_MODEL_A_TRAIN(uint32_t model) { return invoke<BOOL>(0xF87DCFFD, model); }
	static BOOL IS_THIS_MODEL_A_VEHICLE(uint32_t model) { return invoke<BOOL>(0x92B9DAD2, model); }
	static BOOL IS_VEHICLE_EXTRA_TURNED_ON(Vehicle vehicle, uint32_t extra) { return invoke<BOOL>(0x042098B5, vehicle, extra); }
	static BOOL IS_VEHICLE_ON_ALL_WHEELS(Vehicle vehicle) { return invoke<BOOL>(0x10089F8E, vehicle); }
	static BOOL IS_VEHICLE_TOUCHING_OBJECT(Vehicle veh, Object obj) { return invoke<BOOL>(0xB50AB968, veh, obj); }
	static BOOL IS_VEH_DRIVEABLE(Vehicle vehicle) { return invoke<BOOL>(0xDD161A1A, vehicle); }
	static BOOL IS_VEH_STUCK(Vehicle veh, Time time, BOOL flag0, BOOL flag1, BOOL flag2) { return invoke<BOOL>(0x308C5861, veh, time, flag0, flag1, flag2); }
	static BOOL IS_VEH_WINDOW_INTACT(Vehicle vehicle, uint32_t window) { return invoke<BOOL>(0x0A184AFA, vehicle, window); }
	static BOOL LOCATE_CAR_2D(Vehicle car, float x0, float y0, float xUnk48, float yUnk49, BOOL flag) { return invoke<BOOL>(0x4EDC0CBF, car, x0, y0, xUnk48, yUnk49, flag); }
	static BOOL LOCATE_CAR_3D(Vehicle car, float x, float y, float z, float xa, float ya, float za, BOOL flag) { return invoke<BOOL>(0x13B80E94, car, x, y, z, xa, ya, za, flag); }
	static BOOL LOCATE_DEAD_CAR_3D(Vehicle car, float x, float y, float z, float xa, float ya, float za, BOOL flag)  { return invoke<BOOL>(0xA95CBFA7, car, x, y, z, xa, ya, za, flag); }
	static BOOL PLAY_CAR_ANIM(Vehicle car, const char* animname0, const char* animname1, float Unk50, BOOL flag0, BOOL flag1) { return invoke<BOOL>(0x693EEF6A, car, animname0, animname1, Unk50, flag0, flag1); }
	static const char* GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(uint32_t model) { return invoke<const char*>(0xEC86DF39, model); }
	static const char* GET_STATION_NAME(Train train, uint32_t station) { return invoke<const char*>(0x62D15DE6, train, station); }
	static float FIND_POSITION_IN_RECORDING(Vehicle car) { return invoke<float>(0x8A585E98, car); }
	static float FIND_TIME_POSITION_IN_RECORDING(Vehicle car) { return invoke<float>(0xEBA01B48, car); }
	static float GET_ENGINE_HEALTH(Vehicle vehicle) { return invoke<float>(0x1236BACE, vehicle); }
	static float GET_HEIGHT_OF_VEHICLE(Vehicle vehicle, float x, float y, float z, BOOL unknownTrue1, BOOL unknownTrue2) { return invoke<float>(0x62990CD4, vehicle, x, y, z, unknownTrue1, unknownTrue2); }
	static float GET_PETROL_TANK_HEALTH(Vehicle vehicle) { return invoke<float>(0x96D3F96F, vehicle); }
	static float GET_TIME_TIL_NEXT_STATION(Vehicle train) { return invoke<float>(0x443BD51F, train); }
	static float GET_TOTAL_DURATION_OF_CAR_RECORDING(int CarRec) { return invoke<float>(0x29685201, CarRec); }
	static float GET_VEHICLE_ENGINE_REVS(Vehicle veh) { return invoke<float>(0xEC506DED, veh); }
	static int FIND_TRAIN_DIRECTION(Vehicle train) { return invoke<int>(0x4F2855B6, train); }
	static int GET_CAR_SIREN_HEALTH(Vehicle car) { return invoke<int>(0x6614790D, car); }
	static int GET_CURRENT_PLAYBACK_NUMBER_FOR_CAR(Vehicle car) { return invoke<int>(0x78086269, car); }
	static int GET_NUMBER_OF_STICKY_BOMBS_STUCK_TO_VEHICLE(Vehicle veh) { return invoke<int>(0xA2CB434A, veh); }
	static int GET_VEHICLE_GEAR(Vehicle veh) { return invoke<int>(0xCF9246C0, veh); }
	static int GET_VEHICLE_TYPE_OF_MODEL(uint32_t model) { return invoke<int>(0x6E53485D, model); }
	static int SET_HELI_FORCE_ENGINE_ON(Vehicle heli, BOOL set) { return invoke<int>(0x98B872D5, heli, set); }
	static Any SET_CAR_ON_GROUND_PROPERLY(Vehicle vehicle) { return invoke<Any>(0xFDA951D9, vehicle); }
	static uint32_t GET_CURRENT_STATION_FOR_TRAIN(Train train) { return invoke<uint32_t>(0x3B7DCCAA, train); }
	static uint32_t GET_VEHICLE_MODEL_FROM_INDEX(int index) { return invoke<uint32_t>(0x70691B3C, index); }
	static Vehicle GET_CAR_OBJECT_IS_ATTACHED_TO(Object obj) { return invoke<Vehicle>(0xBA5B5428, obj); }
	static Vehicle GET_CLOSEST_CAR(float x, float y, float z, float radius, BOOL unknownFalse, uint32_t unknown70) { return invoke<uint32_t>(0xCBCEC322, x, y, z, radius, unknownFalse, unknown70); }
	static void ACTIVATE_HELI_SPEED_CHEAT(Vehicle heli, int cheat) { invoke<Void>(0x426971EA, heli, cheat); }
	static void ADD_CAR_TO_MISSION_DELETION_LIST(Vehicle car) { invoke<Void>(0x77C876A6, car); }
	static void ADD_STUCK_CAR_CHECK(Vehicle car, float stuckdif, int timeout) { invoke<Void>(0x0C5DCAE4, car, stuckdif, timeout); }
	static void ADD_STUCK_CAR_CHECK_WITH_WARP(Vehicle car, float stuckdif, int time, BOOL flag0, BOOL flag1, BOOL flag2, BOOL flag3) { invoke<Void>(0x3163E9FC, car, stuckdif, time, flag0, flag1, flag2, flag3); }
	static void ADD_UPSIDEDOWN_CAR_CHECK(Vehicle vehicle) { invoke<Void>(0x3163E9FC, vehicle); }
	static void ANCHOR_BOAT(Vehicle boat, BOOL anchor) { invoke<Void>(0x0CD3E50B, boat, anchor); }
	static void APPLY_FORCE_TO_CAR(Vehicle vehicle, uint32_t unknown0_3, float x, float y, float z, float spinX, float spinY, float spinZ, uint32_t unknown4_0, uint32_t unknown5_1, uint32_t unknown6_1, uint32_t unknown7_1) { invoke<Void>(0x3343A65B, vehicle, x, y, z, spinX, spinY, spinZ, unknown4_0, unknown5_1, unknown6_1, unknown7_1); }
	static void ATTACH_CAR_TO_CAR(Vehicle car0, Vehicle car1, int p2, float x0, float y0, float z0, float x1, float y1, float z1) { invoke<Void>(0x59D32723, car0, car1, p2, x0, y0, z0, x1, y1, z1); }
	static void ATTACH_CAR_TO_CAR_PHYSICALLY(int vehid1, int vehid2, BOOL p2, int p3, float xoffset, float yoffset, float zoffset, float xbuffer, float ybuffer, float zbuffer, float xrotateveh1, float yrotateveh1, float p12, float p13, float p14) { invoke<Void>(0xA26C136A, vehid1, vehid2, p2, p3, xoffset, yoffset, zoffset, xrotateveh1, yrotateveh1, p12, p13, p14); }
	static void ATTACH_CAR_TO_OBJECT(Vehicle car, Object obj, float p2, float p3, float p4, float p5, float p6, float p7, float p8) { invoke<Void>(0x1FFED3EB, car, obj, p2, p3, p4, p5, p6, p7, p8); }
	static void ATTACH_PED_TO_CAR(Ped ped, Vehicle vehicle, uint32_t unknown0_0, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, BOOL p8, BOOL p9) { invoke<Void>(0x95EC13EB, ped, vehicle, unknown0_0, offsetX, offsetY, offsetZ, rotX, rotY, p8, p9); }
	static void BREAK_CAR_DOOR(Vehicle vehicle, uint32_t door, BOOL unknownFalse) { invoke<Void>(0x085A6405, vehicle, door, unknownFalse); }
	static void BURST_CAR_TYRE(Vehicle vehicle, uint32_t tyre) { invoke<Void>(0xBA77AEC8, vehicle, tyre); }
	static void CHANGE_CAR_COLOUR(Vehicle vehicle, Colour colour1, Colour colour2) { invoke<Void>(0xDBE7F83D, vehicle, colour1, colour2); }
	static void CHANGE_PLAYBACK_TO_USE_AI(Vehicle car) { invoke<Void>(0x58CB1AD5, car); }
	static void CLEAR_CAR_LAST_DAMAGE_ENTITY(Vehicle vehicle) { invoke<Void>(0xA1C2E905, vehicle); }
	static void CLEAR_CAR_LAST_WEAPON_DAMAGE(Vehicle vehicle) { invoke<Void>(0x8DC580AC, vehicle); }
	static void CLEAR_ROOM_FOR_CAR(Vehicle vehicle) { invoke<Void>(0x834F3BFF, vehicle); }
	static void CLOSE_ALL_CAR_DOORS(Vehicle vehicle) { invoke<Void>(0xBE30BED0, vehicle); }
	static void CONTROL_CAR_DOOR(Vehicle vehicle, uint32_t door, uint32_t unknown_maybe_open, float angle) { invoke<Void>(0xB727E6CF, vehicle, door, unknown_maybe_open, angle); }
	static void CREATE_CAR(uint32_t nameHash, float x, float y, float z, Vehicle* pVehicle, BOOL unknownTrue) { invoke<Void>(0x8B3FED78, nameHash, x, y, z, pVehicle, unknownTrue); }
	static void CREATE_CARS_ON_GENERATORS_IN_AREA(float x0, float y0, float z0, float x1, float y1, float z1) { invoke<Void>(0xBE065299, x0, y0, z0, x1, y1, z1); }
	static void CREATE_CAR_GENERATOR(float x, float y, float z, float yaw, float pitch, float roll, uint32_t model, uint32_t color1, uint32_t color2, uint32_t spec1, uint32_t spec2, int Unk66, BOOL alarm, BOOL doorlock, int* handle)
	{
		invoke<Void>(0x6CF7388D, x, y, z, yaw, pitch, roll, model, color1, color2, spec1, spec2, Unk66, alarm, doorlock, handle);
	}
	static void CREATE_MISSION_TRAIN(uint32_t unknown1, float x, float y, float z, BOOL unknown2, Train* pTrain) { invoke<Void>(0xD4C2EAFD, unknown1, x, y, z, unknown2, pTrain); }
	static void CREATE_RANDOM_CAR_FOR_CAR_PARK(float x, float y, float z, float radius) { invoke<Void>(0x0BA883B6, x, y, z, radius); }
	static void CREATE_RANDOM_CHAR_AS_DRIVER(Vehicle vehicle, Ped* pPed) { invoke<Void>(0x409383BF, vehicle, pPed); }
	static void DAMAGE_CAR(Vehicle car, float x, float y, float z, float unkforce0, float unkforce1, BOOL flag) { invoke<Void>(0x1E62C15B, car, x, y, z, unkforce0, unkforce1, flag); }
	static void DELETE_ALL_TRAINS() { invoke<Void>(0x83DE7ABF); }
	static void DELETE_CAR(Vehicle* pVehicle) { invoke<Void>(0x0D4680B4, pVehicle); }
	static void DELETE_CAR_GENERATOR(int handle) { invoke<Void>(0x24B25F34, handle); }
	static void DELETE_MISSION_TRAIN(Train* pTrain) { invoke<Void>(0x86C9497D, pTrain); }
	static void DELETE_MISSION_TRAINS() { invoke<Void>(0x8CA24934); }
	static void DETACH_CAR(Vehicle vehicle) { invoke<Void>(0xC2BD8CD2, vehicle); }
	static void DISABLE_CAR_GENERATORS(BOOL flag0, BOOL flag1) { invoke<Void>(0x8A5BBA90, flag0, flag1); }
	static void DISABLE_CAR_GENERATORS_WITH_HELI(BOOL disable) { invoke<Void>(0x93F50422, disable); }
	static void DONT_SUPPRESS_ANY_CAR_MODELS() { invoke<Void>(0x10F90FC5); }
	static void DONT_SUPPRESS_CAR_MODEL(uint32_t model) { invoke<Void>(0xCB1D5557, model); }
	static void ENABLE_GPS_IN_VEHICLE(Vehicle veh, BOOL enable) { invoke<Void>(0x46A845AC, veh, enable); }
	static void FIX_CAR(Vehicle vehicle) { invoke<Void>(0x5ADE88C7, vehicle); }
	static void FIX_CAR_TYRE(Vehicle vehicle, uint32_t tyre) { invoke<Void>(0x065D8CF4, vehicle, tyre); }
	static void FORCE_ALL_VEHICLE_LIGHTS_OFF(BOOL off) { invoke<Void>(0x7C1B8647, off); }
	static void FORCE_CAR_LIGHTS(Vehicle car, int lights) { invoke<Void>(0xDB0CDD44, car, lights); }
	static void FORCE_GENERATE_PARKED_CARS_TOO_CLOSE_TO_OTHERS(BOOL set) { invoke<Void>(0x42697DC8, set); }
	static void FORCE_RANDOM_CAR_MODEL(uint32_t hash) { invoke<Void>(0x9B16D31F, hash); }
	static void FREEZE_CAR_POSITION(Vehicle vehicle, BOOL frozen) { invoke<Void>(0xB1E61D60, vehicle, frozen); }
	static void FREEZE_CAR_POSITION_AND_DONT_LOAD_COLLISION(Vehicle vehicle, BOOL frozen) { invoke<Void>(0xC136BCA3, vehicle, frozen); }
	static void GET_CAR_ANIM_CURRENT_TIME(Vehicle car, const char* animname0, const char* animname1, float* time) { invoke<Void>(0x4B47EB16, car, animname0, animname1, time); }
	static void GET_CAR_ANIM_TOTAL_TIME(Vehicle car, const char* animname0, const char* animname1, float* time) { invoke<Void>(0xFE080F08, car, animname0, animname1, time); }
	static void GET_CAR_BLOCKING_CAR(Vehicle car0, Vehicle* car1) { invoke<Void>(0x457D1EDE, car0, car1); }
	static void GET_CAR_CHAR_IS_USING(Ped ped, Vehicle* pVehicle) { invoke<Void>(0x73EA87E1, ped, pVehicle); }
	static void GET_CAR_COLOURS(Vehicle vehicle, Colour* pColour1, Colour* pColour2) { invoke<Void>(0x4C637C64, vehicle, pColour1, pColour2); }
	static void GET_CAR_COORDINATES(Vehicle vehicle, float* pX, float* pY, float* pZ) { invoke<Void>(0x6D72044F, vehicle, pX, pY, pZ); }

}

namespace GRAPHICS
{
	static BOOL HAS_STREAMED_TXD_LOADED(const char* txdName) { return invoke<BOOL>(0x0B955AAA, txdName); }
	static void REQUEST_STREAMED_TXD(const char* txdName, BOOL unknown) { invoke<Void>(0x9C4B3AE4, txdName, unknown); }
	static void DRAW_SPRITE(char* Type, char* IconType, float X, float Y, float Z, float width, float height, int RED, int GREEN, int BLUE, int Alpha) { invoke<Void>(0x1FEC16B0, Type, IconType, X, Y, Z, width, height, RED, GREEN, BLUE, Alpha); } // 0x1FEC16B0
	static void DRAW_RECT(float x1, float y1, float x2, float y2, uint32_t r, uint32_t g, uint32_t b, uint32_t a) { invoke<Void>(0xDD2BFC77, x1, y1, x2, y2, r, g, b, a); }
	static void DRAW_FRONTEND_HELPER_TEXT(const char* str0, const char* str1, BOOL p2) { invoke<Void>(0xA486E58C, str0, str1, p2); }
	static void DRAW_LIGHT_WITH_RANGE(float x, float y, float z, int r, int g, int b, float width, float height) { invoke<Void>(0x6A396E9A, x, y, z, r, g, b, width, height); }
	static void GET_FRAME_TIME(float* time) { invoke<Void>(0x96374262, time); }
	static BOOL GET_IS_HIDEF() { return invoke<BOOL>(0x1C340359); }
	static void GET_SCREEN_RESOLUTION(int* x, int* y) { invoke<Void>(0x29F3572F, x, y); }
	static void ARE_WIDESCREEN_BORDERS_ACTIVE() { invoke<Void>(0x4E26746C); }
	static BOOL GET_IS_WIDESCREEN() { return invoke<BOOL>(0xEC717AEF); }
	static float GET_LINE_HEIGHT() { return invoke<float>(0xF7FC5794); }
	static int GET_FRAME_COUNT() { return invoke<int>(0xB477A015); }
	static int GET_NUMBER_LINES(float p0, float p1, const char* str) { return invoke<int>(0x8AFECC9B, p0, p1, str); }
	static int GET_NUMBER_LINES_WITH_LITERAL_STRINGS(float p0, float p1, const char* str1, const char* str2, const char* str3)
	{
		return invoke<int>(0x01CBFDFF, p0, p1, str1, str2, str3);
	}
	static int GET_NUMBER_LINES_WITH_SUBSTRINGS(float p0, float p1, const char* str1, const char* str2, const char* str3)
	{
		return invoke<int>(0xD172184D, p0, p1, str1, str2, str3);

	}
	static uint32_t CREATE_CHECKPOINT(int type, float x, float y, float z, float p4, float p5) { return invoke<uint32_t>(0xF541B690, type, x, y, z, p4, p5); }
	static void DELETE_CHECKPOINT(uint32_t checkpoint) { invoke<Void>(0xB66CF3CA, checkpoint); }
	static void DISABLE_END_CREDITS_FADE() { invoke<Void>(0xD272A818); }

}

namespace STREAMING
{
	static BOOL HAS_COLLISION_FOR_MODEL_LOADED(uint32_t model) { return invoke<BOOL>(0x41A094F8, model); }
	static BOOL HAS_MODEL_LOADED(uint32_t model) { return invoke<BOOL>(0x62BFDB37, model); }
	static BOOL HAS_THIS_ADDITIONAL_TEXT_LOADED(const char* textName, uint32_t textIndex) { return invoke<BOOL>(0x80A52040, textName, textIndex); }
	static BOOL HAVE_ANIMS_LOADED(const char* animName) { return invoke<BOOL>(0x6720D74C, animName); }
	static BOOL HAVE_REQUESTED_PATH_NODES_BEEN_LOADED(uint32_t requestId) { return invoke<BOOL>(0x5BCEDBCE, requestId); }
	static BOOL IS_MODEL_IN_CDIMAGE(uint32_t model) { return invoke<BOOL>(0x1094782F, model); }
	static BOOL IS_STREAMING_ADDITIONAL_TEXT(uint32_t textIndex) { return invoke<BOOL>(0xF079E4EB, textIndex); }
	static BOOL IS_STREAMING_PRIORITY_REQUESTS() { return invoke<BOOL>(0xD2E1E5DC); } 
	static BOOL IS_STREAMING_THIS_ADDITIONAL_TEXT(const char* str0, int p1, int p2) { return invoke<BOOL>(0x6FF430BC, str0, p1, p2); }
	static BOOL PRELOAD_STREAM(const char* name) { return invoke<BOOL>(0xE2370818, name); }
	static BOOL PRELOAD_STREAM_WITH_START_OFFSET(const char* StreamName, int StartOffset) { return invoke<BOOL>(0x2EF50480, StreamName, StartOffset); }
	static BOOL REMOVE_NAVMESH_REQUIRED_REGION(float p0, float p1) { return invoke<BOOL>(0xE33208D6, p0, p1); }
	static BOOL UPDATE_LOAD_SCENE() { return invoke<BOOL>(0x9A31BD09); }
	static void ADD_ADDITIONAL_POPULATION_MODEL(uint32_t model) { invoke<Void>(0x0251DD25, model); }
	static void ENABLE_SCENE_STREAMING(BOOL enable) { invoke<Void>(0xEF6D0CA9, enable); }
	static void FINISH_STREAMING_REQUEST_LIST() { invoke<Void>(0xF5F30A8A); }
	static void GET_MODEL_DIMENSIONS(uint32_t model, ScrVector* pMinVector, ScrVector* pMaxVector) { invoke<Void>(0x91ABB8E0, model, pMinVector, pMaxVector); }
	static void LOAD_ALL_OBJECTS_NOW() { invoke<Void>(0xC9DBDA90); }
	static void LOAD_SCENE(float x, float y, float z) { invoke<Void>(0xB72403F5, x, y, z); }
	static void LOAD_SCENE_FOR_ROOM_BY_KEY(int interior, uint32_t roomhash) { invoke<Void>(0x2CE2EEF9, interior, roomhash); }
	static void MARK_MODEL_AS_NO_LONGER_NEEDED(uint32_t model) { invoke<Void>(0xE1FE3FDF, model); }
	static BOOL HAS_STREAMED_TXD_LOADED(const char* txdName) { return invoke<BOOL>(0x0B955AAA, txdName); }
	static void MARK_STREAMED_TXD_AS_NO_LONGER_NEEDED(const char* txdName) { invoke<Void>(0x92593BE4, txdName); }
	static void REQUEST_STREAMED_TXD(const char* txdName, BOOL unknown) { invoke<Void>(0x9C4B3AE4, txdName, unknown); }
	static void REMOVE_ADDITIONAL_POPULATION_MODEL(uint32_t model) { invoke<Void>(0x5B41B517, model); }
	static void REMOVE_ALL_INACTIVE_GROUPS_FROM_CLEANUP_LIST() { invoke<Void>(0x6B0D3DCC); }
	static void REMOVE_ANIMS(const char* animName) { invoke<Void>(0x27B551AA, animName); }
	static void REMOVE_IPL(const char* iplName) { invoke<Void>(0xDF7CBD36, iplName); }
	static void REMOVE_IPL_DISCREETLY(const char* iplname) { invoke<Void>(0x125B1802, iplname); }
	static void REMOVE_TXD(TextureDict txd) { invoke<Void>(0x87A1CC5B, txd); }
	static void REQUEST_ADDITIONAL_TEXT(const char* textName, uint32_t textIndex) { invoke<Void>(0x9FA9175B, textName, textIndex); }
	static void REQUEST_ALL_SLODS_IN_WORLD() { invoke<Void>(0xA28ED628); }
	static void REQUEST_ANIMS(const char* animName) { invoke<Void>(0x94B10254, animName); }
	static void REQUEST_CAR_RECORDING(int CarRecId) { invoke<Void>(0xB310B81E, CarRecId); }
	static void REQUEST_COLLISION_AT_POSN(float x, float y, float z) { invoke<Void>(0xD5CD7371, x, y, z); }
	static void REQUEST_COLLISION_FOR_MODEL(uint32_t model) { invoke<Void>(0x3930C042, model); }
	static void REQUEST_INTERIOR_MODELS(uint32_t model, const char* interiorName) { invoke<Void>(0x0514857A, model, interiorName); }
	static void REQUEST_IPL(const char* iplName) { invoke<Void>(0x3B70D1DB, iplName); }
	static void REQUEST_MODEL(uint32_t model) { invoke<Void>(0xFFF1B500, model); }
	static void SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(uint32_t model, float x, float y, float z, int state, float p5) { invoke<Void>(0x38C951A4, model, x, y, z, state, p5); }
	static void SET_STREAMING_REQUEST_LIST_TIME(Time time) { invoke<Void>(0x2E95CDFE, time); }
	static void SET_STREAM_PARAMS(float rolloff, Time UnkTime) { invoke<Void>(0xBDE09C4E, rolloff, UnkTime); }
	static void SIMULATE_UPDATE_LOAD_SCENE() { invoke<Void>(0xE980CEE1); }
	static void START_LOAD_SCENE(float x, float y, float z) { invoke<Void>(0x9843B07F, x, y, z); }
	static void START_STREAMING_REQUEST_LIST(const char* name) { invoke<Void>(0x71998338, name); }
	static void STOP_STREAM() { invoke<Void>(0xD1E364DE); }
	static Texture GET_TEXTURE(TextureDict dictionary, const char* textureName) { return invoke<Texture>(0x6DC9C895, dictionary, textureName); }
	static Texture GET_TEXTURE_FROM_STREAMED_TXD(const char* txdName, const char* textureName) { return invoke<Texture>(0x33E6BA2D, txdName, textureName); }
	static TextureDict GET_TXD(const char* txdName) { return invoke<TextureDict>(0x968FB1BB, txdName); }
	static TextureDict LOAD_TXD(const char* txdName) { return invoke<TextureDict>(0x53AC9059, txdName); }
}

namespace SCRIPT
{
	static BOOL DOES_SCRIPT_EXIST(const char* name) { return invoke<BOOL>(0xDEAB87AB, name); }
	static void REQUEST_SCRIPT(const char* scriptName) { invoke<Void>(0xE26B2666, scriptName); }
	static BOOL IS_THREAD_ACTIVE(uint32_t threadId) { return invoke<uint32_t>(0x78D7A5A0, threadId); }
	static uint32_t GET_ID_OF_THIS_THREAD() { return invoke<uint32_t>(0xDE524830); }
	static uint32_t GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(const char* scriptName) { return invoke<uint32_t>(0xB5A5F10C, scriptName); }
	static void ALLOCATE_SCRIPT_TO_OBJECT(const char* ScriptName, uint32_t model, int Unk602, float radius, Time UnkTime) { invoke<Void>(0x95A2BC99, ScriptName, model, Unk602, radius, UnkTime); }
	static void ALLOCATE_SCRIPT_TO_RANDOM_PED(const char* ScriptName, uint32_t model, int Unk603, BOOL flag) { invoke<Void>(0x5AEEDF6D, ScriptName, model, Unk603, flag); }
	static void ALLOW_THIS_SCRIPT_TO_BE_PAUSED(BOOL allows) { invoke<Void>(0xE45DD496, allows); }
	//static void DESTROY_THREAD(ScrHandle ScriptHandle) { invoke<Void>(0x484829EA, ScriptHandle); }
	static void GET_SCRIPT_RENDERTARGET_RENDER_ID(uint32_t* pRenderId) { invoke<Void>(0xE7617459, pRenderId); }
	static uint32_t START_NEW_SCRIPT_WITH_ARGS(const char* scriptname, void* params, int paramcount, uint32_t stacksize) { return invoke<uint32_t>(0x4A2100E4, scriptname, params, params, stacksize); }
	static BOOL HAS_SCRIPT_LOADED(const char* scriptName) { return invoke<BOOL>(0x5D67F751, scriptName); }
	static void MARK_SCRIPT_AS_NO_LONGER_NEEDED(const char* scriptName) { invoke<Void>(0x944E9033, scriptName); }
	static uint32_t START_NEW_SCRIPT(const char* scriptName, uint32_t stacksize) { return invoke<uint32_t>(0x3F166D0E, scriptName, stacksize); }
	static void TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(const char* name) { invoke<Void>(0x9F861FD4, name); }
	static void SET_INTERP_FROM_GAME_TO_SCRIPT(BOOL p0, int p1) { invoke<Void>(0x8D5AC711, p0, p1); }
	static void SET_INTERP_FROM_SCRIPT_TO_GAME(BOOL p0, int p1) { invoke<Void>(0x1BE309DD, p0, p1); }
	static void SET_SCRIPT_LIMIT_TO_GANG_SIZE(int size) { invoke<Void>(0x93675A29, size); }
	static void SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(BOOL allow) { invoke<Void>(0xD06F1720, allow); }
	static void TERMINATE_THIS_SCRIPT() { invoke<Void>(0x245B6AB6); }
	static void THIS_SCRIPT_SHOULD_BE_SAVED() { invoke<Void>(0xDB0FC3F1); }
}

namespace UI
{
	static Blip GET_FIRST_BLIP_INFO_ID(uint32_t type) { return invoke<Blip>(0x64C0273D, type); }
	static Blip GET_NEXT_BLIP_INFO_ID(uint32_t type) { return invoke<Blip>(0x9356E92F, type); }
	static BOOL DOES_BLIP_EXIST(Blip blip) { return invoke<BOOL>(0xAE92DD96, blip); }
	static BOOL DOES_TEXT_LABEL_EXIST(const char* gxtentry) { return invoke<BOOL>(0x6ECAE560, gxtentry); }
	static BOOL HAS_ADDITIONAL_TEXT_LOADED(uint32_t textIndex) { return invoke<BOOL>(0xB0E56045, textIndex); }
	static BOOL IS_BLIP_SHORT_RANGE(Blip blip) { return invoke<BOOL>(0x1226765A, blip); }
	static BOOL IS_STRING_NULL(char* str) { return invoke<BOOL>(0x8E71E00F, str); }
	static BOOL IS_THIS_HELP_MESSAGE_BEING_DISPLAYED(const char* gxtentry) { return invoke<BOOL>(0x792ECC8C, gxtentry); }
	static BOOL IS_THIS_HELP_MESSAGE_WITH_NUMBER_BEING_DISPLAYED(const char* gxtentry, int number) { return invoke<BOOL>(0x7303D366, gxtentry, number); }
	static BOOL IS_THIS_HELP_MESSAGE_WITH_STRING_BEING_DISPLAYED(const char* gxtentry, const char* str) { return invoke<BOOL>(0x8FDB39D4, gxtentry, str); }
	static const char* GET_STRING_FROM_STRING(const char* str, int startsymb, int endsymb) { return invoke<const char*>(0x0A2FEC42, str, startsymb, endsymb); }
	static const char* GET_STRING_FROM_TEXT_FILE(const char* gxtentry) { return invoke<const char*>(0x8D4AD2BD, gxtentry); }
	static const char* GET_BLIP_NAME(Blip blip) { return invoke<const char*>(0x401505B7, blip); }
	static const char* GET_FIRST_N_CHARACTERS_OF_LITERAL_STRING(const char* literalString, uint32_t chars) { return invoke<const char*>(0x0DFEF066, literalString, chars); }
	static const char* GET_FIRST_N_CHARACTERS_OF_STRING(const char* gxtName, uint32_t chars) { return invoke<const char*>(0xB07A2148, gxtName, chars); }
	static const char* GET_NTH_INTEGER_IN_STRING(const char* gxtName, uint32_t index) { return invoke<const char*>(0xC4EB06A4, gxtName, index); }
	static const char* GET_STRING_FROM_HASH_KEY(uint32_t hash) { return invoke<const char*>(0xAA1BC0DD, hash); }
	static float GET_STRING_WIDTH_WITH_STRING(const char* gxtName, const char* literalString)  { return invoke<float>(0x048A2E6C, gxtName, literalString); }
	static int GET_BLIP_INFO_ID_ROTATION() { return invoke<int>(0x02C9542C); }
	static int GET_LENGTH_OF_STRING_WITH_THIS_HASH_KEY(uint32_t gxtkey) { return invoke<int>(0x9DF4FD21, gxtkey); }
	static int GET_LENGTH_OF_STRING_WITH_THIS_TEXT_LABEL_INS_NUM(Any p0, Any p1, Any p2) { return invoke<int>(0x1888AA8C, p0, p1, p2); }
	static int GET_SIMPLE_BLIP_ID() { return invoke<int>(0xD57804B4); }
	static int GET_STRING_WIDTH(const char* gxtName) { return invoke<int>(0xBABDF3D6, gxtName); }
	static int GET_STRING_WIDTH_WITH_NUMBER(const char* gxtName, int number) { return invoke<int>(0xEAEB477D, gxtName, number); }
	static int GET_STRING_WIDTH_WITH_TEXT_AND_INT(const char* gxtname, const char* gxtnamenext, int val) { return invoke<int>(0x31F5D8FC, gxtname, gxtnamenext, val); }
	static int GET_WIDTH_OF_LITERAL_STRING(const char* str) { return invoke<int>(0xA4CAD139, str); }
	static int GET_WIDTH_OF_SUBSTRING_GIVEN_TEXT_LABEL(const char* gxtname, BOOL p1, Any p2, Any p3, Any p4) { return invoke<int>(0x22D0DDFB, gxtname, p1, p2, p3, p4); }
	static Object GET_BLIP_INFO_ID_OBJECT_INDEX(Blip blip) { return invoke<Object>(0x27AB7110, blip); }
	static Ped GET_BLIP_INFO_ID_PED_INDEX(Blip blip) { return invoke<Ped>(0x0DD57007, blip); }
	static Pickup GET_BLIP_INFO_ID_PICKUP_INDEX(Blip blip) { return invoke<Pickup>(0x86913D37, blip); }
	static Any IS_THIS_PRINT_BEING_DISPLAYED(const char* gxtentry, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10) { return invoke<Any>(0xED8E2421, gxtentry, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }
	static uint32_t GET_BLIP_INFO_ID_DISPLAY(Blip blip) { return invoke<uint32_t>(0xD0FC19F4, blip); }
	static uint32_t GET_BLIP_INFO_ID_TYPE(Blip blip) { return invoke<uint32_t>(0x501D7B4E, blip); }
	static uint32_t GET_BLIP_SPRITE(Blip blip) { return invoke<uint32_t>(0x72FF2E73, blip); }
	static uint32_t GET_LENGTH_OF_LITERAL_STRING(const char* literalString) { return invoke<uint32_t>(0x99379D55, literalString); }
	static uint32_t GET_LENGTH_OF_STRING_WITH_THIS_TEXT_LABEL(const char* gxtName) { return invoke<uint32_t>(0xA4CA7BE5, gxtName); }
	static Vehicle GET_BLIP_INFO_ID_CAR_INDEX(Blip blip) { return invoke<Vehicle>(0x635D6806, blip); }
	static void ACTIVATE_FRONTEND() { invoke<Void>(0x2CF69916); }
	static void ACTIVATE_REPLAY_MENU() { invoke<Void>(0x30E32F9C); }
	static void ACTIVATE_SAVE_MENU() { invoke<Void>(0x0C0B7BC8); }
	static void ADD_BLIP_FOR_CAR(Vehicle vehicle, Blip* pBlip) { invoke<Void>(0xF929BAD5, vehicle, pBlip); }
	static void ADD_BLIP_FOR_CHAR(Ped ped, Blip* pBlip) { invoke<Void>(0x1E203D63, ped, pBlip); }
	static void ADD_BLIP_FOR_CONTACT(float x, float y, float z, Blip* pBlip) { invoke<Void>(0x6295B365, x, y, z, pBlip); }
	static void ADD_BLIP_FOR_COORD(float x, float y, float z, Blip* pBlip) { invoke<Void>(0xC6F43D0E, x, y, z, pBlip); }
	static void ADD_BLIP_FOR_GANG_TERRITORY(float x0, float y0, float x1, float y1, int colour, int* blip) { invoke<Void>(0x63EBC4FA, x0, y0, x1, y1, colour, blip); }
	static void ADD_BLIP_FOR_OBJECT(Object obj, Blip* pBlip) { invoke<Void>(0x0E5372EC, obj, pBlip); }
	static void ADD_BLIP_FOR_PICKUP(Pickup pickup, Blip* pBlip) { invoke<Void>(0x16693C3A, pickup, pBlip); }
	static void ADD_BLIP_FOR_RADIUS(float x, float y, float z, int type, Blip* pBlip) { invoke<Void>(0x4626756C, x, y, z, type, pBlip); }
	static void ADD_BLIP_FOR_WEAPON(float x, float y, float z, Blip* pBlip) { invoke<Void>(0xC5803316, x, y, z, pBlip); }
	static void ADD_FIRST_N_CHARACTERS_OF_STRING_TO_HTML_SCRIPT_OBJECT(int htmlobj, const char* str, int n) { invoke<Void>(0xFA537BB7, htmlobj, str, n); }
	static void ADD_NEXT_MESSAGE_TO_PREVIOUS_BRIEFS(BOOL add) { invoke<Void>(0xB58B25BD, add); }
	static void ADD_SIMPLE_BLIP_FOR_PICKUP(Pickup pickup) { invoke<Void>(0x2AAD35A0, pickup); }
	static void ADD_STRING_TO_HTML_SCRIPT_OBJECT(int htmlobj, const char* str) { invoke<Void>(0x3734F820, htmlobj, str); }
	static void ADD_STRING_TO_NEWS_SCROLLBAR(const char* str) { invoke<Void>(0x00DDFD22, str); }
	static void ADD_STRING_WITH_THIS_TEXT_LABEL_TO_PREVIOUS_BRIEF(const char* gxtname) { invoke<Void>(0xCEE52CA5, gxtname); }
	static void ADD_TICKER_TO_PREVIOUS_BRIEF_WITH_UNDERSCORE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)//used for japanese text correcting
	{
		invoke<Void>(0x0012A4CF, p0, p1, p2, p3, p4, p5, p6);
	}
	static void ADD_TO_PREVIOUS_BRIEF(const char* gxtentry) { invoke<Void>(0xFE33CF4A, gxtentry); }
	static void ADD_TO_PREVIOUS_BRIEF_WITH_UNDERSCORE(const char* gxtentry) { invoke<Void>(0xB12B4573, gxtentry); }
	static void CHANGE_BLIP_ALPHA(Blip blip, int alpha) { invoke<Void>(0xEF9C691E, blip, alpha); }
	static void CHANGE_BLIP_COLOUR(Blip blip, ColourIndex colour) { invoke<Void>(0x3AAE0512, blip, colour); }
	static void CHANGE_BLIP_DISPLAY(Blip blip, uint32_t display) { invoke<Void>(0xB555EA97, blip, display); }
	static void CHANGE_BLIP_NAME_FROM_ASCII(Blip blip, const char* blipName) { invoke<Void>(0xD30EBD66, blip, blipName); }
	static void CHANGE_BLIP_NAME_FROM_TEXT_FILE(Blip blip, const char* gxtName) { invoke<Void>(0x95823232, blip, gxtName); }
	static void CHANGE_BLIP_NAME_TO_PLAYER_NAME(int blip, int playerid) { invoke<Void>(0xE179712B, blip, playerid); }
	static void CHANGE_BLIP_PRIORITY(Blip blip, uint32_t priority) { invoke<Void>(0xA37193AB, blip, priority); }
	static void CHANGE_BLIP_ROTATION(int blip, int rotation) { invoke<Void>(0x0C563F7B, blip, rotation); }
	static void CHANGE_BLIP_SCALE(Blip blip, float scale) { invoke<Void>(0xDC8C2E35, blip, scale); }
	static void CHANGE_BLIP_SPRITE(Blip blip, uint32_t sprite) { invoke<Void>(0xEDE22A59, blip, sprite); }
	static void CHANGE_BLIP_TEAM_RELEVANCE(int blip, int relevance) { invoke<Void>(0x79100C76, blip, relevance); }
	static void CHANGE_PICKUP_BLIP_COLOUR(Colour colour) { invoke<Void>(0x571B40A4, colour); }
	static void CHANGE_PICKUP_BLIP_DISPLAY(int display) { invoke<Void>(0xBCC2D90F, display); }
	static void CHANGE_PICKUP_BLIP_PRIORITY(int priority) { invoke<Void>(0xB756912A, priority); }
	static void CHANGE_PICKUP_BLIP_SCALE(float scale) { invoke<Void>(0x366C5AA5, scale); }
	static void CHANGE_PICKUP_BLIP_SPRITE(int sprite) { invoke<Void>(0x0EADB4AE, sprite); }
	static void CHANGE_TERRITORY_BLIP_SCALE(int blip, float p1, float p2) { invoke<Void>(0x00BA6723, blip, p1, p2); }
	static void CLEAR_ADDITIONAL_TEXT(int textid, BOOL p1) { invoke<Void>(0x518141E0, textid, p1); }
	static void CLEAR_BRIEF() { invoke<Void>(0x9F75A929); }
	static void CLEAR_HELP() { invoke<Void>(0xE6D85741); }
	static void CLEAR_NEWS_SCROLLBAR() { invoke<Void>(0xD70532E8); }
	static void CLEAR_ONSCREEN_COUNTER(int counterid) { invoke<Void>(0xFF50E239, counterid); }
	static void CLEAR_ONSCREEN_TIMER(int timerid) { invoke<Void>(0xF72ED471, timerid); }
	static void CLEAR_PRINTS() { invoke<Void>(0x216CB1C5); }
	static void CLEAR_SMALL_PRINTS() { invoke<Void>(0xA869A238); }
	static void CLEAR_TEXT_LABEL(const char* label) { invoke<Void>(0xA66AAE8F, label); }
	static void CLEAR_THIS_BIG_PRINT(const char* gxtentry) { invoke<Void>(0xEFC037F4, gxtentry); }
	static void CLEAR_THIS_PRINT(const char* gxtentry) { invoke<Void>(0x06878327, gxtentry); }
	static void CLEAR_THIS_PRINT_BIG_NOW(BOOL p0) { invoke<Void>(0xE9BFBF43, p0); }
	static void HIDE_HUD_AND_RADAR_THIS_FRAME() { invoke<Void>(0xB75D4AD2); }
	static void CONVERT_THEN_ADD_STRING_TO_HTML_SCRIPT_OBJECT(int htmlobj, const char* strgxtkey) { invoke<Void>(0x1B9CF010, htmlobj, strgxtkey); }
	static void CREATE_TEMPORARY_RADAR_BLIPS_FOR_PICKUPS_IN_AREA(float x, float y, float z, float radius, int bliptype)
	{
		invoke<Void>(0x470F20A8, x, y, z, radius, bliptype);
	}
	static void DEACTIVATE_FRONTEND() { invoke<Void>(0x6590DD9A); }
	static void DIM_BLIP(Blip blip, BOOL unknownTrue) { invoke<Void>(0x5D367A1B, blip, unknownTrue); }
	static void DISPLAY_ALTIMETER_THIS_FRAME() { invoke<Void>(0x3C970832); }
	static void DISPLAY_AMMO(BOOL display) { invoke<Void>(0x92A4C55C, display); }
	static void DISPLAY_AREA_NAME(BOOL display) { invoke<Void>(0x489FDD41, display); }
	static void HIDE_HELP_TEXT_THIS_FRAME() { invoke<Void>(0xF3807BED); }

	static void DISPLAY_TEXT_WITH_LITERAL_STRING(float x, float y, const char* gxtName, const char* literalStr) { invoke<Void>(0x247F4D85, x, y, gxtName, literalStr); }
	static void SET_TEXT_FONT(uint32_t font) { invoke<Void>(0x80BC530D, font); }
	static void SET_TEXT_INPUT_ACTIVE(BOOL set) { invoke<Void>(0xE5C046AA, set); }
	static void SET_TEXT_JUSTIFY(BOOL value) { invoke<Void>(0xBC971139, value); }
	static void SET_TEXT_LINE_DISPLAY(uint32_t p0, uint32_t p1) { invoke<Void>(0x5AE8AF79, p0, p1); }
	static void SET_TEXT_LINE_HEIGHT_MULT(float lineHeight) { invoke<Void>(0x2F947549, lineHeight); }
	static void SET_TEXT_PROPORTIONAL(BOOL value) { invoke<Void>(0xF49D8A08, value); }
	static void SET_TEXT_RENDER_ID(uint32_t renderId) { invoke<Void>(0xC5C3B7F3, renderId); }
	static void SET_TEXT_RIGHT_JUSTIFY(BOOL value) { invoke<Void>(0x45B60520, value); }
	static void SET_TEXT_SCALE(float w, float h) { invoke<Void>(0xB6E15B23, w, h); }
	static void SET_TEXT_TO_USE_TEXT_FILE_COLOURS(BOOL value) { invoke<Void>(0xB95E39DE, value); }
	static void SET_TEXT_USE_UNDERSCORE(BOOL value) { invoke<Void>(0x95CD1881, value); }
	static void SET_TEXT_VIEWPORT_ID(int id) { invoke<Void>(0xBE9E0A9B, id); }
	static void SET_TEXT_WRAP(float p0, float p1) { invoke<Void>(0x6F60AB54, p0, p1); }
	static void SET_RADAR_AS_INTERIOR_THIS_FRAME() { invoke<Void>(0x6F2626E1); }
	static void SET_RADAR_SCALE(float scale) { invoke<Void>(0x5E4BFB05, scale); }
	static void SET_RADAR_ZOOM(int zoom) { invoke<Void>(0x2A50D1A6, zoom); }
	static void SET_ROUTE(Blip blip, BOOL value) { invoke<Void>(0xD3D8C987, blip, value); }
	static void SET_TEXT_BACKGROUND(BOOL value) { invoke<Void>(0x14ADAD25, value); }
	static void SET_TEXT_CENTRE(BOOL value) { invoke<Void>(0xE26D39A1, value); }
	static void SET_TEXT_CENTRE_WRAPX(float wrapx) { invoke<Void>(0x6035C07C, wrapx); }
	static void SET_TEXT_COLOUR(uint32_t r, uint32_t g, uint32_t b, uint32_t a) { invoke<Void>(0xE54DD2C8, r, g, b, a); }
	static void SET_TEXT_DRAW_BEFORE_FADE(BOOL value) { invoke<Void>(0x1B2BA35E, value); }
	static void SET_TEXT_DROPSHADOW(BOOL displayShadow, uint32_t r, uint32_t g, uint32_t b, uint32_t a) { invoke<Void>(0xE6587517, displayShadow, r, g, b, a); }
	static void SET_TEXT_EDGE(BOOL displayEdge, uint32_t r, uint32_t g, uint32_t b, uint32_t a) { invoke<Void>(0x3F1A5DAB, displayEdge, r, g, b, a); }
	static void SHOW_BLIP_ON_ALTIMETER(Blip blip, BOOL show) { invoke<Void>(0x2590EB2F, blip, show); }
	static void SHOW_SIGNIN_UI() { invoke<Void>(0xBD7C5EE4); }
	static void SHOW_UPDATE_STATS(BOOL show) { invoke<Void>(0x663C3B15, show);  }
	static void UNLOAD_TEXT_FONT() { invoke<Void>(0x469A98C9); }
	static void UNPAUSE_GAME() { invoke<Void>(0x0BF2CD82); }
	static void USE_PREVIOUS_FONT_SETTINGS() { invoke<Void>(0x8056F873); }


	static void PRINT_STRING_WITH_LITERAL_STRING_NOW(const char* gxtName, const char* text, uint32_t timeMS, BOOL enable) { invoke<Void>(0x40D7612D, gxtName, text, timeMS, enable); }
}

namespace GAMEPLAY
{
	static uint32_t GET_CURRENT_EPISODE() { return invoke<uint32_t>(0x0ECE0B08); }
	static int GET_GAME_TIMER() { return invoke<int>(0xA4EA0691); }
	static BOOL STRING_TO_INT(char* string, int* outInteger) { return invoke<BOOL>(0x590A8160, string, outInteger); }
	static int GET_HASH_KEY(const char* p0) { return invoke<int>(0x98EFF6F1, p0); }
}


namespace AUDIO
{
	static void PLAY_SOUND_FRONTEND(uint32_t sound, const char* soundName) { invoke<Void>(0x2E458F74, sound, soundName); }
	static void PLAY_AUDIO_EVENT(const char* name) { invoke<Void>(0x4B31CE89, name); }
}

namespace CUTSCENE
{
	static BOOL HAS_CUTSCENE_FINISHED() { return invoke<BOOL>(0x5DED14B4); }
	static BOOL HAS_CUTSCENE_LOADED() { return invoke<BOOL>(0xF9998582); }
	static BOOL WAS_CUTSCENE_SKIPPED() { return invoke<BOOL>(0xC9B6949D); }
	static int GET_CUTSCENE_AUDIO_TIME_MS() { return invoke<int>(0xCA56C61D); }
	static int GET_CUTSCENE_SECTION_PLAYING() { return invoke<int>(0x1026F0D6); }
	static int GET_CUTSCENE_TIME() { return invoke<int>(0x53F5B5AB); }
	static void CLEAR_CUTSCENE() { invoke<Void>(0x562655BF); }
	static void CLEAR_NAMED_CUTSCENE(const char* name) { invoke<Void>(0x268CC696, name); }
	static void INIT_CUTSCENE(const char* name) { invoke<Void>(0x6D91E94A, name); }
	static void SET_CUTSCENE_EXTRA_ROOM_POS(float x, float y, float z) { invoke<Void>(0x06EB9A03, x, y, z); }
	static void START_CUTSCENE() { invoke<Void>(0x210106F6); }
	static void START_CUTSCENE_NOW(const char* name) { invoke<Void>(0xCDC89731, name); }
	static void STOP_CUTSCENE() { invoke<Void>(0x5EE84DC7); }
	static void STREAM_CUTSCENE() { invoke<Void>(0x39D7BC0C); }
}

namespace BRAIN
{
	static BOOL IS_WORLD_POINT_WITHIN_BRAIN_ACTIVATION_RANGE() { return invoke<BOOL>(0x2CF305A0); }
	static void REGISTER_WORLD_POINT_SCRIPT_BRAIN(const char* ScriptName, float radius) { invoke<Void>(0x725D91F7, ScriptName, radius); }
	static void SWITCH_OBJECT_BRAINS(int brain, BOOL switchstate) { invoke<Void>(0x3224777E, brain, switchstate); }
}

namespace MOBILE
{
	static BOOL CAN_PHONE_BE_SEEN_ON_SCREEN() { return invoke<BOOL>(0x5F978584); }
	static BOOL CODE_WANTS_MOBILE_PHONE_REMOVED() { return invoke<BOOL>(0x4EEA45EA); }
	static BOOL CODE_WANTS_MOBILE_PHONE_REMOVED_FOR_WEAPON_SWITCHING() { return invoke<BOOL>(0x99DFCFB3); }
	static BOOL GET_MOBILE_PHONE_TASK_SUB_TASK(Ped ped, int* p1) { return invoke<BOOL>(0xB47C4CF0, ped, p1); }
	static BOOL IS_MOBILE_PHONE_CALL_ONGOING() { return invoke<BOOL>(0x4ED1400A); }
	static BOOL IS_MOBILE_PHONE_RADIO_ACTIVE() { return invoke<BOOL>(0x6E502A5B); }
	static float GET_MOBILE_PHONE_SCALE() { return invoke<float>(0x905E4B9C); }
	static int GET_NUMBER_OF_WEB_PAGE_LINKS(int htmlviewport) { return invoke<int>(0x8721C767, htmlviewport); }
	static void ADD_LINE_TO_MOBILE_PHONE_CALL(int id, const char* name, const char* text) { invoke<Void>(0x7F8C2272, id, name, text); }
	static void CREATE_MOBILE_PHONE(int p0) { invoke<Void>(0x5BBC5E23, p0); }
	static void DESTROY_MOBILE_PHONE() { invoke<Void>(0x1A65037B); }
	static void GET_MOBILE_PHONE_RENDER_ID(uint32_t* pRenderId) { invoke<Void>(0x88E4FECE, pRenderId); }
	static void NEW_MOBILE_PHONE_CALL() { invoke<Void>(0xF2FF08C5); }
	static void PREVIEW_RINGTONE(int RingtoneId) { invoke<Void>(0x37A8383F, RingtoneId); }
	static void SCRIPT_IS_MOVING_MOBILE_PHONE_OFFSCREEN(BOOL set) { invoke<Void>(0x29828690, set); }
	static void SCRIPT_IS_USING_MOBILE_PHONE(BOOL set) { invoke<Void>(0xC87FB3BC, set); }
	static void SET_MOBILE_PHONE_POSITION(float x, float y, float z) { invoke<Void>(0x841800B3, x, y, z); }
	static void SET_MOBILE_PHONE_RADIO_STATE(BOOL state) { invoke<Void>(0xE1E0ED34, state); }
	static void SET_MOBILE_PHONE_ROTATION(float x, float y, float z) { invoke<Void>(0x209C28CF, x, y, z); }
	static void SET_MOBILE_PHONE_SCALE(float scale) { invoke<Void>(0x09BCF1BE, scale); }
	static void SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(BOOL set) { invoke<Void>(0x990085F0, set); }
	static void SET_MOBILE_RING_TYPE(int type) { invoke<Void>(0x02C4E1D2, type); }
	static void SET_PHONE_HUD_ITEM(int id, const char* gxttext, int p2) { invoke<Void>(0x7FD60931, id, gxttext, p2); }
	static void START_CUSTOM_MOBILE_PHONE_RINGING(int RingtoneId) { invoke<Void>(0x52921CED, RingtoneId); }
	static void START_MOBILE_PHONE_CALL(Ped callfrom, const char* callfromvoice, Ped callto, const char* calltovoice, BOOL flag0, BOOL flag1) { invoke<Void>(0x5B7106AF, callfrom, callfromvoice, callto, calltovoice, flag0, flag1); }
	static void START_MOBILE_PHONE_CALLING() { invoke<Void>(0x058921A9); }
	static void START_MOBILE_PHONE_RINGING() { invoke<Void>(0x67B39C65); }
	static void START_PED_MOBILE_RINGING(Ped ped, int p1) { invoke<Void>(0x354520B6, ped, p1); }
	static void STOP_MOBILE_PHONE_RINGING() { invoke<Void>(0x5A6B9A9D); }
	static void STOP_PREVIEW_RINGTONE() { invoke<Void>(0xB9659902); }
}

namespace INTERNET
{
	static BOOL DOES_WEB_PAGE_EXIST(const char* webaddress) { return invoke<BOOL>(0x0F52FD85, webaddress); }
	static const char* GET_WEB_PAGE_LINK_HREF(int htmlviewport, int linkid) { return invoke<const char*>(0x0AB4E18F, htmlviewport, linkid); }
	static float GET_WEB_PAGE_HEIGHT(int htmlviewport) { return invoke<float>(0xAFDCC2FF, htmlviewport); }
	static int CREATE_HTML_SCRIPT_OBJECT(const char* objname) { return invoke<int>(0xBB9DD763, objname); }
	static int GET_WEB_PAGE_LINK_AT_POSN(int htmlviewport, float x, float y) { return invoke<int>(0x33EB42D0, htmlviewport, x, y); }
	static void ADD_TO_HTML_SCRIPT_OBJECT(int htmlobj, const char* htmlcode) { invoke<Void>(0x01015507, htmlobj, htmlcode); }
	static void DELETE_ALL_HTML_SCRIPT_OBJECTS() { invoke<Void>(0xF54B51A1); }
	static void DELETE_HTML_SCRIPT_OBJECT(int htmlobj) { invoke<Void>(0x6113254C, htmlobj); }
	static void GET_WEB_PAGE_LINK_POSN(int htmlviewport, int linkid, float* x, float* y) { invoke<Void>(0x75596EA5, htmlviewport, linkid, x, y); }
	static void LOAD_WEB_PAGE(int htmlviewport, const char* webaddress) { invoke<Void>(0x0C1058C6, htmlviewport, webaddress); }
	static void RELOAD_WEB_PAGE(int htmlviewport) { invoke<Void>(0xE9B1B93B, htmlviewport); }
	static void SET_WEB_PAGE_LINK_ACTIVE(int htmlviewport, int linkid, BOOL active) { invoke<Void>(0xBE670DC0, htmlviewport, linkid, active); }
	static void SET_WEB_PAGE_SCROLL(int htmlviewport, float scroll) { invoke<Void>(0x52549D0B, htmlviewport, scroll); }
}

namespace TIME
{
	static void CLEAR_TIMECYCLE_MODIFIER() { invoke<Void>(0x8D8DF8EE); }
	static void FORCE_TIME_OF_DAY(uint32_t hour, uint32_t minute) { invoke<Void>(0x49B6ED13, hour, minute); }
	static void FORWARD_TO_TIME_OF_DAY(uint32_t hour, uint32_t minute) { invoke<Void>(0x9A15DFA4, hour, minute); }
	static void FREEZE_ONSCREEN_TIMER(BOOL freeze) { invoke<Void>(0x67B636C6, freeze); }
	static int GET_GAME_TIMER() { return invoke<int>(0xA4EA0691); }
	static void GET_TIME_OF_DAY(uint32_t* hour, uint32_t* minute) { invoke<Void>(0x4E1DE7A5, hour, minute); }
	static void SET_MOVIE_TIME(float time) { invoke<Void>(0xA1930880, time); }
	static void SET_TIMECYCLE_MODIFIER(const char* name) { invoke<Void>(0xA81F3638, name); }
	static void SET_TIMER_BEEP_COUNTDOWN_TIME(int timerid, int beeptime) { invoke<Void>(0xD51E2A5F, timerid, beeptime); }
	static void SET_TIME_CYCLE_FAR_CLIP_DISABLED(BOOL set) { invoke<Void>(0xE9909560, set); }
	static void SET_TIME_OF_DAY(uint32_t hour, uint32_t minute) { invoke<Void>(0xAD03186C, hour, minute); }
	static void SET_TIME_OF_NEXT_APPOINTMENT(int time) { invoke<Void>(0x834D6ED2, time); }
	static void SET_TIME_ONE_DAY_BACK() { invoke<Void>(0x0DB2A037); }
	static void SET_TIME_ONE_DAY_FORWARD() { invoke<Void>(0xBB56C2E5); }
	static void SET_TIME_SCALE(float scale) { invoke<Void>(0xA7F84694, scale); }
}

namespace PATHFIND
{
	static BOOL GET_CLOSEST_CAR_NODE(float x, float y, float z, float* pResX, float* pResY, float* pResZ) { return invoke<BOOL>(0x7DD4CE01, x, y, z, pResX, pResY, pResZ); }
	static BOOL GET_CLOSEST_CAR_NODE_FAVOUR_DIRECTION(int p0, float x, float y, float z, float* pX, float* pY, float* pZ, float* heading) { return invoke<BOOL>(0x1949A4BA, p0, x, y, z, pX, pY, pZ, heading); }
}


namespace INTERIOR
{
	static void ACTIVATE_INTERIOR(Interior interior, BOOL unknownTrue) { invoke<Void>(0x6B09B780, interior, unknownTrue); }
	static void GET_INTERIOR_AT_COORDS(float x, float y, float z, Interior* pInterior) { invoke<Void>(0xA17FBF37, x, y, z, pInterior); }
	static void GET_INTERIOR_FROM_CAR(Vehicle vehicle, Interior* pInterior) { invoke<Void>(0xDD834626, vehicle, pInterior); }
	static void GET_INTERIOR_FROM_CHAR(Ped ped, Interior* pInterior) { invoke<Void>(0x93EC6CF9, ped, pInterior); }
	static void GET_INTERIOR_HEADING(Interior interior, float* pHeading) { invoke<Void>(0xFB56D1AC, interior, pHeading); }
	static void GET_OFFSET_FROM_INTERIOR_IN_WORLD_COORDS(Interior interior, float x, float y, float z, float* pOffset) { invoke<Void>(0x7D8F26A1, interior, x, y, z, pOffset); }
}

namespace CAM
{
	static void SET_CINEMATIC_BUTTON_ENABLED(BOOL set) { invoke<Void>(0x063C4508, set); }
	static BOOL CAM_IS_SPHERE_VISIBLE(Camera camera, float pX, float pY, float pZ, float radius) { return invoke<BOOL>(0xD047DD84, camera, pX, pY, pZ, radius); }
	static BOOL DOES_CAM_EXIST(Camera camera) { return invoke<BOOL>(0x1EF89DC0, camera); }
	static BOOL DOES_VIEWPORT_EXIST(int viewportid) { return invoke<BOOL>(0xCA9DD46F, viewportid); }
	static BOOL GET_VIEWPORT_POSITION_OF_COORD(float x, float y, float z, float* vx, float* vy, float* vz)
	{
		return invoke<BOOL>(0x4BF2A1D7, x, y, z, vx, vy, vz);
	}
	static BOOL IS_CAM_ACTIVE(Camera camera) { return invoke<BOOL>(0x4B58F177, camera); }
	static BOOL IS_CAM_HAPPY(Cam cam) { return invoke<BOOL>(0xF2432971, cam); }
	static BOOL IS_CAM_INTERPOLATING() { return invoke<BOOL>(0x7159CB5D); }
	static BOOL IS_CAM_PROPAGATING(Camera camera) { return invoke<BOOL>(0x188C0D16, camera); }
	static BOOL IS_CAM_SEQUENCE_COMPLETE(int p0) { return invoke<BOOL>(0x14609619, p0); }
	static BOOL IS_CAM_SHAKING() { return invoke<BOOL>(0x0961FD9B); }
	static BOOL IS_FOLLOW_VEHICLE_CAM_OFFSET_ACTIVE() { return invoke<BOOL>(0xEF102F32); }
	static BOOL IS_SPECIFIC_CAM_INTERPOLATING(Cam cam) { return invoke<BOOL>(0x2E9C3C82, cam); }
	static BOOL IS_VIEWPORT_ACTIVE(int viewportid) { return invoke<BOOL>(0x6D40B30C, viewportid); }
	static int COUNT_SCRIPT_CAMS() { return invoke<int>(0x2F3D792B); }
	static int COUNT_SCRIPT_CAMS_BY_TYPE_AND_OR_STATE(int type, int p1, int p2) { return invoke<int>(0x97F869B7, type, p1, p2); }
	static int GET_CAM_STATE(Camera cam) { return invoke<int>(0x3A6B3754, cam); }
	static void ACTIVATE_SCRIPTED_CAMS(BOOL p0, BOOL p1) { invoke<Void>(0xB5539CE8, p0, p1); }
	static void ACTIVATE_VIEWPORT(int viewportid, BOOL activate) { invoke<Void>(0x72175DA6, viewportid, activate); }
	static void ADD_CAM_SPLINE_NODE(int cam, int camnode) { invoke<Void>(0xAD3C7EAA, cam, camnode); }

}

namespace WEAPON
{
	static BOOL GET_AMMO_IN_CLIP(Ped ped, uint32_t weapon, uint32_t* pAmmo) { return invoke<BOOL>(0x73C100C3, ped, weapon, pAmmo); }
	static BOOL GET_CURRENT_CHAR_WEAPON(Ped ped, uint32_t* pWeapon) { return invoke<BOOL>(0x0C058FF9, ped, pWeapon); }
	static BOOL GET_MAX_AMMO(Ped ped, uint32_t weapon, uint32_t* pMaxAmmo) { return invoke<BOOL>(0x0B294796, ped, weapon, pMaxAmmo); }
	static BOOL HAS_CHAR_BEEN_DAMAGED_BY_WEAPON(Ped ped, uint32_t weapon) { return invoke<BOOL>(0x85D3CC9F, ped, weapon); }
	static BOOL HAS_CHAR_GOT_WEAPON(Ped ped, uint32_t weapon) { return invoke<BOOL>(0x6852825A, ped, weapon); }
	static float GET_LOCAL_PLAYER_WEAPON_STAT(int wtype, int wid) { return invoke<float>(0x09DA00D5, wtype, wid); }
	static Any SET_AMMO_IN_CLIP(Ped ped, uint32_t weapon, uint32_t ammo) { return invoke<Any>(0xA54B0B10, ped, weapon, ammo); }
	static void ADD_AMMO_TO_CHAR(Ped ped, uint32_t weapon, uint32_t amount) { invoke<Void>(0x86E05B02, ped, weapon, amount); }
	static void BLOCK_PED_WEAPON_SWITCHING(Ped ped, BOOL value) { invoke<Void>(0xE6DF7715, ped, value); }
	static void ENABLE_MAX_AMMO_CAP(BOOL enable) { invoke<Void>(0xBA9CC5C1, enable); }
	static void FIRE_SINGLE_BULLET(float x, float y, float z, float targetX, float targetY, float targetZ, uint32_t unknown) { invoke<Void>(0xC0BD06E2, x, y, z, targetX, targetY, targetZ, unknown); }
	static void FORCE_CHAR_TO_DROP_WEAPON(Ped ped) { invoke<Void>(0x0AA791B3, ped); }
	static void GET_AMMO_IN_CHAR_WEAPON(Ped ped, uint32_t weapon, uint32_t* pAmmo) { invoke<Void>(0x5A31E7D8, ped, weapon, pAmmo); }
	static void GET_CHAR_WEAPON_IN_SLOT(Ped ped, uint32_t slot, uint32_t* pWeapon, uint32_t* pAmmo0, uint32_t* pAmmo1) { invoke<Void>(0x82ABAA80, ped, slot, pWeapon, pAmmo0, pAmmo1); }
	static void GET_MAX_AMMO_IN_CLIP(Ped ped, uint32_t weapon, uint32_t* pMaxAmmo) { invoke<Void>(0x6961E2A4, ped, weapon, pMaxAmmo); }
	static void GET_WEAPONTYPE_MODEL(int weapontype, uint32_t* model) { invoke<Void>(0x44E1C269, weapontype, model); }
	static void GET_WEAPONTYPE_SLOT(int weapon, int* slot) { invoke<Void>(0x2E3759AF, weapon, slot); }
	static void GIVE_DELAYED_WEAPON_TO_CHAR(Ped ped, int weapon, int delaytime, BOOL flag) { invoke<Void>(0xEEF7F721, ped, weapon, delaytime, flag); }
	static void GIVE_WEAPON_TO_CHAR(Ped ped, uint32_t weapon, uint32_t ammo, BOOL unknown0) { invoke<Void>(0x5302DBC4, ped, weapon, ammo, unknown0); }
	static void HIDE_CHAR_WEAPON_FOR_SCRIPTED_CUTSCENE(Ped ped, BOOL hide) { invoke<Void>(0xA691D377, ped, hide); }
	static void REMOVE_ALL_CHAR_WEAPONS(Ped ped) { invoke<Void>(0x7569CAAE, ped); }
	static void REMOVE_WEAPON_FROM_CHAR(Ped ped, uint32_t weapon) { invoke<Void>(0xAFA3B71D, ped, weapon); }
	static void RESET_LOCAL_PLAYER_WEAPON_STAT(int wtype, int wid) { invoke<Void>(0x7D719B1E, wtype, wid); }
	static void SET_CAN_TARGET_CHAR_WITHOUT_LOS(Ped ped, BOOL set) { invoke<Void>(0xBBAA3DAE, ped, set); }
	static void SET_CHAR_AMMO(Ped ped, uint32_t weapon, uint32_t ammo) { invoke<Void>(0x370E18D4, ped, weapon, ammo); }
	static void SET_CHAR_CURRENT_WEAPON_VISIBLE(Ped ped, BOOL visble) { invoke<Void>(0x2794E7DD, ped, visble); }
	static void SET_CHAR_WEAPON_SKILL(Ped ped, int skill) { invoke<Void>(0x21AD7E36, ped, skill); }
	static void SET_CURRENT_CHAR_WEAPON(Ped ped, uint32_t w, BOOL unknownTrue) { invoke<Void>(0xBB1A1C18, ped, w, unknownTrue); }
	static void SET_ENABLE_NEAR_CLIP_SCAN(BOOL set) { invoke<Void>(0x805814E3, set); }
	static void SET_ENABLE_RC_DETONATE(BOOL set) { invoke<Void>(0x726CDF5A, set); }
	static void SET_ENABLE_RC_DETONATE_ON_CONTACT(BOOL set) { invoke<Void>(0xA1E4BA3C, set); }
	static void SET_HOT_WEAPON_SWAP(BOOL set) { invoke<Void>(0xE1E8530B, set); }
}

namespace NETWORK
{
	static BOOL IS_NETWORK_PLAYER_ACTIVE(Player playerindex) { return invoke<BOOL>(0x695996A7, playerindex); }
	static BOOL CAN_REGISTER_MISSION_OBJECT() { return invoke<BOOL>(0x7E38B6C7); }
	static BOOL CAN_REGISTER_MISSION_PED() { return invoke<BOOL>(0x611F091E); }
	static BOOL CAN_REGISTER_MISSION_VEHICLE() { return invoke<BOOL>(0x82E4DBE4); }
	static BOOL DOES_GAME_CODE_WANT_TO_LEAVE_NETWORK_SESSION() { return invoke<BOOL>(0x64D300D9); }
	static BOOL DOES_OBJECT_EXIST_WITH_NETWORK_ID(int netid) { return invoke<BOOL>(0xE09AD5CE, netid); }
	static BOOL DOES_PED_EXIST_WITH_NETWORK_ID(int netid) { return invoke<BOOL>(0x4FFE7D83, netid); }
	static BOOL DOES_PLAYER_HAVE_CONTROL_OF_NETWORK_ID(int player, int id) { return invoke<BOOL>(0x3C4B2083, player, id); }
	static BOOL DOES_VEHICLE_EXIST_WITH_NETWORK_ID(int nedid) { return invoke<BOOL>(0x99302E1E, nedid); }
	static BOOL GET_CELLPHONE_RANKED() { return invoke<BOOL>(0xE8639CC8); }
	static BOOL GET_FILTER_MENU_ON() { return invoke<BOOL>(0x39B5BDBD); }
	static BOOL GET_GFWL_IS_RETURNING_TO_SINGLE_PLAYER() { return invoke<BOOL>(0xAF4FAE7D); }
	static BOOL GET_HOST_MATCH_ON() { return invoke<BOOL>(0x9C7296F4); }
	static BOOL GET_NETWORK_JOIN_FAIL() { return invoke<BOOL>(0x8931712F); }
	static BOOL GET_RETURN_TO_FILTER_MENU() { return invoke<BOOL>(0x9F44EE34); }
	static BOOL HAS_CONTROL_OF_NETWORK_ID(int netid) { return invoke<BOOL>(0x3D0B0270, netid); }
	static BOOL HAS_GAMER_CHANGED_NETWORK_MODEL_SETTINGS() { return invoke<BOOL>(0x96700018); }
	static BOOL HAS_NETWORK_PLAYER_LEFT_GAME(Player playerIndex) { return invoke<BOOL>(0x0E4B4841, playerIndex); }
	static BOOL IS_NETWORK_GAME_PENDING() { return invoke<BOOL>(0x9249610B); }
	static BOOL IS_NETWORK_GAME_RUNNING() { return invoke<BOOL>(0x1C1CF453); }
	static BOOL IS_NETWORK_SESSION() { return invoke<BOOL>(0x1D8FEF54); }
	static BOOL IS_OBJECT_REASSIGNMENT_IN_PROGRESS() { return invoke<BOOL>(0x127EE29C); }
	static BOOL IS_OUR_PLAYER_HIGHER_PRIORITY_FOR_CAR_GENERATION(Player playerIndex) { return invoke<BOOL>(0xE2AF6D4E, playerIndex); }
	static BOOL IS_PARTY_MODE() { return invoke<BOOL>(0x3DF52521); }
	static BOOL IS_THIS_MACHINE_THE_SERVER() { return invoke<BOOL>(0xDA302665); }
	static BOOL LOCAL_PLAYER_IS_READY_TO_START_PLAYING() { return invoke<BOOL>(0xF3411DB1); }
	static BOOL NETWORK_ALL_PARTY_MEMBERS_PRESENT() { return invoke<BOOL>(0x11A857E0); }
	static BOOL NETWORK_AM_I_BLOCKED_BY_PLAYER(Player playerindex) { return invoke<BOOL>(0x953EF45E, playerindex); }
	static BOOL NETWORK_AM_I_MUTED_BY_PLAYER(Player playerIndex) { return invoke<BOOL>(0xE128F2B0, playerIndex); }
	static BOOL NETWORK_CHANGE_GAME_MODE_PENDING() { return invoke<BOOL>(0x8226F769); }
	static BOOL NETWORK_CHANGE_GAME_MODE_SUCCEEDED() { return invoke<BOOL>(0xFBA800BC); }
	static BOOL NETWORK_CHECK_INVITE_ARRIVAL() { return invoke<BOOL>(0x686548FD); }
	static BOOL NETWORK_DID_INVITE_FRIEND(const char* FRIENDNAME) { return invoke<BOOL>(0x9C8802DA, FRIENDNAME); }
	static BOOL NETWORK_END_SESSION_PENDING() { return invoke<BOOL>(0x40490BCC); }
	static BOOL NETWORK_FIND_GAME_PENDING() { return invoke<BOOL>(0x3AE44227); }
	static BOOL NETWORK_GET_LAN_SESSION() { return invoke<BOOL>(0x42DBF8D8); }
	static BOOL NETWORK_HAS_STRICT_NAT() { return invoke<BOOL>(0x635C9B5E); }
	static BOOL NETWORK_HAVE_ACCEPTED_INVITE() { return invoke<BOOL>(0xD780795D); }
	static BOOL NETWORK_HAVE_ONLINE_PRIVILEGES() { return invoke<BOOL>(0xEF63BFDF); }
	static BOOL NETWORK_HAVE_SUMMONS() { return invoke<BOOL>(0x9060239E); }
	static BOOL NETWORK_HOST_GAME_E1(int Gamemode, int Ranked, int Slots, int Private, int Episode, int MaxTeams) { return invoke<BOOL>(0xF83CE269, Gamemode, Ranked, Slots, Episode, MaxTeams); }
	static BOOL NETWORK_HOST_GAME_PENDING() { return invoke<BOOL>(0x7CA0E52B); }
	static BOOL NETWORK_HOST_GAME_SUCCEEDED() { return invoke<BOOL>(0x910F6483); }
	static BOOL NETWORK_HOST_RENDEZVOUS_E1(int Gamemode, int Slots, int Episode) { return invoke<BOOL>(0xBCB12E53, Gamemode, Slots, Episode); }
	static BOOL NETWORK_IS_BEING_KICKED() { return invoke<BOOL>(0x7DC7097C); }
	static BOOL NETWORK_IS_COMMON_EPISODE(int id) { return invoke<BOOL>(0xF599D235, id); }
	static BOOL NETWORK_IS_FIND_RESULT_UPDATED(int p0) { return invoke<BOOL>(0xFE8B2D06, p0); }
	static BOOL NETWORK_IS_FIND_RESULT_VALID(int p0) { return invoke<BOOL>(0xD4920850, p0); }
	static BOOL NETWORK_IS_FRIEND_IN_SAME_TITLE(uint32_t friendid) { return invoke<BOOL>(0xC54365C2, friendid); }
	static BOOL NETWORK_IS_GAME_RANKED() { return invoke<BOOL>(0xAB1DB6B6); }
	static BOOL NETWORK_IS_INVITEE_ONLINE() { return invoke<BOOL>(0x95B2C62F); }
	static BOOL NETWORK_IS_NETWORK_AVAILABLE() { return invoke<BOOL>(0x0F56413E); }
	static BOOL NETWORK_IS_OPERATION_PENDING() { return invoke<BOOL>(0x6895F923); }
	static BOOL NETWORK_IS_PLAYER_BLOCKED_BY_ME(Player playerIndex) { return invoke<BOOL>(0xAE4F4560, playerIndex); }
	static BOOL NETWORK_IS_PLAYER_MUTED_BY_ME(Player playerIndex) { return invoke<BOOL>(0x7A21050E, playerIndex); }
	static BOOL NETWORK_IS_PLAYER_TALKING(Player playerIndex) { return invoke<BOOL>(0xDA9FD9DB, playerIndex); }
	static BOOL NETWORK_IS_PLAYER_TYPING(Player playerIndex) { return invoke<BOOL>(0x22EC4C73, playerIndex); }
	static BOOL NETWORK_IS_RENDEZVOUS() { return invoke<BOOL>(0xB375073A); }
	static BOOL NETWORK_IS_RENDEZVOUS_HOST() { return invoke<BOOL>(0x59502186); }
	static BOOL NETWORK_IS_ROCKSTART_SESSION_ID_VALID() { return invoke<BOOL>(0xC09DF659); }
	static BOOL NETWORK_IS_SESSION_ADVERTISE() { return invoke<BOOL>(0x6781F5D0); }
	static BOOL NETWORK_IS_SESSION_INVITABLE() { return invoke<BOOL>(0x91E81052); }
	static BOOL NETWORK_IS_SESSION_STARTED() { return invoke<BOOL>(0x9D854A37); }
	static BOOL NETWORK_IS_TVT() { return invoke<BOOL>(0xCEB6F262); }
	static BOOL NETWORK_JOIN_GAME_PENDING() { return invoke<BOOL>(0x7057787F); }
	static BOOL NETWORK_JOIN_GAME_SUCCEEDED() { return invoke<BOOL>(0x46E9E85E); }
	static BOOL NETWORK_JOIN_SUMMONS() { return invoke<BOOL>(0x68C293F4); }
	static BOOL NETWORK_LEAVE_GAME_PENDING() { return invoke<BOOL>(0x7AC97D6F); }
	static BOOL NETWORK_PLAYER_HAS_COMM_PRIVS() { return invoke<BOOL>(0xD5ECB496); }
	static BOOL NETWORK_PLAYER_HAS_DIED_RECENTLY(Player playerIndex) { return invoke<BOOL>(0xE7BA498E, playerIndex); }
	static BOOL NETWORK_PLAYER_HAS_HEADSET(Any p0) { return invoke<BOOL>(0x451FB6B6, p0); }
	static BOOL NETWORK_PLAYER_HAS_KEYBOARD(Player playerIndex) { return invoke<BOOL>(0x2C90236B, playerIndex); }
	static BOOL NETWORK_RESULT_MATCHES_SEARCH_CRITERIA(int result) { return invoke<BOOL>(0xC8BAAB49, result); }
	static BOOL NETWORK_RETURN_TO_RENDEZVOUS() { return invoke<BOOL>(0xBC50DADF); }
	static BOOL NETWORK_RETURN_TO_RENDEZVOUS_PENDING() { return invoke<BOOL>(0xBD4A55B9); }
	static BOOL NETWORK_RETURN_TO_RENDEZVOUS_SUCCEEDED() { return invoke<BOOL>(0xBE1FEE66); }
	static BOOL NETWORK_START_SESSION_PENDING() { return invoke<BOOL>(0x5EDF1995); }
	static BOOL NETWORK_START_SESSION_SUCCEEDED() { return invoke<BOOL>(0xA58E8638); }
	static BOOL NETWORK_STRING_VERIFY_PENDING() { return invoke<BOOL>(0xCB9E9A8D); }
	static BOOL NETWORK_STRING_VERIFY_SUCCEEDED() { return invoke<BOOL>(0xC5BCD493); }
	static BOOL PLAYER_WANTS_TO_JOIN_NETWORK_GAME(int p0) { return invoke<BOOL>(0x01F5C0CD, p0); }
	static BOOL REQUEST_CONTROL_OF_NETWORK_ID(int netid) { return invoke<BOOL>(0x0D4C442A, netid); }//unused
	static const char* NETWORK_GET_HOST_SERVER_NAME(int host) { return invoke<const char*>(0x31FB4D34, host); }
	static const char* NETWORK_GET_FRIEND_NAME(int id) { return invoke<const char*>(0x97420B6D, id); }
	static const char* NETWORK_GET_NEXT_TEXT_CHAT() { return invoke<const char*>(0xE781880A); }
	static const char* NETWORK_GET_UNACCEPTED_INVITER_NAME(int p0) { return invoke<const char*>(0x34A7E847, p0); }
	static float GET_ONLINE_SCORE(signed int p0) { return invoke<float>(0x2EF1B788, p0); }//149
	static int FIND_NETWORK_KILLER_OF_PLAYER(Player playerIndex) { return invoke<int>(0xC48C3103, playerIndex); }
	static int GET_DESTROYER_OF_NETWORK_ID(Player playerIndex, int id) { return invoke<int>(0xD6473E63, playerIndex, id); }
	static int GET_GAMER_NETWORK_SCORE(Player playerIndex, int p1, int p2) { return invoke<int>(0xD35BE0FA, playerIndex, p1, p2); }
	static int GET_NO_OF_PLAYERS_IN_TEAM(int team) { return invoke<int>(0x78D7C5BB, team); }
	static int GET_ONLINE_LAN() { return invoke<int>(0x1F0045A3); }
	static int GET_PLAYER_RANK_LEVEL_DURING_MP(Player playerIndex) { return invoke<int>(0x26064043, playerIndex); }
	static int GET_PLAYER_TEAM(int Player) { return invoke<int>(0x9873E404, Player); }
	static int HOW_LONG_HAS_NETWORK_PLAYER_BEEN_DEAD_FOR(Player playerIndex) { return invoke<int>(0xAF6A8802, playerIndex); }
	static int MP_GET_AMOUNT_OF_ANCHOR_POINTS(Ped ped, int id) { return invoke<int>(0x1B5398D7, ped, id); }
	static int MP_GET_AMOUNT_OF_VARIATION_COMPONENT(Ped ped, int componentid) { return invoke<int>(0xF3825A8D, ped, componentid); }
	static int MP_GET_PREFERENCE_VALUE(int prefid) { return invoke<int>(0x32DC4909, prefid); }
	static int MP_GET_PROP_SETUP(Ped ped, int p0, int p1, int p2, int p3) { return invoke<int>(0xA3254C98, ped, p0, p1, p2, p3); }
	static int MP_GET_VARIATION_SETUP(Ped ped, int p0, int p1, int p2, int p3) { return invoke<int>(0x54FB093F, ped, p0, p1, p2, p3); }
	static int NETWORK_ACCEPT_INVITE(Player playerIndex) { return invoke<int>(0xFB31FA9C, playerIndex); }
	static int NETWORK_GET_FRIEND_COUNT() { return invoke<int>(0xA396ACDE); }
	static int NETWORK_GET_GAME_MODE() { return invoke<int>(0x542F6097); }
	static int NETWORK_GET_HOST_AVERAGE_RANK(int host) { return invoke<int>(0x218479E3, host); }
	static int NETWORK_GET_HOST_LATENCY(int host) { return invoke<int>(0x9C4308F8, host); }
	static int NETWORK_GET_HOST_MATCH_PROGRESS(int host) { return invoke<int>(0xFCDC7C26, host); }
	static int NETWORK_GET_NUMBER_OF_GAMES() { return invoke<int>(0x3429AFE6); }
	static int NETWORK_GET_NUM_OPEN_PUBLIC_SLOTS() { return invoke<int>(0x421E3E12); }
	static int NETWORK_GET_NUM_PARTY_MEMBERS() { return invoke<int>(0x39D26713); }
	static int NETWORK_GET_NUM_PLAYERS_MET() { return invoke<int>(0xB04FC561); }
	static int NETWORK_GET_NUM_UNACCEPTED_INVITES() { return invoke<int>(0xE691321E); }
	static int NETWORK_GET_NUM_UNFILLED_RESERVATIONS() { return invoke<int>(0xA7B2E01A); }
	static int NETWORK_GET_PLAYER_ID_OF_NEXT_TEXT_CHAT() { return invoke<int>(0x1A699BDA); }
	static int NETWORK_GET_RENDEZVOUS_HOST_PLAYER_ID() { return invoke<int>(0x3ECEA8B7); }
	static int NETWORK_GET_UNACCEPTED_INVITE_EPISODE(Any p0) { return invoke<int>(0x0FF5356E, p0); }
	static int NETWORK_SET_SERVER_NAME(const char* name) { return invoke<int>(0x5C5EE458, name); }
	static int STORE_DAMAGE_TRACKER_FOR_NETWORK_PLAYER(Player playerIndex, int p1, Any p2) { return invoke<int>(0x56CBC08C, playerIndex, p1, p2); }
	static Any GET_SERVER_ID() { return invoke<Any>(0x57F9073C); }
	static Any NETWORK_GET_SERVER_NAME() { return invoke<Any>(0x82B4ACB1); }
	static Any NETWORK_IS_FRIEND_ONLINE(Any p0) { return invoke<Any>(0xE0A42430, p0); }
	static uint32_t GET_HOST_ID() { return invoke<uint32_t>(0x5F70F5A3); }
	static uint32_t GET_LOCAL_GAMERLEVEL_FROM_PROFILESETTINGS() { return invoke<uint32_t>(0xADB257C7); }
	static uint32_t GET_NUMBER_OF_PLAYERS() { return invoke<uint32_t>(0x4C1B8867); }
	static uint32_t GET_PLAYER_COLOUR(int Player) { return invoke<uint32_t>(0x710C76F6, Player); }
	static uint32_t NETWORK_GET_MAX_PRIVATE_SLOTS() { return invoke<uint32_t>(0xFF2121DE); }
	static uint32_t NETWORK_GET_MAX_SLOTS() { return invoke<uint32_t>(0xE7DA761C); }
	static void ACTIVATE_DAMAGE_TRACKER_ON_NETWORK_ID(Any p0, Any p1) { invoke<Void>(0x95D07BA5, p0, p1); }
	static void ACTIVATE_NETWORK_SETTINGS_MENU() { invoke<Void>(0x719C50AA); }
	static void ADD_GROUP_TO_NETWORK_RESTART_NODE_GROUP_LIST(int p0) { invoke<Void>(0x3105DC1F, p0); }
	static void ADD_SPAWN_BLOCKING_AREA(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0xDAA55B46, p0, p1, p2, p3); }
	static void ADD_SPAWN_BLOCKING_DISC(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x45EBD3DE, p0, p1, p2, p3, p4); }
	static void CLEAR_NETWORK_RESTART_NODE_GROUP_LIST() { invoke<Void>(0x5B4D98C0); }
	static void CLEAR_SCRIPT_ARRAY_FROM_SCRATCHPAD(int p0) { invoke<Void>(0x50770E90, p0); }
	static  void DEACTIVATE_NETWORK_SETTINGS_MENU() { invoke<Void>(0xA93F3450); }
	static void DISPLAY_PLAYER_NAMES(Any p0) { invoke<Void>(0x8F01C7D0, p0); }
	static void FIND_NETWORK_RESTART_POINT(Any p0, Any p1, Any p2) { invoke<Void>(0x202484D0, p0, p1, p2); }
	static void FLUSH_ALL_SPAWN_BLOCKING_AREAS() { invoke<Void>(0xF25ECA71); }
	static void GET_COORDINATES_FOR_NETWORK_RESTART_NODE(Any p0, Any p1, Any p2) { invoke<Void>(0xA6A94CF0, p0, p1, p2); }
	static void GET_NETWORK_ID_FROM_OBJECT(Object obj, int* netid) { invoke<Void>(0x9FA75090, obj, netid); }
	static void GET_NETWORK_ID_FROM_PED(Ped ped, int* netid) { invoke<Void>(0x4FA366E8, ped, netid); }
	static void GET_NETWORK_ID_FROM_VEHICLE(Vehicle vehicle, int* netid) { invoke<Void>(0x700C3DDA, vehicle, netid); }
	static void GET_NETWORK_TIMER(int p0) { invoke<Void>(0xF733052C, p0); }
	static void GET_OBJECT_FROM_NETWORK_ID(int netid, Object* obj) { invoke<Void>(0x8055551F, netid, obj); }
	static void GET_PLAYER_RGB_COLOUR(int Player, int* r, int* g, int* b) { invoke<Void>(0x6EF43BBB, Player, r, g, b); }
	static void GET_SPAWN_COORDINATES_FOR_CAR_NODE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<Void>(0xFD7281BF, p0, p1, p2, p3, p4, p5); }
	static void GET_TEAM_RGB_COLOUR(int team, int* R, int* G, int* B) { invoke<Void>(0xEAEC3986, team, R, G, B); }
	static void GET_VEHICLE_FROM_NETWORK_ID(int netid, Vehicle* vehicle) { invoke<Void>(0x771F4AC6, netid, vehicle); }
	static void LAUNCH_LOCAL_PLAYER_IN_NETWORK_GAME() { invoke<Void>(0xA3594132); }
	static void MP_SET_PREFERENCE_VALUE(int prefid, int value) { invoke<Void>(0x48729115, prefid, value); }
	static void NETWORK_SET_FRIENDLY_FIRE_OPTION(Any p0) { invoke<Void>(0x6BAF95FA, p0); }
	static void NETWORK_SET_HEALTH_RETICULE_OPTION(BOOL p0) { invoke<Void>(0x18319AA8, p0); }
	static void NETWORK_SET_LAN_SESSION(Any p0) { invoke<Void>(0x432BC94D, p0); }
	static void NETWORK_SET_LOCAL_PLAYER_IS_TYPING(Player PlayerIndex) { invoke<Void>(0x25F07B0F, PlayerIndex); }
	static void NETWORK_SET_MATCH_PROGRESS(float p0) { invoke<Void>(0x841C0D19, p0); }
	static BOOL NETWORK_SET_PLAYER_MUTED(int playerIndex, BOOL value) { return invoke<BOOL>(0xCE451908, playerIndex, value); }
	static void NETWORK_SET_SCRIPT_LOBBY_STATE(Any p0) { invoke<Void>(0x142B7132, p0); }
	static void NETWORK_SET_SESSION_INVITABLE(BOOL invitable) { invoke<Void>(0x548E9F99, invitable); }
	static void NETWORK_SET_TALKER_FOCUS(Any p0) { invoke<Void>(0xDCDAC012, p0); }
	static void NETWORK_SET_TALKER_PROXIMITY(Any p0) { invoke<Void>(0x67555C66, p0); }
	static void NETWORK_SET_TEAM_ONLY_CHAT(BOOL p0) { invoke<Void>(0x3813019A, p0); }
	static void NETWORK_SET_TEXT_CHAT_RECIPIENTS(Any p0) { invoke<Void>(0x10D67C87, p0); }
	static void NETWORK_SHOW_FRIEND_PROFILE_UI(Any p0) { invoke<Void>(0x58D0361F, p0); }
	static void NETWORK_SHOW_MET_PLAYER_FEEDBACK_UI(Player metPlayerIndex) { invoke<Void>(0x7759A85A, metPlayerIndex); }
	static void NETWORK_SHOW_PLAYER_FEEDBACK_UI(Player payerIndex) { invoke<Void>(0x03380FC1, payerIndex); }
	static void NETWORK_SHOW_MET_PLAYER_PROFILE_UI(Any p0) { invoke<Void>(0x2AB80821, p0); }
	static void NETWORK_SHOW_PLAYER_PROFILE_UI(Player playerIndex) { invoke<Void>(0x4F05A4BE, playerIndex); }
	static void NETWORK_START_EXTENDED_SEARCH(Any p0) { invoke<Void>(0xA23A23F7, p0); }
	static void NETWORK_START_SESSION() { invoke<Void>(0x093FB4C8); }
	static void NETWORK_STORE_GAME_CONFIG(Any p0) { invoke<Void>(0x04504805, p0); }
	static void NETWORK_VERIFY_USER_STRING(Any p0) { invoke<Void>(0xCA82A790, p0); }
	static void REGISTER_CLIENT_BROADCAST_VARIABLES(Any p0, Any p1, Any p2) { invoke<Void>(0xF1732769, p0, p1, p2); }
	static void REGISTER_HOST_BROADCAST_VARIABLES(Any p0, int p1, int p2) { invoke<Void>(0xBEDD194D, p0, p1, p2); }
	static void REGISTER_KILL_IN_MULTIPLAYER_GAME(Player playerIndex, int id, uint32_t p2) { invoke<Void>(0xFE86190E, playerIndex, id, p2); }
	static void REGISTER_MULTIPLAYER_GAME_WIN(Player playerIndex, BOOL p1) { invoke<Void>(0x1C2EBC92, playerIndex, p1); }
	static void REGISTER_NETWORK_BEST_GAME_SCORES(Player playerIndex, int p1, int p2) { invoke<Void>(0x78A27645, playerIndex, p1, p2); }
	static void RESERVE_NETWORK_MISSION_OBJECTS_FOR_HOST(int count) { invoke<Void>(0x688376E9, count); }
	static void RESERVE_NETWORK_MISSION_PEDS_FOR_HOST(int p0) { invoke<Void>(0x3EA1D498, p0); }
	static void RESERVE_NETWORK_MISSION_VEHICLES(int p0) { invoke<Void>(0x5062875E, p0); }
	static void RESERVE_NETWORK_MISSION_VEHICLES_FOR_HOST(int p0) { invoke<Void>(0x3D7B2A5E, p0); }
	static void RESTORE_SCRIPT_ARRAY_FROM_SCRATCHPAD(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x5AB30FE1, p0, p1, p2, p3); }
	static void RESURRECT_NETWORK_PLAYER(Player playerIndex, float x, float y, float z, int p4) { invoke<Void>(0xDD08D07A, playerIndex, x, y, z, p4); }
	static void SAVE_SCRIPT_ARRAY_IN_SCRATCHPAD(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x8A3A3C98, p0, p1, p2, p3); }
	static void SET_ARMOUR_PICKUP_NETWORK_REGEN_TIME(uint32_t timeMS) { invoke<Void>(0x07CA5A73, timeMS); }
	static void SET_CAR_EXISTS_ON_ALL_MACHINES(Vehicle vehicle, BOOL exists) { invoke<Void>(0xBA4C8FEB, vehicle, exists); }
	static void SET_CELLPHONE_RANKED(BOOL toggle) { invoke<Void>(0xFF41EAAD, toggle); }
	static void SET_FILTER_MENU_ON(BOOL toggle) { invoke<Void>(0xA836EDDC, toggle); }
	static void SET_GFWL_IS_RETURNING_TO_SINGLE_PLAYER(Any p0) { invoke<Void>(0x27EBAAFD, p0); }
	static void SET_HEALTH_PICKUP_NETWORK_REGEN_TIME(uint32_t timeMS) { invoke<Void>(0x2423BC30, timeMS); }
	static void SET_HOST_MATCH_ON(BOOL p0) { invoke<Void>(0x9660FD45, p0); }
	static void SET_IK_DISABLED_FOR_NETWORK_PLAYER(Player playerIndex, BOOL p1) { invoke<Void>(0xD99CE506, playerIndex, p1); }
	static void SET_IN_MP_TUTORIAL(BOOL set) { invoke<Void>(0x2FD05431, set); }
	static void SET_IN_SPECTATOR_MODE(BOOL spectate) { invoke<Void>(0x74DBC1BF, spectate); }
	static void SET_KILLSTREAK() { invoke<Void>(0x2426610C); }
	static void SET_LOBBY_MUTE_OVERRIDE(BOOL set) { invoke<Void>(0x35BA6682, set); }
	static void SET_MSG_FOR_LOADING_SCREEN(const char* label) { invoke<Void>(0x0C128376, label); }
	static void SET_NETWORK_ID_CAN_MIGRATE(int netid, BOOL value) { invoke<Void>(0x47C8E5FF, netid, value); }
	static void SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(int netID, BOOL set) { invoke<Void>(0x68D486B2, netID, set); }
	static void SET_NETWORK_ID_STOP_CLONING(int id, BOOL p1) { invoke<Void>(0x42B1F401, id, p1); }
	static void SET_NETWORK_JOIN_FAIL(BOOL p0) { invoke<Void>(0x13D7DEA2, p0); }
	static void SET_NETWORK_PLAYER_AS_VIP(Player playerIndex, BOOL p1) { invoke<Void>(0x8B87F9E1, playerIndex, p1); }
	static void SET_NETWORK_VEHICLE_RESPOT_TIMER(int id, int p1) { invoke<Void>(0x2C30912D, id, p1); }
	static void SET_OBJECT_EXISTS_ON_ALL_MACHINES(Object obj, BOOL exists) { invoke<Void>(0xE53691B8, obj, exists); }
	static void SET_ONLINE_LAN(BOOL p0) { invoke<Void>(0x2D79F99C, p0); }
	static void SET_OVERRIDE_NO_SPRINTING_ON_PHONE_IN_MULTIPLAYER(BOOL p0) { invoke<Void>(0xE9FDDA54, p0); }
	static void SET_PED_COMPONENTS_TO_NETWORK_PLAYERSETTINGS_MODEL(Ped ped) { invoke<Void>(0x270FFC9B, ped); }
	static void SET_PED_EXISTS_ON_ALL_MACHINES(Ped ped, BOOL exists) { invoke<Void>(0xDABA6B79, ped, exists); }
	static void SET_PLAYERS_DROP_MONEY_IN_NETWORK_GAME(BOOL toggle) { invoke<Void>(0x0806204B, toggle); }
	static void SET_PLAYER_CONTROL_FOR_NETWORK(Player playerIndex, BOOL unknownTrue, BOOL unknownFalse) { invoke<Void>(0x04E33A0A, playerIndex, unknownTrue, unknownFalse); }
	static void SET_PLAYER_TEAM(int Player, int team) { invoke<Void>(0x725ADCF2, Player, team); }
	static void SET_RETURN_TO_FILTER_MENU(BOOL p0) { invoke<Void>(0x0CD98CC2, p0); }
	static void SET_RICH_PRESENCE(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x7BDCBD45, p0, p1, p2, p3, p4); }
	static void SET_RICH_PRESENCE_TEMPLATEFILTER() { invoke<Void>(0xD1FE2CC0); }
	static void SET_RICH_PRESENCE_TEMPLATELOBBY(Any p0) { invoke<Void>(0xBAFA4F82); }
	static void SET_RICH_PRESENCE_TEMPLATEMP1(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0xE43F303F, p0, p1, p2); }
	static void SET_RICH_PRESENCE_TEMPLATEMP2(Any p0) { invoke<Void>(0x9AE89D93, p0); }
	static void SET_RICH_PRESENCE_TEMPLATEMP3(int p0, int p1) { invoke<Void>(0x08B1F924, p0, p1); }
	static void SET_RICH_PRESENCE_TEMPLATEMP4(Any p0, Any p1) { invoke<Void>(0x2F61468A, p0, p1); }
	static void SET_RICH_PRESENCE_TEMPLATEMP5(Any p0, Any p1, Any p2) { invoke<Void>(0x1D2CA221, p0, p1, p2); }
	static void SET_RICH_PRESENCE_TEMPLATEMP6(Any p0, Any p1, Any p2) { invoke<Void>(0xD3BE0F3D, p0, p1, p2); }
	static void SET_RICH_PRESENCE_TEMPLATEPARTY() { invoke<Void>(0xD3BE0F3D); }
	static void SET_RICH_PRESENCE_TEMPLATESP1(Any p0, Any p1, Any p2) { invoke<Void>(0x832B28DA, p0, p1, p2); }
	static void SET_RICH_PRESENCE_TEMPLATESP2(int p0) { invoke<Void>(0x68FDF488, p0); }
	static void SET_SERVER_ID(int id) { invoke<Void>(0xC1BEF9D0, id); }
	static void SET_START_FROM_FILTER_MENU(Any p0) { invoke<Void>(0xD87D1555, p0); }
	static void SET_SYNC_WEATHER_AND_GAME_TIME(BOOL p0) { invoke<Void>(0xB3A07403, p0); }
	static void SET_THIS_MACHINE_RUNNING_SERVER_SCRIPT(BOOL host) { invoke<Void>(0x1626C5C3, host); }
	static void SET_WEAPON_PICKUP_NETWORK_REGEN_TIME(int weaponType, uint32_t timeMS) { invoke<Void>(0xA64325FE, weaponType, timeMS); }
	static void SHUTDOWN_AND_LAUNCH_NETWORK_GAME(uint32_t episode) { invoke<Void>(0x691694D2, episode); }
	static void SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME() { invoke<Void>(0x92B7351C); }
	static void STORE_SCRIPT_VALUES_FOR_NETWORK_GAME(Any p0) { invoke<Void>(0x53DF52BA, p0); }
	static void TELL_NET_PLAYER_TO_START_PLAYING(Player playerIndex, BOOL p1) { invoke<Void>(0xE1027B43, playerIndex, p1); }
	static void TERMINATE_ALL_SCRIPTS_FOR_NETWORK_GAME() { invoke<Void>(0x51C902BD); }
	static void THIS_SCRIPT_IS_SAFE_FOR_NETWORK_GAME() { invoke<Void>(0x439071C4); }
	static void TURN_OFF_RADIOHUD_IN_LOBBY() { invoke<Void>(0x17EDCC99); }
	static void UNOBFUSCATE_INT(int count, int* val) { invoke<Void>(0x0E74EEAC, count, val); }
	static void UNOBFUSCATE_INT_ARRAY(Any p0, Any p1) { invoke<Void>(0x8ACDFBBA, p0, p1); }
	static void UPDATE_NETWORK_RELATIVE_SCORE(Any p0, Any p1, Any p2) { invoke<Void>(0x3937B8AB, p0, p1, p2); }
	static void UPDATE_NETWORK_STATISTICS(Player playerIndex, int p0, int p1, int p2) { invoke<Void>(0x89CF3B57, playerIndex, p0, p1, p2); }
	static void USE_PLAYER_COLOUR_INSTEAD_OF_TEAM_COLOUR(BOOL p0) { invoke<Void>(0x4DD46DAE, p0); }
	static Any CALCULATE_CHECKSUM(Any p0, Any p1) { return invoke<Void>(0x90E0E14D, p0, p1); }
	static Any GET_CLOSEST_NETWORK_RESTART_NODE(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<Any>(0xFFF0E04A, p0, p1, p2, p3, p4); }
	static Any GET_RANDOM_NETWORK_RESTART_NODE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<Any>(0x943F64AD, p0, p1, p2, p3, p4, p5); }
	static Any GET_RANDOM_NETWORK_RESTART_NODE_USING_GROUP_LIST(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<Any>(0xB150397E, p0, p1, p2, p3, p4, p5); }
	static Any GET_SORTED_NETWORK_RESTART_NODE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<Any>(0x0002B59A, p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static Any GET_SORTED_NETWORK_RESTART_NODE_USING_GROUP_LIST(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<Any>(0x040D4FAA, p0, p1, p2, p3, p4, p5, p6, p7, p8); }
	static Any GET_START_FROM_FILTER_MENU() { return invoke<Any>(0x27E85514); }
	static Any IS_SPHERE_VISIBLE_TO_ANOTHER_MACHINE(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x23C5274E, p0, p1, p2, p3); }
	static Any NETWORK_CHANGE_GAME_MODE(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0xCB8178A3, p0, p1, p2, p3); }
	static Any NETWORK_GET_MET_PLAYER_NAME(Any p0) { return invoke<Any>(0xA70BA410, p0); }
	static Any NETWORK_GET_UNACCEPTED_INVITE_GAME_MODE(Any p0) { return invoke<Any>(0xF66BCD00, p0); }
	static Any NETWORK_JOIN_GAME(Any p0) { return invoke<Any>(0x06F47F40, p0); }
	static Any NETWORK_RESTORE_GAME_CONFIG(Any p0) { return invoke<Any>(0xEA854794, p0); }
	static Any NETWORK_SEND_TEXT_CHAT(Player playerIndex, Any p1) { return invoke<Any>(0x85022D87, playerIndex, p1); }
	static Any NETWORK_STORE_SINGLE_PLAYER_GAME() { return invoke<Any>(0xA52597AE); }
	static Any RESTORE_SCRIPT_VALUES_FOR_NETWORK_GAME(Any p0) { return invoke<Any>(0x242AE86B, p0); }
	static void GET_CAMERA_FROM_NETWORK_ID(int ned_id, int* cam) { invoke<Void>(0x36438285, ned_id, cam); }
}

namespace DLC1
{
	static void FLUSH_ALL_PLAYER_RESPAWN_COORDS() { invoke<Void>(0x86149E7C); }
	static void SEND_CLIENT_BROADCAST_VARIABLES_NOW() { invoke<Void>(0x5857B1DC); }
	static void SET_PLAYER_AS_DAMAGED_PLAYER(Player playerIndex, int p1, BOOL p2) { invoke<Void>(0x29C30A3E, playerIndex, p1, p2); }
}

namespace CONTROLS
{
	static BOOL IS_BUTTON_PRESSED(uint32_t padIndex, uint32_t button) { return invoke<BOOL>(0x7BCB3F15, padIndex, button); }
	static BOOL IS_BUTTON_JUST_PRESSED(uint32_t padIndex, uint32_t button) { return invoke<BOOL>(0x7FCD1FA1, padIndex, button); }
}

namespace DLC2
{
	static BOOL IS_LCPD_DATA_VALID() { return invoke<BOOL>(0x9DFB0C6F); }
	static void SET_DISPLAY_PLAYER_NAME_AND_ICON(Player playerIndex, BOOL set) { invoke<Void>(0xA3202CBD, playerIndex, set); }
	static void SET_NETWORK_PED_USING_PARACHUTE(Ped ped) { invoke<Void>(0xEB68AE51, ped); }
	static void SET_ONLINE_SCORE(int p0, Any p1) { invoke<Void>(0xCE7B2413, p0, p1); }
	static void STOP_SYNCING_SCRIPT_ANIMATIONS(BOOL p0) { invoke<Void>(0x74098F99, p0); }
}

namespace PTFX
{
	static BOOL TRIGGER_PTFX(const char* name, float x, float y, float z, float p4, float p5, float p6, uint32_t flags) { return invoke<BOOL>(0x94C4F762, name, x, y, z, p4, p5, p6, flags); }
	static BOOL TRIGGER_PTFX_ON_OBJ(const char* name, Object obj, float x, float y, float z, float p5, float p6, float p7, uint32_t flags) { return invoke<BOOL>(0x3325AB9C, name, obj, x, y, z, p5, p6, p7, flags); }
	static BOOL TRIGGER_PTFX_ON_OBJ_BONE(const char* name, Object obj, float x, float y, float z, float p5, float p6, float p7, int objbone, uint32_t flags) { return invoke<BOOL>(0x30DACB16, name, obj, x, y, z, p5, p6, p7, objbone, flags); }
	static BOOL TRIGGER_PTFX_ON_PED(const char* name, Ped ped, float x, float y, float z, float p5, float p6, float p7, uint32_t flags) { return invoke<BOOL>(0x98502552, name, ped, x, y, z, p5, p6, p7, flags); }
	static BOOL TRIGGER_PTFX_ON_PED_BONE(const char* name, Ped ped, float x, float y, float z, float p5, float p6, float p7, int pedbone, uint32_t flags) { return invoke<BOOL>(0x9AB3E389, name, ped, x, y, z, p5, p6, p7, pedbone, flags); }
	static BOOL TRIGGER_PTFX_ON_VEH(const char* name, Vehicle veh, float x, float y, float z, float p5, float p6, float p7, float p8) { return invoke<BOOL>(0x6337D904, name, veh, x, y, z, p5, p6, p7, p8); }
	static uint32_t START_PTFX(const char* name, float x, float y, float z, float yaw, float pitch, float roll, float scale) { return invoke<uint32_t>(0xA3126963, name, x, y, z, yaw, pitch, roll, scale); }
	static uint32_t START_PTFX_ON_OBJ(const char* name, Object obj, float x, float y, float z, float yaw, float pitch, float roll, float scale) { return invoke<uint32_t>(0xD8AA4503, name, obj, x, y, z, yaw, pitch, roll, scale); }
	static uint32_t START_PTFX_ON_OBJ_BONE(const char* name, Object obj, float x, float y, float z, float yaw, float pitch, float roll, int objbone, float scale) { return invoke<uint32_t>(0x3101366B, name, obj, x, y, z, yaw, pitch, objbone, scale); }
	static uint32_t START_PTFX_ON_PED(const char* name, Ped ped, float x, float y, float z, float yaw, float pitch, float roll, float scale) { return invoke<uint32_t>(0xFD749E83, name, ped, x, y, z, yaw, pitch, roll, scale); }
	static uint32_t START_PTFX_ON_PED_BONE(const char* name, Ped ped, float x, float y, float z, float yaw, float pitch, float roll, int pedbone, float scale) { return invoke<uint32_t>(0x51A7FB1B, name, ped, x, y, z, yaw, pitch, roll, pedbone, scale); }
	static uint32_t START_PTFX_ON_VEH(const char* name, Vehicle veh, float x, float y, float z, float yaw, float pitch, float roll, float scale) { return invoke<uint32_t>(0x7475356F, name, veh, x, y, z, yaw, pitch, roll, scale); }
	static void EVOLVE_PTFX(uint32_t ptfx, const char* evolvetype, float val) { invoke<Void>(0x14BAAF08, ptfx, evolvetype, val); }
	static void REMOVE_PROJTEX_FROM_OBJECT(Object obj) { invoke<Void>(0x119A0327, obj); }
	static void REMOVE_PROJTEX_IN_RANGE(float x, float y, float z, float radius) { invoke<Void>(0xB2842710, x, y, z, radius); }
	static void REMOVE_PTFX(uint32_t ptfx) { invoke<Void>(0xF47D7A02, ptfx); }
	static void REMOVE_PTFX_FROM_OBJECT(Object obj) { invoke<Void>(0x92526A45, obj); }
	static void REMOVE_PTFX_FROM_PED(Ped ped) { invoke<Void>(0xFA481384, ped); }
	static void REMOVE_PTFX_FROM_VEHICLE(Vehicle veh) { invoke<Void>(0x5AF920A1, veh); }
	static void STOP_PTFX(uint32_t ptfx) { invoke<Void>(0x53C54911, ptfx); }
	static void UPDATE_PTFX_OFFSETS(uint32_t ptfx, float x, float y, float z, float p4, float p5, float p6) { invoke<Void>(0x96DD20B9, ptfx, x, y, z, p4, p5, p6); }
	static void UPDATE_PTFX_TINT(uint32_t ptfx, float r, float g, float b, float a) { invoke<Void>(0xCFFC4028, ptfx, r, g, b, a); }
}

namespace PICKUP
{
	static BOOL DOES_PICKUP_EXIST(Pickup pickup) { return invoke<BOOL>(0x9C6DA0B3, pickup); }
	static BOOL HAS_PICKUP_BEEN_COLLECTED(Pickup pickup) { return invoke<BOOL>(0x0BE5CCED, pickup); }
	static BOOL IS_ANY_PICKUP_AT_COORDS(float x, float y, float z) { return invoke<BOOL>(0x6EDE3A6F, x, y, z); }
	static BOOL IS_MONEY_PICKUP_AT_COORDS(float x, float y, float z) { return invoke<BOOL>(0x07FF9CEA, x, y, z); }
	static int COUNT_PICKUPS_OF_TYPE(int type) { return invoke<int>(0x19220CE2, type); }
	static void ADD_PICKUP_TO_INTERIOR_ROOM_BY_KEY(Object pickup, uint32_t room_hash) { invoke<Void>(0x15623096, pickup, room_hash); }
	static void ADD_PICKUP_TO_INTERIOR_ROOM_BY_NAME(Pickup pickup, const char* roomName) { invoke<Void>(0xA2A73564, pickup, roomName); }
	static void CREATE_MONEY_PICKUP(float x, float y, float z, uint32_t amount, BOOL unknownTrue, Pickup* pPickup) { invoke<Void>(0x36A3D8FA, x, y, z, amount, unknownTrue, pPickup); }
	static void CREATE_PICKUP(uint32_t model, uint32_t pickupType, float x, float y, float z, Pickup* pPickup, BOOL unknownFalse) { invoke<Void>(0x5E14DF68, model, pickupType, x, y, z, pPickup, unknownFalse); }
	static void CREATE_PICKUP_ROTATE(uint32_t model, uint32_t pickupType, uint32_t unknown, float x, float y, float z, float rX, float rY, float rZ, Pickup* pPickup) { invoke<Void>(0xF015BFE2, model, pickupType, unknown, x, y, z, rX, rY, rZ, pPickup); }
	static void CREATE_PICKUP_WITH_AMMO(uint32_t model, uint32_t pickupType, uint32_t unknown, float x, float y, float z, Pickup* pPickup) { invoke<Void>(0x47C32331, model, pickupType, unknown, x, y, z, pPickup); }
	static void GET_PICKUP_COORDINATES(Pickup pickup, float* pX, float* pY, float* pZ) { invoke<Void>(0xC80E9E6B, pickup, pX, pY, pZ); }
	static void GET_ROOM_KEY_FROM_PICKUP(int pickup, uint32_t* hash) { invoke<Void>(0xC9EA67B1, pickup, hash); }
	static void GET_SAFE_PICKUP_COORDS(float x, float y, float z, float* pSafeX, float* pSafeY, float* pSafeZ) { invoke<Void>(0x618B5F67, x, y, z, pSafeX, pSafeY, pSafeZ); }
	static void REMOVE_ALL_PICKUPS_OF_TYPE(uint32_t type) { invoke<Void>(0x40062C53, type); }
	static void REMOVE_PICKUP(Pickup pickup) { invoke<Void>(0x64A7A0E0, pickup); }
	static void REMOVE_TEMPORARY_RADAR_BLIPS_FOR_PICKUPS() { invoke<Void>(0x9A951332); }
	static void RENDER_WEAPON_PICKUPS_BIGGER(BOOL value) { invoke<Void>(0xD5EE42F9, value); }
	static void SET_ALL_PICKUPS_OF_TYPE_COLLECTABLE_BY_CAR(int pickuptype, BOOL set) { invoke<Void>(0x32845E38, pickuptype, set); }
	static void SET_DO_NOT_SPAWN_PARKED_CARS_ON_TOP(int pickup, BOOL set) { invoke<Void>(0x8924931E, pickup, set); }
	static void SET_PICKUPS_FIX_CARS(BOOL set) { invoke<Void>(0x420F9044, set); }
	static void SET_PICKUP_COLLECTABLE_BY_CAR(Object pickup, BOOL set) { invoke<Void>(0x773CC2DD, pickup, set); }
	static void SWITCH_ARROW_ABOVE_BLIPPED_PICKUPS(BOOL on) { invoke<Void>(0x05F94B87, on); }
}

namespace WIDGET
{
	static const char* ADD_TEXT_WIDGET(Any p0) { return invoke<const char*>(0xE178AA0F, p0); }
	static int GET_CONTENTS_OF_TEXT_WIDGET(Any p0) { return invoke<int>(0x28BE9702, p0); }
	static void ADD_TO_WIDGET_COMBO(Any p0) { invoke<Void>(0xE136E83E, p0); }
	static void ADD_WIDGET_FLOAT_READ_ONLY(Any p0, Any p1) { invoke<Void>(0xEF2D8DEA, p0, p1); }
	static void ADD_WIDGET_FLOAT_SLIDER(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x67865135, p0, p1, p2, p3, p4); }
	static void ADD_WIDGET_READ_ONLY(Any p0, Any p1) { invoke<Void>(0x806EEC47, p0, p1); }
	static void ADD_WIDGET_SLIDER(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x1A76E4B9, p0, p1, p2, p3, p4); }
	static void ADD_WIDGET_STRING(Any p0) { invoke<Void>(0xC541594C, p0); }
	static void ADD_WIDGET_TOGGLE(Any p0, Any p1) { invoke<Void>(0x03A1E420, p0, p1); }
	static void CREATE_WIDGET_GROUP(Any p0) { invoke<Void>(0x92DE0ECC, p0); }
	static void DELETE_WIDGET(Any p0) { invoke<Void>(0xB3CAB5FB, p0); }
	static void DELETE_WIDGET_GROUP(Any p0) { invoke<Void>(0xD215BACE, p0); }
	static void END_WIDGET_GROUP() { invoke<Void>(0xBD5D7F9C); }
	static void FINISH_WIDGET_COMBO(Any p0, Any p1) { invoke<Void>(0x4E048A5A, p0, p1); }
	static BOOL DOES_WIDGET_GROUP_EXIST(Any p0) { return invoke<BOOL>(0x2B1D2AF9, p0); }
	static void SET_CONTENTS_OF_TEXT_WIDGET(Any p0, Any p1) { invoke<Void>(0x74E6F8F5, p0, p1); }
	static void START_NEW_WIDGET_COMBO() { invoke<Void>(0x284A3C93); }
}

namespace DEBUG
{
	static void SET_CHAR_NAME_DEBUG(Ped ped, const char* debugName) { invoke<Void>(0xD4BCCA69, ped, debugName); }
	static void OPEN_DEBUG_FILE() { invoke<Void>(0xA754055A); }
	static void CLOSE_DEBUG_FILE() { invoke<Void>(0xAFDE128D); }
	static void DEBUG_OFF() { invoke<Void>(0x31481A35); }
	static void DRAW_DEBUG_SPHERE(float x, float y, float z, float radius) { invoke<Void>(0x304D0EEF, x, y, z, radius); }
	static void SAVE_FLOAT_TO_DEBUG_FILE(Any p0) { invoke<Void>(0xAE315350, p0); }
	static void SAVE_INT_TO_DEBUG_FILE(Any p0) { invoke<Void>(0x13F0037D, p0); }
	static void SAVE_NEWLINE_TO_DEBUG_FILE() { invoke<Void>(0x36383B18); }
	static void SAVE_STRING_TO_DEBUG_FILE(Any p0) { invoke<Void>(0x1BC43E17, p0); }
	static BOOL IS_DEBUG_CAMERA_ON() { return invoke<BOOL>(0xDA5FB969); }
	static const char* GET_MODEL_NAME_FOR_DEBUG(uint32_t model) { return invoke<const char*>(0x6076B648, model); }
	static void ENABLE_DEBUG_CAM(BOOL enable) { invoke<Void>(0x4330116C, enable); }
	static void GET_DEBUG_CAM(Cam* cam) { invoke<Void>(0x76A50592, cam); }
	static void INIT_DEBUG_WIDGETS() { invoke<Void>(0x3D0C3ECA); }
	static void SCRIPT_ASSERT(const char* text) { invoke<Void>(0xD9BCCE95, text); }
	static void SET_DEBUG_TEXT_VISIBLE(BOOL p0) { invoke<Void>(0x50017383, p0); }
	static int GET_CONSOLE_COMMAND_TOKEN() { return invoke<int>(0x9DE3DE24); }
	static int GET_LATEST_CONSOLE_COMMAND() { return invoke<int>(0x2B547FE6); }
}




