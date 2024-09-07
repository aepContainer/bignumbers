#include "../../libft/libft.h"

void	bn_calc_add(char *res, char *buff, char digit1, char digit2)
{
	*res = *buff + digit1 + digit2;
	if (*res >= 10)
	{
		*buff = *res / 10;
		*res %= 10;
	}
	else
		*buff = 0;
}

void	bn_calc_multiply(char *res, char *buff, char digit1, char digit2)
{
	*res = *buff + digit1 * digit2;
	if (*res >= 10)
	{
		*buff = *res / 10;
		*res %= 10;
	}
	else
		*buff = 0;
}
