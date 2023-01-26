

#include <iostream>
#include <iomanip>
#include <random>


using namespace std;



int main()
{
    // Set x, y coordinates of dice
    const int diceArtX1 = 50 - 10;
    const int diceArtY1 = 25 - 3;

    // Set dimentions of print area
    const int printRows = 50;
    const int printColumns = 100;

    // Message
    const string message = "Nothing happens by chance";
    const int messageX1 = 50 - message.length() / 2 - 1;
    const int messageY1 = 11;

    // Calcuate message vars
    int messageX2 = messageX1 + message.length();
    int messageY2 = messageY1 + 2;

    // Dice ASCII art. Source: https://www.asciiart.eu/miscellaneous/dice
    string diceArt[6] = {

        "  ____",
        " /\\' .\\    _____",
        "/: \\___\\  / .  /\\",
        "\\' / . / /____/..\\",
        " \\/___/  \\'  '\\  /",
        "          \\'__'\\/" };

    // Get length of dice ASCII art
    int diceArtLen = sizeof(diceArt) / sizeof(diceArt[0]);

    // Initialize random number generator
    random_device rdevice{};
    default_random_engine num{ rdevice() };
    uniform_int_distribution<int> randomNum{ 1, 6 };

    cout << diceArt << endl;

    for (int y = 0; y < printRows; y++) {
        for (int x = 0; x < printColumns; x++)
        {

            // Message text
            if (y >= messageY1 - 1 && y < messageY2 && x >= messageX1-2 && x < messageX2+2) {
                if (y == messageY1 && x >= messageX1 && x < messageX2) {
                    cout << message[x - messageX1];
                }
                else {
                    cout << " ";
                }
                continue;
            }

            // If row is within range of dice...
            if (y >= diceArtY1 && y < diceArtY1 + diceArtLen) {
                string line = diceArt[y - diceArtY1];
                int lineLen = line.length();
                // If column is within range of dice...
                if (x >= diceArtX1 && x < diceArtX1 + lineLen ) {
                    // Print single character of dice ASCII art
                    cout << line[x - diceArtX1];
                    continue;
                }
            }
            
            // Calculate the distance between the dice center and (x, y)
            double chX = (double)(x - diceArtX1 - 9);
            double chY = (double)(y - diceArtY1 - 3)*2;
            double distFromCenter = sqrt(chX * chX + chY * chY);

            // If the distance if between 17 and 21, skip
            if (distFromCenter > 17 && distFromCenter <= 21) {
                cout << " ";
                continue;
            }

            // On odd rows, skip even columns. On even rows, skip odd columns.
            if (x % 2 != y % 2) {
                cout << " ";
                continue;

            } // Make checkboard pattern
            int diceRoll = randomNum(num);
            switch (diceRoll) {
            case 1:
                cout << "\u001b[31m"; // Red
                break;
            case 2:
                cout << "\u001b[32m"; // Green
                break;
            case 3:
                cout << "\u001b[33m"; // Yellow
                break;
            case 4:
                cout << "\u001b[34m"; // Blue
                break;
            case 5:
                cout << "\u001b[35m"; // Purple
                break;
            case 6:
                cout << "\u001b[36m"; // Light blue
                break;
            }
            cout << diceRoll << "\u001b[0m";
        }
        cout << endl;
    }

    return 0;
}
