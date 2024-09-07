#include "bignumbers.h"

static char	bn_power_line_helper1(char *temp1, char *temp2, char **nbr1, char **nbr2)
{
	*nbr1 = bn_get_perfect_number(temp1);
	if (!*nbr1)
		return (0);
	else if (!bn_isnum(*nbr1))
		return (free(*nbr1), 0);
	*nbr2 = bn_get_perfect_number(temp2);
	if (!*nbr2)
		return (free(*nbr1), 0);
	else if (!bn_isnum(*nbr2))
		return (free(*nbr1), free(*nbr2), 0);
	return (1);
}

static char	bn_power_line_helper2(char *nbr1, char *nbr2)
{
	char	state;
	t_ul	len;

	state = 0;
	len = (t_ul) ft_strlen(nbr2);
	if (nbr1[0] == '-' && (nbr2[len - 1] == '0'
		|| nbr2[len - 1] == '2' || nbr2[len - 1] == '4'
		|| nbr2[len - 1] == '6' || nbr2[len - 1] == '8'))
		state = 1;
	else if (nbr1[0] == '-')
		state = -1;
	return (state);
}

static char	*bn_power_election(char *nbr1, char *nbr2)
{
	char	*rtrn;

	rtrn = NULL;
	if (nbr1[0] == '0')
	{
		if (nbr2[0] == '0')
			rtrn = ft_strdup("1");
		else
			rtrn = ft_strdup("0");
	}
	else if (nbr1[0] == '1' && !nbr1[1])
		rtrn = ft_strdup("1");
	return (rtrn);
}

char	*bn_power(char *temp1, char *temp2)
{
	char	*rtrn;
	char	*nbr1;
	char	*nbr2;
	char	state;

	if (!bn_power_line_helper1(temp1, temp2, &nbr1, &nbr2))
		return (NULL);
	rtrn = bn_power_election(nbr1, nbr2);
	if (rtrn)
		return (free(nbr1), free(nbr2), rtrn);
	if (nbr2[0] == '-')
		return (free(nbr1), free(nbr2), NULL);
	state = bn_power_line_helper2(nbr1, nbr2);
	if (!state)
		rtrn = bn_power_pos(nbr1, nbr2);
	else if (state == 1)
	{
		temp1 = nbr1 + 1;
		rtrn = bn_power_pos(temp1, nbr2);
	}
	else
		rtrn = bn_power_neg(nbr1, nbr2);
	return (free(nbr1), free(nbr2), rtrn);
}
