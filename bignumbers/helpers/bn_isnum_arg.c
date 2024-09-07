#include "../bignumbers.h"

char	bn_isnum_arg(char *nbr1, ...)
{
	va_list	arg_list;
	char	*nbr;

	if (!nbr1 || !nbr1[0] || !bn_isnum(nbr1))
		return (0);
	va_start(arg_list, nbr1);
	nbr = va_arg(arg_list, char *);
	while (nbr && nbr[0])
	{
		if (!bn_isnum(nbr))
			return (va_end(arg_list), 0);
		nbr = va_arg(arg_list, char *);
	}
	va_end(arg_list);
	return (1);
}
