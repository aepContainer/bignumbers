#include "complexnumbers.h"

short	c_isnum_arg(c_num *nbr1, ...)
{
	va_list	numlist;
	c_num	*temp;

	if (!c_isnum(nbr1))
		return (0);
	va_start(numlist, nbr1);
	temp = va_arg(numlist, c_num *);
	while (temp)
	{
		if (!c_isnum(temp))
			return (va_end(numlist), 0);
		temp = va_arg(numlist, c_num *);
	}
	va_end(numlist);
	return (1);
}
