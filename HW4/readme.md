INSTALL

$ make

INSTRUCTION:
BECAREFUL OF THE DATE FORMAT 20190101

pdadd
add a new diary to "diary.txt"
USAGE
pdadd 20190101
end with a single line with "." or EOF(Ctrl+Z for Windows and Ctrl+D for Unix)

pdlist
list all diary in the console
USAGE
pdlist

pdremove
delete a diary with exact date
USAGE
pdremove 20190101

pdshow
print the diary with exact date, if the start date and end date are given, print all the diaries between the start and end.
USAGE
pdshow 20190101
pdshow 20190101 20190103