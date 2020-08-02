/*
 * entry_points.c
 *
 *  Created on: 19 Apr 2020
 *      Author: simon
 */

#include <assert.h>
#include "entry_points.h"

#define MAX_TEXTURE_SIZE 128

// OpenGL 1.0/1.1 and OpenGL ES 1.x but not OpenGL 3.2 core profile
void fpgaglAlphaFunc(GLenum func, GLclampf ref)
{
}

void fpgaglColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
}

void fpgaglColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
}

void fpgaglDisableClientState(GLenum cap)
{
}

void fpgaglEnableClientState(GLenum cap)
{
}

void fpgaglLoadIdentity(void)
{
}

void fpgaglLoadMatrixf(const GLfloat *m)
{
}

void fpgaglMatrixMode(GLenum mode)
{
}

void fpgaglPopMatrix(void)
{
}

void fpgaglPushMatrix(void)
{
}

void fpgaglShadeModel(GLenum mode)
{
}

void fpgaglTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
}

void fpgaglTexEnvf(GLenum target, GLenum pname, GLfloat param)
{
}

void fpgaglVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr)
{
}

// OpenGL 1.0/1.1 and 3.2 core profile but not OpenGL ES 1.x
void fpgaglClearDepth(GLclampd depth)
{
}

void fpgaglDepthRange(GLclampd near_val, GLclampd far_val)
{
}

void fpgaglDrawBuffer(GLenum mode)
{
}

void fpgaglPolygonMode(GLenum face, GLenum mode)
{
}

// OpenGL 1.0/1.1 but not OpenGL 3.2 core profile or OpenGL ES 1.x
void fpgaglArrayElement(GLint i)
{
}

void fpgaglBegin(GLenum mode)
{
}

void fpgaglClipPlane(GLenum plane, const GLdouble *equation)
{
}

void fpgaglColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
}

void fpgaglColor4ubv(const GLubyte *v)
{
}

void fpgaglEnd(void)
{
}

void fpgaglFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val)
{
}

void fpgaglOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val)
{
}

void fpgaglTexCoord2f(GLfloat s, GLfloat t)
{
}

void fpgaglTexCoord2fv(const GLfloat *v)
{
}

void fpgaglVertex2f(GLfloat x, GLfloat y)
{
}

void fpgaglVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
}

void fpgaglVertex3fv(const GLfloat *v)
{
}

// OpenGL 1.0/1.1, OpenGL ES 1.0, and OpenGL 3.2 core profile
void fpgaglBindTexture(GLenum target, GLuint texture)
{
}

void fpgaglBlendFunc(GLenum sfactor, GLenum dfactor)
{
}

void fpgaglClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
}

void fpgaglClear(GLbitfield mask)
{
}

void fpgaglClearStencil(GLint s)
{
}

void fpgaglColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
}

void fpgaglCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
}

void fpgaglCullFace(GLenum mode)
{
}

void fpgaglDeleteTextures(GLsizei n, const GLuint *textures)
{
}

void fpgaglDepthFunc(GLenum func)
{
}

void fpgaglDepthMask(GLboolean flag)
{
}

void fpgaglDisable(GLenum cap)
{
}

void fpgaglDrawArrays(GLenum mode, GLint first, GLsizei count)
{
}

void fpgaglDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
}

void fpgaglEnable(GLenum cap)
{
}

void fpgaglFinish(void)
{
}

void fpgaglFlush(void)
{
}

void fpgaglGenTextures(GLsizei n, GLuint *textures )
{
}

void fpgaglGetBooleanv(GLenum pname, GLboolean *params)
{
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
		case GL_VENDOR:		return "Simon Hall";
		case GL_RENDERER:	return "FPGA renderer";
		case GL_VERSION:	return "1.0";
		case GL_EXTENSIONS:	return "no extensions";
		default:
			assert(!"unknown glGetString");
			return "unknown glGetString";
	}
}

void fpgaglLineWidth(GLfloat width)
{
}

void fpgaglPolygonOffset(GLfloat factor, GLfloat units)
{
}

void fpgaglReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
}

void fpgaglScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
}

void fpgaglStencilFunc(GLenum func, GLint ref, GLuint mask)
{
}

void fpgaglStencilMask(GLuint mask)
{
}

void fpgaglStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
}

void fpgaglTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
}

void fpgaglTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
}

void fpgaglTexParameteri(GLenum target, GLenum pname, GLint param)
{
}

void fpgaglTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
}

void fpgaglTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
}

void fpgaglViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
}

// OpenGL 3.0 specific
const GLubyte *fpgaglGetStringi(GLenum name, GLuint index)
{
	assert(!"glGetStringi");
	return 0;
}
