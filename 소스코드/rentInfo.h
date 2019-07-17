#ifndef __RENTINFO_H__
#define __RENTINFO_H__

#include "dvdInfo.h"
#include "cusInfo.h"

// ���� �߰����� �˻������ Ȯ�强�� ���ؼ�
// �˻������� ������ �Ǵ� Ű����
// �� ���� ����ü�� ����� ������.
// �׷���, ���ο� �˻������� Ű�� �߰���
// �Ǵ��� ������ ���α׷��� ��������
// ���ο� �˻� ����� ������ ������ �� ����.

typedef struct __dvdRentInfo
{
	char cusID[ID_LEN];
	char ISBN[ISBN_LEN];
	unsigned int rentDay;
} dvdRentInfo;

#endif // !__RENTINFO_H__