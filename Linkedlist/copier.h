#pragma once

typedef void*(*copier)(void*);

void* copyInt(void* data);
void* copyFloat(void* data);
void* copyChar(void* data);
void* copyString(void* data);