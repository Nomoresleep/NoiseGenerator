#ifndef __zlgl_core_h__
#define __zlgl_core_h__ 1

/*
** This file is generated on the basis of the following public opengl headers
** published by the khronos group:
** 
** glcorearb.h
** wgl.h
** glxext.h
**
** additionally
*/


/*
** Copyright (c) 2013-2017 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif

#ifndef ZLGL_STRSTR
	static const char*
		ZLGL_StrStr(const char* Str, const char* SubStr)
	{
		//emptystring
		if (!*SubStr)
		{
			return Str;
		}
		const char* SubStrEnd = Str;
		const char* SubStrAt = SubStr;
		//get end of Substr
		while (*++SubStrAt)
		{
			SubStrEnd++;
		}
		const char* StrAt = Str;
		while (*SubStrEnd)
		{
			const char* CurrentSolution = StrAt;
			SubStrAt = SubStr;
			while (*StrAt && *SubStrAt && *StrAt == *SubStrAt)
			{
				StrAt++;
				SubStrAt++;
			}
			if (!*SubStrAt)
			{
				return(CurrentSolution);
			}
			StrAt = CurrentSolution + 1;
			SubStrEnd++;
		}
		return(0);
	}
#define ZLGL_STRSTR ZLGL_StrStr
#endif

#define ZLGL_DECLARE_OPENGL_FUNCTION(fun) extern PFN_zlgl_##fun fun

#ifndef ZLGL_IMPL
#define ZLGL_DEFINE_OPENGL_FUNCTION(fun) extern PFN_zlgl_##fun fun
#else
#define ZLGL_DEFINE_OPENGL_FUNCTION(fun) PFN_zlgl_##fun fun = 0
#endif

#define ZLGL_MAKE_VERSION(major, minor) ((int)major << 8 | (int)minor)
typedef enum ZLGL_opengl_version
{
	ZLGL_opengl_1_0 = ZLGL_MAKE_VERSION(1, 0),
	ZLGL_opengl_1_1 = ZLGL_MAKE_VERSION(1, 1),
	ZLGL_opengl_1_2 = ZLGL_MAKE_VERSION(1, 2),
	ZLGL_opengl_1_3 = ZLGL_MAKE_VERSION(1, 3),
	ZLGL_opengl_1_4 = ZLGL_MAKE_VERSION(1, 4),
	ZLGL_opengl_1_5 = ZLGL_MAKE_VERSION(1, 5),
	ZLGL_opengl_2_0 = ZLGL_MAKE_VERSION(2, 0),
	ZLGL_opengl_2_1 = ZLGL_MAKE_VERSION(2, 1),
	ZLGL_opengl_3_0 = ZLGL_MAKE_VERSION(3, 0),
	ZLGL_opengl_3_1 = ZLGL_MAKE_VERSION(3, 1),
	ZLGL_opengl_3_2 = ZLGL_MAKE_VERSION(3, 2),
	ZLGL_opengl_3_3 = ZLGL_MAKE_VERSION(3, 3),
	ZLGL_opengl_4_0 = ZLGL_MAKE_VERSION(4, 0),
	ZLGL_opengl_4_1 = ZLGL_MAKE_VERSION(4, 1),
	ZLGL_opengl_4_2 = ZLGL_MAKE_VERSION(4, 2),
	ZLGL_opengl_4_3 = ZLGL_MAKE_VERSION(4, 3),
	ZLGL_opengl_4_4 = ZLGL_MAKE_VERSION(4, 4),
	ZLGL_opengl_4_5 = ZLGL_MAKE_VERSION(4, 5)
}ZLGL_opengl_version;

void zlgl_LoadOpenGLFunctions(ZLGL_opengl_version Version);

void zlgl_LoadOpenGLExtensions();

typedef struct
{
	unsigned short DefFramebufferColorBits;
	unsigned short DefFramebufferAlphaBits;
	unsigned short DefFramebufferDepthBits;
	unsigned short DefFramebufferStencilBits;
	unsigned short DefFramebufferMultiSamples;

	int EnableVSync;
	int EnableDoubleBuffering;
	int DebugContext;
	int EnforceRequestedVersion;

} zlgl_OpenGLContextDescriptor;

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif




//
//Note: OpenGL Version 1.0
//
typedef void GLvoid;
typedef unsigned int GLenum;
typedef float GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef unsigned char GLubyte;


#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_FALSE                          0
#define GL_TRUE                           1
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308
#define GL_NONE                           0
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_CW                             0x0900
#define GL_CCW                            0x0901
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_FUNC                     0x0B74
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_VIEWPORT                       0x0BA2
#define GL_DITHER                         0x0BD0
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_DRAW_BUFFER                    0x0C01
#define GL_READ_BUFFER                    0x0C02
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_STEREO                         0x0C33
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F
#define GL_TEXTURE                        0x1702
#define GL_COLOR                          0x1800
#define GL_DEPTH                          0x1801
#define GL_STENCIL                        0x1802
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_REPEAT                         0x2901

typedef void (APIENTRYP PFN_zlgl_glCullFace)(GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glFrontFace)(GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glHint)(GLenum target, GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glLineWidth)(GLfloat width);
typedef void (APIENTRYP PFN_zlgl_glPointSize)(GLfloat size);
typedef void (APIENTRYP PFN_zlgl_glPolygonMode)(GLenum face, GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFN_zlgl_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glTexParameteri)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glDrawBuffer)(GLenum buf);
typedef void (APIENTRYP PFN_zlgl_glClear)(GLbitfield mask);
typedef void (APIENTRYP PFN_zlgl_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFN_zlgl_glClearStencil)(GLint s);
typedef void (APIENTRYP PFN_zlgl_glClearDepth)(GLdouble depth);
typedef void (APIENTRYP PFN_zlgl_glStencilMask)(GLuint mask);
typedef void (APIENTRYP PFN_zlgl_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFN_zlgl_glDepthMask)(GLboolean flag);
typedef void (APIENTRYP PFN_zlgl_glDisable)(GLenum cap);
typedef void (APIENTRYP PFN_zlgl_glEnable)(GLenum cap);
typedef void (APIENTRYP PFN_zlgl_glFinish)(void);
typedef void (APIENTRYP PFN_zlgl_glFlush)(void);
typedef void (APIENTRYP PFN_zlgl_glBlendFunc)(GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFN_zlgl_glLogicOp)(GLenum opcode);
typedef void (APIENTRYP PFN_zlgl_glStencilFunc)(GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFN_zlgl_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFN_zlgl_glDepthFunc)(GLenum func);
typedef void (APIENTRYP PFN_zlgl_glPixelStoref)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFN_zlgl_glPixelStorei)(GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glReadBuffer)(GLenum src);
typedef void (APIENTRYP PFN_zlgl_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFN_zlgl_glGetBooleanv)(GLenum pname, GLboolean *data);
typedef void (APIENTRYP PFN_zlgl_glGetDoublev)(GLenum pname, GLdouble *data);
typedef GLenum(APIENTRYP PFN_zlgl_glGetError)(void);
typedef void (APIENTRYP PFN_zlgl_glGetFloatv)(GLenum pname, GLfloat *data);
typedef void (APIENTRYP PFN_zlgl_glGetIntegerv)(GLenum pname, GLint *data);
typedef const GLubyte *(APIENTRYP PFN_zlgl_glGetString)(GLenum name);
typedef void (APIENTRYP PFN_zlgl_glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFN_zlgl_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsEnabled)(GLenum cap);
typedef void (APIENTRYP PFN_zlgl_glDepthRange)(GLdouble near, GLdouble far);
typedef void (APIENTRYP PFN_zlgl_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);

ZLGL_DEFINE_OPENGL_FUNCTION(glCullFace);
ZLGL_DEFINE_OPENGL_FUNCTION(glFrontFace);
ZLGL_DEFINE_OPENGL_FUNCTION(glHint);
ZLGL_DEFINE_OPENGL_FUNCTION(glLineWidth);
ZLGL_DEFINE_OPENGL_FUNCTION(glPointSize);
ZLGL_DEFINE_OPENGL_FUNCTION(glPolygonMode);
ZLGL_DEFINE_OPENGL_FUNCTION(glScissor);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexParameterf);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexParameteri);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexImage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexImage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glClear);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearColor);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearStencil);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearDepth);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilMask);
ZLGL_DEFINE_OPENGL_FUNCTION(glColorMask);
ZLGL_DEFINE_OPENGL_FUNCTION(glDepthMask);
ZLGL_DEFINE_OPENGL_FUNCTION(glDisable);
ZLGL_DEFINE_OPENGL_FUNCTION(glEnable);
ZLGL_DEFINE_OPENGL_FUNCTION(glFinish);
ZLGL_DEFINE_OPENGL_FUNCTION(glFlush);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendFunc);
ZLGL_DEFINE_OPENGL_FUNCTION(glLogicOp);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilFunc);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilOp);
ZLGL_DEFINE_OPENGL_FUNCTION(glDepthFunc);
ZLGL_DEFINE_OPENGL_FUNCTION(glPixelStoref);
ZLGL_DEFINE_OPENGL_FUNCTION(glPixelStorei);
ZLGL_DEFINE_OPENGL_FUNCTION(glReadBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glReadPixels);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetBooleanv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetDoublev);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetError);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFloatv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetIntegerv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetString);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTexImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTexParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTexParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTexLevelParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTexLevelParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsEnabled);
ZLGL_DEFINE_OPENGL_FUNCTION(glDepthRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glViewport);

//
//Note: OpenGL Version 1.1
//

typedef float GLclampf;
typedef double GLclampd;

#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_FILL            0x8037
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_DOUBLE                         0x140A
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_VERTEX_ARRAY                   0x8074

typedef void (APIENTRYP PFN_zlgl_glDrawArrays)(GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFN_zlgl_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFN_zlgl_glGetPointerv)(GLenum pname, void **params);
typedef void (APIENTRYP PFN_zlgl_glPolygonOffset)(GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFN_zlgl_glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFN_zlgl_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFN_zlgl_glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFN_zlgl_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glBindTexture)(GLenum target, GLuint texture);
typedef void (APIENTRYP PFN_zlgl_glDeleteTextures)(GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFN_zlgl_glGenTextures)(GLsizei n, GLuint *textures);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsTexture)(GLuint texture);

ZLGL_DEFINE_OPENGL_FUNCTION(glDrawArrays);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawElements);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPointerv);
ZLGL_DEFINE_OPENGL_FUNCTION(glPolygonOffset);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTexImage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTexImage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTexSubImage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTexSubImage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexSubImage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexSubImage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindTexture);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteTextures);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenTextures);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsTexture);


//
//Note: OpenGL Version 1.2
//
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E

typedef void (APIENTRYP PFN_zlgl_glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFN_zlgl_glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

ZLGL_DEFINE_OPENGL_FUNCTION(glDrawRangeElements);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexImage3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexSubImage3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTexSubImage3D);

//
//Note: OpenGL Version 1.3
//

#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D

typedef void (APIENTRYP PFN_zlgl_glActiveTexture)(GLenum texture);
typedef void (APIENTRYP PFN_zlgl_glSampleCoverage)(GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFN_zlgl_glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFN_zlgl_glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFN_zlgl_glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFN_zlgl_glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFN_zlgl_glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFN_zlgl_glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFN_zlgl_glGetCompressedTexImage)(GLenum target, GLint level, void *img);

ZLGL_DEFINE_OPENGL_FUNCTION(glActiveTexture);
ZLGL_DEFINE_OPENGL_FUNCTION(glSampleCoverage);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTexImage3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTexImage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTexImage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTexSubImage3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTexSubImage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTexSubImage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetCompressedTexImage);


//
//Note: OpenGL Version 1.4
//

#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_FUNC_ADD                       0x8006
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004

typedef void (APIENTRYP PFN_zlgl_glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFN_zlgl_glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (APIENTRYP PFN_zlgl_glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (APIENTRYP PFN_zlgl_glPointParameterf)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFN_zlgl_glPointParameterfv)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glPointParameteri)(GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glPointParameteriv)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFN_zlgl_glBlendEquation)(GLenum mode);

ZLGL_DEFINE_OPENGL_FUNCTION(glBlendFuncSeparate);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawArrays);
ZLGL_DEFINE_OPENGL_FUNCTION(glPointParameterf);
ZLGL_DEFINE_OPENGL_FUNCTION(glPointParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glPointParameteri);
ZLGL_DEFINE_OPENGL_FUNCTION(glPointParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendColor);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendEquation);


//
//Note: OpenGL Version 1.5
//
#include <stddef.h>
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;

#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_SRC1_ALPHA                     0x8589

typedef void (APIENTRYP PFN_zlgl_glGenQueries)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFN_zlgl_glDeleteQueries)(GLsizei n, const GLuint *ids);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsQuery)(GLuint id);
typedef void (APIENTRYP PFN_zlgl_glBeginQuery)(GLenum target, GLuint id);
typedef void (APIENTRYP PFN_zlgl_glEndQuery)(GLenum target);
typedef void (APIENTRYP PFN_zlgl_glGetQueryiv)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glBindBuffer)(GLenum target, GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glDeleteBuffers)(GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFN_zlgl_glGenBuffers)(GLsizei n, GLuint *buffers);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsBuffer)(GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFN_zlgl_glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFN_zlgl_glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void *(APIENTRYP PFN_zlgl_glMapBuffer)(GLenum target, GLenum access);
typedef GLboolean(APIENTRYP PFN_zlgl_glUnmapBuffer)(GLenum target);
typedef void (APIENTRYP PFN_zlgl_glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetBufferPointerv)(GLenum target, GLenum pname, void **params);

ZLGL_DEFINE_OPENGL_FUNCTION(glGenQueries);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteQueries);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsQuery);
ZLGL_DEFINE_OPENGL_FUNCTION(glBeginQuery);
ZLGL_DEFINE_OPENGL_FUNCTION(glEndQuery);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryObjectiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryObjectuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteBuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenBuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glBufferData);
ZLGL_DEFINE_OPENGL_FUNCTION(glBufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetBufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glMapBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glUnmapBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetBufferParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetBufferPointerv);


//Note: Opengl Version 2.0
typedef char GLchar;
typedef short GLshort;
typedef signed char GLbyte;
typedef unsigned short GLushort;
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5

typedef void (APIENTRYP PFN_zlgl_glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFN_zlgl_glDrawBuffers)(GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFN_zlgl_glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFN_zlgl_glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFN_zlgl_glStencilMaskSeparate)(GLenum face, GLuint mask);
typedef void (APIENTRYP PFN_zlgl_glAttachShader)(GLuint program, GLuint shader);
typedef void (APIENTRYP PFN_zlgl_glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glCompileShader)(GLuint shader);
typedef GLuint(APIENTRYP PFN_zlgl_glCreateProgram)(void);
typedef GLuint(APIENTRYP PFN_zlgl_glCreateShader)(GLenum type);
typedef void (APIENTRYP PFN_zlgl_glDeleteProgram)(GLuint program);
typedef void (APIENTRYP PFN_zlgl_glDeleteShader)(GLuint shader);
typedef void (APIENTRYP PFN_zlgl_glDetachShader)(GLuint program, GLuint shader);
typedef void (APIENTRYP PFN_zlgl_glDisableVertexAttribArray)(GLuint index);
typedef void (APIENTRYP PFN_zlgl_glEnableVertexAttribArray)(GLuint index);
typedef void (APIENTRYP PFN_zlgl_glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint(APIENTRYP PFN_zlgl_glGetAttribLocation)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFN_zlgl_glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFN_zlgl_glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef GLint(APIENTRYP PFN_zlgl_glGetUniformLocation)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGetUniformfv)(GLuint program, GLint location, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetUniformiv)(GLuint program, GLint location, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsProgram)(GLuint program);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsShader)(GLuint shader);
typedef void (APIENTRYP PFN_zlgl_glLinkProgram)(GLuint program);
typedef void (APIENTRYP PFN_zlgl_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (APIENTRYP PFN_zlgl_glUseProgram)(GLuint program);
typedef void (APIENTRYP PFN_zlgl_glUniform1f)(GLint location, GLfloat v0);
typedef void (APIENTRYP PFN_zlgl_glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFN_zlgl_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFN_zlgl_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFN_zlgl_glUniform1i)(GLint location, GLint v0);
typedef void (APIENTRYP PFN_zlgl_glUniform2i)(GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFN_zlgl_glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFN_zlgl_glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFN_zlgl_glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniform1iv)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glUniform2iv)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glUniform3iv)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glUniform4iv)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glValidateProgram)(GLuint program);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib1d)(GLuint index, GLdouble x);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib1dv)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib1f)(GLuint index, GLfloat x);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib1fv)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib1s)(GLuint index, GLshort x);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib1sv)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib2dv)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib2fv)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib2sv)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib3dv)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib3fv)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib3sv)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4Niv)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4Nubv)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4Nusv)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4bv)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4dv)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4fv)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4iv)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4sv)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4uiv)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttrib4usv)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

ZLGL_DEFINE_OPENGL_FUNCTION(glBlendEquationSeparate);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawBuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilOpSeparate);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilFuncSeparate);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilMaskSeparate);
ZLGL_DEFINE_OPENGL_FUNCTION(glAttachShader);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindAttribLocation);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompileShader);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateProgram);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateShader);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteProgram);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteShader); 
ZLGL_DEFINE_OPENGL_FUNCTION(glDetachShader);
ZLGL_DEFINE_OPENGL_FUNCTION(glDisableVertexAttribArray);
ZLGL_DEFINE_OPENGL_FUNCTION(glEnableVertexAttribArray);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveAttrib);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveUniform);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetAttachedShaders); 
ZLGL_DEFINE_OPENGL_FUNCTION(glGetAttribLocation);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramInfoLog);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetShaderiv); 
ZLGL_DEFINE_OPENGL_FUNCTION(glGetShaderInfoLog);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetShaderSource);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformLocation);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribdv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribPointerv);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsProgram);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsShader);
ZLGL_DEFINE_OPENGL_FUNCTION(glLinkProgram);
ZLGL_DEFINE_OPENGL_FUNCTION(glShaderSource);
ZLGL_DEFINE_OPENGL_FUNCTION(glUseProgram);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1f);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2f);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3f);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4f);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1i);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2i);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3i);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4i);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix2fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix3fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix4fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glValidateProgram);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib1d);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib1dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib1f);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib1fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib1s);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib1sv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib2d);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib2f);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib2fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib2s);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib2sv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib3d);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib3f);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib3fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib3s);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib3sv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4Nbv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4Niv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4Nsv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4Nub);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4Nubv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4Nuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4Nusv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4bv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4d);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4f);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4s);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4sv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4ubv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttrib4usv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribPointer);




//
// Note: OpenGL Version 2.1
//
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix2x3fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix3x2fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix2x4fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix4x2fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix3x4fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix4x3fv);



//
//Note: OpenGL Version 3.0
//

typedef unsigned short GLhalf;
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
#define GL_DEPTH_COMPONENT32F             0x8CAC
#define GL_DEPTH32F_STENCIL8              0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT            0x8218
#define GL_FRAMEBUFFER_UNDEFINED          0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#define GL_MAX_RENDERBUFFER_SIZE          0x84E8
#define GL_DEPTH_STENCIL                  0x84F9
#define GL_UNSIGNED_INT_24_8              0x84FA
#define GL_DEPTH24_STENCIL8               0x88F0
#define GL_TEXTURE_STENCIL_SIZE           0x88F1
#define GL_TEXTURE_RED_TYPE               0x8C10
#define GL_TEXTURE_GREEN_TYPE             0x8C11
#define GL_TEXTURE_BLUE_TYPE              0x8C12
#define GL_TEXTURE_ALPHA_TYPE             0x8C13
#define GL_TEXTURE_DEPTH_TYPE             0x8C16
#define GL_UNSIGNED_NORMALIZED            0x8C17
#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_COLOR_ATTACHMENT16             0x8CF0
#define GL_COLOR_ATTACHMENT17             0x8CF1
#define GL_COLOR_ATTACHMENT18             0x8CF2
#define GL_COLOR_ATTACHMENT19             0x8CF3
#define GL_COLOR_ATTACHMENT20             0x8CF4
#define GL_COLOR_ATTACHMENT21             0x8CF5
#define GL_COLOR_ATTACHMENT22             0x8CF6
#define GL_COLOR_ATTACHMENT23             0x8CF7
#define GL_COLOR_ATTACHMENT24             0x8CF8
#define GL_COLOR_ATTACHMENT25             0x8CF9
#define GL_COLOR_ATTACHMENT26             0x8CFA
#define GL_COLOR_ATTACHMENT27             0x8CFB
#define GL_COLOR_ATTACHMENT28             0x8CFC
#define GL_COLOR_ATTACHMENT29             0x8CFD
#define GL_COLOR_ATTACHMENT30             0x8CFE
#define GL_COLOR_ATTACHMENT31             0x8CFF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_HALF_FLOAT                     0x140B
#define GL_MAP_READ_BIT                   0x0001
#define GL_MAP_WRITE_BIT                  0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT       0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT      0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT         0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT         0x0020
#define GL_COMPRESSED_RED_RGTC1           0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1    0x8DBC
#define GL_COMPRESSED_RG_RGTC2            0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2     0x8DBE
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_VERTEX_ARRAY_BINDING           0x85B5
typedef void (APIENTRYP PFN_zlgl_glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFN_zlgl_glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFN_zlgl_glGetIntegeri_v)(GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFN_zlgl_glEnablei)(GLenum target, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glDisablei)(GLenum target, GLuint index);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsEnabledi)(GLenum target, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glBeginTransformFeedback)(GLenum primitiveMode);
typedef void (APIENTRYP PFN_zlgl_glEndTransformFeedback)(void);
typedef void (APIENTRYP PFN_zlgl_glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFN_zlgl_glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void (APIENTRYP PFN_zlgl_glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glClampColor)(GLenum target, GLenum clamp);
typedef void (APIENTRYP PFN_zlgl_glBeginConditionalRender)(GLuint id, GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glEndConditionalRender)(void);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI1i)(GLuint index, GLint x);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI2i)(GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI1ui)(GLuint index, GLuint x);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI1iv)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI2iv)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI3iv)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI4iv)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI1uiv)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI2uiv)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI3uiv)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI4uiv)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI4bv)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI4sv)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI4ubv)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribI4usv)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFN_zlgl_glGetUniformuiv)(GLuint program, GLint location, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name);
typedef GLint(APIENTRYP PFN_zlgl_glGetFragDataLocation)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glUniform1ui)(GLint location, GLuint v0);
typedef void (APIENTRYP PFN_zlgl_glUniform2ui)(GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFN_zlgl_glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFN_zlgl_glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFN_zlgl_glUniform1uiv)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glUniform2uiv)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glUniform3uiv)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glUniform4uiv)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte *(APIENTRYP PFN_zlgl_glGetStringi)(GLenum name, GLuint index);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsRenderbuffer)(GLuint renderbuffer);
typedef void (APIENTRYP PFN_zlgl_glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFN_zlgl_glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
typedef void (APIENTRYP PFN_zlgl_glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFN_zlgl_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsFramebuffer)(GLuint framebuffer);
typedef void (APIENTRYP PFN_zlgl_glBindFramebuffer)(GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFN_zlgl_glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
typedef void (APIENTRYP PFN_zlgl_glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
typedef GLenum(APIENTRYP PFN_zlgl_glCheckFramebufferStatus)(GLenum target);
typedef void (APIENTRYP PFN_zlgl_glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFN_zlgl_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFN_zlgl_glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFN_zlgl_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFN_zlgl_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGenerateMipmap)(GLenum target);
typedef void (APIENTRYP PFN_zlgl_glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFN_zlgl_glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void *(APIENTRYP PFN_zlgl_glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFN_zlgl_glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFN_zlgl_glBindVertexArray)(GLuint array);
typedef void (APIENTRYP PFN_zlgl_glDeleteVertexArrays)(GLsizei n, const GLuint *arrays);
typedef void (APIENTRYP PFN_zlgl_glGenVertexArrays)(GLsizei n, GLuint *arrays);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsVertexArray)(GLuint array);

ZLGL_DEFINE_OPENGL_FUNCTION(glColorMaski);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetBooleani_v);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetIntegeri_v); 
ZLGL_DEFINE_OPENGL_FUNCTION(glEnablei); 
ZLGL_DEFINE_OPENGL_FUNCTION(glDisablei);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsEnabledi);
ZLGL_DEFINE_OPENGL_FUNCTION(glBeginTransformFeedback);
ZLGL_DEFINE_OPENGL_FUNCTION(glEndTransformFeedback); 
ZLGL_DEFINE_OPENGL_FUNCTION(glBindBufferRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindBufferBase);
ZLGL_DEFINE_OPENGL_FUNCTION(glTransformFeedbackVaryings);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTransformFeedbackVarying);
ZLGL_DEFINE_OPENGL_FUNCTION(glClampColor);
ZLGL_DEFINE_OPENGL_FUNCTION(glBeginConditionalRender);
ZLGL_DEFINE_OPENGL_FUNCTION(glEndConditionalRender);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribIPointer);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribIiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribIuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI1i);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI2i);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI3i);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI4i);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI1ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI2ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI3ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI4ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI1iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI2iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI3iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI4iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI1uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI2uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI3uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI4uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI4bv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI4sv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI4ubv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribI4usv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindFragDataLocation);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFragDataLocation);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexParameterIiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexParameterIuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTexParameterIiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTexParameterIuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearBufferiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearBufferuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearBufferfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearBufferfi);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetStringi);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsRenderbuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindRenderbuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteRenderbuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenRenderbuffers); 
ZLGL_DEFINE_OPENGL_FUNCTION(glRenderbufferStorage);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetRenderbufferParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsFramebuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindFramebuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteFramebuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenFramebuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glCheckFramebufferStatus);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferTexture1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferTexture2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferTexture3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferRenderbuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFramebufferAttachmentParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenerateMipmap);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlitFramebuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glRenderbufferStorageMultisample);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferTextureLayer);
ZLGL_DEFINE_OPENGL_FUNCTION(glMapBufferRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glFlushMappedBufferRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindVertexArray);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteVertexArrays);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenVertexArrays);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsVertexArray);



//
//Note: OpenGL Version 3.1
//
#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu
typedef void (APIENTRYP PFN_zlgl_glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (APIENTRYP PFN_zlgl_glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void (APIENTRYP PFN_zlgl_glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glPrimitiveRestartIndex)(GLuint index);
typedef void (APIENTRYP PFN_zlgl_glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFN_zlgl_glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
typedef void (APIENTRYP PFN_zlgl_glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
typedef GLuint(APIENTRYP PFN_zlgl_glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName);
typedef void (APIENTRYP PFN_zlgl_glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
typedef void (APIENTRYP PFN_zlgl_glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

ZLGL_DEFINE_OPENGL_FUNCTION(glDrawArraysInstanced);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawElementsInstanced);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glPrimitiveRestartIndex);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyBufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformIndices);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveUniformsiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveUniformName);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformBlockIndex);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveUniformBlockiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveUniformBlockName);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformBlockBinding);



//
//Note: OpenGL Version 3.2
//
	typedef struct __GLsync *GLsync;
#ifndef GLEXT_64_TYPES_DEFINED
	/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
	/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
	/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
	typedef long int int64_t;
	typedef unsigned long int uint64_t;
#else
	typedef long long int int64_t;
	typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
	typedef long int int32_t;
	typedef long long int int64_t;
	typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
	typedef __int32 int32_t;
	typedef __int64 int64_t;
	typedef unsigned __int64 uint64_t;
#else
	/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
typedef uint64_t GLuint64;
typedef int64_t GLint64;

#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
#define GL_DEPTH_CLAMP                    0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION        0x8E4D
#define GL_LAST_VERTEX_CONVENTION         0x8E4E
#define GL_PROVOKING_VERTEX               0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS      0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT        0x9111
#define GL_OBJECT_TYPE                    0x9112
#define GL_SYNC_CONDITION                 0x9113
#define GL_SYNC_STATUS                    0x9114
#define GL_SYNC_FLAGS                     0x9115
#define GL_SYNC_FENCE                     0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE     0x9117
#define GL_UNSIGNALED                     0x9118
#define GL_SIGNALED                       0x9119
#define GL_ALREADY_SIGNALED               0x911A
#define GL_TIMEOUT_EXPIRED                0x911B
#define GL_CONDITION_SATISFIED            0x911C
#define GL_WAIT_FAILED                    0x911D
#define GL_TIMEOUT_IGNORED                0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT        0x00000001
#define GL_SAMPLE_POSITION                0x8E50
#define GL_SAMPLE_MASK                    0x8E51
#define GL_SAMPLE_MASK_VALUE              0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS          0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110

typedef void (APIENTRYP PFN_zlgl_glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFN_zlgl_glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFN_zlgl_glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void (APIENTRYP PFN_zlgl_glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
typedef void (APIENTRYP PFN_zlgl_glProvokingVertex)(GLenum mode);
typedef GLsync(APIENTRYP PFN_zlgl_glFenceSync)(GLenum condition, GLbitfield flags);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsSync)(GLsync sync);
typedef void (APIENTRYP PFN_zlgl_glDeleteSync)(GLsync sync);
typedef GLenum(APIENTRYP PFN_zlgl_glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFN_zlgl_glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFN_zlgl_glGetInteger64v)(GLenum pname, GLint64 *data);
typedef void (APIENTRYP PFN_zlgl_glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
typedef void (APIENTRYP PFN_zlgl_glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data);
typedef void (APIENTRYP PFN_zlgl_glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFN_zlgl_glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFN_zlgl_glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFN_zlgl_glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFN_zlgl_glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val);
typedef void (APIENTRYP PFN_zlgl_glSampleMaski)(GLuint maskNumber, GLbitfield mask);

ZLGL_DEFINE_OPENGL_FUNCTION(glDrawElementsBaseVertex);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawRangeElementsBaseVertex);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawElementsInstancedBaseVertex);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawElementsBaseVertex);
ZLGL_DEFINE_OPENGL_FUNCTION(glProvokingVertex);
ZLGL_DEFINE_OPENGL_FUNCTION(glFenceSync);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsSync);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteSync);
ZLGL_DEFINE_OPENGL_FUNCTION(glClientWaitSync);
ZLGL_DEFINE_OPENGL_FUNCTION(glWaitSync);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetInteger64v);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetSynciv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetInteger64i_v);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetBufferParameteri64v);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferTexture);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexImage2DMultisample); 
ZLGL_DEFINE_OPENGL_FUNCTION(glTexImage3DMultisample);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultisamplefv);
ZLGL_DEFINE_OPENGL_FUNCTION(glSampleMaski);

//
//Note: OpenGL Version 3.3
//
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
#define GL_SRC1_COLOR                     0x88F9
#define GL_ONE_MINUS_SRC1_COLOR           0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA           0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS   0x88FC
#define GL_ANY_SAMPLES_PASSED             0x8C2F
#define GL_SAMPLER_BINDING                0x8919
#define GL_RGB10_A2UI                     0x906F
#define GL_TEXTURE_SWIZZLE_R              0x8E42
#define GL_TEXTURE_SWIZZLE_G              0x8E43
#define GL_TEXTURE_SWIZZLE_B              0x8E44
#define GL_TEXTURE_SWIZZLE_A              0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA           0x8E46
#define GL_TIME_ELAPSED                   0x88BF
#define GL_TIMESTAMP                      0x8E28
#define GL_INT_2_10_10_10_REV             0x8D9F

typedef void (APIENTRYP PFN_zlgl_glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
typedef GLint(APIENTRYP PFN_zlgl_glGetFragDataIndex)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGenSamplers)(GLsizei count, GLuint *samplers);
typedef void (APIENTRYP PFN_zlgl_glDeleteSamplers)(GLsizei count, const GLuint *samplers);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsSampler)(GLuint sampler);
typedef void (APIENTRYP PFN_zlgl_glBindSampler)(GLuint unit, GLuint sampler);
typedef void (APIENTRYP PFN_zlgl_glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFN_zlgl_glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFN_zlgl_glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFN_zlgl_glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFN_zlgl_glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param);
typedef void (APIENTRYP PFN_zlgl_glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glQueryCounter)(GLuint id, GLenum target);
typedef void (APIENTRYP PFN_zlgl_glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFN_zlgl_glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribDivisor)(GLuint index, GLuint divisor);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);

ZLGL_DEFINE_OPENGL_FUNCTION(glBindFragDataLocationIndexed);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFragDataIndex);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenSamplers);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteSamplers);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsSampler);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindSampler);
ZLGL_DEFINE_OPENGL_FUNCTION(glSamplerParameteri);
ZLGL_DEFINE_OPENGL_FUNCTION(glSamplerParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glSamplerParameterf);
ZLGL_DEFINE_OPENGL_FUNCTION(glSamplerParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glSamplerParameterIiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glSamplerParameterIuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetSamplerParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetSamplerParameterIiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetSamplerParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetSamplerParameterIuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glQueryCounter);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryObjecti64v);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryObjectui64v);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribDivisor);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribP1ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribP1uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribP2ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribP2uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribP3ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribP3uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribP4ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribP4uiv);


//
//Note: OpenGL Version 4.0
//
#define GL_SAMPLE_SHADING                 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE       0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY         0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY   0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY         0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW  0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY     0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER           0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING   0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS    0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS             0x8E71
#define GL_DOUBLE_VEC2                    0x8FFC
#define GL_DOUBLE_VEC3                    0x8FFD
#define GL_DOUBLE_VEC4                    0x8FFE
#define GL_DOUBLE_MAT2                    0x8F46
#define GL_DOUBLE_MAT3                    0x8F47
#define GL_DOUBLE_MAT4                    0x8F48
#define GL_DOUBLE_MAT2x3                  0x8F49
#define GL_DOUBLE_MAT2x4                  0x8F4A
#define GL_DOUBLE_MAT3x2                  0x8F4B
#define GL_DOUBLE_MAT3x4                  0x8F4C
#define GL_DOUBLE_MAT4x2                  0x8F4D
#define GL_DOUBLE_MAT4x3                  0x8F4E
#define GL_ACTIVE_SUBROUTINES             0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS     0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH   0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES                0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES     0x8E4A
#define GL_COMPATIBLE_SUBROUTINES         0x8E4B
#define GL_PATCHES                        0x000E
#define GL_PATCH_VERTICES                 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL      0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL      0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES   0x8E75
#define GL_TESS_GEN_MODE                  0x8E76
#define GL_TESS_GEN_SPACING               0x8E77
#define GL_TESS_GEN_VERTEX_ORDER          0x8E78
#define GL_TESS_GEN_POINT_MODE            0x8E79
#define GL_ISOLINES                       0x8E7A
#define GL_FRACTIONAL_ODD                 0x8E7B
#define GL_FRACTIONAL_EVEN                0x8E7C
#define GL_MAX_PATCH_VERTICES             0x8E7D
#define GL_MAX_TESS_GEN_LEVEL             0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS      0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER         0x8E87
#define GL_TESS_CONTROL_SHADER            0x8E88
#define GL_TRANSFORM_FEEDBACK             0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING     0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70

typedef void (APIENTRYP PFN_zlgl_glMinSampleShading)(GLfloat value);
typedef void (APIENTRYP PFN_zlgl_glBlendEquationi)(GLuint buf, GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFN_zlgl_glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFN_zlgl_glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (APIENTRYP PFN_zlgl_glDrawArraysIndirect)(GLenum mode, const void *indirect);
typedef void (APIENTRYP PFN_zlgl_glDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect);
typedef void (APIENTRYP PFN_zlgl_glUniform1d)(GLint location, GLdouble x);
typedef void (APIENTRYP PFN_zlgl_glUniform2d)(GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFN_zlgl_glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFN_zlgl_glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFN_zlgl_glUniform1dv)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniform2dv)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniform3dv)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniform4dv)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glGetUniformdv)(GLuint program, GLint location, GLdouble *params);
typedef GLint(APIENTRYP PFN_zlgl_glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar *name);
typedef GLuint(APIENTRYP PFN_zlgl_glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
typedef void (APIENTRYP PFN_zlgl_glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint *indices);
typedef void (APIENTRYP PFN_zlgl_glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
typedef void (APIENTRYP PFN_zlgl_glPatchParameteri)(GLenum pname, GLint value);
typedef void (APIENTRYP PFN_zlgl_glPatchParameterfv)(GLenum pname, const GLfloat *values);
typedef void (APIENTRYP PFN_zlgl_glBindTransformFeedback)(GLenum target, GLuint id);
typedef void (APIENTRYP PFN_zlgl_glDeleteTransformFeedbacks)(GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFN_zlgl_glGenTransformFeedbacks)(GLsizei n, GLuint *ids);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsTransformFeedback)(GLuint id);
typedef void (APIENTRYP PFN_zlgl_glPauseTransformFeedback)(void);
typedef void (APIENTRYP PFN_zlgl_glResumeTransformFeedback)(void);
typedef void (APIENTRYP PFN_zlgl_glDrawTransformFeedback)(GLenum mode, GLuint id);
typedef void (APIENTRYP PFN_zlgl_glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
typedef void (APIENTRYP PFN_zlgl_glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
typedef void (APIENTRYP PFN_zlgl_glEndQueryIndexed)(GLenum target, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint *params);

ZLGL_DEFINE_OPENGL_FUNCTION(glMinSampleShading);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendEquationi);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendEquationSeparatei);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendFunci);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendFuncSeparatei); 
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawArraysIndirect);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawElementsIndirect); 
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1d);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2d);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3d);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4d);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1dv); 
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix2x3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix3x2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix2x4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix3x4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix4x3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformMatrix4x2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformdv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetSubroutineUniformLocation);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetSubroutineIndex);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveSubroutineUniformiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveSubroutineUniformName);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveSubroutineName);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformSubroutinesuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformSubroutineuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramStageiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glPatchParameteri);
ZLGL_DEFINE_OPENGL_FUNCTION(glPatchParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindTransformFeedback);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteTransformFeedbacks);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenTransformFeedbacks);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsTransformFeedback);
ZLGL_DEFINE_OPENGL_FUNCTION(glPauseTransformFeedback);
ZLGL_DEFINE_OPENGL_FUNCTION(glResumeTransformFeedback);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawTransformFeedback);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawTransformFeedbackStream);
ZLGL_DEFINE_OPENGL_FUNCTION(glBeginQueryIndexed);
ZLGL_DEFINE_OPENGL_FUNCTION(glEndQueryIndexed);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryIndexediv);



//
//Note: OpenGL Version 4.1
//

#define GL_FIXED                          0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT                      0x8DF0
#define GL_MEDIUM_FLOAT                   0x8DF1
#define GL_HIGH_FLOAT                     0x8DF2
#define GL_LOW_INT                        0x8DF3
#define GL_MEDIUM_INT                     0x8DF4
#define GL_HIGH_INT                       0x8DF5
#define GL_SHADER_COMPILER                0x8DFA
#define GL_SHADER_BINARY_FORMATS          0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS      0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS     0x8DFB
#define GL_MAX_VARYING_VECTORS            0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS   0x8DFD
#define GL_RGB565                         0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH          0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS     0x87FE
#define GL_PROGRAM_BINARY_FORMATS         0x87FF
#define GL_VERTEX_SHADER_BIT              0x00000001
#define GL_FRAGMENT_SHADER_BIT            0x00000002
#define GL_GEOMETRY_SHADER_BIT            0x00000004
#define GL_TESS_CONTROL_SHADER_BIT        0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT     0x00000010
#define GL_ALL_SHADER_BITS                0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE              0x8258
#define GL_ACTIVE_PROGRAM                 0x8259
#define GL_PROGRAM_PIPELINE_BINDING       0x825A
#define GL_MAX_VIEWPORTS                  0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS         0x825C
#define GL_VIEWPORT_BOUNDS_RANGE          0x825D
#define GL_LAYER_PROVOKING_VERTEX         0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX               0x8260

typedef void (APIENTRYP PFN_zlgl_glReleaseShaderCompiler)(void);
typedef void (APIENTRYP PFN_zlgl_glShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFN_zlgl_glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (APIENTRYP PFN_zlgl_glDepthRangef)(GLfloat n, GLfloat f);
typedef void (APIENTRYP PFN_zlgl_glClearDepthf)(GLfloat d);
typedef void (APIENTRYP PFN_zlgl_glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void (APIENTRYP PFN_zlgl_glProgramBinary)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFN_zlgl_glProgramParameteri)(GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFN_zlgl_glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFN_zlgl_glActiveShaderProgram)(GLuint pipeline, GLuint program);
typedef GLuint(APIENTRYP PFN_zlgl_glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const*strings);
typedef void (APIENTRYP PFN_zlgl_glBindProgramPipeline)(GLuint pipeline);
typedef void (APIENTRYP PFN_zlgl_glDeleteProgramPipelines)(GLsizei n, const GLuint *pipelines);
typedef void (APIENTRYP PFN_zlgl_glGenProgramPipelines)(GLsizei n, GLuint *pipelines);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsProgramPipeline)(GLuint pipeline);
typedef void (APIENTRYP PFN_zlgl_glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1i)(GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glValidateProgramPipeline)(GLuint pipeline);
typedef void (APIENTRYP PFN_zlgl_glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL1d)(GLuint index, GLdouble x);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL1dv)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL2dv)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL3dv)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL4dv)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFN_zlgl_glViewportArrayv)(GLuint first, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFN_zlgl_glViewportIndexedfv)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glScissorArrayv)(GLuint first, GLsizei count, const GLint *v);
typedef void (APIENTRYP PFN_zlgl_glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glScissorIndexedv)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFN_zlgl_glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFN_zlgl_glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFN_zlgl_glGetFloati_v)(GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFN_zlgl_glGetDoublei_v)(GLenum target, GLuint index, GLdouble *data);

ZLGL_DEFINE_OPENGL_FUNCTION(glReleaseShaderCompiler);
ZLGL_DEFINE_OPENGL_FUNCTION(glShaderBinary);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetShaderPrecisionFormat);
ZLGL_DEFINE_OPENGL_FUNCTION(glDepthRangef);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearDepthf);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramBinary);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramParameteri);
ZLGL_DEFINE_OPENGL_FUNCTION(glUseProgramStages);
ZLGL_DEFINE_OPENGL_FUNCTION(glActiveShaderProgram);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateShaderProgramv);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindProgramPipeline);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteProgramPipelines);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenProgramPipelines);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsProgramPipeline);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramPipelineiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1i);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1f);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1d);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2i);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2f);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2d);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3i);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3f);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3d);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4i);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4f);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4d);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4ui);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4uiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2x3fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3x2fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2x4fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4x2fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3x4fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4x3fv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2x3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3x2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2x4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4x2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3x4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4x3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glValidateProgramPipeline);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramPipelineInfoLog);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL1d);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL2d);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL3d);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL4d);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL1dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL2dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL3dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL4dv);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribLPointer);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribLdv);
ZLGL_DEFINE_OPENGL_FUNCTION(glViewportArrayv);
ZLGL_DEFINE_OPENGL_FUNCTION(glViewportIndexedf);
ZLGL_DEFINE_OPENGL_FUNCTION(glViewportIndexedfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glScissorArrayv);
ZLGL_DEFINE_OPENGL_FUNCTION(glScissorIndexed);
ZLGL_DEFINE_OPENGL_FUNCTION(glScissorIndexedv);
ZLGL_DEFINE_OPENGL_FUNCTION(glDepthRangeArrayv);
ZLGL_DEFINE_OPENGL_FUNCTION(glDepthRangeIndexed);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFloati_v);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetDoublei_v);

//
//Note: OpenGL Version 4.2
//
#define GL_COPY_READ_BUFFER_BINDING       0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE      0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED      0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH  0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH  0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE   0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH    0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT   0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH    0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE     0x912E
#define GL_NUM_SAMPLE_COUNTS              0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT       0x90BC
#define GL_ATOMIC_COUNTER_BUFFER          0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING  0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START    0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE     0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS     0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS   0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS   0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS   0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS  0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER    0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT      0x00000002
#define GL_UNIFORM_BARRIER_BIT            0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT      0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT            0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT       0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT     0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT      0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT        0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT     0x00001000
#define GL_ALL_BARRIER_BITS               0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME             0x8F3A
#define GL_IMAGE_BINDING_LEVEL            0x8F3B
#define GL_IMAGE_BINDING_LAYERED          0x8F3C
#define GL_IMAGE_BINDING_LAYER            0x8F3D
#define GL_IMAGE_BINDING_ACCESS           0x8F3E
#define GL_IMAGE_1D                       0x904C
#define GL_IMAGE_2D                       0x904D
#define GL_IMAGE_3D                       0x904E
#define GL_IMAGE_2D_RECT                  0x904F
#define GL_IMAGE_CUBE                     0x9050
#define GL_IMAGE_BUFFER                   0x9051
#define GL_IMAGE_1D_ARRAY                 0x9052
#define GL_IMAGE_2D_ARRAY                 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY           0x9054
#define GL_IMAGE_2D_MULTISAMPLE           0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY     0x9056
#define GL_INT_IMAGE_1D                   0x9057
#define GL_INT_IMAGE_2D                   0x9058
#define GL_INT_IMAGE_3D                   0x9059
#define GL_INT_IMAGE_2D_RECT              0x905A
#define GL_INT_IMAGE_CUBE                 0x905B
#define GL_INT_IMAGE_BUFFER               0x905C
#define GL_INT_IMAGE_1D_ARRAY             0x905D
#define GL_INT_IMAGE_2D_ARRAY             0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY       0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE       0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D          0x9062
#define GL_UNSIGNED_INT_IMAGE_2D          0x9063
#define GL_UNSIGNED_INT_IMAGE_3D          0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT     0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE        0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER      0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY    0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY    0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES              0x906D
#define GL_IMAGE_BINDING_FORMAT           0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS      0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS    0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS    0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS    0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM     0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT       0x912F

typedef void (APIENTRYP PFN_zlgl_glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFN_zlgl_glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFN_zlgl_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (APIENTRYP PFN_zlgl_glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (APIENTRYP PFN_zlgl_glMemoryBarrier)(GLbitfield barriers);
typedef void (APIENTRYP PFN_zlgl_glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFN_zlgl_glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFN_zlgl_glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
typedef void (APIENTRYP PFN_zlgl_glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

ZLGL_DEFINE_OPENGL_FUNCTION(glDrawArraysInstancedBaseInstance);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawElementsInstancedBaseInstance);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawElementsInstancedBaseVertexBaseInstance);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetInternalformativ);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetActiveAtomicCounterBufferiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindImageTexture);
ZLGL_DEFINE_OPENGL_FUNCTION(glMemoryBarrier);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexStorage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexStorage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexStorage3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawTransformFeedbackInstanced);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawTransformFeedbackStreamInstanced);

//
//Note: OpenGL Version 4.3
//
typedef void (APIENTRY  *GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
#define GL_NUM_SHADING_LANGUAGE_VERSIONS  0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG       0x874E
#define GL_COMPRESSED_RGB8_ETC2           0x9274
#define GL_COMPRESSED_SRGB8_ETC2          0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC      0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC             0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC      0x9271
#define GL_COMPRESSED_RG11_EAC            0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC     0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX  0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX              0x8D6B
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS     0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS     0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS    0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT   0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE    0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE        0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER       0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT             0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS       0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION        0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM      0x8245
#define GL_DEBUG_SOURCE_API               0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM     0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER   0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY       0x8249
#define GL_DEBUG_SOURCE_APPLICATION       0x824A
#define GL_DEBUG_SOURCE_OTHER             0x824B
#define GL_DEBUG_TYPE_ERROR               0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  0x824E
#define GL_DEBUG_TYPE_PORTABILITY         0x824F
#define GL_DEBUG_TYPE_PERFORMANCE         0x8250
#define GL_DEBUG_TYPE_OTHER               0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH       0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES      0x9144
#define GL_DEBUG_LOGGED_MESSAGES          0x9145
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH    0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH        0x826D
#define GL_BUFFER                         0x82E0
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_QUERY                          0x82E3
#define GL_PROGRAM_PIPELINE               0x82E4
#define GL_SAMPLER                        0x82E6
#define GL_MAX_LABEL_LENGTH               0x82E8
#define GL_DEBUG_OUTPUT                   0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT         0x00000002
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH      0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT     0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS     0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES    0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH          0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT         0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS         0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES        0x9318
#define GL_INTERNALFORMAT_SUPPORTED       0x826F
#define GL_INTERNALFORMAT_PREFERRED       0x8270
#define GL_INTERNALFORMAT_RED_SIZE        0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE      0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE       0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE      0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE      0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE    0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE     0x8277
#define GL_INTERNALFORMAT_RED_TYPE        0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE      0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE       0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE      0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE      0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE    0x827D
#define GL_MAX_WIDTH                      0x827E
#define GL_MAX_HEIGHT                     0x827F
#define GL_MAX_DEPTH                      0x8280
#define GL_MAX_LAYERS                     0x8281
#define GL_MAX_COMBINED_DIMENSIONS        0x8282
#define GL_COLOR_COMPONENTS               0x8283
#define GL_DEPTH_COMPONENTS               0x8284
#define GL_STENCIL_COMPONENTS             0x8285
#define GL_COLOR_RENDERABLE               0x8286
#define GL_DEPTH_RENDERABLE               0x8287
#define GL_STENCIL_RENDERABLE             0x8288
#define GL_FRAMEBUFFER_RENDERABLE         0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND              0x828B
#define GL_READ_PIXELS                    0x828C
#define GL_READ_PIXELS_FORMAT             0x828D
#define GL_READ_PIXELS_TYPE               0x828E
#define GL_TEXTURE_IMAGE_FORMAT           0x828F
#define GL_TEXTURE_IMAGE_TYPE             0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT       0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE         0x8292
#define GL_MIPMAP                         0x8293
#define GL_MANUAL_GENERATE_MIPMAP         0x8294
#define GL_AUTO_GENERATE_MIPMAP           0x8295
#define GL_COLOR_ENCODING                 0x8296
#define GL_SRGB_READ                      0x8297
#define GL_SRGB_WRITE                     0x8298
#define GL_FILTER                         0x829A
#define GL_VERTEX_TEXTURE                 0x829B
#define GL_TESS_CONTROL_TEXTURE           0x829C
#define GL_TESS_EVALUATION_TEXTURE        0x829D
#define GL_GEOMETRY_TEXTURE               0x829E
#define GL_FRAGMENT_TEXTURE               0x829F
#define GL_COMPUTE_TEXTURE                0x82A0
#define GL_TEXTURE_SHADOW                 0x82A1
#define GL_TEXTURE_GATHER                 0x82A2
#define GL_TEXTURE_GATHER_SHADOW          0x82A3
#define GL_SHADER_IMAGE_LOAD              0x82A4
#define GL_SHADER_IMAGE_STORE             0x82A5
#define GL_SHADER_IMAGE_ATOMIC            0x82A6
#define GL_IMAGE_TEXEL_SIZE               0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS      0x82A8
#define GL_IMAGE_PIXEL_FORMAT             0x82A9
#define GL_IMAGE_PIXEL_TYPE               0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE  0x82B3
#define GL_CLEAR_BUFFER                   0x82B4
#define GL_TEXTURE_VIEW                   0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS       0x82B6
#define GL_FULL_SUPPORT                   0x82B7
#define GL_CAVEAT_SUPPORT                 0x82B8
#define GL_IMAGE_CLASS_4_X_32             0x82B9
#define GL_IMAGE_CLASS_2_X_32             0x82BA
#define GL_IMAGE_CLASS_1_X_32             0x82BB
#define GL_IMAGE_CLASS_4_X_16             0x82BC
#define GL_IMAGE_CLASS_2_X_16             0x82BD
#define GL_IMAGE_CLASS_1_X_16             0x82BE
#define GL_IMAGE_CLASS_4_X_8              0x82BF
#define GL_IMAGE_CLASS_2_X_8              0x82C0
#define GL_IMAGE_CLASS_1_X_8              0x82C1
#define GL_IMAGE_CLASS_11_11_10           0x82C2
#define GL_IMAGE_CLASS_10_10_10_2         0x82C3
#define GL_VIEW_CLASS_128_BITS            0x82C4
#define GL_VIEW_CLASS_96_BITS             0x82C5
#define GL_VIEW_CLASS_64_BITS             0x82C6
#define GL_VIEW_CLASS_48_BITS             0x82C7
#define GL_VIEW_CLASS_32_BITS             0x82C8
#define GL_VIEW_CLASS_24_BITS             0x82C9
#define GL_VIEW_CLASS_16_BITS             0x82CA
#define GL_VIEW_CLASS_8_BITS              0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB       0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA      0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA      0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA      0x82CF
#define GL_VIEW_CLASS_RGTC1_RED           0x82D0
#define GL_VIEW_CLASS_RGTC2_RG            0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM          0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT          0x82D3
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
#define GL_BUFFER_VARIABLE                0x92E5
#define GL_SHADER_STORAGE_BLOCK           0x92E6
#define GL_VERTEX_SUBROUTINE              0x92E8
#define GL_TESS_CONTROL_SUBROUTINE        0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE     0x92EA
#define GL_GEOMETRY_SUBROUTINE            0x92EB
#define GL_FRAGMENT_SUBROUTINE            0x92EC
#define GL_COMPUTE_SUBROUTINE             0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM      0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM    0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM    0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM     0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING     0x92F4
#define GL_ACTIVE_RESOURCES               0x92F5
#define GL_MAX_NAME_LENGTH                0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES       0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH                    0x92F9
#define GL_TYPE                           0x92FA
#define GL_ARRAY_SIZE                     0x92FB
#define GL_OFFSET                         0x92FC
#define GL_BLOCK_INDEX                    0x92FD
#define GL_ARRAY_STRIDE                   0x92FE
#define GL_MATRIX_STRIDE                  0x92FF
#define GL_IS_ROW_MAJOR                   0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX    0x9301
#define GL_BUFFER_BINDING                 0x9302
#define GL_BUFFER_DATA_SIZE               0x9303
#define GL_NUM_ACTIVE_VARIABLES           0x9304
#define GL_ACTIVE_VARIABLES               0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER    0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER  0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER  0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER   0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE           0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE         0x930D
#define GL_LOCATION                       0x930E
#define GL_LOCATION_INDEX                 0x930F
#define GL_IS_PER_PATCH                   0x92E7
#define GL_SHADER_STORAGE_BUFFER          0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING  0x90D3
#define GL_SHADER_STORAGE_BUFFER_START    0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE     0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE  0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT     0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE     0x90EA
#define GL_TEXTURE_BUFFER_OFFSET          0x919D
#define GL_TEXTURE_BUFFER_SIZE            0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL         0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS        0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER         0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS        0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS       0x82DF
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET  0x82D5
#define GL_VERTEX_BINDING_DIVISOR         0x82D6
#define GL_VERTEX_BINDING_OFFSET          0x82D7
#define GL_VERTEX_BINDING_STRIDE          0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_VERTEX_BINDING_BUFFER          0x8F4F

typedef void (APIENTRYP PFN_zlgl_glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFN_zlgl_glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFN_zlgl_glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (APIENTRYP PFN_zlgl_glDispatchComputeIndirect)(GLintptr indirect);
typedef void (APIENTRYP PFN_zlgl_glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (APIENTRYP PFN_zlgl_glFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
typedef void (APIENTRYP PFN_zlgl_glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFN_zlgl_glInvalidateTexImage)(GLuint texture, GLint level);
typedef void (APIENTRYP PFN_zlgl_glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFN_zlgl_glInvalidateBufferData)(GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFN_zlgl_glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glMultiDrawArraysIndirect)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
typedef GLuint(APIENTRYP PFN_zlgl_glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
typedef GLint(APIENTRYP PFN_zlgl_glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar *name);
typedef GLint(APIENTRYP PFN_zlgl_glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (APIENTRYP PFN_zlgl_glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFN_zlgl_glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFN_zlgl_glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFN_zlgl_glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (APIENTRYP PFN_zlgl_glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFN_zlgl_glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFN_zlgl_glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFN_zlgl_glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFN_zlgl_glDebugMessageCallback)(GLDEBUGPROC callback, const void *userParam);
typedef GLuint(APIENTRYP PFN_zlgl_glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void (APIENTRYP PFN_zlgl_glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void (APIENTRYP PFN_zlgl_glPopDebugGroup)(void);
typedef void (APIENTRYP PFN_zlgl_glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFN_zlgl_glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFN_zlgl_glObjectPtrLabel)(const void *ptr, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFN_zlgl_glGetObjectPtrLabel)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);

ZLGL_DEFINE_OPENGL_FUNCTION(glClearBufferData);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearBufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glDispatchCompute);
ZLGL_DEFINE_OPENGL_FUNCTION(glDispatchComputeIndirect);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyImageSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferParameteri);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFramebufferParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetInternalformati64v);
ZLGL_DEFINE_OPENGL_FUNCTION(glInvalidateTexSubImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glInvalidateTexImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glInvalidateBufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glInvalidateBufferData);
ZLGL_DEFINE_OPENGL_FUNCTION(glInvalidateFramebuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glInvalidateSubFramebuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawArraysIndirect);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawElementsIndirect);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramInterfaceiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramResourceIndex);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramResourceName);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramResourceiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramResourceLocation);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramResourceLocationIndex);
ZLGL_DEFINE_OPENGL_FUNCTION(glShaderStorageBlockBinding);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexBufferRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexStorage2DMultisample);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexStorage3DMultisample);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureView);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindVertexBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribFormat);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribIFormat);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribLFormat);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribBinding);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexBindingDivisor);
ZLGL_DEFINE_OPENGL_FUNCTION(glDebugMessageControl);
ZLGL_DEFINE_OPENGL_FUNCTION(glDebugMessageInsert);
ZLGL_DEFINE_OPENGL_FUNCTION(glDebugMessageCallback);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetDebugMessageLog);
ZLGL_DEFINE_OPENGL_FUNCTION(glPushDebugGroup);
ZLGL_DEFINE_OPENGL_FUNCTION(glPopDebugGroup);
ZLGL_DEFINE_OPENGL_FUNCTION(glObjectLabel);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetObjectLabel);
ZLGL_DEFINE_OPENGL_FUNCTION(glObjectPtrLabel);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetObjectPtrLabel);


//
//Note: OpenGL Version 4.4
//

#define GL_MAX_VERTEX_ATTRIB_STRIDE       0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING         0x8C2A
#define GL_MAP_PERSISTENT_BIT             0x0040
#define GL_MAP_COHERENT_BIT               0x0080
#define GL_DYNAMIC_STORAGE_BIT            0x0100
#define GL_CLIENT_STORAGE_BIT             0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE       0x821F
#define GL_BUFFER_STORAGE_FLAGS           0x8220
#define GL_CLEAR_TEXTURE                  0x9365
#define GL_LOCATION_COMPONENT             0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_QUERY_BUFFER                   0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT       0x00008000
#define GL_QUERY_BUFFER_BINDING           0x9193
#define GL_QUERY_RESULT_NO_WAIT           0x9194
#define GL_MIRROR_CLAMP_TO_EDGE           0x8743

typedef void (APIENTRYP PFN_zlgl_glBufferStorage)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFN_zlgl_glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFN_zlgl_glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFN_zlgl_glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
typedef void (APIENTRYP PFN_zlgl_glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef void (APIENTRYP PFN_zlgl_glBindTextures)(GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFN_zlgl_glBindSamplers)(GLuint first, GLsizei count, const GLuint *samplers);
typedef void (APIENTRYP PFN_zlgl_glBindImageTextures)(GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFN_zlgl_glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);

ZLGL_DEFINE_OPENGL_FUNCTION(glBufferStorage);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearTexImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearTexSubImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindBuffersBase);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindBuffersRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindTextures);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindSamplers);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindImageTextures);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindVertexBuffers);


//
//Note: OpenGL Version 4.5
//

#define GL_CONTEXT_LOST                   0x0507
#define GL_NEGATIVE_ONE_TO_ONE            0x935E
#define GL_ZERO_TO_ONE                    0x935F
#define GL_CLIP_ORIGIN                    0x935C
#define GL_CLIP_DEPTH_MODE                0x935D
#define GL_QUERY_WAIT_INVERTED            0x8E17
#define GL_QUERY_NO_WAIT_INVERTED         0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED  0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_MAX_CULL_DISTANCES             0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET                 0x1006
#define GL_QUERY_TARGET                   0x82EA
#define GL_GUILTY_CONTEXT_RESET           0x8253
#define GL_INNOCENT_CONTEXT_RESET         0x8254
#define GL_UNKNOWN_CONTEXT_RESET          0x8255
#define GL_RESET_NOTIFICATION_STRATEGY    0x8256
#define GL_LOSE_CONTEXT_ON_RESET          0x8252
#define GL_NO_RESET_NOTIFICATION          0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#define GL_CONTEXT_RELEASE_BEHAVIOR       0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC

typedef void (APIENTRYP PFN_zlgl_glClipControl)(GLenum origin, GLenum depth);
typedef void (APIENTRYP PFN_zlgl_glCreateTransformFeedbacks)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFN_zlgl_glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFN_zlgl_glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint *param);
typedef void (APIENTRYP PFN_zlgl_glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
typedef void (APIENTRYP PFN_zlgl_glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
typedef void (APIENTRYP PFN_zlgl_glCreateBuffers)(GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFN_zlgl_glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFN_zlgl_glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFN_zlgl_glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFN_zlgl_glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFN_zlgl_glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFN_zlgl_glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void *(APIENTRYP PFN_zlgl_glMapNamedBuffer)(GLuint buffer, GLenum access);
typedef void *(APIENTRYP PFN_zlgl_glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean(APIENTRYP PFN_zlgl_glUnmapNamedBuffer)(GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFN_zlgl_glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFN_zlgl_glCreateFramebuffers)(GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src);
typedef void (APIENTRYP PFN_zlgl_glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFN_zlgl_glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFN_zlgl_glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum(APIENTRYP PFN_zlgl_glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFN_zlgl_glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint *param);
typedef void (APIENTRYP PFN_zlgl_glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glCreateRenderbuffers)(GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFN_zlgl_glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glCreateTextures)(GLenum target, GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFN_zlgl_glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFN_zlgl_glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFN_zlgl_glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFN_zlgl_glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFN_zlgl_glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFN_zlgl_glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFN_zlgl_glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFN_zlgl_glTextureParameteri)(GLuint texture, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glTextureParameteriv)(GLuint texture, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFN_zlgl_glGenerateTextureMipmap)(GLuint texture);
typedef void (APIENTRYP PFN_zlgl_glBindTextureUnit)(GLuint unit, GLuint texture);
typedef void (APIENTRYP PFN_zlgl_glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFN_zlgl_glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFN_zlgl_glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glCreateVertexArrays)(GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFN_zlgl_glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFN_zlgl_glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFN_zlgl_glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFN_zlgl_glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
typedef void (APIENTRYP PFN_zlgl_glCreateSamplers)(GLsizei n, GLuint *samplers);
typedef void (APIENTRYP PFN_zlgl_glCreateProgramPipelines)(GLsizei n, GLuint *pipelines);
typedef void (APIENTRYP PFN_zlgl_glCreateQueries)(GLenum target, GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFN_zlgl_glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glMemoryBarrierByRegion)(GLbitfield barriers);
typedef void (APIENTRYP PFN_zlgl_glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFN_zlgl_glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
typedef GLenum(APIENTRYP PFN_zlgl_glGetGraphicsResetStatus)(void);
typedef void (APIENTRYP PFN_zlgl_glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFN_zlgl_glGetnTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformdv)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFN_zlgl_glTextureBarrier)(void);


ZLGL_DEFINE_OPENGL_FUNCTION(glClipControl);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateTransformFeedbacks);
ZLGL_DEFINE_OPENGL_FUNCTION(glTransformFeedbackBufferBase);
ZLGL_DEFINE_OPENGL_FUNCTION(glTransformFeedbackBufferRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTransformFeedbackiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTransformFeedbacki_v);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTransformFeedbacki64_v);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateBuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedBufferStorage);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedBufferData);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedBufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyNamedBufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearNamedBufferData);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearNamedBufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glMapNamedBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glMapNamedBufferRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glUnmapNamedBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glFlushMappedNamedBufferRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedBufferParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedBufferParameteri64v);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedBufferPointerv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedBufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateFramebuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferRenderbuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferParameteri);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferTexture);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferTextureLayer);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferDrawBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferDrawBuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferReadBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glInvalidateNamedFramebufferData);
ZLGL_DEFINE_OPENGL_FUNCTION(glInvalidateNamedFramebufferSubData);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearNamedFramebufferiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearNamedFramebufferuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearNamedFramebufferfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearNamedFramebufferfi);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlitNamedFramebuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glCheckNamedFramebufferStatus);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedFramebufferParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedFramebufferAttachmentParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateRenderbuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedRenderbufferStorage);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedRenderbufferStorageMultisample);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedRenderbufferParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateTextures);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureBufferRange);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage2DMultisample);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage3DMultisample);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureSubImage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureSubImage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureSubImage3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTextureSubImage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTextureSubImage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTextureSubImage3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTextureSubImage1D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTextureSubImage2D);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTextureSubImage3D);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameterf);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameteri);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameterIiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameterIuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenerateTextureMipmap);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindTextureUnit);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetCompressedTextureImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureLevelParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureLevelParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureParameterfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureParameterIiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureParameterIuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureParameteriv);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateVertexArrays);
ZLGL_DEFINE_OPENGL_FUNCTION(glDisableVertexArrayAttrib);
ZLGL_DEFINE_OPENGL_FUNCTION(glEnableVertexArrayAttrib);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayElementBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexBuffer);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexBuffers);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayAttribBinding);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayAttribFormat);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayAttribIFormat);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayAttribLFormat);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayBindingDivisor);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexArrayiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexArrayIndexediv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexArrayIndexed64iv);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateSamplers);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateProgramPipelines);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateQueries);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryBufferObjecti64v);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryBufferObjectiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryBufferObjectui64v);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetQueryBufferObjectuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glMemoryBarrierByRegion);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureSubImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetCompressedTextureSubImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetGraphicsResetStatus);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnCompressedTexImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnTexImage);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformdv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformfv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformuiv);
ZLGL_DEFINE_OPENGL_FUNCTION(glReadnPixels);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureBarrier);

//
//Note: OpenGL Extensions
//
#ifndef ZLGL_NO_GL_EXTENSIONS


static int zlgl_CheckGLExtensionAvailable(const char* ExtensionName)
{
	int Result = 0;
	if (glGetStringi)
	{
		int NumberOfExtensions;
		glGetIntegerv(GL_NUM_EXTENSIONS, &NumberOfExtensions);
		for (int i = 0; i < NumberOfExtensions; i++) {
			const char *glExt = (const char*)glGetStringi(GL_EXTENSIONS, i);
			if (ZLGL_STRSTR(glExt, "GL_ARB_debug_output")) {
				Result = 1;
				break;
			}
		}
	}
	else
	{
		const char* AllExtensions = (const char*)glGetString(GL_EXTENSIONS);
		if (ZLGL_STRSTR(AllExtensions, ExtensionName))
		{
			Result = 1;
		}
	}
	return(Result);
}


#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
#endif /* GL_ARB_ES2_compatibility */

