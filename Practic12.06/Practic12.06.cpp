#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	// линейный поиск
	
	int arr[5]{ 1,2,3,4,5 };
	int a = 4;
	for (int i = 0; i < 5; i++) {
		if (a == arr[i]) {
			cout << "Число есть в массиве под индексом " << i;
			break;
		}
	}
	
	// сортировка выбором
	
	const size_t size = 5;
	int arr[size]{ 1,2,3,4,5 };
	int i, j, k;
	int x;
	for (i = 0; i < size; i++) {
		k = i;
		x = arr[i];
		// цикл выбора наименьшего элемента
		for (j = i + 1; j < size; j++) {
			if (arr[j] < x) {
				k = j; // k - индекс наименьшего элемента
				x = arr[j];
			}
		}
		if (k != i) {
			arr[k] = arr[i];
			arr[i] = x;
		}
	}
	
	// пузырьковая сортировка
	
	int i, j, x;
	for (i = 0; i < size; i++) {
		// первый вариант
		for (j = size - 1; j > i; j--) {
			if (arr[j - 1] > arr[j]) {
				x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
		// второй вариант
		for (j = i; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				x = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = x;
			}
		}
	}
	
	// сортировка вставками
	
	int i, j, x;
	for (i = 0; i < size; i++) {
		x = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > x; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = x;
	}
	
	/*
	Написать программу, которая вводит по строкам с клавиатуры двумерный массив
	и вычисляет сумму его элементов по столбцам.
	*/
	
	const size_t col = 3, row = 4;
	int arr[col][row] = { 
		{5,8,7,1},
		{6,3,4,7},
		{1,8,9,2} 
	};
	
	//int arr[col][row];
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> arr[i][j];
		}
	}
	
	int summ = 0;
	for (int j = 0; j < row; j++) {
		for (int i = 0; i < col; i++) {
			summ += arr[i][j];
		}
		cout << summ << endl;
		summ = 0;
	}
	
	/*
	Написать программу, которая вводит по строкам с клавиатуры двумерный 
	массив и вычисляет сумму его элементов по строкам.
	*/
	
	const size_t col = 3, row = 4;
	int arr[col][row] = {
		{5,8,7,1},
		{6,3,4,7},
		{1,8,9,2}
	};

	int arr[col][row];
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> arr[i][j];
		}
	}
	
	int summ = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			summ += arr[i][j];
		}
		cout << summ << endl;
		summ = 0;
	}
	
	// объединение двух массивов в один, без повторений
	
	const size_t s = 5;
	size_t size_final = 0;
	int arr[s] = { 7,8,9,1,7 };
	int arr2[s] = { 2,6,7,2,1 };
	
	// подсчет кол-ва элемнтов для третьего массива
	int arr_all[s+s]; // создание одного общего массива
	//{ 7,8,9,1,7,2,6,7,2,1 };
	for (int i = 0; i < s; i++) {
		arr_all[i] = arr[i];
		arr_all[i + s] = arr2[i];
	}
	int final_size = 1, count = 0;
	// цикл для подсчета размера массива
	for (int i = 1; i < 2 * s; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr_all[i] == arr_all[j]) {
				count++;
			}
		}
		if (count == 0) {
			final_size++;
		}
		count = 0;
	}
	cout << final_size << endl;

	// занесение чисел без повторений в третий массив
	int* arr_final = new int[final_size];
	int temp = 1;
	arr_final[0] = arr_all[0];
	for (int i = 1; i < 2 * s; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr_all[i] == arr_all[j]) {
				count++;
			}
		}
		if (count == 0) {		
			arr_final[temp] = arr_all[i];
			temp++;
		}
		count = 0;
	}

	// вывод итогового результата
	for (int i = 0; i < final_size; i++) {
		cout << arr_final[i] << " ";
	}
	

	/*
	Написать программу, которая вводит по строкам с клавиатуры двумерный 
	массив дробного типа (3×5 — три строки по пять элементов) и вычисляет среднее 
	арифметическое элементов строк.
	*/
	
	const int col = 3, row = 5;
	double arr_double[col][row];
	// заносим элементы через консоль
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cout << "Введите число для " << i << " строки и " << j << " столбца: ";
			cin >> arr_double[i][j];
		}
	}
	// вычисляем среднеарифметическое
	double sum = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			sum += arr_double[i][j];
		}
		cout << "Среднеарифметическое: " << sum / row << endl;
		sum = 0;
	}
	

	/*
	Написать программу, которая определяет номер строки двумерного массива, 
	сумма элементов которой максимальна.
	*/
	
	int arr[3][5] = {
		{8,7,1,3,4},
		{9,5,2,8,7},
		{6,4,9,2,3}
	};
	int max_index, sum_max = 0, sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			sum += arr[i][j];
		}
		if (sum_max < sum) {
			sum_max = sum;
			max_index = i;
		}
		sum = 0;
	}
	cout << "Максимальная сумма находится в строке " << max_index;
	
	/*
	Написать программу, которая проверяет, является ли введенная с 
	клавиатуры квадратная матрица "магическим квадратом".
	Магическим квадратом называется матрица, у которой сумма чисел в каждом 
	горизонтальном ряду, в каждом вертикальном и по каждой из диагоналей одна и та же
	*/
	
	int arr[3][3] = {
		{2,9,4},
		{7,5,3},
		{6,1,8}
	};
	int summa = 0, temp_sum = 0;
	// сумма главной диагонали
	for (int i = 0; i < 3; i++) {
		summa += arr[i][i];
	}
	while (true) {
		// цикл для подсчета суммы в строках
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp_sum += arr[i][j];
			}
			if (temp_sum != summa) {
				cout << "Не магический квадрат";
				break;
			}
			else temp_sum = 0;
		}
		if (temp_sum != 0) break;
		// цикл для подсчета суммы в столбцах
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 3; i++) {
				temp_sum += arr[i][j];
			}
			if (temp_sum != summa) {
				cout << "Не магический квадрат";
				break;
			}
			else temp_sum = 0;
		}
		if (temp_sum != 0) break;
		// цикл для подсчета суммы в диагоналях
		for (int i = 0, j = 2; i < 3; i++, j--) {
			temp_sum += arr[i][j];
		}
		if (temp_sum != summa) {
			cout << "Не магический квадрат";
			break;
		}
		else {
			cout << "Магичесикй квадрат";
			break;
		}
	}
	
	/*
	Сжать (сдвинуть элементы) массив, удалив из него все 0, 
	и заполнить освободившиеся справа элементы значениями -1
	*/

	int arr[10] = { 8, -4, 7, 0, -5, 9, 0, 3, -2, 5 };
	// 8, -4, 7, -5, 9, 3, -2, -1, -1
	int temp = -1;
	for (int i = 0; i < 10; i++) {
		if (arr[i] == 0) {
			for (int j = i; j < 9; j++) {
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

	/*
	Написать программу, копирующую элементы 2-х массивов размером 5 элементов 
	каждый в один массив размером 10 элементов следующим образом: 
	сначала копируются последовательно все элементы, большие 0, 
	затем последовательно все элементы, равные 0, 
	а затем последовательно все элементы, меньшие 0
	*/

	const int size = 5;
	int arr1[size] = { 5,7,-1,-5,0 };
	int arr2[size] = { 9,0,-4,-5,0 };
	int arr3[size * 2];
	int i = 0;
	for (int j = 0; j < size; j++) {
		if (arr1[j] > 0) {
			arr3[i] = arr1[j];
			i++;
		}
	}
	for (int j = 0; j < size; j++) {
		if (arr2[j] > 0) {
			arr3[i] = arr2[j];
			i++;
		}
	}
	for (int j = 0; j < size; j++) {
		if (arr1[j] == 0) {
			arr3[i] = arr1[j];
			i++;
		}
		if (arr2[j] == 0) {
			arr3[i] = arr2[j];
			i++;
		}
	}
	for (int j = 0; j < size; j++) {
		if (arr1[j] < 0) {
			arr3[i] = arr1[j];
			i++;
		}
	}
	for (int j = 0; j < size; j++) {
		if (arr2[j] < 0) {
			arr3[i] = arr2[j];
			i++;
		}
	}
	for (int i = 0; i < size * 2; i++) {
		cout << arr3[i] << " ";
	}

	/*
	В двумерном массиве целых числе посчитать:
	■ Сумму всех элементов массива;
	■ Среднее арифметическое всех элементов массива;
	■ Минимальный элемент;
	■ Максимальный элемент.
	*/

	int arr[3][5] = {
		{6,8,1,7,2},
		{0,0,4,5,7},
		{9,6,3,4,2}
	};
	int summa = 0, max = arr[0][0], min = arr[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			summa += arr[i][j];
			if (max < arr[i][j]) max = arr[i][j];
			if (min > arr[i][j]) min = arr[i][j];
		}
	}
	cout << "Сумма элементов: " << summa << endl;
	cout << "Среднее арифметическое: " << (float)summa/(3*5)<< endl;
	cout << "Минимальный элемент: " << min << endl;
	cout << "Максимальный элемент: " << max << endl;

	/*
	В двумерном массиве целых чисел посчитать сумму элементов: 
	в каждой строке; в каждом столбце; одновременно по всем строкам и всем столбцам. 
	Оформить следующим образом:

	 3  5   6  7 | 21
	12  1   1  1 | 15
	 0  7  12  1 | 20
	-----------------
	15 13  19  9 | 56
	*/

	int arr[3][4] = {
		{3,5,6,7},
		{12,1,1,1},
		{0,7,12,1}
	};
	int sum = 0, sum2 = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw(4) << arr[i][j];
			sum += arr[i][j];
		}
		sum2 += sum;
		cout << " |" << setw(4) << sum << endl;
		sum = 0;
	}
	cout << string(24, '-') << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			sum += arr[j][i];
		}
		cout << setw(4) << sum;
		sum = 0;
	}
	cout << " |" << setw(4) << sum2;

}
