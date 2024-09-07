#include "infnumbers.h"

void	inf_num_clear(t_inf_num *nbr)
{
	int	i;

	if (!nbr)
		return ;
	i = -1;
	while (++i < nbr->len)
		free(nbr->big_nums[i]);
	free(nbr);
}
