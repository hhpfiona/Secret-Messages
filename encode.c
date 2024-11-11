#include <stdio.h>
#include <stdlib.h>

#include <string.h>  // Only used for strlen

#define MAXLINE 256

// Error messages
#define USAGE "Usage: encode chunksize textfile msg\n"
#define ENCODE_FAILED "Could not encode message.\n"


int main(int argc, char *argv[]) {
    // Check to make sure the user entered the correct number of arguments
    if(argc != 4) { 
        fprintf(stderr, USAGE);
        exit(1); 
        // The argument of 1 is a convention indicating the program failed
    }

    FILE *text_fptr; // File pointer for the text document

    // determine message chunks size
    int chunk_size = strtol(argv[1], NULL, 0);  
    if(chunk_size == 0) {
        fprintf(stderr, "Invalid chunk size\n");
        exit(1);
    }
    
    if((text_fptr = fopen(argv[2], "r")) == NULL) {
        perror("fopen");
        exit(1);
    }
    
    // The message to encode is in argv[3].  We will use a pointer to char
    // to give it a better name.
    char *message = argv[3];
    int msg_length = strlen(message);  // only allowed use of string functions
    
    // Complete the implmentation below

    char text_line[MAXLINE];


    int m = 0;
    int line_counter = 0;
    while (fgets(text_line, MAXLINE, text_fptr) != NULL) {
        for (int i=0; i < (int)strlen(text_line) - chunk_size; i++) {
            if (text_line[i] == message[m] && text_line[i + 1] == message[m + 1] && text_line[i + 2] == message[m + 2]) {
                    printf("%d %d %d", line_counter, i, chunk_size);
                    printf("\n");
                    m += 3; 
                    break;
            };
        }
        line_counter++; 
    }
    

    if (m < msg_length - 3) {
        fprintf(stderr, ENCODE_FAILED);
        exit(1);
    }


    fclose(text_fptr);
    return 0;
}