#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
#endif /* GL_ARB_ES3_1_compatibility */

#ifndef GL_ARB_ES3_2_compatibility
#define GL_ARB_ES3_2_compatibility 1
#define GL_PRIMITIVE_BOUNDING_BOX_ARB     0x92BE
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB 0x9381
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB 0x9382

typedef void (APIENTRYP PFN_zlgl_glPrimitiveBoundingBoxARB)(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
ZLGL_DEFINE_OPENGL_FUNCTION(glPrimitiveBoundingBoxARB);
#endif /* GL_ARB_ES3_2_compatibility */

#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1
#endif /* GL_ARB_ES3_compatibility */

#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1
#endif /* GL_ARB_arrays_of_arrays */

#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
#endif /* GL_ARB_base_instance */

#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
	typedef uint64_t GLuint64EXT;
#define GL_UNSIGNED_INT64_ARB             0x140F
typedef GLuint64 (APIENTRYP PFN_zlgl_glGetTextureHandleARB)(GLuint texture);
typedef GLuint64 (APIENTRYP PFN_zlgl_glGetTextureSamplerHandleARB)(GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFN_zlgl_glMakeTextureHandleResidentARB)(GLuint64 handle);
typedef void (APIENTRYP PFN_zlgl_glMakeTextureHandleNonResidentARB)(GLuint64 handle);
typedef GLuint64 (APIENTRYP PFN_zlgl_glGetImageHandleARB)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFN_zlgl_glMakeImageHandleResidentARB)(GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFN_zlgl_glMakeImageHandleNonResidentARB)(GLuint64 handle);
typedef void (APIENTRYP PFN_zlgl_glUniformHandleui64ARB)(GLint location, GLuint64 value);
typedef void (APIENTRYP PFN_zlgl_glUniformHandleui64vARB)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformHandleui64ARB)(GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformHandleui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
typedef GLboolean (APIENTRYP PFN_zlgl_glIsTextureHandleResidentARB)(GLuint64 handle);
typedef GLboolean (APIENTRYP PFN_zlgl_glIsImageHandleResidentARB)(GLuint64 handle);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL1ui64ARB)(GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL1ui64vARB)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribLui64vARB)(GLuint index, GLenum pname, GLuint64EXT *params);

ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureHandleARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureSamplerHandleARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeTextureHandleResidentARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeTextureHandleNonResidentARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetImageHandleARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeImageHandleResidentARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeImageHandleNonResidentARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformHandleui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformHandleui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformHandleui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformHandleui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsTextureHandleResidentARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsImageHandleResidentARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL1ui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL1ui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribLui64vARB);
#endif /* GL_ARB_bindless_texture */

#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
#endif /* GL_ARB_blend_func_extended */

#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
#endif /* GL_ARB_buffer_storage */

#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
	struct _cl_context;
	struct _cl_event;
#define GL_SYNC_CL_EVENT_ARB              0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB     0x8241
	
typedef GLsync (APIENTRYP PFN_zlgl_glCreateSyncFromCLeventARB)(struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateSyncFromCLeventARB);
#endif /* GL_ARB_cl_event */

#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
#endif /* GL_ARB_clear_buffer_object */

