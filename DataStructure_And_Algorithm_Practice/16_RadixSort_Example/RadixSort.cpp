#include "RadixSort.h"
#include "MyCircularQueue.h"


RadixSort::RadixSort() : radixArr(NULL), arraySize(0), digitLen(0)
{
}


RadixSort::~RadixSort()
{
	if (radixArr != NULL)
		delete[] radixArr;
}

void RadixSort::SetArray(const int *arr, size_t len, size_t digitLen)
{
	if (radixArr != NULL)
		delete[] radixArr;

	arraySize = len;
	this->digitLen = digitLen;
	radixArr = new int[len];
	memcpy(radixArr, arr, sizeof(int) * len);
}

void RadixSort::ResetArray()
{
	if (radixArr != NULL)
	{
		delete[] radixArr;
		radixArr = NULL;
		arraySize = 0;
		digitLen = 0;
	}
}

void RadixSort::Sort(int numElem)
{
	if (arraySize <= 0)
		return;

	MyCircularQueue<int> buckets[BUCKET_NUM];

	int divfac = 1;

	// 가장 낮은 수부터 차례대로 높은 수까지 반복
	for (int digit = 0; digit < digitLen; digit++)
	{
		// 정렬대상의 수만큼 반복
		for (int i = 0; i < numElem; i++)
		{
			// N 번째 자리의 숫자 추출
			int radixNum = (radixArr[i] / divfac) % 10;

			// 추출한 숫자를 근거로 버킷에 데이터 저장
			buckets[radixNum].Push(radixArr[i]);
		}

		// 버킷 수만큼 반복
		for (int iBucket = 0, iPos = 0; iBucket < BUCKET_NUM; iBucket++)
		{
			//버킷에 저장된 것 순서대로 다 꺼내서 다시 radixArr에 저장
			while (!buckets[iBucket].Empty())
				radixArr[iPos++] = buckets[iBucket].Pop();
		}

		divfac *= 10;
	}
}

void RadixSort::TestAllArray() const
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << radixArr[i] << " ";
	}
	cout << endl;
}
