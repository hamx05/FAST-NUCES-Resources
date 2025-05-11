#include <iostream>
#include <ctime>
using namespace std;

void guessGame (int answer) {
    int guess;
    cout<<"enter ur guess: ";
    cin >> guess;

    if (guess<1 || guess >100) {
        return;
    }

    if (guess == answer) {
        cout<<"Correct answer.";
        return;
    }

    if (guess < answer) {
        cout<<"Guess is low.";
    } else {
        cout<<"Guess is high.";
    }

    guessGame(answer);

}

int main () {

    int srand(time(0));
    int answer = rand() % 101;

    guessGame(answer);

    return 0;
}

