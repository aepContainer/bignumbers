#include "bignumbers.h"

//	code divide

//	test
//	modulate

/*
void	tester(const char *temp1, const char *temp2)
{
	char	*nbr1;
	char	*nbr2;
	char	*res;
	// char	state;

	nbr1 = (char *) temp1;
	nbr2 = (char *) temp2;
	res = bn_multiply(nbr1, nbr2);
	if (!res)
		return ;
	ft_printf("tester;\nnbr1 : %s\tnbr2 : %s\nres : %s\n\n", nbr1, nbr2, res);
	free(res);
}

//*/

int	main(void)
{
	char	*temp1;
	char	*temp2;
	char	*res;

	temp1 = ft_strdup("65");
	if (!temp1)
		return (0);
	temp2 = ft_strdup("4");
	if (!temp2)
		return (free(temp1), 0);
	res = bn_divide(temp1, temp2, 'i', 0);
	if (!res)
		return (free(temp1), free(temp2), 0);
	ft_printf("\nres : %s\n\n", res);
	return (free(temp1), free(temp2), free(res), 0);
}
//*/

/*

void	tester(const char *temp)
{
	char	*nbr;
	char	*res;
	//char	state;

	nbr = (char *) temp;
	res = bn_factorialize(nbr);
	if (!res)
		return ;
	ft_printf("%s! : %s\n\n", temp, res);
	free(res);
}

void	tester_2(const char *nbr)
{
	char	*temp;
	char	*nbr1;
	char	*nbr2;
	char	*res;

	tester(nbr);
	temp = ft_strdup("1");
	if (!temp)
		return ;
	nbr1 = bn_substract((char *) nbr, temp);
	free(temp);
	if (!nbr1)
		return ;
	res = bn_factorialize(nbr1);
	if (!res)
		return (free(nbr1));
	ft_printf("%s! : %s\n", nbr1, res);
	free(nbr1);
	nbr2 = ft_strdup(nbr);
	if (!nbr2)
		return (free(res));
	nbr1 = res;
	res = bn_multiply(res, nbr2);
	free(nbr1);
	if (!res)
		return ;
	ft_printf("%s! : %s\n", nbr2, res);
	return (free(nbr2), free(res));
}

int main(void)
{
	tester_2("56");
}

//*/
