#ifndef INF_NUMBERS_H
# define INF_NUMBERS_H

# include "../complexnumbers/complexnumbers.h"

typedef struct	s_inf_num
{
	char	**big_nums;
	int		len;
}				t_inf_num;

typedef struct	s_inf_c_num
{
	t_inf_num	*re;
	t_inf_num	*im;
	int			len;
}				t_inf_c_num;

t_inf_num	*inf_num_new(char **big_nums, int len);
t_inf_num	*inf_num_add(t_inf_num *nbr1, t_inf_num *nbr2);
t_inf_num	*inf_num_multiply(t_inf_num *nbr1, t_inf_num *nbr2);
t_inf_num	*inf_num_power(t_inf_num *nbr1, t_inf_num *nbr2);
t_inf_num	*inf_num_substract(t_inf_num *nbr1, t_inf_num *nbr2);
t_inf_num	*inf_num_divide(t_inf_num *nbr1, t_inf_num *nbr2);
t_inf_num	*inf_num_modulate(t_inf_num *nbr1, t_inf_num *nbr2);
t_inf_num	*inf_num_factorialize(t_inf_num *nbr1, t_inf_num *nbr2);
t_inf_num	*inf_num_abstract(t_inf_num *nbr1, t_inf_num *nbr2);

t_inf_num	*inf_num_to_neg(t_inf_num *nbr);
void		inf_num_clear(t_inf_num *nbr);

t_inf_c_num	*inf_c_num_new(t_inf_num *re, t_inf_num *im, int len);
t_inf_c_num	*inf_c_num_add(t_inf_c_num *nbr1, t_inf_c_num *nbr2);
t_inf_c_num	*inf_c_num_multiply(t_inf_c_num *nbr1, t_inf_c_num *nbr2);
t_inf_c_num	*inf_c_num_power(t_inf_c_num *nbr1, t_inf_c_num *nbr2);
t_inf_c_num	*inf_c_num_substract(t_inf_c_num *nbr1, t_inf_c_num *nbr2);
t_inf_c_num	*inf_c_num_divide(t_inf_c_num *nbr1, t_inf_c_num *nbr2);
t_inf_c_num	*inf_c_num_conjugate(t_inf_c_num *nbr);
t_inf_c_num	*inf_c_num_abstract_re(t_inf_c_num *nbr);
t_inf_c_num	*inf_c_num_abstract_im(t_inf_c_num *nbr);
t_inf_c_num	*inf_c_num_abstract(t_inf_c_num *nbr);

t_inf_c_num	*inf_c_num_to_im(t_inf_c_num *nbr);
t_inf_c_num	*inf_c_num_lose_im(t_inf_c_num *nbr);
void		inf_c_num_clear(t_inf_c_num *nbr);

#endif