#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
#endif /* GL_ARB_clear_texture */

#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
#endif /* GL_ARB_clip_control */

#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1
#endif /* GL_ARB_compressed_texture_pixel_storage */

#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
#endif /* GL_ARB_compute_shader */

#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
typedef void (APIENTRYP PFN_zlgl_glDispatchComputeGroupSizeARB)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
ZLGL_DEFINE_OPENGL_FUNCTION(glDispatchComputeGroupSizeARB);
#endif /* GL_ARB_compute_variable_group_size */

#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1
#endif /* GL_ARB_conditional_render_inverted */

#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1
#endif /* GL_ARB_conservative_depth */

#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
#endif /* GL_ARB_copy_buffer */

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
#endif /* GL_ARB_copy_image */

#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1
#endif /* GL_ARB_cull_distance */

#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
typedef void (APIENTRY GLDEBUGPROCARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB   0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB    0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB  0x8245
#define GL_DEBUG_SOURCE_API_ARB           0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB   0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB   0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB         0x824B
#define GL_DEBUG_TYPE_ERROR_ARB           0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB     0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB     0x8250
#define GL_DEBUG_TYPE_OTHER_ARB           0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB   0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB  0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB      0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB        0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB      0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB         0x9148

typedef void (APIENTRYP PFN_zlgl_glDebugMessageControlARB)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFN_zlgl_glDebugMessageInsertARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFN_zlgl_glDebugMessageCallbackARB)(GLDEBUGPROCARB callback, const void *userParam);
typedef GLuint(APIENTRYP PFN_zlgl_glGetDebugMessageLogARB)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);

ZLGL_DEFINE_OPENGL_FUNCTION(glDebugMessageControlARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glDebugMessageInsertARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glDebugMessageCallbackARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetDebugMessageLogARB);
#endif /* GL_ARB_debug_output */

#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1
#endif /* GL_ARB_depth_buffer_float */

#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1
#endif /* GL_ARB_depth_clamp */

#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1
#endif /* GL_ARB_derivative_control */

#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
#endif /* GL_ARB_direct_state_access */

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
typedef void (APIENTRYP PFN_zlgl_glBlendEquationiARB)(GLuint buf, GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glBlendEquationSeparateiARB)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFN_zlgl_glBlendFunciARB)(GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFN_zlgl_glBlendFuncSeparateiARB)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);

ZLGL_DEFINE_OPENGL_FUNCTION(glBlendEquationiARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendEquationSeparateiARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendFunciARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendFuncSeparateiARB);
#endif /* GL_ARB_draw_buffers_blend */

#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
#endif /* GL_ARB_draw_elements_base_vertex */

#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
#endif /* GL_ARB_draw_indirect */

#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
typedef void (APIENTRYP PFN_zlgl_glDrawArraysInstancedARB)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFN_zlgl_glDrawElementsInstancedARB)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);

ZLGL_DEFINE_OPENGL_FUNCTION(glDrawArraysInstancedARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawElementsInstancedARB);
#endif /* GL_ARB_draw_instanced */

#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1
#endif /* GL_ARB_enhanced_layouts */

#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1
#endif /* GL_ARB_explicit_attrib_location */

#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1
#endif /* GL_ARB_explicit_uniform_location */

#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1
#endif /* GL_ARB_fragment_coord_conventions */

#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1
#endif /* GL_ARB_fragment_layer_viewport */

#ifndef GL_ARB_fragment_shader_interlock
#define GL_ARB_fragment_shader_interlock 1
#endif /* GL_ARB_fragment_shader_interlock */

#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
#endif /* GL_ARB_framebuffer_no_attachments */

#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
#endif /* GL_ARB_framebuffer_object */

#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1
#endif /* GL_ARB_framebuffer_sRGB */

#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
#define GL_LINES_ADJACENCY_ARB            0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB       0x000B
#define GL_TRIANGLES_ADJACENCY_ARB        0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB   0x000D
#define GL_PROGRAM_POINT_SIZE_ARB         0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB            0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB      0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB        0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB       0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1

typedef void (APIENTRYP PFN_zlgl_glProgramParameteriARB)(GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFN_zlgl_glFramebufferTextureARB)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFN_zlgl_glFramebufferTextureLayerARB)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFN_zlgl_glFramebufferTextureFaceARB)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);

ZLGL_DEFINE_OPENGL_FUNCTION(glProgramParameteriARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferTextureARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferTextureLayerARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferTextureFaceARB);
#endif /* GL_ARB_geometry_shader4 */

#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
#endif /* GL_ARB_get_program_binary */

#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
#endif /* GL_ARB_get_texture_sub_image */

#ifndef GL_ARB_gl_spirv
#define GL_ARB_gl_spirv 1
#define GL_SHADER_BINARY_FORMAT_SPIR_V_ARB 0x9551
#define GL_SPIR_V_BINARY_ARB              0x9552
typedef void (APIENTRYP PFN_zlgl_glSpecializeShaderARB)(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
ZLGL_DEFINE_OPENGL_FUNCTION(glSpecializeShaderARB);
#endif /* GL_ARB_gl_spirv */

#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1
#endif /* GL_ARB_gpu_shader5 */

#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
#endif /* GL_ARB_gpu_shader_fp64 */

#ifndef GL_ARB_gpu_shader_int64
#define GL_ARB_gpu_shader_int64 1
#define GL_INT64_ARB                      0x140E
#define GL_INT64_VEC2_ARB                 0x8FE9
#define GL_INT64_VEC3_ARB                 0x8FEA
#define GL_INT64_VEC4_ARB                 0x8FEB
#define GL_UNSIGNED_INT64_VEC2_ARB        0x8FF5
#define GL_UNSIGNED_INT64_VEC3_ARB        0x8FF6
#define GL_UNSIGNED_INT64_VEC4_ARB        0x8FF7
typedef void (APIENTRYP PFN_zlgl_glUniform1i64ARB)(GLint location, GLint64 x);
typedef void (APIENTRYP PFN_zlgl_glUniform2i64ARB)(GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFN_zlgl_glUniform3i64ARB)(GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFN_zlgl_glUniform4i64ARB)(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFN_zlgl_glUniform1i64vARB)(GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFN_zlgl_glUniform2i64vARB)(GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFN_zlgl_glUniform3i64vARB)(GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFN_zlgl_glUniform4i64vARB)(GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFN_zlgl_glUniform1ui64ARB)(GLint location, GLuint64 x);
typedef void (APIENTRYP PFN_zlgl_glUniform2ui64ARB)(GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFN_zlgl_glUniform3ui64ARB)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFN_zlgl_glUniform4ui64ARB)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFN_zlgl_glUniform1ui64vARB)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFN_zlgl_glUniform2ui64vARB)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFN_zlgl_glUniform3ui64vARB)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFN_zlgl_glUniform4ui64vARB)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFN_zlgl_glGetUniformi64vARB)(GLuint program, GLint location, GLint64 *params);
typedef void (APIENTRYP PFN_zlgl_glGetUniformui64vARB)(GLuint program, GLint location, GLuint64 *params);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformi64vARB)(GLuint program, GLint location, GLsizei bufSize, GLint64 *params);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformui64vARB)(GLuint program, GLint location, GLsizei bufSize, GLuint64 *params);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1i64ARB)(GLuint program, GLint location, GLint64 x);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2i64ARB)(GLuint program, GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3i64ARB)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4i64ARB)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1ui64ARB)(GLuint program, GLint location, GLuint64 x);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2ui64ARB)(GLuint program, GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3ui64ARB)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4ui64ARB)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);

ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1i64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2i64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3i64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4i64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1i64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2i64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3i64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4i64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1ui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2ui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3ui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4ui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1ui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2ui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3ui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4ui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformi64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformi64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1i64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2i64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3i64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4i64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1i64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2i64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3i64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4i64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1ui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2ui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3ui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4ui64ARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1ui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2ui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3ui64vARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4ui64vARB);
#endif /* GL_ARB_gpu_shader_int64 */

#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1
#endif /* GL_ARB_half_float_vertex */

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
#define GL_BLEND_COLOR                    0x8005
#define GL_BLEND_EQUATION                 0x8009
#endif /* GL_ARB_imaging */

#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
#define GL_PARAMETER_BUFFER_ARB           0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB   0x80EF

typedef void (APIENTRYP PFN_zlgl_glMultiDrawArraysIndirectCountARB)(GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glMultiDrawElementsIndirectCountARB)(GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);

ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawArraysIndirectCountARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawElementsIndirectCountARB);
#endif /* GL_ARB_indirect_parameters */

#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE
typedef void (APIENTRYP PFN_zlgl_glVertexAttribDivisorARB)(GLuint index, GLuint divisor);

ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribDivisorARB);
#endif /* GL_ARB_instanced_arrays */

#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
#endif /* GL_ARB_internalformat_query */

#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
#define GL_SRGB_DECODE_ARB                0x8299
#endif /* GL_ARB_internalformat_query2 */

#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
#endif /* GL_ARB_invalidate_subdata */

#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1
#endif /* GL_ARB_map_buffer_alignment */

#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
#endif /* GL_ARB_map_buffer_range */

#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
#endif /* GL_ARB_multi_bind */

#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
#endif /* GL_ARB_multi_draw_indirect */

#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1
#endif /* GL_ARB_occlusion_query2 */

#ifndef GL_ARB_parallel_shader_compile
#define GL_ARB_parallel_shader_compile 1
#define GL_MAX_SHADER_COMPILER_THREADS_ARB 0x91B0
#define GL_COMPLETION_STATUS_ARB          0x91B1
typedef void (APIENTRYP PFN_zlgl_glMaxShaderCompilerThreadsARB)(GLuint count);

ZLGL_DEFINE_OPENGL_FUNCTION(glMaxShaderCompilerThreadsARB);
#endif /* GL_ARB_parallel_shader_compile */

#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query 1
#define GL_VERTICES_SUBMITTED_ARB         0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB       0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB  0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB  0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#endif /* GL_ARB_pipeline_statistics_query */

#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object 1
#define GL_PIXEL_PACK_BUFFER_ARB          0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB        0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB  0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF
#endif /* GL_ARB_pixel_buffer_object */

#ifndef GL_ARB_post_depth_coverage
#define GL_ARB_post_depth_coverage 1
#endif /* GL_ARB_post_depth_coverage */

#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
#endif /* GL_ARB_program_interface_query */

#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
#endif /* GL_ARB_provoking_vertex */

#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object 1
#endif /* GL_ARB_query_buffer_object */

#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1
#endif /* GL_ARB_robust_buffer_access_behavior */

#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB      0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB       0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB     0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB      0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB      0x8261
typedef GLenum(APIENTRYP PFN_zlgl_glGetGraphicsResetStatusARB)(void);
typedef void (APIENTRYP PFN_zlgl_glGetnTexImageARB)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFN_zlgl_glReadnPixelsARB)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFN_zlgl_glGetnCompressedTexImageARB)(GLenum target, GLint lod, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformfvARB)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformivARB)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformuivARB)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glGetnUniformdvARB)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);

ZLGL_DEFINE_OPENGL_FUNCTION(glGetGraphicsResetStatusARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnTexImageARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glReadnPixelsARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnCompressedTexImageARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformfvARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformivARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformuivARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetnUniformdvARB);
#endif /* GL_ARB_robustness */

#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1
#endif /* GL_ARB_robustness_isolation */

#ifndef GL_ARB_sample_locations
#define GL_ARB_sample_locations 1
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB 0x9340
#define GL_SAMPLE_LOCATION_ARB            0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB 0x9343
typedef void (APIENTRYP PFN_zlgl_glFramebufferSampleLocationsfvARB)(GLenum target, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferSampleLocationsfvARB)(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glEvaluateDepthValuesARB)(void);

ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferSampleLocationsfvARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferSampleLocationsfvARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glEvaluateDepthValuesARB);
#endif /* GL_ARB_sample_locations */

#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
#define GL_SAMPLE_SHADING_ARB             0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB   0x8C37
typedef void (APIENTRYP PFN_zlgl_glMinSampleShadingARB)(GLfloat value);

ZLGL_DEFINE_OPENGL_FUNCTION(glMinSampleShadingARB);
#endif /* GL_ARB_sample_shading */

#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
#endif /* GL_ARB_sampler_objects */

#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1
#endif /* GL_ARB_seamless_cube_map */

#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture 1
#endif /* GL_ARB_seamless_cubemap_per_texture */

#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
#endif /* GL_ARB_separate_shader_objects */

#ifndef GL_ARB_shader_atomic_counter_ops
#define GL_ARB_shader_atomic_counter_ops 1
#endif /* GL_ARB_shader_atomic_counter_ops */

#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
#endif /* GL_ARB_shader_atomic_counters */

#ifndef GL_ARB_shader_ballot
#define GL_ARB_shader_ballot 1
#endif /* GL_ARB_shader_ballot */

#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1
#endif /* GL_ARB_shader_bit_encoding */

#ifndef GL_ARB_shader_clock
#define GL_ARB_shader_clock 1
#endif /* GL_ARB_shader_clock */

#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters 1
#endif /* GL_ARB_shader_draw_parameters */

#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote 1
#endif /* GL_ARB_shader_group_vote */

#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
#endif /* GL_ARB_shader_image_load_store */

#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1
#endif /* GL_ARB_shader_image_size */

#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision 1
#endif /* GL_ARB_shader_precision */

#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1
#endif /* GL_ARB_shader_stencil_export */

#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
#endif /* GL_ARB_shader_storage_buffer_object */

#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
#endif /* GL_ARB_shader_subroutine */

#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples 1
#endif /* GL_ARB_shader_texture_image_samples */

#ifndef GL_ARB_shader_viewport_layer_array
#define GL_ARB_shader_viewport_layer_array 1
#endif /* GL_ARB_shader_viewport_layer_array */

#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1
#endif /* GL_ARB_shading_language_420pack */

#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
#define GL_SHADER_INCLUDE_ARB             0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB        0x8DE9
#define GL_NAMED_STRING_TYPE_ARB          0x8DEA

typedef void (APIENTRYP PFN_zlgl_glNamedStringARB)(GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
typedef void (APIENTRYP PFN_zlgl_glDeleteNamedStringARB)(GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glCompileShaderIncludeARB)(GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsNamedStringARB)(GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glGetNamedStringARB)(GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
typedef void (APIENTRYP PFN_zlgl_glGetNamedStringivARB)(GLint namelen, const GLchar *name, GLenum pname, GLint *params);

ZLGL_DEFINE_OPENGL_FUNCTION(glNamedStringARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteNamedStringARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompileShaderIncludeARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsNamedStringARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedStringARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedStringivARB);
#endif /* GL_ARB_shading_language_include */

#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1
#endif /* GL_ARB_shading_language_packing */

#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
#define GL_SPARSE_STORAGE_BIT_ARB         0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB    0x82F8
typedef void (APIENTRYP PFN_zlgl_glBufferPageCommitmentARB)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFN_zlgl_glNamedBufferPageCommitmentEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFN_zlgl_glNamedBufferPageCommitmentARB)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);

ZLGL_DEFINE_OPENGL_FUNCTION(glBufferPageCommitmentARB);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedBufferPageCommitmentEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedBufferPageCommitmentARB);
#endif /* GL_ARB_sparse_buffer */

#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
#define GL_TEXTURE_SPARSE_ARB             0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB    0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB          0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB     0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB        0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB        0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB        0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB    0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
typedef void (APIENTRYP PFN_zlgl_glTexPageCommitmentARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);

ZLGL_DEFINE_OPENGL_FUNCTION(glTexPageCommitmentARB);
#endif /* GL_ARB_sparse_texture */

#ifndef GL_ARB_sparse_texture2
#define GL_ARB_sparse_texture2 1
#endif /* GL_ARB_sparse_texture2 */

#ifndef GL_ARB_sparse_texture_clamp
#define GL_ARB_sparse_texture_clamp 1
#endif /* GL_ARB_sparse_texture_clamp */

#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1
#endif /* GL_ARB_stencil_texturing */

#ifndef GL_ARB_sync
#define GL_ARB_sync 1
#endif /* GL_ARB_sync */

#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
#endif /* GL_ARB_tessellation_shader */

#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1
#endif /* GL_ARB_texture_barrier */

#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp 1
#define GL_CLAMP_TO_BORDER_ARB            0x812D
#endif /* GL_ARB_texture_border_clamp */

#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1
#define GL_TEXTURE_BUFFER_ARB             0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB    0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB     0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB      0x8C2E
typedef void (APIENTRYP PFN_zlgl_glTexBufferARB)(GLenum target, GLenum internalformat, GLuint buffer);

ZLGL_DEFINE_OPENGL_FUNCTION(glTexBufferARB);
#endif /* GL_ARB_texture_buffer_object */

#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1
#endif /* GL_ARB_texture_buffer_object_rgb32 */

#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
#endif /* GL_ARB_texture_buffer_range */

#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#endif /* GL_ARB_texture_compression_bptc */

#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1
#endif /* GL_ARB_texture_compression_rgtc */

#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB     0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB     0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#endif /* GL_ARB_texture_cube_map_array */

#ifndef GL_ARB_texture_filter_minmax
#define GL_ARB_texture_filter_minmax 1
#define GL_TEXTURE_REDUCTION_MODE_ARB     0x9366
#define GL_WEIGHTED_AVERAGE_ARB           0x9367
#endif /* GL_ARB_texture_filter_minmax */

#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#endif /* GL_ARB_texture_gather */

#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge 1
#endif /* GL_ARB_texture_mirror_clamp_to_edge */

#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat 1
#define GL_MIRRORED_REPEAT_ARB            0x8370
#endif /* GL_ARB_texture_mirrored_repeat */

#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
#endif /* GL_ARB_texture_multisample */

#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two 1
#endif /* GL_ARB_texture_non_power_of_two */

#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1
#endif /* GL_ARB_texture_query_levels */

#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1
#endif /* GL_ARB_texture_query_lod */

#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1
#endif /* GL_ARB_texture_rg */

#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1
#endif /* GL_ARB_texture_rgb10_a2ui */

#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8 1
#endif /* GL_ARB_texture_stencil8 */

#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
#endif /* GL_ARB_texture_storage */

#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
#endif /* GL_ARB_texture_storage_multisample */

#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1
#endif /* GL_ARB_texture_swizzle */

#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
#endif /* GL_ARB_texture_view */

#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
#endif /* GL_ARB_timer_query */

#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
#endif /* GL_ARB_transform_feedback2 */

#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
#endif /* GL_ARB_transform_feedback3 */

#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
#endif /* GL_ARB_transform_feedback_instanced */

#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query 1
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#endif /* GL_ARB_transform_feedback_overflow_query */

#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
#endif /* GL_ARB_uniform_buffer_object */

#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1
#endif /* GL_ARB_vertex_array_bgra */

#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
#endif /* GL_ARB_vertex_array_object */

#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
#endif /* GL_ARB_vertex_attrib_64bit */

#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
#endif /* GL_ARB_vertex_attrib_binding */

#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev 1
#endif /* GL_ARB_vertex_type_10f_11f_11f_rev */

#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
#endif /* GL_ARB_vertex_type_2_10_10_10_rev */

#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
#endif /* GL_ARB_viewport_array */

#ifndef GL_KHR_blend_equation_advanced
#define GL_KHR_blend_equation_advanced 1
#define GL_MULTIPLY_KHR                   0x9294
#define GL_SCREEN_KHR                     0x9295
#define GL_OVERLAY_KHR                    0x9296
#define GL_DARKEN_KHR                     0x9297
#define GL_LIGHTEN_KHR                    0x9298
#define GL_COLORDODGE_KHR                 0x9299
#define GL_COLORBURN_KHR                  0x929A
#define GL_HARDLIGHT_KHR                  0x929B
#define GL_SOFTLIGHT_KHR                  0x929C
#define GL_DIFFERENCE_KHR                 0x929E
#define GL_EXCLUSION_KHR                  0x92A0
#define GL_HSL_HUE_KHR                    0x92AD
#define GL_HSL_SATURATION_KHR             0x92AE
#define GL_HSL_COLOR_KHR                  0x92AF
#define GL_HSL_LUMINOSITY_KHR             0x92B0
typedef void (APIENTRYP PFN_zlgl_glBlendBarrierKHR)(void);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendBarrierKHR);
#endif /* GL_KHR_blend_equation_advanced */

#ifndef GL_KHR_blend_equation_advanced_coherent
#define GL_KHR_blend_equation_advanced_coherent 1
#define GL_BLEND_ADVANCED_COHERENT_KHR    0x9285
#endif /* GL_KHR_blend_equation_advanced_coherent */

#ifndef GL_KHR_context_flush_control
#define GL_KHR_context_flush_control 1
#endif /* GL_KHR_context_flush_control */

#ifndef GL_KHR_debug
#define GL_KHR_debug 1
#endif /* GL_KHR_debug */

#ifndef GL_KHR_no_error
#define GL_KHR_no_error 1
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR  0x00000008
#endif /* GL_KHR_no_error */

#ifndef GL_KHR_robust_buffer_access_behavior
#define GL_KHR_robust_buffer_access_behavior 1
#endif /* GL_KHR_robust_buffer_access_behavior */

#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
#define GL_CONTEXT_ROBUST_ACCESS          0x90F3
#endif /* GL_KHR_robustness */

#ifndef GL_KHR_texture_compression_astc_hdr
#define GL_KHR_texture_compression_astc_hdr 1
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR   0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR   0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR   0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR   0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR   0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR   0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR   0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR   0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR  0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR  0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR  0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#endif /* GL_KHR_texture_compression_astc_hdr */

#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr 1
#endif /* GL_KHR_texture_compression_astc_ldr */

#ifndef GL_KHR_texture_compression_astc_sliced_3d
#define GL_KHR_texture_compression_astc_sliced_3d 1
#endif /* GL_KHR_texture_compression_astc_sliced_3d */

#ifndef GL_AMD_performance_monitor
#define GL_AMD_performance_monitor 1
#define GL_COUNTER_TYPE_AMD               0x8BC0
#define GL_COUNTER_RANGE_AMD              0x8BC1
#define GL_UNSIGNED_INT64_AMD             0x8BC2
#define GL_PERCENTAGE_AMD                 0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD   0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD        0x8BC5
#define GL_PERFMON_RESULT_AMD             0x8BC6
typedef void (APIENTRYP PFN_zlgl_glGetPerfMonitorGroupsAMD)(GLint *numGroups, GLsizei groupsSize, GLuint *groups);
typedef void (APIENTRYP PFN_zlgl_glGetPerfMonitorCountersAMD)(GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
typedef void (APIENTRYP PFN_zlgl_glGetPerfMonitorGroupStringAMD)(GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
typedef void (APIENTRYP PFN_zlgl_glGetPerfMonitorCounterStringAMD)(GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
typedef void (APIENTRYP PFN_zlgl_glGetPerfMonitorCounterInfoAMD)(GLuint group, GLuint counter, GLenum pname, void *data);
typedef void (APIENTRYP PFN_zlgl_glGenPerfMonitorsAMD)(GLsizei n, GLuint *monitors);
typedef void (APIENTRYP PFN_zlgl_glDeletePerfMonitorsAMD)(GLsizei n, GLuint *monitors);
typedef void (APIENTRYP PFN_zlgl_glSelectPerfMonitorCountersAMD)(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
typedef void (APIENTRYP PFN_zlgl_glBeginPerfMonitorAMD)(GLuint monitor);
typedef void (APIENTRYP PFN_zlgl_glEndPerfMonitorAMD)(GLuint monitor);
typedef void (APIENTRYP PFN_zlgl_glGetPerfMonitorCounterDataAMD)(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);

ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfMonitorGroupsAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfMonitorCountersAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfMonitorGroupStringAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfMonitorCounterStringAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfMonitorCounterInfoAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenPerfMonitorsAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeletePerfMonitorsAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glSelectPerfMonitorCountersAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glBeginPerfMonitorAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glEndPerfMonitorAMD);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfMonitorCounterDataAMD);
#endif /* GL_AMD_performance_monitor */

#ifndef GL_APPLE_rgb_422
#define GL_APPLE_rgb_422 1
#define GL_RGB_422_APPLE                  0x8A1F
#define GL_UNSIGNED_SHORT_8_8_APPLE       0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE   0x85BB
#define GL_RGB_RAW_422_APPLE              0x8A51
#endif /* GL_APPLE_rgb_422 */

#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label 1
#define GL_PROGRAM_PIPELINE_OBJECT_EXT    0x8A4F
#define GL_PROGRAM_OBJECT_EXT             0x8B40
#define GL_SHADER_OBJECT_EXT              0x8B48
#define GL_BUFFER_OBJECT_EXT              0x9151
#define GL_QUERY_OBJECT_EXT               0x9153
#define GL_VERTEX_ARRAY_OBJECT_EXT        0x9154

typedef void (APIENTRYP PFN_zlgl_glLabelObjectEXT)(GLenum type, GLuint object, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFN_zlgl_glGetObjectLabelEXT)(GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);

ZLGL_DEFINE_OPENGL_FUNCTION(glLabelObjectEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetObjectLabelEXT);
#endif /* GL_EXT_debug_label */

#ifndef GL_EXT_debug_marker
#define GL_EXT_debug_marker 1
typedef void (APIENTRYP PFN_zlgl_glInsertEventMarkerEXT)(GLsizei length, const GLchar *marker);
typedef void (APIENTRYP PFN_zlgl_glPushGroupMarkerEXT)(GLsizei length, const GLchar *marker);
typedef void (APIENTRYP PFN_zlgl_glPopGroupMarkerEXT)(void);

ZLGL_DEFINE_OPENGL_FUNCTION(glInsertEventMarkerEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glPushGroupMarkerEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glPopGroupMarkerEXT);
#endif /* GL_EXT_debug_marker */

#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
#define GL_PROGRAM_MATRIX_EXT             0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT   0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
typedef void (APIENTRYP PFN_zlgl_glMatrixLoadfEXT)(GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixLoaddEXT)(GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixMultfEXT)(GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixMultdEXT)(GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixLoadIdentityEXT)(GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glMatrixRotatefEXT)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFN_zlgl_glMatrixRotatedEXT)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFN_zlgl_glMatrixScalefEXT)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFN_zlgl_glMatrixScaledEXT)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFN_zlgl_glMatrixTranslatefEXT)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFN_zlgl_glMatrixTranslatedEXT)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFN_zlgl_glMatrixFrustumEXT)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFN_zlgl_glMatrixOrthoEXT)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFN_zlgl_glMatrixPopEXT)(GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glMatrixPushEXT)(GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glClientAttribDefaultEXT)(GLbitfield mask);
typedef void (APIENTRYP PFN_zlgl_glPushClientAttribDefaultEXT)(GLbitfield mask);
typedef void (APIENTRYP PFN_zlgl_glTextureParameterfEXT)(GLuint texture, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFN_zlgl_glTextureParameterfvEXT)(GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glTextureParameteriEXT)(GLuint texture, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glTextureParameterivEXT)(GLuint texture, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glCopyTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFN_zlgl_glCopyTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFN_zlgl_glCopyTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFN_zlgl_glCopyTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glGetTextureImageEXT)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFN_zlgl_glGetTextureParameterfvEXT)(GLuint texture, GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureParameterivEXT)(GLuint texture, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureLevelParameterfvEXT)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureLevelParameterivEXT)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glTextureImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glCopyTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glBindMultiTextureEXT)(GLenum texunit, GLenum target, GLuint texture);
typedef void (APIENTRYP PFN_zlgl_glMultiTexCoordPointerEXT)(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFN_zlgl_glMultiTexEnvfEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFN_zlgl_glMultiTexEnvfvEXT)(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexEnviEXT)(GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glMultiTexEnvivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexGendEXT)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
typedef void (APIENTRYP PFN_zlgl_glMultiTexGendvEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexGenfEXT)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFN_zlgl_glMultiTexGenfvEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexGeniEXT)(GLenum texunit, GLenum coord, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glMultiTexGenivEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexEnvfvEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexEnvivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexGendvEXT)(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexGenfvEXT)(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexGenivEXT)(GLenum texunit, GLenum coord, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexParameteriEXT)(GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glMultiTexParameterivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexParameterfEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFN_zlgl_glMultiTexParameterfvEXT)(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glCopyMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFN_zlgl_glCopyMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFN_zlgl_glCopyMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFN_zlgl_glCopyMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexImageEXT)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexParameterfvEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexParameterivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexLevelParameterfvEXT)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexLevelParameterivEXT)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFN_zlgl_glCopyMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glEnableClientStateIndexedEXT)(GLenum array, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glDisableClientStateIndexedEXT)(GLenum array, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glGetFloatIndexedvEXT)(GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFN_zlgl_glGetDoubleIndexedvEXT)(GLenum target, GLuint index, GLdouble *data);
typedef void (APIENTRYP PFN_zlgl_glGetPointerIndexedvEXT)(GLenum target, GLuint index, void **data);
typedef void (APIENTRYP PFN_zlgl_glEnableIndexedEXT)(GLenum target, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glDisableIndexedEXT)(GLenum target, GLuint index);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsEnabledIndexedEXT)(GLenum target, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glGetIntegerIndexedvEXT)(GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFN_zlgl_glGetBooleanIndexedvEXT)(GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFN_zlgl_glCompressedTextureImage3DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glGetCompressedTextureImageEXT)(GLuint texture, GLenum target, GLint lod, void *img);
typedef void (APIENTRYP PFN_zlgl_glCompressedMultiTexImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glCompressedMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFN_zlgl_glGetCompressedMultiTexImageEXT)(GLenum texunit, GLenum target, GLint lod, void *img);
typedef void (APIENTRYP PFN_zlgl_glMatrixLoadTransposefEXT)(GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixLoadTransposedEXT)(GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixMultTransposefEXT)(GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixMultTransposedEXT)(GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFN_zlgl_glNamedBufferDataEXT)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFN_zlgl_glNamedBufferSubDataEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void *(APIENTRYP PFN_zlgl_glMapNamedBufferEXT)(GLuint buffer, GLenum access);
typedef GLboolean(APIENTRYP PFN_zlgl_glUnmapNamedBufferEXT)(GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glGetNamedBufferParameterivEXT)(GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedBufferPointervEXT)(GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedBufferSubDataEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1fEXT)(GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1iEXT)(GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2iEXT)(GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3iEXT)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4iEXT)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1ivEXT)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2ivEXT)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3ivEXT)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4ivEXT)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2x3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3x2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2x4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4x2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3x4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4x3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glTextureBufferEXT)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glMultiTexBufferEXT)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glTextureParameterIivEXT)(GLuint texture, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glTextureParameterIuivEXT)(GLuint texture, GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureParameterIivEXT)(GLuint texture, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetTextureParameterIuivEXT)(GLuint texture, GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexParameterIivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glMultiTexParameterIuivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexParameterIivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetMultiTexParameterIuivEXT)(GLenum texunit, GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1uiEXT)(GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParameters4fvEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParameterI4iEXT)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParameterI4ivEXT)(GLuint program, GLenum target, GLuint index, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParametersI4ivEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParameterI4uiEXT)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParameterI4uivEXT)(GLuint program, GLenum target, GLuint index, const GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParametersI4uivEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedProgramLocalParameterIivEXT)(GLuint program, GLenum target, GLuint index, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedProgramLocalParameterIuivEXT)(GLuint program, GLenum target, GLuint index, GLuint *params);
typedef void (APIENTRYP PFN_zlgl_glEnableClientStateiEXT)(GLenum array, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glDisableClientStateiEXT)(GLenum array, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glGetFloati_vEXT)(GLenum pname, GLuint index, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetDoublei_vEXT)(GLenum pname, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFN_zlgl_glGetPointeri_vEXT)(GLenum pname, GLuint index, void **params);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramStringEXT)(GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParameter4dEXT)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParameter4dvEXT)(GLuint program, GLenum target, GLuint index, const GLdouble *params);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParameter4fEXT)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFN_zlgl_glNamedProgramLocalParameter4fvEXT)(GLuint program, GLenum target, GLuint index, const GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedProgramLocalParameterdvEXT)(GLuint program, GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedProgramLocalParameterfvEXT)(GLuint program, GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedProgramivEXT)(GLuint program, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedProgramStringEXT)(GLuint program, GLenum target, GLenum pname, void *string);
typedef void (APIENTRYP PFN_zlgl_glNamedRenderbufferStorageEXT)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glGetNamedRenderbufferParameterivEXT)(GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glNamedRenderbufferStorageMultisampleEXT)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glNamedRenderbufferStorageMultisampleCoverageEXT)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef GLenum(APIENTRYP PFN_zlgl_glCheckNamedFramebufferStatusEXT)(GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferTexture1DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferTexture2DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferTexture3DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferRenderbufferEXT)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFN_zlgl_glGetNamedFramebufferAttachmentParameterivEXT)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glGenerateTextureMipmapEXT)(GLuint texture, GLenum target);
typedef void (APIENTRYP PFN_zlgl_glGenerateMultiTexMipmapEXT)(GLenum texunit, GLenum target);
typedef void (APIENTRYP PFN_zlgl_glFramebufferDrawBufferEXT)(GLuint framebuffer, GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glFramebufferDrawBuffersEXT)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFN_zlgl_glFramebufferReadBufferEXT)(GLuint framebuffer, GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glGetFramebufferParameterivEXT)(GLuint framebuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glNamedCopyBufferSubDataEXT)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferTextureEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferTextureLayerEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferTextureFaceEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
typedef void (APIENTRYP PFN_zlgl_glTextureRenderbufferEXT)(GLuint texture, GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFN_zlgl_glMultiTexRenderbufferEXT)(GLenum texunit, GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayColorOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayEdgeFlagOffsetEXT)(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayIndexOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayNormalOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayTexCoordOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayMultiTexCoordOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayFogCoordOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArraySecondaryColorOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexAttribOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexAttribIOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glEnableVertexArrayEXT)(GLuint vaobj, GLenum array);
typedef void (APIENTRYP PFN_zlgl_glDisableVertexArrayEXT)(GLuint vaobj, GLenum array);
typedef void (APIENTRYP PFN_zlgl_glEnableVertexArrayAttribEXT)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glDisableVertexArrayAttribEXT)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFN_zlgl_glGetVertexArrayIntegervEXT)(GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFN_zlgl_glGetVertexArrayPointervEXT)(GLuint vaobj, GLenum pname, void **param);
typedef void (APIENTRYP PFN_zlgl_glGetVertexArrayIntegeri_vEXT)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFN_zlgl_glGetVertexArrayPointeri_vEXT)(GLuint vaobj, GLuint index, GLenum pname, void **param);
typedef void *(APIENTRYP PFN_zlgl_glMapNamedBufferRangeEXT)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFN_zlgl_glFlushMappedNamedBufferRangeEXT)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFN_zlgl_glNamedBufferStorageEXT)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFN_zlgl_glClearNamedBufferDataEXT)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFN_zlgl_glClearNamedBufferSubDataEXT)(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferParameteriEXT)(GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFN_zlgl_glGetNamedFramebufferParameterivEXT)(GLuint framebuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1dEXT)(GLuint program, GLint location, GLdouble x);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2x3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix2x4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3x2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix3x4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4x2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformMatrix4x3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFN_zlgl_glTextureBufferRangeEXT)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage1DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage2DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage3DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage2DMultisampleEXT)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFN_zlgl_glTextureStorage3DMultisampleEXT)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayBindVertexBufferEXT)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexAttribFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexAttribIFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexAttribLFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexAttribBindingEXT)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexBindingDivisorEXT)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexAttribLOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFN_zlgl_glTexturePageCommitmentEXT)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
typedef void (APIENTRYP PFN_zlgl_glVertexArrayVertexAttribDivisorEXT)(GLuint vaobj, GLuint index, GLuint divisor);

ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixLoadfEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixLoaddEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixMultfEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixMultdEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixLoadIdentityEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixRotatefEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixRotatedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixScalefEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixScaledEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixTranslatefEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixTranslatedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixFrustumEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixOrthoEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixPopEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixPushEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glClientAttribDefaultEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glPushClientAttribDefaultEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameterfEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameterfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameteriEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureSubImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureSubImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTextureImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTextureImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTextureSubImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTextureSubImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureImageEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureParameterfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureLevelParameterfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureLevelParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureSubImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyTextureSubImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glBindMultiTextureEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexCoordPointerEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexEnvfEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexEnvfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexEnviEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexEnvivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexGendEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexGendvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexGenfEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexGenfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexGeniEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexGenivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexEnvfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexEnvivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexGendvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexGenfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexGenivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexParameteriEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexParameterfEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexParameterfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexSubImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexSubImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyMultiTexImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyMultiTexImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyMultiTexSubImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyMultiTexSubImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexImageEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexParameterfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexLevelParameterfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexLevelParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexSubImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyMultiTexSubImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glEnableClientStateIndexedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glDisableClientStateIndexedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFloatIndexedvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetDoubleIndexedvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPointerIndexedvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glEnableIndexedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glDisableIndexedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsEnabledIndexedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetIntegerIndexedvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetBooleanIndexedvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTextureImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTextureImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTextureImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTextureSubImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTextureSubImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedTextureSubImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetCompressedTextureImageEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedMultiTexImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedMultiTexImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedMultiTexImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedMultiTexSubImage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedMultiTexSubImage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompressedMultiTexSubImage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetCompressedMultiTexImageEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixLoadTransposefEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixLoadTransposedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixMultTransposefEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixMultTransposedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedBufferDataEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedBufferSubDataEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMapNamedBufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glUnmapNamedBufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedBufferParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedBufferPointervEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedBufferSubDataEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1fEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2fEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3fEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4fEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1iEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2iEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3iEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4iEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1ivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2ivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3ivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4ivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2x3fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3x2fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2x4fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4x2fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3x4fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4x3fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureBufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexBufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameterIivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureParameterIuivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureParameterIivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureParameterIuivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexParameterIivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexParameterIuivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexParameterIivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetMultiTexParameterIuivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1uiEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2uiEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3uiEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4uiEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1uivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2uivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3uivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4uivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParameters4fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParameterI4iEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParameterI4ivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParametersI4ivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParameterI4uiEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParameterI4uivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParametersI4uivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedProgramLocalParameterIivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedProgramLocalParameterIuivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glEnableClientStateiEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glDisableClientStateiEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFloati_vEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetDoublei_vEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPointeri_vEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramStringEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParameter4dEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParameter4dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParameter4fEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedProgramLocalParameter4fvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedProgramLocalParameterdvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedProgramLocalParameterfvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedProgramivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedProgramStringEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedRenderbufferStorageEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedRenderbufferParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedRenderbufferStorageMultisampleEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedRenderbufferStorageMultisampleCoverageEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCheckNamedFramebufferStatusEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferTexture1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferTexture2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferTexture3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferRenderbufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedFramebufferAttachmentParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenerateTextureMipmapEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGenerateMultiTexMipmapEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferDrawBufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferDrawBuffersEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferReadBufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFramebufferParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedCopyBufferSubDataEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferTextureEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferTextureLayerEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferTextureFaceEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureRenderbufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiTexRenderbufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayColorOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayEdgeFlagOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayIndexOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayNormalOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayTexCoordOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayMultiTexCoordOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayFogCoordOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArraySecondaryColorOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexAttribOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexAttribIOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glEnableVertexArrayEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glDisableVertexArrayEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glEnableVertexArrayAttribEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glDisableVertexArrayAttribEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexArrayIntegervEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexArrayPointervEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexArrayIntegeri_vEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexArrayPointeri_vEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glMapNamedBufferRangeEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glFlushMappedNamedBufferRangeEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedBufferStorageEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearNamedBufferDataEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glClearNamedBufferSubDataEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferParameteriEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedFramebufferParameterivEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1dEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2dEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3dEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4dEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2x3dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix2x4dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3x2dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix3x4dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4x2dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformMatrix4x3dvEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureBufferRangeEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage1DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage2DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage3DEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage2DMultisampleEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureStorage3DMultisampleEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayBindVertexBufferEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexAttribFormatEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexAttribIFormatEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexAttribLFormatEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexAttribBindingEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexBindingDivisorEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexAttribLOffsetEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexturePageCommitmentEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexArrayVertexAttribDivisorEXT);
#endif /* GL_EXT_direct_state_access */

