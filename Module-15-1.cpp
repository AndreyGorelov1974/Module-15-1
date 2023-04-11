/*Задача 1
Что нужно сделать
Вам даётся массив целых чисел.
Необходимо найти такие два индекса i и j в этом массиве,
что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.

a = {-2,1,-3,4,-1,2,1,-5,4}

Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6.
Необходимо вывести 3 и 6.*/
#include <iostream>
#include <chrono>


const int sizeArray = 2000;

int main()
{
	int arr[sizeArray];

	//заполняем массив случайными числами
	srand(time(NULL));
	for (int i = 0; i < sizeArray; ++i) {
		rand() % 2 == 0 ? arr[i] = rand() % 100 : arr[i] = -1 * (rand() % 100);
	}

	
	{
		//максимальная сумма
		int maxSum = 0;
		//текущая сумма
		int currentSum = 0;
		//индексы элементов дающих максимальную сумму
		int iMax = 0;
		int jMax = 0;
		auto start = std::chrono::system_clock::now();

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
		std::cout << "The array elements located between the index - " << iMax << " and the index - "
			<< jMax << " give the maximum sum - " << maxSum << std::endl;
		std::cout << "O(n3) - "
			<< std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
	}

	{
		int maxsofar = 0;
		int	maxendinghere = 0;
		auto start = std::chrono::system_clock::now();


		for (int i = 0; i < sizeArray; ++i) {
			/* инвариант: значения maxendinghere и
			   maxsofar точны для x[0..i-1] */
			maxendinghere + arr[i] > 0 ? maxendinghere = maxendinghere + arr[i] : maxendinghere = 0;
			if (maxendinghere > maxsofar) {
				maxsofar = maxendinghere;
			}
		}
		std::cout << "The array elements located between the index - " << " and the index - "
			<< " give the maximum sum - " << maxsofar << std::endl;
		std::cout << "O(n) - "
			<< std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
	}

}


