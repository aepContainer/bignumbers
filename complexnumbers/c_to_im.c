#include "complexnumbers.h"

char	*c_to_im(char *number)
{
	char	*rtrn;
	t_ui	i;

	if (!number || !*number)
		return (NULL);
	rtrn = (char *) ft_calloc(1, ft_strlen(number) + 2);
	if (!rtrn)
		return (NULL);
	i = -1;
	while (number[++i])
		rtrn[i] = number[i];
	rtrn[i] = 'i';
	rtrn[i + 1] = 0;
	return (rtrn);
}
