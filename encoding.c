#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void leftRotatebyOne(char arr[], int n) {   // Shifts array
  int temp = arr[0], i; 
  for (i = 0; i < n - 1; i++) 
    arr[i] = arr[i + 1]; 
  arr[i] = temp; 
}

void createGrid(char input[], char grid[][BUFFER_SIZE], int n) {  // Populates 2D array
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

void sortGrid(char arr[][BUFFER_SIZE], int n) { 
  int i, j; 
  char key[BUFFER_SIZE];
  for (i = 1; i < n; i++) { 
    strncpy(key, arr[i], n);
    j = i - 1; 

    while (j >= 0 && strncmp(arr[j], key, n) > 0) { 
      strncpy(arr[j + 1], arr[j], n);
      j = j - 1; 
    } 
    strncpy(arr[j + 1], key, n);
  } 
} 

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
  char input[BUFFER_SIZE] = {'y','e','t','i','\0'};

  n = strlen(input);

  createGrid(input, grid, n);
  sortGrid(grid, n);
  printGrid(grid, n);
}
