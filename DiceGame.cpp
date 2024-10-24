#include <iostream>
#include <ctime>

using namespace std;

void printRules() {
    cout << "+- RULES------------------------------+" << endl;
    cout << "|  Sides per die                  6   |" << endl;
    cout << "|  starting $                   100   |" << endl;
    cout << "|  maximum $                    200   |" << endl;
    cout << "|  maximum rolls               1000   |" << endl;
    cout << "|  random seed                 1234   |" << endl;
    cout << "+-------------------------------------+" << endl;
}

int rollDie() { // Function to roll a die
    const int NUM_SIDES = 6;
    return rand() % NUM_SIDES + 1;
}

void printHeader(int roll_num, int playerAmount) {
    // Print the round number and player's current money
    cout << "Roll #" << roll_num << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Player's Money: $" << playerAmount << endl;
}

bool gameOver(int playerAmount, int roll_num, const int WIN_AMT, const int LOSE_AMT, const int ROLL_LIMIT) {
    return playerAmount <= LOSE_AMT || playerAmount >= WIN_AMT || roll_num > ROLL_LIMIT;
}

void printFinalMessage(int playerAmount, const int WIN_AMT, const int LOSE_AMT, int roll_num, const int ROLL_LIMIT) {
    if (playerAmount <= LOSE_AMT) {
        cout << " ------- I'm Sorry, You Lost! -------" << endl;
    } else if (playerAmount >= WIN_AMT) {
        cout << "+++++ You Won! Congratulations +++++" << endl;
    } else if (roll_num > ROLL_LIMIT) {
        cout << "------Sorry---No Rolls Left---------" << endl;
    }
    cout << "\n";
}

int roll_n_print_Dice(int NUM_SIDES) {
    int init_roll = rollDie();
    cout << "  Die roll: " << init_roll << endl;

    int step3_sum = 0;
    cout << "  Dice rolls: ";
    for (int i = 0; i < init_roll; ++i) {
        int small_roll = rollDie();
        cout << small_roll << " ";
        step3_sum += small_roll;
    }
    cout << endl;
    return step3_sum;
}

int get_n_print_Result(int step3_sum, int& playerAmount) {
    cout << "  Sum: " << step3_sum << endl;

    if (step3_sum % 2 == 0) {
        cout << "  Result: Lost $" << step3_sum << endl;
        playerAmount -= step3_sum;
    } else {
        cout << "  Result: Gained $" << step3_sum << endl;
        playerAmount += step3_sum;
    }

    return playerAmount;
}

void playGame() {
    // Player starts with $100
    int playerAmount = 100;

    // Game constants
    const int WIN_AMT = 200;
    const int LOSE_AMT = 0;
    const int NUM_SIDES = 6;
    const int ROLL_LIMIT = 1000;

    int roll_num = 1;

    // Print game rules
    printRules();

    // Game loop
    while (!gameOver(playerAmount, roll_num, WIN_AMT, LOSE_AMT, ROLL_LIMIT)) {
        printHeader(roll_num, playerAmount);

        int step3_sum = roll_n_print_Dice(NUM_SIDES);

        get_n_print_Result(step3_sum, playerAmount);

        roll_num++;
    }

    // Final message
    printFinalMessage(playerAmount, WIN_AMT, LOSE_AMT, roll_num, ROLL_LIMIT);
}

int main() {
    srand(1234);  // Fixed seed for repeatable results
    playGame();
    return 0;
}
