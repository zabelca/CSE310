#include <stdio.h>
#include <string.h>

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

void createGrid(char input[], char grid[][256], int n) {  // Populates 2D array
  int i = 0;
  int k;
  int shift = 1;
  for (int j = 0;j < n;j++) {
    for (k = 0;k < n;k++) {
      grid[j][k] = input[i++];
    }
    leftRotate(input, shift, n);
  }
}

void printArray(char arr[], int n) { 
  int i;
  for (i = 0; i < n; i++) 
    printf("%c", arr[i]);
  printf("\n");
}  


/* void sortGrid(char grid[][256], int n) { */  
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

/* void makeClusters(char sortedGrid[][256], int n) { */
/*   int clusters[256]; */
/*   int j, i; */
/*   for (j = 0;j < n;j++) { */
/*     if (sortedGrid[j][n-1] == sortedGrid[j + 1][n - 1]) { */
      
/*     clusters[i] = sortedGrid[j][n-1]; */
/*     i++; */
/*   } */
/* } */

void printClusters(char sortedGrid[][256]) {
  
}

void printGrid(char grid[][256], int n) {
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
  char grid[256][256];
  char arr[256];

  fgets(arr, 256, stdin);
  n = strlen(arr);

  createGrid(arr, grid, n);
  printGrid(grid, n);
  /* int b; */
  /* for (b = 0;b < n;b++) { */
  /*   sortGrid(grid,n); */
  /* } */
}
