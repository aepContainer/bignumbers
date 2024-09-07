#include "../infnumbers.h"
//	* big_nums[0] int_max uzunluğundaysa ??? *
t_inf_num	*inf_num_to_neg(t_inf_num *nbr)
{
	t_inf_num	*rtrn;
	int			i;

	if (!nbr)
		return (NULL);
	rtrn = ft_calloc(1, sizeof(t_inf_num));
	if (!rtrn)
		return (NULL);
	rtrn->big_nums[0] = bn_to_neg(nbr->big_nums[0]);
	if (!rtrn->big_nums[0])
		return (inf_num_clear(rtrn), NULL);
	i = 0;
	while (++i < nbr->len)
	{
		rtrn->big_nums[i] = ft_strdup(nbr->big_nums[i]);
		if (!rtrn->big_nums[i])
			return (inf_num_clear(rtrn), NULL);
	}
	return (rtrn);
}
