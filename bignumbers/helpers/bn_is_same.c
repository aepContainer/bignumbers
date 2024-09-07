char	bn_is_same(char *nbr1, char *nbr2)
{
	if (!nbr1 || !nbr2 || !nbr1[0] || !nbr2[0])
		return (0);
	while (*nbr1 && *nbr2)
	{
		if (*nbr1 != *nbr2)
			return (0);
		nbr1++;
		nbr2++;
	}
	if (*nbr1 || *nbr2)
		return (0);
	return (1);
}
