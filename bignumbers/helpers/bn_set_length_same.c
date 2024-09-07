#include "../bignumbers.h"

static char	*bn_sls_helper(char *str, int i, int len)
{
	char	*temp;

	while (i < len)
	{
		temp = str;
		str = bn_insert_digit_to_number_l(temp, 0);
		free(temp);
		i++;
	}
	return (str);
}

int bn_set_length_same(char **nbr1, char **nbr2, int len1, int len2)
{
	char *strs[3];
	int len_index[2];

	if (len1 == len2)
		return (len1);
	len_index[0] = len2;
	len_index[1] = len1;
	strs[0] = *nbr2;
	strs[1] = *nbr1;
	if (len1 > len2)
	{
		len_index[0] = len1;
		len_index[1] = len2;
		strs[0] = *nbr1;
		strs[1] = *nbr2;
	}
	if (len1 > len2)
		*nbr2 = bn_sls_helper(strs[1], len_index[1], len_index[0]);
	else
		*nbr1 = bn_sls_helper(strs[1], len_index[1], len_index[0]);
	return (len_index[0]);
}
