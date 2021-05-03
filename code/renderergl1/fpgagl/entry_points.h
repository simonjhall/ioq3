/*
 * entry_points.h
 *
 *  Created on: 19 Apr 2020
 *      Author: simon
 */

#ifndef CODE_RENDERERGL1_FPGAGL_ENTRY_POINTS_H_
#define CODE_RENDERERGL1_FPGAGL_ENTRY_POINTS_H_

/*
 * entry_points.h
 *
 *  Created on: 19 Apr 2020
 *      Author: simon
 */

//#include "../../renderercommon/tr_common.h"

#ifdef __cplusplus
extern "C" {
#endif

const GLubyte *fpgaglGetString(GLenum name);
const GLubyte *fpgaglGetStringi(GLenum name, GLuint index);
GLenum fpgaglGetError(void);
void fpgaglActiveTextureARB(GLenum texture);
void fpgaglAlphaFunc(GLenum func, GLclampf ref);
void fpgaglArrayElement(GLint i);
void fpgaglBegin(GLenum mode);
void fpgaglBindProgramARB (GLenum target, GLuint program);
void fpgaglBindTexture(GLenum target, GLuint texture);
void fpgaglBlendFunc(GLenum sfactor, GLenum dfactor);
void fpgaglClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void fpgaglClearDepth(GLclampd depth);
void fpgaglClear(GLbitfield mask);
void fpgaglClearStencil(GLint s);
void fpgaglClientActiveTextureARB(GLenum texture);
void fpgaglClipPlane(GLenum plane, const GLdouble *equation);
void fpgaglColor3f(GLfloat red, GLfloat green, GLfloat blue);
void fpgaglColor3fv(const GLfloat *v);
void fpgaglColor3ubv(const GLubyte *v);
void fpgaglColor3ub(GLubyte red, GLubyte alpga, GLubyte blue);
void fpgaglColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void fpgaglColor4fv(const GLfloat *v);
void fpgaglColor4ubv(const GLubyte *v);
void fpgaglColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void fpgaglColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void fpgaglColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
void fpgaglColorPointerSIMON(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr, GLint numverts);
void fpgaglCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void fpgaglCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void fpgaglCullFace(GLenum mode);
void fpgaglDeleteTextures(GLsizei n, const GLuint *textures);
void fpgaglDepthFunc(GLenum func);
void fpgaglDepthMask(GLboolean flag);
void fpgaglDepthRange(GLclampd near_val, GLclampd far_val);
void fpgaglDisableClientState(GLenum cap);
void fpgaglDisable(GLenum cap);
void fpgaglDisableVertexAttribArrayARB (GLuint index);
void fpgaglDrawArrays(GLenum mode, GLint first, GLsizei count);
void fpgaglDrawBuffer(GLenum mode);
void fpgaglDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void fpgaglDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void fpgaglEnableClientState(GLenum cap);
void fpgaglEnable(GLenum cap);
void fpgaglEnableVertexAttribArrayARB (GLuint index);
void fpgaglEnd(void);
void fpgaglFinish(void);
void fpgaglFlush(void);
void fpgaglFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val);
void fpgaglFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void fpgaglGenProgramsARB (GLsizei n, GLuint *programs);
void fpgaglGenTextures(GLsizei n, GLuint *textures );
void fpgaglGenTextures(GLsizei n, GLuint *textures);
void fpgaglGetBooleanv(GLenum pname, GLboolean *params);
void fpgaglGetFloatv(GLenum pname, GLfloat *params);
void fpgaglGetIntegerv(GLenum pname, GLint *params);
void fpgaglGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
void fpgaglLineWidth(GLfloat width);
void fpgaglLoadIdentity(void);
void fpgaglLoadMatrixf(const GLfloat *m);
void fpgaglLockArraysEXT(GLint first, GLsizei count);
void fpgaglMatrixMode(GLenum mode);
void fpgaglMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t);
void fpgaglMultiTexCoord2fvARB(GLenum texture, GLfloat *st);
void fpgaglNormalPointer(GLenum type, GLsizei stride, const GLvoid *ptr);
void fpgaglNormalPointerSIMON(GLenum type, GLsizei stride, const GLvoid *ptr, GLint numverts);
void fpgaglOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val);
void fpgaglOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void fpgaglPixelStorei(GLenum pname, GLint param);
void fpgaglPixelZoom(GLfloat xfactor, GLfloat yfactor);
void fpgaglPointSize(GLfloat size);
void fpgaglPolygonMode(GLenum face, GLenum mode);
void fpgaglPolygonOffset(GLfloat factor, GLfloat units);
void fpgaglPopAttrib(void);
void fpgaglPopMatrix(void);
void fpgaglPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities);
void fpgaglProgramEnvParameter4fvARB (GLenum target, GLuint index, const GLfloat *params);
void fpgaglProgramLocalParameter4fvARB (GLenum target, GLuint index, const GLfloat *params);
void fpgaglProgramStringARB (GLenum target, GLenum format, GLsizei len, const void *string);
void fpgaglPushAttrib(GLbitfield mask);
void fpgaglPushMatrix(void);
void fpgaglRasterPos2f(GLfloat x, GLfloat y);
void fpgaglReadBuffer(GLenum mode);
void fpgaglReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
void fpgaglScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void fpgaglShadeModel(GLenum mode);
void fpgaglStencilFunc(GLenum func, GLint ref, GLuint mask);
void fpgaglStencilMask(GLuint mask);
void fpgaglStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void fpgaglTexCoord2f(GLfloat s, GLfloat t);
void fpgaglTexCoord2fv(const GLfloat *v);
void fpgaglTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
void fpgaglTexCoordPointerSIMON(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr, GLint numverts);
void fpgaglTexEnvf(GLenum target, GLenum pname, GLfloat param);
void fpgaglTexEnvfv(GLenum target, GLenum pname, const GLfloat *params);
void fpgaglTexEnvi(GLenum target, GLenum pname, GLint param);
void fpgaglTexGenf(GLenum coord, GLenum pname, GLfloat param);
void fpgaglTexGenfv(GLenum coord, GLenum pname, const GLfloat *params);
void fpgaglTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void fpgaglTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void fpgaglTexParameterf(GLenum target, GLenum pname, GLfloat param);
void fpgaglTexParameterfv(GLenum target, GLenum pname, const GLfloat *params);
void fpgaglTexParameteri(GLenum target, GLenum pname, GLint param);
void fpgaglTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void fpgaglTranslatef(GLfloat x, GLfloat y, GLfloat z);
void fpgaglUnlockArraysEXT(void);
void fpgaglVertexAttribPointerARB (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
void fpgaglVertexAttribPointerSIMON (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer,  GLint numverts);
void fpgaglVertex2f(GLfloat x, GLfloat y);
void fpgaglVertex3f(GLfloat x, GLfloat y, GLfloat z);
void fpgaglVertex3fv(const GLfloat *v);
void fpgaglVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
void fpgaglVertexPointerSIMON(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr, GLint numverts);
void fpgaglViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void fpgaSwapBuffers(void);

#ifdef __cplusplus
}
#endif


#endif /* CODE_RENDERERGL1_FPGAGL_ENTRY_POINTS_H_ */
