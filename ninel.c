#include <stdio.h>
#define MIN 1000000

int main(void)
{
	int n, cur_x, prev_x, next_x, i, k, xmax_impar, xmin_par;
	int even_index, odd_index;
	long s = 0;
	scanf("%d", &n); //how many trees
	if (n >= 3) {
		scanf("%d", &prev_x);
		scanf("%d", &cur_x);
		i = 1;
		k = 0; // how many special trees
		xmax_impar = 0;
		xmin_par = MIN;
		even_index = 0;
		odd_index = 0;
		while (i < n - 1) {
			scanf("%d", &next_x);
			if (prev_x < cur_x && cur_x > next_x) { //if cur_x is special
				s += cur_x;
				k++;
			if (i % 2 == 0) { //for even index
				if (cur_x < xmin_par) {
					xmin_par = cur_x;
					even_index = 1;
				}
			} else {
				if (cur_x > xmax_impar) { //for odd index
					xmax_impar = cur_x;
					odd_index = 1;
				}
			}
		}
		//update the current and the previous tree
		prev_x = cur_x;
		cur_x = next_x;
		i++;
		}
	}

	if (k == 0) { //if there are no special trees
		xmin_par = 0;
		xmax_impar = 0;
	} else {
		//if there are special trees, but none on even index
		if (even_index == 0)
			xmin_par = -1;
		//if there are special trees, but none on odd index
		if (odd_index == 0)
			xmax_impar = -1;
	}
	printf("%ld\n", s);
	printf("%0.7f\n", k > 0 ? (double)s / k : 0);
	printf("%d\n", xmax_impar);
	printf("%d\n", xmin_par);
	return 0;
}
