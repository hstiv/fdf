#include "libft.h"

int				ft_abs(int a, int b)
{
	int res;

	(a - b > 0) ? (res = a - b) : (res = b - a);
	return (res);
}