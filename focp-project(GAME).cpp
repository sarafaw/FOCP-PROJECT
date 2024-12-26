#include <iostream>  // For input/output operations
#include <chrono>    // For time measurement and durations
#include <thread>    // For thread operations like sleep_for()
#include <limits>    // For numeric limits like numeric_limits<int>::max()
#include <string>    // For using the string class
#include <vector>    // For using the vector container
#include <cstdlib>   // For random number generation and system calls
#include <ctime>     // For seeding random number generation with time
#include <algorithm> // For algorithms like transform()
#include <conio.h>   // For _kbhit() and _getch() to handle keyboard input
#include <windows.h> // For Windows-specific functions like Sleep() and SetConsoleCursorPosition()
#include <fstream>   // For file handling (reading/writing files)
#include <iomanip>   // For formatted output
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace std; // To avoid using `std::` prefix for standard library objects

// Structure for quiz questions
struct Question {
    string question;               // The actual question text
    vector<string> options;        // Options for multiple-choice questions
    string correctAnswer;          // The correct answer for the question
    bool isMultipleChoice;         // True if the question is multiple choice, false otherwise

    // Function to display the question (const member function ensures it doesn't modify the object)
    void displayQuestion() const {
        cout << question << endl; // Display the question text
        if (isMultipleChoice) {
            // Loop through and display all the options for multiple-choice questions
            for (int i = 0; i < options.size(); ++i) {
                cout << (i + 1) << ". " << options[i] << endl; // Numbered options
            }
        }
        else {
            // If not multiple choice, no additional display (can be extended for other formats)
            cout << "";
        }
    }

    // Function to check if the player's answer is correct (const ensures it doesn't modify the object)
    bool checkAnswer(const string& playerAnswer) const {
        if (isMultipleChoice) {
            // For multiple-choice questions, convert playerAnswer to an integer
            int choice = stoi(playerAnswer); // Convert answer to integer (assumes valid input)
            return (choice >= 1 && choice <= options.size()) && options[choice - 1] == correctAnswer;
        }
        else {
            // For fill-in-the-blank questions, perform a case-insensitive comparison
            string cleanAnswer = playerAnswer; // Copy the player's answer
            transform(cleanAnswer.begin(), cleanAnswer.end(), cleanAnswer.begin(), ::tolower); // Convert to lowercase
            return cleanAnswer == correctAnswer; // Compare with the correct answer
        }
    }
};

vector<Question> level1Questions = {
    {
        "What is the correct syntax for starting a basic C++ program?",
        {"start main()", "int main() { }", "main() {}", "begin main() {}"},
        "int main() { }",
        true
    },
    {
        "What symbol is used to end a statement in C++?",
        {":", ".", ";", ","},
        ";",
        true
    },
    {
        "What is the purpose of #include <iostream> in C++?",
        {"It defines the main() function.", "It includes the input/output stream library.", "It is used for declaring variables.", "It ends the program."},
        "It includes the input/output stream library.",
        true
    },
    {
        "What is the output of the following code?\n\n#include <iostream>\nusing namespace std;\nint main() {\n    cout << \"Hello, World!\";\n    return 0;\n}",
        {"Hello, World!", "Hello World", "Error", "No output"},
        "Hello, World!",
        true
    },
    {
        "Which of these is NOT a valid C++ identifier?",
        {"_value", "2value", "value2", "value_2"},
        "2value",
        true
    },
    {
        "What is the correct syntax for a single-line comment in C++?",
        {"/* comment */", "// comment", "# comment", "<!-- comment -->"},
        "// comment",
        true
    },
    {
        "What is the size of an int in C++ (in bytes)?",
        {"1 byte", "2 bytes", "4 bytes", "8 bytes"},
        "4 bytes",
        true
    },

};

// Level 2 Question Bank (Mock Questions)
vector<Question> level2Questions = {
    {
        "Fill in the blank to define a function that returns an integer:\n_ add(int a, int b) {\n    return a + b;\n}",
        {"void", "int", "float", "string"},
        "int",
        true
    },
    {
        "Fill in the blank to call the function displayMessage:\nvoid displayMessage() {\n    cout << \"Hello!\";\n}\nint main() {\n    _ displayMessage();\n    return 0;\n}",
        {"print", "call", "displayMessage()", "invoke"},
        "displayMessage()",
        true
    },
    {
        "Fill in the blank to pass a value to a function:\nvoid greet(string name) {\n    cout << \"Hello, \" << name << \"!\";\n}\nint main() {\n    greet(_);\n    return 0;\n}",
        {"\"John\"", "Hello", "name", "cout"},
        "\"John\"",
        true
    },
    {
        "Fill in the blank to return a value from a function:\nfloat multiply(float a, float b) {\n    _ a * b;\n}",
        {"return", "output", "give", "send"},
        "return",
        true
    },
    {
        "Fill in the blank to declare a function prototype:\n_ printMessage();",
        {"int", "string", "void", "float"},
        "void",
        true
    },
    {
        "Fill in the blank to specify default arguments in a function:\nint sum(int a, int b = _) {\n    return a + b;\n}",
        {"10", "1", "0", "b"},
        "0",
        true
    },
    {
        "Fill in the blank to define a function with no parameters:\n_ sayHello() {\n    cout << \"Hello!\";\n}",
        {"int", "void", "string", "function"},
        "void",
        true
    }
};
// Level 3 Question Bank (Mock Questions)
vector<Question> level3Questions = {
    {
        "Fill in the blank to declare an array of integers with 5 elements:\nint arr[_];",
        {"5", "4", "6", "3"},
        "5",
        true
    },
    {
        "Fill in the blank to access the third element of an array:\ncout << arr[_];",
        {"0", "2", "3", "1"},
        "2",
        true
    },
    {
        "Fill in the blank to initialize an array with values 1, 2, 3:\nint numbers[3] = {_};",
        {"1, 2, 3", "0, 1, 2", "2, 3, 4", "1, 3, 5"},
        "1, 2, 3",
        true
    },
    {
        "Fill in the blank to use a loop to print all elements of an array:\nfor (int i = 0; i < 5; i++) {\n    cout << arr[_];\n}",
        {"0", "i", "arr", "5"},
        "i",
        true
    },
    {
        "Fill in the blank to declare a 2D array with 2 rows and 3 columns:\nint matrix[2][_];",
        {"2", "3", "4", "5"},
        "3",
        true
    },
    {
        "Fill in the blank to assign a value to the first element of an array:\narr[0] = _;",
        {"10", "5", "20", "15"},
        "10",
        true
    },
    {
        "Fill in the blank to find the size of an array in terms of bytes:\ncout << sizeof(_);",
        {"array", "arr", "size", "bytes"},
        "arr",
        true
    },
    {
        "Fill in the blank to iterate over an array using a range-based for loop:\nfor (int x : _) {\n    cout << x;\n}",
        {"array", "arr", "loop", "x"},
        "arr",
        true
    }
};

