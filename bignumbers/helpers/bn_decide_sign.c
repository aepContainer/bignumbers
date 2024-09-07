char	bn_decide_helper_2(char sign1, char sign2)
{
	if ((sign1 == '-' && sign2 == '-')
		|| (sign1 != '-' && sign2 != '-'))
		return (1);
	return (-1);
}

char	bn_decide_helper_1(char sign1, char sign2)
{
	if (sign1 != '-' && sign2 != '-')
		return (1);
	else if (sign1 == '-' && sign2 == '-')
		return (-1);
	return (0);
}

char	bn_decide_sign(char *nbr1, char *nbr2, char sign)
{
	if (!nbr1 || !nbr2 || !nbr1[0] || !nbr2[0])
		return (0);
	if (sign == '+')
		return (bn_decide_helper_1(nbr1[0], nbr2[0]));
	else if (sign == '-')
		return ((nbr1[0] == '-' && nbr2[0] == '-')
			|| (nbr1[0] != '-' && nbr2[0] != '-'));
	else if (sign == '*' || sign == '/')
		return (bn_decide_helper_2(nbr1[0], nbr2[0]));
	return (0);
}
