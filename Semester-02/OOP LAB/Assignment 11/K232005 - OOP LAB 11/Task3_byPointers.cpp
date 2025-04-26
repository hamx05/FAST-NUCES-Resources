#include <iostream>
#include <vector>
using namespace std;

class Data {
	protected:
		int *balance;
        int N = 0;
	public:
		Data () {
			balance = NULL;
		}
		
        void push (int x){
            if(balance == NULL){
                balance = new int[1];
                balance[0] =x;
                N++;
            }else{
                int *temp = new int [N+1];
                for(int i=0; i<N;i++){
                    temp[i] = balance[i];
                } 
                temp[N] = x;
                delete []balance;
                balance = temp;
                N++;
            }

			cout << "Pushed Back: " << x << endl;
		}

        void pop(){
            if(N<1){
                cout << "Q is already empty"<<endl;
                N = 0;
                return;
            }else if (N == 1){
    			cout << "Popped: " << balance[0]<< endl;
                delete [] balance;
                balance = NULL;
                N = 0;
            }else{
                int *temp = new int[N-1];
                for(int i=0; i<N-1;i++)
                    temp[i] = balance[i+1];
			    cout << "Popped: " << balance[0]<< endl;
                
                delete[] balance;
                balance = temp;
                N--;
            }
		}

		void isEmpty(){
			if (N>=1) {
				cout<<"The vector is not empty." << endl;

			}
			cout<<"Vector is empty now." << endl;
		}

		void displayQ () {
			cout <<"Q: " ;
			for (int i=0; i<N; i++) {
				cout << balance[i] << " ";
			}
            cout << endl;
		}

};

int main () {
	
	Data d;

	d.push(500);
    d.pop();
	d.displayQ();
	d.push(300);
	d.displayQ();
	d.push(200);
	d.displayQ();

	return 0;
}
