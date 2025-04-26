#include <iostream>
#include <vector>
using namespace std;

/*
            Player
         /    |    \
    Weapon   Char   Enemy

*/

class Player {
    protected:
        int playerID;
        string playerName;
        int health;

    public:
        Player () {
            playerID = 0;
            health = 100;
            playerName = "Default player name";
        }

        Player (int id, string name) {
            playerID = id;
            playerName = name;
        }

        void setPlayerName (string newPlayerName) {
            playerName = newPlayerName;
        }

        string getPlayerName () {
            return playerName;
        }

        void setPlayerID (int newPlayerID) {
            playerID = newPlayerID;
        }

        int getPlayerID () {
            return playerID;
        }

        void deductHealth (int dmgReceived) {
            health -= dmgReceived;
        }

        void setHealth (int newHealth) {
            health = newHealth;
        }
        
        int getHealth () {
            return health;
        }
};

// class Weapon;
// class Character;
// class Enemy;

class Weapon : public Player {
    protected:
        vector <string> weaponList;
        string selectedWeapon;

    public:
        vector <string> getWeaponList () {
            return weaponList; 
        }

        friend vector <string> getWeaponList ();
        
        Weapon () {
            weaponList = {"Knife", "Deagle", "MP5", "M4", "Sniper"};
        }

        void addWeapon () {
            int n;
            string weaponToAdd;

            cout<<"Enter the number of weapons to add to the list: ";
            cin >> n;

            for (int i=0;  i<n; i++) {
                cout<<"Enter weapon " << i+1 << " : ";
                cin>> weaponToAdd;
                weaponList.push_back(weaponToAdd);
            }
        }
        
        void displayWeapons () {
            for (int i=0; i<weaponList.size(); i++) {
                cout<<"Weapon " << i+1 << ": " << weaponList[i] << endl;
            }
        }

        //friend void displayWeapons (Character &C);

        vector <string> useWeapon () {
            int choice;

            displayWeapons();
            cout<<"Select a weapon from the available list: ";
            cin>>choice;

            selectedWeapon = weaponList[choice-1];
        }
};

class Enemy;

class Character : public Player {
    protected:
        int level;
        string experience;
        int points;
        string weaponChar;
        
    public:
        Enemy* enemy;
        Weapon wep;

        Character () {}

        Character (int id, string name) : Player (id, name) {
            level = 0;
            points = 0;
            experience = "Beginner";
        }

        friend void attack();
        // friend void attack(Character &C, Enemy &E);
        // void setLevel(int newLevel);
        // void setPoints (int newPoints);
        // int getPoints ();
        void levelUp ();
        void playGame ();

        void setLevel(int newLevel) {
            level = newLevel;
        }

        void setPoints (int newPoints) {
            points = newPoints;
        }

        int getPoints () {
            return points;
        }
};

class Enemy : public Player {
    protected:
        int damage;
        string weaponEnemy;
        Character charac;
        Weapon wep;

    public:
        Enemy () {
            damage = 5; // assuming a default dmg
        }
        Enemy (int d) {
            if (d>=1 && d<=10) {
                damage = d;
            }
            else {
                cout<<"Damage is not in the given range (1-10), hence will not be initilized." << endl;
            }
        }

        //friend void attack(Character &C, Enemy &E);
        friend void attack();

        void attack () {
            int choice;
            string startKey;
            vector <string> weapons = wep.getWeaponList();

            cout<<"Available Weapons for Enemy: " << endl;
            wep.displayWeapons();
            cout<<"Which weapon does the enemy want to choose? ";
            cin>> choice;

            if (choice>(weapons.size()-1)) {
                cout<<"Invalid weapon choice. Try again." << endl;
                attack();
            }
            else {
                weaponEnemy = weapons[choice-1];
                cout<<"You have chosen" << weaponEnemy << " to attack the character." << endl;
                cout<<"Press any key to attack the character." << endl;
                cin>> startKey;
                cout<<"The character has lost " << damage << " health." << endl;
                charac.deductHealth(damage);
            }
        }

        
};

// vector <string> getWeaponList () {
//     Weapon W;
//     W.getWeaponList();
// }

// void displayWeapons(Character& C) {
//     Weapon W;
//     W.displayWeapons();
// }

void Character::levelUp () {
    if (points>=10) {
        level++;

        if (experience=="Beginner") {
            cout<<"You have leveled upto Intermediate from Beginner level." << endl;
            experience="Intermediate";
        }
        else if (experience=="Intermediate") {
            cout<<"You have leveled upto Advanced from Intermediate level." << endl;
            experience="Advanced";
        }
         else if (experience=="Advanced") {
            cout<<"You have leveled upto Expert from Advanced level." << endl;
            experience="Expert";
        }
         else {}
    }
}

void Character::playGame () {
    int choice;
    string startKey;
    vector <string> weapons = wep.getWeaponList();
    //vector <string> weapons;

    cout<<"Available weapons: " << endl;
    wep.displayWeapons();
    cout<< "Select a weapon to attack the enemy: ";
    cin>> choice;

    //weapons = getWeaponList();
    // weaponChar = weapons[choice-1]
    if (choice>(weapons.size()-1)) {
        cout<<"Invalid weapon choice. Try again." << endl;
        playGame();
    }
    else {
        weaponChar = weapons[choice-1];
        cout<<"You have chosen " << weaponChar << " to fight against the enemy." << endl;
        cout<<"Press any key to attack the enemy: " << endl;
        cin>> startKey;
        cout<<"You have received 10 points for damaging the enemy." << endl;
        points += 10;
        levelUp();
        enemy->deductHealth(5);
     }
}

void attack(Character &C, Enemy &E) {
    E.attack();
}

int main() {

    cout<<"*************************" << endl;
    cout<<"* Name: Muhammad Hammad *" << endl;
    cout<<"* Roll Number: 23K-2005 *" << endl;
    cout<<"*************************" << endl << endl;


    Character C(11, "Hammad");
    Enemy E(5); // sending 5 because mentioned in the question

    cout<<"----------------------------------------------------" << endl;
    cout<<"\t Adding Weapon" << endl;
    C.wep.addWeapon();

    cout<< endl <<"-----------------------------------------" << endl;
    cout<<"\t Starting The Game" << endl;
    C.playGame();

    cout<< endl <<"-----------------------------------------" << endl;
    cout<<"\t Enemy Attacks The Character" << endl;
    attack(C, E);

    cout<< endl <<"-----------------------------------------" << endl;
    cout<<"\t Character Fights Back" << endl;
    C.playGame();
    C.playGame();

    return 0;
}