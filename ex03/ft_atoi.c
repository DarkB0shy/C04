#include <unistd.h>
#include <stdio.h>

int spacesheck(char *str, int *i_ptr)
{
	int i = 0;
	int sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	*i_ptr = i;
	return (sign);
}

int ft_atoi(char *str)
{
	int i = 0;
	int k = 0;
	int get_sign = 0;
	get_sign = spacesheck(str, &i);
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{		
			k *= 10;
			k += str[i] - 48;
			i++;
			if (str[i] < 48 || str[i] > 57)
				break;
		}
		else
			i++;		
	}
	return (k * get_sign);
}

int main (void)
{
	char *a = "    -+--asdf123s4";
	int b = ft_atoi(a);
	printf("%d", b);
	return (0);
}
