#include "COMMON.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "cusInfo.h"
#include "rentInfo.h"

void ShowmainMenu() {
	system("cls"); //stdlib.h
	puts("----�� ��----");
	puts("1. ȸ������");
	puts("2. DVD����");
	puts("3. �̷���ȸ");
	puts("4. ����");
	puts("-------------");
	printf(" ���� >>  ");
}

void ShowCusMenu() {
	system("cls"); //stdlib.h
	puts("----�� ��----");
	puts("1. ȸ�����");
	puts("2. ȸ����ȸ");
	puts("3. ����ȭ��");
	puts("4. ����");
	puts("-------------");
	printf("���� >>  ");
}

void ShowDVDMenu() {
	system("cls"); //stdlib.h
	puts("----�� ��----");
	puts("1. DVD���");
	puts("2. DVD��ȸ");
	puts("3. �뿩");
	puts("4. �ݳ�");
	puts("5. ����ȭ��");
	puts("6. ����");
	puts("-------------");
	printf("���� >>  ");
}

void ShowRentMenu() {
	system("cls"); //stdlib.h
	puts("----�� ��----");
	puts("1. ISBN�� �̿��Ͽ� ������� �뿩�� �뿩�� ����ã��");
	puts("2. ��¥�� ID�� ���� ���� �뿩�� DVD ISBN, �뿩�� ã��");
	puts("3. ����ȭ��");
	puts("4. ����");
	puts("-------------");
	printf("���� >>  ");
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
	printf("  �뿩�� : %u \n", dvd.rentDay);
	puts("----------------");
}


