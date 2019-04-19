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
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			delete_date(DIARY_NAME, argv[i]);
		}
	}
	else
	{
		std::cout << "pdremove\n\
USAGE:\n\n\
pdremove DATE1 DATE2 ...\n";
	}
	return 0;
}