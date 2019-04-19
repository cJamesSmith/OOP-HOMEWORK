/*  Author: Chen Xianwei
 *  Zhejiang University
 *  Date:2019-04-08 10:46:18
 *  Version:1.0
 *  Description:

 */

#ifndef __DIARY_H
#define __DIARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <io.h>

void create_new_file(std::string diary_name);
void add_new_diary(std::string diary_name, std::string date);
void list_all_date(std::string diary_name);
void delete_date(std::string diary_name, std::string date);
void print_date(std::string diary_name, std::string date);
void print_all(std::string diary_name);

#endif