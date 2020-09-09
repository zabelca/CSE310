#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void leftRotatebyOne(char arr[], int n) {   // Shifts array
  int temp = arr[0], i; 
  for (i = 0; i < n - 1; i++) 
    arr[i] = arr[i + 1]; 
  arr[i] = temp; 
}

void leftRotate(char arr[], int shift, int n) { 
  int i; 
  for (i = 0; i < shift; i++)     // Determines how many shifts
    leftRotatebyOne(arr, n); 
}

void createGrid(char input[], char grid[][BUFFER_SIZE], int n) {  // Populates 2D array
  /* int i = 0; */
  /* int shift = 1; */
  for (int j = 0;j < n;j++) {
    for (int k = 0;k < n;k++) {
      grid[j][(k-j+n)%n] = input[k];
    }
    /* leftRotate(input, shift, n); */
  }
}

void printArray(char arr[], int n) { 
  int i;
  for (i = 0; i < n; i++) 
    printf("%c", arr[i]);
  printf("\n");
}  


/* void sortGrid(char grid[][BUFFER_SIZE], int n) { */  
/*   int i, key, j; */
/* //  for (int m = 0;m < n;m++) { */
/*     for (i = 0;i < n;i++) { */
/*       key = grid[i][k]; */
/*       j = i - 1; */
/*       while (j >= 0 && grid[j][k] > key) { */
/*         grid[j + 1][k] = grid[j][k]; */
/*         j = j - 1; */
/*       } */
/*       grid[j + 1][k] = key; */
/*     } */
/* //  } */
/* } */

/* void makeClusters(char sortedGrid[][BUFFER_SIZE], int n) { */
/*   int clusters[BUFFER_SIZE]; */
/*   int j, i; */
/*   for (j = 0;j < n;j++) { */
/*     if (sortedGrid[j][n-1] == sortedGrid[j + 1][n - 1]) { */
      
/*     clusters[i] = sortedGrid[j][n-1]; */
/*     i++; */
/*   } */
/* } */

void printClusters(char sortedGrid[][BUFFER_SIZE]) {
  
}

void printGrid(char grid[][BUFFER_SIZE], int n) {
  int j, k;
  for(j=0;j<n;j++) {
    for(k=0;k<n;k++) {
      printf("%c ", grid[j][k]); // printing 2D array
    }
    printf("\n");
  }
}   

int main() {
  int n;
  char grid[BUFFER_SIZE][BUFFER_SIZE];
  char input[BUFFER_SIZE] = {'a','b','c','d','\0'};

  /* fgets(input, BUFFER_SIZE, stdin); */
  n = strlen(input);

  createGrid(input, grid, n);
  printGrid(grid, n);
  /* int b; */
  /* for (b = 0;b < n;b++) { */
  /*   sortGrid(grid,n); */
  /* } */
}
