#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
   omp_set_num_threads(2);
#pragma omp parallel num_threads(3)
   {
      printf("Параллельная область 1\n");
   }
#pragma omp parallel
   {
      printf("Параллельная область 2\n");
   }
}

#include <stdio.h>
int main(int argc, char *argv[])
{
   int count = 0;
#pragma omp parallel reduction (+: count)
   {
      count++;
      printf("Текущее значение count: %d\n", count);
   }
   printf("Число нитей: %d\n", count);
}