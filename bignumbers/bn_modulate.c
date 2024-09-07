#include "bignumbers.h"

char	*bn_modulate(char *nbr1, char *nbr2)
{
	char	*temp;

	nbr1 = bn_get_perfect_number(nbr1);
	if (!bn_isnum(nbr1))
		return (free(nbr1), NULL);
	nbr2 = bn_get_perfect_number(nbr2);
	if (!bn_isnum(nbr2))
		return (free(nbr1), free(nbr2), NULL);
	temp = bn_substract(nbr1, nbr2);
	if (!temp)
		return (free(nbr1), free(nbr2), NULL);
	while (temp[0] != '-')
	{
		free(nbr1);
		nbr1 = ft_strdup(temp);
		free(temp);
		if (!nbr1)
			return (free(nbr2), NULL);
		temp = bn_substract(nbr1, nbr2);
		if (!temp)
			return (free(nbr1), free(nbr2), NULL);
	}
	return (free(temp), free(nbr2), nbr1);
}
