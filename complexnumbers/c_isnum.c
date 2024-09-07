#include "complexnumbers.h"

short	c_isnum(c_num *nbr)
{
	if (!nbr)
		return (0);
	if (!bn_isnum(nbr->re))
		return (0);
	else if (!bn_isnum(nbr->im))
		return (0);
	return (1);
}