// Question bank for debugging with MCQs
string question_bank[5] = {
    "Which one is the correct data type for storing integer values?\n1. float\n2. int\n3. char\n4. string\nYour Answer: ",
    "Which one is the correct syntax to output \"Hello World\" in C++?\n1. printf('Hello World');\n2. print('Hello World');\n3. cout << 'Hello World!';\n4. console.log('Hello World!');\nYour Answer: ",
    "What is missing in this for loop?\nfor(int i = 0; i < 10 ; ) { cout << i; }\n1. ';'\n2. 'i++'\n3. 'i<10'\n4. 'cout';\nYour Answer: ",
    "Which of the following is the correct way to declare a pointer in C++?\n1. int ptr;\n2. int* ptr;\n3. *int ptr;\n4. ptr* int;\nYour Answer: ",
    "What is the default value of a static variable in C++?\n1. 0\n2. NULL\n3. Uninitialized\n4. Depends on the type\nYour Answer: "
};

// Correct answers for the MCQs (1 for correct option, 2 for second option, etc.)
int correct_answers[5] = { 2, 3, 2, 2, 1 }; // correct answers for each question like this

// Global variables
const int TOTAL_FLOORS = 3;
int currentFloor = 1; // Starting floor
int key = 0; // Key to unlock the door
int doors = 0; // Number of doors unlocked
int score = 0; // Score

// Function prototypes
// Function prototypes
void setColor(int colorCode);                             // Changes the text color in the console
void resetColor();                                        // Resets the console text color to default
void typeWriterEffect(const string& text);               // Displays text with a typewriter effect, character by character
void blinkingText(const string& text, int times, int delay); // Makes a text blink on the screen a specified number of times with a delay
void showProgressBar(int total);                         // Displays a progress bar for a visual loading effect
void displayBuilding(int current);                       // Visualizes the building's layout or state
void enterFloor();                                       // Handles actions when the player enters a floor
void displayMenu();                                      // Displays the main menu of the game
int getChoice();                                         // Gets the player's choice from the menu
void buildingProgress();                                 // Tracks and shows building progression
void newGame();                                          // Starts a new game session
void showInstructions();                                 // Shows game instructions to the player
void showStory();                                        // Displays the storyline of the game
void showHelp();                                         // Provides help or tips for the player
void playGame();                                         // Main gameplay loop
void loadGame();                                         // Loads a previously saved game state
void saveGame();                                         // Saves the current game state
void displayStoryline(int level);                       // Displays a storyline segment based on the current level
char** initializeMaze(int rows, int cols);              // Initializes a maze (game level) with a given size
void deleteMaze(char** maze, int rows);                 // Frees up memory allocated for the maze
void populateMaze1(char** maze);                        // Populates the maze with layout and objects for level 1
void populateMaze2(char** maze);                        // Populates the maze with layout and objects for level 2
void populateMaze3(char** maze);                        // Populates the maze with layout and objects for level 3
void printMaze(char** maze, int rows, int cols);        // Prints the current maze to the console
void movePlayer(char direction, char** maze, int rows, int cols, int level); // Moves the player in the maze based on input direction and updates the game state
void switchToNextLevel(int& currentLevel, char**& currentMaze, int& currentRows, int& currentCols); // Advances the player to the next level and updates maze and level parameters
void clearScreen();                                     // Clears the console screen for a fresh display
void setCursorPosition(int x, int y);                   // Sets the cursor to a specific position in the console
static void doorAndWindowMechanics(int level);          // Handles door and window-related mechanics in the game for a given level
static bool openDoorAndCheckKey(vector<Question>& questions); // Manages the logic for opening doors and checking if the player has the correct key
static bool askQuestion(const Question& q);             // Asks a single question and checks if the player's answer is correct
bool ask(int questionIndex);                            // Asks a debugging question during gameplay and verifies the answer
void earthquakeEvent(int level);                        // Simulates the earthquake event, asking questions to stabilize the building
void simulateEarthquake();                              // Handles the visual simulation of an earthquake effect