#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
typedef void (APIENTRYP PFN_zlgl_glDrawArraysInstancedEXT)(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFN_zlgl_glDrawElementsInstancedEXT)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);

ZLGL_DEFINE_OPENGL_FUNCTION(glDrawArraysInstancedEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawElementsInstancedEXT);
#endif /* GL_EXT_draw_instanced */

#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1
#define GL_POLYGON_OFFSET_CLAMP_EXT       0x8E1B
typedef void (APIENTRYP PFN_zlgl_glPolygonOffsetClampEXT)(GLfloat factor, GLfloat units, GLfloat clamp);

ZLGL_DEFINE_OPENGL_FUNCTION(glPolygonOffsetClampEXT);
#endif /* GL_EXT_polygon_offset_clamp */

#ifndef GL_EXT_post_depth_coverage
#define GL_EXT_post_depth_coverage 1
#endif /* GL_EXT_post_depth_coverage */

#ifndef GL_EXT_raster_multisample
#define GL_EXT_raster_multisample 1
#define GL_RASTER_MULTISAMPLE_EXT         0x9327
#define GL_RASTER_SAMPLES_EXT             0x9328
#define GL_MAX_RASTER_SAMPLES_EXT         0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT 0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT 0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT   0x932C
typedef void (APIENTRYP PFN_zlgl_glRasterSamplesEXT)(GLuint samples, GLboolean fixedsamplelocations);

ZLGL_DEFINE_OPENGL_FUNCTION(glRasterSamplesEXT);
#endif /* GL_EXT_raster_multisample */

#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1
#define GL_ACTIVE_PROGRAM_EXT             0x8B8D
typedef void (APIENTRYP PFN_zlgl_glUseShaderProgramEXT)(GLenum type, GLuint program);
typedef void (APIENTRYP PFN_zlgl_glActiveProgramEXT)(GLuint program);
typedef GLuint(APIENTRYP PFN_zlgl_glCreateShaderProgramEXT)(GLenum type, const GLchar *string);

ZLGL_DEFINE_OPENGL_FUNCTION(glUseShaderProgramEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glActiveProgramEXT);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateShaderProgramEXT);
#endif /* GL_EXT_separate_shader_objects */

#ifndef GL_EXT_shader_integer_mix
#define GL_EXT_shader_integer_mix 1
#endif /* GL_EXT_shader_integer_mix */

#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  0x83F3
#endif /* GL_EXT_texture_compression_s3tc */

#ifndef GL_EXT_texture_filter_anisotropic
#define GL_EXT_texture_filter_anisotropic 1
#define GL_TEXTURE_MAX_ANISOTROPY_EXT     0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
#endif /* GL_EXT_texture_filter_anisotropic */

#ifndef GL_EXT_texture_filter_minmax
#define GL_EXT_texture_filter_minmax 1
#endif /* GL_EXT_texture_filter_minmax */

#ifndef GL_EXT_texture_sRGB_decode
#define GL_EXT_texture_sRGB_decode 1
#define GL_TEXTURE_SRGB_DECODE_EXT        0x8A48
#define GL_DECODE_EXT                     0x8A49
#define GL_SKIP_DECODE_EXT                0x8A4A
#endif /* GL_EXT_texture_sRGB_decode */

#ifndef GL_EXT_window_rectangles
#define GL_EXT_window_rectangles 1
#define GL_INCLUSIVE_EXT                  0x8F10
#define GL_EXCLUSIVE_EXT                  0x8F11
#define GL_WINDOW_RECTANGLE_EXT           0x8F12
#define GL_WINDOW_RECTANGLE_MODE_EXT      0x8F13
#define GL_MAX_WINDOW_RECTANGLES_EXT      0x8F14
#define GL_NUM_WINDOW_RECTANGLES_EXT      0x8F15
typedef void (APIENTRYP PFN_zlgl_glWindowRectanglesEXT)(GLenum mode, GLsizei count, const GLint *box);

ZLGL_DEFINE_OPENGL_FUNCTION(glWindowRectanglesEXT);
#endif /* GL_EXT_window_rectangles */

#ifndef GL_INTEL_conservative_rasterization
#define GL_INTEL_conservative_rasterization 1
#define GL_CONSERVATIVE_RASTERIZATION_INTEL 0x83FE
#endif /* GL_INTEL_conservative_rasterization */

#ifndef GL_INTEL_framebuffer_CMAA
#define GL_INTEL_framebuffer_CMAA 1
typedef void (APIENTRYP PFN_zlgl_glApplyFramebufferAttachmentCMAAINTEL)(void);

ZLGL_DEFINE_OPENGL_FUNCTION(glApplyFramebufferAttachmentCMAAINTEL);
#endif /* GL_INTEL_framebuffer_CMAA */

#ifndef GL_INTEL_performance_query
#define GL_INTEL_performance_query 1
#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL 0x00000000
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL 0x00000001
#define GL_PERFQUERY_WAIT_INTEL           0x83FB
#define GL_PERFQUERY_FLUSH_INTEL          0x83FA
#define GL_PERFQUERY_DONOT_FLUSH_INTEL    0x83F9
#define GL_PERFQUERY_COUNTER_EVENT_INTEL  0x94F0
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL 0x94F1
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL 0x94F2
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL 0x94F3
#define GL_PERFQUERY_COUNTER_RAW_INTEL    0x94F4
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL 0x94F5
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL 0x94F8
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL 0x94F9
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL 0x94FA
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL 0x94FB
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL 0x94FC
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL 0x94FD
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL 0x94FE
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL 0x94FF
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL 0x9500

typedef void (APIENTRYP PFN_zlgl_glBeginPerfQueryINTEL)(GLuint queryHandle);
typedef void (APIENTRYP PFN_zlgl_glCreatePerfQueryINTEL)(GLuint queryId, GLuint *queryHandle);
typedef void (APIENTRYP PFN_zlgl_glDeletePerfQueryINTEL)(GLuint queryHandle);
typedef void (APIENTRYP PFN_zlgl_glEndPerfQueryINTEL)(GLuint queryHandle);
typedef void (APIENTRYP PFN_zlgl_glGetFirstPerfQueryIdINTEL)(GLuint *queryId);
typedef void (APIENTRYP PFN_zlgl_glGetNextPerfQueryIdINTEL)(GLuint queryId, GLuint *nextQueryId);
typedef void (APIENTRYP PFN_zlgl_glGetPerfCounterInfoINTEL)(GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
typedef void (APIENTRYP PFN_zlgl_glGetPerfQueryDataINTEL)(GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid *data, GLuint *bytesWritten);
typedef void (APIENTRYP PFN_zlgl_glGetPerfQueryIdByNameINTEL)(GLchar *queryName, GLuint *queryId);
typedef void (APIENTRYP PFN_zlgl_glGetPerfQueryInfoINTEL)(GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);

ZLGL_DEFINE_OPENGL_FUNCTION(glBeginPerfQueryINTEL);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreatePerfQueryINTEL);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeletePerfQueryINTEL);
ZLGL_DEFINE_OPENGL_FUNCTION(glEndPerfQueryINTEL);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetFirstPerfQueryIdINTEL);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNextPerfQueryIdINTEL);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfCounterInfoINTEL);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfQueryDataINTEL);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfQueryIdByNameINTEL);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPerfQueryInfoINTEL);

#endif /* GL_INTEL_performance_query */

#ifndef GL_NV_bindless_multi_draw_indirect
#define GL_NV_bindless_multi_draw_indirect 1
typedef void (APIENTRYP PFN_zlgl_glMultiDrawArraysIndirectBindlessNV)(GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFN_zlgl_glMultiDrawElementsIndirectBindlessNV)(GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);

ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawArraysIndirectBindlessNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawElementsIndirectBindlessNV);
#endif /* GL_NV_bindless_multi_draw_indirect */

#ifndef GL_NV_bindless_multi_draw_indirect_count
#define GL_NV_bindless_multi_draw_indirect_count 1
typedef void (APIENTRYP PFN_zlgl_glMultiDrawArraysIndirectBindlessCountNV)(GLenum mode, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFN_zlgl_glMultiDrawElementsIndirectBindlessCountNV)(GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);

ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawArraysIndirectBindlessCountNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMultiDrawElementsIndirectBindlessCountNV);
#endif /* GL_NV_bindless_multi_draw_indirect_count */

#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture 1
typedef GLuint64 (APIENTRYP PFN_zlgl_glGetTextureHandleNV)(GLuint texture);
typedef GLuint64 (APIENTRYP PFN_zlgl_glGetTextureSamplerHandleNV)(GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFN_zlgl_glMakeTextureHandleResidentNV)(GLuint64 handle);
typedef void (APIENTRYP PFN_zlgl_glMakeTextureHandleNonResidentNV)(GLuint64 handle);
typedef GLuint64 (APIENTRYP PFN_zlgl_glGetImageHandleNV)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFN_zlgl_glMakeImageHandleResidentNV)(GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFN_zlgl_glMakeImageHandleNonResidentNV)(GLuint64 handle);
typedef void (APIENTRYP PFN_zlgl_glUniformHandleui64NV)(GLint location, GLuint64 value);
typedef void (APIENTRYP PFN_zlgl_glUniformHandleui64vNV)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformHandleui64NV)(GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformHandleui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
typedef GLboolean (APIENTRYP PFN_zlgl_glIsTextureHandleResidentNV)(GLuint64 handle);
typedef GLboolean (APIENTRYP PFN_zlgl_glIsImageHandleResidentNV)(GLuint64 handle);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureHandleNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetTextureSamplerHandleNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeTextureHandleResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeTextureHandleNonResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetImageHandleNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeImageHandleResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeImageHandleNonResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformHandleui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformHandleui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformHandleui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformHandleui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsTextureHandleResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsImageHandleResidentNV);
#endif /* GL_NV_bindless_texture */

#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced 1
#define GL_BLEND_OVERLAP_NV               0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV     0x9280
#define GL_BLUE_NV                        0x1905
#define GL_COLORBURN_NV                   0x929A
#define GL_COLORDODGE_NV                  0x9299
#define GL_CONJOINT_NV                    0x9284
#define GL_CONTRAST_NV                    0x92A1
#define GL_DARKEN_NV                      0x9297
#define GL_DIFFERENCE_NV                  0x929E
#define GL_DISJOINT_NV                    0x9283
#define GL_DST_ATOP_NV                    0x928F
#define GL_DST_IN_NV                      0x928B
#define GL_DST_NV                         0x9287
#define GL_DST_OUT_NV                     0x928D
#define GL_DST_OVER_NV                    0x9289
#define GL_EXCLUSION_NV                   0x92A0
#define GL_GREEN_NV                       0x1904
#define GL_HARDLIGHT_NV                   0x929B
#define GL_HARDMIX_NV                     0x92A9
#define GL_HSL_COLOR_NV                   0x92AF
#define GL_HSL_HUE_NV                     0x92AD
#define GL_HSL_LUMINOSITY_NV              0x92B0
#define GL_HSL_SATURATION_NV              0x92AE
#define GL_INVERT_OVG_NV                  0x92B4
#define GL_INVERT_RGB_NV                  0x92A3
#define GL_LIGHTEN_NV                     0x9298
#define GL_LINEARBURN_NV                  0x92A5
#define GL_LINEARDODGE_NV                 0x92A4
#define GL_LINEARLIGHT_NV                 0x92A7
#define GL_MINUS_CLAMPED_NV               0x92B3
#define GL_MINUS_NV                       0x929F
#define GL_MULTIPLY_NV                    0x9294
#define GL_OVERLAY_NV                     0x9296
#define GL_PINLIGHT_NV                    0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV          0x92B2
#define GL_PLUS_CLAMPED_NV                0x92B1
#define GL_PLUS_DARKER_NV                 0x9292
#define GL_PLUS_NV                        0x9291
#define GL_RED_NV                         0x1903
#define GL_SCREEN_NV                      0x9295
#define GL_SOFTLIGHT_NV                   0x929C
#define GL_SRC_ATOP_NV                    0x928E
#define GL_SRC_IN_NV                      0x928A
#define GL_SRC_NV                         0x9286
#define GL_SRC_OUT_NV                     0x928C
#define GL_SRC_OVER_NV                    0x9288
#define GL_UNCORRELATED_NV                0x9282
#define GL_VIVIDLIGHT_NV                  0x92A6
#define GL_XOR_NV                         0x1506
typedef void (APIENTRYP PFN_zlgl_glBlendParameteriNV)(GLenum pname, GLint value);
typedef void (APIENTRYP PFN_zlgl_glBlendBarrierNV)(void);

ZLGL_DEFINE_OPENGL_FUNCTION(glBlendParameteriNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glBlendBarrierNV);
#endif /* GL_NV_blend_equation_advanced */

#ifndef GL_NV_blend_equation_advanced_coherent
#define GL_NV_blend_equation_advanced_coherent 1
#define GL_BLEND_ADVANCED_COHERENT_NV     0x9285
#endif /* GL_NV_blend_equation_advanced_coherent */

#ifndef GL_NV_clip_space_w_scaling
#define GL_NV_clip_space_w_scaling 1
#define GL_VIEWPORT_POSITION_W_SCALE_NV   0x937C
#define GL_VIEWPORT_POSITION_W_SCALE_X_COEFF_NV 0x937D
#define GL_VIEWPORT_POSITION_W_SCALE_Y_COEFF_NV 0x937E
typedef void (APIENTRYP PFN_zlgl_glViewportPositionWScaleNV)(GLuint index, GLfloat xcoeff, GLfloat ycoeff);

ZLGL_DEFINE_OPENGL_FUNCTION(glViewportPositionWScaleNV);
#endif /* GL_NV_clip_space_w_scaling */

#ifndef GL_NV_command_list
#define GL_NV_command_list 1
#define GL_TERMINATE_SEQUENCE_COMMAND_NV  0x0000
#define GL_NOP_COMMAND_NV                 0x0001
#define GL_DRAW_ELEMENTS_COMMAND_NV       0x0002
#define GL_DRAW_ARRAYS_COMMAND_NV         0x0003
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV 0x0004
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV   0x0005
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV 0x0006
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV 0x0007
#define GL_ELEMENT_ADDRESS_COMMAND_NV     0x0008
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV   0x0009
#define GL_UNIFORM_ADDRESS_COMMAND_NV     0x000A
#define GL_BLEND_COLOR_COMMAND_NV         0x000B
#define GL_STENCIL_REF_COMMAND_NV         0x000C
#define GL_LINE_WIDTH_COMMAND_NV          0x000D
#define GL_POLYGON_OFFSET_COMMAND_NV      0x000E
#define GL_ALPHA_REF_COMMAND_NV           0x000F
#define GL_VIEWPORT_COMMAND_NV            0x0010
#define GL_SCISSOR_COMMAND_NV             0x0011
#define GL_FRONT_FACE_COMMAND_NV          0x0012
typedef void (APIENTRYP PFN_zlgl_glCreateStatesNV)(GLsizei n, GLuint *states);
typedef void (APIENTRYP PFN_zlgl_glDeleteStatesNV)(GLsizei n, const GLuint *states);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsStateNV)(GLuint state);
typedef void (APIENTRYP PFN_zlgl_glStateCaptureNV)(GLuint state, GLenum mode);
typedef GLuint(APIENTRYP PFN_zlgl_glGetCommandHeaderNV)(GLenum tokenID, GLuint size);
typedef GLushort(APIENTRYP PFN_zlgl_glGetStageIndexNV)(GLenum shadertype);
typedef void (APIENTRYP PFN_zlgl_glDrawCommandsNV)(GLenum primitiveMode, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, GLuint count);
typedef void (APIENTRYP PFN_zlgl_glDrawCommandsAddressNV)(GLenum primitiveMode, const GLuint64 *indirects, const GLsizei *sizes, GLuint count);
typedef void (APIENTRYP PFN_zlgl_glDrawCommandsStatesNV)(GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
typedef void (APIENTRYP PFN_zlgl_glDrawCommandsStatesAddressNV)(const GLuint64 *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
typedef void (APIENTRYP PFN_zlgl_glCreateCommandListsNV)(GLsizei n, GLuint *lists);
typedef void (APIENTRYP PFN_zlgl_glDeleteCommandListsNV)(GLsizei n, const GLuint *lists);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsCommandListNV)(GLuint list);
typedef void (APIENTRYP PFN_zlgl_glListDrawCommandsStatesClientNV)(GLuint list, GLuint segment, const void **indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
typedef void (APIENTRYP PFN_zlgl_glCommandListSegmentsNV)(GLuint list, GLuint segments);
typedef void (APIENTRYP PFN_zlgl_glCompileCommandListNV)(GLuint list);
typedef void (APIENTRYP PFN_zlgl_glCallCommandListNV)(GLuint list);

ZLGL_DEFINE_OPENGL_FUNCTION(glCreateStatesNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteStatesNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsStateNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glStateCaptureNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetCommandHeaderNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetStageIndexNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawCommandsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawCommandsAddressNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawCommandsStatesNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glDrawCommandsStatesAddressNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCreateCommandListsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeleteCommandListsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsCommandListNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glListDrawCommandsStatesClientNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCommandListSegmentsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCompileCommandListNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCallCommandListNV);
#endif /* GL_NV_command_list */

#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
#define GL_QUERY_WAIT_NV                  0x8E13
#define GL_QUERY_NO_WAIT_NV               0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV        0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV     0x8E16
typedef void (APIENTRYP PFN_zlgl_glBeginConditionalRenderNV)(GLuint id, GLenum mode);
typedef void (APIENTRYP PFN_zlgl_glEndConditionalRenderNV)(void);

ZLGL_DEFINE_OPENGL_FUNCTION(glBeginConditionalRenderNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glEndConditionalRenderNV);
#endif /* GL_NV_conditional_render */

#ifndef GL_NV_conservative_raster
#define GL_NV_conservative_raster 1
#define GL_CONSERVATIVE_RASTERIZATION_NV  0x9346
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV 0x9347
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV 0x9348
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV 0x9349
typedef void (APIENTRYP PFN_zlgl_glSubpixelPrecisionBiasNV)(GLuint xbits, GLuint ybits);

ZLGL_DEFINE_OPENGL_FUNCTION(glSubpixelPrecisionBiasNV);
#endif /* GL_NV_conservative_raster */

#ifndef GL_NV_conservative_raster_dilate
#define GL_NV_conservative_raster_dilate 1
#define GL_CONSERVATIVE_RASTER_DILATE_NV  0x9379
#define GL_CONSERVATIVE_RASTER_DILATE_RANGE_NV 0x937A
#define GL_CONSERVATIVE_RASTER_DILATE_GRANULARITY_NV 0x937B
typedef void (APIENTRYP PFN_zlgl_glConservativeRasterParameterfNV)(GLenum pname, GLfloat value);

ZLGL_DEFINE_OPENGL_FUNCTION(glConservativeRasterParameterfNV);
#endif /* GL_NV_conservative_raster_dilate */

#ifndef GL_NV_conservative_raster_pre_snap_triangles
#define GL_NV_conservative_raster_pre_snap_triangles 1
#define GL_CONSERVATIVE_RASTER_MODE_NV    0x954D
#define GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV 0x954E
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV 0x954F
typedef void (APIENTRYP PFN_zlgl_glConservativeRasterParameteriNV)(GLenum pname, GLint param);

ZLGL_DEFINE_OPENGL_FUNCTION(glConservativeRasterParameteriNV);
#endif /* GL_NV_conservative_raster_pre_snap_triangles */

#ifndef GL_NV_draw_vulkan_image
#define GL_NV_draw_vulkan_image 1
typedef void (APIENTRYP  *GLVULKANPROCNV)(void);
typedef void (APIENTRYP PFN_zlgl_glDrawVkImageNV)(GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
typedef GLVULKANPROCNV(APIENTRYP PFN_zlgl_glGetVkProcAddrNV)(const GLchar *name);
typedef void (APIENTRYP PFN_zlgl_glWaitVkSemaphoreNV)(GLuint64 vkSemaphore);
typedef void (APIENTRYP PFN_zlgl_glSignalVkSemaphoreNV)(GLuint64 vkSemaphore);
typedef void (APIENTRYP PFN_zlgl_glSignalVkFenceNV)(GLuint64 vkFence);

ZLGL_DEFINE_OPENGL_FUNCTION(glDrawVkImageNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVkProcAddrNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glWaitVkSemaphoreNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glSignalVkSemaphoreNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glSignalVkFenceNV);
#endif /* GL_NV_draw_vulkan_image */

#ifndef GL_NV_fill_rectangle
#define GL_NV_fill_rectangle 1
#define GL_FILL_RECTANGLE_NV              0x933C
#endif /* GL_NV_fill_rectangle */

#ifndef GL_NV_fragment_coverage_to_color
#define GL_NV_fragment_coverage_to_color 1
#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV  0x92DD
#define GL_FRAGMENT_COVERAGE_COLOR_NV     0x92DE
typedef void (APIENTRYP PFN_zlgl_glFragmentCoverageColorNV)(GLuint color);

ZLGL_DEFINE_OPENGL_FUNCTION(glFragmentCoverageColorNV);
#endif /* GL_NV_fragment_coverage_to_color */

#ifndef GL_NV_fragment_shader_interlock
#define GL_NV_fragment_shader_interlock 1
#endif /* GL_NV_fragment_shader_interlock */

#ifndef GL_NV_framebuffer_mixed_samples
#define GL_NV_framebuffer_mixed_samples 1
#define GL_COVERAGE_MODULATION_TABLE_NV   0x9331
#define GL_COLOR_SAMPLES_NV               0x8E20
#define GL_DEPTH_SAMPLES_NV               0x932D
#define GL_STENCIL_SAMPLES_NV             0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV 0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV 0x9330
#define GL_COVERAGE_MODULATION_NV         0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV 0x9333
typedef void (APIENTRYP PFN_zlgl_glCoverageModulationTableNV)(GLsizei n, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glGetCoverageModulationTableNV)(GLsizei bufsize, GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glCoverageModulationNV)(GLenum components);

ZLGL_DEFINE_OPENGL_FUNCTION(glCoverageModulationTableNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetCoverageModulationTableNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCoverageModulationNV);
#endif /* GL_NV_framebuffer_mixed_samples */

#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV  0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV  0x8E12
typedef void (APIENTRYP PFN_zlgl_glRenderbufferStorageMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);

ZLGL_DEFINE_OPENGL_FUNCTION(glRenderbufferStorageMultisampleCoverageNV);
#endif /* GL_NV_framebuffer_multisample_coverage */

#ifndef GL_NV_geometry_shader_passthrough
#define GL_NV_geometry_shader_passthrough 1
#endif /* GL_NV_geometry_shader_passthrough */

#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1
	typedef int64_t GLint64EXT;
#define GL_INT64_NV                       0x140E
#define GL_UNSIGNED_INT64_NV              0x140F
#define GL_INT8_NV                        0x8FE0
#define GL_INT8_VEC2_NV                   0x8FE1
#define GL_INT8_VEC3_NV                   0x8FE2
#define GL_INT8_VEC4_NV                   0x8FE3
#define GL_INT16_NV                       0x8FE4
#define GL_INT16_VEC2_NV                  0x8FE5
#define GL_INT16_VEC3_NV                  0x8FE6
#define GL_INT16_VEC4_NV                  0x8FE7
#define GL_INT64_VEC2_NV                  0x8FE9
#define GL_INT64_VEC3_NV                  0x8FEA
#define GL_INT64_VEC4_NV                  0x8FEB
#define GL_UNSIGNED_INT8_NV               0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV          0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV          0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV          0x8FEF
#define GL_UNSIGNED_INT16_NV              0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV         0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV         0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV         0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV         0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV         0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV         0x8FF7
#define GL_FLOAT16_NV                     0x8FF8
#define GL_FLOAT16_VEC2_NV                0x8FF9
#define GL_FLOAT16_VEC3_NV                0x8FFA
#define GL_FLOAT16_VEC4_NV                0x8FFB
typedef void (APIENTRYP PFN_zlgl_glUniform1i64NV)(GLint location, GLint64EXT x);
typedef void (APIENTRYP PFN_zlgl_glUniform2i64NV)(GLint location, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFN_zlgl_glUniform3i64NV)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFN_zlgl_glUniform4i64NV)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFN_zlgl_glUniform1i64vNV)(GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glUniform2i64vNV)(GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glUniform3i64vNV)(GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glUniform4i64vNV)(GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glUniform1ui64NV)(GLint location, GLuint64EXT x);
typedef void (APIENTRYP PFN_zlgl_glUniform2ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFN_zlgl_glUniform3ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFN_zlgl_glUniform4ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFN_zlgl_glUniform1ui64vNV)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glUniform2ui64vNV)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glUniform3ui64vNV)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glUniform4ui64vNV)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glGetUniformi64vNV)(GLuint program, GLint location, GLint64EXT *params);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1i64NV)(GLuint program, GLint location, GLint64EXT x);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1ui64NV)(GLuint program, GLint location, GLuint64EXT x);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform1ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform2ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform3ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniform4ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);

ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1i64NV) ;
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2i64NV) ;
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3i64NV) ;
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4i64NV) ;
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform1ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform2ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform3ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniform4ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformi64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1i64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2i64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3i64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4i64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform1ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform2ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform3ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniform4ui64vNV);
#endif /* GL_NV_gpu_shader5 */

#ifndef GL_NV_internalformat_sample_query
#define GL_NV_internalformat_sample_query 1
#define GL_MULTISAMPLES_NV                0x9371
#define GL_SUPERSAMPLE_SCALE_X_NV         0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV         0x9373
#define GL_CONFORMANT_NV                  0x9374
typedef void (APIENTRYP PFN_zlgl_glGetInternalformatSampleivNV)(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetInternalformatSampleivNV);
#endif /* GL_NV_internalformat_sample_query */

