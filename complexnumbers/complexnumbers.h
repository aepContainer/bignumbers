#ifndef COMPLEXNUMBERS_H
# define COMPLEXNUMBERS_H

# include "../bignumbers/bignumbers.h"

typedef struct	complex_num
{
	char	*re;
	char	*im;
}				c_num;

void	c_num_free(c_num *nbr)
{
	free(nbr->re);
	free(nbr->im);
	free(nbr);
}

//	bn_get_perfect_number() fonksiyonunu kullan!!!

//	TEMEL FONKSİYONLAR / Hepsi Test Edilmeli
c_num	*c_add(c_num *nbr1, c_num *nbr2);
c_num	*c_multiply(c_num *nbr1, c_num *nbr2);
c_num	*c_power(c_num *nbr1, char *nbr2);
c_num	*c_substract(c_num *nbr1, c_num *nbr2);
c_num	**c_divide(c_num *nbr1, c_num *nbr2);
c_num	*c_conjugate(c_num *nbr);
c_num	*c_abstract_re(c_num *nbr);
c_num	*c_abstract_im(c_num *nbr);
c_num	*c_abstract(c_num *nbr);

//	YARDIMCI FONKSİYONLAR / Hepsi Test Edilmeli
c_num	*c_num_new(char *re, char *im);
short	c_isnum_arg(c_num *nbr1, ...);
short	c_isnum(c_num *nbr);
char	*c_to_im(char *number);
char	*c_lose_im(char *im);

#endif
