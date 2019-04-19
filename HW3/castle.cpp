// name: castle.cpp
// author: Xianwei C.
// date: 2019.3.30
 
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
 
#include "castle.h"
 
using namespace std;
 
Castle::Castle(){
 
    Room *room = new Room("lobby", exitNames, true);
    rooms.push_back(room);
}
 
Castle::~Castle(){
 
    while(!rooms.empty()){
        vector<Room*>::iterator it = rooms.end();
        rooms.pop_back();
        delete (*it);        
    }
}
 
vector<string> Castle::exitNames = {
    "up", "down",
    "east", "west"
};
 
 
Room *Castle::addRoom(string name){
    
    Room *room = new Room(name, exitNames);
    rooms.push_back(room);
    return room;
}
 
void Castle::printInfo(){
 
    cout << "Welcome to my castle, "
        << "enjoy your time!" << endl;
} 
 
void Castle::run(){
 
    Room *nowRoom = rooms[0];
 
    string go, exitName, roomName;
 
    while(1){ //don't like for(;;)
        nowRoom->printInfo();
        cin >> go >> exitName;
        if ('go' != go)
        {
            cout << go << " is a bad command! Please try again!" << endl;
            continue;
        }
        if(!nowRoom->existExit(exitName))
        {
            cout << "There isn't a exit named "
                << exitName << "." << endl;
            continue;
        }
 
        Room *newRoom = nowRoom->goExit(exitName);
        if(!newRoom){
            cout << "Please enter a new room name: ";
            char str[5] = "";
            srand(time(NULL));
            int i;
            for (int i = 0; i < 4; ++i)
            {
            	switch ((rand() % 2))
            	{
            		case 1:
            		str[i] = 'A' + rand() % 26;
            		break;
            		default:
            		str[i] = 'a' + rand() % 26;
            	}
            }
            str[4] = '\0';
            roomName = str;
            newRoom = addRoom(roomName);
            nowRoom->setExit(exitName, newRoom);
            newRoom->setExit(oppoExit(exitName), nowRoom);
        }
        nowRoom = newRoom;
 
        if(nowRoom->hasMonster()){
            cout << "You meet the monster and game over!" << endl;
            return; //dead
        }
 
        if(nowRoom->hasPrincess()){
            if(!princess){
                princess = true;
                cout << "You get the princess, return back quickly!" << endl;
            }
        }
 
        if(princess && nowRoom==rooms[0]){
            cout << "You win!" << endl
                << "Return back to the lobby and get the princess." << endl;
            return; //win
        }
    }
}
 
string Castle::oppoExit(string exitName){
 
    //make sure you can get the princess and return in original path
 
//    if("up" == exitName || "down" == exitName){
//        oppoExitName = ("up" == exitName) ? "down" : "up";
//    }
//    if("east" == exitName || "west" == exitName){
//        oppoExitName = ("east" == exitName) ? "west" : "east";
//    }
    
    vector<string>::iterator it;
    for(it = exitNames.begin(); it != exitNames.end(); it += 2){
        
        if((*it) == exitName)
            return *(it+1);
 
        if(*(it+1) == exitName)
            return *it;
    }
 
    cout << "No oppoExit!" << endl;
 
    return string("error"); 
}
 