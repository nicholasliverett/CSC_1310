/*
	Title:  driver.cpp
	Author:  Nicholas Liverett
	Date:  1/30/25
	Purpose:  *sigh* fortnite loadout driver file
*/

#include "loadout.h"

int main ()
{
	//Create a pointer to an array of loadout pointers called myLoadouts here
	loadout** myLoadouts;

	
	int numLoadouts, numWeapons;
	string name, location;
	int numHealingItems;
	
	cout << "\nHow many loadouts are you planning this season?\n";
	cin >> numLoadouts;
	cin.ignore();
	
	//Dynamically allocate a new array of pointers (of type Loadouts) using numLoadouts and assign this array to myLoadouts
	myLoadouts = new loadout* [numLoadouts];
	
	for (int i=0; i< numLoadouts; i++)
	{
		cout << "\nLOADOUT NAME:\t\t";
		getline(cin, name);
		cout << "\nLOADOUT LOCATION:\t";
		getline(cin, location);
		cout << "\nNUMBER OF HEALING ITEMS:\t\t";
		cin >> numHealingItems;
		cout << "\nNUMBER OF WEAPONS?\t";
		cin >> numWeapons;
		cin.ignore();
		
		//Call the createLoadout function and make sure to assign the returned value to myLoadouts[i]
		myLoadouts[i] = createLoadout(name, location, numWeapons, numHealingItems);
		
		for(int x=0; x<numWeapons; x++)
		{
			cout << "\nWEAPON " << x+1 << ":\t\t";
			//Read in the string from the user and put in the correct array element of the weapon array
			getline(cin, myLoadouts[i]->weapons[x]);
		}
		cout << "\n*******************************\n";
	}
	
	cout << "\n\nThe following are the loadouts you entered:\n\n";
	for(int i=0; i<numLoadouts; i++)
	{
		cout << "******************************* LOADOUT " << (i+1) << "*******************************\n";
		printLoadout(myLoadouts[i]);
	}
	
	for(int i=0;  i< numLoadouts; i++)
	{
		destroyLoadout(myLoadouts[i]);
	}
	delete [] myLoadouts;
	
	cout << endl << endl;
	return 0;
}
