#include <stdio.h>
#include <omp.h>
//Подключаем файлы заголовков
int main(int argc, char *argv[])
{
   int n;
   //Разрешает или запрещает вложенный параллелизм (распараллеливание вложенных циклов). По умолчанию – запрещено.
   omp_set_nested(1);//вложенный параллелизм разрешен
#pragma omp parallel private(n)//каждый поток будет хранить свою копию переменной
   {
      n=omp_get_thread_num();//Возвращает номер потока
#pragma omp parallel
      {
         printf("Часть 1, нить %d - %d\n", n,
                omp_get_thread_num());//Возвращает номер вложенного потока
      }
   }
   omp_set_nested(0);//вложенный параллелизм запрещен, далее по аналогии
#pragma omp parallel private(n)
   {
      n=omp_get_thread_num();
#pragma omp parallel
      {
         printf("Часть 2, нить %d - %d\n", n,
                omp_get_thread_num());
      }
   }
}
