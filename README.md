# DATA-COMPRESSION-TOOL

COMPANY:CODETECH IT SOLUTIONS

NAME:PUJA RANI

INTERN ID::CT04DN1860

DOMAIN:C LANGUAGE

DURATION:4 WEEKS

MENTOR:NEELA SANTOSH


This C program is a tool that implements a simple Run-Length Encoding (RLE) algorithm to compress and decompress text files. Run-Length Encoding is a lossless data compression technique in which consecutive characters (or symbols) in the input data are stored as a single data value and count. The program provides an interactive interface where the user can choose to either compress or decompress a file using this technique.

Key Components of the Program:
Header Files:

<stdio.h>: This library is used for input and output operations, including file handling (opening, reading, writing).

<stdlib.h>: This library provides functions like exit(), atoi(), and dynamic memory management functions. The program uses exit(1) to terminate the program when an error occurs.

<string.h>: This library offers string manipulation functions like fgets(), strcspn(), and others used in the program for handling input strings.

<ctype.h>: This is used to handle character classification. In this program, it's particularly useful for identifying if a character is a digit or not.

Main Functionality:
The core functionality of this program is split into two main operations: compression and decompression, each handled by a dedicated function.

Compression: The compressFile() function compresses a text file by replacing consecutive repeated characters with the character followed by its count. For example, if the string is "aaabbbcc", it will be compressed into "3a3b2c".

Decompression: The decompressFile() function restores the compressed file back to its original form. For example, it will convert "3a3b2c" back into "aaabbbcc".

Compression Process:

The compressFile() function starts by opening the input file in read mode and the output file in write mode.

It reads the file character by character, keeping track of consecutive characters and their count.

If the current character is the same as the previous one, the count is incremented. If it's different, the current count and character are written to the output file, and the count is reset.

After the loop ends, the final character count pair is written to the file.

The files are then closed, and the program prints a message indicating that the compression is complete.

Decompression Process:

The decompressFile() function also opens the input and output files.

It reads the file character by character. When it encounters a digit, it adds it to a buffer. When a non-digit character is encountered, the program assumes the previous buffer contains the count (number of occurrences) of that character.

The count is converted to an integer using the atoi() function, and that character is written to the output file the number of times specified by the count.

The process continues until the end of the input file is reached.

Once the decompression is complete, the files are closed, and a success message is displayed.

User Interaction:

The program starts by printing a simple text interface that allows the user to choose between compressing or decompressing a file.

The user is prompted to enter the names of the input and output files.

The program then proceeds based on the user’s choice (either compression or decompression), calling the appropriate function and providing feedback on the operation.

Error Handling:

In both compressFile() and decompressFile() functions, the program checks if the files have been successfully opened using fopen(). If either the input or output file cannot be opened (e.g., due to incorrect file paths or lack of permissions), the program prints an error message and exits.

The program also checks for invalid user input (e.g., entering a number other than 1 or 2 when asked for a choice).

How the Program Works:
Compressing a File:

The program reads each character from the input file and counts how many times consecutive characters appear. Once a different character is encountered, it writes the count and the previous character to the output file. This process continues until the entire input file is processed. For example:

Input: "aaabbbcc"

Output: "3a3b2c"

Decompressing a File:

The program reads the compressed file and converts each character count pair back into the original repeated characters. For example:

Input: "3a3b2c"

Output: "aaabbbcc"

Advantages of Run-Length Encoding:
Space Efficiency: For files with a lot of repetitive data, RLE can significantly reduce the file size. This is particularly useful for images and simple text files.

Simplicity: RLE is one of the simplest compression algorithms and easy to implement, making it a good choice for basic compression tasks.

Limitations of Run-Length Encoding:
Inefficiency for Non-Repetitive Data: If the data doesn't have many consecutive repeating characters, RLE may not reduce the file size and could even increase it. For example, in a file with no repetitions, RLE would essentially just store the original file with the character count 1 for each character.

Conclusion:
This program is an excellent example of how simple compression techniques like Run-Length Encoding can be implemented in C. It provides an efficient and user-friendly way to compress and decompress text files, with error handling to ensure smooth operation. For internships or beginner programmers, it is an ideal project that demonstrates core concepts like file I/O, string manipulation, and algorithm design.

OUTPUT:

![Image](https://github.com/user-attachments/assets/cb3aaa81-ee83-4514-828a-eb99bfc64752)


