#include <iostream>
using namespace std;

class Celebrity {
    protected:
        string name;
        string popLevel;
    
    public:
        Celebrity (string name, string popLevel) {
            this->name = name;
            this->popLevel = popLevel;
        }
        virtual void displayName () {}
        virtual void displayPopLevel () {}
        virtual void playAnAct () {}
        virtual void singASong () {} 
        virtual void attendEvent () {}
};

class Actor : public Celebrity {
    public:
        Actor (string name, string popLevel) : Celebrity (name, popLevel) {}

        void displayName () {
            cout<<"The name of the actor is " << name << endl;
        }
        
        void displayPopLevel () {
            cout<<"The popularity level of " << name << " is " << popLevel << endl;
        }

        void playAnAct () {
            cout<< name << " is now playing an act." << endl;
        }
};

class Singer : public Celebrity {
    public:
        Singer (string name, string popLevel) : Celebrity (name, popLevel) {}

        void displayName () {
            cout<<"The name of the actor is " << name << endl;
        }
        
        void displayPopLevel () {
            cout<<"The popularity level of " << name << " is " << popLevel << endl;
        }

        void singASong () {
            cout<< name << " is now singing a song." << endl;
        }
};

class PublicFigure : public Celebrity {
    public:
        PublicFigure (string name, string popLevel) : Celebrity (name, popLevel) {}

        void displayName () {
            cout<<"The name of the actor is " << name << endl;
        }
        
        void displayPopLevel () {
            cout<<"The popularity level of " << name << " is " << popLevel << endl;
        }

        void attendEvent () {
            cout<< name << " is now attending an event." << endl;
        }
}; 

int main() {
    
    Celebrity *c1, *c2, *c3;
    Actor a1("Cillian Murphy", "Extreme");
    Singer s1("Faiq Afaq", "Good");
    PublicFigure p1("Sami Ashfaq", "Good");

    cout<<"--------------------------------------------------" << endl;
    cout<<"\tDisplaying Functions for Actor" << endl;
    c1 = &a1;
    c1->displayName();
    c1->displayPopLevel();
    c1->playAnAct();

    cout<<endl<<"--------------------------------------------------" << endl;
    cout<<"\tDisplaying Functions for Singer" << endl;
    c2 = &s1;
    c2->displayName();
    c2->displayPopLevel();
    c2->singASong();

    cout<<endl<<"--------------------------------------------------" << endl;
    cout<<"\tDisplaying Functions for Public Figure" << endl;
    c3 = &p1;
    c3->displayName();
    c3->displayPopLevel();
    c3->attendEvent();

    return 0;
}