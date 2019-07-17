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
	
	printf("ID �Է� : ");
	gets(ID);

	if (IsregistID(ID)) {
		puts("�ش� ID�� ������Դϴ�.");
		getchar();
		return;
	}

	printf("�̸� �Է� : ");
	gets(name);
	printf("��ȭ��ȣ �Է� :");
	gets(phoneNum);

	if (!AddCusInfo(ID, name, phoneNum))
	{
		puts("������ ���忡 �����߽��ϴ�.");
		getchar();
		return;
	}
	

	puts("ȸ�������� �Ǿ����ϴ�");
	getchar();
}

void SearchCusInfo(void) {
	char ID[ID_LEN];
	cusInfo * cusPtr;

	printf("ã�� ID �Է�: ");
	gets(ID);

	cusPtr = GetCusPtrByID(ID);
	if (cusPtr == 0) {
		puts("�������� �ʴ� ID�Դϴ�");
		getchar();
		return;
	}

	ShowCustomerInfo(cusPtr);
}

//DVD���
void RegistDVD(void) {

	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("ISBN �Է� : ");
	gets(ISBN);

	if (IsRegistISBN(ISBN)) {
		puts("�ش� DVD�� �����մϴ�.");
		getchar();
		return;
	}

	printf("���� �Է� : ");
	gets(title);

	printf("�帣 �Է�  \n");
	printf("1. ACTION 2. COMIC 3. SF 4. ROMANTIC : ");
	scanf("%d", &genre);
	getchar();

	if (!AddDVDInfo(ISBN, title, genre)) {
		printf("DVD���忡 �����Ͽ����ϴ�.\n");
		getchar();
		return;
	}

	puts("DVD����� �Ϸ�Ǿ����ϴ�");
	getchar();

}

//��ϵ� DVD ã��
void SearchDVDInfo(void) {
	char ISBN[ISBN_LEN];
	dvdInfo *dvdPtr;

	printf("ã�� ISBN �Է� : ");
	gets(ISBN);

	dvdPtr = GetDVDPtrByISBN(ISBN);
	if (dvdPtr == 0) {
		puts("�������� �ʴ� DVD�Դϴ�");
		getchar();
		return;
	}

	ShowDVDInfo(dvdPtr);
}

//�뿩
void RegistRENT(void) {
	char ISBN[ISBN_LEN];
	char cusID[ID_LEN];
	unsigned int rentDay;

	printf("ID�� �Է� : ");
	gets(cusID);

	if (!IsregistID(cusID)) {
		printf("��ϵ��� ���� ID�Դϴ�.");
		getchar();
		return;
	}

	printf("rentDay�� �Է� : ");
	scanf("%d", &rentDay);
	getchar();

	printf("ISBN�� �Է� : ");
	gets(ISBN);

	if (!IsRegistISBN(ISBN)) {
		puts("����̵��� ���� DVD�Դϴ�.");
		getchar();
		return;
	}

	else {
		if (GetDVDPtrByISBN(ISBN)->rentState == RENTED) {
			puts("�뿩�� DVD�Դϴ�.");
			getchar();
			return;
		}

		else {
			GetDVDPtrByISBN(ISBN)->rentState = RENTED;
			AddRentList(ISBN, cusID, rentDay);
			StoreDVDListToFile();
		}
	}
	puts("�뿩�� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

//�ݳ��ϱ�
void RegistRETURN() {
	char ISBN[ISBN_LEN];

	printf("ISBN�� �Է� : ");
	gets(ISBN);

	if (!IsRegistISBN(ISBN)) {
		puts("����̵��� ���� DVD�Դϴ�.");
		getchar();
		return;
	}

	else {
		if (GetDVDPtrByISBN(ISBN)->rentState == RENTED) {
			GetDVDPtrByISBN(ISBN)->rentState = RETURNED;
			StoreDVDListToFile();
			puts("�ݳ��Ǿ����ϴ�");
			getchar();
			return;
		}
		else {
			puts("�ݳ��� DVD�Դϴ�.");
			getchar();
			return;
		}
	}
}

//ISBN���� �� ���� ã��
void SearchRENTInfo() {
	char ISBN[ISBN_LEN];

	printf("ISBN�� �Է� : ");
	gets(ISBN);

	if (!IsRegistISBN(ISBN)) {
		puts("����̵��� ���� DVD�Դϴ�.");
		getchar();
		return;
	}

	PrintOutRentAllCusInfo(ISBN);
}

//ID, �������ڷ� ���� ISBN�� �������� ã��
void Searchrentday_ID(void) {
	char cusID[ID_LEN];
	unsigned int S_Day;
	unsigned int L_Day;

	int S_DVD, S_rentDay;//DVD, rentday�� ã�� ���� ����

	dvdInfo *dvdPtr;

	printf("���� ��¥ : ");
	scanf("%d", &S_Day);
	getchar();

	printf("������ ��¥ : ");
	scanf("%d", &L_Day);
	getchar();

	while (S_Day > L_Day) {
		printf("������ ��¥�� �ٽ� �Է��ϼ���\n");
		printf("������ ��¥ : ");
		scanf("%d", &L_Day);
		getchar();
		if (S_Day < L_Day) break;
	}

	printf("ID�� �Է� : ");
	gets(cusID);

	if (!IsregistID(cusID)) {
		puts("�ش� ID�� ��ϵ��� �ʾҽ��ϴ�.");
		getchar();
		return;
	}

	PrintOutCusAllRentInfo(cusID, S_Day, L_Day);
	puts("��ȸ�� �Ϸ��Ͽ����ϴ�.");
	getchar();
}