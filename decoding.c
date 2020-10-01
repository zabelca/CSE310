#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  char letter;
  int count;
} lettercount;

void insertionSort(char *grid[], int n) { 
  int i, j; 
  char key;
  for (i = 1; i < n; i++) { 
    key = grid[i][0];
    j = i - 1; 

    while (j >= 0 && grid[j][0] > key) { 
      grid[j + 1][0] = grid[j][0];
      j = j - 1; 
    } 
    grid[j + 1][0] = key;
  } 
}

void quickSort(char *grid[],int first,int last) {
  int i, j, pivot;
  char temp;

  if (first < last) {
    pivot = first;
    i = first;
    j = last;

    while (i < j) {
      while (grid[i][0] <= grid[pivot][0] && i < last)
        i++;
      while (grid[j][0] > grid[pivot][0])
        j--;
      if (i < j) {
        temp = grid[i][0];
        grid[i][0] = grid[j][0];
        grid[j][0] = temp;
      }
    }

    temp = grid[pivot][0];
    grid[pivot][0] = grid[j][0];
    grid[j][0] = temp;
    quickSort(grid, first, j - 1);
    quickSort(grid, j + 1, last);
  }
}

int getOriginalStringSize(char *line) {
  int count = 0;
  do {
    if (*line != ' ') {
      int digits = atoi(line);
      count += digits;
      line += (digits / 10);
    }
  } while (*line++ && *line++); // advance `line` two characters, checking each for '\0'
  return count;
}

void createCluster(char *line, lettercount cluster[], int gridSize) {
  bool parseNumber = true;
  int i = 0;
  do {
    if (parseNumber) {
      int digits = atoi(line);
      cluster[i].count = digits;
      line += (digits / 10);
    } else {
      cluster[i].letter = *line;
      i++;
    }
    parseNumber = !parseNumber;
  } while (*line++ && *line++); // advance `line` two characters, checking each for '\0'
}

void createGrid(lettercount clusters[], char *grid[], int size) {
  lettercount *cluster = clusters;
  int i = 0;

  while (cluster->letter && i < size) {
    for (int j = 0; j < cluster->count; j++) {
      grid[i][0] = cluster->letter;
      grid[i][size-1] = cluster->letter;
      i++;
    }
    cluster++;
  }

//  insertionSort(grid, size);

 // for (int a=0; a<size; a++) {
 //   printf("%c %c\n", grid[a][0], grid[a][size-1]);
 // }
}

int findNext(char *grid[], int gridSize, int i) {
  char firstChar;
  firstChar = grid[i][0];
  for (int m = 0; m < gridSize; m++) {
    if (firstChar == grid[m][gridSize-1]) {
      grid[m][gridSize-1] = 0;
      return m;
    }
  }
  return -1;
}

void getOriginalString(int index, char *grid[], int gridSize, char *original, int origStringSize) {
  int next[gridSize];
  for (int i = 0; i < gridSize; i++) {
    next[i] = findNext(grid, gridSize, i);
  }
  for (int m = 0; m < gridSize; m++) {
    original[m] = grid[index][0];
    index = next[index];
  }
  original[origStringSize - 1] = '\0';
}


void printGrid(char *grid[], int n) {
  int j;
  for(j=0;j<n;j++) {
    printf("%s\n", grid[j]); // printing 2D array
  }
}   

void printCluster(lettercount cluster[], int n) {
  for (int i = 0; cluster[i].letter != 0; i++) {
    printf("%d%c", cluster[i].count, cluster[i].letter);
  }
  printf("\n");
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
  bool parseIndex = true;
         
  while ((nread = getline(&line, &len, stdin)) != -1) {
    if (0 == strcmp(argv[1], "insertion")) {
      if (parseIndex) {
        index = atoi(line);
      } else {
        int size = getOriginalStringSize(line);
        lettercount clusters[size];
        createCluster(line, clusters, size);
        //printCluster(clusters, size);
        char *grid[size];
        for (int i = 0; i < size; i++) {
          grid[i] = malloc(size);
          memset(grid[i], 0, sizeof(char) * (size));
        }
        //printf("%p\n", grid[1]);
        createGrid(clusters, grid, size);
        insertionSort(grid, size);
        char origString[size+1];
        getOriginalString(index, grid, size, origString, size+1);
        printf("%s\n", origString);
        for (int i = 0; i < size; i++) {
          free(grid[i]);
        }
      }
      parseIndex = !parseIndex;
    } else if (0 == strcmp(argv[1], "quick")) {
      if (parseIndex) {
        index = atoi(line);
      } else {
        int size = getOriginalStringSize(line);
        lettercount clusters[size];
        createCluster(line, clusters, size);
        char *grid[size];
        for (int i = 0; i < size; i++) {
          grid[i] = malloc(size);
          memset(grid[i], 0, sizeof(char) * (size));
        }
        //printf("%p\n", grid[1]);
        createGrid(clusters, grid, size);
        quickSort(grid, 0, size-1);
        char origString[size+1];
        getOriginalString(index, grid, size, origString, size+1);
        printf("%s\n", origString);
        for (int i = 0; i < size; i++) {
          free(grid[i]);
        }
      }
      parseIndex = !parseIndex;
    } else {
      printf("Invalid Argument");
    }
  }
  free(line);
}
        
                                                                                       
