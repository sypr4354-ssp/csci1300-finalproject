# csci1300-finalproject
cs final project
# CSCI 1300 Final Project

## Theme
The game is a text-based strategy RPG thing set in the Marvel Universe where you basically get to play as a S.H.I.E.L.D. director. You have to manage resources, defend your operational bases, and deploy different Avengers to deal with universal threats before things get completely wrecked. You have to keep an eye on your energy shield metrics while picking the best hero for different planetary missions so you don't lose.

## Goal
Complete the primary operational missions and keep the global S.H.I.E.L.D. base shields from crashing before your tactical turns run out.

## How to compile and run
```bash
g++ -std=c++17 -Wall -Werror main.cpp Character.cpp Avenger.cpp Game.cpp -o marvel_game
./marvel_game
'''
