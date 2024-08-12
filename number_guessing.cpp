#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // seed the random number generator
    int randomnumber = rand() % 100 + 1; // generate a random number from 1 to 100
    int tries = 1;
    int guess = 0;

    cout << "Welcome to the guessing game. Please guess a number from 1 to 100!" << endl;

    while (guess != randomnumber)
    {
        cout << "Guess! ";
        cin >> guess;
        if (guess < randomnumber)
        {
            cout << "Woops - too low. Try again." << endl;
        }
        else if (guess > randomnumber)
        {
            cout << "Too high. Try again. " << endl;
        }
        tries++;
    }

    string comment;
    if (tries < 10)
    {
        comment = " - you are a superstar!";
    }
    else if (tries > 30)
    {
        comment = "Uhm.. That took you a long time.";
    }

    cout << "Great job you only took " << tries << " attempts!" << comment << endl;

    return 0;
}