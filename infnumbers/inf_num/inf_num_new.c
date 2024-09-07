#include "../infnumbers.h"

t_inf_num	*inf_num_new(char **big_nums, int len)
{
	t_inf_num	*rtrn;
	int			i;

	if (!big_nums || !len)
		return (NULL);
	rtrn = ft_calloc(1, sizeof(t_inf_num));
	if (!rtrn)
		return (NULL);
	rtrn->len = len;
	rtrn->big_nums = ft_calloc(sizeof(char *), len);
	if (!rtrn->big_nums)
		return (free(rtrn), NULL);
	i = -1;
	while (++i < len)
	{
		rtrn->big_nums[i] = ft_strdup(big_nums[i]);
		if (!rtrn->big_nums[i])
			return (inf_num_clear(rtrn), NULL);
	}
	return (rtrn);
}
