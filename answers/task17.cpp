#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
   int i;
#pragma omp parallel private(i)//Смотри билет 10
   {
#pragma omp for schedule (static)
//#pragma omp for schedule (static, 1)
//#pragma omp for schedule (static, 2)
//#pragma omp for schedule (dynamic)
//#pragma omp for schedule (dynamic, 2)
//#pragma omp for schedule (guided)
//#pragma omp for schedule (guided, 2)
      for (i=0; i<10; i++)
      {
         printf("Íèòü %d âûïîëíèëà èòåðàöèþ %d\n",
                omp_get_thread_num(), i);
         sleep(1);
      }
   }
