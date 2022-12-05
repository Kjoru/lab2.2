#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>


double l_rectangles(double a, double b, unsigned int N);
double r_rectangles(double a, double b, unsigned int N);
double trap(double a, double b, unsigned int N);
double simpson (double a, double b, unsigned int N);
double integral(double);


int main()
{
    double a, b;
    int N, var;
    double s_itg;


do
    {
    printf("\nEnter first limit:");
    scanf("%lf", &a);
    printf("\nEnter second limit:");
    scanf("%lf", &b);
    }
while(a==b);

do
    {
    printf("\nEnter N:");
    scanf("%u", &N);
    }
while(N<=0);

system("cls");
//----------------------------------------------------------------------------
    do {
        printf("\nChoose method:\n");
        printf("\n1  L Rectangles method:");
        printf("\n2  R Rectangles method:");
        printf("\n3  Trapezium method:");
        printf("\n4  Simpson method:");
        printf("\nVariant:");
        scanf("%u", &var);
    }
    while (var!=1 &&var!=2 &&var!=3 &&var!=4 );
system("cls");
//----------------------------------------------------------------------------
    switch(var)
      {
          case 1:
              {
                  s_itg = l_rectangles(a, b, N);
                  printf("\na = %.2lf \nb = %.2lf \nIntegral = %.5lf \nN = %d",a, b, s_itg, N);
              }
          break;


          case 2:
              {
                  s_itg = r_rectangles(a, b, N);
                  printf("\na = %.2lf \nb = %.2lf \nIntegral = %.5lf \nN = %d",a, b, s_itg, N);
              }
          break;


          case 3:
              {
                  s_itg = trap(a, b, N);
                  printf("\na = %.2lf \nb = %.2lf \nIntegral = %.5lf \nN = %d",a, b, s_itg, N);
              }
          break;


          case 4:
              {
                  s_itg = simpson(a, b, N);
                  printf("\na = %.2lf \nb = %.2lf \nIntegral = %.5lf \nN = %d",a, b, s_itg, N);
              }
          break;
            }
        return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
double integral( double x )
        {
            return (9*pow(x,3)+1000);
        }
//------------------------------------------------------------------------------------------------------------------------------------------------------------
double l_rectangles(double a, double b, unsigned int N)
        {
            double s_itg, x, h;
            unsigned int i;
            h = (b - a) / N;
            x = a;
            for (i = 0; i < N; i++)
                { x += h; s_itg += integral(x);}
            return s_itg*h;
        }
//------------------------------------------------------------------------------------------------------------------------------------------------------------
double r_rectangles(double a, double b, unsigned int N)
        {
            double s_itg, x, h;
            unsigned int i;
            h = (b - a) / N;
            x = a + h;
            for (i = 0; i <= N; i++)
                { x += h; s_itg += integral(x);}
            return s_itg * h;

        }
//------------------------------------------------------------------------------------------------------------------------------------------------------------
double trap (double a, double b, unsigned int N)
        {
            double s_itg, x , h;
            unsigned int i;
            h = (b - a) / N;
            x = a + h;
            for (i = 0; i <= (N - 1); i++)
                {x += h; s_itg += (integral(x) + integral(x + h)) / 2;}
            return s_itg * h;
        }
//------------------------------------------------------------------------------------------------------------------------------------------------------------
double simpson (double a, double b, unsigned int N)
        {
            double sum1 , sum2 , h ;
            h = (b - a) / N;
            for (int i = 1; i <= (N - 1); i++)
                {
                    if (i%2!=0)
                    sum1 += integral(a + h * i);
                    else
                    sum2 += integral(a+ h * i);
                }
  return ((h / 3)*(integral(a) + integral(b) + 4 * sum1 + 2 * sum2));
        }
