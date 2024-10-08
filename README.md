# Hangman: A simple console-based game

## Description

Hangman is a classic word-guessing game created in C++. Players try to guess a hidden word by suggesting letters, with a limited number of incorrect guesses allowed. This game is fun and easy to play, making it suitable for everyone.

## Key Features

- Random Word Selection: Picks a word from a list stored in a text file.
- Simple Interface: Easy-to-use console interface for a smooth gaming experience.
- Hangman Drawing: A visual representation of the hangman that updates with each incorrect guess.
- Input Checks: Ensures user guesses are valid and prevents duplicates.
- Replay Option: Players can choose to play again after finishing a game.
- Error Alerts: Notifies users if there are issues with accessing the word list file.

## Getting Started

### Requirements

- C++ compiler

### Installation
1. **Clone the Repository:** Clone this GitHub repository to your local system:

    ```shell
    git clone https://github.com/sahajpokharel/Hangman.git
    ```
2. **Compile the Code:** Navigate to the project directory and compile the C++ source code. This will create an executable file named `hangman`.

3. **Run the Program:** Run the compiled program.

### How To Play

1. The goal is to guess the hidden word within 7 attempts before the hangman is completely drawn.
2. At the beginning, you'll see a series of blanks representing each letter in the word, an empty list of incorrect letters, and a prompt to enter your guess.
3. Type a letter you think is in the word.
4. If the letter is in the word, it will fill in all the blanks where that letter appears.
5. If the letter is not in the word, it will be added to the list of incorrect letters, and a part of the hangman will be drawn.
6. Continue guessing letters until you reveal all the letters in the word before the hangman is fully drawn.
7. If the hangman is fully drawn before you guess the word, you lose.
8. After a game ends, you can choose to play again or exit the program.
