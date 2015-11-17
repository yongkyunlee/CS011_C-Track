#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "memcheck.h"

/* Signature Function */
int *initial_array(int num_element);
/*int update(int arr[], int num_element);*/
void print_arr(int arr[], int num_element);

/* This function generates the initial array of the 1d game of life.
The size of array is decided by the input integer.
The first and last cell are set to be empty, and all the other cells are
designated to be either full or empty randomly.
Arguments:
 n: the number of cells in the array
Return value: randomly generated array of cells */
int *initial_array(int num_element)
{
  int i, rand_num;
  int *arr;
  srand(time(0));
  /* initialize array to have num_element elements */
  arr = (int *)calloc(num_element, sizeof(int));
  /* Check that the calloc call succeeded */
  if (arr == NULL)
  {
    fprintf(stderr, "Error! Memory allocation failed\n");
    exit(1);
  }
  arr[0] = 0; /* first and last elements are empty */
  arr[num_element - 1] = 0;
  for (i = 1; i < num_element - 1; i++)
  {
    rand_num = rand() % 2; /* Generate either 0 or 1 */
    arr[i] = rand_num;
  }
  return arr;
}

/* Produce next generation of array of cells from the given array
Arguments:
 arr[] : input array that is base of the next generation
 int num_element : the number of cells in arr[]
Return value: the next generation produced from arr[] */
/*
int update(int arr[], int num_element)
{
  int *next_arr[num_element];
  int i;
*/
  /* The first and the last cells are always empty. */
/*
  next_arr[0] = 0;
  next_arr[num_element-1] = 0;
*/
  /* make next generation array according to the rules:
  Full(1) if one of adjacent cells if full and Empty(0) otherwise */
/*
  for (i=1; i<num_element-1; i++)
  {
    if (arr[i]==0 && arr[i-1]==1 && arr[i+1]==0 )
    {
      next_arr[i] = 1;
    }
    else if (arr[i]==0 && arr[i-1]==0 && arr[i+1]==1)
    {
      next_arr[i] = 1;
    }
    else
    {
      next_arr[i] = 0;
    }
  }
  return next_arr;
}
*/

/* Prints the input array in a single row.
Arguments:
 arr[]: the input array to print
 num_element: the number of cells in the input array
Return value: None*/

void print_arr(int arr[], int num_element)
{
  int i;
  for (i=0; i<num_element; i++)
  {
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  /* initial array and free it */
  int *arr_init;
  int num_element = atoi(argv[1]);
  arr_init = initial_array(num_element);
  print_arr(arr_init, num_element);
  return 0;
}