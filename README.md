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




