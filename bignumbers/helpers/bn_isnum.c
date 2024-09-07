char	bn_isnum(char *nbr)
{
	if (!nbr || !nbr[0])
		return (0);
	while (*nbr == ' ')
		nbr++;
	if (nbr[0] == '0' && !nbr[1])
		return (1);
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (nbr[0] == '0')
		return (0);
	while (*nbr)
	{
		if (*nbr < 48 || *nbr > 57)
			return (0);
		nbr++;
	}
	while (*nbr == ' ')
		nbr++;
	if (*nbr)
		return (0);
	return (1);
}
