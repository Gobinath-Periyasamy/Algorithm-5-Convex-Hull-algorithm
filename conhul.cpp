#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;




/**********************************
Created on Wed May 05 12:59:26 2022

Name: Gobinath P
Roll No : CS21M501
Convex Hull algorithm
************************************/



//Creating Structure for coordinates
struct Coordinate
{
    int x,y;
};
int valuate(Coordinate p, Coordinate q, Coordinate r)
{
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}


int direction(Coordinate p, Coordinate q, Coordinate r)
{
    int val = valuate(p,q,r);

    if(val == 0)
        return 0;
    if(val>0)
        return 1;
    else
        return 2;
    //return (val>0)?1:2;
}



            
// Driver program to test above functions
int main()
{


    cout << "\n*********************************************"<<endl;
    cout << "* Name: Gobinath P                          *"<<endl;
    cout << "* Roll No : CS21M501                        *"<<endl;
    cout << "* Convex Hull Algorithm                     *"<<endl;
    cout << "*********************************************"<<endl;

    int num_point = 0;
    
    cout<<"Number of Points : "<<endl;
    cin>> num_point;


    int array[20][2] ={0};
    for (int i=0;i<num_point;i++)
    {
        cout<< "\nEnter point "<< i+1 <<endl;
        cin >> array[i][0] >> array[i][1];
    }


    // cout<< "\nArray : \n";
    // for (int i=0;i<num_point;i++)
    // {
    //     cout<< array[i][0] << "  "<< array[i][1]<< "  ";
    // }
    // cout<<"\n";



    Coordinate coordinates[] = {};

    cout<< "\nGiven coordinates : \n";
         for (int i = 0;i<num_point;i++)
    {
         cout<<"("<<coordinates[i].x << ","<<coordinates[i].y<<"), ";
//         cout<<coordinates[i].y << " ";

     }
//    cout<<coordinates<<endl;


    for (int i = 0;i<num_point;i++)
    {
          coordinates[i].x = array[i][0];
          coordinates[i].y = array[i][1];

    }
    // cout<<coordinates<<endl;

    // cout<<"After :\n";

    // cout<< "\ncoordinates : \n";
    //      for (int i = 0;i<num_point;i++)
    // {
    //      cout<<coordinates[i].x << " ";
    //      cout<<coordinates[i].y << " ";

    //  }
    // cout<<coordinates<<endl;



    int n = num_point;

    // cout<<"Size : "<<" "<<n<<endl;
    // Base Case
    if(n<3)
        return 0;
    vector<Coordinate> conhull;
    int l = 0;
    for (int i = 1;i<n;i++)
    {
        if(coordinates[i].x < coordinates[l].x)
            l=i;
    }
    int p = l, q;
    do
    {
        conhull.push_back(coordinates[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
            Coordinate g,h,k;
            g = coordinates[p], h = coordinates[i], k = coordinates[q];
            if (direction(g,h,k) == 2)
                q = i;
        }
        
        p = q;
        
    } while (p != l); 

    // Conhul Cordinates 
    cout << "\n\n************************************************************"<<endl;
    cout << "************************************************************"<<endl;
    cout<<"Convex Hull Cordinates are : \n" << endl;
    for (int i = 0; i < conhull.size(); i++)
        cout << "\t (" << conhull[i].x << ", " << conhull[i].y << ")\n";
    cout << "\n************************************************************"<<endl;
    cout << "************************************************************"<<endl;


    system("PAUSE");

    return EXIT_SUCCESS;

}