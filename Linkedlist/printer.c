#pragma once

#include <stdio.h>

void printInt(void* data)
{
	printf("%d", *(int*)data);
}

void printFloat(void* data)
{
	printf("%f", *(float*)data);
}

void printChar(void* data)
{
	printf("%c", *(char*)data);
}

void printString(void* data)
{
	printf("%s", *(char**)data);
}