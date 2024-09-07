#ifndef BIGNUMBERS_H
# define BIGNUMBERS_H

# include "../libft/libft.h"
# include "../vartype/vartype.h"
# include "helpers/bn_helpers.h"

char	*bn_add(char *nbr1, char *nbr2);
char	*bn_add_pos(char *nbr1, char *nbr2);

char	*bn_substract(char *nbr1, char *nbr2);
char	*bn_substract_pos(char *nbr1, char *nbr2);

char	*bn_divide(char *nbr1, char *nbr2, char mode, int round);
char	*bn_divide_exact(char *nbr1, char *nbr2);
char	*bn_divide_float(char *nbr1, char *nbr2, int round);

char	*bn_multiply(char *nbr1, char *nbr2);
char	*bn_power(char *nbr1, char *nbr2);
char	*bn_modulate(char *nbr1, char *nbr2);
char	*bn_factorialize(char *nbr);
char	*bn_abstract(char *nbr);

#endif
