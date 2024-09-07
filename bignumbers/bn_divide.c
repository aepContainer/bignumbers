#include "bignumbers.h"

static void	bn_divide_abs(char **nbr1, char **nbr2)
{
	char *temp;

	if ((*nbr1)[0] == '-')
	{
		temp = *nbr1;
		*nbr1 = ft_strdup(*nbr1 + 1);
		free(temp);
	}
	if ((*nbr2)[0] == '-')
	{
		temp = *nbr2;
		*nbr2 = ft_strdup(*nbr2 + 1);
		free(temp);
	}
}

char	*bn_divide_exact(char *nbr1, char *nbr2)
{
	char *rtrn;
	char **all;

	if (!nbr1 || !nbr2)
		return (free(nbr1), free(nbr2), NULL);
	all = bn_divide_by_substraction(nbr1, nbr2);
	if (!all)
		return (NULL);
	free(all[1]);
	rtrn = ft_strdup(all[0]);
	free(all[0]);
	free(all);
	return (rtrn);
}

char	*bn_divide_float(char *nbr1, char *nbr2, int round)
{
	char	*rtrn;
	char	*flt;
	char	*temp;
	char	**all;

	all = bn_divide_by_substraction(nbr1, nbr2);
	if (!all)
		return (NULL);
	flt = bn_divide_calc_flt(all[1], nbr2, round);// içinde free(all[1]);
	if (!flt)
		return (free(all[0]), free(all), NULL);
	rtrn = ft_strjoin(all[0], ",");
	free(all[0]);
	free(all);
	if (!rtrn)
		return (free(flt), NULL);
	temp = rtrn;
	rtrn = ft_strjoin(rtrn, flt);
	free(temp);
	free(flt);
	return (rtrn);
}

char	*bn_divide(char *nbr1, char *nbr2, char mode, int round)
{
	char	*rtrn;
	char	*temp;
	char	state;

	nbr1 = bn_get_perfect_number(nbr1);
	if (!bn_isnum(nbr1))
		return (free(nbr1), NULL);
	nbr2 = bn_get_perfect_number(nbr2);
	if (!bn_isnum(nbr2))
		return (free(nbr1), free(nbr2), NULL);
	rtrn = NULL;
	state = bn_decide_sign(nbr1, nbr2, '/');
	bn_divide_abs(&nbr1, &nbr2);
	if (mode == 'i')
		rtrn = bn_divide_exact(nbr1, nbr2);
	else if (mode == 'f')
		rtrn = bn_divide_float(nbr1, nbr2, round);
	if (state == -1)
	{
		temp = rtrn;
		rtrn = bn_to_neg(temp);
		free(temp);
	}
	return (free(nbr1), free(nbr2), rtrn);
}
