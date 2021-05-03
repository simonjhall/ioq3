/*
 * entry_points.c
 *
 *  Created on: 19 Apr 2020
 *      Author: simon
 */

#include <assert.h>
#ifdef USE_LOCAL_HEADERS
#	include "SDL.h"
#else
#	include <SDL.h>
#endif

#include "../renderercommon/tr_common.h"

#include "entry_points.h"
#include "serialise.h"

#define MAX_TEXTURE_SIZE 1024

static int enumToByteSize(GLenum type)
{
	int el_size = 0;
	switch (type)
	{
		case GL_BYTE:
		case GL_UNSIGNED_BYTE:
			el_size = 1;
			break;
		case GL_SHORT:
		case GL_UNSIGNED_SHORT:
			el_size = 2;
			break;
		case GL_INT:
		case GL_UNSIGNED_INT:
			el_size = 4;
			break;
		case GL_FLOAT:
			el_size = 4;
			break;
		case GL_DOUBLE:
			el_size = 8;
			break;
		default:
			assert(0);
	}

	return el_size;
}

//////////////////////

void fpgaglActiveTextureARB(GLenum texture)
{
	EmitFunc(ActiveTextureARB);
	EmitArg(texture);
}

void fpgaglAlphaFunc(GLenum func, GLclampf ref)
{
	EmitFunc(AlphaFunc);
	EmitArg(func);
	EmitArg(ref);
}

void fpgaglArrayElement(GLint i)
{
	assert(0);
}

void fpgaglBegin(GLenum mode)
{
	assert(mode == GL_TRIANGLES);
	EmitFunc(Begin);
	EmitArg(mode);
}

void fpgaglBindProgramARB (GLenum target, GLuint program)
{
	EmitFunc(BindProgramARB);
	EmitArg(target);
	EmitArg(program);
}

void fpgaglBindTexture(GLenum target, GLuint texture)
{
	EmitFunc(BindTexture);
	EmitArg(target);
	EmitArg(texture);
}

void fpgaglBlendFunc(GLenum sfactor, GLenum dfactor)
{
	EmitFunc(BlendFunc);
	EmitArg(sfactor);
	EmitArg(dfactor);
}

void fpgaglClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	EmitFunc(ClearColor);
	EmitArg(red);
	EmitArg(green);
	EmitArg(blue);
	EmitArg(alpha);
}

void fpgaglClear(GLbitfield mask)
{
	EmitFunc(Clear);
	EmitArg(mask);
}

void fpgaglClearStencil(GLint s)
{
	EmitFunc(ClearStencil);
	EmitArg(s);
}

void fpgaglClientActiveTextureARB(GLenum texture)
{
	EmitFunc(ClientActiveTextureARB);
	EmitArg(texture);
}

void fpgaglClipPlane(GLenum plane, const GLdouble *equation)
{
	assert(0);
}

void fpgaglColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
	EmitFunc(Color3f);
	EmitArg(red);
	EmitArg(green);
	EmitArg(blue);
}

void fpgaglColor4ubv(const GLubyte *v)
{
	assert(0);
}

void fpgaglClearDepth(GLclampd depth)
{
	EmitFunc(ClearDepth);
	EmitArg(depth);
}

void fpgaglColor3fv(const GLfloat *v)
{
	fpgaglColor4f(v[0], v[1], v[2], 1.0f);
}

void fpgaglColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
	fpgaglColor4ub(red, green, blue, 255);
}

void fpgaglColor3ubv(const GLubyte *v)
{
	fpgaglColor3ub(v[0], v[1], v[2]);
}

void fpgaglColor4fv(const GLfloat *v)
{
	fpgaglColor4f(v[0], v[1], v[2], v[3]);
}

void fpgaglColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	EmitFunc(Color4f);
	EmitArg(red);
	EmitArg(green);
	EmitArg(blue);
	EmitArg(alpha);
}

void fpgaglColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
	EmitFunc(Color4ub);
	EmitArg(red);
	EmitArg(green);
	EmitArg(blue);
	EmitArg(alpha);
}

void fpgaglColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	EmitFunc(ColorMask);
	EmitArg(red);
	EmitArg(green);
	EmitArg(blue);
	EmitArg(alpha);
}

void fpgaglColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
	assert(0);
}


void fpgaglColorPointerSIMON(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr, GLint numverts)
{
	EmitFunc(ColorPointer);
	EmitArg(size);
	EmitArg(type);
	EmitArg(stride);

	int el_size = enumToByteSize(type);
	if (stride == 0)
		EmitArray((char *)ptr, size * el_size * numverts);
	else
		EmitArray((char *)ptr, stride * numverts);
}

void fpgaglCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	assert(0);
}

void fpgaglCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	assert(0);
}

