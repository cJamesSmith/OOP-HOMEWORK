#include "diary.h"
#include <unistd.h>

void print_all(std::string diary_name)
{
	std::fstream fp;
	fp.open(diary_name.c_str(), std::ios::in);
	std::string line_buff;
	std::getline(fp, line_buff);
	while (!fp.eof())
	{
		std::cout << line_buff << std::endl;
		std::getline(fp, line_buff);
	}
	fp.close();
}


//DONE
void create_new_file(std::string diary_name)
{
	std::fstream fp;
	if (access(diary_name.c_str(), 0) == -1)
	{
		fp.open(diary_name.c_str(), std::ios::out);
		fp << std::endl;
		fp.close();
	}
}

//TODO
void add_new_diary(std::string diary_name, std::string date)
{
	std::fstream fp;
	std::fstream fp_tmp;
	fp.open(diary_name.c_str(), std::ios::in);
	fp_tmp.open((diary_name + "temp").c_str(), std::ios::out);
	std::string line_buff;
	std::getline(fp, line_buff);
	while (!fp.eof())
	{
		while ((line_buff.substr(0, 2) == "$$") && line_buff.substr(3, line_buff.length() - 3) < date)
		{
			fp_tmp << line_buff << std::endl;
			while ((line_buff != "."))
			{
				std::getline(fp, line_buff);
				fp_tmp << line_buff << std::endl;
			}
			std::getline(fp, line_buff);
		}
		std::string new_diary = "";
		fp_tmp << "$$ " << date << std::endl;
		while (std::getline(std::cin, new_diary) && new_diary != ".")
		{
			fp_tmp << new_diary << std::endl;
		}
		fp_tmp << "." << std::endl;
		while (!fp.eof())
		{
			fp_tmp << line_buff << std::endl;
			std::getline(fp, line_buff);
		}
	}
	fp.close();
	fp_tmp.close();
	remove(diary_name.c_str());
	rename((diary_name + "temp").c_str(), diary_name.c_str());
}

//DONE
void list_all_date(std::string diary_name)
{
	std::fstream fp;
	fp.open(diary_name.c_str(), std::ios::in);
	std::string line_buff;
	std::getline(fp, line_buff);
	while (!fp.eof())
	{
		if (line_buff.substr(0, 2) == "$$")
		{
			std::cout << line_buff.substr(3, line_buff.length()-3) << std::endl;
		}
		std::getline(fp, line_buff);
	}
	fp.close();
}

//DONE
void delete_date(std::string diary_name, std::string date)
{
	std::fstream fp;
	std::fstream fp_tmp;
	fp.open(diary_name.c_str(), std::ios::in);
	fp_tmp.open((diary_name + "temp").c_str(), std::ios::out);
	std::string line_buff;
	std::getline(fp, line_buff);
	while (!fp.eof())
	{
		if ((line_buff.substr(0, 2) == "$$") && line_buff.substr(3, line_buff.length() - 3) != date)
		{
			fp_tmp << line_buff << std::endl;
			while ((line_buff != "."))
			{
				std::getline(fp, line_buff);
				fp_tmp << line_buff << std::endl;
			}
		}
		std::getline(fp, line_buff);
	}
	fp_tmp << std::endl;
	fp.close();
	fp_tmp.close();
	remove(diary_name.c_str());
	rename((diary_name + "temp").c_str(), diary_name.c_str());
}


//DONE
void print_date(std::string diary_name, std::string date)
{
	std::fstream fp;
	fp.open(diary_name.c_str(), std::ios::in);
	std::string line_buff;
	std::getline(fp, line_buff);
	while (!fp.eof())
	{
		if ((line_buff.substr(0, 2) == "$$") && line_buff.substr(3, line_buff.length() - 3) == date)
		{
			while ((line_buff[line_buff.length() - 1] != '.'))
			{
				std::cout << line_buff << std::endl;
				std::getline(fp, line_buff);
			}
			std::cout << line_buff << std::endl;
			break;
		}
		std::getline(fp, line_buff);
	}
	fp.close();
}