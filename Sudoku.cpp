#include <iostream>
#include <conio.h>
#include <time.h>       //  srand; rand;
#include <stdlib.h>     //  time;
using namespace std;

int main()
{
    int a[9][9],i,j,k,x;

// initialize random seed:
    srand (time(NULL));



//  Setting initial matrix to 0.
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            a[i][j]=0;
        }
    }

    //  Displaying the Sudoku matrix.
    for(i=0;i<9;i++)
    {
        cout<<"\n\n";
        for(j=0;j<9;j++)
        {
            cout<<"\t"<<a[i][j];
        }
    }

    getch();


//  Filling Matrix with values
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<"\n\t\tFor [i,j] = ["<<i+1<<"]["<<j+1<<"]";
                    
            // generating pseudo-random number between 1 and 9 using time
            x = rand() % 10;
            cout<<"\n\t\t\tx = "<<x;
            //getch();
            
            if(a[i][j]==0)
            {
                do
                {
                    cout<<"\n\t\t\tSince x = "<<x;
                    x = rand() % 10;
                }while(x==0);
                
                for(k=0;k<9;k++)
                {
                    int c=0,n=0;
                    
                    cout<<"\n\t\t\tx = "<<x<<"\t k = "<<k;
                    
                    if(x==a[i][k])
                    {
                        c++;
                        cout<<"\n\t\t\t\tSince a["<<i+1<<"]["<<k+1<<"] = "<<a[i][k]<<" == x = "<<x;
                    }
                    if(x==a[k][j])
                    {
                        c++;
                        cout<<"\n\t\t\t\tSince a["<<k+1<<"]["<<j+1<<"] = "<<a[k][j]<<" == x = "<<x;
                    }
                    
                    if(c>0)
                    {
                        k=-1;
                        n=x;
                        
                        do
                        {
                            x = rand() % 10;
                        }while(x==0 || x==n);
                    }
                    
                }
                a[i][j]=x;
                cout<<"\n\t->>A["<<i+1<<"]["<<j+1<<"] = "<<x;
            }

            

            
        }
    }


    //  Displaying the Sudoku matrix.
    for(i=0;i<9;i++)
    {
        cout<<"\n\n";
        for(j=0;j<9;j++)
        {
            cout<<"\t"<<a[i][j];
        }
    }

    getch();
}
