#include "ArrayLinkedList.h"
#include <iostream>



int main()
{
	ArrayLinkedList *list = new ArrayLinkedList(false);

	list->Insert(3);
	list->Insert(2);
	list->Insert(3);
	list->Insert(1);
	list->Insert(1);
	
	list->TestAllArray();

	list->Remove(2);

	list->TestAllArray();

	list->Insert(2, 10);

	list->TestAllArray();

	return 0;
}

// �ڵ� ���� ����� ��� �ϴ� Inline���� �Լ��� ����
// ���� 1. Inline�� ���ؼ�
// ���� �������� �Լ��� ������ �Լ��� �ּҸ� ���� �ش� ��ġ�� ���� �д� ������ ������,
// Inline �Լ��� �Լ��� ������ ȣ���ϴ� ��ġ�� �����ϵ��� �����Ϸ����� ����� ��ġ�� 
// �̵��ϴ� ������ �ٿ� �Լ� ȣ�� ������带 ���� �� �ֽ��ϴ�.