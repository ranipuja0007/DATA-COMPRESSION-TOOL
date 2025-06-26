#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to compress the input file
void compressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("Error opening file.\n");
        exit(1);
    }

    char prev = fgetc(in);
    if (prev == EOF) {
        fclose(in);
        fclose(out);
        return;
    }

    int count = 1;
    char curr;
    while ((curr = fgetc(in)) != EOF) {
        if (curr == prev) {
            count++;
        } else {
            fprintf(out, "%d%c", count, prev);
            prev = curr;
            count = 1;
        }
    }
    fprintf(out, "%d%c", count, prev);

    fclose(in);
    fclose(out);
    printf("Compression complete.\n");
}


void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("Error opening file.\n");
        exit(1);
    }

    int ch;
    char buffer[20]; 
    int idx = 0;

    while ((ch = fgetc(in)) != EOF) {
        if (isdigit(ch)) {
            buffer[idx++] = ch;
        } else {
            buffer[idx] = '\0';
            int count = atoi(buffer);
            for (int i = 0; i < count; i++) {
                fputc(ch, out);
            }
            idx = 0;
        }
    }

    fclose(in);
    fclose(out);
    printf("Decompression complete.\n");
}


int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("Run-Length Encoding Tool\n");
    printf("1. Compress\n");
    printf("2. Decompress\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar(); 

    printf("Enter input file name: ");
    fgets(inputFile, sizeof(inputFile), stdin);
    inputFile[strcspn(inputFile, "\n")] = '\0'; 

    printf("Enter output file name: ");
    fgets(outputFile, sizeof(outputFile), stdin);
    outputFile[strcspn(outputFile, "\n")] = '\0';

    if (choice == 1) {
        compressFile(inputFile, outputFile);
    } else if (choice == 2) {
        decompressFile(inputFile, outputFile);
    } else {
        printf("Invalid choice.\n");
    }
       return 0;
}