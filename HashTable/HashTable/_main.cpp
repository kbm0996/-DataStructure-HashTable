#include <cstdio>
#include <Windows.h>
#include <conio.h>
#include "Hashtable.h"
using namespace std;


void main()
{
	Hashtable* AccountManager = new Hashtable;
	char chSelect;
	char szInID[df_LEN_MAX];
	char szInName[df_LEN_MAX];

	while (1)
	{
		system("cls");

		printf("## HASH TABLE ##");
		AccountManager->Print();

		printf("\n## MENU ##\n");
		printf("1. ID 생성\n");
		printf("2. ID 삭제\n");
		printf("3. ID 검색\n");
		printf("4. 종료\n\n");
		chSelect = _getch();

		switch (chSelect)
		{
		case '1':
			printf("## INSERT ID ##\n");
			printf(" ID : ");
			gets_s(szInID, sizeof(szInID));
			printf(" Name : ");
			gets_s(szInName, sizeof(szInName));

			if (AccountManager->Insert(szInID, strlen(szInID), szInName, strlen(szInName)))
				printf(" Insert Success\n");
			else
				printf(" Insert Fail\n");

			break;
		case '2':
			printf("## DELETE ID ##\n");
			printf("ID : ");
			gets_s(szInID, sizeof(szInID));

			if (AccountManager->Delete(szInID))
				printf(" Delete Success\n");
			else
				printf(" Delete Fail\n");
			break;

		case '3':
			printf("## FIND ID ##\n");
			printf(" ID : ");
			gets_s(szInID, sizeof(szInID));

			AccountManager->Search(szInID);
			break;

		case '4':
			return;
		}

		printf("\n Press Any Key...");
		_getch();
	}
}