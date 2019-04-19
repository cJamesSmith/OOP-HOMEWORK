/*  Author: Chen Xianwei
 *  Zhejiang University
 *  Date:2019-04-08 10:46:18
 *  Version:1.0
 *  Description:

 */

#include "diary.h"

#define DIARY_NAME "diary.txt"

int main(int argc, char *argv[])
{
	switch (argc)
	{
	case 1:
		break;
	case 2:
		print_date(DIARY_NAME, argv[1]);
		break;
	default:
		long int start, end;
		sscanf(argv[1], "%ld", &start);
		sscanf(argv[2], "%ld", &end);
		char date[8];
		for (long int i = start; i <= end; i++)
		{
			sprintf(date, "%ld", i);
			print_date(DIARY_NAME, date);
		}
	}
	return 0;
}