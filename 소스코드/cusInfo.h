/*
	���   : �� ���� ����ü
	�ۼ��� : �����
	�ۼ��� : 19.03.11.
	ver    : 1.0
*/
#ifndef __CUSINFO_H__
#define __CUSINFO_H__

#define ID_LEN 10
#define NAME_LEN 5
#define PHONE_LEN 15

typedef struct
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
}cusInfo;

#endif