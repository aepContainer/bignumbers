#include "../bignumbers.h"

static void bn_substract_pos_core_helper1(char **nbr1, int i)
{
	while ((*nbr1)[i] == '0')
	{
		(*nbr1)[i] = '9';
		i--;
	}
	(*nbr1)[i] -= 1;
}

static char *bn_substract_pos_core_helper2(char *temp)
{
	char	*rtrn;

	if (*temp != '0')
		return (temp);
	rtrn = temp;
	while (*rtrn == '0')
		rtrn++;
	rtrn = ft_strdup(rtrn);
	return (free(temp), rtrn);
}

char *bn_substract_pos_core(char *nbr1, char *nbr2)
{
	char	*rtrn;
	char	*temp;
	char	res;
	int		i;

	rtrn = NULL;
	i = bn_set_length_same(&nbr1, &nbr2, ft_strlen(nbr1), ft_strlen(nbr2)) - 1;
	while (i >= 0)
	{
		res = nbr1[i] - nbr2[i];
		if (res < 0)
		{
			res += 10;
			bn_substract_pos_core_helper1(&nbr1, i - 1);
		}
		temp = rtrn;
		rtrn = bn_insert_digit_to_number_l(temp, res);
		free(temp);
		if (!rtrn)
			return (NULL);
		i--;
	}
	return (free(nbr1), free(nbr2), bn_substract_pos_core_helper2(rtrn));
}

char *bn_substract_add(char *nbr1, char *nbr2)
{
	char	*rtrn;
	char	*temps[2];
	char	neg;

	neg = 0;
	temps[1] = nbr1;
	if (nbr1[0] != '-')
		temps[0] = bn_to_neg(nbr2);
	else
	{
		temps[0] = bn_to_neg(nbr1);
		temps[1] = nbr2;
		neg = 1;
	}
	if (!temps[0])
		return (NULL);
	rtrn = bn_add(temps[0], temps[1]);
	if (neg)
	{
		temps[1] = rtrn;
		rtrn = bn_to_neg(temps[1]);
		free(temps[1]);
	}
	return (free(temps[0]), rtrn);
}
