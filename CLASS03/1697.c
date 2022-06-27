#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	mini(int a, int b)
{
	return ((a < b) ? a : b);
}

int	warp(int N, int M, int result)
{
	int	M2 = M / 2;
	int	min;
	int	a, b;

	if (N >= M)
		return (N - M + result);
	if (N == 0 && M == 1)
		return (result + 1);
	if (M % 2)
		return (mini(warp(N, M - 1, result + 1), warp(N, M + 1, result + 1)));
	else
	{
		min = mini(N - M2, M - N);
		if (min >= 0)
		{
			if (min == M - N)
				return (min + result);
			else
				return (min + result + 1);
		}
		else
			return (warp(N, M / 2, result + 1));
	}
}

int	main(void)
{
	int	N;
	int	M;

	scanf("%d %d", &N, &M);
	printf("%d\n", warp(N, M, 0));
	return (0);
}