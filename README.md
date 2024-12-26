# FOCP-PROJECT
**Tower of Odyssey** is an educational console game that teaches C++ programming through interactive puzzles and mazes. Players navigate a 7-floor building, solving coding challenges and overcoming obstacles to reach the top. Each level introduces progressively harder C++ concepts, making learning fun and engaging.

 
GULWARINA MUSKA SALEEM (520047), 
SARA FAWAD (509615) , 
ANEEQA ZAHID (519265)  ,
 DUA FATIMA (510591) 


This includes:
work breakdown
Project description and relevant details
Technical architecture
           TOWER OF ODYSSEY 

Project Description
"Tower of Odyssey" is an educational, console-based game designed to teach and reinforce C++ programming concepts through interactive gameplay. Players must navigate a seven-floor building filled with mazes, questions, and random events. Each floor introduces progressively challenging programming tasks, aligning with real-world coding concepts. The game combines learning and entertainment by incorporating dynamic mazes, unexpected events, and a captivating storyline. Each level focuses on a distinct C++ topic, helping players improve their coding skills while solving puzzles and overcoming obstacles to reach the top.

Objectives
Educational Goals
Teach core C++ programming concepts through engaging and interactive tasks.
Develop critical thinking, problem-solving, and debugging skills.
Gameplay Goals
Provide a fun and challenging experience with strategic navigation, real-time events, and a dynamic storyline.
Promote replayability through randomized questions, events, and maze layouts.

Game Features
1. Multi-Level Progression
Floors as Levels:
Each floor represents a specific C++ programming concept:
Level 1: Basics (Syntax, variables, data types).
Level 2: Advanced variables and operators.
Level 3: Arrays and loops.
Level 4-7: (Upcoming topics: Functions, pointers, object-oriented programming).
Objective: Players navigate mazes, find hidden keys, and solve C++ questions to ascend the building.
2. Core Gameplay Mechanics
Maze Navigation:
Unique mazes per floor.
WASD keys for movement.
Maze Elements:
Doors (D): Contain randomized C++ questions.
Windows (W): Obstruct paths and reduce points on collision.
Walls (+, |, -): Impassable barriers.
Player (P) and Exit (E) indicators.
Key Collection:
Solve questions correctly to find the key behind a door.
Keys unlock exits, allowing progression to the next floor.
Score System:
+10 points: Correct answers.
-1 point: Colliding with windows.
-10 points: Encountering a burglar.
3. Random Events
Burglar Challenge:
Random burglar appearances deduct points from the player's score.
Earthquake Debugging:
Debugging challenges where players must fix C++ code snippets.
Correct debugging stabilizes the building; failure resets progress.
4. Visuals and Interactions
Console Art: Floors visualized as stacked rectangles.
Highlighted Floors: Current floor distinctly highlighted.
Real-time Updates: Player’s position and progress displayed.
5. Narrative and Immersion
Storyline:

Players are trapped in a mysterious building and must collect materials to build a parachute for escape.
Sub-stories for each level add motivation and immersion.
Console Effects:

Visuals and sound effects create an engaging, accessible experience.
6. Save and Load System
Automatic Save: Progress, score, and current floor saved after each level.
Load Game: Resume from the last saved state with retained score.
7. Advanced Elements
Maze Generation: Custom-designed mazes for each level.
Debugging Mode: Advanced players debug real C++ code snippets.
8. Educational Value
Interactive Question Bank:
Randomized C++ questions (multiple-choice, fill-in-the-blank).
Topics include syntax, loops, functions, arrays, and more.

Data Structures and Technical Implementation
Proposed Data Structures
Structs:
Question:

string questionText: Stores the question.
string correctAnswer: Holds the correct answer.
vector<string> options: Stores multiple-choice options.
Floor:

int floorNumber: Identifier for the floor.
char layout[GRID_SIZE][GRID_SIZE]: Defines the maze layout.
vector<Door>: Holds doors on the floor.
Door:

int x, y: Door’s position.
bool hasKey: Indicates if the door hides a key.
Technical Details
Programming Language: C++
Graphics: Console-based visuals for simplicity and accessibility.
Question Storage: Arrays or external files store level-specific questions.
Standard Libraries Used
<iostream>: Input/output operations.
<fstream>: File handling (save/load functionality).
<cstdlib>, <ctime>: Random number generation.
<conio.h>, <windows.h>: Real-time input and console manipulation (Windows-specific).
<vector>, <string>, <algorithm>, <chrono>, <thread>: General-purpose utilities.

