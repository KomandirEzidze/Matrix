#include <stdio.h>

void addition();
void subtraction();
void multiplic_number();
void multiplication();
void transpose();

void rules();

void get_matrix(int rows, int cols, int matrix[][cols]);
void show(int rows, int cols, int matrix[][cols]);

int main() {
	int choice;

	rules();
	printf("Ваш выбор: ");
	scanf("%d", &choice);

	switch (choice) {
		case 1:
			addition();
			break;
		case 2:
			subtraction();
			break;
		case 3:
			multiplic_number();
			break;
		case 4:
			transpose();
			break;
		case 5:
			multiplication();
			break;
		default:
			printf("Нет такого действия.");
	}

	return 0;
}

void rules() {
	printf("Выберите одно из действий над матрицами:\n");
	printf("1 - Сложение\n");
	printf("2 - Вычитание\n");
	printf("3 - Умножение на число\n");
	printf("4 - Транспонирование\n");
	printf("5 - Умножение матриц\n");
}

void get_matrix(int rows, int cols, int matrix[][cols]) {

	printf("Введите элементы матрицы:\n");
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			scanf("%d", &matrix[i][j]);
		}
		printf("\n");
	}
}

void addition() {
	int rows, cols;

	printf("Введите количество строк и столбцов матриц: ");
	scanf("%d %d", &rows, &cols);

	int matrix1[rows][cols];
	int matrix2[rows][cols];
	get_matrix(rows, cols, matrix1);
	get_matrix(rows, cols, matrix2);

	int matrix[rows][cols];
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			matrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	show(rows, cols, matrix);
}

void show(int rows, int cols, int matrix[][cols]) {
	printf("Ваша матрица:\n");
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

void subtraction() {
	int rows, cols;

	printf("Введите количество строк и столбцов матриц: ");
	scanf("%d %d", &rows, &cols);

	int matrix1[rows][cols];
	int matrix2[rows][cols];
	get_matrix(rows, cols, matrix1);
	get_matrix(rows, cols, matrix2);

	int matrix[rows][cols];
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			matrix[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}

	show(rows, cols, matrix);
}

void multiplic_number() {
	int rows, cols;

	printf("Введите количество строк и столбцов матрицы: ");
	scanf("%d %d", &rows, &cols);

	int matrix[rows][cols];
	get_matrix(rows, cols, matrix);

	int number;
	printf("Введите число, на которое нужно умножить: ");
	scanf("%d", &number);

	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			matrix[i][j] = matrix[i][j] * number;
		}
	}

	show(rows, cols, matrix);
}

void multiplication() {
	int m, k, n;

	printf("Введите количество строк и столбцов в первой матрице и количество столбцов во второй: ");
	scanf("%d %d %d", &m, &k, &n);

	int matrix1[m][k];
	int matrix2[k][n];
	get_matrix(m, k, matrix1);
	get_matrix(k, n, matrix2);

	int matrix[m][n];
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			matrix[i][j] = 0;
			for(int q=0;q<k;q++) {
				matrix[i][j] += matrix1[i][q] * matrix2[q][j];
			}
		}
	}

	show(m, n, matrix);
}

void transpose() {}
