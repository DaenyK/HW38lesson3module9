#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
#include "Header.h"

using namespace std;

unsigned short int q;

void main()

{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	int bckr, t;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));


	srand(time(NULL));

	unsigned short int nz;

	do
	{
		cout << "������� ����� �������: ";
		cin >> nz;

		cin.get();

		switch (nz)
		{
		case 1:
		{
			/*1.	������� ��������� � ������ NOTE1, ���������� ���� :
				a.Name � ������� � ��������
				b.TELE � ����� ��������
				c.DATE � ���� ��������(���, �����, �����)

				�������� ���������, ����������� :
			�	���� � ���������� ������ � ������ BLOCK, ��������� �� 9 ��������� ���� NOTE1,
			������ ������ ���� ����������� �� ���������;
			�	����� �� ����� ���������� � �����, ��� ��� �������� ���������� �� �����, �������� �������� ������� � ����������; ���� ������ �������� ��� � ������ ���������.*/
			note1 * block = NULL;
			block = (note1*)malloc(9 * sizeof(note1));
			int month, count = 0;
			if (block == NULL)
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			else
			{
				printf("������� ����� ������, ��� ����, ����� ������ ���������� � ��������: ");
				scanf("%d", &month);

				for (int i = 0; i < 9; i++)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

					(block + i)->name = (char*)malloc(1 * sizeof(char));
					generateName((block + i)->name);

					(block + i)->tele = (char*)malloc(1 * sizeof(char));
					generateNumber((block + i)->tele);

					//(block + i)->ymd = (dob*)malloc(1 * sizeof(dob)); 
					// ��� ��������� �������� ������ �����?
					generateDOB(block + i);

					if ((block + i)->ymd.month == month)
					{
						SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));
						count++;
					}
					printf("#%d \t %s\t%s\t %d.%d.%d\n",
						i + 1, (block + i)->name, (block + i)->tele, (block + i)->ymd.day,
						(block + i)->ymd.month, (block + i)->ymd.year);
				}
				/*sortName(block, 9);

				for (int i = 0; i < 9; i++)
				{
					printf("#%d \t %s\t%s\t %d.%d.%d\n",
						i + 1, (block + i)->name, (block + i)->tele, (block + i)->ymd.day,
						(block + i)->ymd.month, (block + i)->ymd.year);
				}*/

				if (count == 0)
					printf("\n��� �����, ���������� � ���� ������\n\n");

			}

			//�� ������� ������ � ����� ���� � �������� ��� �������������� �����, 
			//� ����� �����, � ����� ���� � �� �� ������
			//������ �������� � ���������, ���� � ����� ��� ������� �����������
			//������, ��������� ��� ������ ������ 
		}

		case 2:
		{

			/*2.	������� ��������� � ������ TOVAR, ���������� ���� :
			a.�������� ������;
			b.���������� ������ ������;
			c.��������� ������;
			d.���� ����������� ������ � ���� ���������(���, �����, ����).

				�������� ������� :
			�	�������� ������� SPISOK �� ����� ��� �� 10 �������(��������) ������
			� �������(���� ������ � ����������);
			�	���������� ������� ��������� ������;
			�	������������ ������� �� ����������� ��������� �������;
			�	������ �������� � �������, ����������� ����� 10 ������� �����.

				��� ����������� ������ ��� ������� ������ ������������ � ��������
				�� ����������.������������� ���������� ���������� �� �����������.������� ������, ������� ������������� ������ ���� �������
*/
			tovar * spisok = NULL;
			spisok = (tovar*)malloc(8 * sizeof(tovar));
			int sum = 0;
			if (spisok == NULL)
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			else
			{
				printf(" \t ��������\t ���-��\t ����\t ���� �����������\n");
				for (int i = 0; i < 8; i++)
				{
					(spisok + i)->name = (char*)malloc(1 * sizeof(char));
					generateNameOfProduct((spisok + i)->name);

					(spisok + i)->count = (int)malloc(1 * sizeof(int));
					(spisok + i)->count = 10 + rand() % 25;

					(spisok + i)->price = (int)malloc(1 * sizeof(int));
					(spisok + i)->price = 100 + rand() % 2500;
					sum += (spisok + i)->price;

					//(spisok + i)->ymd = (dob)calloc(1, sizeof(dob));
					(spisok + i)->ymd.year = 2014 + rand() % 4;
					(spisok + i)->ymd.month = 1 + rand() % 12;
					(spisok + i)->ymd.day = 1 + rand() % 30;
					printf("#%d\t %s\t %d\t %d\t %d.%d.%d\n",
						i + 1, (spisok + i)->name, (spisok + i)->count, (spisok + i)->price,
						(spisok + i)->ymd.day, (spisok + i)->ymd.month, (spisok + i)->ymd.year);
				}
				sortTovar(spisok, 8);

				printf("\n������� ��������� �������: %d\n", sum / 8);

				for (int i = 0; i < 8; i++)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

					if ((spisok + i)->ymd.year == 2017 && (spisok + i)->ymd.month < 6 || (spisok + i)->ymd.year < 2017)
						SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));

					printf("#%d\t %s\t %d\t %d\t %d.%d.%d\n",
						i + 1, (spisok + i)->name, (spisok + i)->count, (spisok + i)->price,
						(spisok + i)->ymd.day, (spisok + i)->ymd.month, (spisok + i)->ymd.year);
				}
			}
		}break;

		case 3:
		{
			/*3.	������� ��������� � ������ MARSHRUT, ���������� ���� :
			a.����� ��������;
			b.��������� ����� ��������;
			c.�������� ����� ��������;
			d.����� ��������.
				�������� ������� :
			�	�������� ������� �� ����� ��� �� 10 �������(��������) �������� � ���������
			(���� ������ � ����������);
			�	����������� �������� � ������������ ������;
			�	������������ ������� �� ����������� ������� ���������;
			�	������ �������� � ���������, ������� ���������� ��� ������������� � ������, �������� �������� �������� � ����������.

				��� ����������� ������ ��� ������� ������ ������������ � �������� �� ����������.������������� ���������� ���������� �� �����������.������� ������, ������� ������������� ������ ���� �������.*/
			marshrut * bus = NULL;
			bus = (marshrut*)malloc(8 * sizeof(marshrut));
			int sum = 0, max = 0, index;
			if (bus == NULL)
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			else
			{
				printf(" \t �����\t ������\t\t �����\t\t �����\t\n");
				for (int i = 0; i < 8; i++)
				{
					(bus + i)->number = (int)malloc(1 * sizeof(int));
					(bus + i)->number = 4 + rand() % 100;

					(bus + i)->nameStart = (char*)malloc(1 * sizeof(char));
					generateNameOfPlace((bus + i)->nameStart);

					(bus + i)->nameEnd = (char*)malloc(1 * sizeof(char));
					generateNameOfPlace((bus + i)->nameEnd);

					(bus + i)->lenght = (int)malloc(1 * sizeof(int));
					(bus + i)->lenght = 1 + rand() % 20;
					if ((bus + i)->lenght > max)
					{
						max = (bus + i)->lenght;
						index = i;
					}

					printf("#%d\t %d\t %s\t %s\t %d\t\n", i + 1, (bus + i)->number,
						(bus + i)->nameStart, (bus + i)->nameEnd, (bus + i)->lenght);
				}
				printf("\n������� � ���������� ������\n");
				printf("#%d\t %d\t %s\t %s\t %d\t\n", index + 1, (bus + index)->number,
					(bus + index)->nameStart, (bus + index)->nameEnd, (bus + index)->lenght);
				
				/*printf("\n������� �������� �����");
				char s [20]= "";
				scanf("%s", s);*/

				sortLenght(bus, 8);
				printf("\n����� ���������� �� �����\n");

				for (int i = 0; i < 8; i++)
				{
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

					//if (s== (bus + i)->nameStart ||s== (bus + i)->nameEnd)
						//SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));

					printf("#%d\t %d\t %s\t %s\t %d\t\n", i + 1, (bus + i)->number,
						(bus + i)->nameStart, (bus + i)->nameEnd, (bus + i)->lenght);
				}
			}

		}break;

		}
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		cout << "������ ���������� 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
			cout << "������" << endl;
		}
	} while (nz > 0);


}