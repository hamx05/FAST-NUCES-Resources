#include <iostream>
using namespace std;

class InjusticeCharacter {
    private:
        string name;
        float health;
        float powerLevel;
        string specialAbilities;

    public:
        void setData (string a, float b, float c, string d) {
            name = a;
            health = b;
            powerLevel = c;
            specialAbilities =  d;
        }

        void displayService () {
            cout<<"Name of character: " << name << endl;
            cout<<"Health of character: " << health <<" HP" << endl;
            cout<<"Power level of character: " << powerLevel << endl;
            cout<<"Speciai abilities of the character: " << specialAbilities << endl;
        }
};

int main () {
    
    InjusticeCharacter Char1;
    Char1.setData("Alien", 500, 2500, "can fly the Urran Khatola");
    Char1.displayService();
    return 0;
}