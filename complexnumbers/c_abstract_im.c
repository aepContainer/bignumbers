#include "complexnumbers.h"

c_num	*c_abstract_im(c_num *nbr)
{
	c_num	*rtrn;
	char	*abs_im;

	if (!nbr || !nbr->im || !*(nbr->im) || !nbr->re || !*(nbr->re))
		return (NULL);
	abs_im = bn_abstract(nbr->im);
	if (!abs_im)
		return (NULL);
	rtrn = c_num_new(nbr->re, abs_im);
	return (free(abs_im), rtrn);
}
