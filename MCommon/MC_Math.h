// Massgate
// Copyright (C) 2017 Ubisoft Entertainment
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
#pragma once 
#ifndef INCGUARD_MC_MATH_H
#define INCGUARD_MC_MATH_H

#include "mc_globaldefines.h"
#include <math.h>
#include <xmmintrin.h>
#pragma intrinsic( cos, sin, sqrt )

// Fast with decent accuracy.
MC_FORCEINLINE f32 MC_InvSqrtFastSafe(f32 x)
{
#if IS_PC_BUILD

	// Error around 0.0004%
	f32 xhalf = 0.5f * x;
	s32 i = *(s32*)&x;
	i = 0x5f3759df - (i>>1);
	x = *(f32*)&i;
	x = x*(1.5f - xhalf*x*x);
	x = x*(1.5f - xhalf*x*x);	// Extra Newton-Raphson step to improve precision
	return x;

#else

	// Error around 0.00001%
	// We add the tiny value to avoid exceptions on zero input (this does not affect precision measurably).
	return 1.0f / (1e-15f + sqrtf(x));

#endif
}

// Very fast, but very inaccurate.
MC_FORCEINLINE f32 MC_InvSqrtFastSafe_Estimate(f32 x)
{
#if IS_PC_BUILD

	// Error around 0.15%
	f32 xhalf = 0.5f * x;
	s32 i = *(s32*)&x;
	i = 0x5f3759df - (i>>1);
	x = *(f32*)&i;
	x = x*(1.5f - xhalf*x*x);
	return x;

#else

	// Error around 0.00001%
	// We add the tiny value to avoid exceptions on zero input (this does not affect precision measurably).
	return 1.0f / (1e-15f + sqrtf(x));

#endif
}

MC_FORCEINLINE void __fastcall MC_SinCos(f32 angle, f32* s, f32* c)
{
	__asm
	{
		mov      ecx, c
		mov      edx, s

		fld      dword ptr [angle]
		fsincos
		fstp     dword ptr [ecx]
		fstp     dword ptr [edx]
	}
	*s = (f32)sin(angle);
	*c = (f32)cos(angle);
}

MC_FORCEINLINE void __fastcall MC_SinCosVec(f32 angleA, f32 angleB, f32 angleC, f32* sinvals, f32* cosvals)
{
	__asm
	{
		mov      ecx, cosvals
		mov      edx, sinvals

		fld      dword ptr [angleA]
		fsincos
		fstp     dword ptr [ecx]
		fstp     dword ptr [edx]

		fld      dword ptr [angleB]
		fsincos
		fstp     dword ptr [ecx+4]
		fstp     dword ptr [edx+4]

		fld      dword ptr [angleC]
		fsincos
		fstp     dword ptr [ecx+8]
		fstp     dword ptr [edx+8]
	}
}

MC_FORCEINLINE f32 __fastcall MC_Abs(f32 x)
{
	*((u32*)&x) &= 0x7fffffff;
	return x;
}

#endif//INCGUARD_MC_MATH_H

