/*
	Title:  loadout.cpp
	Author:  Nicholas Liverett
	Date:  1/30/25
	Purpose:  *sigh* fortnite loadout function file
*/

#include "loadout.h"

/**
 * @brief Dynamically create loadout and string array of weapons in loadout
 * 
 * @param name loadout name
 * @param location loadout location
 * @param num_weapons number of weapons in loadout, used to 
 * 		dynamically create a string array containing weapons
 * @param heals num of heals in loadout
 * 
 * @return pointer to created loadout
 */

loadout* createLoadout(string name, string location, int num_weapons, int heals) {
	loadout* newloadout = new loadout;
	string* weapons = new string [num_weapons];
	newloadout->name = name;
	newloadout->location = location;
	newloadout->weapons = weapons;
	newloadout->num_weapons = num_weapons;
	newloadout->heal_items = heals;
	return newloadout;
}

/**
 * @brief Print all data in myloadout
 * 
 * @param myloadout the loadout to be printed
 * 
 */
void printLoadout(loadout* myloadout) {
	cout << "\nMy Loadout: " << myloadout->name;
	cout << "\nLocation: " << myloadout->location;
	cout << "\nNum of Weapons: " << myloadout->num_weapons;
	cout << "\nWeapons:";
	for (int i=0;i<myloadout->num_weapons;i++) {
		cout << "\n\t" << i+1 << ". " << myloadout->weapons[i];
	}
	cout << "\nHeals: " << myloadout->heal_items << endl;
}

/**
 * @brief destroy dynamically allocated loadout
 * 
 * @param myloadout loadout to be deleted
 * 
 */
void destroyLoadout(loadout* myloadout) {
	delete [] myloadout->weapons;
	delete [] myloadout;
}