void fpgaglCullFace(GLenum mode)
{
	EmitFunc(CullFace);
	EmitArg(mode);
}

void fpgaglDeleteTextures(GLsizei n, const GLuint *textures)
{
	EmitFunc(DeleteTextures);
	EmitArg(n);
	EmitArray(textures, n);
}

void fpgaglDepthFunc(GLenum func)
{
	EmitFunc(DepthFunc);
	EmitArg(func);
}

void fpgaglDepthMask(GLboolean flag)
{
	EmitFunc(DepthMask);
	EmitArg(flag);
}

void fpgaglDepthRange(GLclampd near_val, GLclampd far_val)
{
	EmitFunc(DepthRange);
	EmitArg(near_val);
	EmitArg(far_val);
}

void fpgaglDisable(GLenum cap)
{
	EmitFunc(Disable);
	EmitArg(cap);
}

void fpgaglDisableClientState(GLenum cap)
{
	EmitFunc(DisableClientState);
	EmitArg(cap);
}

void fpgaglDisableVertexAttribArrayARB (GLuint index)
{
	EmitFunc(DisableVertexAttribArrayARB);
	EmitArg(index);
}

void fpgaglDrawArrays(GLenum mode, GLint first, GLsizei count)
{
	assert(0);
}

void fpgaglDrawBuffer(GLenum mode)
{
	EmitFunc(DrawBuffer);
	EmitArg(mode);
}

void fpgaglDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
	EmitFunc(DrawElements);
	EmitArg(mode);
	EmitArg(count);
	EmitArg(type);

	assert(type == GL_UNSIGNED_INT);
	assert(mode == GL_TRIANGLES);

	int el_size = enumToByteSize(type);
	EmitArray((char *)indices, el_size * count);
}

void fpgaglDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	EmitFunc(DrawPixels);
	EmitArg(width);
	EmitArg(height);
	EmitArg(format);
	EmitArg(type);
	assert(0);
}

void fpgaglEnable(GLenum cap)
{
	EmitFunc(Enable);
	EmitArg(cap);
}

void fpgaglEnableClientState(GLenum cap)
{
	EmitFunc(EnableClientState);
	EmitArg(cap);
}

void fpgaglEnableVertexAttribArrayARB (GLuint index)
{
	EmitFunc(EnableVertexAttribArrayARB);
	EmitArg(index);
}

void fpgaglEnd(void)
{
	EmitFunc(End);
}

void fpgaglFinish(void)
{
	EmitFunc(Finish);
}

void fpgaglFlush(void)
{
	assert(0);
}

void fpgaglFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val)
{
	assert(0);
}

void fpgaglGenTextures(GLsizei n, GLuint *textures )
{
	static int id = 1;

	EmitFunc(GenTextures);
	EmitArg(n);

	for (int count = 0; count < n; count++)
		textures[count] = id++;

	EmitArray(textures, n);
}

void fpgaglGenProgramsARB (GLsizei n, GLuint *programs)
{
	assert(0);
}

void fpgaglGetBooleanv(GLenum pname, GLboolean *params)
{
	assert(0);
}

GLenum fpgaglGetError(void)
{
	return 0;
}

void fpgaglGetFloatv(GLenum pname, GLfloat *params)
{
	assert(0);
}

void fpgaglGetIntegerv(GLenum pname, GLint *params)
{
	assert(params);

	switch (pname)
	{
		case GL_MAX_TEXTURE_SIZE:
			*params = MAX_TEXTURE_SIZE;
			break;
		case GL_NUM_EXTENSIONS:
			*params = 0;
			break;
		case GL_MAX_TEXTURE_COORDS_ARB:
		case GL_MAX_TEXTURE_IMAGE_UNITS_ARB:
		case GL_MAX_TEXTURE_UNITS_ARB:
			*params = 3;
			break;
		case GL_PROGRAM_ERROR_POSITION_ARB:
			*params = -1;
			break;
		default:
			assert(!"invalid pname");
			*params = 0;
			break;
	}
}

const GLubyte *fpgaglGetString(GLenum name)
{
	switch (name)
	{
		case GL_VENDOR:		return (const GLubyte *)"Simon Hall";
		case GL_RENDERER:	return (const GLubyte *)"FPGA renderer";
		case GL_VERSION:	return (const GLubyte *)"1.0";
		case GL_EXTENSIONS:	return (const GLubyte *)"no extensions";
		default:
			assert(!"unknown glGetString");
			return (const GLubyte *)"unknown glGetString";
	}
}

const GLubyte *fpgaglGetStringi(GLenum name, GLuint index)
{
	assert(!"glGetStringi");
	return 0;
}

void fpgaglGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
{
	assert(0);
}

void fpgaglLineWidth(GLfloat width)
{
	assert(0);
}

