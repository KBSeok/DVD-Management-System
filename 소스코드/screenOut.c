#include "COMMON.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "cusInfo.h"
#include "rentInfo.h"

void ShowmainMenu() {
	system("cls"); //stdlib.h
	puts("----메 뉴----");
	puts("1. 회원관리");
	puts("2. DVD관리");
	puts("3. 이력조회");
	puts("4. 종료");
	puts("-------------");
	printf(" 선택 >>  ");
}

void ShowCusMenu() {
	system("cls"); //stdlib.h
	puts("----메 뉴----");
	puts("1. 회원등록");
	puts("2. 회원조회");
	puts("3. 이전화면");
	puts("4. 종료");
	puts("-------------");
	printf("선택 >>  ");
}

void ShowDVDMenu() {
	system("cls"); //stdlib.h
	puts("----메 뉴----");
	puts("1. DVD등록");
	puts("2. DVD조회");
	puts("3. 대여");
	puts("4. 반납");
	puts("5. 이전화면");
	puts("6. 종료");
	puts("-------------");
	printf("선택 >>  ");
}

void ShowRentMenu() {
	system("cls"); //stdlib.h
	puts("----메 뉴----");
	puts("1. ISBN을 이용하여 현재까지 대여한 대여자 정보찾기");
	puts("2. 날짜와 ID를 통한 고객이 대여한 DVD ISBN, 대여일 찾기");
	puts("3. 이전화면");
	puts("4. 종료");
	puts("-------------");
	printf("선택 >>  ");
}
void ShowCustomerInfo(cusInfo * pCus) {
	puts("");
	puts("----------------");
	printf(" ID : %s \n", pCus->ID);
	printf(" Name : %s \n",pCus->name);
	printf(" Phone : %s \n",pCus->phoneNum);
	puts("----------------");

	getchar();
}

void ShowGenre(int gen) {
	if (gen == 1) printf("ACTION");
	if (gen == 2) printf("COMIC");
	if (gen == 3) printf("SF");
	if (gen == 4) printf("ROMANTIC");
}

void ShowDVDInfo(dvdInfo * pDVD) {
	puts("");
	puts("---------------");
	printf(" ISBN : %s\n", pDVD->ISBN);
	printf(" Title : %s\n", pDVD->title);
	printf(" Genre : "); ShowGenre(pDVD->genre);
	printf("\n");
	puts("----------------");

	getchar();
}

void ShowDVDRentInfo(dvdRentInfo dvd)
{
	puts("");
	puts("---------------");
	printf("  ISBN: %s \n", dvd.ISBN);
	printf("  대여일 : %u \n", dvd.rentDay);
	puts("----------------");
}


