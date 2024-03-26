#include <stdio.h>
#define MAX 100

void read_matrix(int N, int M, int nom[MAX][MAX])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &nom[i][j]);
	}
}

void show_matrix(int N, int M, int nom[MAX][MAX])
{
	printf("\nMatricea este:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", nom[i][j]);
		printf("\n");
	}
}

void rows(int N, int M, int groups_row[MAX + 1][MAX + 1], int nom[MAX][MAX])
{
	int elem, col, groups;
	for (int i = 0; i < N; i++) {
		int j = 0;
		while (j < M) {
			elem = 0;
			col = j; //check for groups starting from current column
			while (nom[i][col] == 1 &&  col < M) {
				elem++; //count elements of the group
				col++;
			}
			if (col != j) {
				//if it went through "while"
				j = col;
				groups_row[i][elem]++; //complete groups_row
			} else {
				j++;
			}
		}
	}
}

void cols(int N, int M, int groups_col[MAX + 1][MAX + 1], int nom[MAX][MAX])
{
	int elem, row, groups;
	for (int j = 0; j < M; j++) {
		int i = 0;
		while (i < N) {
			elem = 0;
			row = i; //check for groups starting from current row
			while (nom[row][j] == 1 &&  row < N) {
				elem++; //count elements of the group
				row++;
			}
			if (row != i) {
				//if it went through "while"
				i = row; // update the row
				groups_col[j][elem]++; //complete groups_col
			} else {
				i++;
			}
		}
	}
}

void rules(int P, int rule[MAX + 1][MAX + 1], int nom[MAX][MAX])
{
	//P = number of rows/columns
	int x, correct_nr_of_groups;
	for (int i = 0; i < P; i++) {
		scanf("%d", &correct_nr_of_groups);
		for (int k = 1; k <= correct_nr_of_groups; k++) {
			scanf("%d", &x);
			rule[i][x]++;
		}
	}
}

int main(void)
{
	int N, M, T, i, j, x, nom[MAX][MAX], ok;

	scanf("%d", &T); //number of puzzles

	while (T > 0) {
		int rule_row[MAX + 1][MAX + 1] = {0}, rule_col[MAX + 1][MAX + 1] = {0};
		//using 2 matrix for rules on rows and columns based on input
		int groups_row[MAX + 1][MAX + 1] = {0};
		int groups_col[MAX + 1][MAX + 1] = {0};
		scanf("%d%d", &N, &M);

		ok = 1; //if nomogram is correct or not

		rules(N, rule_row, nom); //complete rule_row based on input
		rules(M, rule_col, nom); //complete rule_cow based on input

		read_matrix(N, M, nom); //read completed nomogram

		rows(N, M, groups_row, nom); //complete groups_row based on nomogram
		cols(N, M, groups_col, nom); //complete groups_col based on nomogram

		for (i = 0; i < N; i++) { //verify if nomogram is correct on rows
			for (j = 1; j <= M ; j++) {
				if (groups_row[i][j] != rule_row[i][j])
					ok = 0;
			}
		}

		if (ok == 0) {
			printf("Eroare\n");
		} else {
			for (i = 0; i < M; i++) { //verify if nomogram is correct on columns
				for (j = 1; j <= N; j++) {
					if (groups_col[i][j] != rule_col[i][j])
						ok = 0;
				}
			}
			if (ok == 0)
				printf("Eroare\n");
				else
					printf("Corect\n");
		}
		T--;
	}

	return 0;
}
