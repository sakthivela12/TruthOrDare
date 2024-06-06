#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // For sleep function
#include <vector>
#include <string>

using namespace std;

// Function to select a random truth question
string selectRandomTruth() {
    vector<string> truths = {
        "What is your biggest fear?",
        "Have you ever cheated on a test?",
        "What is your most embarrassing moment?",
        "What is your guilty pleasure?",
        "What is your weirdest habit?",
        "What is something you've never told anyone?",
        "What is the last lie you told?",
        "What is your most irrational fear?",
        "What is the craziest thing you've ever done?",
        "What is your most embarrassing nickname?",
    };
    srand(time(nullptr));
    return truths[rand() % truths.size()];
}

// Function to select a random dare
string selectRandomDare() {
    vector<string> dares = {
        "Sing a song out loud.",
        "Do 10 pushups.",
        "Text someone you haven't talked to in a year.",
        "Eat a spoonful of hot sauce.",
        "Dance for 30 seconds.",
        "Speak in an accent for the next round.",
        "Do your best impression of a celebrity.",
        "Send a funny meme to the fifth person in your contacts.",
        "Wear socks on your hands for the next 3 rounds.",
        "Do a handstand against the wall for 10 seconds.",
    };
    srand(time(nullptr));
    return dares[rand() % dares.size()];
}

// Function to simulate spinning animation
void spinAnimation() {
    cout << "Spinning..." << flush;
    for (int i = 0; i < 10; ++i) {
        cout << "." << flush;
        usleep(200000); // Sleep for 0.2 seconds
    }
    cout << endl;
}

int main() {
    cout << "Welcome to Multiplayer Truth or Dare! Get ready for some fun challenges!" << endl;

    vector<string> players;
    for (int i = 0; i < 4; ++i) {
        string name;
        cout << "Enter name of Player " << i + 1 << ": ";
        cin >> name;
        players.push_back(name);
    }

    while (true) {
        // Simulate spinning animation
        spinAnimation();

        // Randomly select a player
        int index = rand() % players.size();
        string selectedPlayer = players[index];
        cout << "Selected player: " << selectedPlayer << endl;

        // Randomly select truth or dare
        int choice = rand() % 2; // 0 for truth, 1 for dare

        if (choice == 0) {
            // Truth
            cout << "Truth: " << selectRandomTruth() << endl;
        } else {
            // Dare
            cout << "Dare: " << selectRandomDare() << endl;
        }

        // Ask if the players want to continue
        char response;
        cout << "Do you want to continue playing? (y/n): ";
        cin >> response;
        if (response != 'y' && response != 'Y') {
            cout << "Thanks for playing Multiplayer Truth or Dare! Have fun!" << endl;
            break;
        }
    }

    return 0;
}
