#include "common.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"

#define MAX_DVD  100
#define DVD_BACKUP_FILE "dvdInfo.dat"

static dvdInfo * dvdList[MAX_DVD];
static int numOfDVD = 0;

int AddDVDInfo(char * ISBN, char * title, int genre)
{
	dvdInfo * pDVD;

	if (numOfDVD >= MAX_DVD)
		return 0;  // 입력 실패

	pDVD = (dvdInfo *)malloc(sizeof(dvdInfo));
	strcpy(pDVD->ISBN, ISBN);
	strcpy(pDVD->title, title);
	pDVD->genre = genre;

	/* 추가된 기본 초기화 */
	pDVD->rentState = RETURNED;
	//pDVD->numOfRentCus=0;

	dvdList[numOfDVD++] = pDVD;

	//DVD가 신규 등록될 경우, 파일에 백업.
	StoreDVDListToFile();

	return numOfDVD;   // 입력 성공
}

dvdInfo * GetDVDPtrByISBN(char * ISBN)
{
	int i;

	for (i = 0; i < numOfDVD; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN))
			return dvdList[i];
	}

	return (dvdInfo *)0;
}

int IsRegistISBN(char * ISBN)
{
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;  // 가입 안된 경우.
	else
		return 1;  // 가입 된 경우.
}

/* DVD 리스트를 파일로부터 복구하는 함수 */
void LoadDVDListFromFile(void)
{
	FILE *fp = fopen(DVD_BACKUP_FILE, "rb");
	if (fp == NULL) return;

	fread(&numOfDVD, sizeof(int), 1, fp);

	for (int i = 0; i < numOfDVD; i++)
	{
		dvdList[i] = (dvdInfo *)malloc(sizeof(dvdInfo));
		fread(dvdList[i], sizeof(dvdInfo), 1, fp);
	}

	fclose(fp);
}

/* DVD 리스트를 파일에 백업하는 함수 */
void StoreDVDListToFile(void)
{
	FILE * fp = fopen(DVD_BACKUP_FILE, "wb");
	if (fp == NULL) return;

	fwrite(&numOfDVD, sizeof(int), 1, fp);

	for (int i = 0; i < numOfDVD; i++)
		fwrite(dvdList[i], sizeof(dvdInfo), 1, fp);

	fclose(fp);
}