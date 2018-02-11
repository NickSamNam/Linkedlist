#include <string.h>

void* copyInt(void* data)
{
	int* copy = malloc(sizeof(int));
	*copy = *((int*)data);
	return copy;
}

void* copyFloat(void* data)
{
	float* copy = malloc(sizeof(float));
	*copy = *((float*)data);
	return copy;
}

void* copyChar(void* data)
{
	char* copy = malloc(sizeof(char));
	*copy = *((char*)data);
	return copy;
}

void* copyString(void* data)
{
	char* copy = malloc(strlen(data));
	strcpy(copy, data);
	return copy;
}