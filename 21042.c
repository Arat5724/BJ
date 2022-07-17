#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	map[25][25];
	int		i, j;
	char	c1, c2, c3;

	i = 25;
	while (i < 50)
	{
		j = 1;
		while (j < 5)
		{
			c1 = i % 25 + 'A';
			c2 = (i - j) % 25 + 'A';
			if (j == 1)
				c3 = (i + 5) % 25;
			else if (j == 2)
				c3 = (i + 8) % 25;
			else if (j == 3)
				c3 = (i + 9) % 25;
			else if (j == 4)
				c3 = (i + 14) % 25;
			c3 += 'A';
			printf("%c%c%c\n", c1, c2, c3);
			j ++;
		}
		i ++;
	}
	return (0);
}