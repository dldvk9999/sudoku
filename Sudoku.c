#include <stdio.h>
#include <string.h>
#include <windows.h>

#define LENGTH 9
#define HIGH_PRINT		"\n��������������������������������������������������������\n"
#define MIDDLE_PRINT	"\n��������������������������������������������������������"
#define LOW_PRINT		  "��������������������������������������������������������\n"

int temp								= 0;
int sudoku_array[LENGTH][LENGTH]  		= { 0, };
int check_ROW	[LENGTH][LENGTH + 1] 	= { 0, };
int check_COL	[LENGTH][LENGTH + 1] 	= { 0, };
int check		[LENGTH][LENGTH + 1] 	= { 0, };

void PRINT() {
	printf(HIGH_PRINT);
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (j % (LENGTH / 3) == 0) printf("��  ");
			printf("%d ", sudoku_array[i][j]);
		}
		printf("��");
		if (i % (LENGTH / 3) == 2 && i != LENGTH - 1) printf(MIDDLE_PRINT);
		printf("\n");
	}
	printf(LOW_PRINT);
}

void ANSWER() {
	// ���ڰ� 0�� ��ĭ�� ã��
	int r = -1, c = -1;
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++)
			if (sudoku_array[i][j] == 0) {
				r = i;
				c = j;
				break;
			}
		if (r != -1) break;
	}
	
	// �ϼ��Ǿ����� ���
	if (r == -1) PRINT();
	
	// ��Ʈ��ŷ
	for (int num = 1; num <= LENGTH; num++)
		if (!check_ROW[r][num] && !check_COL[c][num] && !check[3*(r/3)+(c/3)][num]) {
			check_ROW[r][num] = check_COL[c][num] = check[3*(r/3)+(c/3)][num] = 1;
			sudoku_array[r][c] = num;
			ANSWER();
		}
}

int main(void) {
	FILE *fp = fopen("Sudoku.txt", "r");
	for (int i = 0; i < LENGTH; i++) {
		if (fp == NULL) printf("%d��° �� �Է� : ", i + 1);
		for (int j = 0; j < LENGTH; j++) {
			if (fp == NULL) scanf("%d", &temp);
			else fscanf(fp, "%d", &temp);
			sudoku_array[i][j] = temp;
			
			check_ROW[i][temp] = 1;
			check_COL[j][temp] = 1;
			check[3*(i/3)+(j/3)][temp] = 1;
		}
	}
	fclose(fp);
	printf("\n**********��� ���**********");
	ANSWER();
	system("pause");
	return 0;
}