#include <iostream>
using namespace std;

int main () {

    int dept = 4;
    int courses[4]; // for 4 depts
    float **gpas = new float*[dept];

    // Dept 01 = SE -- Dept 02 = AI -- Dept 03 = CS -- Dept 04 = DS
    cout<<"Dept 01 = SE || Dept 02 = AI || Dept 03 = CS || Dept 04 = DS" << endl;
    for (int i=0; i<dept; i++) {
        cout<<"Enter number of courses for Department " << i+1 << ": ";
        cin>>courses[i];
        gpas[i] = new float[courses[i]];
    }

    cout<<endl;
    // storing gpa
    cout<<"Dept 01 = SE || Dept 02 = AI || Dept 03 = CS || Dept 04 = DS" << endl;
    for (int i=0; i<dept; i++) {
        for (int j=0; j<courses[i]; j++) {
            cout<<"Enter GPA for Department " << i+1 << " & Course " << j+1 <<": ";
            cin>>gpas[i][j];
        }
        cout<<endl;
    }

    // displaying
    for (int i=0; i<dept; i++) {
        for (int j=0; j<courses[i]; j++) {
            cout<<"Department " << i+1 << " & Course " << j+1 <<" GPA is: " << gpas[i][j] << endl;
        }
        cout<<endl;
    }





    return 0;
}