#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1
#define GL_PATH_FORMAT_SVG_NV             0x9070
#define GL_PATH_FORMAT_PS_NV              0x9071
#define GL_STANDARD_FONT_NAME_NV          0x9072
#define GL_SYSTEM_FONT_NAME_NV            0x9073
#define GL_FILE_NAME_NV                   0x9074
#define GL_PATH_STROKE_WIDTH_NV           0x9075
#define GL_PATH_END_CAPS_NV               0x9076
#define GL_PATH_INITIAL_END_CAP_NV        0x9077
#define GL_PATH_TERMINAL_END_CAP_NV       0x9078
#define GL_PATH_JOIN_STYLE_NV             0x9079
#define GL_PATH_MITER_LIMIT_NV            0x907A
#define GL_PATH_DASH_CAPS_NV              0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV       0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV      0x907D
#define GL_PATH_DASH_OFFSET_NV            0x907E
#define GL_PATH_CLIENT_LENGTH_NV          0x907F
#define GL_PATH_FILL_MODE_NV              0x9080
#define GL_PATH_FILL_MASK_NV              0x9081
#define GL_PATH_FILL_COVER_MODE_NV        0x9082
#define GL_PATH_STROKE_COVER_MODE_NV      0x9083
#define GL_PATH_STROKE_MASK_NV            0x9084
#define GL_COUNT_UP_NV                    0x9088
#define GL_COUNT_DOWN_NV                  0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV    0x908A
#define GL_CONVEX_HULL_NV                 0x908B
#define GL_BOUNDING_BOX_NV                0x908D
#define GL_TRANSLATE_X_NV                 0x908E
#define GL_TRANSLATE_Y_NV                 0x908F
#define GL_TRANSLATE_2D_NV                0x9090
#define GL_TRANSLATE_3D_NV                0x9091
#define GL_AFFINE_2D_NV                   0x9092
#define GL_AFFINE_3D_NV                   0x9094
#define GL_TRANSPOSE_AFFINE_2D_NV         0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV         0x9098
#define GL_UTF8_NV                        0x909A
#define GL_UTF16_NV                       0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_PATH_COMMAND_COUNT_NV          0x909D
#define GL_PATH_COORD_COUNT_NV            0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV       0x909F
#define GL_PATH_COMPUTED_LENGTH_NV        0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV      0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV    0x90A2
#define GL_SQUARE_NV                      0x90A3
#define GL_ROUND_NV                       0x90A4
#define GL_TRIANGULAR_NV                  0x90A5
#define GL_BEVEL_NV                       0x90A6
#define GL_MITER_REVERT_NV                0x90A7
#define GL_MITER_TRUNCATE_NV              0x90A8
#define GL_SKIP_MISSING_GLYPH_NV          0x90A9
#define GL_USE_MISSING_GLYPH_NV           0x90AA
#define GL_PATH_ERROR_POSITION_NV         0x90AB
#define GL_ACCUM_ADJACENT_PAIRS_NV        0x90AD
#define GL_ADJACENT_PAIRS_NV              0x90AE
#define GL_FIRST_TO_REST_NV               0x90AF
#define GL_PATH_GEN_MODE_NV               0x90B0
#define GL_PATH_GEN_COEFF_NV              0x90B1
#define GL_PATH_GEN_COMPONENTS_NV         0x90B3
#define GL_PATH_STENCIL_FUNC_NV           0x90B7
#define GL_PATH_STENCIL_REF_NV            0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV     0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV       0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV      0x90B4
#define GL_MOVE_TO_RESETS_NV              0x90B5
#define GL_MOVE_TO_CONTINUES_NV           0x90B6
#define GL_CLOSE_PATH_NV                  0x00
#define GL_MOVE_TO_NV                     0x02
#define GL_RELATIVE_MOVE_TO_NV            0x03
#define GL_LINE_TO_NV                     0x04
#define GL_RELATIVE_LINE_TO_NV            0x05
#define GL_HORIZONTAL_LINE_TO_NV          0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_VERTICAL_LINE_TO_NV            0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV   0x09
#define GL_QUADRATIC_CURVE_TO_NV          0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_CUBIC_CURVE_TO_NV              0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV     0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV   0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV       0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_SMALL_CCW_ARC_TO_NV            0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV   0x13
#define GL_SMALL_CW_ARC_TO_NV             0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV    0x15
#define GL_LARGE_CCW_ARC_TO_NV            0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV   0x17
#define GL_LARGE_CW_ARC_TO_NV             0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV    0x19
#define GL_RESTART_PATH_NV                0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV    0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV     0xF4
#define GL_RECT_NV                        0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV         0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV          0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV     0xFC
#define GL_ARC_TO_NV                      0xFE
#define GL_RELATIVE_ARC_TO_NV             0xFF
#define GL_BOLD_BIT_NV                    0x01
#define GL_ITALIC_BIT_NV                  0x02
#define GL_GLYPH_WIDTH_BIT_NV             0x01
#define GL_GLYPH_HEIGHT_BIT_NV            0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_HAS_KERNING_BIT_NV       0x100
#define GL_FONT_X_MIN_BOUNDS_BIT_NV       0x00010000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV       0x00020000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV       0x00040000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV       0x00080000
#define GL_FONT_UNITS_PER_EM_BIT_NV       0x00100000
#define GL_FONT_ASCENDER_BIT_NV           0x00200000
#define GL_FONT_DESCENDER_BIT_NV          0x00400000
#define GL_FONT_HEIGHT_BIT_NV             0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV  0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_FONT_HAS_KERNING_BIT_NV        0x10000000
#define GL_ROUNDED_RECT_NV                0xE8
#define GL_RELATIVE_ROUNDED_RECT_NV       0xE9
#define GL_ROUNDED_RECT2_NV               0xEA
#define GL_RELATIVE_ROUNDED_RECT2_NV      0xEB
#define GL_ROUNDED_RECT4_NV               0xEC
#define GL_RELATIVE_ROUNDED_RECT4_NV      0xED
#define GL_ROUNDED_RECT8_NV               0xEE
#define GL_RELATIVE_ROUNDED_RECT8_NV      0xEF
#define GL_RELATIVE_RECT_NV               0xF7
#define GL_FONT_GLYPHS_AVAILABLE_NV       0x9368
#define GL_FONT_TARGET_UNAVAILABLE_NV     0x9369
#define GL_FONT_UNAVAILABLE_NV            0x936A
#define GL_FONT_UNINTELLIGIBLE_NV         0x936B
#define GL_CONIC_CURVE_TO_NV              0x1A
#define GL_RELATIVE_CONIC_CURVE_TO_NV     0x1B
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV  0x20000000
#define GL_STANDARD_FONT_FORMAT_NV        0x936C
#define GL_PATH_PROJECTION_NV             0x1701
#define GL_PATH_MODELVIEW_NV              0x1700
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV  0x0BA3
#define GL_PATH_MODELVIEW_MATRIX_NV       0x0BA6
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV 0x0D36
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV 0x84E3
#define GL_PATH_PROJECTION_STACK_DEPTH_NV 0x0BA4
#define GL_PATH_PROJECTION_MATRIX_NV      0x0BA7
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV 0x0D38
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV 0x84E4
#define GL_FRAGMENT_INPUT_NV              0x936D
typedef GLuint(APIENTRYP PFN_zlgl_glGenPathsNV)(GLsizei range);
typedef void (APIENTRYP PFN_zlgl_glDeletePathsNV)(GLuint path, GLsizei range);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsPathNV)(GLuint path);
typedef void (APIENTRYP PFN_zlgl_glPathCommandsNV)(GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFN_zlgl_glPathCoordsNV)(GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFN_zlgl_glPathSubCommandsNV)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFN_zlgl_glPathSubCoordsNV)(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFN_zlgl_glPathStringNV)(GLuint path, GLenum format, GLsizei length, const void *pathString);
typedef void (APIENTRYP PFN_zlgl_glPathGlyphsNV)(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFN_zlgl_glPathGlyphRangeNV)(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFN_zlgl_glWeightPathsNV)(GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
typedef void (APIENTRYP PFN_zlgl_glCopyPathNV)(GLuint resultPath, GLuint srcPath);
typedef void (APIENTRYP PFN_zlgl_glInterpolatePathsNV)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
typedef void (APIENTRYP PFN_zlgl_glTransformPathNV)(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFN_zlgl_glPathParameterivNV)(GLuint path, GLenum pname, const GLint *value);
typedef void (APIENTRYP PFN_zlgl_glPathParameteriNV)(GLuint path, GLenum pname, GLint value);
typedef void (APIENTRYP PFN_zlgl_glPathParameterfvNV)(GLuint path, GLenum pname, const GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glPathParameterfNV)(GLuint path, GLenum pname, GLfloat value);
typedef void (APIENTRYP PFN_zlgl_glPathDashArrayNV)(GLuint path, GLsizei dashCount, const GLfloat *dashArray);
typedef void (APIENTRYP PFN_zlgl_glPathStencilFuncNV)(GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFN_zlgl_glPathStencilDepthOffsetNV)(GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFN_zlgl_glStencilFillPathNV)(GLuint path, GLenum fillMode, GLuint mask);
typedef void (APIENTRYP PFN_zlgl_glStencilStrokePathNV)(GLuint path, GLint reference, GLuint mask);
typedef void (APIENTRYP PFN_zlgl_glStencilFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFN_zlgl_glStencilStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFN_zlgl_glPathCoverDepthFuncNV)(GLenum func);
typedef void (APIENTRYP PFN_zlgl_glCoverFillPathNV)(GLuint path, GLenum coverMode);
typedef void (APIENTRYP PFN_zlgl_glCoverStrokePathNV)(GLuint path, GLenum coverMode);
typedef void (APIENTRYP PFN_zlgl_glCoverFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFN_zlgl_glCoverStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFN_zlgl_glGetPathParameterivNV)(GLuint path, GLenum pname, GLint *value);
typedef void (APIENTRYP PFN_zlgl_glGetPathParameterfvNV)(GLuint path, GLenum pname, GLfloat *value);
typedef void (APIENTRYP PFN_zlgl_glGetPathCommandsNV)(GLuint path, GLubyte *commands);
typedef void (APIENTRYP PFN_zlgl_glGetPathCoordsNV)(GLuint path, GLfloat *coords);
typedef void (APIENTRYP PFN_zlgl_glGetPathDashArrayNV)(GLuint path, GLfloat *dashArray);
typedef void (APIENTRYP PFN_zlgl_glGetPathMetricsNV)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
typedef void (APIENTRYP PFN_zlgl_glGetPathMetricRangeNV)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
typedef void (APIENTRYP PFN_zlgl_glGetPathSpacingNV)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsPointInFillPathNV)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsPointInStrokePathNV)(GLuint path, GLfloat x, GLfloat y);
typedef GLfloat(APIENTRYP PFN_zlgl_glGetPathLengthNV)(GLuint path, GLsizei startSegment, GLsizei numSegments);
typedef GLboolean(APIENTRYP PFN_zlgl_glPointAlongPathNV)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
typedef void (APIENTRYP PFN_zlgl_glMatrixLoad3x2fNV)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixLoad3x3fNV)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixLoadTranspose3x3fNV)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixMult3x2fNV)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixMult3x3fNV)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glMatrixMultTranspose3x3fNV)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFN_zlgl_glStencilThenCoverFillPathNV)(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
typedef void (APIENTRYP PFN_zlgl_glStencilThenCoverStrokePathNV)(GLuint path, GLint reference, GLuint mask, GLenum coverMode);
typedef void (APIENTRYP PFN_zlgl_glStencilThenCoverFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFN_zlgl_glStencilThenCoverStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef GLenum(APIENTRYP PFN_zlgl_glPathGlyphIndexRangeNV)(GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2]);
typedef GLenum(APIENTRYP PFN_zlgl_glPathGlyphIndexArrayNV)(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef GLenum(APIENTRYP PFN_zlgl_glPathMemoryGlyphIndexArrayNV)(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFN_zlgl_glProgramPathFragmentInputGenNV)(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
typedef void (APIENTRYP PFN_zlgl_glGetProgramResourcefvNV)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params);


ZLGL_DEFINE_OPENGL_FUNCTION(glGenPathsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glDeletePathsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsPathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathCommandsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathCoordsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathSubCommandsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathSubCoordsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathStringNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathGlyphsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathGlyphRangeNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glWeightPathsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCopyPathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glInterpolatePathsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glTransformPathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathParameterivNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathParameteriNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathParameterfvNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathParameterfNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathDashArrayNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathStencilFuncNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathStencilDepthOffsetNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilFillPathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilStrokePathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilFillPathInstancedNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilStrokePathInstancedNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathCoverDepthFuncNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCoverFillPathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCoverStrokePathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCoverFillPathInstancedNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glCoverStrokePathInstancedNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPathParameterivNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPathParameterfvNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPathCommandsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPathCoordsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPathDashArrayNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPathMetricsNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPathMetricRangeNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPathSpacingNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsPointInFillPathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsPointInStrokePathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetPathLengthNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPointAlongPathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixLoad3x2fNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixLoad3x3fNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixLoadTranspose3x3fNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixMult3x2fNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixMult3x3fNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMatrixMultTranspose3x3fNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilThenCoverFillPathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilThenCoverStrokePathNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilThenCoverFillPathInstancedNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glStencilThenCoverStrokePathInstancedNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathGlyphIndexRangeNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathGlyphIndexArrayNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glPathMemoryGlyphIndexArrayNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramPathFragmentInputGenNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetProgramResourcefvNV);
#endif /* GL_NV_path_rendering */

#ifndef GL_NV_path_rendering_shared_edge
#define GL_NV_path_rendering_shared_edge 1
#define GL_SHARED_EDGE_NV                 0xC0
#endif /* GL_NV_path_rendering_shared_edge */

#ifndef GL_NV_sample_locations
#define GL_NV_sample_locations 1
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV 0x9340
#define GL_SAMPLE_LOCATION_NV             0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV 0x9343
typedef void (APIENTRYP PFN_zlgl_glFramebufferSampleLocationsfvNV)(GLenum target, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glNamedFramebufferSampleLocationsfvNV)(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFN_zlgl_glResolveDepthValuesNV)(void);

ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferSampleLocationsfvNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glNamedFramebufferSampleLocationsfvNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glResolveDepthValuesNV);
#endif /* GL_NV_sample_locations */

#ifndef GL_NV_sample_mask_override_coverage
#define GL_NV_sample_mask_override_coverage 1
#endif /* GL_NV_sample_mask_override_coverage */

#ifndef GL_NV_shader_atomic_counters
#define GL_NV_shader_atomic_counters 1
#endif /* GL_NV_shader_atomic_counters */

#ifndef GL_NV_shader_atomic_float
#define GL_NV_shader_atomic_float 1
#endif /* GL_NV_shader_atomic_float */

#ifndef GL_NV_shader_atomic_float64
#define GL_NV_shader_atomic_float64 1
#endif /* GL_NV_shader_atomic_float64 */

#ifndef GL_NV_shader_atomic_fp16_vector
#define GL_NV_shader_atomic_fp16_vector 1
#endif /* GL_NV_shader_atomic_fp16_vector */

#ifndef GL_NV_shader_atomic_int64
#define GL_NV_shader_atomic_int64 1
#endif /* GL_NV_shader_atomic_int64 */

#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load 1
#define GL_BUFFER_GPU_ADDRESS_NV          0x8F1D
#define GL_GPU_ADDRESS_NV                 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV   0x8F35
typedef void (APIENTRYP PFN_zlgl_glMakeBufferResidentNV)(GLenum target, GLenum access);
typedef void (APIENTRYP PFN_zlgl_glMakeBufferNonResidentNV)(GLenum target);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsBufferResidentNV)(GLenum target);
typedef void (APIENTRYP PFN_zlgl_glMakeNamedBufferResidentNV)(GLuint buffer, GLenum access);
typedef void (APIENTRYP PFN_zlgl_glMakeNamedBufferNonResidentNV)(GLuint buffer);
typedef GLboolean(APIENTRYP PFN_zlgl_glIsNamedBufferResidentNV)(GLuint buffer);
typedef void (APIENTRYP PFN_zlgl_glGetBufferParameterui64vNV)(GLenum target, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFN_zlgl_glGetNamedBufferParameterui64vNV)(GLuint buffer, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFN_zlgl_glGetIntegerui64vNV)(GLenum value, GLuint64EXT *result);
typedef void (APIENTRYP PFN_zlgl_glUniformui64NV)(GLint location, GLuint64EXT value);
typedef void (APIENTRYP PFN_zlgl_glUniformui64vNV)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFN_zlgl_glGetUniformui64vNV)(GLuint program, GLint location, GLuint64EXT *params);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformui64NV)(GLuint program, GLint location, GLuint64EXT value);
typedef void (APIENTRYP PFN_zlgl_glProgramUniformui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);

ZLGL_DEFINE_OPENGL_FUNCTION(glMakeBufferResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeBufferNonResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsBufferResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeNamedBufferResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glMakeNamedBufferNonResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIsNamedBufferResidentNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetBufferParameterui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetNamedBufferParameterui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetIntegerui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glUniformui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetUniformui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glProgramUniformui64vNV);
#endif /* GL_NV_shader_buffer_load */

#ifndef GL_NV_shader_buffer_store
#define GL_NV_shader_buffer_store 1
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010
#endif /* GL_NV_shader_buffer_store */

#ifndef GL_NV_shader_thread_group
#define GL_NV_shader_thread_group 1
#define GL_WARP_SIZE_NV                   0x9339
#define GL_WARPS_PER_SM_NV                0x933A
#define GL_SM_COUNT_NV                    0x933B
#endif /* GL_NV_shader_thread_group */

#ifndef GL_NV_shader_thread_shuffle
#define GL_NV_shader_thread_shuffle 1
#endif /* GL_NV_shader_thread_shuffle */

#ifndef GL_NV_stereo_view_rendering
#define GL_NV_stereo_view_rendering 1
#endif /* GL_NV_stereo_view_rendering */

#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier 1
typedef void (APIENTRYP PFN_zlgl_glTextureBarrierNV)(void);
ZLGL_DEFINE_OPENGL_FUNCTION(glTextureBarrierNV);
#endif /* GL_NV_texture_barrier */

#ifndef GL_NV_uniform_buffer_unified_memory
#define GL_NV_uniform_buffer_unified_memory 1
#define GL_UNIFORM_BUFFER_UNIFIED_NV      0x936E
#define GL_UNIFORM_BUFFER_ADDRESS_NV      0x936F
#define GL_UNIFORM_BUFFER_LENGTH_NV       0x9370
#endif /* GL_NV_uniform_buffer_unified_memory */

#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit 1
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL1i64NV)(GLuint index, GLint64EXT x);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL2i64NV)(GLuint index, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL3i64NV)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL4i64NV)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL1i64vNV)(GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL2i64vNV)(GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL3i64vNV)(GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL4i64vNV)(GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL1ui64NV)(GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL2ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL3ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL4ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL1ui64vNV)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL2ui64vNV)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL3ui64vNV)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribL4ui64vNV)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribLi64vNV)(GLuint index, GLenum pname, GLint64EXT *params);
typedef void (APIENTRYP PFN_zlgl_glGetVertexAttribLui64vNV)(GLuint index, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribLFormatNV)(GLuint index, GLint size, GLenum type, GLsizei stride);

ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL1i64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL2i64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL3i64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL4i64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL1i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL2i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL3i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL4i64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL1ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL2ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL3ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL4ui64NV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL1ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL2ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL3ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribL4ui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribLi64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetVertexAttribLui64vNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribLFormatNV);
#endif /* GL_NV_vertex_attrib_integer_64bit */

#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV       0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV        0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV        0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV         0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV         0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV     0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV     0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV       0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV  0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV         0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV         0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV          0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV          0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV  0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV      0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV      0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV        0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV       0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV       0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV        0x8F42
typedef void (APIENTRYP PFN_zlgl_glBufferAddressRangeNV)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
typedef void (APIENTRYP PFN_zlgl_glVertexFormatNV)(GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glNormalFormatNV)(GLenum type, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glColorFormatNV)(GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glIndexFormatNV)(GLenum type, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glTexCoordFormatNV)(GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glEdgeFlagFormatNV)(GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glSecondaryColorFormatNV)(GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glFogCoordFormatNV)(GLenum type, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribFormatNV)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glVertexAttribIFormatNV)(GLuint index, GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFN_zlgl_glGetIntegerui64i_vNV)(GLenum value, GLuint index, GLuint64EXT *result);

ZLGL_DEFINE_OPENGL_FUNCTION(glBufferAddressRangeNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glNormalFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glColorFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glIndexFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glTexCoordFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glEdgeFlagFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glSecondaryColorFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glFogCoordFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glVertexAttribIFormatNV);
ZLGL_DEFINE_OPENGL_FUNCTION(glGetIntegerui64i_vNV);
#endif /* GL_NV_vertex_buffer_unified_memory */

#ifndef GL_NV_viewport_array2
#define GL_NV_viewport_array2 1
#endif /* GL_NV_viewport_array2 */

