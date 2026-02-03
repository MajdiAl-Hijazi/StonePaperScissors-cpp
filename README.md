# Stone-Paper-Scissors Game in C++

This repository contains **two C++ implementations** of the classic game **Rock-Paper-Scissors**.  
Both files implement the same game logic but differ in coding style and structure.  
This project was developed for the course **Algorithms & Problem-Solving – Level 2** with Dr. Abu Hadhoud.

## Overview of the Two Files

### File 1
- Uses **enums** for the choices (Stone, Paper, Scissors).  
- The computer makes a random choice using `RandomNumber()`.  
- `ProcessRound()` determines the winner of each round and changes the screen color according to the result.  
- `DisplayRound()` shows the choices and winner for each round.  
- The player can choose the number of rounds (1-10).  
- The game displays the number of wins for the player, the computer, the number of draws, and the final winner.

### File 2
- Uses **enums** and **structs** (`stRoundInfo` for each round and `stGameResults` for the whole game).  
- Functions are more modular and organized: reading input, computing computer choice, determining winner, printing results.  
- Displays results for each round neatly using tabs for alignment.  
- Changes screen color only for the final winner.  
- Easier to extend and maintain due to structured programming.

## Key Differences Between the Two Files

| Feature                  | File 1                 | File 2                        |
|--------------------------|----------------------|-------------------------------|
| Data Organization        | Enums only           | Enums + Structs               |
| Functions                | Few, some long       | Many small, modular functions |
| Screen Color             | Changes every round  | Only final winner             |
| Display                  | Simple, direct       | Neat, aligned with tabs       |
| Extensibility            | Harder to extend     | Easier with structs           |

## How to Run

1. Download the `.cpp` file.  
2. Open it in a C++ IDE (Visual Studio, Code::Blocks, VS Code with C++ compiler, etc.).  
3. Compile and run the program.  
4. Enter the number of rounds you want to play (1-10).  
5. Choose your option each round: Stone, Paper, or Scissors.  
6. The program will display the winner of each round and the final game result.

---
<div align="center">

<h2>Majdi Al-Hijazi</h2>
<p>💻 Computer Information Systems (CIS) Student</p>

<br>

<a href="https://github.com/MajdiAl-Hijazi" target="_blank">
  <img src="https://cdn-icons-png.flaticon.com/512/25/25231.png" width="40" />
</a>

<a href="https://www.linkedin.com/in/majdi-alhijazi-274947334" target="_blank">
  <img src="https://cdn-icons-png.flaticon.com/512/174/174857.png" width="40" />
</a>

<a href="mailto:majdialhijazi@gmail.com">
    <img src="https://img.icons8.com/color/48/000000/gmail.png" alt="Email" width="40"/>

</div>
