#include "complexnumbers.h"

c_num	*c_abstract(c_num *nbr)
{
	c_num	*rtrn;
	char	*abs_re;
	char	*abs_im;

	if (!nbr || !nbr->im || !*(nbr->im) || !nbr->re || !*(nbr->re))
		return (NULL);
	abs_re = bn_abstract(nbr->re);
	if (!abs_re)
		return (NULL);
	abs_im = bn_abstract(nbr->im);
	if (!abs_im)
		return (free(abs_re), NULL);
	rtrn = c_num_new(abs_re, abs_im);
	return (free(abs_re), free(abs_im), rtrn);
}