// Main function
int main() {

    // Load background music
    sf::Music backgroundMusic;
    if (!backgroundMusic.openFromFile("gamesound.wav")) { // Ensure the file exists
        cout << "Error: Could not load background music!" << endl;
        return -1;
    }

    // Set music properties
    backgroundMusic.setLoop(true); // Loop the music
    backgroundMusic.setVolume(50); // Set volume
    backgroundMusic.play();        // Start playing

    int choice;

    // Display the game title with animation and color
    setColor(35); // Magenta for the title
    typeWriterEffect("\n========== CODE ESCAPE CHALLENGE ==========\n");
    resetColor();

    // Welcome message with animation
    setColor(36); // Cyan for the welcome text
    typeWriterEffect("Welcome to the ultimate test of your coding knowledge and survival instincts!\n");
    resetColor();

    while (true) {
        displayMenu();
        choice = getChoice();

        switch (choice) {
        case 1:
            setColor(32); // Green for starting a new game
            typeWriterEffect("\nStarting a new game...");
            resetColor();
            newGame();
            break;
        case 2:
            setColor(33); // Yellow for loading a game
            typeWriterEffect("\nLoading your saved game...");
            resetColor();
            loadGame();
            break;
        case 3:
            setColor(34); // Blue for showing instructions
            typeWriterEffect("\nDisplaying gameplay instructions...");
            resetColor();
            showInstructions();
            break;
        case 4:
            setColor(35); // Magenta for showing the story
            typeWriterEffect("\nIntroducing the storyline...");
            resetColor();
            showStory();
            break;
        case 5:
            setColor(36); // Cyan for showing help
            typeWriterEffect("\nAccessing the help menu...");
            resetColor();
            showHelp();
            break;
        case 0:
            setColor(31); // Red for exiting the game
            typeWriterEffect("\nExiting the game. Goodbye!");
            resetColor();
            return 0;
        default:
            setColor(31); // Red for invalid input
            typeWriterEffect("\nInvalid choice! Please try again.");
            resetColor();
        }
    }

    return 0;
}

// Function to set text color
void setColor(int colorCode) {
    cout << "\033[1;" << colorCode << "m";
}

// Function to reset text color to default
void resetColor() {
    cout << "\033[0m";
}

// Function to simulate a typing effect
void typeWriterEffect(const string& text) {
    for (int i = 0; i < text.length(); i++) {
        cout << text[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(50)); // Adjust speed here
    }
    cout << endl;
}

// Function to simulate blinking text
// Parameters:
// - text: The text to display
// - times: Number of times the text should blink
// - delay: Time delay between each blink in milliseconds
void blinkingText(const string& text, int times, int delay) {
    for (int i = 0; i < times; ++i) {
        cout << "\033[2K"; // ANSI escape code to clear the current line
        setColor(33); // Set text color to yellow 
        cout << text; // Display the text
        resetColor(); // Reset the text color to default 
        cout.flush(); // Flush the output buffer to ensure the text is displayed immediately
        this_thread::sleep_for(chrono::milliseconds(delay)); // Pause for the specified delay time

        cout << "\033[2K"; // Clear the line again for the "off" part of the blink
        cout.flush(); // Flush to ensure the line is cleared
        this_thread::sleep_for(chrono::milliseconds(delay)); // Pause for the specified delay time
    }
    cout << endl; // Move to the next line after blinking is complete
}

// Function to show a progress bar animation
// Parameters:
// - total: The total number of steps in the progress bar (controls the completion percentage)
void showProgressBar(int total) {
    for (int i = 0; i <= total; ++i) {
        int percentage = (i * 100) / total; // Calculate the completion percentage
        cout << "\r["; // Move the cursor to the start of the line and print the opening bracket for the progress bar

        int barWidth = 50;  // Fixed width of the progress bar
        int pos = barWidth * i / total; // Calculate the position of the progress indicator based on progress

        // Draw the progress bar
        for (int j = 0; j < barWidth; ++j) {
            if (j < pos)          // Completed portion of the progress bar
                cout << "=";
            else if (j == pos)    // Current position of progress
                cout << ">";
            else                  // Remaining portion of the progress bar
                cout << " ";
        }
        cout << "] " << percentage << "%"; // Close the progress bar and show the percentage completed
        cout.flush(); // Flush the output buffer to ensure the progress bar updates in real time

        this_thread::sleep_for(chrono::milliseconds(10)); // Delay to control the speed of the animation
    }
    cout << endl; // Move to the next line once the progress bar is complete
}

// Function to display the building with floors
void displayBuilding(int current) {
    clearScreen();
    setColor(36); // Cyan text
    cout << "\n========== BUILDING MAP ==========" << endl;
    resetColor();

    for (int i = TOTAL_FLOORS; i >= 1; i--) {
        if (i == current) {
            setColor(33); // Yellow text for the current floor
            cout << "\t--> [ ** FLOOR " << i << " ** ]" << endl;
        }
        else {
            setColor(34); // Blue text for other floors
            cout << "\t    [ Floor " << i << " ]" << endl;
        }
    }
    resetColor();
    setColor(36); // Cyan text
    cout << "====================================" << endl;
    resetColor();
}

// Function to simulate entering a floor
void enterFloor() {
    cout << "\nYou are now on Floor " << currentFloor << "!" << endl;
    cout << "Press Enter to enter the floor..." << endl;
    cin.get(); // Wait for Enter
    cout << "Entering Floor " << currentFloor << "...\n";
}

