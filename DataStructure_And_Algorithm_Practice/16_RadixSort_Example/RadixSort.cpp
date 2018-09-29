#include "RadixSort.h"
#include "MyCircularQueue.h"


RadixSort::RadixSort() : radixArr(NULL), arraySize(0), maxStrSize(0)
{
}


RadixSort::~RadixSort()
{
	if (radixArr != NULL)
		delete[] radixArr;
}

void RadixSort::SetArray(const int * arr, size_t len, size_t maxStrLen)
{
	if (radixArr != NULL)
		delete[] radixArr;

	arraySize = len;
	maxStrSize = maxStrLen;
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
		maxStrSize = 0;
	}
}

void RadixSort::Sort(int radixSize)
{
	MyCircularQueue<int> buckets[BUCKET_NUM];

	// 가장 긴 데이터의 길이만큼 반복
	for (int size = 0; size < maxStrSize; size++)
	{
		int divfac = 1;
		// 정렬대상의 수만큼 반복
		for (int sortNum = 0; sortNum < radixSize; sortNum++)
		{
			// N 번째 자리의 숫자 추출
			int radixNum = (radixArr[sortNum] / divfac) % 10;

			// 추출한 숫자를 근거로 버킷에 데이터 저장
			buckets[radixNum].Push(radixArr[sortNum]);
		}

		// 버킷 수만큼 반복
		for (int bucketNum = 0, dn = 0; bucketNum < BUCKET_NUM; bucketNum++)
		{
			//버킷에 저장된 것 순서대로 다 꺼내서 다시 radixArr에 저장
			while (!buckets[bucketNum].Empty())
				radixArr[dn++] = buckets[bucketNum].Pop();
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