void fpgaglLoadIdentity(void)
{
	EmitFunc(LoadIdentity);
}

void fpgaglLoadMatrixf(const GLfloat *m)
{
	EmitFunc(LoadMatrixf);
	EmitArray(m, 16);
}

void fpgaglLockArraysEXT(GLint first, GLsizei count)
{
	EmitFunc(LockArraysEXT);
	EmitArg(first);
	EmitArg(count);
}

void fpgaglMatrixMode(GLenum mode)
{
	EmitFunc(MatrixMode);
	EmitArg(mode);
}

void fpgaglMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t)
{
	EmitFunc(MultiTexCoord2fARB);
	EmitArg(target);
	EmitArg(s);
	EmitArg(t);
}

void fpgaglMultiTexCoord2fvARB(GLenum texture, GLfloat *st)
{
	fpgaglMultiTexCoord2fARB(texture, st[0], st[1]);
}

void fpgaglNormalPointer(GLenum type, GLsizei stride, const GLvoid *ptr)
{
	assert(0);
}

void fpgaglNormalPointerSIMON(GLenum type, GLsizei stride, const GLvoid *ptr, GLint numverts)
{
	EmitFunc(NormalPointer);
	EmitArg(type);
	EmitArg(stride);

	int el_size = enumToByteSize(type);
	if (stride == 0)
		EmitArray((char *)ptr, 3 * el_size * numverts);
	else
		EmitArray((char *)ptr, stride * numverts);
}

void fpgaglOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val)
{
	EmitFunc(Ortho);
	EmitArg(left);
	EmitArg(right);
	EmitArg(bottom);
	EmitArg(top);
	EmitArg(near_val);
	EmitArg(far_val);
}

void fpgaglPixelStorei(GLenum pname, GLint param)
{
	assert(0);
}

void fpgaglPixelZoom(GLfloat xfactor, GLfloat yfactor)
{
	assert(0);
}

void fpgaglPointSize(GLfloat size)
{
	assert(0);
}

void fpgaglPolygonOffset(GLfloat factor, GLfloat units)
{
	EmitFunc(PolygonOffset);
	EmitArg(factor);
	EmitArg(units);
}

void fpgaglPolygonMode(GLenum face, GLenum mode)
{
	EmitFunc(PolygonMode);
	assert(face == GL_FRONT_AND_BACK);
	EmitArg(mode);
}

void fpgaglPopAttrib(void)
{
	assert(0);
}

void fpgaglPopMatrix(void)
{
	EmitFunc(PopMatrix);
}

void fpgaglPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities)
{
	assert(0);
}

void fpgaglProgramEnvParameter4fvARB (GLenum target, GLuint index, const GLfloat *params)
{
	EmitFunc(ProgramEnvParameter4fvARB);
	EmitArg(target);
	EmitArg(index);
	EmitArray(params, 4);
}

void fpgaglProgramLocalParameter4fvARB (GLenum target, GLuint index, const GLfloat *params)
{
	assert(0);
}

void fpgaglPushAttrib(GLbitfield mask)
{
	assert(0);
}

void fpgaglProgramStringARB (GLenum target, GLenum format, GLsizei len, const void *string)
{
	EmitFunc(ProgramStringARB);
	EmitArg(target);
	EmitArg(format);
	EmitArg(len);
	EmitArray((const char *)string, len);
}

void fpgaglPushMatrix(void)
{
	EmitFunc(PushMatrix);
}

void fpgaglRasterPos2f(GLfloat x, GLfloat y)
{
	assert(0);
}

void fpgaglReadBuffer(GLenum mode)
{
	EmitFunc(ReadBuffer);
	EmitArg(mode);
}

void fpgaglReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
	assert(0);
}

void fpgaglScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	EmitFunc(Scissor);
	EmitArg(x);
	EmitArg(y);
	EmitArg(width);
	EmitArg(height);
}

void fpgaglShadeModel(GLenum mode)
{
	EmitFunc(ShadeModel);
	EmitArg(mode);
}

void fpgaglStencilFunc(GLenum func, GLint ref, GLuint mask)
{
	EmitFunc(StencilFunc);
	EmitArg(func);
	EmitArg(ref);
	EmitArg(mask);
}

void fpgaglStencilMask(GLuint mask)
{
	EmitFunc(StencilMask);
	EmitArg(mask);
}

void fpgaglStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
	EmitFunc(StencilOp);
	EmitArg(fail);
	EmitArg(zfail);
	EmitArg(zpass);
}

void fpgaglTexCoord2f(GLfloat s, GLfloat t)
{
	EmitFunc(TexCoord2f);
	EmitArg(s);
	EmitArg(t);
}