// Function to display the menu with animations and colors
void displayMenu() {
    setColor(34); // Set text color to blue
    cout << "====================================" << endl;
    cout << "        Tower of Odyssey            " << endl;
    cout << "====================================" << endl;
    resetColor(); // Reset color

    // Typing effect for the introduction
    typeWriterEffect("Welcome to the Tower of Odyssey!\nNavigate the challenges and escape to freedom.");

    // Show progress bar to simulate loading
    cout << "Loading menu, please wait..." << endl;
    showProgressBar(50); // Progress bar goes from 0 to 50

    // Display menu options
    cout << "\nMenu Options: \n";
    setColor(32); // Set text color to green
    cout << "1. New Game\n";
    cout << "2. Load Game\n";
    cout << "3. Gameplay Instructions\n";
    cout << "4. Story Intro\n";
    cout << "5. Help\n";
    cout << "0. Exit\n";
    resetColor(); // Reset color

    setColor(34); // Set text color to blue
    cout << "====================================" << endl;
    resetColor(); // Reset color
}

// Function to get a valid menu choice from the user
// Returns: The user's valid choice as an integer
int getChoice() {
    int choice; // Variable to store the user's choice
    cout << "Enter your choice: ";
    cin >> choice;

    // Validate input: Ensure the input is a valid number and within the acceptable range (0 to 6)
    while (cin.fail() || choice < 0 || choice > 6) {
        cin.clear(); // Clear the error flags set by invalid input (e.g., entering non-numeric characters)

        // If the 'max' is defined, we undefine (remove) it to avoid conflicts.
#ifdef max 
#undef max 
#endif
        // Ignore the invalid input up to the next newline to reset the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

#ifdef max 
#define max 
#endif
        // Prompt the user again for valid input
        cout << "Invalid input. Please choose a number between 0 and 6: ";
        cin >> choice; // Read the input again
    }
    return choice; // Return the valid choice
}

// Function to simulate the building progress
void buildingProgress() {
    char choice;
    while (currentFloor <= TOTAL_FLOORS) {
        displayBuilding(currentFloor);
        cout << "\nDo you want to enter Floor " << currentFloor << "? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cin.ignore(); // To clear input buffer
            enterFloor();
            playGame(); // Start the maze game for the current floor
            currentFloor++;
        }
        else {
            cout << "\nYou chose not to enter Floor " << currentFloor << ". Continuing...\n";
            currentFloor++;
        }
    }
    cout << "\nCongratulations! You've reached the top of the building!\n";
}

void newGame() {
    setColor(36); // Cyan text
    cout << "Starting a new adventure in the Code Escape Challenge..." << endl;
    resetColor();
    buildingProgress(); // Start building progress
}

void showInstructions() {
    setColor(36); // Cyan text
    cout << "========== GAMEPLAY INSTRUCTIONS ==========" << endl;
    cout << "1. Navigate through the building using WASD keys.\n";
    cout << "2. Solve C++ puzzles to unlock doors and collect keys.\n";
    cout << "3. Avoid windows and traps that may lower your score.\n";
    cout << "4. Survive random events like earthquakes and burglars!\n";
    cout << "5. Reach the top floor to complete your escape.\n";
    resetColor();
}

// Function to display the storyline
void showStory() {
    clearScreen();
    setColor(36);
    typeWriterEffect("You are trapped in the Tower of Code, a seven-story labyrinth controlled by the mysterious Code Master...");
    typeWriterEffect("Your mission: Ascend through each floor, solving coding challenges and outsmarting traps, to reach freedom.");
    typeWriterEffect("But beware, the higher you climb, the harder the puzzles become. Are you ready?");
    resetColor();
}

void showHelp() {
    clearScreen();
    setColor(36);
    cout << "========== HELP ==========" << endl;
    cout << "Stuck? Here are some tips to help you succeed:\n";
    cout << "- Revisit the instructions and storyline to refresh your goals.\n";
    cout << "- Pay attention to hints in the puzzles.\n";
    cout << "- Manage your score wisely to avoid penalties.\n";
    cout << "- Save your progress frequently!\n";
    resetColor();
}

// Constants for maze size
const int MAZE_SIZE_LEVEL1 = 15;
const int MAZE_SIZE_LEVEL2 = 17;
const int MAZE_SIZE_LEVEL3 = 19;

// Characters representing maze elements
const char CORNER = '+';   // Represents corners
const char HORIZONTAL = '-'; // Represents horizontal walls
const char VERTICAL = '|'; // Represents vertical walls
const char EMPTY = ' ';
const char DOOR = 'D';
const char WINDOW = 'W';
const char PLAYER = 'P';
const char EXIT = 'E';

// Player's starting position
int playerX = 1, playerY = 1;


