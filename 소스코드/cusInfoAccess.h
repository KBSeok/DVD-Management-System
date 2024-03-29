/*
	기능   : 고객 정보 저장 및 참조 함수들의 선언.
	작성자 : 김범석
	작성일 : 19.03.11
	Ver    : 1.0
*/

#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

/*
	기능 : cusInfo 할당 및 저장
	반환 : 성공 시 등록된 정보의 개수, 실패 시 0을 반환
*/
int AddCusInfo(char * ID, char * name, char * num);

/*
	기능 : 해당 고객 ID의 정보를 가지고 있는 포인터를 반환
	반환 : 등록 안된 ID의 경우 NULL포인터 반환.
*/
cusInfo * GetCusPtrByID(char * ID);

/*
	기능 : 가입된 ID인지 체크
	반환 : 가입되었으면 1, 아니면 0을 반환
*/
int IsregistID(char * ID);

//고객 리스트를 파일로부터 복구하는 함수
void LoadCusListFromFile(void);

//고객 리스트를 파일에 백업하는 함수
void StoreCusListToFile(void);

#endif