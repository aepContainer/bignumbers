#include "../bignumbers.h"

static void	bn_to_neg_helper(char *rtrn, char *nbr, char state)
{
	t_ui	i;

	i = -1;
	while (nbr[!state + ++i])
		rtrn[state + i] = nbr[!state + i];
	rtrn[state + i] = 0;
}

char	*bn_to_neg(char *nbr)
{
	char	*rtrn;
	char	state;

	if (!nbr || !nbr[0])
		return (0);
	if (nbr[0] != '-')
	{
		if (!(rtrn = (char *) ft_calloc(1, ft_strlen(nbr) + 2)))
			return (0);
		rtrn[0] = '-';
		state = 1;
	}
	else
	{
		if (!(rtrn = (char *) ft_calloc(1, ft_strlen(nbr))))
			return (0);
		state = 0;
	}
	bn_to_neg_helper(rtrn, nbr, state);
	return (rtrn);
}
