#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  char letter;
  int count;
} lettercount;

int getIndex(char *line, size_t nread) {
  int index;
  for (int i = 0; i < nread; i++) {
    line[i] = index;
  }
  printf("%d", index);
  return index;
}

void doInsertion(char *line, size_t len, size_t nread) {
  char *grid[nread];
  char *sortedGrid[nread]; 

  getIndex(line, nread);
  // getClusters();
  //put clusters in last of grid
  // insertionSort();// put sorted in first col of grid
  // findNext();
  // getOriginalInput();
}

int getOriginalStringSize(char *line) {
  int count = 0;
  while (*line) {
    int digits = atoi(line);
    count += digits;
    line += (digits / 10) + 1;
  }
  return count;
}

void parseLetterCount(char *line, lettercount grid[], int gridSize) {
  bool parseChar = 1;
  int i = 0;
  while (*line) {
    if (parseChar) {
      int digits = atoi(line);
      grid[i].count = digits;
      line += (digits / 10) + 1;
    } else {
      grid[i].letter = *line;
      line++;
      i++;
    }
    parseChar = !parseChar;
  }
}

void printGrid(lettercount grid[], int gridSize) {
  for (int i = 0; i < 8; i++) {
    printf("this is the count: %d\n", grid[i].count);
    printf("this is the letter: %c\n", grid[i].letter);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("argument missing");
    return(-1);
  }

  char *line = 0;
  size_t len = 0;
  size_t nread;
  int index = 0;
  bool parseIndex = 1;
         
  while ((nread = getline(&line, &len, stdin)) != -1) {
    if (parseIndex) {
      index = atoi(line);
    } else {
      int size = getOriginalStringSize(line);
      lettercount grid[size];
      parseLetterCount(line, grid, size);
      printGrid(grid, nread);
    }
    parseIndex = !parseIndex;
  }
  free(line);
}
        
                                                                                       
