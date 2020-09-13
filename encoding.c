#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char letter;
  int count;
} lettercount;

void createGrid(char input[], char *grid[], int n) {  // Populates 2D array
  for (int j = 0;j < n;j++) {
    for (int k = 0;k < n;k++) {
      grid[j][(k-j+n)%n] = input[k];
    }
  }
}

void printArray(char arr[], int n) { 
  int i;
  for (i = 0; i < n; i++) 
    printf("%c", arr[i]);
  printf("\n");
}  

void insertionSort(char *sortedGrid[], int n) { 
  int i, j; 
  char *key;
  for (i = 1; i < n; i++) { 
    key = sortedGrid[i];
    j = i - 1; 

    while (j >= 0 && strncmp(sortedGrid[j], key, n) > 0) { 
      sortedGrid[j + 1] = sortedGrid[j];
      j = j - 1; 
    } 
    sortedGrid[j + 1] = key;
  } 
}

void quickSort(char *sortedGrid[], int first, int last) {
  int i, j, pivot;
  char *temp;

  if (first < last) {
    pivot = first;
    i = first;
    j = last;

    while (strcmp(sortedGrid[i], sortedGrid[j]) > 0) {
      while (strcmp(sortedGrid[i], sortedGrid[pivot]) >= 0 && i < last)
        i++;
      while (strcmp(sortedGrid[j], sortedGrid[pivot]) > 0)
        j--;
      if (strcmp(sortedGrid[i], sortedGrid[j]) > 0) {
        temp = sortedGrid[i];
        sortedGrid[i] = sortedGrid[j];
        sortedGrid[j] = temp;
      }
    }

    temp = sortedGrid[pivot];
    sortedGrid[pivot] = sortedGrid[j];
    sortedGrid[j] = temp;
    quickSort(sortedGrid, first, j-1);
    quickSort(sortedGrid, j+1, last);
  }
}


int findInput(char *input, char *grid[], int n) {
  for (int i = 0;i < n;i++) {
    int pos = strncmp(grid[i], input, n);
    if (pos == 0) {
      return i;
    }
  }
  return -1;
}

void makeCluster(char *grid[], int n) {
  char lastKnownChar = 0;
  int clusterIndex = -1;

  lettercount cluster[n];
  memset(cluster, 0, sizeof(cluster));

  for (int i = 0; i < n; i++) {
    if (lastKnownChar == 0 || lastKnownChar != grid[i][n - 1]) {
      clusterIndex++;
      lastKnownChar = grid[i][n - 1];
      cluster[clusterIndex].letter = lastKnownChar;
      cluster[clusterIndex].count = 1;
    } else {
      cluster[clusterIndex].count++;
    }
  }
  for (int m = 0; m < n && cluster[m].letter != 0; m++) {
    printf("%d%c", cluster[m].count, cluster[m].letter);
  }
  printf("\n");
}

/*void printCluster(lettercount cluster[BUFFER_SIZE], int n) {
  for (int i = 0; cluster[i].letter != 0; i++) {
    printf("%d%c", cluster[i].count, cluster[i].letter);
  }
  printf("\n");
}*/

void printGrid(char *grid[], int n) {
  int j, k;
  for(j=0;j<n;j++) {
    for(k=0;k<n;k++) {
      printf("%c ", grid[j][k]); // printing 2D array
    }
    printf("\n");
  }
}   

void printSortedGrid(char *grid[], int n) {
  int j;
  for(j=0;j<n;j++) {
    printf("%s\n", grid[j]); // printing 2D array
  }
}   

char *replaceChar(char *str, char find, char replace) {
  char *currentPos = strchr(str, find);
  while (currentPos) {
    *currentPos = replace;
    currentPos = strchr(currentPos, find);
  }
  return str;
}

void doInsertion(char *line, size_t nread) {
  char *grid[nread];
  char *sortedGrid[nread];
  char input[nread];

  for (int i = 0; i < nread; i++) {
    grid[i] = malloc(nread + 1);
    sortedGrid[i] = grid[i];
  }

  for (int m = 0; m < nread; m++) {
    input[m] = line[m];
  }
  int n = nread - 1;

  createGrid(input, grid, n); // <- I can't seem to figure out how to get rid of this warning
  insertionSort(sortedGrid, n);
//  printSortedGrid(sortedGrid, n);
  int newPosition = findInput(input, sortedGrid, n);
  printf("%d\n", newPosition);
  makeCluster(sortedGrid, n);

//  printf("%d\n", newPosition);
//  printCluster(cluster, n);
  for (int i = 0; i < nread; i++) {
    free(grid[i]);
  }
}

void doQuick(char *line, size_t nread) {
  char *grid[nread];
  char *sortedGrid[nread];
  char input[nread];

  for (int i = 0; i < nread; i++) {
    grid[i] = malloc(nread + 1);
    sortedGrid[i] = grid[i];
  }

  for (int m = 0; m < nread; m++) {
    input[m] = line[m];
  }
  int n = nread - 1;

  createGrid(input, grid, n);
  quickSort(sortedGrid, 0, n-1);
  /* printSortedGrid(sortedGrid, n); */
  int newPosition = findInput(input, sortedGrid, n);
  printf("%d\n", newPosition);
  makeCluster(sortedGrid, n);

//  printf("%d\n", newPosition);
//  printCluster(cluster, n);
  for (int i = 0; i < nread; i++) {
    free(grid[i]);
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

  while ((nread = getline(&line, &len, stdin)) != -1) {
    if (nread != 1) {
      
      if (0 == strcmp(argv[1], "insertion")) {
        doInsertion(line, nread);
      }
      if (0 == strcmp(argv[1], "quick")) {
        doQuick(line, nread);
      }
    } else {
      printf("\n\n");
    }
  }
  free(line);
}



/*
 * 1. Quick sort - written out but not working - 
 * 2. Accept and check command line parameters - DONE
 * 3. Multi-line file - DONE - DONE even better 
 * 4. Empty line in the file - DONE 
 * 5. Make dynamic - 
 * 6. Makefile - 
 *
 * 0
 * 1 i 1 p 2 s 1 M 1 p 1 i 2 s 2 i
 *
 * 0
 * 1 a 1 m 1 l 1 b 1 a 1 A 1 a
 *
 */
