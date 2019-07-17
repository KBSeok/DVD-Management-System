#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#define ISBN_LEN 30
#define TITLE_LEN 30
#define ID_LEN  10
#define RENT_LEN 100
#define Phone_LEN 20
//도서 장르 정보
enum {ACTION = 1, COMIC, SF, ROMANTIC};

//대여 상태 정보
enum {RENTED,RETURNED};


typedef struct
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;//장르

	//대여가능여부(대여, 반납)
	int rentState;
	 //  rentList의 저장 위치정보
	int numOFRentCus;
	//   대여이력
	
} dvdInfo;
 
#endif