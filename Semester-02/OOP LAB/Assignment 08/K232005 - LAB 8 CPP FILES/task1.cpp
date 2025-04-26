#include <iostream>
using namespace std;

class Player {
    public:
        string username;
        int level;
        int expPoints;
        string weapon;
        string accuracy;
        int healing;

        void create (string UN, int lvl, int points, string wep) {
            username = UN;
            level = lvl;
            expPoints = points;
            weapon = wep;
        }
        void create (string UN, int lvl, int points, string wep, string acc) {
            username = UN;
            level = lvl;
            expPoints = points;
            weapon = wep;
            accuracy = acc;
        }
        void create (string UN, int lvl, int points, string wep, int heal) {
            username = UN;
            level = lvl;
            expPoints = points;
            weapon = wep;
            healing = heal;
        }
        
        void display (string a) {
            cout<<"----------------------------------------" << endl;
            cout<<"\tDisplaying Details of Infantary Player" << endl;
            cout<< "User name: " << username << endl;
            cout<< "Level: " << level << endl;
            cout<< "Experience Points: " << expPoints << endl;
            cout<< "Weapon: " << weapon << endl;
        }

        void display (int a) {
            cout<<"----------------------------------------" << endl;
            cout<<"\tDisplaying Details of Sniper Player" << endl;
            cout<< "User name: " << username << endl;
            cout<< "Level: " << level << endl;
            cout<< "Experience Points: " << expPoints << endl;
            cout<< "Weapon: " << weapon << endl;
            cout<< "Accuracy: " << accuracy << endl;

        }

        void display (char a) {
            cout<<"----------------------------------------" << endl;
            cout<<"\tDisplaying Details of Medic Player" << endl;
            cout<< "User name: " << username << endl;
            cout<< "Level: " << level << endl;
            cout<< "Experience Points: " << expPoints << endl;
            cout<< "Weapon: " << weapon << endl;
            cout<< "Healing Profeciency: " << healing << endl;
        }
};

int main () {
    
    Player infantry, sniper, medic;
    
    infantry.create("Hammad", 5, 10, "Deagle");
    sniper.create("Sami", 6, 11, "Sniper", "Medium");
    medic.create("Faiq", 7, 12, "Loadout", 50);

    infantry.display("a");
    sniper.display(1);
    medic.display('a');

}