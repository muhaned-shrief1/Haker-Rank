#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort to sort integers in descending order
int compare(const void *x, const void *y)
{
	return *(const int *)y - *(const int *)x;
}

// Function to calculate the minimum cost based on crew and job IDs
long getMinCost(int crew_id_count, int *crew_id, int job_id_count, int *job_id)
{
	// Sort crew and job IDs in descending order
	qsort(crew_id, crew_id_count, sizeof(int), compare);
	qsort(job_id, job_id_count, sizeof(int), compare);

	long totalDistance = 0;

	// Calculate the total distance as the absolute difference between corresponding each crew and job ID
	for (int i = 0; i < crew_id_count; i++)
	{
		totalDistance += abs(crew_id[i] - job_id[i]);
	}

	return totalDistance;
}

int main()
{
	int crew_id_count;
	scanf("%d", &crew_id_count);

	int *crew_id = (int *)malloc(crew_id_count * sizeof(int));
	for (int i = 0; i < crew_id_count; i++)
	{
		scanf("%d", &crew_id[i]);
	}

	int job_id_count;
	scanf("%d", &job_id_count);

	int *job_id = (int *)malloc(job_id_count * sizeof(int));
	for (int i = 0; i < job_id_count; i++)
	{
		scanf("%d", &job_id[i]);
	}

	long minCost = getMinCost(crew_id_count, crew_id, job_id_count, job_id);

	printf("%ld\n", minCost);

	free(crew_id);
	free(job_id);

	return 0;
}
