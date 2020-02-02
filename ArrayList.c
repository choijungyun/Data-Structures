/*
�迭 ��� ����Ʈ

	���� : �������� ������ ����. 
		   �ε��� ���� �������� ���� �� ���� ������ �����ϴ�.
		   �������� ������ �����ϴ�
	
	���� : �迭�� ���̰� �ʱ⿡ �����Ǿ�� �Ѵ�. ���� �Ұ���
		   ������ �������� �������� �̵�(����)�� �ſ� ����� �Ͼ��.
*/
#include <stdio.h>
#include "ArrayList.h"

//�迭 ��� ����Ʈ�� �ʱ�ȭ
// ������ �ʱ�ȭ�� ����� ����ü ������ ����̴�.
// ���� �ʱ�ȭ �Լ��� ������ ����ü�� ���Ǹ� ������� �Ѵ�.
void ListInit(List * plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1; //-1�� �ƹ��� ��ġ�� �������� �ʾ����� �ǹ�
}
/*
	(plist->numOfData) == (*plist).numOfData
	*plist�� �ڷ��� List -> List�� ����ü�� ����Ŵ
	���� ����ü�� ��������� �����ϰ� �ִ� ��!
	
*/


//�迭 ��� ����Ʈ�� ����
void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN) 
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;  //������ ����
	(plist->numOfData)++; //����� �������� �� ����
}

//�迭 ��� ����Ʈ�� ��ȸ
/*
	��ȸ�� ù��°�� �� ���ķ� ���� ���� ����?
	- ��ȸ�� ó������ �ٽ� �����ϰ� ���� ���� ���� 
	- �������� Ž���� ����Ǳ⿡
	- LNext�� �����Ѵٸ� ó������ �� �� ���
*/

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;  //���� ��ġ �ʱ�ȭ, ù��° ������ ������ �ǹ�
	*pdata = plist->arr[0];  //pdata�� ����Ű�� ������ ������ ����
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
//���� ��ȯ�� �Ű������� , �Լ��� ��ȯ�� ���� ���θ� �˸��� ���ؼ�


//�迭 ��� ����Ʈ�� ����
/*
	�����Ǵ� �����ʹ� ��ȯ�� ������ ���ؼ� �ǵ����ִ� ���� �Ǵ�!
	-> ����ü ������ �ּڰ��� ����� ���� free�� ���� �޸𸮸� ��ü���־�� �ؼ�
	������ �⺻ ���� �迭�� ��� ������ Data �ڸ��� �� ä���ֱ� ���� ������ ��ĭ�� �̵��Ѵ�!
	���� ���� ��ġ�� �޶������Ѵ�.
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
	(plist->curPosition)--; //������ġ�� �ϳ� �ǵ�����.
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}