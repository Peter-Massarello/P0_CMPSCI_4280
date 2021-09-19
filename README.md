# Project 0

Name:        Peter Massarello
Date:        September 20th 2021
Class:       CMPSCI 4280
Professor:   Mark Hauschild
Assignment:  P0 (written in C++)

How to build:
    - CD to main_files directory (command: cd main_files)
    - run make file to compile all files (command: make)

How to run:
    - ./P0 [filename] 
        - Contains optional argument "filename". If run without optional arg, takes input from stdin, otherwise reads from "filename"
    
    - ./P0 < somefile
        - Acts the name as the no argument implementation except the stdin input is taken from the files contents instead of the keyboard

How to cleanup:
    - run make clean to remove all program created files (command: make clean)

Code similarities:
    - A major resource used was geeksforgeeks.org for implementations of BST in C++. While code is not a direct copy from there, it is very similar.
    - StackOverflow was used for question I had pertaining to file reading/writing. Mainly the while loops I used came from there.

Notes:
    - Instructions given said that all input would be clean and deal with only alphanumeric characters. So there is no validation on reading other symbols.
    - A test file for the optional argument is supplied but if the grader wants to they can use their own.
