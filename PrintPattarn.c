void printPattarn(int num)
{
  int i, j, val;
  int size = (num * 2) - 1;
  
   for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            val = i < j ? i : j;
            val = val < size - i ? val : size - i - 1;
            val = val < size - j - 1 ? val : size - j - 1;
            
            printf("%d ", num - val);            
        }
        printf("\n");
    }
}

void printPattarnUsingLoops(int num)
{
  int i, j, val;
  int size = (num * 2) - 1;
  int arr[size][size];
  int start = 0, end = size - 1;
  
  while (num)
  {
   for (i = start; i <= end; i++)
    {
        for (j = start; j <= end; j++)
        {
          if (i == start || j == start || i == end || j == end)
          {
            arr[i][j] = num;
          }
        }
    }
    start++;
    end--;
    num--;
  }
    
    for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
      {
        printf("%d ", arr[i][j]);
      }
      printf("\n");
    }
    
}

int main() {
  printPattarn(2);
  printf("\n---------------------------------\n");
  printPattarnUsingLoops(2);
  
  
  return 0;
}
