#include <stdio.h>
#define MAX 100

void swap(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void selection_sort(int n, int v[])
{
	int min_index;
	for (int i = 0; i < n; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (v[min_index] > v[j])
				min_index = j;
		}
		swap(&v[i], &v[min_index]);
	}
}

int main(void)
{
	int n, i, p_min, grades[MAX], credits[MAX], p, increase[MAX], m, dim;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &grades[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &credits[i]);

	scanf("%d", &p_min);
	p = 0;

	for (i = 0; i < n; i++)
		p += grades[i] * credits[i]; //calculate points

	dim = 0;

	for (i = 0; i < n; i++) {
		if (grades[i] != 10) {
			increase[dim] = credits[i] * (10 - grades[i]); //calculate increase
			dim++;
		}
	}

	m = 0; //how many grades should be modified

	selection_sort(dim, increase);

	for (i = dim - 1; i >= 0; i--) {
		if (p < p_min && m <= dim) {
			p += increase[i]; //calculate points after a grade increased
			m++;
		}
	}

	if (p < p_min) //if it is not possible to get minimum points
		m = -1;

	printf("%d", m);

	return 0;
}
