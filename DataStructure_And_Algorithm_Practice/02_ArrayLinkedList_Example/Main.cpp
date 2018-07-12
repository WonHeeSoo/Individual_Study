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

// 자동 정의 만들기 사용 하니 Inline으로 함수를 생성
// 질문 1. Inline에 대해서
// 실행 과정에서 함수를 만나면 함수의 주소를 통해 해당 위치로 가서 읽는 과정을 하지만,
// Inline 함수는 함수의 내용을 호출하는 위치에 삽입하도록 컴파일러에게 명령해 위치를 
// 이동하는 과정을 줄여 함수 호출 오버헤드를 줄일 수 있습니다.