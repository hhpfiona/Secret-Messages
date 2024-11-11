#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

// Error messages 
// These are the only error messages that your code should print.
// All error messages must be printed to stderr.
#define USAGE "Usage: decode textfile codefile\n"
#define INVALID_LINE "Invalid line number\n"
#define EMPTY "Document is empty\n"
#define INVALID_POSITION "Invalid character position for this line\n"
#define LENGTH "Invalid chunk size"


int main(int argc, char **argv) {
    // If the user did not enter the correct number of arguments then exit
    if(argc != 3) { 
        fprintf(stderr, USAGE);
        exit(1); 
        // The argument of 1 is a convention indicating the program failed
    }

    FILE *text_fptr; // File pointer for the text document
    FILE *code_fptr; // File pointer for the code file


    // Open both files for reading. Terminate if there is any problem 
    //  opening the files 
    if((text_fptr = fopen(argv[1], "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    if((code_fptr = fopen(argv[2], "r")) == NULL) {
        perror("fopen");
        exit(1);

    }

    // We will assume that lines read from the text file and the code file
    // will never exceed MAXLINE-1 characters.
    char text_line[MAXLINE];
    
    // Add your implementation below.

    int line, start, chunk;
    int line_counter = 0;

    while (fscanf(code_fptr, "%d %d %d", &line, &start, &chunk) == 3) {
        if (line < line_counter) {
            fprintf(stderr, INVALID_LINE);
            exit(1);
        }

        while (line_counter <= line) {
            if (fgets(text_line, MAXLINE, text_fptr) == NULL) {
                fprintf(stderr, EMPTY);
                exit(1);
            } 
            line_counter++;
        }

        int char_counter = 0;
        
        while (text_line[char_counter] != '\0') {
            if (start - 1 < char_counter && char_counter < start + chunk) {
                printf("%c", text_line[char_counter]);
            }
            char_counter++;
        }
        if (start > char_counter) { 
            fprintf(stderr, INVALID_POSITION);
            exit(1);
        } else if (start + chunk > char_counter) { 
            fprintf(stderr, LENGTH);
            exit(1);
        }
    }
    

    // Print a newline after the end of the message so the prompt appears on 
    // the next line.
    printf("\n");
    fclose(text_fptr);
    fclose(code_fptr);

    return 0;   
}
