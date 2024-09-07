#include "bignumbers.h"

char	*bn_multiply(char *temp1, char *temp2)
{
	char	*rtrn;
	char	*nbr1;
	char	*nbr2;
	char	state;

	nbr1 = bn_get_perfect_number(temp1);
	if (!bn_isnum(nbr1))
		return (free(nbr1), NULL);
	nbr2 = bn_get_perfect_number(temp2);
	if (!bn_isnum(nbr2))
		return (free(nbr1), free(nbr2), NULL);
	if (nbr1[0] == '0' || nbr2[0] == '0')
		return (free(nbr1), free(nbr2), ft_strdup("0"));
	rtrn = NULL;
	state = bn_decide_sign(nbr1, nbr2, '*');
	if (state == 1)
		rtrn = bn_multiply_helper_pos(nbr1, nbr2);
	else if (state == -1)
		rtrn = bn_multiply_helper_neg(nbr1, nbr2);
	return (free(nbr1), free(nbr2), rtrn);
}
