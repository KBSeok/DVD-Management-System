#include "COMMON.h"
#include "cusInfo.h"
#include "rentInfo.h"
#include "cusdvdManager.h"
#include "screenOut.h"
#include "cusInfoAccess.h"


#define RENT_LEN 100
#define RENT_BACKUP_FILE "rentInfo.dat"

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

void StoreRentListToFile(void);

void AddRentList(char * ISBN, char * cusID, int rentDay) {
	strcpy(rentList[numOfRentCus].cusID, cusID);
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	rentList[numOfRentCus].rentDay = rentDay;
	
	numOfRentCus++;
	StoreRentListToFile();
}

void PrintOutRentAllCusInfo(char * ISBN) {
	int i;
	cusInfo * ptrCusInfo;

	for (i = 0; i < numOfRentCus; i++)
	{
		printf("´ë¿©ÀÏ : %d \n", rentList[i].rentDay);
		ptrCusInfo = GetCusPtrByID(rentList[i].cusID);
		ShowCustomerInfo(ptrCusInfo);
	}
	
}

void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end) {
	int i;

	for (i = 0; i < numOfRentCus; i++)
	{
		if (!strcmp(rentList[i].cusID, ID))
		{
			if (start <= rentList[i].rentDay && rentList[i].rentDay <= end)
				ShowDVDRentInfo(rentList[i]);
		}
	}
}


void LoadRentListFromFile(void) {
	FILE *fp = fopen(RENT_BACKUP_FILE, "rb");
	
	if (fp == NULL) return;

	fread(&numOfRentCus, sizeof(int), 1, fp);
	fread(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);
	
}

void StoreRentListToFile(void) {
	FILE *fp = fopen(RENT_BACKUP_FILE, "wb");
	
	if (fp == NULL) return;

	fwrite(&numOfRentCus, sizeof(int), 1, fp);
	fwrite(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);

	fclose(fp);
}