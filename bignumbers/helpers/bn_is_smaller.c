#include "../bignumbers.h"

char	bn_is_smaller(char *nbr1, char *nbr2)
{
	char	state;
	char	*temp;

	if (!nbr1 || !nbr2 || !nbr1[0] || !nbr2[0])
		return (-1);
	if (bn_is_same(nbr1, nbr2))
		return (0);
	if (nbr1[0] != '-' && nbr2[0] == '-')
		state = 0;
	else if (nbr1[0] == '-' && nbr2[0] != '-')
		state = 1;
	else
	{
		temp = bn_max(nbr1, nbr2);
		if (!temp)
			return (-1);
		state = 1;
		if (bn_is_same(temp, nbr1))
			state = 0;
		free(temp);
	}
	return (state);
}
