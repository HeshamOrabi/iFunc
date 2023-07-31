#include <stdio.h>
#include <stdlib.h>

int *addtwo(int *arr, int arrlen, int target)
{
  int i, j;
  int *arrp = malloc(sizeof(int) * 2);
  
  for (i = 0; i < arrlen; i++)
  {
    for (j = i + 1; j < arrlen; j++)
    {
      if (arr[i] + arr[j] == target)
      {
        arrp[0] = i;
        arrp[1] = j;
        return (arrp);
      }
    }
  }
}

int main() {
  int arr[] = {2, 7, 9, 15, 20};
  int *retarr;
  
  retarr = addtwo(arr, 5, 27);
  
  printf("INDEX : [%d] [%d]", retarr[0], retarr[1]);
  return 0;
}