void fpgaglTexCoord2fv(const GLfloat *v)
{
	assert(0);
}

void fpgaglTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
	assert(0);
}

void fpgaglTexCoordPointerSIMON(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr, GLint numverts)
{
	EmitFunc(TexCoordPointer);
	EmitArg(size);
	EmitArg(type);
	EmitArg(stride);

	int el_size = enumToByteSize(type);
	if (stride == 0)
		EmitArray((char *)ptr, size * el_size * numverts);
	else
		EmitArray((char *)ptr, stride * numverts);
}

void fpgaglTexEnvf(GLenum target, GLenum pname, GLfloat param)
{
	EmitFunc(TexEnvf);
	EmitArg(target);
	EmitArg(pname);
	EmitArg(param);
}

void fpgaglTexEnvfv(GLenum target, GLenum pname, const GLfloat *params)
{
	EmitFunc(TexEnvfv);
	assert(pname == GL_TEXTURE_ENV_COLOR);
	EmitArg(target);
	EmitArg(pname);
	EmitArray(params, 4);
}

void fpgaglTexEnvi(GLenum target, GLenum pname, GLint param)
{
	EmitFunc(TexEnvi);
	EmitArg(target);
	EmitArg(pname);
	EmitArg(param);
}

void fpgaglTexGenf(GLenum coord, GLenum pname, GLfloat param)
{
	EmitFunc(TexGenf);
	EmitArg(coord);
	EmitArg(pname);
	EmitArg(param);
}

void fpgaglTexGenfv(GLenum coord, GLenum pname, const GLfloat *params)
{
	EmitFunc(TexGenfv);
	EmitArg(coord);
	EmitArg(pname);
	EmitArray(params, 4);
}

void fpgaglTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	if (width == 256 && height == 32 && target == GL_TEXTURE_2D && internalFormat == GL_RGB8 && level == 0)
		printf("here");
	EmitFunc(TexImage2D);
	assert(target == GL_TEXTURE_2D || (target >= GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT && target < GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT + 6));
	assert(format == GL_RGBA);
	assert(type == GL_UNSIGNED_BYTE);

	EmitArg(target);
	EmitArg(level);
	EmitArg(internalFormat);
	EmitArg(width);
	EmitArg(height);
	EmitArg(border);
	EmitArg(format);
	EmitArg(type);
	EmitArray((char *)pixels, width * height * 4);
}

void fpgaglTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
	EmitFunc(TexParameterf);
	EmitArg(target);
	EmitArg(pname);
	EmitArg(param);
}

void fpgaglTexParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
	EmitFunc(TexParameterfv);
	EmitArg(target);
	EmitArg(pname);

	switch (pname)
	{
		case GL_TEXTURE_BORDER_COLOR:
			EmitArray(params, 4);
			break;
		default:
			assert(0);
	}
}

void fpgaglTexParameteri(GLenum target, GLenum pname, GLint param)
{
	EmitFunc(TexParameteri);
	EmitArg(target);
	EmitArg(pname);
	EmitArg(param);
}

void fpgaglTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	assert(0);
}

void fpgaglTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
	assert(0);
}

void fpgaglUnlockArraysEXT(void)
{
	EmitFunc(UnlockArraysEXT);
}

void fpgaglVertexAttribPointerARB (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
{
	assert(0);
}

void fpgaglVertexAttribPointerSIMON (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *ptr, GLint numverts)
{
	EmitFunc(VertexAttribPointerARB);
	EmitArg(index);
	EmitArg(size);
	EmitArg(type);
	EmitArg(normalized);
	EmitArg(stride);

	int el_size = enumToByteSize(type);
	if (stride == 0)
		EmitArray((const char *)ptr, size * el_size * numverts);
	else
		EmitArray((const char *)ptr, stride * numverts);
}

void fpgaglVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
	assert(0);
}

void fpgaglVertexPointerSIMON(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr, GLint numverts)
{
	EmitFunc(VertexPointer);
	EmitArg(size);
	EmitArg(type);
	EmitArg(stride);

	int el_size = enumToByteSize(type);
	if (stride == 0)
		EmitArray((char *)ptr, size * el_size * numverts);
	else
		EmitArray((char *)ptr, stride * numverts);
}

void fpgaglVertex2f(GLfloat x, GLfloat y)
{
	EmitFunc(Vertex2f);
	EmitArg(x);
	EmitArg(y);
}

void fpgaglVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
	assert(0);
}

void fpgaglVertex3fv(const GLfloat *v)
{
	assert(0);
}

void fpgaglViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	EmitFunc(Viewport);
	EmitArg(x);
	EmitArg(y);
	EmitArg(width);
	EmitArg(height);
}

///////////////

void fpgaSwapBuffers(void)
{
	EmitFunc(SwapBuffers);
}

