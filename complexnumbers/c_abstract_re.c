#include "complexnumbers.h"

c_num	*c_abstract_re(c_num *nbr)
{
	c_num	*rtrn;
	char	*abs_re;

	if (!nbr || !nbr->im || !*(nbr->im) || !nbr->re || !*(nbr->re))
		return (NULL);
	abs_re = bn_abstract(nbr->re);
	if (!abs_re)
		return (NULL);
	rtrn = c_num_new(abs_re, nbr->im);
	return (free(abs_re), rtrn);
}
