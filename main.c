#include <stdio.h>
#include <math.h>

void addition();
void subtraction();
void multiplic_number();
void multiplication();
void transpose();
void revers();

void rules();

void get_matrix(int rows, int cols, int matrix[][cols]);

void show_int(int rows, int cols, int matrix[rows][cols]);
void show_float(int rows, int cols, float matrix[rows][cols]);

void write_int(FILE* file, int rows, int cols, int matrix[rows][cols]);
void write_float(FILE* file, int rows, int cols, float matrix[rows][cols]);

int det(FILE* file ,int n, int matrix[n][n]);
void determinist();

void inverse();

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
		case 6:
			determinist();
			break;
		case 7:
		  revers();
			break;
		default:
			printf("Нет такого действия.\n");
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
	printf("6 - Найти определитель\n");
	printf("7 - Найти обратную матрицу\n");
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

	show_int(rows, cols, matrix);
}

void show_int(int rows, int cols, int matrix[][cols]) {
	printf("\n");
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void show_float(int rows, int cols, float matrix[][cols]) {
	printf("\n");
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			printf("%.2f\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void write_int(FILE* file, int rows, int cols, int matrix[rows][cols]) {
	fprintf(file, "\n");
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			fprintf(file, "%d\t", matrix[i][j]);
		}
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
}

void write_float(FILE* file, int rows, int cols, float matrix[rows][cols]) {
	fprintf(file, "\n");
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			fprintf(file, "%.2f\t", matrix[i][j]);
		}
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
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

	printf("Итоговая матрица:\n");
	show_int(rows, cols, matrix);
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

	printf("Итоговая матрица:\n");
	show_int(rows, cols, matrix);
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

	printf("Итоговая матрица:\n");
	show_int(m, n, matrix);
}

void transpose() {
	int rows, cols;

	printf("Введите количество строк и столбцов в матрице: ");
	scanf("%d %d", &rows, &cols);

	int original_matrix[rows][cols];
	get_matrix(rows, cols, original_matrix);

	int matrix[cols][rows];
	for (int i=0;i<rows;i++) {
		for (int j=0;j<cols;j++) {
			matrix[j][i] = original_matrix[i][j];
		}
	}

	printf("Транспонированная матрица:\n");
	show_int(cols, rows, matrix);
}

int det(FILE* file, int n, int matrix[n][n]) {
	int result;

	show_int(n, n, matrix);
	if (file != NULL) {
		write_int(file, n, n, matrix);
	}

	switch (n) {
		case 1:
			result = matrix[0][0];
			break;
		case 2:
			result = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
			break;
		case 3:
			// схема Саррюса
			result = matrix[0][0] * matrix[1][1] * matrix[2][2] + // главная диагональ
						matrix[0][2] * matrix[1][0] * matrix[2][1] + // равнобедренный треугольник
						matrix[0][1] * matrix[1][2] * matrix[2][0] - // равнобедренный треугольник
						matrix[0][2] * matrix[1][1] * matrix[2][0] - // побочная диагональ
						matrix[0][0] * matrix[1][2] * matrix[2][1] - // равнобедренный треугольник
						matrix[0][1] * matrix[2][2] * matrix[1][0];  // равнобедренный треугольник
			break;
		default:
			result = 0;
			for (int j=0;j<n;j++) {
				int temp_matrix[n-1][n-1];
				for (int i=0;i<n-1;i++) {
					for (int k=0;k<n;k++) {
						if (k < j) {
							temp_matrix[i][k] = matrix[i+1][k];
						} else if (k > j) {
							temp_matrix[i][k-1] = matrix[i+1][k];
						}
					}
				}
				int sign = j%2==0 ? 1 : -1;
				result += matrix[0][j] * det(file, n-1 ,temp_matrix) * sign;
			}
	}

	return result;
}

void determinist() {
	int n;
	printf("Укажите для матрицы какого порядка нужно найти определитель: ");
	scanf("%d", &n);

	int matrix[n][n];
	get_matrix(n, n, matrix);

	FILE *file;
	file = fopen("file.txt", "a");

	int result = det(file, n, matrix);
	printf("Определитель матрицы равен: %d\n", result);
}

void revers(){
	int n;
	printf("Введите порядок матрицы: ");
	scanf("%d", &n);

	int matrix[n][n];
	get_matrix(n, n, matrix);

	FILE *file;
	file = fopen("file.txt", "a");

	int det_matrix = det(file, n, matrix);

	if (det_matrix != 0) {

		int transpose_matrix[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
	      transpose_matrix[i][j] = matrix[j][i];
			}
		}

		printf("Транспонированная матрица:\n");
		show_int(n, n, transpose_matrix);
		if (file != NULL) {
			fprintf(file, "Транспонированная матрица\n");
			write_int(file, n, n, transpose_matrix);
		}

		int union_matrix[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
    		int minor[n-1][n-1];

				for (int a=0; a<n; a++) {
		  		for (int b=0; b<n; b++) {
						if (a<i && b>j) {
							minor[a][b-1]=transpose_matrix[a][b];
						}
						else if (a<i && b<j) {
							minor[a][b]=transpose_matrix[a][b];
						}
						else if (a>i && b<j) {
							minor[a-1][b]=transpose_matrix[a][b];
						}
						else if (a>i && b>j) {
							minor[a-1][b-1]=transpose_matrix[a][b];
						}
					}
				}

				printf("Минор элемента %d строки %d столбца:\n", i+1, j+1);
				if (file != NULL) {
					fprintf(file, "Минор элемента %d строки %d столбца:\n", i+1, j+1);
				}

				int sign=(((i+j)%2==0)?1:-1);
				union_matrix[i][j]=sign*det(file, n-1,minor);
			}
		}

		printf("Союзная матрица:\n");
		show_int(n, n, union_matrix);
		if (file != NULL) {
			fprintf(file, "Союзная матрица:\n");
			write_int(file, n, n, union_matrix);
		}

		float revers_matrix[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				revers_matrix[i][j]=1/(float)det_matrix*union_matrix[i][j];
			}
		}

		printf("Обратная матрица:\n");
		show_float(n, n, revers_matrix);
		if (file != NULL) {
			fprintf(file, "Обратная матрица:\n");
			write_float(file, n, n, revers_matrix);
		}
	}

	fclose(file);
}
