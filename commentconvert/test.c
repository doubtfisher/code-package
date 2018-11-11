#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "CommentConvert.h"


void test()
{
	FILE* pfRead = NULL;
	FILE* pfWrite = NULL;
	pfRead = fopen("input.c", "r");
	if (pfRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}

	pfWrite = fopen("output.c", "w");
	if (pfWrite == NULL)
	{
		perror("open file for write");
		fclose(pfRead);
		pfRead = NULL;
		exit(EXIT_FAILURE);
	}
	//ע��ת��
	CommentConvert(pfRead, pfWrite);
	printf("ת�����\n");
	fclose(pfRead);
	fclose(pfWrite);
	pfRead = NULL;
	pfWrite = NULL;
}

int main()
{
	test();
	system("pause");
	return 0;
}
