#include <stdio.h>

int n_ascending(int n) //order digits ascending
{
	int v[10] = {0}, i, dim; //initialize an array with 0
	while (n != 0) {
		v[n % 10]++; //counting how many times a digit appears in number
		dim++;
		n /= 10;
	}
	for (i = 0; i <= 9; i++) {
		while (v[i] != 0) {
			n = n * 10 + i;
			v[i]--;
		}
	}
	return n;
}

int n_descending(int n) //order digits descending
{
	int v[10] = {0}, i, dim; //initialize an array with 0
	while (n != 0) {
		v[n % 10]++; //counting how many times a digit appears in number
		dim++;
		n /= 10;
	}
	for (i = 9; i >= 0; i--) {
		while (v[i] != 0) {
			n = n * 10 + i;
			v[i]--;
		}
	}
	return n;
}

int main(void)
{
	int n, a[101], k, found, dif, first_period_index;
	scanf("%d", &n);
	found = 0; //if we found first digit in period
	k = 0;
	dif = n_descending(n) - n_ascending(n);
	while (found == 0) {
		for (int i = 0; i < k; i++) {
			if (dif == a[i]) { //new dif is already in array
				found = 1;
				first_period_index = i;
				break;
			}
		}
		a[k] = dif;
		dif = n_descending(a[k]) - n_ascending(a[k]); //calculate new dif
		k++; //go to the next index
	}
	k--;
	printf("%d\n", first_period_index);
	for (int i = first_period_index; i < k; i++)
		printf("%d ", a[i]); //print period numbers
	return 0;
}
