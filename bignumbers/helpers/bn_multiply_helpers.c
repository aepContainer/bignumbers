#include "../bignumbers.h"

char	*bn_multiply_always_pos(char *nbr1, char *nbr2)
{
	char	*rtrn;
	char	*temp1;
	char	*temp2;
	int		len;
	int		i;

	rtrn = ft_strdup("0");
	len = ft_strlen(nbr2);
	i = len;
	while (--i >= 0)
	{
		if (nbr2[i] != '0')
			temp2 = bn_multiply_helper(nbr1, nbr2[i] - 48);
		else
			continue ;
		temp2 = bn_multiply_by_10(temp2, len - i - 1);
		temp1 = rtrn;
		rtrn = bn_add(temp1, temp2);
		free(temp1);
		free(temp2);
		if (!rtrn)
			return (NULL);
	}
	return (rtrn);
}

char	*bn_multiply_by_10(char *nbr, char times)
{
	char	*rtrn;
	int		len;
	int		i;

	if (!nbr || !nbr[0])
		return (NULL);
	if (!times)
		return (nbr);
	len = ft_strlen(nbr);
	rtrn = (char *) ft_calloc(1, len + times + 1);
	if (!rtrn)
		return (NULL);
	i = -1;
	while (nbr[++i])
		rtrn[i] = nbr[i];
	while (i < len + times)
		rtrn[i++] = '0';
	rtrn[i] = 0;
	return (free(nbr), rtrn);
}

char	*bn_multiply_helper(char *nbr, char digit)
{
	char	*rtrn;
	char	*temp;
	char	res_buff[2];
	int		i;

	rtrn = ft_strdup("");
	i = ft_strlen(nbr);
	res_buff[1] = 0;
	while (--i >= 0)
	{
		bn_calc_multiply(&res_buff[0], &res_buff[1], nbr[i] - 48, digit);
		temp = rtrn;
		rtrn = bn_insert_digit_to_number_l(temp, res_buff[0]);
		free(temp);
		if (!rtrn)
			return (NULL);
	}
	if (res_buff[1])
	{
		temp = rtrn;
		rtrn = bn_insert_digit_to_number_l(temp, res_buff[1]);
		free(temp);
	}
	return (rtrn);
}

char	*bn_multiply_helper_neg(char *temp1, char *temp2)
{
	char	*rtrn;
	char	*nbr1;
	char	*nbr2;

	nbr1 = temp1;
	nbr2 = temp2;
	if (temp1[0] == '-')
		nbr1++;
	if (temp2[0] == '-')
		nbr2++;
	rtrn = bn_multiply_always_pos(nbr1, nbr2);
	if (!rtrn)
		return (NULL);
	nbr1 = rtrn;
	rtrn = bn_to_neg(nbr1);
	return (free(nbr1), rtrn);
}

char	*bn_multiply_helper_pos(char *temp1, char *temp2)
{
	char	*rtrn;
	char	*nbr1;
	char	*nbr2;

	nbr1 = temp1;
	nbr2 = temp2;
	if (temp1[0] == '-')
	{
		nbr1++;
		nbr2++;
	}
	rtrn = bn_multiply_always_pos(nbr1, nbr2);
	return (rtrn);
}
