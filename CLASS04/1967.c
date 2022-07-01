#include <stdio.h>
#include <stdlib.h>

int	hello2(char **arr, int V, int node, int *map2, int dd, int *res)
{
	int	i;
	int	kk;
	char	*now = *(arr + node);
	int	d;
	int	temp;
	int	min;
	int	min2;
	int	branch;

	i = 1;
	kk = *(map2 + node);
	if (!dd)
		kk = 0;
	min = kk;
	min2 = min;
	while (i <= V)
	{
		if (*(now + i) && !*(map2 + i))
		{
			d = dd + *(now + i);
			*(map2 + i) = d;
			temp = hello2(arr, V, i, map2, d, res);
			if (temp > min2)
			{
				min = min2;
				min2 = temp;
			}
			else if (temp > min)
				min = temp;
		}
		i ++;
	}
	branch = min + min2 - kk * 2;
	if (branch > *(res))
		*(res) = branch;
	return (min2);
}

int	main(void)
{
	int	V;
	int	a, b, c;
	int	map2[100001] = {0, 1, 0, 0, 0, 0, 0, };
	char	*str;
	int	i, j;
	int	node;
	char **arr;
	int	res;

	scanf("%d", &V);
	getchar();
	arr = (char **)malloc(sizeof(char *) * (V + 1));
	i = 1;
	while (i <= V)
	{
		*(arr + i) = (char *)malloc(sizeof(char) * (V + 1));
		j = 0;
		while (j <= V)
		{
			*(*(arr + i) + j) = 0;
			j ++;
		}
		i ++;
	}	
	i = 0;
	while (i < V - 1)
	{
		scanf("%d %d %d", &a, &b, &c);
		getchar();
		*(*(arr + a) + b) = c;
		i ++;
	}
	res = 0;
	hello2(arr, V, 1, map2, 0, &res);
	printf("%d", res);
	i = 1;
	while (i <= V)
	{
		free(*(arr + i));
		i ++;
	}
	free(arr);
	return (0);
}