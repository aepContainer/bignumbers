#include "bignumbers.h"

char	*bn_substract_pos(char *nbr1, char *nbr2)
{
	char	*rtrn;
	char	*temp;
	char	*max;
	char	*min;
	char	state;

	if (bn_is_same(nbr1, nbr2))
		return (ft_strdup("0"));
	max = bn_max(nbr1, nbr2);
	if (!max)
		return (NULL);
	min = bn_min(nbr1, nbr2);
	if (!min)
		return (free(max), NULL);
	state = bn_is_same(max, nbr1);
	rtrn = bn_substract_pos_core(max, min);
	if (!rtrn)
		return (NULL);
	if (!state)
	{
		temp = rtrn;
		rtrn = bn_to_neg(temp);
		free(temp);
	}
	return (rtrn);
}

char	bn_substract_line_helper(char *temp1, char *temp2, char **nbr1, char **nbr2)
{
	*nbr1 = bn_get_perfect_number(temp1);
	if (!bn_isnum(*nbr1))
		return (free(*nbr1), 0);
	*nbr2 = bn_get_perfect_number(temp2);
	if (!bn_isnum(*nbr2))
		return (free(*nbr1), free(*nbr2), 0);
	return (1);
}

char	*bn_substract(char *temp1, char *temp2)
{
	char	*rtrn;
	char	*nbr1;
	char	*nbr2;
	char	state;

	if (!bn_substract_line_helper(temp1, temp2, &nbr1, &nbr2))
		return (NULL);
	state = bn_decide_sign(nbr1, nbr2, '-');
	if (state && nbr1[0] != '-')
		rtrn = bn_substract_pos(nbr1, nbr2);
	else if (state && nbr1[0] == '-')
	{
		temp1 = bn_to_neg(nbr2);
		if (!temp1)
			return (NULL);
		rtrn = bn_add(nbr1, temp1);
		free(temp1);
		if (!rtrn)
			return (NULL);
	}
	else
		rtrn = bn_substract_add(nbr1, nbr2);
	return (free(nbr1), free(nbr2), rtrn);
}
