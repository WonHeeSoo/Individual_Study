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

	// ���� �� �������� ���̸�ŭ �ݺ�
	for (int size = 0; size < maxStrSize; size++)
	{
		int divfac = 1;
		// ���Ĵ���� ����ŭ �ݺ�
		for (int sortNum = 0; sortNum < radixSize; sortNum++)
		{
			// N ��° �ڸ��� ���� ����
			int radixNum = (radixArr[sortNum] / divfac) % 10;

			// ������ ���ڸ� �ٰŷ� ��Ŷ�� ������ ����
			buckets[radixNum].Push(radixArr[sortNum]);
		}

		// ��Ŷ ����ŭ �ݺ�
		for (int bucketNum = 0, dn = 0; bucketNum < BUCKET_NUM; bucketNum++)
		{
			//��Ŷ�� ����� �� ������� �� ������ �ٽ� radixArr�� ����
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
