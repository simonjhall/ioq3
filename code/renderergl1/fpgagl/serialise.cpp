/*
 * serialise.cpp
 *
 *  Created on: 3 Aug 2020
 *      Author: simon
 */

#include <stdio.h>
#include <assert.h>

#include "serialise.h"

static FILE *g_fp = 0;
static size_t s_written = 0;

int BeginSerialise(const char *pFilename)
{
	g_fp = fopen(pFilename, "wb");
	assert(g_fp);

	return 0;
}

int EndSerialise(void)
{
	assert(g_fp);
	fclose(g_fp);
	g_fp = 0;

	printf("wrote %.2f GB\n", (float)s_written / (1024 * 1024 * 1024));

	return 0;
}

void Emit(int func, int size, const void *pData)
{
	int misalignment = 0;
	if (size & 3)
		misalignment = 4 - (size & 3);

	s_written += size + sizeof(func) + sizeof(size) + misalignment;
	assert((s_written & 3) == 0);

	fwrite(&func, sizeof(func), 1, g_fp);
	fwrite(&size, sizeof(size), 1, g_fp);

	if (size)
		fwrite(pData, 1, size, g_fp);

	char zeroes[3] = {0, 0, 0};
	if (misalignment)
		fwrite(zeroes, 1, misalignment, g_fp);
}

