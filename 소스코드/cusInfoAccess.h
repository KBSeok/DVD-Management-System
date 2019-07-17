/*
	���   : �� ���� ���� �� ���� �Լ����� ����.
	�ۼ��� : �����
	�ۼ��� : 19.03.11
	Ver    : 1.0
*/

#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

/*
	��� : cusInfo �Ҵ� �� ����
	��ȯ : ���� �� ��ϵ� ������ ����, ���� �� 0�� ��ȯ
*/
int AddCusInfo(char * ID, char * name, char * num);

/*
	��� : �ش� �� ID�� ������ ������ �ִ� �����͸� ��ȯ
	��ȯ : ��� �ȵ� ID�� ��� NULL������ ��ȯ.
*/
cusInfo * GetCusPtrByID(char * ID);

/*
	��� : ���Ե� ID���� üũ
	��ȯ : ���ԵǾ����� 1, �ƴϸ� 0�� ��ȯ
*/
int IsregistID(char * ID);

//�� ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�
void LoadCusListFromFile(void);

//�� ����Ʈ�� ���Ͽ� ����ϴ� �Լ�
void StoreCusListToFile(void);

#endif