#ifndef GL_NV_viewport_swizzle
#define GL_NV_viewport_swizzle 1
#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV 0x9350
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV 0x9351
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV 0x9352
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV 0x9353
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV 0x9354
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV 0x9355
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV 0x9356
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV 0x9357
#define GL_VIEWPORT_SWIZZLE_X_NV          0x9358
#define GL_VIEWPORT_SWIZZLE_Y_NV          0x9359
#define GL_VIEWPORT_SWIZZLE_Z_NV          0x935A
#define GL_VIEWPORT_SWIZZLE_W_NV          0x935B
typedef void (APIENTRYP PFN_zlgl_glViewportSwizzleNV)(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
ZLGL_DEFINE_OPENGL_FUNCTION(glViewportSwizzleNV);
#endif /* GL_NV_viewport_swizzle */

#ifndef GL_OVR_multiview
#define GL_OVR_multiview 1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR 0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR 0x9632
#define GL_MAX_VIEWS_OVR                  0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR 0x9633
typedef void (APIENTRYP PFN_zlgl_glFramebufferTextureMultiviewOVR)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
ZLGL_DEFINE_OPENGL_FUNCTION(glFramebufferTextureMultiviewOVR);
#endif /* GL_OVR_multiview */

#ifndef GL_OVR_multiview2
#define GL_OVR_multiview2 1
#endif /* GL_OVR_multiview2 */

#endif //ZLGL_NO_GL_EXTENSIONS


//wgl implementation

#if defined(_WIN32) || defined(WIN32)

//Note: wgl Version 1.0
#define ZLGL_DECLARE_WGL_FUNCTION(fun) extern PFN_zlgl_wgl##fun _zlgl_wgl##fun
#define ZLGL_DEFINE_WGL_FUNCTION(fun) static PFN_zlgl_wgl##fun _zlgl_wgl##fun = 0

#define WGL_FONT_LINES                    0
#define WGL_FONT_POLYGONS                 1
#define WGL_SWAP_MAIN_PLANE               0x00000001
#define WGL_SWAP_OVERLAY1                 0x00000002
#define WGL_SWAP_OVERLAY2                 0x00000004
#define WGL_SWAP_OVERLAY3                 0x00000008
#define WGL_SWAP_OVERLAY4                 0x00000010
#define WGL_SWAP_OVERLAY5                 0x00000020
#define WGL_SWAP_OVERLAY6                 0x00000040
#define WGL_SWAP_OVERLAY7                 0x00000080
#define WGL_SWAP_OVERLAY8                 0x00000100
#define WGL_SWAP_OVERLAY9                 0x00000200
#define WGL_SWAP_OVERLAY10                0x00000400
#define WGL_SWAP_OVERLAY11                0x00000800
#define WGL_SWAP_OVERLAY12                0x00001000
#define WGL_SWAP_OVERLAY13                0x00002000
#define WGL_SWAP_OVERLAY14                0x00004000
#define WGL_SWAP_OVERLAY15                0x00008000
#define WGL_SWAP_UNDERLAY1                0x00010000
#define WGL_SWAP_UNDERLAY2                0x00020000
#define WGL_SWAP_UNDERLAY3                0x00040000
#define WGL_SWAP_UNDERLAY4                0x00080000
#define WGL_SWAP_UNDERLAY5                0x00100000
#define WGL_SWAP_UNDERLAY6                0x00200000
#define WGL_SWAP_UNDERLAY7                0x00400000
#define WGL_SWAP_UNDERLAY8                0x00800000
#define WGL_SWAP_UNDERLAY9                0x01000000
#define WGL_SWAP_UNDERLAY10               0x02000000
#define WGL_SWAP_UNDERLAY11               0x04000000
#define WGL_SWAP_UNDERLAY12               0x08000000
#define WGL_SWAP_UNDERLAY13               0x10000000
#define WGL_SWAP_UNDERLAY14               0x20000000
#define WGL_SWAP_UNDERLAY15               0x40000000

typedef PROC(__stdcall *PFN_zlgl_wglGetProcAddress)(LPCSTR ProcName);
typedef BOOL(__stdcall *PFN_zlgl_wglCopyContext)(HGLRC SrcRC, HGLRC DstRC, UINT Mask);
typedef HGLRC(__stdcall *PFN_zlgl_wglCreateContext)(HDC DeviceContext);
typedef HGLRC(__stdcall *PFN_zlgl_wglCreateLayerContext)(HDC DeviceContext, int LayerPlane);
typedef BOOL(__stdcall *PFN_zlgl_wglDescribeLayerPlane)(HDC DeviceContext, int PixelFormat, int LayerPlane, UINT NumBytes, const LAYERPLANEDESCRIPTOR *Descriptor);
typedef int(__stdcall *PFN_zlgl_wglGetLayerPaletteEntries)(HDC DeviceContext, int LayerPlane, int Start, int Entries, const COLORREF *Ref);
typedef BOOL(__stdcall *PFN_zlgl_wglRealizeLayerPalette)(HDC DeviceContext, int LayerPlane, BOOL Realize);
typedef int(__stdcall *PFN_zlgl_wglSetLayerPaletteEntries)(HDC DeviceContext, int LayerPlane, int Start, int Entries, const COLORREF *Ref);
typedef BOOL(__stdcall *PFN_zlgl_wglSwapLayerBuffers)(HDC DeviceContext, UINT Flags);
typedef BOOL(__stdcall *PFN_zlgl_wglDeleteContext)(HGLRC RenderContext);
typedef HGLRC(__stdcall *PFN_zlgl_wglGetCurrentContext)();
typedef HDC(__stdcall *PFN_zlgl_wglGetCurrentDC)();
typedef BOOL(__stdcall *PFN_zlgl_wglMakeCurrent)(HDC DeviceContext, HGLRC RenderContext);
typedef BOOL(__stdcall *PFN_zlgl_wglShareLists)(HGLRC RenderContext1, HGLRC RenderContext2);
typedef BOOL(__stdcall *PFN_zlgl_wglUseFontBitmapsA)(HDC DeviceContext, DWORD First, DWORD Count, DWORD ListBase);
typedef BOOL(__stdcall *PFN_zlgl_wglUseFontBitmapsW)(HDC DeviceContext, DWORD First, DWORD Count, DWORD ListBase);
typedef BOOL(__stdcall *PFN_zlgl_wglUseFontOutlinesA)(HDC DeviceContext, DWORD First, DWORD Count, DWORD ListBase, FLOAT Deviation, FLOAT Extrusion, int Format, LPGLYPHMETRICSFLOAT GlyphMetrics);
typedef BOOL(__stdcall *PFN_zlgl_wglUseFontOutlinesW)(HDC DeviceContext, DWORD First, DWORD Count, DWORD ListBase, FLOAT Deviation, FLOAT Extrusion, int Format, LPGLYPHMETRICSFLOAT GlyphMetrics);

ZLGL_DEFINE_WGL_FUNCTION(GetProcAddress);
ZLGL_DEFINE_WGL_FUNCTION(CopyContext);
ZLGL_DEFINE_WGL_FUNCTION(CreateContext);
ZLGL_DEFINE_WGL_FUNCTION(CreateLayerContext);
ZLGL_DEFINE_WGL_FUNCTION(DescribeLayerPlane);
ZLGL_DEFINE_WGL_FUNCTION(GetLayerPaletteEntries);
ZLGL_DEFINE_WGL_FUNCTION(RealizeLayerPalette);
ZLGL_DEFINE_WGL_FUNCTION(SetLayerPaletteEntries);
ZLGL_DEFINE_WGL_FUNCTION(SwapLayerBuffers);
ZLGL_DEFINE_WGL_FUNCTION(DeleteContext);
ZLGL_DEFINE_WGL_FUNCTION(GetCurrentContext);
ZLGL_DEFINE_WGL_FUNCTION(GetCurrentDC);
ZLGL_DEFINE_WGL_FUNCTION(MakeCurrent);
ZLGL_DEFINE_WGL_FUNCTION(ShareLists);
ZLGL_DEFINE_WGL_FUNCTION(UseFontBitmapsA);
ZLGL_DEFINE_WGL_FUNCTION(UseFontBitmapsW);
ZLGL_DEFINE_WGL_FUNCTION(UseFontOutlinesA);
ZLGL_DEFINE_WGL_FUNCTION(UseFontOutlinesW);

#define wglGetProcAddress _zlgl_wglGetProcAddress
#define wglCopyContext _zlgl_wglCopyContext
#define wglCreateContext _zlgl_wglCreateContext
#define wglCreateLayerContext _zlgl_wglCreateLayerContext
#define wglDescribeLayerPlane _zlgl_wglDescribeLayerPlane
#define wglGetLayerPaletteEntries _zlgl_wglGetLayerPaletteEntries
#define wglRealizeLayerPalette _zlgl_wglRealizeLayerPalette
#define wglSetLayerPaletteEntries _zlgl_wglSetLayerPaletteEntries
#define wglSwapLayerBuffers _zlgl_wglSwapLayerBuffers
#define wglDeleteContext _zlgl_wglDeleteContext
#define wglGetCurrentContext _zlgl_wglGetCurrentContext
#define wglGetCurrentDC _zlgl_wglGetCurrentDC
#define wglMakeCurrent _zlgl_wglMakeCurrent
#define wglShareLists _zlgl_wglShareLists
#define wglUseFontBitmapsW _zlgl_wglUseFontBitmapsW
#define wglUseFontBitmapsA _zlgl_wglUseFontBitmapsA
#define wglUseFontOutlinesW _zlgl_wglUseFontOutlinesW
#define wglUseFontOutlinesA _zlgl_wglUseFontOutlinesA;

#ifdef UNICODE
#define wglUseFontBitmaps wglUseFontBitmapsW
#define wglUseFontOutlines wglUseFontOutlinesW
#else
#define wglUseFontBitmaps wglUseFontBitmapsA
#define wglUseFontOutlines wglUseFontOutlinesA
#endif 

//Note: WGL_ARB_buffer_region
#ifndef WGL_ARB_buffer_region
#define WGL_ARB_buffer_region 1

#define WGL_FRONT_COLOR_BUFFER_BIT_ARB    0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB     0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB          0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB        0x00000008

typedef HANDLE(__stdcall *PFN_zlgl_wglCreateBufferRegionARB)(HDC DeviceContext, int LayerPlane, UINT Type);
typedef void(__stdcall *PFN_zlgl_wglDeleteBufferRegionARB)(HANDLE Region);
typedef BOOL(__stdcall *PFN_zlgl_wglSaveBufferRegionARB)(HANDLE Region, int X, int Y, int Width, int Height);
typedef BOOL(__stdcall *PFN_zlgl_wglRestoreBufferRegionARB)(HANDLE Region, int X, int Y, int Width, int Height, int SrcX, int SrcY);

ZLGL_DEFINE_WGL_FUNCTION(CreateBufferRegionARB);
ZLGL_DEFINE_WGL_FUNCTION(DeleteBufferRegionARB);
ZLGL_DEFINE_WGL_FUNCTION(SaveBufferRegionARB);
ZLGL_DEFINE_WGL_FUNCTION(RestoreBufferRegionARB);

#define wglCreateBufferRegionARB _zlgl_wglCreateBufferRegionARB
#define wglDeleteBufferRegionARB _zlgl_wglDeleteBufferRegionARB
#define wglSaveBufferRegionARB _zlgl_wglSaveBufferRegionARB
#define wglRestoreBufferRegionARB _zlgl_wglRestoreBufferRegionARB

#endif //WGL_ARB_buffer_region


//Note: WGL_ARB_context_flush_control
#ifndef WGL_ARB_context_flush_control
#define WGL_ARB_context_flush_control 1

#define WGL_CONTEXT_RELEASE_BEHAVIOR_ARB  0x2097
#define WGL_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB 0
#define WGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB 0x2098

#endif //WGL_ARB_context_flush_control

//Note: WGL_ARB_create_context
#ifndef WGL_ARB_create_context
#define WGL_ARB_create_context 1

#define WGL_CONTEXT_DEBUG_BIT_ARB         0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002
#define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB       0x2093
#define WGL_CONTEXT_FLAGS_ARB             0x2094
#define ERROR_INVALID_VERSION_ARB         0x2095

typedef HGLRC(__stdcall *PFN_zlgl_wglCreateContextAttribsARB)(HDC DeviceContext, HGLRC ShareContext, const int *AttribList);

ZLGL_DEFINE_WGL_FUNCTION(CreateContextAttribsARB);

#define wglCreateContextAttribsARB _zlgl_wglCreateContextAttribsARB

#endif //WGL_ARB_create_context

//Note: WGL_ARB_create_context_profile
#ifndef WGL_ARB_create_context_profile
#define WGL_ARB_create_context_profile 1

#define WGL_CONTEXT_PROFILE_MASK_ARB      0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB  0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define ERROR_INVALID_PROFILE_ARB         0x2096

#endif //WGL_ARB_create_context_profile

//Note: WGL_ARB_create_context_robustness
#ifndef WGL_ARB_create_context_robustness
#define WGL_ARB_create_context_robustness 1

#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB 0x00000004
#define WGL_LOSE_CONTEXT_ON_RESET_ARB     0x8252
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define WGL_NO_RESET_NOTIFICATION_ARB     0x8261

#endif //WGL_ARB_create_context_robustness

//Note: WGL_ARB_framebuffer_sRGB
#ifndef WGL_ARB_framebuffer_sRGB
#define WGL_ARB_framebuffer_sRGB 1

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB  0x20A9

#endif //WGL_ARB_framebuffer_sRGB

//Note: WGL_ARB_extension_string
#ifndef WGL_ARB_extension_string
#define WGL_ARB_extension_string 1

typedef const char *(__stdcall *PFN_zlgl_wglGetExtensionsStringARB)(HDC DeviceContext);

ZLGL_DEFINE_WGL_FUNCTION(GetExtensionsStringARB);

#define wglGetExtensionsStringARB _zlgl_wglGetExtensionsStringARB

#endif //WGL_ARB_extension_string


//Note: WGL_ARB_make_current_read
#ifndef WGL_ARB_make_current_read
#define WGL_ARB_make_current_read 1

#define ERROR_INVALID_PIXEL_TYPE_ARB      0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB 0x2054

typedef BOOL(__stdcall *PFN_zlgl_wglMakeContextCurrentARB)(HDC DrawDeviceContext, HDC ReadDeviceContext, HGLRC RenderContext);
typedef HDC(__stdcall *PFN_zlgl_wglGetCurrentReadDCARB)();

ZLGL_DEFINE_WGL_FUNCTION(MakeContextCurrentARB);
ZLGL_DEFINE_WGL_FUNCTION(GetCurrentReadDCARB);

#define wglMakeContextCurrentARB _zlgl_wglMakeContextCurrentARB
#define wglGetCurrentReadDCARB _zlgl_wglGetCurrentReadDCARB

#endif //WGL_ARB_make_current_read

//Note: WGL_ARB_multisample
#ifndef WGL_ARB_multisample
#define WGL_ARB_multisample 1

#define WGL_SAMPLE_BUFFERS_ARB            0x2041
#define WGL_SAMPLES_ARB                   0x2042

#endif //WGL_ARB_multisample

//Note: WGL_ARB_pbuffer
#ifndef WGL_ARB_pbuffer
#define WGL_ARB_pbuffer 1

DECLARE_HANDLE(HPBUFFERARB);
#define WGL_DRAW_TO_PBUFFER_ARB           0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB        0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB         0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB        0x2030
#define WGL_PBUFFER_LARGEST_ARB           0x2033
#define WGL_PBUFFER_WIDTH_ARB             0x2034
#define WGL_PBUFFER_HEIGHT_ARB            0x2035
#define WGL_PBUFFER_LOST_ARB              0x2036

typedef HPBUFFERARB(__stdcall *PFN_zlgl_wglCreatePbufferARB)(HDC DeviceContext, int PixelFormat, int Width, int Height, const int *AttribList);
typedef HDC(__stdcall *PFN_zlgl_wglGetPbufferDCARB)(HPBUFFERARB Pbuffer);
typedef int(__stdcall *PFN_zlgl_wglReleasePbufferDCARB)(HPBUFFERARB Pbuffer, HDC DeviceContext);
typedef BOOL(__stdcall *PFN_zlgl_wglDestroyPbufferARB)(HPBUFFERARB Pbuffer);
typedef BOOL(__stdcall *PFN_zlgl_wglQueryPbufferARB)(HPBUFFERARB Pbuffer, int Attribute, int *Value);

ZLGL_DEFINE_WGL_FUNCTION(CreatePbufferARB);
ZLGL_DEFINE_WGL_FUNCTION(GetPbufferDCARB);
ZLGL_DEFINE_WGL_FUNCTION(ReleasePbufferDCARB);
ZLGL_DEFINE_WGL_FUNCTION(DestroyPbufferARB);
ZLGL_DEFINE_WGL_FUNCTION(QueryPbufferARB);

#define wglCreatePbufferARB _zlgl_wglCreatePbufferARB
#define wglGetPbufferDCARB _zlgl_wglGetPbufferDCARB
#define wglReleasePbufferDCARB _zlgl_wglReleasePbufferDCARB
#define wglDestroyPbufferARB _zlgl_wglDestroyPbufferARB
#define wglQueryPbufferARB _zlgl_wglQueryPbufferARB

#endif //WGL_ARB_pbuffer

//Note: WGL_ARB_pixel_format
#ifndef WGL_ARB_pixel_format
#define WGL_ARB_pixel_format 1

#define WGL_NUMBER_PIXEL_FORMATS_ARB      0x2000
#define WGL_DRAW_TO_WINDOW_ARB            0x2001
#define WGL_DRAW_TO_BITMAP_ARB            0x2002
#define WGL_ACCELERATION_ARB              0x2003
#define WGL_NEED_PALETTE_ARB              0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB       0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB        0x2006
#define WGL_SWAP_METHOD_ARB               0x2007
#define WGL_NUMBER_OVERLAYS_ARB           0x2008
#define WGL_NUMBER_UNDERLAYS_ARB          0x2009
#define WGL_TRANSPARENT_ARB               0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB     0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB   0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB    0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB   0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB   0x203B
#define WGL_SHARE_DEPTH_ARB               0x200C
#define WGL_SHARE_STENCIL_ARB             0x200D
#define WGL_SHARE_ACCUM_ARB               0x200E
#define WGL_SUPPORT_GDI_ARB               0x200F
#define WGL_SUPPORT_OPENGL_ARB            0x2010
#define WGL_DOUBLE_BUFFER_ARB             0x2011
#define WGL_STEREO_ARB                    0x2012
#define WGL_PIXEL_TYPE_ARB                0x2013
#define WGL_COLOR_BITS_ARB                0x2014
#define WGL_RED_BITS_ARB                  0x2015
#define WGL_RED_SHIFT_ARB                 0x2016
#define WGL_GREEN_BITS_ARB                0x2017
#define WGL_GREEN_SHIFT_ARB               0x2018
#define WGL_BLUE_BITS_ARB                 0x2019
#define WGL_BLUE_SHIFT_ARB                0x201A
#define WGL_ALPHA_BITS_ARB                0x201B
#define WGL_ALPHA_SHIFT_ARB               0x201C
#define WGL_ACCUM_BITS_ARB                0x201D
#define WGL_ACCUM_RED_BITS_ARB            0x201E
#define WGL_ACCUM_GREEN_BITS_ARB          0x201F
#define WGL_ACCUM_BLUE_BITS_ARB           0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB          0x2021
#define WGL_DEPTH_BITS_ARB                0x2022
#define WGL_STENCIL_BITS_ARB              0x2023
#define WGL_AUX_BUFFERS_ARB               0x2024
#define WGL_NO_ACCELERATION_ARB           0x2025
#define WGL_GENERIC_ACCELERATION_ARB      0x2026
#define WGL_FULL_ACCELERATION_ARB         0x2027
#define WGL_SWAP_EXCHANGE_ARB             0x2028
#define WGL_SWAP_COPY_ARB                 0x2029
#define WGL_SWAP_UNDEFINED_ARB            0x202A
#define WGL_TYPE_RGBA_ARB                 0x202B
#define WGL_TYPE_COLORINDEX_ARB           0x202C

typedef BOOL(__stdcall *PFN_zlgl_wglGetPixelFormatAttribivARB)(HDC DeviceContext, int PixelFormat, int LayerPlane, UINT NumAttributes, const int *Attributes, int *Values);
typedef BOOL(__stdcall *PFN_zlgl_wglGetPixelFormatAttribfvARB)(HDC DeviceContext, int PixelFormat, int LayerPlane, UINT NumAttributes, const int *Attributes, FLOAT *Values);
typedef BOOL(__stdcall *PFN_zlgl_wglChoosePixelFormatARB)(HDC DeviceContext, const int *IntAttribList, const FLOAT *FloatAttribList, UINT MaxFormats, int *Formats, UINT *NumFormats);

ZLGL_DEFINE_WGL_FUNCTION(GetPixelFormatAttribivARB);
ZLGL_DEFINE_WGL_FUNCTION(GetPixelFormatAttribfvARB);
ZLGL_DEFINE_WGL_FUNCTION(ChoosePixelFormatARB);

#define wglGetPixelFormatAttribivARB _zlgl_wglGetPixelFormatAttribivARB
#define wglGetPixelFormatAttribfvARB _zlgl_wglGetPixelFormatAttribfvARB
#define wglChoosePixelFormatARB _zlgl_wglChoosePixelFormatARB

#endif //WGL_ARB_pixel_format

//Note: WGL_ARB_pixel_format_float
#ifndef WGL_ARB_pixel_format_float
#define WGL_ARB_pixel_format_float 1

#define WGL_TYPE_RGBA_FLOAT_ARB           0x21A0

#endif //WGL_ARB_pixel_format_float

//Note: WGL_ARB_render_texture
#ifndef WGL_ARB_render_texture
#define WGL_ARB_render_texture 1

#define WGL_BIND_TO_TEXTURE_RGB_ARB       0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB      0x2071
#define WGL_TEXTURE_FORMAT_ARB            0x2072
#define WGL_TEXTURE_TARGET_ARB            0x2073
#define WGL_MIPMAP_TEXTURE_ARB            0x2074
#define WGL_TEXTURE_RGB_ARB               0x2075
#define WGL_TEXTURE_RGBA_ARB              0x2076
#define WGL_NO_TEXTURE_ARB                0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB          0x2078
#define WGL_TEXTURE_1D_ARB                0x2079
#define WGL_TEXTURE_2D_ARB                0x207A
#define WGL_MIPMAP_LEVEL_ARB              0x207B
#define WGL_CUBE_MAP_FACE_ARB             0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x2082
#define WGL_FRONT_LEFT_ARB                0x2083
#define WGL_FRONT_RIGHT_ARB               0x2084
#define WGL_BACK_LEFT_ARB                 0x2085
#define WGL_BACK_RIGHT_ARB                0x2086
#define WGL_AUX0_ARB                      0x2087
#define WGL_AUX1_ARB                      0x2088
#define WGL_AUX2_ARB                      0x2089
#define WGL_AUX3_ARB                      0x208A
#define WGL_AUX4_ARB                      0x208B
#define WGL_AUX5_ARB                      0x208C
#define WGL_AUX6_ARB                      0x208D
#define WGL_AUX7_ARB                      0x208E
#define WGL_AUX8_ARB                      0x208F
#define WGL_AUX9_ARB                      0x2090

typedef BOOL(__stdcall *PFN_zlgl_wglBindTexImageARB)(HPBUFFERARB Pbuffer, int Buffer);
typedef BOOL(__stdcall *PFN_zlgl_wglReleaseTexImageARB)(HPBUFFERARB Pbuffer, int Buffer);
typedef BOOL(__stdcall *PFN_zlgl_wglSetPbufferAttribARB)(HPBUFFERARB Pbuffer, const int *AttribList);

ZLGL_DEFINE_WGL_FUNCTION(BindTexImageARB);
ZLGL_DEFINE_WGL_FUNCTION(ReleaseTexImageARB);
ZLGL_DEFINE_WGL_FUNCTION(SetPbufferAttribARB);

#define wglBindTexImageARB _zlgl_wglBindTexImageARB
#define wglReleaseTexImageARB _zlgl_wglReleaseTexImageARB
#define wglSetPbufferAttribARB _zlgl_wglSetPbufferAttribARB

#endif //WGL_ARB_render_texture

//Note: WGL_ARB_robustness_application_isolation
#ifndef WGL_ARB_robustness_application_isolation
#define WGL_ARB_robustness_application_isolation 1

#define WGL_CONTEXT_RESET_ISOLATION_BIT_ARB 0x00000008

#endif //WGL_ARB_robustness_application_isolation

//Note: WGL_3DL_stereo_control
#ifndef WGL_3DL_stereo_control
#define WGL_3DL_stereo_control 1

#define WGL_STEREO_EMITTER_ENABLE_3DL     0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL    0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL    0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL    0x2058

typedef BOOL(__stdcall *PFN_zlgl_wglSetStereoEmitterState3DL)(HDC DeviceContext, UINT State);

ZLGL_DEFINE_WGL_FUNCTION(SetStereoEmitterState3DL);

#define wglSetStereoEmitterState3DL _zlgl_wglSetStereoEmitterState3DL

#endif //WGL_3DL_stereo_control

//Note: WGL_AMD_gpu_association
#ifndef WGL_AMD_gpu_association
#define WGL_AMD_gpu_association 1
#define WGL_GPU_VENDOR_AMD                0x1F00
#define WGL_GPU_RENDERER_STRING_AMD       0x1F01
#define WGL_GPU_OPENGL_VERSION_STRING_AMD 0x1F02
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD   0x21A2
#define WGL_GPU_RAM_AMD                   0x21A3
#define WGL_GPU_CLOCK_AMD                 0x21A4
#define WGL_GPU_NUM_PIPES_AMD             0x21A5
#define WGL_GPU_NUM_SIMD_AMD              0x21A6
#define WGL_GPU_NUM_RB_AMD                0x21A7
#define WGL_GPU_NUM_SPI_AMD               0x21A8

typedef UINT(__stdcall *PFN_zlgl_wglGetGPUIDsAMD)(UINT MaxCount, UINT *IDs);
typedef INT(__stdcall *PFN_zlgl_wglGetGPUInfoAMD)(UINT ID, int Property, GLenum DataType, UINT Size, void *Data);
typedef UINT(__stdcall *PFN_zlgl_wglGetContextGPUIDAMD)(HGLRC RenderContext);
typedef HGLRC(__stdcall *PFN_zlgl_wglCreateAssociatedContextAMD)(UINT ID);
typedef HGLRC(__stdcall *PFN_zlgl_wglCreateAssociatedContextAttribsAMD)(UINT ID, HGLRC ShareContext, const int *AttribList);
typedef BOOL(__stdcall *PFN_zlgl_wglDeleteAssociatedContextAMD)(HGLRC RenderContext);
typedef BOOL(__stdcall *PFN_zlgl_wglMakeAssociatedContextCurrentAMD)(HGLRC RenderContext);
typedef HGLRC(__stdcall *PFN_zlgl_wglGetCurrentAssociatedContextAMD)(void);
typedef void(__stdcall *PFN_zlgl_wglBlitContextFramebufferAMD)(HGLRC DestContext, GLint SrcX0, GLint SrcY0, GLint SrcX1, GLint SrcY1, GLint DstX0, GLint DstY0, GLint DstX1, GLint DstY1, GLbitfield Mask, GLenum Filter);

ZLGL_DEFINE_WGL_FUNCTION(GetGPUIDsAMD);
ZLGL_DEFINE_WGL_FUNCTION(GetGPUInfoAMD);
ZLGL_DEFINE_WGL_FUNCTION(GetContextGPUIDAMD);
ZLGL_DEFINE_WGL_FUNCTION(CreateAssociatedContextAMD);
ZLGL_DEFINE_WGL_FUNCTION(CreateAssociatedContextAttribsAMD);
ZLGL_DEFINE_WGL_FUNCTION(DeleteAssociatedContextAMD);
ZLGL_DEFINE_WGL_FUNCTION(MakeAssociatedContextCurrentAMD);
ZLGL_DEFINE_WGL_FUNCTION(GetCurrentAssociatedContextAMD);
ZLGL_DEFINE_WGL_FUNCTION(BlitContextFramebufferAMD);

#define wglGetGPUIDsAMD _zlgl_wglGetGPUIDsAMD
#define wglGetGPUInfoAMD _zlgl_wglGetGPUInfoAMD
#define wglGetContextGPUIDAMD _zlgl_wglGetContextGPUIDAMD
#define wglCreateAssociatedContextAMD _zlgl_wglCreateAssociatedContextAMD
#define wglCreateAssociatedContextAttribsAMD _zlgl_wglCreateAssociatedContextAttribsAMD
#define wglDeleteAssociatedContextAMD _zlgl_wglDeleteAssociatedContextAMD
#define wglMakeAssociatedContextCurrentAMD _zlgl_wglMakeAssociatedContextCurrentAMD
#define wglGetCurrentAssociatedContextAMD _zlgl_wglGetCurrentAssociatedContextAMD
#define wglBlitContextFramebufferAMD _zlgl_wglBlitContextFramebufferAMD

#endif //WGL_AMD_gpu_association


//Note: WGL_ATI_pixel_format_float
#ifndef WGL_ATI_pixel_format_float
#define WGL_ATI_pixel_format_float 1

#define WGL_TYPE_RGBA_FLOAT_ATI           0x21A0

#endif WGL_ATI_pixel_format_float

//Note: WGL_EXT_colorspace
#ifndef WGL_EXT_colorspace
#define WGL_EXT_colorspace 1

#define WGL_COLORSPACE_EXT                0x3087
#define WGL_COLORSPACE_SRGB_EXT           0x3089
#define WGL_COLORSPACE_LINEAR_EXT         0x308A

#endif //WGL_EXT_colorspace


//Note: WGL_EXT_create_context_es2_profile
#ifndef WGL_EXT_create_context_es2_profile
#define WGL_EXT_create_context_es2_profile 1

#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT   0x00000004

#endif //WGL_EXT_create_context_es2_profile

//Note: WGL_EXT_create_context_es_profile
#ifndef WGL_EXT_create_context_es_profile
#define WGL_EXT_create_context_es_profile 1

#define WGL_CONTEXT_ES_PROFILE_BIT_EXT   0x00000004

#endif

//Note: WGL_EXT_depth_float
#ifndef WGL_EXT_depth_float
#define WGL_EXT_depth_float 1

#define WGL_DEPTH_FLOAT_EXT               0x2040

#endif //WGL_EXT_depth_float

//Note: WGL_EXT_display_color_table
#ifndef WGL_EXT_display_color_table
#define WGL_EXT_display_color_table 1

typedef GLboolean(__stdcall *PFN_zlgl_wglCreateDisplayColorTableEXT)(GLushort ID);
typedef GLboolean(__stdcall *PFN_zlgl_wglLoadDisplayColorTableEXT)(const GLushort *Table, GLuint Length);
typedef GLboolean(__stdcall *PFN_zlgl_wglBindDisplayColorTableEXT)(GLushort ID);
typedef void(__stdcall *PFN_zlgl_wglDestroyDisplayColorTableEXT)(GLushort ID);

ZLGL_DEFINE_WGL_FUNCTION(CreateDisplayColorTableEXT);
ZLGL_DEFINE_WGL_FUNCTION(LoadDisplayColorTableEXT);
ZLGL_DEFINE_WGL_FUNCTION(BindDisplayColorTableEXT);
ZLGL_DEFINE_WGL_FUNCTION(DestroyDisplayColorTableEXT);

#define wglCreateDisplayColorTableEXT _zlgl_wglCreateDisplayColorTableEXT
#define wglLoadDisplayColorTableEXT _zlgl_wglLoadDisplayColorTableEXT
#define wglBindDisplayColorTableEXT _zlgl_wglBindDisplayColorTableEXT
#define wglDestroyDisplayColorTableEXT _zlgl_wglDestroyDisplayColorTableEXT

#endif //WGL_EXT_display_color_table

//Note: WGL_EXT_extension_string
#ifndef WGL_EXT_extension_string
#define WGL_EXT_extension_string 1

typedef const char *(__stdcall *PFN_zlgl_wglGetExtensionsStringEXT)(void);

ZLGL_DEFINE_WGL_FUNCTION(GetExtensionsStringEXT);

#define wglGetExtensionsStringEXT _zlgl_wglGetExtensionsStringEXT

#endif //WGL_EXT_extension_string

//Note: WGL_EXT_framebuffer_sRGB
#ifndef WGL_EXT_framebuffer_sRGB
#define WGL_EXT_framebuffer_sRGB 1

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT  0x20A9

#endif //WGL_EXT_framebuffer_sRGB

//Note: WGL_EXT_make_current_read
#ifndef WGL_EXT_make_current_read
#define WGL_EXT_make_current_read 1

#define ERROR_INVALID_PIXEL_TYPE_EXT      0x2043

typedef BOOL(__stdcall *PFN_zlgl_wglMakeContextCurrentEXT)(HDC DrawDeviceContext, HDC ReadDeviceContext, HGLRC RenderContext);
typedef HDC(__stdcall *PFN_zlgl_wglGetCurrentReadDCEXT)(void);

ZLGL_DEFINE_WGL_FUNCTION(MakeContextCurrentEXT);
ZLGL_DEFINE_WGL_FUNCTION(GetCurrentReadDCEXT);

#define wglMakeContextCurrentEXT _zlgl_wglMakeContextCurrentEXT
#define wglGetCurrentReadDCEXT _zlgl_wglGetCurrentReadDCEXT

#endif //WGL_EXT_make_current_read

//Note: WGL_EXT_multisample
#ifndef WGL_EXT_multisample
#define WGL_EXT_multisample 1

#define WGL_SAMPLE_BUFFERS_EXT            0x2041
#define WGL_SAMPLES_EXT                   0x2042

#endif //WGL_EXT_multisample

//Note: WGL_EXT_pbuffer
#ifndef WGL_EXT_pbuffer
#define WGL_EXT_pbuffer 1

DECLARE_HANDLE(HPBUFFEREXT);
#define WGL_DRAW_TO_PBUFFER_EXT           0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT        0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT         0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT        0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT     0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT    0x2032
#define WGL_PBUFFER_LARGEST_EXT           0x2033
#define WGL_PBUFFER_WIDTH_EXT             0x2034
#define WGL_PBUFFER_HEIGHT_EXT            0x2035

typedef HPBUFFEREXT(__stdcall *PFN_zlgl_wglCreatePbufferEXT)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
typedef HDC(__stdcall *PFN_zlgl_wglGetPbufferDCEXT)(HPBUFFEREXT hPbuffer);
typedef int(__stdcall *PFN_zlgl_wglReleasePbufferDCEXT)(HPBUFFEREXT hPbuffer, HDC hDC);
typedef BOOL(__stdcall *PFN_zlgl_wglDestroyPbufferEXT)(HPBUFFEREXT hPbuffer);
typedef BOOL(__stdcall *PFN_zlgl_wglQueryPbufferEXT)(HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);

ZLGL_DEFINE_WGL_FUNCTION(CreatePbufferEXT);
ZLGL_DEFINE_WGL_FUNCTION(GetPbufferDCEXT);
ZLGL_DEFINE_WGL_FUNCTION(ReleasePbufferDCEXT);
ZLGL_DEFINE_WGL_FUNCTION(DestroyPbufferEXT);
ZLGL_DEFINE_WGL_FUNCTION(QueryPbufferEXT);

#define wglCreatePbufferEXT _zlgl_wglCreatePbufferEXT
#define wglGetPbufferDCEXT _zlgl_wglGetPbufferDCEXT
#define wglReleasePbufferDCEXT _zlgl_wglReleasePbufferDCEXT
#define wglDestroyPbufferEXT _zlgl_wglDestroyPbufferEXT
#define wglQueryPbufferEXT _zlgl_wglQueryPbufferEXT

#endif //WGL_EXT_pbuffer

//Note: WGL_EXT_pixel_format
#ifndef WGL_EXT_pixel_format
#define WGL_EXT_pixel_format 1
#define WGL_NUMBER_PIXEL_FORMATS_EXT      0x2000
#define WGL_DRAW_TO_WINDOW_EXT            0x2001
#define WGL_DRAW_TO_BITMAP_EXT            0x2002
#define WGL_ACCELERATION_EXT              0x2003
#define WGL_NEED_PALETTE_EXT              0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT       0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT        0x2006
#define WGL_SWAP_METHOD_EXT               0x2007
#define WGL_NUMBER_OVERLAYS_EXT           0x2008
#define WGL_NUMBER_UNDERLAYS_EXT          0x2009
#define WGL_TRANSPARENT_EXT               0x200A
#define WGL_TRANSPARENT_VALUE_EXT         0x200B
#define WGL_SHARE_DEPTH_EXT               0x200C
#define WGL_SHARE_STENCIL_EXT             0x200D
#define WGL_SHARE_ACCUM_EXT               0x200E
#define WGL_SUPPORT_GDI_EXT               0x200F
#define WGL_SUPPORT_OPENGL_EXT            0x2010
#define WGL_DOUBLE_BUFFER_EXT             0x2011
#define WGL_STEREO_EXT                    0x2012
#define WGL_PIXEL_TYPE_EXT                0x2013
#define WGL_COLOR_BITS_EXT                0x2014
#define WGL_RED_BITS_EXT                  0x2015
#define WGL_RED_SHIFT_EXT                 0x2016
#define WGL_GREEN_BITS_EXT                0x2017
#define WGL_GREEN_SHIFT_EXT               0x2018
#define WGL_BLUE_BITS_EXT                 0x2019
#define WGL_BLUE_SHIFT_EXT                0x201A
#define WGL_ALPHA_BITS_EXT                0x201B
#define WGL_ALPHA_SHIFT_EXT               0x201C
#define WGL_ACCUM_BITS_EXT                0x201D
#define WGL_ACCUM_RED_BITS_EXT            0x201E
#define WGL_ACCUM_GREEN_BITS_EXT          0x201F
#define WGL_ACCUM_BLUE_BITS_EXT           0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT          0x2021
#define WGL_DEPTH_BITS_EXT                0x2022
#define WGL_STENCIL_BITS_EXT              0x2023
#define WGL_AUX_BUFFERS_EXT               0x2024
#define WGL_NO_ACCELERATION_EXT           0x2025
#define WGL_GENERIC_ACCELERATION_EXT      0x2026
#define WGL_FULL_ACCELERATION_EXT         0x2027
#define WGL_SWAP_EXCHANGE_EXT             0x2028
#define WGL_SWAP_COPY_EXT                 0x2029
#define WGL_SWAP_UNDEFINED_EXT            0x202A
#define WGL_TYPE_RGBA_EXT                 0x202B
#define WGL_TYPE_COLORINDEX_EXT           0x202C

typedef BOOL (__stdcall *PFN_zlgl_wglGetPixelFormatAttribivEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
typedef BOOL (__stdcall *PFN_zlgl_wglGetPixelFormatAttribfvEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
typedef BOOL (__stdcall *PFN_zlgl_wglChoosePixelFormatEXT)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

ZLGL_DEFINE_WGL_FUNCTION(GetPixelFormatAttribivEXT);
ZLGL_DEFINE_WGL_FUNCTION(GetPixelFormatAttribfvEXT);
ZLGL_DEFINE_WGL_FUNCTION(ChoosePixelFormatEXT);

#define wglGetPixelFormatAttribivEXT _zlgl_wglGetPixelFormatAttribivEXT
#define wglGetPixelFormatAttribfvEXT _zlgl_wglGetPixelFormatAttribfvEXT
#define wglChoosePixelFormatEXT _zlgl_wglChoosePixelFormatEXT

#endif //WGL_EXT_pixel_format

//Note: WGL_EXT_pixel_format_packed_float
#ifndef WGL_EXT_pixel_format_packed_float
#define WGL_EXT_pixel_format_packed_float 1

#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT  0x20A8

#endif //WGL_EXT_pixel_format_packed_float

//Note: WGL_EXT_swap_control
#ifndef WGL_EXT_swap_control
#define WGL_EXT_swap_control 1

typedef BOOL (__stdcall *PFN_zlgl_wglSwapIntervalEXT)(int interval);
typedef int (__stdcall *PFN_zlgl_wglGetSwapIntervalEXT)(void);

ZLGL_DEFINE_WGL_FUNCTION(SwapIntervalEXT);
ZLGL_DEFINE_WGL_FUNCTION(GetSwapIntervalEXT);

#define wglSwapIntervalEXT _zlgl_wglSwapIntervalEXT
#define wglGetSwapIntervalEXT _zlgl_wglGetSwapIntervalEXT

#endif // WGL_EXT_swap_control

#ifndef WGL_EXT_swap_control_tear
#define WGL_EXT_swap_control_tear 1

#endif /* WGL_EXT_swap_control_tear */

#ifndef WGL_I3D_digital_video_control
#define WGL_I3D_digital_video_control 1

#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D 0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D 0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D 0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D 0x2053

typedef BOOL (__stdcall *PFN_zlgl_wglGetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, int *piValue);
typedef BOOL (__stdcall *PFN_zlgl_wglSetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, const int *piValue);

ZLGL_DEFINE_WGL_FUNCTION(GetDigitalVideoParametersI3D);
ZLGL_DEFINE_WGL_FUNCTION(SetDigitalVideoParametersI3D);

#define wglGetDigitalVideoParametersI3D _zlgl_wglGetDigitalVideoParametersI3D
#define wglSetDigitalVideoParametersI3D _zlgl_wglSetDigitalVideoParametersI3D

#endif /* WGL_I3D_digital_video_control */

#ifndef WGL_I3D_gamma
#define WGL_I3D_gamma 1

#define WGL_GAMMA_TABLE_SIZE_I3D          0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D     0x204F

typedef BOOL (__stdcall *PFN_zlgl_wglGetGammaTableParametersI3D)(HDC hDC, int iAttribute, int *piValue);
typedef BOOL (__stdcall *PFN_zlgl_wglSetGammaTableParametersI3D)(HDC hDC, int iAttribute, const int *piValue);
typedef BOOL (__stdcall *PFN_zlgl_wglGetGammaTableI3D)(HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
typedef BOOL (__stdcall *PFN_zlgl_wglSetGammaTableI3D)(HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);

ZLGL_DEFINE_WGL_FUNCTION(GetGammaTableParametersI3D);
ZLGL_DEFINE_WGL_FUNCTION(SetGammaTableParametersI3D);
ZLGL_DEFINE_WGL_FUNCTION(GetGammaTableI3D);
ZLGL_DEFINE_WGL_FUNCTION(SetGammaTableI3D);

#define wglGetGammaTableParametersI3D _zlgl_wglGetGammaTableParametersI3D
#define wglSetGammaTableParametersI3D _zlgl_wglSetGammaTableParametersI3D
#define wglGetGammaTableI3D _zlgl_wglGetGammaTableI3D
#define wglSetGammaTableI3D _zlgl_wglSetGammaTableI3D

#endif /* WGL_I3D_gamma */

#ifndef WGL_I3D_genlock
#define WGL_I3D_genlock 1

#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D  0x2044
#define WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D 0x2045
#define WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D 0x2046
#define WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D 0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D 0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D 0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D 0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D 0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D  0x204C

typedef BOOL(__stdcall *PFN_zlgl_wglEnableGenlockI3D)(HDC hDC);
typedef BOOL(__stdcall *PFN_zlgl_wglDisableGenlockI3D)(HDC hDC);
typedef BOOL(__stdcall *PFN_zlgl_wglIsEnabledGenlockI3D)(HDC hDC, BOOL *pFlag);
typedef BOOL(__stdcall *PFN_zlgl_wglGenlockSourceI3D)(HDC hDC, UINT uSource);
typedef BOOL(__stdcall *PFN_zlgl_wglGetGenlockSourceI3D)(HDC hDC, UINT *uSource);
typedef BOOL(__stdcall *PFN_zlgl_wglGenlockSourceEdgeI3D)(HDC hDC, UINT uEdge);
typedef BOOL(__stdcall *PFN_zlgl_wglGetGenlockSourceEdgeI3D)(HDC hDC, UINT *uEdge);
typedef BOOL(__stdcall *PFN_zlgl_wglGenlockSampleRateI3D)(HDC hDC, UINT uRate);
typedef BOOL(__stdcall *PFN_zlgl_wglGetGenlockSampleRateI3D)(HDC hDC, UINT *uRate);
typedef BOOL(__stdcall *PFN_zlgl_wglGenlockSourceDelayI3D)(HDC hDC, UINT uDelay);
typedef BOOL(__stdcall *PFN_zlgl_wglGetGenlockSourceDelayI3D)(HDC hDC, UINT *uDelay);
typedef BOOL(__stdcall *PFN_zlgl_wglQueryGenlockMaxSourceDelayI3D)(HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);

ZLGL_DEFINE_WGL_FUNCTION(EnableGenlockI3D);
ZLGL_DEFINE_WGL_FUNCTION(DisableGenlockI3D);
ZLGL_DEFINE_WGL_FUNCTION(IsEnabledGenlockI3D);
ZLGL_DEFINE_WGL_FUNCTION(GenlockSourceI3D);
ZLGL_DEFINE_WGL_FUNCTION(GetGenlockSourceI3D);
ZLGL_DEFINE_WGL_FUNCTION(GenlockSourceEdgeI3D);
ZLGL_DEFINE_WGL_FUNCTION(GetGenlockSourceEdgeI3D);
ZLGL_DEFINE_WGL_FUNCTION(GenlockSampleRateI3D);
ZLGL_DEFINE_WGL_FUNCTION(GetGenlockSampleRateI3D);
ZLGL_DEFINE_WGL_FUNCTION(GenlockSourceDelayI3D);
ZLGL_DEFINE_WGL_FUNCTION(GetGenlockSourceDelayI3D);
ZLGL_DEFINE_WGL_FUNCTION(QueryGenlockMaxSourceDelayI3D);

#define wglEnableGenlockI3D _zlgl_wglEnableGenlockI3D
#define wglDisableGenlockI3D _zlgl_wglDisableGenlockI3D
#define wglIsEnabledGenlockI3D _zlgl_wglIsEnabledGenlockI3D
#define wglGenlockSourceI3D _zlgl_wglGenlockSourceI3D
#define wglGetGenlockSourceI3D _zlgl_wglGetGenlockSourceI3D
#define wglGenlockSourceEdgeI3D _zlgl_wglGenlockSourceEdgeI3D
#define wglGetGenlockSourceEdgeI3D _zlgl_wglGetGenlockSourceEdgeI3D
#define wglGenlockSampleRateI3D _zlgl_wglGenlockSampleRateI3D
#define wglGetGenlockSampleRateI3D _zlgl_wglGetGenlockSampleRateI3D
#define wglGenlockSourceDelayI3D _zlgl_wglGenlockSourceDelayI3D
#define wglGetGenlockSourceDelayI3D _zlgl_wglGetGenlockSourceDelayI3D
#define wglQueryGenlockMaxSourceDelayI3D _zlgl_wglQueryGenlockMaxSourceDelayI3D

#endif /* WGL_I3D_genlock */

#ifndef WGL_I3D_image_buffer
#define WGL_I3D_image_buffer 1

#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D   0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D         0x00000002

typedef LPVOID (__stdcall * PFN_zlgl_wglCreateImageBufferI3D)(HDC hDC, DWORD dwSize, UINT uFlags);
typedef BOOL (__stdcall * PFN_zlgl_wglDestroyImageBufferI3D)(HDC hDC, LPVOID pAddress);
typedef BOOL (__stdcall * PFN_zlgl_wglAssociateImageBufferEventsI3D)(HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
typedef BOOL (__stdcall * PFN_zlgl_wglReleaseImageBufferEventsI3D)(HDC hDC, const LPVOID *pAddress, UINT count);

ZLGL_DEFINE_WGL_FUNCTION(CreateImageBufferI3D);
ZLGL_DEFINE_WGL_FUNCTION(DestroyImageBufferI3D);
ZLGL_DEFINE_WGL_FUNCTION(AssociateImageBufferEventsI3D);
ZLGL_DEFINE_WGL_FUNCTION(ReleaseImageBufferEventsI3D);

#define wglCreateImageBufferI3D _zlgl_wglCreateImageBufferI3D
#define wglDestroyImageBufferI3D _zlgl_wglDestroyImageBufferI3D
#define wglAssociateImageBufferEventsI3D _zlgl_wglAssociateImageBufferEventsI3D
#define wglReleaseImageBufferEventsI3D _zlgl_wglReleaseImageBufferEventsI3D

#endif /* WGL_I3D_image_buffer */

#ifndef WGL_I3D_swap_frame_lock
#define WGL_I3D_swap_frame_lock 1

typedef BOOL (__stdcall *PFN_zlgl_wglEnableFrameLockI3D)(void);
typedef BOOL (__stdcall *PFN_zlgl_wglDisableFrameLockI3D)(void);
typedef BOOL (__stdcall *PFN_zlgl_wglIsEnabledFrameLockI3D)(BOOL *pFlag);
typedef BOOL (__stdcall *PFN_zlgl_wglQueryFrameLockMasterI3D)(BOOL *pFlag);

ZLGL_DEFINE_WGL_FUNCTION(EnableFrameLockI3D);
ZLGL_DEFINE_WGL_FUNCTION(DisableFrameLockI3D);
ZLGL_DEFINE_WGL_FUNCTION(IsEnabledFrameLockI3D);
ZLGL_DEFINE_WGL_FUNCTION(QueryFrameLockMasterI3D);

#define wglEnableFrameLockI3D _zlgl_wglEnableFrameLockI3D
#define wglDisableFrameLockI3D _zlgl_wglDisableFrameLockI3D
#define wglIsEnabledFrameLockI3D _zlgl_wglIsEnabledFrameLockI3D
#define wglQueryFrameLockMasterI3D _zlgl_wglQueryFrameLockMasterI3D

#endif /* WGL_I3D_swap_frame_lock */

#ifndef WGL_I3D_swap_frame_usage
#define WGL_I3D_swap_frame_usage 1

typedef BOOL (APIENTRYP PFN_zlgl_wglGetFrameUsageI3D)(float *pUsage);
typedef BOOL (APIENTRYP PFN_zlgl_wglBeginFrameTrackingI3D)(void);
typedef BOOL (APIENTRYP PFN_zlgl_wglEndFrameTrackingI3D)(void);
typedef BOOL (APIENTRYP PFN_zlgl_wglQueryFrameTrackingI3D)(DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);

ZLGL_DEFINE_WGL_FUNCTION(GetFrameUsageI3D);
ZLGL_DEFINE_WGL_FUNCTION(BeginFrameTrackingI3D);
ZLGL_DEFINE_WGL_FUNCTION(EndFrameTrackingI3D);
ZLGL_DEFINE_WGL_FUNCTION(QueryFrameTrackingI3D);

#define wglGetFrameUsageI3D _zlgl_wglGetFrameUsageI3D
#define wglBeginFrameTrackingI3D _zlgl_wglBeginFrameTrackingI3D
#define wglEndFrameTrackingI3D _zlgl_wglEndFrameTrackingI3D
#define wglQueryFrameTrackingI3D _zlgl_wglQueryFrameTrackingI3D

#endif /* WGL_I3D_swap_frame_usage */

#ifndef WGL_NV_DX_interop
#define WGL_NV_DX_interop 1

#define WGL_ACCESS_READ_ONLY_NV           0x00000000
#define WGL_ACCESS_READ_WRITE_NV          0x00000001
#define WGL_ACCESS_WRITE_DISCARD_NV       0x00000002

typedef BOOL   (APIENTRYP PFN_zlgl_wglDXSetResourceShareHandleNV)(void *dxObject, HANDLE shareHandle);
typedef HANDLE (APIENTRYP PFN_zlgl_wglDXOpenDeviceNV)(void *dxDevice);
typedef BOOL   (APIENTRYP PFN_zlgl_wglDXCloseDeviceNV)(HANDLE hDevice);
typedef HANDLE (APIENTRYP PFN_zlgl_wglDXRegisterObjectNV)(HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
typedef BOOL   (APIENTRYP PFN_zlgl_wglDXUnregisterObjectNV)(HANDLE hDevice, HANDLE hObject);
typedef BOOL   (APIENTRYP PFN_zlgl_wglDXObjectAccessNV)(HANDLE hObject, GLenum access);
typedef BOOL   (APIENTRYP PFN_zlgl_wglDXLockObjectsNV)(HANDLE hDevice, GLint count, HANDLE *hObjects);
typedef BOOL   (APIENTRYP PFN_zlgl_wglDXUnlockObjectsNV)(HANDLE hDevice, GLint count, HANDLE *hObjects);

ZLGL_DEFINE_WGL_FUNCTION(DXSetResourceShareHandleNV);
ZLGL_DEFINE_WGL_FUNCTION(DXOpenDeviceNV);
ZLGL_DEFINE_WGL_FUNCTION(DXCloseDeviceNV);
ZLGL_DEFINE_WGL_FUNCTION(DXRegisterObjectNV);
ZLGL_DEFINE_WGL_FUNCTION(DXUnregisterObjectNV);
ZLGL_DEFINE_WGL_FUNCTION(DXObjectAccessNV);
ZLGL_DEFINE_WGL_FUNCTION(DXLockObjectsNV);
ZLGL_DEFINE_WGL_FUNCTION(DXUnlockObjectsNV);

#define wglDXSetResourceShareHandleNV _zlgl_wglDXSetResourceShareHandleNV
#define wglDXOpenDeviceNV _zlgl_wglDXOpenDeviceNV
#define wglDXCloseDeviceNV _zlgl_wglDXCloseDeviceNV
#define wglDXRegisterObjectNV _zlgl_wglDXRegisterObjectNV
#define wglDXUnregisterObjectNV _zlgl_wglDXUnregisterObjectNV
#define wglDXObjectAccessNV _zlgl_wglDXObjectAccessNV
#define wglDXLockObjectsNV _zlgl_wglDXLockObjectsNV
#define wglDXUnlockObjectsNV _zlgl_wglDXUnlockObjectsNV

#endif /* WGL_NV_DX_interop */

#ifndef WGL_NV_DX_interop2
#define WGL_NV_DX_interop2 1

#endif /* WGL_NV_DX_interop2 */

#ifndef WGL_NV_copy_image
#define WGL_NV_copy_image 1

typedef BOOL (APIENTRYP PFN_zlgl_wglCopyImageSubDataNV)(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);

ZLGL_DEFINE_WGL_FUNCTION(CopyImageSubDataNV);

#define wglCopyImageSubDataNV _zlgl_wglCopyImageSubDataNV

#endif /* WGL_NV_copy_image */

#ifndef WGL_NV_delay_before_swap
#define WGL_NV_delay_before_swap 1

typedef BOOL (APIENTRYP PFN_zlgl_wglDelayBeforeSwapNV)(HDC hDC, GLfloat seconds);

ZLGL_DEFINE_WGL_FUNCTION(DelayBeforeSwapNV);

#define wglDelayBeforeSwapNV _zlgl_wglDelayBeforeSwapNV

#endif /* WGL_NV_delay_before_swap */

#ifndef WGL_NV_float_buffer
#define WGL_NV_float_buffer 1

#define WGL_FLOAT_COMPONENTS_NV           0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV 0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV 0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV 0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV 0x20B4
#define WGL_TEXTURE_FLOAT_R_NV            0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV           0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV          0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV         0x20B8

#endif /* WGL_NV_float_buffer */

#ifndef WGL_NV_gpu_affinity
#define WGL_NV_gpu_affinity 1

DECLARE_HANDLE(HGPUNV);
struct _GPU_DEVICE {
	DWORD  cb;
	CHAR   DeviceName[32];
	CHAR   DeviceString[128];
	DWORD  Flags;
	RECT   rcVirtualScreen;
};
typedef struct _GPU_DEVICE *PGPU_DEVICE;
#define ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV 0x20D0
#define ERROR_MISSING_AFFINITY_MASK_NV    0x20D1

typedef BOOL (APIENTRYP PFN_zlgl_wglEnumGpusNV)(UINT iGpuIndex, HGPUNV *phGpu);
typedef BOOL (APIENTRYP PFN_zlgl_wglEnumGpuDevicesNV)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
typedef HDC  (APIENTRYP PFN_zlgl_wglCreateAffinityDCNV)(const HGPUNV *phGpuList);
typedef BOOL (APIENTRYP PFN_zlgl_wglEnumGpusFromAffinityDCNV)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
typedef BOOL (APIENTRYP PFN_zlgl_wglDeleteDCNV)(HDC hdc);

ZLGL_DEFINE_WGL_FUNCTION(EnumGpusNV);
ZLGL_DEFINE_WGL_FUNCTION(EnumGpuDevicesNV);
ZLGL_DEFINE_WGL_FUNCTION(CreateAffinityDCNV);
ZLGL_DEFINE_WGL_FUNCTION(EnumGpusFromAffinityDCNV);
ZLGL_DEFINE_WGL_FUNCTION(DeleteDCNV);

#define wglEnumGpusNV _zlgl_wglEnumGpusNV
#define wglEnumGpuDevicesNV _zlgl_wglEnumGpuDevicesNV
#define wglCreateAffinityDCNV _zlgl_wglCreateAffinityDCNV
#define wglEnumGpusFromAffinityDCNV _zlgl_wglEnumGpusFromAffinityDCNV
#define wglDeleteDCNV _zlgl_wglDeleteDCNV

#endif /* WGL_NV_gpu_affinity */

#ifndef WGL_NV_multisample_coverage
#define WGL_NV_multisample_coverage 1

#define WGL_COVERAGE_SAMPLES_NV           0x2042
#define WGL_COLOR_SAMPLES_NV              0x20B9

#endif /* WGL_NV_multisample_coverage */

#ifndef WGL_NV_present_video
#define WGL_NV_present_video 1

DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
#define WGL_NUM_VIDEO_SLOTS_NV            0x20F0

typedef int  (APIENTRYP PFN_zlgl_wglEnumerateVideoDevicesNV)(HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
typedef BOOL (APIENTRYP PFN_zlgl_wglBindVideoDeviceNV)(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
typedef BOOL (APIENTRYP PFN_zlgl_wglQueryCurrentContextNV)(int iAttribute, int *piValue);

ZLGL_DEFINE_WGL_FUNCTION(EnumerateVideoDevicesNV);
ZLGL_DEFINE_WGL_FUNCTION(BindVideoDeviceNV);
ZLGL_DEFINE_WGL_FUNCTION(QueryCurrentContextNV);

#define wglEnumerateVideoDevicesNV _zlgl_wglEnumerateVideoDevicesNV
#define wglBindVideoDeviceNV _zlgl_wglBindVideoDeviceNV
#define wglQueryCurrentContextNV _zlgl_wglQueryCurrentContextNV

#endif /* WGL_NV_present_video */

#ifndef WGL_NV_render_depth_texture
#define WGL_NV_render_depth_texture 1

#define WGL_BIND_TO_TEXTURE_DEPTH_NV      0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV 0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV       0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV    0x20A6
#define WGL_DEPTH_COMPONENT_NV            0x20A7

#endif /* WGL_NV_render_depth_texture */

#ifndef WGL_NV_render_texture_rectangle
#define WGL_NV_render_texture_rectangle 1

#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV 0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV 0x20A1
#define WGL_TEXTURE_RECTANGLE_NV          0x20A2

#endif /* WGL_NV_render_texture_rectangle */

#ifndef WGL_NV_swap_group
#define WGL_NV_swap_group 1

typedef BOOL (APIENTRYP PFN_zlgl_wglJoinSwapGroupNV)(HDC hDC, GLuint group);
typedef BOOL (APIENTRYP PFN_zlgl_wglBindSwapBarrierNV)(GLuint group, GLuint barrier);
typedef BOOL (APIENTRYP PFN_zlgl_wglQuerySwapGroupNV)(HDC hDC, GLuint *group, GLuint *barrier);
typedef BOOL (APIENTRYP PFN_zlgl_wglQueryMaxSwapGroupsNV)(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
typedef BOOL (APIENTRYP PFN_zlgl_wglQueryFrameCountNV)(HDC hDC, GLuint *count);
typedef BOOL (APIENTRYP PFN_zlgl_wglResetFrameCountNV)(HDC hDC);

ZLGL_DEFINE_WGL_FUNCTION(JoinSwapGroupNV);
ZLGL_DEFINE_WGL_FUNCTION(BindSwapBarrierNV);
ZLGL_DEFINE_WGL_FUNCTION(QuerySwapGroupNV);
ZLGL_DEFINE_WGL_FUNCTION(QueryMaxSwapGroupsNV);
ZLGL_DEFINE_WGL_FUNCTION(QueryFrameCountNV);
ZLGL_DEFINE_WGL_FUNCTION(ResetFrameCountNV);

#define wglJoinSwapGroupNV _zlgl_wglJoinSwapGroupNV
#define wglBindSwapBarrierNV _zlgl_wglBindSwapBarrierNV
#define wglQuerySwapGroupNV _zlgl_wglQuerySwapGroupNV
#define wglQueryMaxSwapGroupsNV _zlgl_wglQueryMaxSwapGroupsNV
#define wglQueryFrameCountNV _zlgl_wglQueryFrameCountNV
#define wglResetFrameCountNV _zlgl_wglResetFrameCountNV

#endif /* WGL_NV_swap_group */

#ifndef WGL_NV_vertex_array_range
#define WGL_NV_vertex_array_range 1

typedef void* (APIENTRYP PFN_zlgl_wglAllocateMemoryNV)(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
typedef void  (APIENTRYP PFN_zlgl_wglFreeMemoryNV)(void *pointer);

ZLGL_DEFINE_WGL_FUNCTION(AllocateMemoryNV);
ZLGL_DEFINE_WGL_FUNCTION(FreeMemoryNV);

#define wglAllocateMemoryNV _zlgl_wglAllocateMemoryNV
#define wglFreeMemoryNV _zlgl_wglFreeMemoryNV

#endif /* WGL_NV_vertex_array_range */

#ifndef WGL_NV_video_capture
#define WGL_NV_video_capture 1

DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
#define WGL_UNIQUE_ID_NV                  0x20CE
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV    0x20CF

typedef BOOL (APIENTRYP PFN_zlgl_wglBindVideoCaptureDeviceNV)(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
typedef UINT (APIENTRYP PFN_zlgl_wglEnumerateVideoCaptureDevicesNV)(HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
typedef BOOL (APIENTRYP PFN_zlgl_wglLockVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
typedef BOOL (APIENTRYP PFN_zlgl_wglQueryVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
typedef BOOL (APIENTRYP PFN_zlgl_wglReleaseVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);

ZLGL_DEFINE_WGL_FUNCTION(BindVideoCaptureDeviceNV);
ZLGL_DEFINE_WGL_FUNCTION(EnumerateVideoCaptureDevicesNV);
ZLGL_DEFINE_WGL_FUNCTION(LockVideoCaptureDeviceNV);
ZLGL_DEFINE_WGL_FUNCTION(QueryVideoCaptureDeviceNV);
ZLGL_DEFINE_WGL_FUNCTION(ReleaseVideoCaptureDeviceNV);

#define wglBindVideoCaptureDeviceNV _zlgl_wglBindVideoCaptureDeviceNV
#define wglEnumerateVideoCaptureDevicesNV _zlgl_wglEnumerateVideoCaptureDevicesNV
#define wglLockVideoCaptureDeviceNV _zlgl_wglLockVideoCaptureDeviceNV
#define wglQueryVideoCaptureDeviceNV _zlgl_wglQueryVideoCaptureDeviceNV
#define wglReleaseVideoCaptureDeviceNV _zlgl_wglReleaseVideoCaptureDeviceNV

#endif /* WGL_NV_video_capture */

#ifndef WGL_NV_video_output
#define WGL_NV_video_output 1

DECLARE_HANDLE(HPVIDEODEV);
#define WGL_BIND_TO_VIDEO_RGB_NV          0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV         0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV 0x20C2
#define WGL_VIDEO_OUT_COLOR_NV            0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV            0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV            0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV  0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV  0x20C7
#define WGL_VIDEO_OUT_FRAME               0x20C8
#define WGL_VIDEO_OUT_FIELD_1             0x20C9
#define WGL_VIDEO_OUT_FIELD_2             0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2  0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1  0x20CC

typedef BOOL (APIENTRYP PFN_zlgl_wglGetVideoDeviceNV)(HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
typedef BOOL (APIENTRYP PFN_zlgl_wglReleaseVideoDeviceNV)(HPVIDEODEV hVideoDevice);
typedef BOOL (APIENTRYP PFN_zlgl_wglBindVideoImageNV)(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
typedef BOOL (APIENTRYP PFN_zlgl_wglReleaseVideoImageNV)(HPBUFFERARB hPbuffer, int iVideoBuffer);
typedef BOOL (APIENTRYP PFN_zlgl_wglSendPbufferToVideoNV)(HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
typedef BOOL (APIENTRYP PFN_zlgl_wglGetVideoInfoNV)(HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);

ZLGL_DEFINE_WGL_FUNCTION(GetVideoDeviceNV);
ZLGL_DEFINE_WGL_FUNCTION(ReleaseVideoDeviceNV);
ZLGL_DEFINE_WGL_FUNCTION(BindVideoImageNV);
ZLGL_DEFINE_WGL_FUNCTION(ReleaseVideoImageNV);
ZLGL_DEFINE_WGL_FUNCTION(SendPbufferToVideoNV);
ZLGL_DEFINE_WGL_FUNCTION(GetVideoInfoNV);

#define wglGetVideoDeviceNV _zlgl_wglGetVideoDeviceNV
#define wglReleaseVideoDeviceNV _zlgl_wglReleaseVideoDeviceNV
#define wglBindVideoImageNV _zlgl_wglBindVideoImageNV
#define wglReleaseVideoImageNV _zlgl_wglReleaseVideoImageNV
#define wglSendPbufferToVideoNV _zlgl_wglSendPbufferToVideoNV
#define wglGetVideoInfoNV _zlgl_wglGetVideoInfoNV

#endif /* WGL_NV_video_output */

#ifndef WGL_OML_sync_control
#define WGL_OML_sync_control 1

typedef BOOL  (APIENTRYP PFN_zlgl_wglGetSyncValuesOML)(HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
typedef BOOL  (APIENTRYP PFN_zlgl_wglGetMscRateOML)(HDC hdc, INT32 *numerator, INT32 *denominator);
typedef INT64 (APIENTRYP PFN_zlgl_wglSwapBuffersMscOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef INT64 (APIENTRYP PFN_zlgl_wglSwapLayerBuffersMscOML)(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
typedef BOOL  (APIENTRYP PFN_zlgl_wglWaitForMscOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
typedef BOOL  (APIENTRYP PFN_zlgl_wglWaitForSbcOML)(HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);

ZLGL_DEFINE_WGL_FUNCTION(GetSyncValuesOML);
ZLGL_DEFINE_WGL_FUNCTION(GetMscRateOML);
ZLGL_DEFINE_WGL_FUNCTION(SwapBuffersMscOML);
ZLGL_DEFINE_WGL_FUNCTION(SwapLayerBuffersMscOML);
ZLGL_DEFINE_WGL_FUNCTION(WaitForMscOML);
ZLGL_DEFINE_WGL_FUNCTION(WaitForSbcOML);

#define wglGetSyncValuesOML _zlgl_wglGetSyncValuesOML
#define wglGetMscRateOML _zlgl_wglGetMscRateOML
#define wglSwapBuffersMscOML _zlgl_wglSwapBuffersMscOML
#define wglSwapLayerBuffersMscOML _zlgl_wglSwapLayerBuffersMscOML
#define wglWaitForMscOML _zlgl_wglWaitForMscOML
#define wglWaitForSbcOML _zlgl_wglWaitForSbcOML

#endif /* WGL_OML_sync_control */



#define LOAD_WGL_FUNCTION(lib, fun) \
	_zlgl_wgl##fun = (PFN_zlgl_wgl##fun)GetProcAddress(lib, "wgl"#fun)

#define LOAD_WGL_EXT_FUNCTION(lib, fun) \
	wgl##fun = (PFN_zlgl_wgl##fun)wglGetProcAddress("wgl"#fun)

static HMODULE oglLib;

static void zlgl_LoadWGLFunctions()
{
	if (!oglLib)
	{
		oglLib = LoadLibraryA("opengl32.dll");
	}

	LOAD_WGL_FUNCTION(oglLib, GetProcAddress);
	LOAD_WGL_FUNCTION(oglLib, CopyContext);
	LOAD_WGL_FUNCTION(oglLib, CreateContext);
	LOAD_WGL_FUNCTION(oglLib, CreateLayerContext);
	LOAD_WGL_FUNCTION(oglLib, DescribeLayerPlane);
	LOAD_WGL_FUNCTION(oglLib, GetLayerPaletteEntries);
	LOAD_WGL_FUNCTION(oglLib, RealizeLayerPalette);
	LOAD_WGL_FUNCTION(oglLib, SetLayerPaletteEntries);
	LOAD_WGL_FUNCTION(oglLib, SwapLayerBuffers);
	LOAD_WGL_FUNCTION(oglLib, DeleteContext);
	LOAD_WGL_FUNCTION(oglLib, GetCurrentContext);
	LOAD_WGL_FUNCTION(oglLib, GetCurrentDC);
	LOAD_WGL_FUNCTION(oglLib, MakeCurrent);
	LOAD_WGL_FUNCTION(oglLib, ShareLists);
	LOAD_WGL_FUNCTION(oglLib, UseFontBitmapsA);
	LOAD_WGL_FUNCTION(oglLib, UseFontBitmapsW);
	LOAD_WGL_FUNCTION(oglLib, UseFontOutlinesA);
	LOAD_WGL_FUNCTION(oglLib, UseFontOutlinesW);
}

static void zlgl_LoadWGLExtensions()
{
#ifdef WGL_ARB_buffer_region
	LOAD_WGL_EXT_FUNCTION(oglLib, CreateBufferRegionARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, DeleteBufferRegionARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, SaveBufferRegionARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, RestoreBufferRegionARB);
#endif

#ifdef WGL_ARB_create_context
	LOAD_WGL_EXT_FUNCTION(oglLib, CreateContextAttribsARB);
#endif

#ifdef WGL_ARB_extension_string
	LOAD_WGL_EXT_FUNCTION(oglLib, GetExtensionsStringARB);
#endif

#ifdef WGL_ARB_make_current_read
	LOAD_WGL_EXT_FUNCTION(oglLib, MakeContextCurrentARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetCurrentReadDCARB);
#endif

#ifdef WGL_ARB_pbuffer
	LOAD_WGL_EXT_FUNCTION(oglLib, CreatePbufferARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetPbufferDCARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, ReleasePbufferDCARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, DestroyPbufferARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, QueryPbufferARB);
#endif

#ifdef WGL_ARB_pixel_format
	LOAD_WGL_EXT_FUNCTION(oglLib, GetPixelFormatAttribivARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetPixelFormatAttribfvARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, ChoosePixelFormatARB);
#endif

#ifdef WGL_ARB_render_texture
	LOAD_WGL_EXT_FUNCTION(oglLib, BindTexImageARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, ReleaseTexImageARB);
	LOAD_WGL_EXT_FUNCTION(oglLib, SetPbufferAttribARB);
#endif

#ifdef WGL_3DL_stereo_control
	LOAD_WGL_EXT_FUNCTION(oglLib, SetStereoEmitterState3DL);
#endif

#ifdef WGL_AMD_gpu_association
	LOAD_WGL_EXT_FUNCTION(oglLib, GetGPUIDsAMD);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetGPUInfoAMD);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetContextGPUIDAMD);
	LOAD_WGL_EXT_FUNCTION(oglLib, CreateAssociatedContextAMD);
	LOAD_WGL_EXT_FUNCTION(oglLib, CreateAssociatedContextAttribsAMD);
	LOAD_WGL_EXT_FUNCTION(oglLib, DeleteAssociatedContextAMD);
	LOAD_WGL_EXT_FUNCTION(oglLib, MakeAssociatedContextCurrentAMD);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetCurrentAssociatedContextAMD);
	LOAD_WGL_EXT_FUNCTION(oglLib, BlitContextFramebufferAMD);
#endif

#ifdef WGL_EXT_display_color_table
	LOAD_WGL_EXT_FUNCTION(oglLib, CreateDisplayColorTableEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, LoadDisplayColorTableEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, BindDisplayColorTableEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, DestroyDisplayColorTableEXT);
#endif

#ifdef WGL_EXT_extension_string
	LOAD_WGL_EXT_FUNCTION(oglLib, GetExtensionsStringEXT);
#endif

#ifdef WGL_EXT_make_current_read
	LOAD_WGL_EXT_FUNCTION(oglLib, MakeContextCurrentEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetCurrentReadDCEXT);
#endif

#ifdef WGL_EXT_pbuffer
	LOAD_WGL_EXT_FUNCTION(oglLib, CreatePbufferEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetPbufferDCEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, ReleasePbufferDCEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, DestroyPbufferEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, QueryPbufferEXT);
#endif

#ifdef WGL_EXT_pixel_format
	LOAD_WGL_EXT_FUNCTION(oglLib, GetPixelFormatAttribivEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetPixelFormatAttribfvEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, ChoosePixelFormatEXT);
#endif //WGL_EXT_pixel_format


#ifdef WGL_EXT_swap_control
	LOAD_WGL_EXT_FUNCTION(oglLib, SwapIntervalEXT);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetSwapIntervalEXT);
#endif // WGL_EXT_swap_control

#ifdef WGL_I3D_digital_video_control
	LOAD_WGL_EXT_FUNCTION(oglLib, GetDigitalVideoParametersI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, SetDigitalVideoParametersI3D);
#endif /* WGL_I3D_digital_video_control */

#ifdef WGL_I3D_gamma
	LOAD_WGL_EXT_FUNCTION(oglLib, GetGammaTableParametersI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, SetGammaTableParametersI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetGammaTableI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, SetGammaTableI3D);
#endif /* WGL_I3D_gamma */

#ifdef WGL_I3D_genlock
	LOAD_WGL_EXT_FUNCTION(oglLib, EnableGenlockI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, DisableGenlockI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, IsEnabledGenlockI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, GenlockSourceI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetGenlockSourceI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, GenlockSourceEdgeI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetGenlockSourceEdgeI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, GenlockSampleRateI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetGenlockSampleRateI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, GenlockSourceDelayI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetGenlockSourceDelayI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, QueryGenlockMaxSourceDelayI3D);
#endif /* WGL_I3D_genlock */

#ifdef WGL_I3D_image_buffer
	LOAD_WGL_EXT_FUNCTION(oglLib, CreateImageBufferI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, DestroyImageBufferI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, AssociateImageBufferEventsI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, ReleaseImageBufferEventsI3D);
#endif /* WGL_I3D_image_buffer */

#ifdef WGL_I3D_swap_frame_lock
	LOAD_WGL_EXT_FUNCTION(oglLib, EnableFrameLockI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, DisableFrameLockI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, IsEnabledFrameLockI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, QueryFrameLockMasterI3D);
#endif /* WGL_I3D_swap_frame_lock */

#ifdef WGL_I3D_swap_frame_usage
	LOAD_WGL_EXT_FUNCTION(oglLib, GetFrameUsageI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, BeginFrameTrackingI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, EndFrameTrackingI3D);
	LOAD_WGL_EXT_FUNCTION(oglLib, QueryFrameTrackingI3D);
#endif /* WGL_I3D_swap_frame_usage */

#ifdef WGL_NV_DX_interop
	LOAD_WGL_EXT_FUNCTION(oglLib, DXSetResourceShareHandleNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, DXOpenDeviceNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, DXCloseDeviceNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, DXRegisterObjectNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, DXUnregisterObjectNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, DXObjectAccessNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, DXLockObjectsNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, DXUnlockObjectsNV);
#endif /* WGL_NV_DX_interop */

#ifdef WGL_NV_copy_image
	LOAD_WGL_EXT_FUNCTION(oglLib, CopyImageSubDataNV);
#endif /* WGL_NV_copy_image */

#ifdef WGL_NV_delay_before_swap
	LOAD_WGL_EXT_FUNCTION(oglLib, DelayBeforeSwapNV);
#endif /* WGL_NV_delay_before_swap */

#ifdef WGL_NV_gpu_affinity
	LOAD_WGL_EXT_FUNCTION(oglLib, EnumGpusNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, EnumGpuDevicesNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, CreateAffinityDCNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, EnumGpusFromAffinityDCNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, DeleteDCNV);
#endif /* WGL_NV_gpu_affinity */

#ifdef WGL_NV_present_video
	LOAD_WGL_EXT_FUNCTION(oglLib, EnumerateVideoDevicesNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, BindVideoDeviceNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, QueryCurrentContextNV);
#endif /* WGL_NV_present_video */

#ifdef WGL_NV_swap_group
	LOAD_WGL_EXT_FUNCTION(oglLib, JoinSwapGroupNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, BindSwapBarrierNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, QuerySwapGroupNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, QueryMaxSwapGroupsNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, QueryFrameCountNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, ResetFrameCountNV);
#endif /* WGL_NV_swap_group */

#ifdef WGL_NV_vertex_array_range
	LOAD_WGL_EXT_FUNCTION(oglLib, AllocateMemoryNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, FreeMemoryNV);
#endif /* WGL_NV_vertex_array_range */

#ifdef WGL_NV_video_capture
	LOAD_WGL_EXT_FUNCTION(oglLib, BindVideoCaptureDeviceNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, EnumerateVideoCaptureDevicesNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, LockVideoCaptureDeviceNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, QueryVideoCaptureDeviceNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, ReleaseVideoCaptureDeviceNV);
#endif /* WGL_NV_video_capture */

#ifdef WGL_NV_video_output
	LOAD_WGL_EXT_FUNCTION(oglLib, GetVideoDeviceNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, ReleaseVideoDeviceNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, BindVideoImageNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, ReleaseVideoImageNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, SendPbufferToVideoNV);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetVideoInfoNV);
#endif /* WGL_NV_video_output */

#ifdef WGL_OML_sync_control
	LOAD_WGL_EXT_FUNCTION(oglLib, GetSyncValuesOML);
	LOAD_WGL_EXT_FUNCTION(oglLib, GetMscRateOML);
	LOAD_WGL_EXT_FUNCTION(oglLib, SwapBuffersMscOML);
	LOAD_WGL_EXT_FUNCTION(oglLib, SwapLayerBuffersMscOML);
	LOAD_WGL_EXT_FUNCTION(oglLib, WaitForMscOML);
	LOAD_WGL_EXT_FUNCTION(oglLib, WaitForSbcOML);
#endif /* WGL_OML_sync_control */
}

static void zlgl_UnloadWGLFunctions()
{
	if (oglLib)
	{
		_zlgl_wglGetProcAddress = 0;
		_zlgl_wglCopyContext = 0;
		_zlgl_wglCreateContext = 0;
		_zlgl_wglCreateLayerContext = 0;
		_zlgl_wglDeleteContext = 0;
		_zlgl_wglGetCurrentContext = 0;
		_zlgl_wglGetCurrentDC = 0;
		_zlgl_wglMakeCurrent = 0;
		_zlgl_wglShareLists = 0;
		_zlgl_wglUseFontBitmapsA = 0;
		_zlgl_wglUseFontBitmapsW = 0;

		FreeLibrary(oglLib);
		oglLib = 0;
	}
}

static int zlgl_CheckWGLExtensionAvailable(const char* ExtensionName)
{
	int Result = 1;
	HDC DeviceContext = wglGetCurrentDC();
	const char* AllExtensions = wglGetExtensionsStringARB(DeviceContext);
	if (!ZLGL_STRSTR(AllExtensions, ExtensionName))
	{
		Result = 0;
	}
	return(Result);
}

static HGLRC zlgl_create_context(int RequiredVersion, HDC DeviceContext, ZLGL_opengl_version* ReturnedVersion, zlgl_OpenGLContextDescriptor* Descriptor)
{
	HGLRC RenderContext = 0;

	if (Descriptor == NULL)
		return RenderContext;

	zlgl_LoadWGLFunctions();

	PIXELFORMATDESCRIPTOR pfd = {};

	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cAlphaBits = (BYTE)Descriptor->DefFramebufferAlphaBits;
	pfd.cColorBits = (BYTE)Descriptor->DefFramebufferColorBits;
	pfd.cDepthBits = (BYTE)Descriptor->DefFramebufferDepthBits;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int format = ChoosePixelFormat(DeviceContext, &pfd);
	if (format != 0)
	{
		SetPixelFormat(DeviceContext, format, &pfd);

		HGLRC DummyContext = wglCreateContext(DeviceContext);
		if (DummyContext)
		{
			wglMakeCurrent(DeviceContext, DummyContext);

			zlgl_LoadWGLExtensions();

			if (zlgl_CheckWGLExtensionAvailable("WGL_ARB_create_context") &&
				zlgl_CheckWGLExtensionAvailable("WGL_ARB_pixel_format"))
			{
				const int AttribList[] = {
					WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
					WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
					WGL_DOUBLE_BUFFER_ARB, (Descriptor->EnableDoubleBuffering != 0) ? GL_TRUE : GL_FALSE,
					WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
					WGL_COLOR_BITS_ARB, (const int)Descriptor->DefFramebufferColorBits,
					WGL_ALPHA_BITS_ARB, (const int)Descriptor->DefFramebufferAlphaBits,
					WGL_DEPTH_BITS_ARB, (const int)Descriptor->DefFramebufferDepthBits,
					WGL_STENCIL_BITS_ARB, (const int)Descriptor->DefFramebufferStencilBits,
					WGL_SAMPLE_BUFFERS_ARB, Descriptor->DefFramebufferMultiSamples ? 1 : 0,
					WGL_SAMPLES_ARB, (const int)Descriptor->DefFramebufferMultiSamples,
					0,
				};

				int PixelFormat;
				UINT NumFormats;
				wglChoosePixelFormatARB(DeviceContext, AttribList, 0, 1, &PixelFormat, &NumFormats);

				int MajorVersion = (((int)RequiredVersion) & 0xFF00) >> 8;
				int MinorVersion = ((int)RequiredVersion) & 0x00FF;
				const int ContextAttribList[] =
				{
					WGL_CONTEXT_MAJOR_VERSION_ARB, MajorVersion,
					WGL_CONTEXT_MINOR_VERSION_ARB, MinorVersion,
					WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB |
						((Descriptor->DebugContext != 0) ? WGL_CONTEXT_DEBUG_BIT_ARB : 0),
					WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
					0
				};
				RenderContext = wglCreateContextAttribsARB(DeviceContext, 0, ContextAttribList);
				if (RenderContext)
				{
					wglMakeCurrent(DeviceContext, RenderContext);
					wglDeleteContext(DummyContext);
					zlgl_LoadOpenGLFunctions((ZLGL_opengl_version)RequiredVersion);

					glGetIntegerv(GL_MAJOR_VERSION, &MajorVersion);
					glGetIntegerv(GL_MINOR_VERSION, &MinorVersion);
				}
				else if (RequiredVersion < ZLGL_opengl_3_0)
				{
					RenderContext = DummyContext;
					zlgl_LoadOpenGLFunctions((ZLGL_opengl_version)RequiredVersion);

					const GLubyte* glVersion = glGetString(GL_VERSION);
					if (glVersion && ReturnedVersion)
					{
						MajorVersion = glVersion[0] - '0';
						MinorVersion = glVersion[2] - '0';
					}
				}
				*ReturnedVersion = (ZLGL_opengl_version)((MajorVersion << 8) + MinorVersion);
				if (!Descriptor->EnforceRequestedVersion && (*ReturnedVersion > RequiredVersion))
				{
					zlgl_LoadOpenGLFunctions(*ReturnedVersion);
				}

				zlgl_LoadOpenGLExtensions();

                glEnable(GL_MULTISAMPLE);
				wglSwapIntervalEXT(Descriptor->EnableVSync);
			}
		}
	}
	return(RenderContext);
}

static HGLRC zlgl_create_compatible_context(ZLGL_opengl_version RequiredVersion, HDC DeviceContext, HGLRC MainRenderContext)
{
	HGLRC SharedContext = 0;
	if (zlgl_CheckWGLExtensionAvailable("WGL_ARB_create_context"))
	{
		int MajorVersion = (((int)RequiredVersion) & 0xFF00) >> 8;
		int MinorVersion = ((int)RequiredVersion) & 0x00FF;
		const int ContextAttribList[] =
		{
			WGL_CONTEXT_MAJOR_VERSION_ARB, MajorVersion,
			WGL_CONTEXT_MINOR_VERSION_ARB, MinorVersion,
			WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB
#ifndef NDEBUG
			| WGL_CONTEXT_DEBUG_BIT_ARB
#endif
			,
			WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
			0
		};
		SharedContext = wglCreateContextAttribsARB(DeviceContext, MainRenderContext, ContextAttribList);
	}
	else 
	{
		//Note: Old Context sharing style
		SharedContext = wglCreateContext(DeviceContext);
		wglShareLists(MainRenderContext, SharedContext);
	}
	return(SharedContext);
}

static void* zlgl_Win32GetGLProcAddress_internal(const char* Name)
{
	void *Result = (void *)wglGetProcAddress(Name);
	if (Result == 0)
	{
		Result = (void *)GetProcAddress(oglLib, Name);
	}
	return(Result);
}

#define ZLGL_LOAD_OPENGL_FUNCTION(fun) \
	fun = (PFN_zlgl_##fun)zlgl_Win32GetGLProcAddress_internal(#fun)	

#elif defined(__linux__)

//glx
#define ZLGL_LOAD_OPENGL_FUNCTION(fun)
#endif

static void 
zlgl_LoadOpenGLExtensions()
{
#ifdef GL_ARB_ES3_2_compatibility
	ZLGL_LOAD_OPENGL_FUNCTION(glPrimitiveBoundingBoxARB);
#endif /* GL_ARB_ES3_2_compatibility */

#ifdef GL_ARB_bindless_texture
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureHandleARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureSamplerHandleARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeTextureHandleResidentARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeTextureHandleNonResidentARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetImageHandleARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeImageHandleResidentARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeImageHandleNonResidentARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformHandleui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformHandleui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformHandleui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformHandleui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsTextureHandleResidentARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsImageHandleResidentARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL1ui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL1ui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribLui64vARB);
#endif /* GL_ARB_bindless_texture */

#ifdef GL_ARB_cl_event
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateSyncFromCLeventARB);
#endif /* GL_ARB_cl_event */

#ifdef GL_ARB_compute_variable_group_size
	ZLGL_LOAD_OPENGL_FUNCTION(glDispatchComputeGroupSizeARB);
#endif /* GL_ARB_compute_variable_group_size */

#ifdef GL_ARB_debug_output
	ZLGL_LOAD_OPENGL_FUNCTION(glDebugMessageControlARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glDebugMessageInsertARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glDebugMessageCallbackARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetDebugMessageLogARB);
#endif /* GL_ARB_debug_output */

#ifdef GL_ARB_draw_buffers_blend
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendEquationiARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendEquationSeparateiARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendFunciARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendFuncSeparateiARB);
#endif /* GL_ARB_draw_buffers_blend */

#ifdef GL_ARB_draw_instanced
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawArraysInstancedARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawElementsInstancedARB);
#endif /* GL_ARB_draw_instanced */

#ifdef GL_ARB_geometry_shader4
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramParameteriARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferTextureARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferTextureLayerARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferTextureFaceARB);
#endif /* GL_ARB_geometry_shader4 */

#ifdef GL_ARB_gl_spirv
	ZLGL_LOAD_OPENGL_FUNCTION(glSpecializeShaderARB);
#endif /* GL_ARB_gl_spirv */

#ifdef GL_ARB_gpu_shader_int64
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1i64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2i64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3i64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4i64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1i64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2i64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3i64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4i64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1ui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2ui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3ui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4ui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1ui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2ui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3ui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4ui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformi64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformi64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1i64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2i64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3i64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4i64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1i64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2i64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3i64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4i64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1ui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2ui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3ui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4ui64ARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1ui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2ui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3ui64vARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4ui64vARB);
#endif /* GL_ARB_gpu_shader_int64 */

#ifdef GL_ARB_indirect_parameters
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawArraysIndirectCountARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawElementsIndirectCountARB);
#endif /* GL_ARB_indirect_parameters */

#ifdef GL_ARB_instanced_arrays
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribDivisorARB);
#endif /* GL_ARB_instanced_arrays */

#ifdef GL_ARB_parallel_shader_compile
	ZLGL_LOAD_OPENGL_FUNCTION(glMaxShaderCompilerThreadsARB);
#endif /* GL_ARB_parallel_shader_compile */

#ifdef GL_ARB_robustness
	ZLGL_LOAD_OPENGL_FUNCTION(glGetGraphicsResetStatusARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnTexImageARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glReadnPixelsARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnCompressedTexImageARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformfvARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformivARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformuivARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformdvARB);
#endif /* GL_ARB_robustness */

#ifdef GL_ARB_sample_locations
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferSampleLocationsfvARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferSampleLocationsfvARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glEvaluateDepthValuesARB);
#endif /* GL_ARB_sample_locations */

#ifdef GL_ARB_sample_shading
	ZLGL_LOAD_OPENGL_FUNCTION(glMinSampleShadingARB);
#endif /* GL_ARB_sample_shading */

#ifdef GL_ARB_shading_language_include
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedStringARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteNamedStringARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompileShaderIncludeARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsNamedStringARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedStringARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedStringivARB);
#endif /* GL_ARB_shading_language_include */

#ifdef GL_ARB_sparse_buffer
	ZLGL_LOAD_OPENGL_FUNCTION(glBufferPageCommitmentARB);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedBufferPageCommitmentEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedBufferPageCommitmentARB);
#endif /* GL_ARB_sparse_buffer */

#ifdef GL_ARB_sparse_texture
	ZLGL_LOAD_OPENGL_FUNCTION(glTexPageCommitmentARB);
#endif /* GL_ARB_sparse_texture */

#ifdef GL_ARB_texture_buffer_object
	ZLGL_LOAD_OPENGL_FUNCTION(glTexBufferARB);
#endif /* GL_ARB_texture_buffer_object */

#ifdef GL_KHR_blend_equation_advanced
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendBarrierKHR);
#endif /* GL_KHR_blend_equation_advanced */

#ifdef GL_AMD_performance_monitor
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfMonitorGroupsAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfMonitorCountersAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfMonitorGroupStringAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfMonitorCounterStringAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfMonitorCounterInfoAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenPerfMonitorsAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeletePerfMonitorsAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glSelectPerfMonitorCountersAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glBeginPerfMonitorAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glEndPerfMonitorAMD);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfMonitorCounterDataAMD);
#endif /* GL_AMD_performance_monitor */

#ifdef GL_EXT_debug_label
	ZLGL_LOAD_OPENGL_FUNCTION(glLabelObjectEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetObjectLabelEXT);
#endif /* GL_EXT_debug_label */

#ifdef GL_EXT_debug_marker
	ZLGL_LOAD_OPENGL_FUNCTION(glInsertEventMarkerEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glPushGroupMarkerEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glPopGroupMarkerEXT);
#endif /* GL_EXT_debug_marker */

#ifdef GL_EXT_direct_state_access
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixLoadfEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixLoaddEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixMultfEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixMultdEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixLoadIdentityEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixRotatefEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixRotatedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixScalefEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixScaledEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixTranslatefEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixTranslatedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixFrustumEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixOrthoEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixPopEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixPushEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glClientAttribDefaultEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glPushClientAttribDefaultEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameterfEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameterfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameteriEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureSubImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureSubImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTextureImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTextureImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTextureSubImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTextureSubImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureImageEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureParameterfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureLevelParameterfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureLevelParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureSubImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTextureSubImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindMultiTextureEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexCoordPointerEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexEnvfEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexEnvfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexEnviEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexEnvivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexGendEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexGendvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexGenfEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexGenfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexGeniEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexGenivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexEnvfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexEnvivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexGendvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexGenfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexGenivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexParameteriEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexParameterfEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexParameterfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexSubImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexSubImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyMultiTexImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyMultiTexImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyMultiTexSubImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyMultiTexSubImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexImageEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexParameterfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexLevelParameterfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexLevelParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexSubImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyMultiTexSubImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glEnableClientStateIndexedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glDisableClientStateIndexedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFloatIndexedvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetDoubleIndexedvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPointerIndexedvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glEnableIndexedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glDisableIndexedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsEnabledIndexedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetIntegerIndexedvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetBooleanIndexedvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTextureImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTextureImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTextureImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTextureSubImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTextureSubImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTextureSubImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetCompressedTextureImageEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedMultiTexImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedMultiTexImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedMultiTexImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedMultiTexSubImage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedMultiTexSubImage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedMultiTexSubImage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetCompressedMultiTexImageEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixLoadTransposefEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixLoadTransposedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixMultTransposefEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixMultTransposedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedBufferDataEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedBufferSubDataEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMapNamedBufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glUnmapNamedBufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedBufferParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedBufferPointervEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedBufferSubDataEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1fEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2fEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3fEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4fEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1iEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2iEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3iEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4iEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1ivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2ivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3ivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4ivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2x3fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3x2fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2x4fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4x2fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3x4fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4x3fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureBufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexBufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameterIivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameterIuivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureParameterIivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureParameterIuivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexParameterIivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexParameterIuivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexParameterIivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultiTexParameterIuivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1uiEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2uiEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3uiEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4uiEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1uivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2uivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3uivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4uivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParameters4fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParameterI4iEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParameterI4ivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParametersI4ivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParameterI4uiEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParameterI4uivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParametersI4uivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedProgramLocalParameterIivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedProgramLocalParameterIuivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glEnableClientStateiEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glDisableClientStateiEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFloati_vEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetDoublei_vEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPointeri_vEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramStringEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParameter4dEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParameter4dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParameter4fEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedProgramLocalParameter4fvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedProgramLocalParameterdvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedProgramLocalParameterfvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedProgramivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedProgramStringEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedRenderbufferStorageEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedRenderbufferParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedRenderbufferStorageMultisampleEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedRenderbufferStorageMultisampleCoverageEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCheckNamedFramebufferStatusEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferTexture1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferTexture2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferTexture3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferRenderbufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedFramebufferAttachmentParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenerateTextureMipmapEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenerateMultiTexMipmapEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferDrawBufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferDrawBuffersEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferReadBufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFramebufferParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedCopyBufferSubDataEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferTextureEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferTextureLayerEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferTextureFaceEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureRenderbufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiTexRenderbufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayColorOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayEdgeFlagOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayIndexOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayNormalOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayTexCoordOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayMultiTexCoordOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayFogCoordOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArraySecondaryColorOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexAttribOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexAttribIOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glEnableVertexArrayEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glDisableVertexArrayEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glEnableVertexArrayAttribEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glDisableVertexArrayAttribEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexArrayIntegervEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexArrayPointervEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexArrayIntegeri_vEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexArrayPointeri_vEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glMapNamedBufferRangeEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glFlushMappedNamedBufferRangeEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedBufferStorageEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearNamedBufferDataEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearNamedBufferSubDataEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferParameteriEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedFramebufferParameterivEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1dEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2dEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3dEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4dEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2x3dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2x4dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3x2dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3x4dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4x2dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4x3dvEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureBufferRangeEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage1DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage2DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage3DEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage2DMultisampleEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage3DMultisampleEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayBindVertexBufferEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexAttribFormatEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexAttribIFormatEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexAttribLFormatEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexAttribBindingEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexBindingDivisorEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexAttribLOffsetEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexturePageCommitmentEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexAttribDivisorEXT);
#endif /* GL_EXT_direct_state_access */

#ifdef GL_EXT_draw_instanced
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawArraysInstancedEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawElementsInstancedEXT);
#endif /* GL_EXT_draw_instanced */

#ifdef GL_EXT_polygon_offset_clamp
	ZLGL_LOAD_OPENGL_FUNCTION(glPolygonOffsetClampEXT);
#endif /* GL_EXT_polygon_offset_clamp */

#ifdef GL_EXT_raster_multisample
	ZLGL_LOAD_OPENGL_FUNCTION(glRasterSamplesEXT);
#endif /* GL_EXT_raster_multisample */

#ifdef GL_EXT_separate_shader_objects
	ZLGL_LOAD_OPENGL_FUNCTION(glUseShaderProgramEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glActiveProgramEXT);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateShaderProgramEXT);
#endif /* GL_EXT_separate_shader_objects */

#ifdef GL_EXT_window_rectangles
	ZLGL_LOAD_OPENGL_FUNCTION(glWindowRectanglesEXT);
#endif /* GL_EXT_window_rectangles */

#ifdef GL_INTEL_framebuffer_CMAA
	ZLGL_LOAD_OPENGL_FUNCTION(glApplyFramebufferAttachmentCMAAINTEL);
#endif /* GL_INTEL_framebuffer_CMAA */

#ifdef GL_INTEL_performance_query
	ZLGL_LOAD_OPENGL_FUNCTION(glBeginPerfQueryINTEL);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreatePerfQueryINTEL);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeletePerfQueryINTEL);
	ZLGL_LOAD_OPENGL_FUNCTION(glEndPerfQueryINTEL);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFirstPerfQueryIdINTEL);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNextPerfQueryIdINTEL);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfCounterInfoINTEL);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfQueryDataINTEL);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfQueryIdByNameINTEL);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPerfQueryInfoINTEL);
