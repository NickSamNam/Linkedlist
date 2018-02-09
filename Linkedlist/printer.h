#pragma once

typedef void(*printer)(void*);

void printInt(void* data);
void printFloat(void* data);
void printChar(void* data);
void printString(void* data);