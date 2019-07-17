#include "COMMON.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "cusInfoAccess.h"
#include "cusInfo.h"
#include "rentInfoAccess.h"

void InitData(void) {
	LoadRentListFromFile();
	LoadCusListFromFile();
	LoadDVDListFromFile();
}

void RegisterCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
	
	printf("ID 입력 : ");
	gets(ID);

	if (IsregistID(ID)) {
		puts("해당 ID는 사용중입니다.");
		getchar();
		return;
	}

	printf("이름 입력 : ");
	gets(name);
	printf("전화번호 입력 :");
	gets(phoneNum);

	if (!AddCusInfo(ID, name, phoneNum))
	{
		puts("데이터 저장에 실패했습니다.");
		getchar();
		return;
	}
	

	puts("회원가입이 되었습니다");
	getchar();
}

void SearchCusInfo(void) {
	char ID[ID_LEN];
	cusInfo * cusPtr;

	printf("찾을 ID 입력: ");
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0) {
		puts("존재하지 않는 ID입니다");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}

//DVD등록
void RegistDVD(void) {

	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("ISBN 입력 : ");
	gets(ISBN);

	if (IsRegistISBN(ISBN)) {
		puts("해당 DVD는 존재합니다.");
		getchar();
		return;
	}

	printf("제목 입력 : ");
	gets(title);

	printf("장르 입력  \n");
	printf("1. ACTION 2. COMIC 3. SF 4. ROMANTIC : ");
	scanf("%d", &genre);
	getchar();

	if (!AddDVDInfo(ISBN, title, genre)) {
		printf("DVD저장에 실패하였습니다.\n");
		getchar();
		return;
	}

	puts("DVD등록이 완료되었습니다");
	getchar();

}

//등록된 DVD 찾기
void SearchDVDInfo(void) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;

	printf("찾을 ISBN 입력 : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN);
	if (dvdPtr == 0) {
		puts("존재하지 않는 DVD입니다");
		getchar();
		return;
	}

	ShowDVDInfo(dvdPtr);
}

//대여
void RegistRENT(void) {
	char ISBN[ISBN_LEN];
	char cusID[ID_LEN];
	unsigned int rentDay;

	printf("ID을 입력 : ");
	gets(cusID);

	if (!IsregistID(cusID)) {
		printf("등록되지 않은 ID입니다.");
		getchar();
		return;
	}

	printf("rentDay을 입력 : ");
	scanf("%d", &rentDay);
	getchar();

	printf("ISBN을 입력 : ");
	gets(ISBN);

	if (!IsRegistISBN(ISBN)) {
		puts("등록이되지 않은 DVD입니다.");
		getchar();
		return;
	}

	else {
		if (GetDVDPtrByISBN(ISBN)->rentState == RENTED) {
			puts("대여된 DVD입니다.");
			getchar();
			return;
		}

		else {
			GetDVDPtrByISBN(ISBN)->rentState = RENTED;
			AddRentList(ISBN, cusID, rentDay);
			StoreDVDListToFile();
		}
	}
	puts("대여가 완료되었습니다.");
	getchar();
}

//반납하기
void RegistRETURN() {
	char ISBN[ISBN_LEN];

	printf("ISBN을 입력 : ");
	gets(ISBN);

	if (!IsRegistISBN(ISBN)) {
		puts("등록이되지 않은 DVD입니다.");
		getchar();
		return;
	}

	else {
		if (GetDVDPtrByISBN(ISBN)->rentState == RENTED) {
			GetDVDPtrByISBN(ISBN)->rentState = RETURNED;
			StoreDVDListToFile();
			puts("반납되었습니다");
			getchar();
			return;
		}
		else {
			puts("반납된 DVD입니다.");
			getchar();
			return;
		}
	}
}

//ISBN으로 고객 정보 찾기
void SearchRENTInfo() {
	char ISBN[ISBN_LEN];

	printf("ISBN을 입력 : ");
	gets(ISBN);

	if (!IsRegistISBN(ISBN)) {
		puts("등록이되지 않은 DVD입니다.");
		getchar();
		return;
	}

	PrintOutRentAllCusInfo(ISBN);
}

//ID, 대출일자로 빌린 ISBN과 대출일자 찾기
void Searchrentday_ID(void) {
	char cusID[ID_LEN];
	unsigned int S_Day;
	unsigned int L_Day;

	int S_DVD, S_rentDay;//DVD, rentday를 찾기 위한 변수

	dvdInfo *dvdPtr;

	printf("시작 날짜 : ");
	scanf("%d", &S_Day);
	getchar();

	printf("마지막 날짜 : ");
	scanf("%d", &L_Day);
	getchar();

	while (S_Day > L_Day) {
		printf("마지막 날짜를 다시 입력하세요\n");
		printf("마지막 날짜 : ");
		scanf("%d", &L_Day);
		getchar();
		if (S_Day < L_Day) break;
	}

	printf("ID을 입력 : ");
	gets(cusID);

	if (!IsregistID(cusID)) {
		puts("해당 ID는 등록되지 않았습니다.");
		getchar();
		return;
	}

	PrintOutCusAllRentInfo(cusID, S_Day, L_Day);
	puts("조회를 완료하였습니다.");
	getchar();
}