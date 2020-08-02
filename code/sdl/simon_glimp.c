/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#ifdef FPGAGL

#ifdef USE_LOCAL_HEADERS
#	include "SDL.h"
#else
#	include <SDL.h>
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../renderercommon/tr_common.h"
#include "../sys/sys_local.h"

#include "../renderergl1/fpgagl/entry_points.h"

void (APIENTRYP qglActiveTextureARB) (GLenum texture);
void (APIENTRYP qglClientActiveTextureARB) (GLenum texture);
void (APIENTRYP qglMultiTexCoord2fARB) (GLenum target, GLfloat s, GLfloat t);

void (APIENTRYP qglLockArraysEXT) (GLint first, GLsizei count);
void (APIENTRYP qglUnlockArraysEXT) (void);

#define GLE(ret, name, ...) name##proc * qgl##name;
QGL_1_1_FIXED_FUNCTION_PROCS;
QGL_DESKTOP_1_1_PROCS;
QGL_DESKTOP_1_1_FIXED_FUNCTION_PROCS;
//QGL_ES_1_1_PROCS;
QGL_1_1_PROCS;
//QGL_ES_1_1_FIXED_FUNCTION_PROCS;
//QGL_1_3_PROCS;
//QGL_1_5_PROCS;
//QGL_2_0_PROCS;
QGL_3_0_PROCS;
//QGL_ARB_occlusion_query_PROCS;
//QGL_ARB_framebuffer_object_PROCS;
//QGL_ARB_vertex_array_object_PROCS;
//QGL_EXT_direct_state_access_PROCS;
#undef GLE

/*
===============
GLimp_Shutdown
===============
*/
void GLimp_Shutdown( void )
{
	ri.IN_Shutdown();
}

/*
===============
GLimp_Minimize

Minimize the game so that user is back at the desktop
===============
*/
void GLimp_Minimize( void )
{
}


/*
===============
GLimp_LogComment
===============
*/
void GLimp_LogComment( char *comment )
{
}

/*
===============
GLimp_SetMode
===============
*/
static void GLimp_SetMode(void)
{
#define GLE( ret, name, ... ) qgl##name = fpgagl##name;

	QGL_1_1_FIXED_FUNCTION_PROCS;
	QGL_DESKTOP_1_1_PROCS;
	QGL_DESKTOP_1_1_FIXED_FUNCTION_PROCS;
	//QGL_ES_1_1_PROCS;
	QGL_1_1_PROCS;
	//QGL_ES_1_1_FIXED_FUNCTION_PROCS;
	//QGL_1_3_PROCS;
	//QGL_1_5_PROCS;
	//QGL_2_0_PROCS;
	QGL_3_0_PROCS;
	//QGL_ARB_occlusion_query_PROCS;
	//QGL_ARB_framebuffer_object_PROCS;
	//QGL_ARB_vertex_array_object_PROCS;
	//QGL_EXT_direct_state_access_PROCS;
#undef GLE
	///////////////////////////////////
	displayAspect = 1.33333f;
	glConfig.isFullscreen = qtrue;
	glConfig.stereoEnabled = qfalse;

	glConfig.vidWidth = 640;
	glConfig.vidHeight = 480;

	glConfig.windowAspect = (float)glConfig.vidWidth / (float)glConfig.vidHeight;
	glConfig.colorBits = 15;
	glConfig.depthBits = 16;
	glConfig.stencilBits = 0;

	ri.Printf( PRINT_ALL, "GL_RENDERER: %s\n", qglGetString (GL_RENDERER) );
}

/*
===============
GLimp_StartDriverAndSetMode
===============
*/
static void GLimp_StartDriverAndSetMode(void)
{
	GLimp_SetMode();
}

/*
===============
GLimp_Init

This routine is responsible for initializing the OS specific portions
of OpenGL
===============
*/
void GLimp_Init( qboolean fixedFunction )
{
	ri.Printf( PRINT_DEVELOPER, "Glimp_Init( )\n" );

	ri.Sys_GLimpInit( );

	// Create the window and set up the context
	GLimp_StartDriverAndSetMode();

	// These values force the UI to disable driver selection
	glConfig.driverType = GLDRV_ICD;
	glConfig.hardwareType = GLHW_GENERIC;

	// Only using SDL_SetWindowBrightness to determine if hardware gamma is supported
	glConfig.deviceSupportsGamma = 0;

	// get our config strings
	Q_strncpyz( glConfig.vendor_string, (char *) qglGetString (GL_VENDOR), sizeof( glConfig.vendor_string ) );
	Q_strncpyz( glConfig.renderer_string, (char *) qglGetString (GL_RENDERER), sizeof( glConfig.renderer_string ) );

	if (*glConfig.renderer_string && glConfig.renderer_string[strlen(glConfig.renderer_string) - 1] == '\n')
		glConfig.renderer_string[strlen(glConfig.renderer_string) - 1] = 0;

	Q_strncpyz( glConfig.version_string, (char *) qglGetString (GL_VERSION), sizeof( glConfig.version_string ) );
	Q_strncpyz( glConfig.extensions_string, (char *) qglGetString (GL_EXTENSIONS), sizeof( glConfig.extensions_string ) );

	// This depends on SDL_INIT_VIDEO, hence having it here
	ri.IN_Init(0);
}


/*
===============
GLimp_EndFrame

Responsible for doing a swapbuffers
===============
*/
void GLimp_EndFrame( void )
{
	// don't flip if drawing to front buffer
	if ( Q_stricmp( r_drawBuffer->string, "GL_FRONT" ) != 0 )
	{
		//swap buffers
	}
}

#endif
