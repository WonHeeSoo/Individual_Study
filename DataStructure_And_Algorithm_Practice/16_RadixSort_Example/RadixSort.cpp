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

	// ���� ���� ������ ���ʴ�� ���� ������ �ݺ�
	for (int digit = 0; digit < digitLen; digit++)
	{
		// ���Ĵ���� ����ŭ �ݺ�
		for (int i = 0; i < numElem; i++)
		{
			// N ��° �ڸ��� ���� ����
			int radixNum = (radixArr[i] / divfac) % 10;

			// ������ ���ڸ� �ٰŷ� ��Ŷ�� ������ ����
			buckets[radixNum].Push(radixArr[i]);
		}

		// ��Ŷ ����ŭ �ݺ�
		for (int iBucket = 0, iPos = 0; iBucket < BUCKET_NUM; iBucket++)
		{
			//��Ŷ�� ����� �� ������� �� ������ �ٽ� radixArr�� ����
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
