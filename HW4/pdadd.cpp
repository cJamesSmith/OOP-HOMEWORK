#include "diary.h"

#define DIARY_NAME "diary.txt"

int main(int argc, char const *argv[])
{
    create_new_file(DIARY_NAME);
	if (argc > 1)
	{
        delete_date(DIARY_NAME, argv[1]);
	   add_new_diary(DIARY_NAME, argv[1]);
	}
    else
    {
		std::cout << "pdadd FUNCTION:\n\
add a new diary record in DIARY_NAME\n\
\nUSEAGE:\n\
pdadd DATE\n\
DATE is supposed to be in the style as 20190409\n\n\
AN EXAMPLE OF pdadd USE IS LIKE:\n\
pdadd 20190409\n\n\
ATTENTION: each new diary is supposed to end with a line \n\
with single '.' or EOF(Ctrl-D in Unix and Ctrl-Z in Windows)\n\n\
All of the diaries are saved in the file DIARY_NAME";
    }

	return 0;
}
