/*
	기능   : 고객 관련 업무 처리 함수들의 선언.
	작성자 : 김범석
	작성일 : 190311
	버전   : 1.0
*/

#ifndef _CUSMGR_H__
#define _CUSMGR_H__

void RegisterCustomer();
/*
	기능 : 신규 회원 가입
	반환 : void
*/

void SearchCusInfo();
/*
	기능 : ID를 통한 회원 검색
	반환 : void
*/

void RegistDVD(void);
void SearchDVDInfo(void);

void RegistRENT(void);
void SearchRENTInfo(void);

void RegistRETURN(void);
void Searchrentday_ID(void);

void InitData(void);
#endif