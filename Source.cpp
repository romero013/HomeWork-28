#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T> void showArray(T arr[], int length);
template <typename T> void fillArray(T arr[], int length, int min, int max);
template <typename T> void resizeArr(T *&arr, int length, int length1);

int main() {
	setlocale(LC_ALL, "ru");

	// ������ 1
	cout << "������ 1.\n";
	int size1, size2;	

	cout << "������� ������ ������� �������: \n";
	cin >> size1;
	int* arr1 = new int[size1];
	cout << "������ ������:\n";
	fillArray(arr1, size1, 10, 50);
	showArray(arr1, size1);

	cout << "������� ������ ������� �������: \n";
	cin >> size2;
	int* arr2 = new int[size2];
	cout << "������ ������:\n";
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

	cout << "�������� ������:\n";
	showArray (arr3, size1 + size2);
	cout << endl;

	// ������ 2
	cout << "������ 2.\n";
	cout << "������� ��������� ����� �������: ";
	int size;
	cin >> size;
	int newSize;
	cout << "������� �������� ����� �������: ";
	cin >> newSize;
	int *arr = new int[size];
	cout << "����������� ������:\n";
	//fillArray(arr, size, 10, 30);
	showArray(arr, size);
	cout << "��������� ������:\n";
	resizeArr(arr, size, newSize);
	showArray(arr, newSize);

	return 0;
}
// ��������� ����� �������
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
// ����� �������
template <typename T> void showArray(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
// ���������� ������� ���������� �������
template <typename T> void fillArray(T arr[], int length, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}