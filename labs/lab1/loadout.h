/*
   Title:  loadout.h
	Author:  Nicholas Liverett
	Date:  1/30/25
	Purpose:  *sigh* fortnite loadout header file
*/

#ifndef LOADOUT_H
#define LOADOUT_H

#include <iostream>
#include <string>

using namespace std;

// Structure declaration
struct loadout{
   string name;
   string location;
   string* weapons;
   int num_weapons;
   int heal_items;
};

//func declaration
loadout* createLoadout(string,string,int,int);
void printLoadout(loadout*);
void destroyLoadout(loadout*);

#endif