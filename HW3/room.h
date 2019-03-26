// name: room.h
// author: Amrzs
// date: 2014/03/29
 
#ifndef ROOM_H
#define ROOM_H
 
#include <string>
#include <map>
 
using namespace std;
 
class Room {
 
public:
    Room(string name, vector<string> exitNames, bool safe = false); 
    ~Room();
 
private:
    string name;
    map<string, Room*> exitMap; 
    bool princess, monster;
    
public:
    bool hasPrincess();
    bool hasMonster();
    bool existExit(string exitName);
    Room *goExit(string exitName);
    void printInfo();
    
    void setExit(string exitName, Room*);
};
 
#endif //ROOM_H