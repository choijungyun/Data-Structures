/*
배열 기반 리스트

	장점 : 데이터의 참조가 쉽다. 
		   인덱스 값을 기준으로 어디든 한 번에 참조가 가능하다.
		   순차접근 참조가 가능하다
	
	단점 : 배열의 길이가 초기에 결정되어야 한다. 변경 불가능
		   삭제의 과정에서 데이터의 이동(복사)가 매우 빈번히 일어난다.
*/
#include <stdio.h>
#include "ArrayList.h"

//배열 기반 리스트의 초기화
// 실제로 초기화할 대상은 구조체 변수의 멤버이다.
// 따라서 초기화 함수의 구성은 구조체의 정의를 기반으로 한다.
void ListInit(List * plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1; //-1은 아무런 위치도 참조하지 않았음을 의미
}
/*
	(plist->numOfData) == (*plist).numOfData
	*plist의 자료형 List -> List는 구조체를 가리킴
	따라서 구조체의 멤버변수에 접근하고 있는 것!
	
*/


//배열 기반 리스트의 삽입
void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN) 
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;  //데이터 저장
	(plist->numOfData)++; //저장된 데이터의 수 증가
}

//배열 기반 리스트의 조회
/*
	조회를 첫번째와 그 이후로 구분 지은 이유?
	- 조회를 처음부터 다시 시작하고 싶을 때를 위해 
	- 삭제에도 탐색이 선행되기에
	- LNext만 존재한다면 처음으로 갈 수 없어서
*/

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;  //참조 위치 초기화, 첫번째 데이터 참조를 의미
	*pdata = plist->arr[0];  //pdata가 가리키는 공간에 데이터 저장
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}
//값의 반환은 매개변수로 , 함수의 반환은 성공 여부를 알리기 위해서


//배열 기반 리스트의 삭제
/*
	삭제되는 데이터는 반환의 과정을 통해서 되돌려주는 것이 옳다!
	-> 구조체 변수의 주솟값을 사용할 때는 free를 통해 메모리를 해체해주어야 해서
	삭제의 기본 모델은 배열의 경우 삭제된 Data 자리를 꽉 채워주기 위해 앞으로 한칸씩 이동한다!
	따라서 참조 위치가 달라져야한다.
*/
LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for(i=rpos; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--; //참조위치를 하나 되돌린다.
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}