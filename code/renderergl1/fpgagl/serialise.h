/*
 * serialise.h
 *
 *  Created on: 2 Aug 2020
 *      Author: simon
 */

#ifndef CODE_RENDERERGL1_FPGAGL_SERIALISE_H_
#define CODE_RENDERERGL1_FPGAGL_SERIALISE_H_

#include <stddef.h>
#include <limits.h>

#ifdef __cplusplus

enum GLFunction
{
	NoFunc = 0,
	AlphaFunc,
	Color4f,
	ColorPointer,
	DisableClientState,
	EnableClientState,
	LoadIdentity,
	LoadMatrixf,
	MatrixMode,
	PopMatrix,
	PushMatrix,
	ShadeModel,
	TexCoordPointer,
	TexEnvf,
	VertexPointer,
	ClearDepth,
	DepthRange,
	DrawBuffer,
	PolygonMode,
	ArrayElement,
	Begin,
	ClipPlane,
	Color3f,
	Color4ubv,
	End,
	Frustum,
	Ortho,
	TexCoord2f,
	TexCoord2fv,
	Vertex2f,
	Vertex3f,
	Vertex3fv,
	BindTexture,
	BlendFunc,
	ClearColor,
	Clear,
	ClearStencil,
	ColorMask,
	CopyTexSubImage2D,
	CullFace,
	DeleteTextures,
	DepthFunc,
	DepthMask,
	Disable,
	DrawArrays,
	DrawElements,
	Enable,
	Finish,
	Flush,
	GenTextures,
	GetIntegerv,
	LineWidth,
	PolygonOffset,
	ReadPixels,
	Scissor,
	StencilFunc,
	StencilMask,
	StencilOp,
	TexImage2D,
	TexParameterf,
	TexParameteri,
	TexSubImage2D,
	Translatef,
	Viewport,
	LockArraysEXT,
	UnlockArraysEXT,
	SwapBuffers,
	ActiveTextureARB,
	ClientActiveTextureARB,
	MultiTexCoord2fARB,

	Color4ub,
	DrawPixels,
	TexParameterfv,
	TexGenf,
	TexGenfv,
	TexEnvi,
	TexEnvfv,
	NormalPointer,
	ReadBuffer,

	VertexAttribPointerARB,
	EnableVertexAttribArrayARB,
	DisableVertexAttribArrayARB,
	ProgramStringARB,
	BindProgramARB,
	ProgramEnvParameter4fvARB,
};

struct DataElement
{
	int m_func;
	int m_size;
	//then data
};

void Emit(int func, int size, const void *pData);

template <class T>
void EmitFunc(T func)
{
	assert(func != 0);
	Emit(func, 0, 0);
}

template <class T>
void EmitArg(T arg)
{
	Emit(0, sizeof(T), &arg);
}

template <class T>
void EmitArray(const T *arg, size_t elems)
{
	assert(sizeof(T) * elems < INT_MAX);
	Emit(0, sizeof(T) * elems, arg);
}

#endif

#ifdef __cplusplus
extern "C" {
#endif

int BeginSerialise(const char *pFilename);
int EndSerialise(void);

#ifdef __cplusplus
}
#endif


#endif /* CODE_RENDERERGL1_FPGAGL_SERIALISE_H_ */
