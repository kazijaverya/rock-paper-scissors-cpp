#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// Function to get the computer's choice
string getComputerChoice()
{
    int randomNumber = rand() % 3; // 0 for Rock, 1 for Paper, 2 for Scissors
    if (randomNumber == 0)
        {
        return "rock";
    }
    else if (randomNumber == 1)
    {
        return "paper";
    }
     else
    {
        return "scissors";
    }
}

// Function to determine the winner
string determineWinner(const string& playerChoice, const string& computerChoice)
{
    cout << "You chose: " << playerChoice << endl;
    cout << "Computer chose: " << computerChoice <<endl;

    if (playerChoice == computerChoice)
        {
        return "It's a tie!";
    }
    else if ((playerChoice == "rock" && computerChoice == "scissors") ||
               (playerChoice == "paper" && computerChoice == "rock") ||
               (playerChoice == "scissors" && computerChoice == "paper"))
               {
        return "You win!";
    }
     else
        {
        return "Computer wins!";
    }
}

int main()
{
    // Seed the random number generator
    srand(time(0));

    string playerChoice;
    int rounds = 0;
    int playerWins = 0;
    int computerWins = 0;
    int ties = 0;

    cout << "Welcome to Rock Paper Scissors!" << endl;

    while (true)
        {
        cout << "\nRound " << rounds + 1 << endl;
        cout << "Choose your move (rock, paper, scissors, or quit): ";
        cin >> playerChoice;

        // Convert player's choice to lowercase for case-insensitive comparison
        for (char &c : playerChoice)
            {
            c = tolower(c);
        }

        if
            (playerChoice == "quit")
            {
            break;
        }

        if
        (playerChoice != "rock" && playerChoice != "paper" && playerChoice != "scissors")
            {
            cout << "Invalid choice. Please enter rock, paper, or scissors." << endl;
            continue;
        }

        string computerChoice = getComputerChoice();
        string result = determineWinner(playerChoice, computerChoice);
        cout << result << std::endl;

        rounds++;
        if
            (result == "You win!")
            {
            playerWins++;
        }
        else if
        (result == "Computer wins!")
            {
            computerWins++;
        }
        else
            {
            ties++;
        }
    }

    cout << "\n--- Game Over ---" << endl;
    cout << "Total Rounds: " << rounds << endl;
    cout << "Your Wins: " << playerWins << endl;
    cout << "Computer Wins: " << computerWins << endl;
    cout << "Ties: " << ties << endl;

    if (playerWins > computerWins)
        {
        cout << "Congratulations, you won the game!" << endl;
    }
    else if (computerWins > playerWins)
    {
        cout << "The computer won the game!" << endl;
    }
    else
    {
        cout << "The game ended in a tie!" << endl;
    }

    return 0;
}
