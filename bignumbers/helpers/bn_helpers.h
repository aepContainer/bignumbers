#ifndef BN_HELPERS_H
# define BN_HELPERS_H

void	bn_calc_add(char *res, char *buff, char digit1, char digit2);
void	bn_calc_multiply(char *res, char *buff, char digit1, char digit2);

char	*bn_substract_add(char *nbr1, char *nbr2);
char	*bn_substract_pos_core(char *nbr1, char *nbr2);

char	*bn_multiply_always_pos(char *nbr1, char *nbr2);
char	*bn_multiply_by_10(char *nbr, char times);
char	*bn_multiply_helper(char *nbr, char digit);
char	*bn_multiply_helper_neg(char *temp1, char *temp2);
char	*bn_multiply_helper_pos(char *temp1, char *temp2);

char	*bn_power_neg(char *nbr1, char *nbr2);
char	*bn_power_pos(char *nbr1, char *nbr2);

char	**bn_divide_by_substraction(char *nbr1, char *nbr2);
char	*bn_divide_calc_flt(char *remain, char *nbr, int round);

char	bn_decide_helper_2(char sign1, char sign2);
char	bn_decide_helper_1(char sign1, char sign2);
char	bn_decide_sign(char *nbr1, char *nbr2, char sign);

char	*bn_get_perfect_number(char *nbr);
char	*bn_insert_digit_to_number_l(const char *nbr, char digit);
char	*bn_insert_digit_to_number_r(const char *nbr, char digit);

char	bn_isnum_arg(char *nbr1, ...);
char	bn_isnum(char *nbr);
char	*bn_max(char *nbr1, char *nbr2);
char	*bn_max_pos(char *nbr1, char *nbr2);
char	*bn_min(char *nbr1, char *nbr2);
char	*bn_min_pos(char *nbr1, char *nbr2);
char	*bn_to_neg(char *nbr);
char	bn_is_same(char *nbr1, char *nbr2);
char	bn_is_greater(char *nbr1, char *nbr2);
char 	bn_is_smaller(char *nbr1, char *nbr2);
int		bn_set_length_same(char **nbr1, char **nbr2, int len1, int len2);

#endif
