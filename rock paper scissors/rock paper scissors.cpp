// INCLUDES //
#include <iostream>
#include <random>
#include <unordered_map>

// Function to get computers choice
std::string getComputerChoice() noexcept {
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> dist(1, 3);

    // Map representing possible choices for the computer
    std::unordered_map<int, std::string> choices = {
        {1, "Rock"},
        {2, "Paper"},
        {3, "Scissors"}
    };

    // Generate a random choice for the computer
    uint8_t randomChoice = dist(engine);
    return choices.find(randomChoice)->second;
}

// Function to print winner
void printWinner(int userChoice, const std::string& computerChoice) noexcept {
    // Map representing winning combinations
    std::unordered_map<int, std::pair<std::string, std::string>> choices = {
      {1, {"Rock", "Scissors"}},
      {2, {"Paper", "Rock"}},
      {3, {"Scissors", "Paper"}}
    };

    // Determine the result based on user's and computer's choices
    std::string result = "Invalid Choice.";
    if (choices.find(userChoice) != choices.end()) {
        if (choices[userChoice].first == computerChoice) result = "Tie.";
        else if (choices[userChoice].second == computerChoice) result = "You won!";
        else result = "You lost.";
    }

    // Clear console screen
    system("cls");

    // Print choices and result
    std::cout << "Your choice: " << choices[userChoice].first << '\n';
    std::cout << "Computer choice: " << computerChoice << '\n';
    std::cout << "Result: " << result;
}

// Function to output the choices
inline void outputChoices() noexcept {
    std::cout << "Choose:\n";
    std::cout << "1. Rock\n";
    std::cout << "2. Paper\n";
    std::cout << "3. Scissors\n";
}

int main()
{
    int userChoice;
    std::string computerChoice = getComputerChoice();

    // Display avaiable choices to the user
    outputChoices();

    // Prompt user to enter their choice
    std::cout << "Your choice: "; std::cin >> userChoice;

    // Determine and print the winner
    printWinner(userChoice, computerChoice);
}
