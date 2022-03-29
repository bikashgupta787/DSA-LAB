#include <iostream.h>
#include <stdio.h>
#include <conio.h>
 
void bubblesort(float[], int);
void insertionsort(float[], int);
void selectionsort(float[], int); 
 
void print(float[], int);
void read(float[], int);
 
void main() {
  char wtc = 'y';
  while (wtc == 'y' || wtc == 'Y') {
    clrscr();
    int choice, n;
    float a[200];
    printf("Enter the size of array");
    scanf("%d", & n);
    printf("\n");
    printf("Enter %d integers of array", n);
 
    read(a, n);
    printf("\n Enter the following numbers to use the following techniques:\n");
    printf("\t1.BUBBLE SORT\n");
    printf("\t2.INSERTION SORT\n");
    printf("\t3.SELECTION SORT\n");
 
    printf("\n");
    printf("Enter your choice");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      {
        bubblesort(a, n);
        print(a, n); //calling funtion by using switch statements
        getch();
        break;
      }
    case 2:
      {
        insertionsort(a, n);
        print(a, n);
        getch();
        break;
      }
    case 3:
      {
        selectionsort(a, n);
        print(a, n);
        getch();
        break;
      }

    }
    
    printf("\n\n Do you want to continue(y/n)");
    scanf("%d",&wtc);
  }
  return 0;
}
 
void read(float a[], int n) {
  for (int i = 0; i < n; i++) {
    //printf(a[i]);
  }
}
 
//Bubble sort implementation
void bubblesort(float a[], int n) {
  for (int p = 0; p < (n - 1); p++) {
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        float temp;
        temp = a[i + 1];
        a[i + 1] = a[i];
        a[i] = temp;
      }
    }
  }
}
 
//Insertion sort implementation
void insertionsort(float a[], int n) {
  for (int i = 1; i < n; i++) {
    float x = a[i];
    int j = i;
    while (j > 0 && a[j - 1] > x) //definition of insertion sort
      a[j--] = a[j - 1];
    a[j] = x;
  }
}
 
//Selection sort implementation
void selectionsort(float a[], int n) {
  for (int i = 0; i < n; i++) {
 
    for (int j = i + 1; j <= n - 1; j++)
      if (a[i] > a[j]) {
        float temp;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
  }
}
 
void print(float a[], int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d",&a[i]);
  }
  //cout << endl;
}
