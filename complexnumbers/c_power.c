#include "complexnumbers.h"

c_num	*c_power(c_num *nbr1, char *nbr2)
{
	c_num	*rtrn;
	c_num	*temp;
	char	*digit_1;
	char	*temp_str;

	if (!nbr1 || !nbr2 || nbr2[0] == '-')
		return (NULL);
	digit_1 = ft_strdup("1");
	if (!digit_1)
		return (NULL);
	if (nbr2[0] == '0')
		return (c_num_new(digit_1, nbr2));
	temp_str = 0;
	while (nbr2[0] != '1')
	{
		rtrn = c_multiply(nbr1, nbr1);
		if (!rtrn)
			return (free(digit_1), NULL);
		temp_str = ft_strdup(nbr2);
		nbr2 = bn_substract(temp_str, digit_1);
		free(temp_str);
	}
	return (free(digit_1), rtrn);
}
