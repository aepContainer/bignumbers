#include "../bignumbers.h"

char	*bn_insert_digit_to_number_l(const char *nbr, char digit)
{
	char	*rtrn;
	int		i;

	if (!nbr)
	{
		rtrn = (char *) ft_calloc(1, 2);
		if (!rtrn)
			return (NULL);
		rtrn[0] = digit + '0';
		return (rtrn);
	}
	rtrn = (char *) ft_calloc(1, ft_strlen(nbr) + 2);
	if (!rtrn)
		return (NULL);
	rtrn[0] = digit + '0';
	i = -1;
	while (nbr[++i])
		rtrn[i + 1] = nbr[i];
	rtrn[i + 1] = 0;
	return (rtrn);
}

char	*bn_insert_digit_to_number_r(const char *nbr, char digit)
{
	char	*rtrn;
	int		i;

	if (!nbr || !nbr[0])
	{
		rtrn = (char *) ft_calloc(1, 2);
		if (!rtrn)
			return (NULL);
		rtrn[0] = digit + '0';
		return (rtrn);
	}
	rtrn = (char *) ft_calloc(1, ft_strlen(nbr) + 2);
	if (!rtrn)
		return (NULL);
	i = -1;
	while (nbr[++i])
		rtrn[i] = nbr[i];
	rtrn[i] = digit + '0';
	rtrn[i + 1] = 0;
	return (rtrn);
}
