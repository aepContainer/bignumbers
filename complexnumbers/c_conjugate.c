#include "complexnumbers.h"

c_num	*c_conjugate(c_num *nbr)
{
	c_num	*rtrn;
	char	*temp;

	rtrn = ft_calloc(sizeof(c_num), 1);
	if (!rtrn)
		return (NULL);
	rtrn->re = ft_strdup(nbr->re);
	if (!rtrn->re)
		return (free(rtrn), NULL);
	temp = c_lose_im(nbr->im);
	rtrn->im = bn_to_neg(temp);
	free(temp);
	if (!rtrn->im)
		return (free(rtrn->re), free(rtrn), NULL);
	temp = rtrn->im;
	rtrn->im = c_to_im(temp);
	free(temp);
	if (!rtrn->im)
		return (free(rtrn->re), free(rtrn), NULL);
	return (rtrn);
}
