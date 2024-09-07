#include "bignumbers.h"

static char	bn_factorialize_helper1(char *nbr, char **temp1, char **temp2)
{
	*temp1 = ft_strdup("1");
	if (!*temp1)
		return (0);
	if (nbr[0] == '0' || (nbr[0] == '1' && !nbr[1]))
		return (-1);
	*temp2 = ft_strdup(nbr);
	if (!*temp2)
		return (free(*temp1), 0);
	return (1);
}

static char	*bn_factorialize_helper2(char *rtrn, char *temp1, char *temp2)
{
	char	*temp3;

	while (temp2[0] != '2' || temp2[1])
	{
		temp3 = temp2;
		temp2 = bn_substract(temp2, temp1);
		free(temp3);
		if (!temp2)
			return (NULL);
		temp3 = rtrn;
		rtrn = bn_multiply(rtrn, temp2);
		free(temp3);
		if (!rtrn)
			return (free(temp2), NULL);
	}
	return (free(temp2), rtrn);
}

char	*bn_factorialize(char *temp)
{
	char	*rtrn;
	char	*temp1;
	char 	*temp2;
	char	state;

	rtrn = bn_get_perfect_number(temp);
	if (!rtrn)
		return (NULL);
	else if (rtrn[0] == '-' || !bn_isnum(rtrn))
		return (free(rtrn), NULL);
	state = bn_factorialize_helper1(rtrn, &temp1, &temp2);
	if (!state)
		return (free(rtrn), NULL);
	else if (state == -1)
		return (free(rtrn), temp1);
	rtrn = bn_factorialize_helper2(rtrn, temp1, temp2);
	return (free(temp1), rtrn);
}
