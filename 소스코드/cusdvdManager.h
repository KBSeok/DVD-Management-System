/*
	���   : �� ���� ���� ó�� �Լ����� ����.
	�ۼ��� : �����
	�ۼ��� : 190311
	����   : 1.0
*/

#ifndef _CUSMGR_H__
#define _CUSMGR_H__

void RegisterCustomer();
/*
	��� : �ű� ȸ�� ����
	��ȯ : void
*/

void SearchCusInfo();
/*
	��� : ID�� ���� ȸ�� �˻�
	��ȯ : void
*/

void RegistDVD(void);
void SearchDVDInfo(void);

void RegistRENT(void);
void SearchRENTInfo(void);

void RegistRETURN(void);
void Searchrentday_ID(void);

void InitData(void);
#endif