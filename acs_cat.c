/**
 * Recreate basic cat program
 * 
 */
#include <stdio.h>
#include <stdlib.h> //realloc
#include <string.h> //strcat

void resetPointers(char **, int *);

int main(int argc, char **argv) {
    if (argc < 2) {
        exit(-1);
    }

    FILE *fp;
    char c;
    char *buffer = NULL;
    char *extra = NULL;
    int len = 0;
    
    fp = fopen(argv[1], "r");

    if (fp) {       
        do {  
            extra = realloc(buffer,(++len) +1);
            
            if (extra) {
                buffer = extra;
            }
            else {
                printf("No memory\n");
                exit(-1);
            }
            
            c = fgetc(fp);
            buffer[len-1] = c;
            buffer[len] = '\0';
                        
            if (c == '\n') {
                printf("%d\n",len);
                fputs(buffer, stdout);
                free(buffer);
                buffer = NULL;
                len = 0;
                //resetPointers(&buffer,&len);
            }            
        } while (c != EOF);

        if (len) {
            buffer[len-1] = '\0'; //remove EOF
            fputs(buffer,stdout);            
        }        
    }
}

void resetPointers(char **buffer, int *len) {    
    if (buffer) {
        free(*buffer);
        *buffer = NULL;    
    }
    *len = 0;
}
