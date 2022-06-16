#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int s1 = *((int *)a);
    int	s2 = *((int *)b);

	if (s1 > s2)
		return (1);
	else if (s1 < s2)
		return (-1);
	else
    	return (0);
}

int	aply(int *queue, int front, int back, int *arr, int N, int size, int *map, int d)
{
	int	now;
	int	dis;
	int	index;

	if (front == back)
	{
		return (0);
	}
	now = queue[front];
	dis = now / 1000;
	index = now % 1000;		
	if (dis > d)
	{
		qsort(queue + front, back - front, 4, compare);
		now = queue[front];
		dis = now / 1000;
		index = now % 1000;
	}
	if (*(arr + index) && *(arr + index) < size)
		return (now);
	else
	{
		if (index / N && *(map + index - N) && *(arr + index - N) <= size)
		{
			*(queue + back) = (dis + 1) * 1000 + index - N;
			*(map + index - N) = 0;
			back ++;
		}
		if (index % N && *(map + index - 1) && *(arr + index - 1) <= size)
		{
			*(queue + back) = (dis + 1) * 1000 + index - 1;
			*(map + index - 1) = 0;
			back ++;
		}
		if (index % N != N - 1 && *(map + index + 1) && *(arr + index + 1) <= size)
		{
			*(queue + back) = (dis + 1) * 1000 + index + 1;
			*(map + index + 1) = 0;
			back ++;
		}
		if (index / N != N - 1 && *(map + index + N) && *(arr + index + N) <= size)
		{
			*(queue + back) = (dis + 1) * 1000 + index + N;
			*(map + index + N) = 0;
			back ++;
		}
		return (aply(queue, front + 1, back, arr, N, size, map, dis));
	}
}

int	main(void)
{
	int	N;
	int	size;
	int	arr[500];
	int	map[500];
	int	queue[500] = {0, };
	int	i;
	int	index;
	int	time;
	int	count;
	int	sk;
	int	fish;

	scanf("%d", &N);
	getchar();
	fish = 0;
	i = 0;
	while (i < N * N)
	{
		scanf("%d", arr + i);
		getchar();
		if (*(arr + i) == 9)
			index = i;
		else if (*(arr + i))
			fish ++;
		i ++;
	}
	size = 2;
	time = 0;
	count = 0;
	while (fish)
	{
		i = 0;
		while (i < N * N)
		{
			*(map + i) = 1;
			i ++;
		}
		i = 0;
		while (i < N * N)
		{
			if (*(arr + i) && *(arr + i) < size)
				break ;
			i ++;
		}
		if (i == N * N)
			break ;
		*(map + index) = 0;
		queue[0] = index;
		sk = aply(queue, 0, 1, arr, N, size, map, 0);
		if (!sk)
			break ;
		*(arr + index) = 0;
		index = sk % 1000;
		*(arr + index) = 9;
		time += sk / 1000;
		fish --;
		count ++;
		if (count == size)
		{
			size ++;
			count = 0;
		}
	}
	printf("%d", time);
	return (0);
}