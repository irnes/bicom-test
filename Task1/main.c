/* 
 * File:   main.c
 * Author: irnes
 *
 * Created on April 1, 2012, 8:53 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char* argv[])
{
    printf("Task1 (C Programm) - Irnes Mujkanovic\n");
    /*
    printf("| a | b | c | d |\n");
    printf("+---+---+---+---+\n");
    printf("| e | f |   | g |\n");
    printf("+---+---+   +---+\n");
    printf("| h |\n");
    printf("+---+\n");
    */

    // File containing test data
    char* filename = argv[1];

    FILE *fp = NULL;
    fp = fopen(filename, "r");

    // Make sure the file opened properly
    if(fp == NULL)
    {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return 1;
    }

    // Set up the buffer to read the line into
    int buff_size = 0;
    // the getline function allocates buffer
    char *buff; // = (char*)malloc(buff_size * sizeof(char));

    printf("Content of file: %s\n", filename);

    char delimiter_row[] = "+---+---+---+---+";

    // Read each line and print it to the screen
    int row_number = 0;
    while(getline(&buff, &buff_size, fp) != -1)
    {
        if(row_number == 0)
            printf("%s\n", delimiter_row);

        // clear previous content of delimiter_row
        memset((void *)&delimiter_row, '\0', sizeof(delimiter_row));

        int linelength = strlen(buff);
        int i;
        for(i = 0; i < linelength; i++)
        {
            // print every second character from row
            if((i % 2) == 0)
            {
                printf("| %c ", buff[i]);
                // compose row delimiter based on row content
                strcat(delimiter_row, "+");
                if(buff[i] == ' ')
                    strcat(delimiter_row, "   ");
                else
                    strcat(delimiter_row, "---");
            }

            // complete row delimiter
            if(i == linelength - 1)
            {
                printf("|\n");
                strcat(delimiter_row, "+");
            }
        }

        printf("%s\n", delimiter_row);

        // clear previos buffer content
        memset((void *)&buff, '\0', sizeof(buff));

        row_number++;
    }

    // Close the file and clean up the buffer when we're finished
    fclose(fp);
    free(buff);

    return 0;
}