// Function to set the cursor position in the console
void setCursorPosition(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to clear the console screen
void clearScreen() {
    system("cls");
}

// Function to dynamically initialize a maze
// Parameters:
// - rows: Number of rows in the maze
// - cols: Number of columns in the maze
// Returns: A pointer to a dynamically allocated 2D array representing the maze
char** initializeMaze(int rows, int cols) {
    // Allocate memory for the array of row pointers
    char** maze = new char* [rows];

    // Allocate memory for each row (each row is an array of characters)
    for (int i = 0; i < rows; ++i) {
        maze[i] = new char[cols];
    }

    return maze; // Return the pointer to the 2D maze
}

// Function to delete a dynamically allocated maze
// Parameters:
// - maze: Pointer to the dynamically allocated 2D array
// - rows: Number of rows in the maze
void deleteMaze(char** maze, int rows) {
    // Deallocate memory for each row (individual arrays)
    for (int i = 0; i < rows; ++i) {
        delete[] maze[i];
    }

    // Deallocate memory for the array of row pointers
    delete[] maze;
}

// Function to populate the first maze
void populateMaze1(char** maze) {
    char temp[15][15] = {
    { '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+' },
    { '|', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E', '|' },
    { '|', '-', '-', '|', ' ', ' ', '-', '-', ' ', '|', '-', '-', '-', ' ', '|' },
    { '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|' },
    { '|', ' ', '|', '-', '-', 'D', '|', '-', '-', ' ', '|', ' ', '|', ' ', '|' },
    { '|', 'D', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', '|' },
    { '|', '-', '-', ' ', '|', '-', '|', 'W', '|', '-', '-', '-', '-', ' ', '|' },
    { '|', 'W', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|' },
    { '|', ' ', '|', '-', '-', '-', '-', ' ', '|', ' ', '|', 'D', '|', ' ', '|' },
    { '|', ' ', 'D', ' ', ' ', ' ', 'D', ' ', '|', ' ', '|', ' ', '|', ' ', '|' },
    { '|', '-', '-', '-', ' ', '|', ' ', '|', '-', '-', '|', ' ', '|', ' ', '|' },
    { '|', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', 'W', '|', ' ', '|' },
    { '|', ' ', '|', '-', ' ', '|', ' ', '|', ' ', '|', '-', ' ', '|', ' ', '|' },
    { '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|' },
    { '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+' }
    };

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            maze[i][j] = temp[i][j];
        }
    }
}

// Function to populate the second maze
void populateMaze2(char** maze) {
    char temp[17][17] = {
        { '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+' },
        { '|', 'P', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '-', 'W', ' ', ' ', '|' },
        { '|', '-', '-', '-', ' ', '-', '-', ' ', '-', ' ', '-', ' ', '-', ' ', '-', ' ', '|' },
        { '|', ' ', ' ', '-', 'D', ' ', ' ', ' ', '-', ' ', ' ', ' ', '-', ' ', ' ', 'E', '|' },
        { '|', '-', ' ', '-', ' ', '-', '-', '-', '-', '-', '-', ' ', '-', ' ', '-', '-', '|' },
        { '|', ' ', ' ', ' ', ' ', '-', ' ', ' ', '-', ' ', ' ', ' ', '-', ' ', ' ', ' ', '|' },
        { '|', ' ', '-', '-', '-', '-', ' ', ' ', '-', ' ', '-', '-', '-', ' ', 'D', '-', '|' },
        { '|', 'D', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', '|' },
        { '|', '-', '-', ' ', '-', '-', '-', '-', '-', ' ', '-', '-', '-', '-', '-', ' ', '|' },
        { '|', ' ', '-', 'W', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', '|' },
        { '|', ' ', '-', ' ', '-', '-', ' ', '-', '-', '-', '-', '-', '-', '-', '-', ' ', '|' },
        { '|', ' ', '-', ' ', '-', '-', ' ', ' ', '-', ' ', ' ', ' ', '-', ' ', '-', ' ', '|' },
        { '|', ' ', '-', ' ', '-', '-', '-', ' ', '-', ' ', '-', ' ', '-', ' ', '-', ' ', '|' },
        { '|', ' ', '-', ' ', '-', '-', '-', ' ', '-', ' ', 'W', ' ', '-', ' ', 'D', ' ', '|' },
        { '|', ' ', '-', '-', '-', ' ', '-', 'D', '-', ' ', '-', ' ', '-', 'D', ' ', ' ', 'W' },
        { '|', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', '-', ' ', ' ', ' ', '-', '-', '-' },
        { '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+' }
    };

    for (int i = 0; i < 17; ++i) {
        for (int j = 0; j < 17; ++j) {
            maze[i][j] = temp[i][j];
        }
    }
}

// Function to populate the third maze
void populateMaze3(char** maze) {
    char temp[19][19] = {
        { '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+' },
        { '|', 'P', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', '-', ' ', 'D', ' ', '-', ' ', ' ', '|' },
        { '|', '-', '-', '-', ' ', '-', ' ', '-', '-', ' ', '-', ' ', '-', ' ', '-', '-', ' ', '|' },
        { '|', ' ', ' ', '-', 'D', '-', ' ', ' ', '-', ' ', ' ', ' ', '-', ' ', '-', ' ', ' ', '|' },
        { '|', '-', ' ', '-', ' ', '-', '-', '-', '-', '-', '-', ' ', '-', ' ', '-', ' ', '-', '|' },
        { '|', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', '-', ' ', '-', ' ', '-', ' ', '-', '|' },
        { '|', ' ', '-', '-', '-', '-', ' ', ' ', '-', ' ', '-', ' ', '-', ' ', '-', ' ', '-', '|' },
        { '|', ' ', 'W', ' ', '-', ' ', ' ', ' ', '-', ' ', 'D', ' ', '-', ' ', ' ', ' ', '-', '|' },
        { '|', '-', '-', ' ', '-', '-', '-', 'D', '-', '-', '-', '-', '-', ' ', '-', '-', '-', '|' },
        { '|', ' ', '-', ' ', ' ', ' ', '-', ' ', ' ', '-', ' ', 'W', ' ', ' ', '-', ' ', 'D', '|' },
        { '|', ' ', '-', ' ', '-', '-', '-', '-', ' ', '-', ' ', '-', '-', '-', '-', ' ', '-', '|' },
        { '|', ' ', '-', ' ', '-', '-', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', '-', ' ', '-', '|' },
        { '|', '-', '-', 'D', '-', ' ', ' ', ' ', '-', '-', '-', '-', '-', ' ', '-', ' ', ' ', '|' },
        { '|', 'D', ' ', ' ', '-', ' ', '-', ' ', '-', ' ', ' ', ' ', '-', 'D', '-', '-', ' ', '|' },
        { '|', ' ', '-', '-', '-', ' ', '-', ' ', '-', '-', '-', ' ', '-', ' ', ' ', ' ', 'W', '|' },
        { '|', ' ', ' ', '-', ' ', ' ', '-', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', '-', ' ', '|' },
        { '|', '-', 'W', '-', '-', ' ', '-', '-', '-', ' ', '-', '-', '-', '-', '-', '-', ' ', '|' },
        { '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', '|' },
        { '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+' }
    };

    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            maze[i][j] = temp[i][j];
        }
    }
}

// Function to display the storyline for each level
void displayStoryline(int level) {
    clearScreen();
    if (level == 1) {
        cout << "Level 1: Mastering the Basics – Crafting Your Parachute" << endl;
        cout << "You awaken in a shadowy room, disoriented but determined. Your mission? Gather the materials needed to construct a parachute." << endl;
        cout << "Use the right C++ syntax to assemble the parts and take the first step toward your great escape!" << endl;
    }
    else if (level == 2) {
        cout << "Level 2: Loops and Functions – Precision in Parachute Engineering" << endl;
        cout << "The clock is ticking, and your next task awaits. Stitch the fabric seamlessly using loops, and attach the parachute securely to the backpack with the power of functions." << endl;
        cout << "This isn’t just programming; it’s survival engineering!" << endl;
    }
    else if (level == 3) {
        cout << "Level 3: Arrays and Advanced Challenges – The Flight to Freedom" << endl;
        cout << "The pinnacle of your journey is here. The parachute is packed, and you’re prepared to leap into the unknown." << endl;
        cout << "But before you take flight, a final trial awaits—a thrilling test of all the C++ skills you've honed. Rise to the occasion and prove your genius to earn your freedom!" << endl;
    }
    Sleep(5000); // Pause to allow the player to read the storyline
    clearScreen();
}

// Function to print the maze
void printMaze(char** maze, int rows, int cols) {
    setCursorPosition(0, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == playerY && j == playerX) {
                setColor(32); // Green for the player
                cout << PLAYER;
            }
            else if (maze[i][j] == DOOR) {
                setColor(33); // Yellow for doors
                cout << maze[i][j];
            }
            else if (maze[i][j] == WINDOW) {
                setColor(31); // Red for windows
                cout << maze[i][j];
            }
            else if (maze[i][j] == EXIT) {
                setColor(35); // Magenta for the exit
                cout << maze[i][j];
            }
            else {
                resetColor();
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
    resetColor();
    cout << "Score: " << score << endl;
}

// Function to check if a position is a wall
bool isWall(char cell) {
    return (cell == CORNER || cell == HORIZONTAL || cell == VERTICAL);
}

// Function to move the player based on user input and handle interactions in the maze
// Parameters:
// - direction: The player's input ('w', 's', 'a', 'd' for movement directions)
// - maze: The 2D array representing the maze
// - rows: Number of rows in the maze
// - cols: Number of columns in the maze
// - level: Current level of the game
void movePlayer(char direction, char** maze, int rows, int cols, int level) {
    int newX = playerX; // Temporary variable for new X-coordinate
    int newY = playerY; // Temporary variable for new Y-coordinate

    // Determine the new position based on the input direction
    switch (direction) {
    case 'w': newY--; break; // Move up
    case 's': newY++; break; // Move down
    case 'a': newX--; break; // Move left
    case 'd': newX++; break; // Move right
    }

    // Check if the move is valid (within bounds and not a wall)
    if (newY >= 0 && newY < rows && newX >= 0 && newX < cols && !isWall(maze[newY][newX])) {
        // Handle interaction if the player hits a window
        if (maze[newY][newX] == WINDOW) {
            clearScreen();
            cout << "\033[1;33m"; // Set text color to yellow
            cout << "You hit a window! -1 point." << endl;
            cout << "\033[0m"; // Reset text color
            _getch(); // Wait for the player to press a key
            clearScreen();
            score -= 1; // Deduct 1 point for hitting a window
        }
        // Handle interaction if the player reaches a door
        else if (maze[newY][newX] == DOOR) {

            // Add this code before the burglar encounter message
            sf::SoundBuffer burglarBuffer;
            if (!burglarBuffer.loadFromFile("burglar.wav")) {
                std::cerr << "Error loading burglar sound!" << std::endl;
                return;
            }
            sf::Sound burglarSound;
            burglarSound.setBuffer(burglarBuffer);

            // Random chance of encountering a burglar (1 in 5 chance)
            if (rand() % 5 == 3 && doors != 3) {
                clearScreen();

                // Play the burglar sound
                burglarSound.play();

                // Display the burglar encounter message
                cout << "\033[1;31m"; // Set text color to red
                cout << "You encountered a Burglar! He ran away with your points (and your GPA)." << endl;
                cout << "\033[0m"; // Reset text color

                // Simple animation for burglar escaping
                cout << "\033[1;31m"; // Red color
                cout << "The Burglar is running away..." << endl;
                cout << "\033[0m"; // Reset color
                _getch(); // Wait for the player to press a key
                clearScreen();

                score -= 10; // Deduct 10 points for the burglar encounter
            }
            else {
                // Handle door mechanics and increment door count
                doorAndWindowMechanics(level);
                doors++;
                _getch(); // Wait for the player to press a key
                clearScreen();
                score += 10; // Reward 10 points for finding a door
            }
        }
        // Handle interaction if the player reaches the exit
        if (maze[newY][newX] == EXIT) {
            if (key == 0) {
                // If the player doesn't have the key, prompt them to find it
                clearScreen();
                cout << "\033[1;34m"; // Set text color to blue
                cout << "You need to find the key to proceed to the next level!" << endl;
                cout << "\033[0m"; // Reset text color
                _getch(); // Wait for the player to press a key
            }
            else {
                // If the player has the key, proceed to the next level
                maze[playerY][playerX] = EMPTY; // Clear the old position
                playerX = newX;
                playerY = newY;
                doors = 0; // Reset door count for the next level
            }
        }
        // Handle general movement or random earthquake events
        else {
            if (rand() % 70 == 5) { // Small chance of an earthquake event occurring
                earthquakeEvent(level);
            }
            maze[playerY][playerX] = EMPTY; // Clear the player's old position
            playerX = newX; // Update player's X-coordinate
            playerY = newY; // Update player's Y-coordinate
        }
    }
}

// Function to switch to the next level
void switchToNextLevel(int& currentLevel, char**& currentMaze, int& currentRows, int& currentCols) {
    deleteMaze(currentMaze, currentRows);
    playerX = 1;
    playerY = 1;

    if (currentLevel == 1) {
        currentLevel++;
        currentRows = MAZE_SIZE_LEVEL2;
        currentCols = MAZE_SIZE_LEVEL2;
        currentMaze = initializeMaze(currentRows, currentCols);
        populateMaze2(currentMaze);
    }
    else if (currentLevel == 2) {
        currentLevel++;
        currentRows = MAZE_SIZE_LEVEL3;
        currentCols = MAZE_SIZE_LEVEL3;
        currentMaze = initializeMaze(currentRows, currentCols);
        populateMaze3(currentMaze);
    }
    else if (currentLevel == 3) {
        currentLevel++;
        currentRows = MAZE_SIZE_LEVEL3;
        currentCols = MAZE_SIZE_LEVEL3;
        currentMaze = initializeMaze(currentRows, currentCols);
        populateMaze3(currentMaze);
    }

    else {
        cout << "Congratulations, you've completed all levels!" << endl;
        exit(0); // Game Over
    }
}

// Main game function
void playGame() {
    int currentLevel = currentFloor;
    int currentRows, currentCols;
    char** currentMaze;

    // Ensure the game starts from the correct saved level
    switch (currentFloor) {
    case 1:
        currentRows = MAZE_SIZE_LEVEL1;
        currentCols = MAZE_SIZE_LEVEL1;
        currentMaze = initializeMaze(currentRows, currentCols);
        populateMaze1(currentMaze);
        break;
    case 2:
        currentRows = MAZE_SIZE_LEVEL2;
        currentCols = MAZE_SIZE_LEVEL2;
        currentMaze = initializeMaze(currentRows, currentCols);
        populateMaze2(currentMaze);
        break;
    case 3:
        currentRows = MAZE_SIZE_LEVEL3;
        currentCols = MAZE_SIZE_LEVEL3;
        currentMaze = initializeMaze(currentRows, currentCols);
        populateMaze3(currentMaze);
        break;
    default:
        cout << "Invalid level!" << endl;
        return;
    }

    displayStoryline(currentFloor);
    printMaze(currentMaze, currentRows, currentCols);

    while (true) {
        if (_kbhit()) {
            char input = _getch();
            movePlayer(input, currentMaze, currentRows, currentCols, currentLevel);
            printMaze(currentMaze, currentRows, currentCols);

            if (currentMaze[playerY][playerX] == EXIT) { // Check for exit condition
                if (key == 0) {
                    cout << "You need to find the key to proceed to the next level!" << endl;
                }
                else {
                    cout << "Congratulations! You've reached the exit." << endl;
                    _getch();
                    key = 0;  // Reset key for next level

                    saveGame(); // Save progress only when proceeding to the next level

                    switchToNextLevel(currentLevel, currentMaze, currentRows, currentCols);
                    displayStoryline(currentLevel);
                    printMaze(currentMaze, currentRows, currentCols);
                }
            }
        }
    }

    deleteMaze(currentMaze, currentRows); // Cleanup
}

static void doorAndWindowMechanics(int level) {
    vector<Question> questions;

    // Set questions for the current level
    if (level == 1) {
        questions = level1Questions;
    }
    else if (level == 2) {
        questions = level2Questions;
    }
    else if (level == 3) {
        questions = level3Questions;
    }

    // Functionality: When player reaches a door, quiz question is asked
    bool doorOpened = false;
    while (!doorOpened) {
        cout << "\nYou approach a door. Answer the question to open it." << endl;

        // Open the door and check if the key is behind it
        doorOpened = openDoorAndCheckKey(questions);
    }

    cout << "\nYour current score: " << score << endl;
}

// Function to ask the question and check the answer
static bool askQuestion(const Question& q) {
    string playerAnswer;

    q.displayQuestion();

    // Allow the player to input their answer
    cout << "Your answer: ";
    getline(cin, playerAnswer);

    // Validate answer
    if (q.checkAnswer(playerAnswer)) {
        setColor(32); // Green for correct
        cout << "Correct! You can check the door." << endl;
        resetColor();
        return true;  // Answer is correct
    }
    else {
        setColor(31); // Red for incorrect
        cout << "Wrong answer! -1 point. Try again." << endl;
        resetColor();
        score -= 1;  // Deduct 1 point for wrong answer
        return false;  // Answer is wrong
    }
}

// Function to open a door and check if the key is there
static bool openDoorAndCheckKey(vector<Question>& questions) {
    bool answeredCorrectly = false;

    // Ask the question until the player answers correctly
    while (!answeredCorrectly) {
        // Pick a random question for the level
        srand(static_cast<unsigned int>(time(0)));  // Cast time(0) to unsigned int to avoid warning
        int questionIndex = rand() % questions.size();

        // Ask the question and validate the answer
        answeredCorrectly = askQuestion(questions[questionIndex]);

        // If the answer is correct, check if the key is behind the door
        if (answeredCorrectly) {
            // Randomly decide if the key is behind the door
            bool keyFound = rand() % 2 == 0;  // 50% chance to find the key

            if (doors == 3)
            {
                keyFound = true;
            }
            if (keyFound) {
                cout << "You found the key! You can proceed to the next level." << endl;
                key = 1;  // Set key to 1 to indicate key found
                return true;  // Key found, proceed to next level
            }
            else {
                cout << "No key behind this door. Try another door." << endl;
                return true;  // No key, player continues trying
            }
        }
    }
    return false;
}

void simulateEarthquake() {
    // Load the earthquake sound buffer
    sf::SoundBuffer earthquakeBuffer;
    if (!earthquakeBuffer.loadFromFile("earthquake.wav")) {
        std::cerr << "Error loading earthquake sound!" << std::endl;
        return;
    }

    sf::Sound earthquakeSound;
    earthquakeSound.setBuffer(earthquakeBuffer);

    // Play the earthquake sound (looped for a shaking effect)
    earthquakeSound.play();

    for (int i = 0; i < 5; i++) {  // Shake the screen 5 times
        clearScreen();
        setColor(31); // Red for urgency
        cout << "EARTHQUAKE! The screen shakes violently as the building trembles...\n";
        resetColor();
        this_thread::sleep_for(chrono::milliseconds(100));
        clearScreen();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// Function to ask a debugging question and check if the answer is correct
bool ask(int questionIndex) {
    string userAnswer; // Variable to store the user's answer
    cout << question_bank[questionIndex];  // Show the debugging question
    cin >> userAnswer; // Get the user's answer

    // Convert the answer to an integer and check if it's correct
    int userChoice = stoi(userAnswer);
    if (userChoice == correct_answers[questionIndex]) {
        return true; // Answer is correct
    }
    else {
        return false; // Answer is incorrect
    }
}

// Main game loop for the earthquake event
void earthquakeEvent(int level) {
    // Determine how many earthquakes happen based on the level
    int earthquakeCount = level - 3;  // Level 4 starts triggering earthquakes
    if (earthquakeCount < 1) earthquakeCount = 1;  // Always have at least one earthquake

    // Loop through each earthquake event
    for (int i = 0; i < earthquakeCount; i++) {
        clearScreen(); // Clear the screen for a dramatic effect
        setColor(33); // Use yellow color to show a warning message
        cout << "Prepare for the earthquake...\n"; // Notify the player
        resetColor(); // Reset to default color
        this_thread::sleep_for(chrono::seconds(2)); // Pause for 2 seconds

        simulateEarthquake();  // Simulate the earthquake effect on the screen

        // Ask the player a random debugging question
        cin.ignore(); // Clear the input buffer to avoid issues
        bool isCorrect = ask(rand() % 3); // Randomly pick a question from the question bank
        if (isCorrect) {
            // If the answer is correct, stabilize the building and continue
            clearScreen(); // Clear the screen for a clean success message
            setColor(32); // Use green color for success
            cout << "Correct! The building stabilizes, and you can continue.\n";
            resetColor(); // Reset to default color
            cin.ignore(); // Wait for the user to press Enter
            _getch(); // Wait for user input (platform-specific)
            clearScreen(); // Clear the screen again for the next phase
        }
        else {
            // If the answer is wrong, the game ends
            clearScreen(); // Clear the screen for a clean failure message
            setColor(31); // Use red color for failure
            cout << "Incorrect! The building collapses, and you have to start over.\n";
            resetColor(); // Reset to default color
            exit(0);  // Exit the game or restart (based on game design)
        }
    }
}

// Function to save the current game state to a file
void saveGame() {
    ofstream saveFile("savegame.txt"); // Open a file named "savegame.txt" for writing
    if (saveFile.is_open()) { // Check if the file opened successfully
        // Save the game variables into the file, each on a new line
        saveFile << currentFloor << "\n";
        saveFile << score << "\n";
        saveFile << key << "\n";
        saveFile << doors << "\n";
        saveFile.close(); // Close the file after saving
        cout << "Game saved successfully!" << endl; // Inform the player the save was successful
    }
    else {
        cout << "Error saving the game!" << endl; // Inform the player if saving failed
    }
}

// Function to load a saved game state from a file
void loadGame() {
    ifstream saveFile("savegame.txt"); // Open the file named "savegame.txt" for reading
    if (saveFile.is_open()) { // Check if the file exists and opened successfully
        // Load the saved values into the game variables
        saveFile >> currentFloor;
        saveFile >> score;
        saveFile >> key;
        saveFile >> doors;
        saveFile.close(); // Close the file after loading
        cout << "Game loaded successfully!" << endl; // Inform the player the load was successful
        playGame(); // Resume the game from the loaded state
    }
    else {
        cout << "No saved game found!" << endl; // Inform the player if no save file exists
    }
}
