#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int filledOrders(int order_count, int *order, int k)
{
	qsort(order, order_count, sizeof(int), compare);

	int filledCounter = 0;

	for (int i = 0; i < order_count && k >= order[i]; i++)
	{
		filledCounter++;
		k -= order[i];
	}

	return filledCounter;
}

int main()
{
	int order_count;
	scanf("%d", &order_count);

	int *order = (int *)malloc(order_count * sizeof(int));
	for (int i = 0; i < order_count; i++)
	{
		scanf("%d", &order[i]);
	}

	int k;
	scanf("%d", &k);

	int result = filledOrders(order_count, order, k);
	printf("%d\n", result);

	free(order);
	return 0;
}
