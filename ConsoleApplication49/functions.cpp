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

void generateSurname(char *name)
{
	strcpy(name, "person #");
	int a = 1 + rand() % 25;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}

void generateName (char*name)
{
	//char*name = NULL;
	//name = (char*)calloc(25, sizeof(char));

	//int a = 10 + rand() % 10;
	for (int i = 0; i < 15; i++)
	{
		name[i] = 97 + rand() % 26;

		if (i == 0 || i == 3 || i == 6)
			name[i]= toupper(name[i]);
		if (i == 1 || i == 4)
			name[i] = '.';
		if (i == 2 || i == 5)
			name[i] = ' ';
	}
}

void generateNumber(char*tele)
{
	//char *tele = NULL;
	//tele = (char*)calloc(2, sizeof(char));

	for (int i = 0; i < 11; i++)
	{
		if (i == 0)
			tele[i] = '8';
		else
			tele[i] = 48 + rand() % 9;
	}
}

void generateDOB( note1* date)
{
	date->ymd.year = 1968 + rand()%30;
	date->ymd.month = 1+ rand() % 12;
	date->ymd.day = 1 + rand() % 30;

}

void generateNameOfProduct(char *name)
{
	strcpy(name, "product #");
	int a = 1 + rand() % 25;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}


void generateNameOfPr(char *name)
{
	strcpy(name, "TOO ");
	int a = 20 + rand() % 25;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}

void generatePosition(char *name)
{
	strcpy(name, "position ");
	int a = 20 + rand() % 25;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}

void generateEducation(char *name)
{
	strcpy(name, "university ");
	int a = 20 + rand() % 25;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}

void sortName(note1* a, int r)
{
	note1 temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if ((a + j - 1)->name > (a + j)->name)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
			/*if (*(a+j) < *(a - j))
			{
			temp = *(a-j);
			*(a-j) = *(a + j);
			*(a + j) = temp;
			}*/
		}
	}
}

void sortTovar(tovar* a, int r)
{
	tovar temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if ((a + j - 1)->price > (a + j)->price)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
			/*if (*(a+j) < *(a - j))
			{
			temp = *(a-j);
			*(a-j) = *(a + j);
			*(a + j) = temp;
			}*/
		}
	}
}

void generateNameOfPlace(char *name)
{
	strcpy(name, "Place #");
	int a = 1 + rand() % 25;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}

void sortLenght(marshrut* a, int r)
{
	marshrut temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if ((a + j - 1)->lenght > (a + j)->lenght)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
			/*if (*(a+j) < *(a - j))
			{
			temp = *(a-j);
			*(a-j) = *(a + j);
			*(a + j) = temp;
			}*/
		}
	}
}