/*
	기능   : 콘솔출력을 위한 함수들의 선언
	작성자 : 김범석
	작성일 : 190311
	버전   : 1.0
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
