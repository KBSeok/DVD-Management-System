#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__

/*
	기능 : DVD 대여 정보를 저장하는 함수
	반환 : void
*/
void AddRentList(char * ISBN, char * cusID, int rentDay);

/*
	기능 : 특정 ISBN의 DVD 대여 고객 정보 출력 함수
*/
void PrintOutRentAllCusInfo(char * ISBN);

/*
	기능 : 일정 기간 안에 이뤄진 특정 고객의
		DVD 대여 정보 출력
*/
void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end);

//대여 이력 리스트를 파일로부터 복구하는 함수
void LoadRentListFromFile(void);

//대여 이력 리스트를 파일에 백업하는 함수
void StoreRentListToFile(void);

#endif // !__RENTACCESS_H__



