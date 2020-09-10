/*
 * entry_points.c
 *
 *  Created on: 19 Apr 2020
 *      Author: simon
 */

#include <assert.h>
#include "entry_points.h"
#include "serialise.h"

#define MAX_TEXTURE_SIZE 128

// OpenGL 1.0/1.1 and OpenGL ES 1.x but not OpenGL 3.2 core profile
void fpgaglAlphaFunc(GLenum func, GLclampf ref)
{
	EmitFunc(AlphaFunc);
	EmitArg(func);
	EmitArg(ref);
}

void fpgaglColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	EmitFunc(Color4f);
	EmitArg(red);
	EmitArg(green);
	EmitArg(blue);
	EmitArg(alpha);
}

void fpgaglColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
	assert(0);
}

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

void fpgaglDisableClientState(GLenum cap)
{
	EmitFunc(DisableClientState);
	EmitArg(cap);
}

void fpgaglEnableClientState(GLenum cap)
{
	EmitFunc(EnableClientState);
	EmitArg(cap);
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

void fpgaglMatrixMode(GLenum mode)
{
	EmitFunc(MatrixMode);
	EmitArg(mode);
}

void fpgaglPopMatrix(void)
{
	assert(0);
}

void fpgaglPushMatrix(void)
{
	assert(0);
}

void fpgaglShadeModel(GLenum mode)
{
	EmitFunc(ShadeModel);
	EmitArg(mode);
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

// OpenGL 1.0/1.1 and 3.2 core profile but not OpenGL ES 1.x
void fpgaglClearDepth(GLclampd depth)
{
	EmitFunc(ClearDepth);
	EmitArg(depth);
}

void fpgaglDepthRange(GLclampd near_val, GLclampd far_val)
{
	EmitFunc(DepthRange);
	EmitArg(near_val);
	EmitArg(far_val);
}

void fpgaglDrawBuffer(GLenum mode)
{
	EmitFunc(DrawBuffer);
	EmitArg(mode);
}

void fpgaglPolygonMode(GLenum face, GLenum mode)
{
	EmitFunc(PolygonMode);
	assert(face == GL_FRONT_AND_BACK);
	EmitArg(mode);
}

// OpenGL 1.0/1.1 but not OpenGL 3.2 core profile or OpenGL ES 1.x
void fpgaglArrayElement(GLint i)
{
	assert(0);
}

void fpgaglBegin(GLenum mode)
{
	assert(0);
}

void fpgaglClipPlane(GLenum plane, const GLdouble *equation)
{
	assert(0);
}

void fpgaglColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
	assert(0);
}

void fpgaglColor4ubv(const GLubyte *v)
{
	assert(0);
}

void fpgaglEnd(void)
{
	assert(0);
}

void fpgaglFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val)
{
	assert(0);
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

void fpgaglTexCoord2f(GLfloat s, GLfloat t)
{
	assert(0);
}

void fpgaglTexCoord2fv(const GLfloat *v)
{
	assert(0);
}

void fpgaglVertex2f(GLfloat x, GLfloat y)
{
	assert(0);
}

void fpgaglVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
	assert(0);
}

void fpgaglVertex3fv(const GLfloat *v)
{
	assert(0);
}

// OpenGL 1.0/1.1, OpenGL ES 1.0, and OpenGL 3.2 core profile
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
	assert(0);
}

void fpgaglClear(GLbitfield mask)
{
	EmitFunc(Clear);
	EmitArg(mask);
}

void fpgaglClearStencil(GLint s)
{
	assert(0);
}

void fpgaglColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	assert(red == GL_TRUE);
	assert(green == GL_TRUE);
	assert(blue == GL_TRUE);
	assert(alpha == GL_TRUE);
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

void fpgaglDisable(GLenum cap)
{
	EmitFunc(Disable);
	EmitArg(cap);
}

void fpgaglDrawArrays(GLenum mode, GLint first, GLsizei count)
{
	assert(0);
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

void fpgaglEnable(GLenum cap)
{
	EmitFunc(Enable);
	EmitArg(cap);
}

void fpgaglFinish(void)
{
	EmitFunc(Finish);
}

void fpgaglFlush(void)
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

void fpgaglGetBooleanv(GLenum pname, GLboolean *params)
{
	assert(0);
}

GLenum fpgaglGetError(void)
{
	return 0;
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
		case GL_MAX_TEXTURE_UNITS_ARB:
			*params = 4;
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

void fpgaglLineWidth(GLfloat width)
{
	assert(0);
}

void fpgaglPolygonOffset(GLfloat factor, GLfloat units)
{
	EmitFunc(PolygonOffset);
	EmitArg(factor);
	EmitArg(units);
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

void fpgaglStencilFunc(GLenum func, GLint ref, GLuint mask)
{
	assert(0);
}

void fpgaglStencilMask(GLuint mask)
{
	assert(0);
}

void fpgaglStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
	assert(0);
}

void fpgaglTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	EmitFunc(TexImage2D);
	assert(target == GL_TEXTURE_2D);
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

void fpgaglTexParameteri(GLenum target, GLenum pname, GLint param)
{
	assert(0);
}

void fpgaglTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	assert(0);
}

void fpgaglTranslatef(GLfloat x, GLfloat y, GLfloat z)
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

// OpenGL 3.0 specific
const GLubyte *fpgaglGetStringi(GLenum name, GLuint index)
{
	assert(!"glGetStringi");
	return 0;
}

void fpgaglLockArraysEXT(GLint first, GLsizei count)
{
	EmitFunc(LockArraysEXT);
	EmitArg(first);
	EmitArg(count);
}

void fpgaglUnlockArraysEXT(void)
{
	EmitFunc(UnlockArraysEXT);
}

void fpgaglActiveTextureARB(GLenum texture)
{
	EmitFunc(ActiveTextureARB);
	EmitArg(texture);
}

void fpgaglClientActiveTextureARB(GLenum texture)
{
	EmitFunc(ClientActiveTextureARB);
	EmitArg(texture);
}

void fpgaglMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t)
{
	EmitFunc(MultiTexCoord2fARB);
	EmitArg(target);
	EmitArg(s);
	EmitArg(t);
}

void fpgaSwapBuffers(void)
{
	EmitFunc(SwapBuffers);
}