#endif /* GL_INTEL_performance_query */

#ifdef GL_NV_bindless_multi_draw_indirect
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawArraysIndirectBindlessNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawElementsIndirectBindlessNV);
#endif /* GL_NV_bindless_multi_draw_indirect */

#ifdef GL_NV_bindless_multi_draw_indirect_count
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawArraysIndirectBindlessCountNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawElementsIndirectBindlessCountNV);
#endif /* GL_NV_bindless_multi_draw_indirect_count */

#ifdef GL_NV_bindless_texture
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureHandleNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureSamplerHandleNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeTextureHandleResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeTextureHandleNonResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetImageHandleNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeImageHandleResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeImageHandleNonResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformHandleui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformHandleui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformHandleui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformHandleui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsTextureHandleResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsImageHandleResidentNV);
#endif /* GL_NV_bindless_texture */

#ifdef GL_NV_blend_equation_advanced
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendParameteriNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendBarrierNV);
#endif /* GL_NV_blend_equation_advanced */

#ifdef GL_NV_clip_space_w_scaling
	ZLGL_LOAD_OPENGL_FUNCTION(glViewportPositionWScaleNV);
#endif /* GL_NV_clip_space_w_scaling */

#ifdef GL_NV_command_list
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateStatesNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteStatesNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsStateNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glStateCaptureNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetCommandHeaderNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetStageIndexNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawCommandsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawCommandsAddressNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawCommandsStatesNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawCommandsStatesAddressNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateCommandListsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteCommandListsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsCommandListNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glListDrawCommandsStatesClientNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCommandListSegmentsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompileCommandListNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCallCommandListNV);
#endif /* GL_NV_command_list */

