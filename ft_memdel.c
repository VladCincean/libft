#include "libft.h"
#include <stdlib.h>

void ft_memdel(void **ap)
{
	if (!ap)
		return ;
	if (!*ap)
		return ;
	free(*ap);
	*ap = NULL;
}
