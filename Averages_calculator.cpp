//
//  main.cpp
//  Zadanie_dodatkowe
//
//  Created by Kinga Kulawik on 04/12/2021.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

 void sorting(double *tab, int n)

  {
    for(int i=0; i<n; i++)
        for(int j=1; j<n-1; j++)
            if(tab[j-1]>tab[j])
                swap(tab[j-1],tab[j]);
  }

 double arithmetic_average(double *tab)

  {
    double arithmetic_average=0;
    double sum=0;
     
     for(int i=0; i<10; i++)
      {
        sum=sum+tab[i];
      }
     
     arithmetic_average=sum/10;
    
   return arithmetic_average;
  }

 double geometric_average(double *tab)

  {
    double geometric_average=0;
    double multiplication=0;
     
     for(int i=0; i<10; i++)
      {
        multiplication=multiplication*tab[i];
      }
     
    geometric_average=pow(multiplication,1/10);
    
    return geometric_average;
  }

 double harmonic_average(double *tab)

  {
    double harmonic_average=0;
    double sum=0;
    
     for(int i=0; i<10; i++)
      {
        sum=sum+1/tab[i];
      }
     
    harmonic_average=10/sum;
     
    return harmonic_average;
    
  }

 double square_average(double *tab)

  {
    double square_average=0;
    double sum=0;
     
     for(int i=0; i<10; i++)
      {
        sum=sum+tab[i]*tab[i];
      }
     
    square_average=sqrt(sum/10);
     
    return square_average;
  }

 double median(double *tab, int i)

  {
    double median=0;
    int m=i/2;
     
    sorting(tab,10);
     
     if(i/2==0)
        median=tab[i/2];
     
     else median=(tab[m]+tab[m+1])/2;
     
    return median;
  }

 double modal(double *tab)

  {
    sorting(tab,10);
     
    double modal;
    int max=0;
    int m=0;
     
     for(int i=0; i<10; i++)
    {
        if(tab[i]==tab[i+1])
       {
         m++;
         modal=tab[i];
       }
     else
      {
        if(m>max)
          {
            max=m;
            m=0;
          }
          
        else m=0;
       }

        
    }
     
    return modal;
 }
int main()

{
    srand(time(NULL));
    
    double table[10];
    double arithmetic;
    double geometric;
    double harmonic;
    double square;
    double me;
    double mo;
    double t[6];
    int sum=0;
    
    cout<<"Averages calculator: "<<endl;
    
    for(int i=0; i<10; i++)
      {
        table[i]=rand()%10;
      }
    
    arithmetic=arithmetic_average(table);
    geometric=geometric_average(table);
    harmonic=harmonic_average(table);
    square=square_average(table);
    me=median(table,10);
    mo=modal(table);
    
    t[0]=arithmetic;
    t[1]=geometric;
    t[2]=harmonic;
    t[3]=square;
    t[4]=me;
    t[5]=mo;
    
    sorting(t,6);
    
    for(int i=0; i<6; i++)
      {
        if(t[i]==arithmetic)
            cout<<"arithmetic average: "<<t[i]<<endl;
          
        if(t[i]==geometric)
        cout<<"geometric average: "<<t[i]<<endl;
          
        if(t[i]==harmonic)
            cout<<"harmonic average: "<<t[i]<<endl;
          
        if(t[i]==square)
            cout<<"square average: "<<t[i]<<endl;
          
        if(t[i]==me)
            cout<<"median: "<<t[i]<<endl;
          
        if(t[i]==mo)
            cout<<"modal: "<<t[i]<<endl;
        }
 
    return 0;
}
