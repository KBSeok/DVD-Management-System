/*
	���   : �ܼ������ ���� �Լ����� ����
	�ۼ��� : �����
	�ۼ��� : 190311
	����   : 1.0
*/

#ifndef _SCREENOUT_H__
#define _SCREENOUT_H__
#include "dvdInfo.h"
#include "cusInfo.h"

void ShowmainMenu();

void ShowCusMenu();

void ShowDVDMenu();

void ShowRentMenu();

void ShowCustomerInfo(cusInfo * pCus);

void ShowDVDInfo(dvdInfo * pDVD);

void ShowGenre(int gen);

void ShowInfo(dvdInfo *rentday_ID, int i);
#endif 
