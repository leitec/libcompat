#include "libcompat.h"

char *strdup(const char *orig)
{
	char *n = malloc(strlen(orig)+1);
	
	strcpy(n, orig);
	return n;
}
