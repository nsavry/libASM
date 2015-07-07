#include "libftasm.h"

int        main(void)
{
	char	test[99][99] = {"9789", "109.6", "+109.5", ")19", "898a", "98.0.0"
						"-8", "-223f", "-.8", "45", "lol", "-/98", "98.", "99999999"};
	char	str[] = "cette phrase a ete ecris avec ft_putchar!!!\n";
	char	str2[] = "abcdefghijklmnopqrstuvwxyz";
	int		i = 0;
	int		var = 0;
	
	printf("----------ft_isinteger-----------\n");
	while (i < 13)
	{
		printf("%s: %i\n", test[i], ft_isinteger(test[i]));
		i++;
	}
	i = 0;
	printf("----------ft_isfloat-------------\n");
	while (i < 13)
	{
		printf("%s: %i\n", test[i], ft_isfloat(test[i]));
		i++;
	}
	i = 0;
	printf("----------ft_putchar-------------\n");
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
	i = 0;
	printf("----------ft_isspace-------------\n");
	while (i < 100)
	{
		if (ft_isspace(i) != isspace(i))
		{
			printf("fail sur %i\n", i);
			var = 1;
		}
		i++;
	}
	if (var == 0)
		printf("ft_isspace OK\n");
	i = 0;
	var = 0;
	printf("----------ft_strchr-------------\n");
	while (str2[i] != 0)
	{
		if (ft_strchr(str, str2[i]) != strchr(str, str2[i]))
		{
			var = 1;
			printf("fail sur %c\n", str[i]);
		}
		i++;
	}
	if (var == 0)
		printf("ft_strchr OK\n");
	return (0);
}
