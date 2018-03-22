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
            // generating pseudo-random number between 1 and 9 using time
            x = rand() % 10;
            cout<<"\n\ta["<<i+1<<"]["<<j+1<<"] = "<<x;
            //getch();
            k=0;

            for(k=0;k<9;k++)
            {
                if ((a[i][k]==x) || (a[k][j]==x))
                {
                    k=k-1;
                    x = rand() % 10;

                    if ((a[i][k]==x))
                    {
                        cout<<"\n\t\tSince a["<<i+1<<"]["<<k+1<<"] = "<<a[i][k]<<" = "<<x;
                        cout<<"\n\t\t   Thus a["<<i+1<<"]["<<j+1<<"] = "<<x;
                    }
                    else if ((a[k][j]==x))
                    {
                        cout<<"\n\t\tSince a["<<k+1<<"]["<<j+1<<"] = "<<a[k][j]<<" = "<<x;
                        cout<<"\n\t\t   Thus a["<<i+1<<"]["<<j+1<<"] = "<<x;
                    }
                }
            }

            a[i][j]=x;
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
