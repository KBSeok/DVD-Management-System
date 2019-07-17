#ifndef __DVDINFOACESS_H__
#define __DVDINFOACESS_H__

#include "dvdInfo.h"

/*
	��� : dvdInfo ������� �Ҵ� �� ����ü �迭 ����
	��ȯ : ���� �� ��ϵ� ������ ��, ���н�  0�� ��ȯ
*/
int AddDVDInfo(char *ISBN, char *title, int genre);

/*
	��� : �ش� ISBN�� ������ ��� �ִ� ������ �����͸� ��ȯ
	��ȯ : ��ϵ��� ���� ISBN�� ��� NULL�����͸� ��ȯ.
*/
dvdInfo * GetDVDPtrByISBN(char *ISBN);

/*
	��� : �� ��ϵ� ISBN���� üũ
	��ȯ : ��ϵǾ����� 1, �ƴϸ� 0�� ��ȯ
*/
int IsRegistISBN(char * ISBN);

//DVD ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�
void LoadDVDListFromFile();

//DVD ����Ʈ�� ���Ͽ� ����ϴ� �Լ�
void StoreDVDListToFile(void);

#endif