Modules and Their Functions
Game Initialization:

Loads saved progress, initializes structures, and sets up the score.
Building Generation:

Creates floors with doors, windows, and walls.
Maze Navigation:

Manages player movement and maze interactions.
Question System:

Displays C++ challenges.
Validates answers and adjusts scores.
Random Events:

Introduces events like burglars and earthquakes.
Adjusts rewards and difficulty dynamically.
Score Management:

Tracks and updates scores in real-time.
Save and Load:

Saves game state to a file and retrieves it upon loading.
Display System:

Shows building layout, maze, score, and menus.

How to Play
Use WASD keys to navigate mazes.
Solve C++ questions to unlock doors and find keys.
Avoid obstacles and complete levels to win.
Save your progress to resume later.

Future Improvements
Add new levels focusing on advanced C++ topics.
Implement a leaderboard for competitive gameplay.
Introduce dynamic maze generation for infinite replayability.
AI Integration: Add AI-driven question difficulty adjustments based on player performance.

Technical Architecture

![PROJECT-ARCHITECTURE](https://github.com/sarafaw/FOCP-PROJECT/blob/main/project-architecture-focp.jpg?raw=true)

         The Tower of Odyssey: User Guide for Running and Deployment 
 
Introduction 
The Tower of Odyssey is an engaging, console-based game that challenges players with C++ programming puzzles as they ascend through seven levels of a mysterious building. Each level presents unique gameplay mechanics, such as randomized questions, penalties for mistakes, and exciting events like burglar chases and earthquakes. 
 
Prerequisites 
Required Software: 
Operating System: Compatible with Windows
C++ Compiler: Recommended options include GCC, Clang, or MSVC. 
Code Editor/IDE: Visual Studio, or Visual Studio Code are suggested for ease of use. 
Basic Knowledge: 
Familiarity with compiling and executing C++ programs. 
Understanding file input/output operations for save/load functionality. 
 
Installation Steps 
Download the Game Files: 
Obtain the source code and associated files from the official repository or shared link. 
Ensure all required files are in a single directory. 
Prepare the Environment: 
Install a suitable C++ compiler and editor if not already available. 
 
Building the Game 
Open a terminal or Command Prompt. 
Navigate to the game directory. 
Compile the game (we used visual studio to compile the games code) 
Ensure there are no errors during compilation. Resolve issues if any arise. 
Running the Game 
After successful compilation, execute the game: 
 
On Windows, double-click the executable or run it through Command Prompt. (using the link for GitHub) 
Follow the instructions displayed on the screen to start your journey. 
 
Gameplay Features 
Main Menu: 
Options include New Game, Load Game, Help, Instructions and Exit. 
Progress is saved automatically after completing each level. 
Navigating the Building: 
Floors are represented visually as stacked rectangles in the console. 
Use WASD keys to move your character through each maze. 
Puzzle Mechanics: 
Solve C++ programming questions to unlock doors and find the hidden key. 
Hitting windows result in point deductions. 
Random Events: 
Burglar Alert: Burglar causes loss in points. 
Earthquakes: Debug code challenges to stabilize the building. 


 
Scoring System 
Points are awarded for correct answers and successful actions. 
Penalties apply for mistakes or failing random events. 
 
Testing the Game 
Component Testing: 
Verify door unlocking and window penalties by navigating the maze. 
Test burglar and earthquake events to ensure triggers
Confirm scoring logic updates accurately for all actions. 
Validate save/load functionality by resuming progress from a saved state. 
Debugging Tips: 
Use debug statements to identify issues during development. 
Check compiler warnings and fix potential code issues before running. 
 
Deploying the Game 
Packaging: 
Compile the game into a standalone executable. 
Include all necessary files (e.g., resource files, question banks) in a compressed ZIP folder. 
Distribution: 
Share the ZIP file via GitHub, direct links. 
Include a README file containing a project title, group members, short project description, features, technical architecture, and detailed documentation on how to run and deploy your project.
 
Conclusion 
This guide provides all the information needed to run, test, and deploy The Tower of Odyssey. By following the steps outlined, players and developers can enjoy a seamless experience. For updates or support, refer to the official project repository.




