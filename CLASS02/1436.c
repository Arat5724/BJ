#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int	p10(int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= 10;
		power -= 1;
	}
	return (result);
}

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

int	main(void)
{
	int	N;
	int	i;
	int	j;
	int	arr[50000];
	int	count;
	int	a;
	int	b;
	int	last;

	scanf("%d", &N);
	i = 0;
	count = 0;
	while (i < 3000)
	{
		j = 0;
		last = -1;
		while (j < 4)
		{
			if (last != 6)
			{			
				a = i / p10(j);
				b = i % p10(j);
				arr[count] =  a * p10(j + 3) + 666 * p10(j) + b;
				count ++;
			}
			last = i / p10(j) % 10;;
			j ++;
		}
		i ++;
	}
	qsort(arr, count, sizeof(int), compare);
	printf("%d\n", arr[N - 1]);
	return (0);
}

