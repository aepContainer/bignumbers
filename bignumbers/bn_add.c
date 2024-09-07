#include "bignumbers.h"

static char *bn_add_sub(char *nbr1, char *nbr2)
{
	char *rtrn;
	char *abbr[3];
	char state;

	abbr[0] = nbr1;
	if (nbr1[0] == '-')
		abbr[0]++;
	abbr[1] = nbr2;
	if (nbr2[0] == '-')
		abbr[1]++;
	if (bn_is_same(abbr[0], abbr[1]))
		return (free(nbr1), free(nbr2), ft_strdup("0"));
	state = bn_is_greater(abbr[0], abbr[1]);
	if (state)
		abbr[2] = bn_substract_pos_core(ft_strdup(abbr[0]), ft_strdup(abbr[1]));
	else
		abbr[2] = bn_substract_pos_core(ft_strdup(abbr[1]), ft_strdup(abbr[0]));
	if (!abbr[2])
		return (free(nbr1), free(nbr2), NULL);
	if ((state && nbr1[0] != '-') || (!state && nbr1[0] == '-'))
		rtrn = ft_strdup(abbr[2]);
	else
		rtrn = bn_to_neg(abbr[2]);
	return (free(abbr[2]), free(nbr1), free(nbr2), rtrn);
}

static char *bn_add_neg(char *nbr1, char *nbr2)
{
	char *rtrn;
	char *temp1;
	char *temp2;

	temp1 = ft_strdup(nbr1 + 1);
	if (!temp1)
		return (NULL);
	temp2 = ft_strdup(nbr2 + 1);
	if (!temp2)
		return (free(temp1), NULL);
	rtrn = bn_add_pos(temp1, temp2);
	if (!rtrn)
		return (NULL);
	temp1 = rtrn;
	rtrn = bn_to_neg(temp1);
	free(temp1);
	return (free(nbr1), free(nbr2), rtrn);
}

char	*bn_add_pos(char *nbr1, char *nbr2)
{
	char	*rtrn;
	char	*temp;
	char	res_buff[2];
	int 	i;

	rtrn = NULL;
	res_buff[1] = 0;
	i = bn_set_length_same(&nbr1, &nbr2, ft_strlen(nbr1), ft_strlen(nbr2)) - 1;
	while (i >= 0)
	{
		bn_calc_add(&res_buff[0], &res_buff[1], nbr1[i] - 48, nbr2[i] - 48);
		temp = rtrn;
		rtrn = bn_insert_digit_to_number_l(temp, res_buff[0]);
		free(temp);
		if (!rtrn)
			return (NULL);
		i--;
	}
	if (res_buff[1])
	{
		temp = rtrn;
		rtrn = bn_insert_digit_to_number_l(temp, res_buff[1]);
		free(temp);
	}
	return (free(nbr1), free(nbr2), rtrn);
}

char	*bn_add(char *temp1, char *temp2)
{
	char	*rtrn;
	char	*nbr1;
	char	*nbr2;
	char	state;

	nbr1 = bn_get_perfect_number(temp1);
	if (!bn_isnum(nbr1))
		return (free(nbr1), NULL);
	nbr2 = bn_get_perfect_number(temp2);
	if (!bn_isnum(nbr2))
		return (free(nbr1), free(nbr2), NULL);
	state = bn_decide_sign(nbr1, nbr2, '+');
	rtrn = NULL;
	if (state == 1)
		rtrn = bn_add_pos(nbr1, nbr2);
	else if (state == -1)
		rtrn = bn_add_neg(nbr1, nbr2);
	else
		rtrn = bn_add_sub(nbr1, nbr2);
	return (rtrn);
}
