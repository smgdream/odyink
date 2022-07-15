#include <stdlib.h>
#include "ocfg_type.h"

/* 
 * 
 */
Odyconf *ocfg_create(void)
{
	return (Odyconf *)malloc(sizeof(Odyconf));
}