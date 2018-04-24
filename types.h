#pragma once

#include <cstdint>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define U8_MAX 0xFF
#define U16_MAX 0xFFFF
#define U32_MAX 0xFFFFFFFF
#define U64_MAX 0xFFFFFFFFFFFFFFFF

#define F32_MIN 1.175494351e-38F
#define F32_MAX 3.402823466e+38F
#define F64_MIN 2.2250738585072014e-308
#define F64_MAX 1.7976931348623158e+308

#ifdef _WIN64
typedef unsigned __int64 mem_t;
#else
typedef unsigned int     mem_t;
#endif

typedef float f32;
typedef double f64;

struct f16
{
    f16(f32 f)
    {
        u32 inu = *((u32*)&f);
        u32 exp_mantissa;
        u32 sign_bit;
        u32 exp;

        exp_mantissa = inu & 0x7fffffff;
        sign_bit = inu & 0x80000000;
        exp = inu & 0x7f800000;

        exp_mantissa >>= 13;
        sign_bit >>= 16;

        exp_mantissa -= 0x1c000;

        exp_mantissa = (exp < 0x38800000) ? 0 : exp_mantissa;
        exp_mantissa = (exp > 0x47000000) ? 0x7bff : exp_mantissa;
        exp_mantissa = (exp == 0 ? 0 : exp_mantissa);

        exp_mantissa |= sign_bit;

        myData = exp_mantissa;
    }

    operator f32()
    {
        f32 Result = 0.0f;

        u32 exp_mantissa;
        u32 sign_bit;
        u32 exp;

        sign_bit = myData & 0x8000;
        exp_mantissa = myData & 0x7FFF;
        exp = myData & 0x7C00;

        exp_mantissa <<= 13;
        sign_bit <<= 16;

        exp_mantissa += 0x38000000;

        exp_mantissa = (exp == 0 ? 0 : exp_mantissa);

        exp_mantissa |= sign_bit;

        Result = *(f32*)&exp_mantissa;
        return Result;
    }

private:
    u16 myData;
};