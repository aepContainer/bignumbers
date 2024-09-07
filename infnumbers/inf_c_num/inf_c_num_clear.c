#include "infnumbers.h"

void	inf_c_num_clear(t_inf_c_num *nbr)
{
	if (!nbr)
		return ;
	inf_num_clear(nbr->re);
	inf_num_clear(nbr->im);
	free(nbr);
}
