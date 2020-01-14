#include <stdio.h>
#include <omp.h>
double f(double y) {return(4.0/(1.0+y*y));}//Функция для счета f
int main()
{
   double w, x, sum, pi, t1, t2;
   int i, size;
   int n = 1000000000;
   t1=omp_get_wtime();//Установка точки начала таймера
   w = 1.0/(double)n;
   sum = 0.0;
#pragma omp parallel private(x) shared(w)//В параллельном блоке переменная w используется всеми потоками
//переменная x своя для каждого потока в свой промежуток времени
   {
      size=omp_get_num_threads();//Присваиваем переменной значение количества потоков в блоке
#pragma omp for reduction(+:sum)//Открываем параллельный цикл, используя условие reduction для сложения значений
      for(i=1; i <= n; i++)
      {
         x = w*(i-0.5);
         sum = sum + f(x);
      }
   }
   pi = w*sum;
   t2=omp_get_wtime();//окончание работы таймера
   printf("N= %d, Nproc=%d, pi = %lf, Time=%lf \n", n, size, pi, t2-t1);//вывод результатов
}
