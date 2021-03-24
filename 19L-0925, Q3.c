#include<stdio.h>
#include<string.h>

void reverse(char arr[], int start, int end)
{
	for (int i = 0; i < (end - start) / 2; i++)
	{
		if (arr[start] != 'a' && arr[start] != 'e' && arr[start] != 'i' && arr[start] != 'o' && arr[start] != 'u'
			&& arr[end] != 'a' && arr[end] != 'e' && arr[end] != 'i' && arr[end] != 'o'
			&& arr[end] != 'u')
		{
			char temp = arr[end];
			arr[end] = arr[start];
			arr[start] = temp;
		}
		start++;
		end--;
	}
}


int main(int argvs,char* filename[])
{
	//char* filename = "file2.txt";
	FILE* fp;

	fp = fopen(filename[1], "r");
	int i = 0;
	int j = 0;

	char arr[200] = { '\0' };

	if (fp == NULL)
	{
		printf("Error! File Not Open!!!");
	}
	else
	{
		while (!feof(fp))
		{
			arr[i] = fgetc(fp);
			if (arr[i] == ' ' || arr[i] == '.')
			{
				reverse(arr, j, i - 1);
				j = i + 1;
			}
			

			i++;
		}

		arr[i] = '\0';

		printf("%s\n", arr);
		fclose(fp);
	}

	
	
	
	

}
