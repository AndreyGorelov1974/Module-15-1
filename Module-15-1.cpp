/*Задача 1
Что нужно сделать
Вам даётся массив целых чисел.
Необходимо найти такие два индекса i и j в этом массиве,
что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.

a = {-2,1,-3,4,-1,2,1,-5,4}

Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6.
Необходимо вывести 3 и 6.*/
#include <iostream>

const int sizeArray = 10;

int main()
{
	int arr[sizeArray];

	//заполняем массив случайными числами
	srand(time(NULL));
	for (int i = 0; i < sizeArray; ++i) {
		rand() % 2 == 0 ? arr[i] = rand() % 100 : arr[i] = -1 * (rand() % 100);
	}

	for (int i = 0; i < sizeArray; ++i) {
		std::cout << arr[i] << " ";
	}

	//максимальная сумма
	int maxSum = 0;
	//текущая сумма
	int currentSum = 0;
	//индексы элементов дающих максимальную сумму
	int iMax = 0;
	int jMax = 0;
	//два цикла для перебора всех возможных пар элементов
	for (int i = 0; i < sizeArray; ++i) {
		for (int j = i; j < sizeArray; ++j) {
			//подсчёт текущей суммы
			for (int k = i; k <= j; ++k) {
				currentSum += arr[k];
			}
			//если текущая сумма больше максимальной переписываем индексы  и максимальную сумму
			if (currentSum > maxSum) {
				iMax = i;
				jMax = j;
				maxSum = currentSum;
			}
			//сброс текущей суммы перед новой итерацией
			currentSum = 0;
		}
	}
	std::cout << "the array elements located between the index - " << iMax << " and the index - " << jMax << " give the maximum sum" << std::endl;
}


