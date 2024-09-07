#include "../bignumbers.h"

char	*bn_power_neg(char *nbr1, char *nbr2)
{
	char	*rtrn;
	char	*temp;

	temp = bn_to_neg(nbr1);
	if (!temp)
		return (NULL);
	rtrn = bn_power_pos(temp, nbr2);
	free(temp);
	if (!rtrn)
		return (NULL);
	temp = rtrn;
	rtrn = bn_to_neg(temp);
	return (free(temp), rtrn);
}

char	*bn_power_pos(char *nbr1, char *nbr2)
{
	char	*rtrn;
	char	*temp1;
	char	*temp2;

	temp2 = ft_strdup(nbr2);
	if (!temp2)
		return (NULL);
	rtrn = ft_strdup("1");
	while (temp2[0] != '0')
	{
		temp1 = rtrn;
		rtrn = bn_multiply(temp1, nbr1);
		free(temp1);
		if (!rtrn)
			return (free(temp2), NULL);
		temp1 = temp2;
		temp2 = bn_substract(temp1, "1");
		free(temp1);
		if (!temp2)
			return (free(rtrn), NULL);
	}
	return (free(temp2), rtrn);
}
