#include "../bignumbers.h"

char	*bn_get_perfect_number(char *nbr)
{
	char	*rtrn;
	char	*temp;

	if (!nbr || !nbr[0])
		return (NULL);
	rtrn = ft_strtrim(nbr, " ");
	if (!rtrn)
		return (NULL);
	if (!bn_isnum(rtrn))
		return (free(rtrn), NULL);
	if (rtrn[0] == '+')
	{
		temp = rtrn;
		rtrn = ft_strdup(temp + 1);
		free(temp);
		return (rtrn);
	}
	return (rtrn);
}
