#include "bignumbers.h"

char	*bn_abstract(char *nbr)
{
	char	*rtrn;

	nbr = bn_get_perfect_number(nbr);
	if (!bn_isnum(nbr))
		return (free(nbr), NULL);
	if (nbr[0] != '-')
		rtrn = ft_strdup(nbr);
	else
		rtrn = bn_to_neg(nbr);
	return (rtrn);
}
