#include <stdio.h>
#include <omp.h>

void mode(void){
   if(omp_in_parallel()) printf("Параллельная область\n");//omp_in_parallel Возвращает не нулевое значение, если вызвана 
  // внутри параллельного блока.В противном случае возвращается 0.
   
   else printf("Последовательная область\n");
}

int main(int argc, char *argv[])
{
   mode();//Последовательная область
#pragma omp parallel
   {
#pragma omp master//Синхронизация типа master используется для определения структурного блока программы,
      //который будет выполняться исключительно в главном потоке (параллельном потоке с нулевым номером)
      //из всего набора параллельных потоков
      {
         mode();//Параллельная область
      }
   }
}
