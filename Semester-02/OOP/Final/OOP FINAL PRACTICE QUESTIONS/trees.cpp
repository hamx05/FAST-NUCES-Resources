#include <iostream>
using namespace std;

class Plants {
    public:
        virtual void water() = 0;
        virtual void changeSoil() = 0;
};

class Rose : public Plants {
    private:
        bool isWateredRecently;
        int moistureLevel; // 0 se 10
        int soilLevel;
    
    public:
        Rose (bool isWateredRecently, int moistureLevel, int soilLevel) {
            this->isWateredRecently = isWateredRecently;
            this->moistureLevel = moistureLevel;
            this->soilLevel = soilLevel;
        }

        void water () {
            if ((moistureLevel>=0 && moistureLevel<10) || !isWateredRecently) {
                cout<<"The rose plant has been watered." << endl;
                isWateredRecently = true;
                moistureLevel++;
            }
            else {
                cout<<"The rose plant is already moisturized, thus does not require any watering." << endl;
            }
        }

        void changeSoil () {
            if (soilLevel<5) {
                cout<<"The soil has been changed and soil level is now maintained to 10." << endl;
                soilLevel = 10;
            }
            else {
                cout<<"There is sufficient soil right now, thus does not need to be changed." << endl;
            }
        }
};

class LemonPlant : public Plants {
    private:
        bool isWateredRecently;
        int moistureLevel; // 0 se 10
        int soilLevel; // 0 se 10
    
    public:
        LemonPlant (bool isWateredRecently, int moistureLevel, int soilLevel) {
            this->isWateredRecently = isWateredRecently;
            this->moistureLevel = moistureLevel;
            this->soilLevel = soilLevel;
        }

        void water () {
            if ((moistureLevel>=0 && moistureLevel<10) || !isWateredRecently) {
                cout<<"The lemon plant has been watered." << endl;
                isWateredRecently = true;
                moistureLevel++;
            }
            else {
                cout<<"The plant is already moisturized, thus does not require any watering." << endl;
            }
        }

        void changeSoil () {
            if (soilLevel<3) {
                cout<<"The soil has been changed and soil level is now maintained to 10." << endl;
                soilLevel = 10;
            }
            else {
                cout<<"There is sufficient soil right now, thus does not need to be changed." << endl;
            }
        }
};

class Tree {
    public:
        virtual void water() = 0;
        virtual void trim() = 0;
        virtual void checkFruits() = 0;
};

class CoconutTree : public Tree {
    private:
        bool isWateredRecently;
        int moistureLevel; // 0 se 10
        int length; // 1 se 15
        int totalCoconuts; // 0 or more
    
    public:
        CoconutTree (bool isWateredRecently, int moistureLevel, int length, int totalCoconuts) {
            this->isWateredRecently = isWateredRecently;
            this->moistureLevel = moistureLevel;
            this->length = length;
            this->totalCoconuts = totalCoconuts;
        }
        void water () {
            if ((moistureLevel>=0 && moistureLevel<10) || !isWateredRecently) {
                cout<<"The coconut tree has been watered and its moisture level is increased by 1." << endl;
                moistureLevel++;
                isWateredRecently = true;
            }
            else {
                cout<<"The coconut tree is already moisturized, thus does not require any watering." << endl;
            }
        }

        void trim () {
            if (length>30) {
                cout<<"The coconut tree has been trimmed down to 30 meters." << endl;   
                length = 30;
            }
            else {
                cout<<"The coconut tree is not greater than 30 meters, thus does not require any trimming." << endl;
            }
        }

        void checkFruits () {
            cout<<"The coconut tree has " << totalCoconuts << " coconuts." << endl;
        }
};

class MangoTree : public Tree {
    private:
        bool isWateredRecently;
        int moistureLevel; // 1 se 10
        int length; // 1 se 15
        int totalMangos; // 0 or more
    
    public:
        MangoTree (bool isWateredRecently, int moistureLevel, int length, int totalMangos) {
            this->isWateredRecently = isWateredRecently;
            this->moistureLevel = moistureLevel;
            this->length = length;
            this->totalMangos = totalMangos;
        }
        void water () {
            if ((moistureLevel>=0 && moistureLevel<10) || !isWateredRecently) {
                cout<<"The mango tree has been watered and its moisture level is increased by 1." << endl;
                moistureLevel++;
                isWateredRecently = true;
            }
            else {
                cout<<"The mango tree is already moisturized and does not require any watering." << endl;
            }
        }

        void trim () {
            if (length>15) {
                cout<<"The mango tree has been trimmed down to 15 meters." << endl;   
                length = 15;
            }
            else {
                cout<<"The mango tree is not greater than 15 meters, thus does not require any trimming." << endl;
            }
        }

        void checkFruits () {
            cout<<"The mango tree has " << totalMangos << " Mangos." << endl;
        }
};

int main() {
    
    Rose r1(false, 3, 4);
    r1.water();
    r1.changeSoil();

    cout<< endl << endl;
    LemonPlant l1(true, 5, 3);
    l1.water();
    l1.changeSoil();

    cout<< endl << endl;
    CoconutTree c1(false, 8, 40, 6);
    c1.water();
    c1.trim();
    c1.checkFruits();

    cout<< endl << endl;
    MangoTree m1(true, 10, 12, 16);
    m1.water();
    m1.trim();
    m1.checkFruits();



    return 0;
}