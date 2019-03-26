// name: castle.cpp
// author: Amrzs
// date: 2014/03/29
 
#include <iostream>
#include <string>
#include <vector>
 
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
    cout << "The castle gone!" << endl;
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
        if(!nowRoom->existExit(exitName)){
            cout << "There isn't a exit named "
                << exitName << "." << endl;
            continue;
        }
 
        Room *newRoom = nowRoom->goExit(exitName);
        if(!newRoom){
            cout << "Please enter a new room name: ";
            cin >> roomName;
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
 