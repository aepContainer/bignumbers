#include "../bignumbers.h"

char	*bn_min_pos(char *nbr1, char *nbr2)
{
	int	len1;
	int	len2;
	int	i;

	if (!nbr1 || !nbr2 || !nbr1[0] || !nbr2[0])
		return (0);
	len1 = ft_strlen(nbr1);
	len2 = ft_strlen(nbr2);
	if (len1 < len2)
		return (ft_strdup(nbr1));
	else if (len2 < len1)
		return (ft_strdup(nbr2));
	i = 0;
	while (nbr1[i] && nbr2[i])
	{
		if (nbr1[0] < nbr2[0])
			return (ft_strdup(nbr1));
		else if (nbr1[0] > nbr2[0])
			return (ft_strdup(nbr2));
		i++;
	}
	if (nbr1[0])
		return (ft_strdup(nbr2));
	return (ft_strdup(nbr1));
}

static char	*bn_min_neg(char *nbr1, char *nbr2)
{
	char	*rtrn;
	char	*temp1;
	char	*temp2;
	char	state;

	temp1 = nbr1 + 1;
	temp2 = nbr2 + 1;
	rtrn = bn_min_pos(temp1, temp2);
	state = bn_is_same(rtrn, temp1);
	free(rtrn);
	if (state)
		rtrn = ft_strdup(nbr2);
	else
		rtrn = ft_strdup(nbr1);
	return (rtrn);
}

char	*bn_min(char *nbr1, char *nbr2)
{
	char	*rtrn;

	if (!nbr1 || !nbr2 || !nbr1[0] || !nbr2[0] || !bn_isnum_arg(nbr1, nbr2, NULL))
		return (NULL);
	rtrn = NULL;
	if (nbr1[0] == '-' && nbr2[0] != '-')
		rtrn = ft_strdup(nbr1);
	else if (nbr1[0] != '-' && nbr2[0] == '-')
		rtrn = ft_strdup(nbr2);
	else if (nbr1[0] != '-' && nbr2[0] != '-')
		rtrn = bn_min_pos(nbr1, nbr2);
	else
		rtrn = bn_min_neg(nbr1, nbr2);
	return (rtrn);
}
