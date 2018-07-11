#include "ArrayLinkedList.h"
#include <iostream>



int main()
{
	ArrayLinkedList *list = new ArrayLinkedList(false);
	list->Insert(0, 3);
	list->Insert(1, 4);
	list->Insert(2, 4);
	list->Insert(3, 3);
	list->Insert(4, 3);

	list->TestAllArray();

	list->RemovePosition(0);

	list->TestAllArray();

	list->RemoveData(4);

	list->TestAllArray();

	return 0;
}

// �ڵ� ���� ����� ��� �ϴ� Inline���� �Լ��� ����
// ���� 1. Inline�� ���ؼ�
// ���� �������� �Լ��� ������ �Լ��� �ּҸ� ���� �ش� ��ġ�� ���� �д� ������ ������,
// Inline �Լ��� �Լ��� ������ ȣ���ϴ� ��ġ�� �����ϵ��� �����Ϸ����� ����� ��ġ�� 
// �̵��ϴ� ������ �ٿ� �Լ� ȣ�� ������带 ���� �� �ֽ��ϴ�.
