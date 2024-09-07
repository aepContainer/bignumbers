#include "../bignumbers.h"

static char	*bn_divide_find_biggest_10(char *nbr1, char *nbr2)
{
	char	*rtrn;
	char	*temp;
	char	state;

	rtrn = NULL;
	state = bn_is_greater(nbr1, nbr2);
	if (state)
	{
		temp = ft_strdup(nbr2);
		if (!temp)
			return (NULL);
		while (state)
		{
			free(rtrn);
			rtrn = temp;
			temp = bn_insert_digit_to_number_l(temp, 0);
			if (!temp)
				return (NULL);
			state = bn_is_greater(nbr1, temp);
		}
		free(temp);
	}
	else
		rtrn = ft_strdup("0");
	return (rtrn);
}

static char	*bn_divide_bs_helper(char **exact, char **temp_big, char *nbr2)
{
	char	*rtrn;
	char	*temp;

	rtrn = NULL;
	while (bn_is_greater(*exact, temp_big) && !(*temp_big[0] == '0' && !*temp_big[1]))
	{
		temp = *exact;
		*exact = bn_substract(*exact, *temp_big);
		free(temp);
		if (!*exact)
			return (free(*temp_big), NULL);
		free(rtrn);
		rtrn = ft_strdup(*temp_big);
		if (!rtrn)
			return (free(*exact), free(*temp_big), NULL);
		temp = *temp_big;
		*temp_big = bn_divide_find_biggest_10(*exact, nbr2);
		free(temp);
		if (!*temp_big)
			return (free(*exact), NULL);
	}
	return (free(*temp_big), rtrn);
}

char	**bn_divide_by_substraction(char *nbr1, char *nbr2)
{
	char	**rtrn;
	char	*exact;
	char	*temp_big;

	rtrn = ft_calloc(sizeof(char *), 3);
	if (!rtrn)
		return (NULL);
	exact = ft_strdup(nbr1);
	if (!exact)
		return (free(rtrn), NULL);
	temp_big = bn_divide_find_biggest_10(nbr1, nbr2);
	if (!temp_big)
		return (free(rtrn), free(exact), NULL);
	if (temp_big[0] == '0' && !temp_big[1])
		return (free(rtrn), free(exact), temp_big);
	temp_big = bn_divide_exact_bs_helper(&exact, &temp_big, nbr2);
	rtrn[0] = exact;
	rtrn[1] = temp_big;
	return (rtrn);
}
