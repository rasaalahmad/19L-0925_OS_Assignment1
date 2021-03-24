#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char name[3][40] = { '.' }, roll_number[3][20] = { '.' }, email[3][60] = { '.' };

FILE* fp;

void stringBreaking(char arr[], int index)
{
	int start = 0;
	int count = 0;
	int k = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == ',')
		{
			for (int j = start; j < i; j++)
			{
				if (count == 0)
				{
					name[index][k++] = arr[j];
				}
				else if (count == 1)
				{
					roll_number[index][k++] = arr[j];
				}
				else if (count == 2)
				{
					email[index][k++] = arr[j];
				}
			}
			if (count == 0)
			{
				name[index][k] = '\0';
			}
			else if (count == 1)
			{
				roll_number[index][k] = '\0';
			}
			else if (count == 2)
			{
				email[index][k] = '\0';
			}
			count++;
			k = 0;
			start = i + 1;
		}
	}
}

void readFile()
{
	fp = fopen("studentData.txt", "r");

	if (fp == NULL)
	{
		printf("Error! File Not Open!!!");
	}
	else
	{
		char arr[200] = { '\0' };

		int i = 0;

		while (!feof(fp))
		{
			fgets(arr, 200, fp);
			stringBreaking(arr, i);
			i++;
			if (i == 3)
			{
				break;
			}
		}
		fclose(fp);
	}	
	
}

void ADDInFile()
{
	fp = fopen("studentData.txt", "w");

	if (fp == NULL)
	{
		printf("Error! File Not Open!!!");
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			fputs(name[i], fp);
			fputc(',', fp);
			fputs(roll_number[i], fp);
			fputc(',', fp);
			fputs(email[i], fp);
			fputc(',', fp);
			fputc('\n', fp);
		}
		fclose(fp);
	}
	
}

void mainMenu()
{
	printf("\t\tMenu\n1. Press 1 to add to students details\n"); 
	printf("2. Press 2 to delete student details\n");
	printf("3. Press 3 to read data from file and print it on screen");
	printf("\n4. Press 4 to exit");
	printf("\nEnter your choice: ");
}

void addStudentMenu()
{
	printf("\n1. Press 1 to add your details\n2. Press 2 to add your 1st friend details\n3. Press 3 to add your 2nd friend details\n");
	printf("Enter your choice: ");
}

void delStudentMenu()
{
	printf("\n1. Press 1 to delete your details\n2. Press 2 to delete your 1st friend details\n3. Press 3 to delete your 2nd friend details\n");
	printf("Enter your choice:");
}

void takeInputtoadd(int choice)
{
	if (choice == 1)
	{
		if (name[0] != ".")
		{
			printf("\nEnter your name: ");
			gets(name[0]);
			gets(name[0]);
			printf("Enter your roll number: ");
			gets(roll_number[0]);
			printf("Enter your email: ");
			gets(email[0]);
		}
		else
		{
			printf("\nData already present!!!");
		}
	}
	else if (choice == 2)
	{
		if (name[1] != ".")
		{
			printf("\nEnter 1st friend name: ");
			gets(name[1]);
			gets(name[1]);
			printf("Enter 1st friend roll number: ");
			gets(roll_number[1]);
			printf("Enter 1st friend email: ");
			gets(email[1]);
		}
		else
		{
			printf("\nData already present!!!\n\n");
		}
	}
	else if (choice == 3)
	{
		if (name[2] != ".")
		{
			printf("\nEnter 2nd friend name: ");
			gets(name[2]);
			gets(name[2]);
			printf("Enter 2nd friend roll number: ");
			gets(roll_number[2]);
			printf("Enter 2nd friend email: ");
			gets(email[2]);
		}
		else
		{
			printf("\nData already present!!!\n\n");
		}
	}
	else
	{
		printf("\nInvalid Choice!!!!!\n");
	}

	ADDInFile();
}

void takeInputtoDel(int choice)
{
	if (choice == 1)
	{
		name[0][0] = '.';
		name[0][1] = '\0';

		email[0][0] = '.';
		email[0][1] = '\0';
		
		roll_number[0][0] = '.';
		roll_number[0][1] = '\0';
	}
	else if (choice == 2)
	{
		name[1][0] = '.';
		name[1][1] = '\0';

		email[1][0] = '.';
		email[1][1] = '\0';

		roll_number[1][0] = '.';
		roll_number[1][1] = '\0';
	}
	else if (choice == 3)
	{
		name[2][0] = '.';
		name[2][1] = '\0';

		email[2][0] = '.';
		email[2][1] = '\0';

		roll_number[2][0] = '.';
		roll_number[2][1] = '\0';
	}
	else
	{
		printf("\nInvalid Choice!!!!!\n");
	}

	ADDInFile();
}

void printData()
{
	for (int i = 0; i < 3; i++)
	{
		printf("\n\t\tDetails\n");
		printf("Name: %s", name[i]);
		printf("\nRoll Number: %s", roll_number[i]);
		printf("\nEmail: %s", email[i]);
		printf("\n\n");
	}
}

int main(int args, char* arg[])
{
	int options = 0;
	int addopt = 0, delopt = 0;
	int temp = 1;
	while (temp)
	{
		mainMenu();
		scanf("%d", &options);

		switch (options)
		{
		case 1:
			addStudentMenu();
			scanf("%d", &addopt);
			takeInputtoadd(addopt);
			break;
		case 2:
			delStudentMenu();
			scanf("%d", &delopt);
			takeInputtoDel(delopt);
			break;
		case 3:
			readFile();
			printData();
			break;
		case 4:
			temp = 0;
			break;
		default:
			printf("\n\nInvalid Input!!!!\n");
			break;
		}

	}
}
