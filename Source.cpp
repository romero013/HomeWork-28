#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T> void showArray(T arr[], int length);
template <typename T> void fillArray(T arr[], int length, int min, int max);
template <typename T> void resizeArr(T *&arr, int length, int length1);

int main() {
	setlocale(LC_ALL, "ru");

	// Задача 1
	cout << "Задача 1.\n";
	int size1, size2;	

	cout << "Введите размер первого массива: \n";
	cin >> size1;
	int* arr1 = new int[size1];
	cout << "Первый массив:\n";
	fillArray(arr1, size1, 10, 50);
	showArray(arr1, size1);

	cout << "Введите размер второго массива: \n";
	cin >> size2;
	int* arr2 = new int[size2];
	cout << "Второй массив:\n";
	fillArray (arr2, size2, 10, 50);
	showArray (arr2, size2);

	int* arr3 = new int[size1 + size2];

	for (int i = 0; i < size1; i++)
		arr3[i] = arr1[i];
	
	for (int i = size1; i < size1 + size2;) {
		for (int j = 0; j < size2; j++) {
			arr3[i] = arr2[j];
			i++;
		}
	}

	delete [] arr1;
	delete [] arr2;

	cout << "Итоговый массив:\n";
	showArray (arr3, size1 + size2);
	cout << endl;

	// Задача 2
	cout << "Задача 2.\n";
	cout << "Введите начальную длину массива: ";
	int size;
	cin >> size;
	int newSize;
	cout << "Введите конечную длину массива: ";
	cin >> newSize;
	int *arr = new int[size];
	cout << "Изначальный массив:\n";
	//fillArray(arr, size, 10, 30);
	showArray(arr, size);
	cout << "Изменённый массив:\n";
	resizeArr(arr, size, newSize);
	showArray(arr, newSize);

	return 0;
}
// Изменение длины массива
template <typename T> void resizeArr(T *&arr, int length, int length1) {	

	if (length < length1) {
		T *tmp = new T[length1];
		for (int i = 0; i < length1; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
	}
	else {
		T *tmp = new T[length - (length - length1)];
		for (int i = 0; i < length - (length - length1); i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
	}
}
// Вывод массива
template <typename T> void showArray(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
// Заполнение массива случайными числами
template <typename T> void fillArray(T arr[], int length, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}