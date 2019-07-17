#include "COMMON.h"
#include "cusInfoAccess.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100
#define CUS_BACK_UP "cusInfo.dat"

//분할컴파일에서 전역변수 선언시
//extern -> 공유, static -> 공유하지 않겠다.
static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

int AddCusInfo(char * ID, char * name, char * num) {
	cusInfo *pCus;

	if (numOfCustomer >= MAX_CUSTOMER)
		return 0;

	pCus = (cusInfo *)malloc(sizeof(cusInfo));
	strcpy(pCus->ID, ID);
	strcpy(pCus->name, name);
	strcpy(pCus->phoneNum, num);

	cusList[numOfCustomer++] = pCus;
	
	StoreCusListToFile();
	return numOfCustomer;
}

cusInfo * GetCusPtrByID(char * ID)
{
	int i;

	for (i = 0; i < numOfCustomer; i++) {
		if (!strcmp(cusList[i]->ID, ID))
			return cusList[i];
	}
	return (cusInfo *)0;
}

int IsregistID(char * ID) {
	cusInfo * pCus = GetCusPtrByID(ID);
	if (pCus == 0)
		return 0;
	else
		return 1;
}

//고객 리스트를 파일로부터 복구하는 함수
void LoadCusListFromFile(void) {
	FILE *fp= fopen(CUS_BACK_UP, "rb");

	if (fp == NULL) return;

	fread(&numOfCustomer, sizeof(int), 1, fp);

	for (int i = 0; i < numOfCustomer; i++) {
		cusList[i] = (cusInfo *)malloc(sizeof(cusInfo));
		fread(cusList[i], sizeof(cusInfo), 1, fp);
	}
}

//고객 리스트를 파일에 백업하는 함수
void StoreCusListToFile(void) {
	FILE *fp = fopen(CUS_BACK_UP, "wb");
	
	if (fp == NULL) return;

	fwrite(&numOfCustomer, sizeof(int), 1, fp);

	for (int i = 0; i < numOfCustomer; i++) 
		fwrite(cusList[i], sizeof(cusInfo), 1, fp);

	fclose(fp);
}