#ifdef GL_NV_conditional_render
	ZLGL_LOAD_OPENGL_FUNCTION(glBeginConditionalRenderNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glEndConditionalRenderNV);
#endif /* GL_NV_conditional_render */

#ifdef GL_NV_conservative_raster
	ZLGL_LOAD_OPENGL_FUNCTION(glSubpixelPrecisionBiasNV);
#endif /* GL_NV_conservative_raster */

#ifdef GL_NV_conservative_raster_dilate
	ZLGL_LOAD_OPENGL_FUNCTION(glConservativeRasterParameterfNV);
#endif /* GL_NV_conservative_raster_dilate */

#ifdef GL_NV_conservative_raster_pre_snap_triangles
	ZLGL_LOAD_OPENGL_FUNCTION(glConservativeRasterParameteriNV);
#endif /* GL_NV_conservative_raster_pre_snap_triangles */

#ifdef GL_NV_draw_vulkan_image
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawVkImageNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVkProcAddrNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glWaitVkSemaphoreNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glSignalVkSemaphoreNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glSignalVkFenceNV);
#endif /* GL_NV_draw_vulkan_image */

#ifdef GL_NV_fragment_coverage_to_color
	ZLGL_LOAD_OPENGL_FUNCTION(glFragmentCoverageColorNV);
#endif /* GL_NV_fragment_coverage_to_color */

#ifdef GL_NV_framebuffer_mixed_samples
	ZLGL_LOAD_OPENGL_FUNCTION(glCoverageModulationTableNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetCoverageModulationTableNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCoverageModulationNV);
#endif /* GL_NV_framebuffer_mixed_samples */

#ifdef GL_NV_framebuffer_multisample_coverage
	ZLGL_LOAD_OPENGL_FUNCTION(glRenderbufferStorageMultisampleCoverageNV);
#endif /* GL_NV_framebuffer_multisample_coverage */

#ifdef GL_NV_gpu_shader5
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformi64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4ui64vNV);
#endif /* GL_NV_gpu_shader5 */

#ifdef GL_NV_internalformat_sample_query
	ZLGL_LOAD_OPENGL_FUNCTION(glGetInternalformatSampleivNV);
#endif /* GL_NV_internalformat_sample_query */

#ifdef GL_NV_path_rendering
	ZLGL_LOAD_OPENGL_FUNCTION(glGenPathsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeletePathsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsPathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathCommandsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathCoordsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathSubCommandsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathSubCoordsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathStringNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathGlyphsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathGlyphRangeNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glWeightPathsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyPathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glInterpolatePathsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glTransformPathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathParameterivNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathParameteriNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathParameterfvNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathParameterfNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathDashArrayNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathStencilFuncNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathStencilDepthOffsetNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilFillPathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilStrokePathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilFillPathInstancedNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilStrokePathInstancedNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathCoverDepthFuncNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCoverFillPathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCoverStrokePathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCoverFillPathInstancedNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glCoverStrokePathInstancedNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPathParameterivNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPathParameterfvNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPathCommandsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPathCoordsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPathDashArrayNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPathMetricsNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPathMetricRangeNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPathSpacingNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsPointInFillPathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsPointInStrokePathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPathLengthNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPointAlongPathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixLoad3x2fNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixLoad3x3fNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixLoadTranspose3x3fNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixMult3x2fNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixMult3x3fNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMatrixMultTranspose3x3fNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilThenCoverFillPathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilThenCoverStrokePathNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilThenCoverFillPathInstancedNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilThenCoverStrokePathInstancedNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathGlyphIndexRangeNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathGlyphIndexArrayNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glPathMemoryGlyphIndexArrayNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramPathFragmentInputGenNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramResourcefvNV);
#endif /* GL_NV_path_rendering */

#ifdef GL_NV_sample_locations
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferSampleLocationsfvNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferSampleLocationsfvNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glResolveDepthValuesNV);
#endif /* GL_NV_sample_locations */

#ifdef GL_NV_shader_buffer_load
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeBufferResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeBufferNonResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsBufferResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeNamedBufferResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glMakeNamedBufferNonResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsNamedBufferResidentNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetBufferParameterui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedBufferParameterui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetIntegerui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformui64vNV);
#endif /* GL_NV_shader_buffer_load */

#ifdef GL_NV_texture_barrier
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureBarrierNV);
#endif /* GL_NV_texture_barrier */

#ifdef GL_NV_vertex_attrib_integer_64bit
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL1i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL2i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL3i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL4i64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL1i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL2i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL3i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL4i64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL1ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL2ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL3ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL4ui64NV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL1ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL2ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL3ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL4ui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribLi64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribLui64vNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribLFormatNV);
#endif /* GL_NV_vertex_attrib_integer_64bit */

#ifdef GL_NV_vertex_buffer_unified_memory
	ZLGL_LOAD_OPENGL_FUNCTION(glBufferAddressRangeNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glNormalFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glColorFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glIndexFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexCoordFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glEdgeFlagFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glSecondaryColorFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glFogCoordFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribIFormatNV);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetIntegerui64i_vNV);
#endif /* GL_NV_vertex_buffer_unified_memory */

#ifdef GL_NV_viewport_swizzle
	ZLGL_LOAD_OPENGL_FUNCTION(glViewportSwizzleNV);
#endif /* GL_NV_viewport_swizzle */

#ifdef GL_OVR_multiview
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferTextureMultiviewOVR);
#endif /* GL_OVR_multiview */
}

static void 
zlgl_load_functions_1_0_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glCullFace);
	ZLGL_LOAD_OPENGL_FUNCTION(glFrontFace);
	ZLGL_LOAD_OPENGL_FUNCTION(glHint);
	ZLGL_LOAD_OPENGL_FUNCTION(glLineWidth);
	ZLGL_LOAD_OPENGL_FUNCTION(glPointSize);
	ZLGL_LOAD_OPENGL_FUNCTION(glPolygonMode);
	ZLGL_LOAD_OPENGL_FUNCTION(glScissor);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexParameterf);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexParameteri);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexImage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexImage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glClear);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearColor);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearStencil);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearDepth);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilMask);
	ZLGL_LOAD_OPENGL_FUNCTION(glColorMask);
	ZLGL_LOAD_OPENGL_FUNCTION(glDepthMask);
	ZLGL_LOAD_OPENGL_FUNCTION(glDisable);
	ZLGL_LOAD_OPENGL_FUNCTION(glEnable);
	ZLGL_LOAD_OPENGL_FUNCTION(glFinish);
	ZLGL_LOAD_OPENGL_FUNCTION(glFlush);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendFunc);
	ZLGL_LOAD_OPENGL_FUNCTION(glLogicOp);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilFunc);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilOp);
	ZLGL_LOAD_OPENGL_FUNCTION(glDepthFunc);
	ZLGL_LOAD_OPENGL_FUNCTION(glPixelStoref);
	ZLGL_LOAD_OPENGL_FUNCTION(glPixelStorei);
	ZLGL_LOAD_OPENGL_FUNCTION(glReadBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glReadPixels);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetBooleanv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetDoublev);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetError);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFloatv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetIntegerv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetString);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTexImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTexParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTexParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTexLevelParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTexLevelParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsEnabled);
	ZLGL_LOAD_OPENGL_FUNCTION(glDepthRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glViewport);
}

static void zlgl_load_functions_1_1_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawArrays);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawElements);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetPointerv);
	ZLGL_LOAD_OPENGL_FUNCTION(glPolygonOffset);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTexImage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTexImage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTexSubImage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTexSubImage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexSubImage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexSubImage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindTexture);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteTextures);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenTextures);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsTexture);
	zlgl_load_functions_1_0_internal();
}

static void zlgl_load_functions_1_2_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawRangeElements);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexImage3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexSubImage3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTexSubImage3D);
	zlgl_load_functions_1_1_internal();
}

static void zlgl_load_functions_1_3_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glActiveTexture);
	ZLGL_LOAD_OPENGL_FUNCTION(glSampleCoverage);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTexImage3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTexImage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTexImage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTexSubImage3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTexSubImage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTexSubImage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetCompressedTexImage);
	zlgl_load_functions_1_2_internal();
}

static void zlgl_load_functions_1_4_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendFuncSeparate);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawArrays);
	ZLGL_LOAD_OPENGL_FUNCTION(glPointParameterf);
	ZLGL_LOAD_OPENGL_FUNCTION(glPointParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glPointParameteri);
	ZLGL_LOAD_OPENGL_FUNCTION(glPointParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendColor);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendEquation);
	zlgl_load_functions_1_3_internal();
}

static void zlgl_load_functions_1_5_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glGenQueries);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteQueries);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsQuery);
	ZLGL_LOAD_OPENGL_FUNCTION(glBeginQuery);
	ZLGL_LOAD_OPENGL_FUNCTION(glEndQuery);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryObjectiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryObjectuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteBuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenBuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glBufferData);
	ZLGL_LOAD_OPENGL_FUNCTION(glBufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetBufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glMapBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glUnmapBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetBufferParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetBufferPointerv);
	zlgl_load_functions_1_4_internal();
}

static void zlgl_load_functions_2_0_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendEquationSeparate);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawBuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilOpSeparate);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilFuncSeparate);
	ZLGL_LOAD_OPENGL_FUNCTION(glStencilMaskSeparate);
	ZLGL_LOAD_OPENGL_FUNCTION(glAttachShader);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindAttribLocation);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompileShader);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateProgram);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateShader);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteProgram);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteShader);
	ZLGL_LOAD_OPENGL_FUNCTION(glDetachShader);
	ZLGL_LOAD_OPENGL_FUNCTION(glDisableVertexAttribArray);
	ZLGL_LOAD_OPENGL_FUNCTION(glEnableVertexAttribArray);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveAttrib);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveUniform);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetAttachedShaders);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetAttribLocation);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramInfoLog);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetShaderiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetShaderInfoLog);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetShaderSource);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformLocation);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribdv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribPointerv);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsProgram);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsShader);
	ZLGL_LOAD_OPENGL_FUNCTION(glLinkProgram);
	ZLGL_LOAD_OPENGL_FUNCTION(glShaderSource);
	ZLGL_LOAD_OPENGL_FUNCTION(glUseProgram);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1f);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2f);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3f);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4f);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1i);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2i);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3i);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4i);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix2fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix3fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix4fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glValidateProgram);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib1d);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib1dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib1f);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib1fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib1s);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib1sv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib2d);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib2f);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib2fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib2s);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib2sv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib3d);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib3f);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib3fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib3s);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib3sv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4Nbv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4Niv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4Nsv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4Nub);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4Nubv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4Nuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4Nusv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4bv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4d);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4f);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4s);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4sv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4ubv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttrib4usv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribPointer);
	zlgl_load_functions_1_5_internal();
}

static void zlgl_load_functions_2_1_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix2x3fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix3x2fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix2x4fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix4x2fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix3x4fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix4x3fv);
	zlgl_load_functions_2_0_internal();
}

static void zlgl_load_functions_3_0_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glColorMaski);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetBooleani_v);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetIntegeri_v);
	ZLGL_LOAD_OPENGL_FUNCTION(glEnablei);
	ZLGL_LOAD_OPENGL_FUNCTION(glDisablei);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsEnabledi);
	ZLGL_LOAD_OPENGL_FUNCTION(glBeginTransformFeedback);
	ZLGL_LOAD_OPENGL_FUNCTION(glEndTransformFeedback);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindBufferRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindBufferBase);
	ZLGL_LOAD_OPENGL_FUNCTION(glTransformFeedbackVaryings);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTransformFeedbackVarying);
	ZLGL_LOAD_OPENGL_FUNCTION(glClampColor);
	ZLGL_LOAD_OPENGL_FUNCTION(glBeginConditionalRender);
	ZLGL_LOAD_OPENGL_FUNCTION(glEndConditionalRender);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribIPointer);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribIiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribIuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI1i);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI2i);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI3i);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI4i);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI1ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI2ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI3ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI4ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI1iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI2iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI3iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI4iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI1uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI2uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI3uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI4uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI4bv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI4sv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI4ubv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribI4usv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindFragDataLocation);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFragDataLocation);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexParameterIiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexParameterIuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTexParameterIiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTexParameterIuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearBufferiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearBufferuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearBufferfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearBufferfi);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetStringi);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsRenderbuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindRenderbuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteRenderbuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenRenderbuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glRenderbufferStorage);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetRenderbufferParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsFramebuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindFramebuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteFramebuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenFramebuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glCheckFramebufferStatus);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferTexture1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferTexture2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferTexture3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferRenderbuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFramebufferAttachmentParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenerateMipmap);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlitFramebuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glRenderbufferStorageMultisample);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferTextureLayer);
	ZLGL_LOAD_OPENGL_FUNCTION(glMapBufferRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glFlushMappedBufferRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindVertexArray);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteVertexArrays);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenVertexArrays);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsVertexArray);
	zlgl_load_functions_2_1_internal();
}

static void zlgl_load_functions_3_1_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawArraysInstanced);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawElementsInstanced);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glPrimitiveRestartIndex);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyBufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformIndices);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveUniformsiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveUniformName);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformBlockIndex);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveUniformBlockiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveUniformBlockName);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformBlockBinding);
	zlgl_load_functions_3_0_internal();
}


static void zlgl_load_functions_3_2_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawElementsBaseVertex);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawRangeElementsBaseVertex);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawElementsInstancedBaseVertex);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawElementsBaseVertex);
	ZLGL_LOAD_OPENGL_FUNCTION(glProvokingVertex);
	ZLGL_LOAD_OPENGL_FUNCTION(glFenceSync);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsSync);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteSync);
	ZLGL_LOAD_OPENGL_FUNCTION(glClientWaitSync);
	ZLGL_LOAD_OPENGL_FUNCTION(glWaitSync);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetInteger64v);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetSynciv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetInteger64i_v);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetBufferParameteri64v);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferTexture);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexImage2DMultisample);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexImage3DMultisample);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetMultisamplefv);
	ZLGL_LOAD_OPENGL_FUNCTION(glSampleMaski); 
	zlgl_load_functions_3_1_internal();
}

static void zlgl_load_functions_3_3_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glBindFragDataLocationIndexed);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFragDataIndex);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenSamplers);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteSamplers);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsSampler);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindSampler);
	ZLGL_LOAD_OPENGL_FUNCTION(glSamplerParameteri);
	ZLGL_LOAD_OPENGL_FUNCTION(glSamplerParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glSamplerParameterf);
	ZLGL_LOAD_OPENGL_FUNCTION(glSamplerParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glSamplerParameterIiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glSamplerParameterIuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetSamplerParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetSamplerParameterIiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetSamplerParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetSamplerParameterIuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glQueryCounter);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryObjecti64v);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryObjectui64v);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribDivisor);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribP1ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribP1uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribP2ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribP2uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribP3ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribP3uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribP4ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribP4uiv);
	zlgl_load_functions_3_2_internal();
}

static void zlgl_load_functions_4_0_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glMinSampleShading);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendEquationi);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendEquationSeparatei);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendFunci);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlendFuncSeparatei);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawArraysIndirect);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawElementsIndirect);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1d);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2d);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3d);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4d);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform1dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniform4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix2x3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix3x2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix2x4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix3x4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix4x3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformMatrix4x2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformdv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetSubroutineUniformLocation);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetSubroutineIndex);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveSubroutineUniformiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveSubroutineUniformName);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveSubroutineName);
	ZLGL_LOAD_OPENGL_FUNCTION(glUniformSubroutinesuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetUniformSubroutineuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramStageiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glPatchParameteri);
	ZLGL_LOAD_OPENGL_FUNCTION(glPatchParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindTransformFeedback);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteTransformFeedbacks);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenTransformFeedbacks);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsTransformFeedback);
	ZLGL_LOAD_OPENGL_FUNCTION(glPauseTransformFeedback);
	ZLGL_LOAD_OPENGL_FUNCTION(glResumeTransformFeedback);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawTransformFeedback);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawTransformFeedbackStream);
	ZLGL_LOAD_OPENGL_FUNCTION(glBeginQueryIndexed);
	ZLGL_LOAD_OPENGL_FUNCTION(glEndQueryIndexed);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryIndexediv);
	zlgl_load_functions_3_3_internal();
}

static void zlgl_load_functions_4_1_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glReleaseShaderCompiler);
	ZLGL_LOAD_OPENGL_FUNCTION(glShaderBinary);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetShaderPrecisionFormat);
	ZLGL_LOAD_OPENGL_FUNCTION(glDepthRangef);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearDepthf);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramBinary);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramParameteri);
	ZLGL_LOAD_OPENGL_FUNCTION(glUseProgramStages);
	ZLGL_LOAD_OPENGL_FUNCTION(glActiveShaderProgram);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateShaderProgramv);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindProgramPipeline);
	ZLGL_LOAD_OPENGL_FUNCTION(glDeleteProgramPipelines);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenProgramPipelines);
	ZLGL_LOAD_OPENGL_FUNCTION(glIsProgramPipeline);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramPipelineiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1i);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1f);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1d);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform1uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2i);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2f);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2d);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform2uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3i);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3f);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3d);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform3uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4i);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4f);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4d);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4ui);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniform4uiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2x3fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3x2fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2x4fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4x2fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3x4fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4x3fv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2x3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3x2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix2x4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4x2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix3x4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glProgramUniformMatrix4x3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glValidateProgramPipeline);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramPipelineInfoLog);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL1d);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL2d);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL3d);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL4d);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL1dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL2dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL3dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribL4dv);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribLPointer);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexAttribLdv);
	ZLGL_LOAD_OPENGL_FUNCTION(glViewportArrayv);
	ZLGL_LOAD_OPENGL_FUNCTION(glViewportIndexedf);
	ZLGL_LOAD_OPENGL_FUNCTION(glViewportIndexedfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glScissorArrayv);
	ZLGL_LOAD_OPENGL_FUNCTION(glScissorIndexed);
	ZLGL_LOAD_OPENGL_FUNCTION(glScissorIndexedv);
	ZLGL_LOAD_OPENGL_FUNCTION(glDepthRangeArrayv);
	ZLGL_LOAD_OPENGL_FUNCTION(glDepthRangeIndexed);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFloati_v);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetDoublei_v); 
	zlgl_load_functions_4_0_internal();
}

static void zlgl_load_functions_4_2_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawArraysInstancedBaseInstance);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawElementsInstancedBaseInstance);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawElementsInstancedBaseVertexBaseInstance);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetInternalformativ);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetActiveAtomicCounterBufferiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindImageTexture);
	ZLGL_LOAD_OPENGL_FUNCTION(glMemoryBarrier);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexStorage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexStorage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexStorage3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawTransformFeedbackInstanced);
	ZLGL_LOAD_OPENGL_FUNCTION(glDrawTransformFeedbackStreamInstanced);
	zlgl_load_functions_4_1_internal();
}

static void zlgl_load_functions_4_3_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glClearBufferData);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearBufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glDispatchCompute);
	ZLGL_LOAD_OPENGL_FUNCTION(glDispatchComputeIndirect);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyImageSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glFramebufferParameteri);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetFramebufferParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetInternalformati64v);
	ZLGL_LOAD_OPENGL_FUNCTION(glInvalidateTexSubImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glInvalidateTexImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glInvalidateBufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glInvalidateBufferData);
	ZLGL_LOAD_OPENGL_FUNCTION(glInvalidateFramebuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glInvalidateSubFramebuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawArraysIndirect);
	ZLGL_LOAD_OPENGL_FUNCTION(glMultiDrawElementsIndirect);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramInterfaceiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramResourceIndex);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramResourceName);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramResourceiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramResourceLocation);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetProgramResourceLocationIndex);
	ZLGL_LOAD_OPENGL_FUNCTION(glShaderStorageBlockBinding);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexBufferRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexStorage2DMultisample);
	ZLGL_LOAD_OPENGL_FUNCTION(glTexStorage3DMultisample);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureView);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindVertexBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribFormat);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribIFormat);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribLFormat);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexAttribBinding);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexBindingDivisor);
	ZLGL_LOAD_OPENGL_FUNCTION(glDebugMessageControl);
	ZLGL_LOAD_OPENGL_FUNCTION(glDebugMessageInsert);
	ZLGL_LOAD_OPENGL_FUNCTION(glDebugMessageCallback);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetDebugMessageLog);
	ZLGL_LOAD_OPENGL_FUNCTION(glPushDebugGroup);
	ZLGL_LOAD_OPENGL_FUNCTION(glPopDebugGroup);
	ZLGL_LOAD_OPENGL_FUNCTION(glObjectLabel);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetObjectLabel);
	ZLGL_LOAD_OPENGL_FUNCTION(glObjectPtrLabel);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetObjectPtrLabel);
	zlgl_load_functions_4_2_internal();
}

static void zlgl_load_functions_4_4_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glBufferStorage);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearTexImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearTexSubImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindBuffersBase);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindBuffersRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindTextures);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindSamplers);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindImageTextures);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindVertexBuffers);
	zlgl_load_functions_4_3_internal();
}

static void zlgl_load_functions_4_5_internal()
{
	ZLGL_LOAD_OPENGL_FUNCTION(glClipControl);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateTransformFeedbacks);
	ZLGL_LOAD_OPENGL_FUNCTION(glTransformFeedbackBufferBase);
	ZLGL_LOAD_OPENGL_FUNCTION(glTransformFeedbackBufferRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTransformFeedbackiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTransformFeedbacki_v);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTransformFeedbacki64_v);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateBuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedBufferStorage);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedBufferData);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedBufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyNamedBufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearNamedBufferData);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearNamedBufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glMapNamedBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glMapNamedBufferRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glUnmapNamedBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glFlushMappedNamedBufferRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedBufferParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedBufferParameteri64v);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedBufferPointerv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedBufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateFramebuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferRenderbuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferParameteri);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferTexture);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferTextureLayer);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferDrawBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferDrawBuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedFramebufferReadBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glInvalidateNamedFramebufferData);
	ZLGL_LOAD_OPENGL_FUNCTION(glInvalidateNamedFramebufferSubData);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearNamedFramebufferiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearNamedFramebufferuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearNamedFramebufferfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glClearNamedFramebufferfi);
	ZLGL_LOAD_OPENGL_FUNCTION(glBlitNamedFramebuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glCheckNamedFramebufferStatus);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedFramebufferParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedFramebufferAttachmentParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateRenderbuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedRenderbufferStorage);
	ZLGL_LOAD_OPENGL_FUNCTION(glNamedRenderbufferStorageMultisample);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetNamedRenderbufferParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateTextures);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureBufferRange);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage2DMultisample);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureStorage3DMultisample);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureSubImage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureSubImage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureSubImage3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTextureSubImage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTextureSubImage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCompressedTextureSubImage3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTextureSubImage1D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTextureSubImage2D);
	ZLGL_LOAD_OPENGL_FUNCTION(glCopyTextureSubImage3D);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameterf);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameteri);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameterIiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameterIuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGenerateTextureMipmap);
	ZLGL_LOAD_OPENGL_FUNCTION(glBindTextureUnit);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetCompressedTextureImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureLevelParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureLevelParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureParameterfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureParameterIiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureParameterIuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureParameteriv);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateVertexArrays);
	ZLGL_LOAD_OPENGL_FUNCTION(glDisableVertexArrayAttrib);
	ZLGL_LOAD_OPENGL_FUNCTION(glEnableVertexArrayAttrib);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayElementBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexBuffer);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayVertexBuffers);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayAttribBinding);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayAttribFormat);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayAttribIFormat);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayAttribLFormat);
	ZLGL_LOAD_OPENGL_FUNCTION(glVertexArrayBindingDivisor);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexArrayiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexArrayIndexediv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetVertexArrayIndexed64iv);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateSamplers);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateProgramPipelines);
	ZLGL_LOAD_OPENGL_FUNCTION(glCreateQueries);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryBufferObjecti64v);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryBufferObjectiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryBufferObjectui64v);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetQueryBufferObjectuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glMemoryBarrierByRegion);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetTextureSubImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetCompressedTextureSubImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetGraphicsResetStatus);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnCompressedTexImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnTexImage);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformdv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformfv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glGetnUniformuiv);
	ZLGL_LOAD_OPENGL_FUNCTION(glReadnPixels);
	ZLGL_LOAD_OPENGL_FUNCTION(glTextureBarrier);
	zlgl_load_functions_4_4_internal();
}

static void zlgl_LoadOpenGLFunctions(ZLGL_opengl_version Version)
{
	if (Version >= ZLGL_opengl_4_5)
	{
		zlgl_load_functions_4_5_internal();
	}
	else if (Version >= ZLGL_opengl_4_4)
	{
		zlgl_load_functions_4_4_internal();
	}
	else if (Version >= ZLGL_opengl_4_3)
	{
		zlgl_load_functions_4_3_internal();
	}
	else if (Version >= ZLGL_opengl_4_2)
	{
		zlgl_load_functions_4_2_internal();
	}
	else if (Version >= ZLGL_opengl_4_1)
	{
		zlgl_load_functions_4_1_internal();
	}
	else if (Version >= ZLGL_opengl_4_0)
	{
		zlgl_load_functions_4_0_internal();
	}
	else if (Version >= ZLGL_opengl_3_3)
	{
		zlgl_load_functions_3_3_internal();
	}
	else if (Version >= ZLGL_opengl_3_2)
	{
		zlgl_load_functions_3_2_internal();
	}
	else if (Version >= ZLGL_opengl_3_1)
	{
		zlgl_load_functions_3_1_internal();
	}
	else if (Version >= ZLGL_opengl_3_0)
	{
		zlgl_load_functions_3_0_internal();
	}
	else if (Version >= ZLGL_opengl_2_1)
	{
		zlgl_load_functions_2_1_internal();
	}
	else if (Version >= ZLGL_opengl_2_0)
	{
		zlgl_load_functions_2_0_internal();
	}
	else if (Version >= ZLGL_opengl_1_5)
	{
		zlgl_load_functions_1_5_internal();
	}
	else if (Version >= ZLGL_opengl_1_4)
	{
		zlgl_load_functions_1_4_internal();
	}
	else if (Version >= ZLGL_opengl_1_3)
	{
		zlgl_load_functions_1_3_internal();
	}
	else if (Version >= ZLGL_opengl_1_2)
	{
		zlgl_load_functions_1_2_internal();
	}
	else if(Version >= ZLGL_opengl_1_1)
	{
		zlgl_load_functions_1_1_internal();
	}
	else
	{
		zlgl_load_functions_1_0_internal();
	}
}
#ifdef __cplusplus
}
#endif

#endif //__zlgl_core_h__