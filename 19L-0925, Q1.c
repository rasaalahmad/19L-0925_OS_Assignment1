#include<stdio.h>


int main(int argv, char* filename[])
{
	char* substring = filename[2];
	FILE* fp;

        fp = fopen(filename[1], "r");

	int count = 0;

	if (fp == NULL)
	{
		printf("Error! File Not Open!!!");
	}
	else
	{
		char temp = ' ';
		int i = 0;

		while (!feof(fp))
		{				
			temp = fgetc(fp);

			if (substring[i]!='\0' && temp == substring[i])
			{
				if (substring[i + 1] == '\0')
				{
					count++;
					i = 0;
				}
				else
				{
					i++;
				}
			}		
			else
			{
				i = 0;
			}
		}
		
		printf("No of substrings: %d\n", count);
	fclose(fp);
	}



}


