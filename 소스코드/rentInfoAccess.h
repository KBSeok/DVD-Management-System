#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__

/*
	��� : DVD �뿩 ������ �����ϴ� �Լ�
	��ȯ : void
*/
void AddRentList(char * ISBN, char * cusID, int rentDay);

/*
	��� : Ư�� ISBN�� DVD �뿩 �� ���� ��� �Լ�
*/
void PrintOutRentAllCusInfo(char * ISBN);

/*
	��� : ���� �Ⱓ �ȿ� �̷��� Ư�� ����
		DVD �뿩 ���� ���
*/
void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end);

//�뿩 �̷� ����Ʈ�� ���Ϸκ��� �����ϴ� �Լ�
void LoadRentListFromFile(void);

//�뿩 �̷� ����Ʈ�� ���Ͽ� ����ϴ� �Լ�
void StoreRentListToFile(void);

#endif // !__RENTACCESS_H__



