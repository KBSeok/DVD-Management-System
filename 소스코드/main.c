#include "COMMON.h"
#include "cusdvdManager.h"
#include "screenOut.h"

enum {CUS = 1, DVD, Information, QUIT};

void main() {
	int inPutMenu = 0;
	InitData();
	while (1) {
		ShowmainMenu();
		scanf("%d", &inPutMenu);
		getchar();

		switch (inPutMenu) {
		case CUS:
			ShowCusMenu();
			scanf("%d", &inPutMenu);
			getchar();
			if (inPutMenu == 1) RegisterCustomer();
			if (inPutMenu == 2) SearchCusInfo();
			if (inPutMenu == 3) ShowmainMenu();
			if (inPutMenu == 4) {
				puts("이용해주셔서 감사합니다.");
				exit(1);
			}
			break;

		case DVD:
			ShowDVDMenu();
			scanf("%d", &inPutMenu);
			getchar();
			if (inPutMenu == 1) RegistDVD();
			if (inPutMenu == 2) SearchDVDInfo();
			if (inPutMenu == 3) RegistRENT();
			if (inPutMenu == 4) RegistRETURN();
			if (inPutMenu == 5) ShowmainMenu();
			if (inPutMenu == 6) {
				puts("이용해주셔서 감사합니다.");
				exit(1);
			}
			break;

		case Information:
			ShowRentMenu();
			scanf("%d", &inPutMenu);
			getchar();
			if (inPutMenu == 1) SearchRENTInfo();
			if (inPutMenu == 2) Searchrentday_ID();
			if (inPutMenu == 3) ShowmainMenu();
			if (inPutMenu == 4) {
				puts("이용해주셔서 감사합니다.");
				exit(1);
			}
			break;
		}
		if (inPutMenu == QUIT) {
			puts("이용해주셔서 감사합니다.");
			break;
		}
	}
}
