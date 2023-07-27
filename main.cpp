#include <iostream>

using namespace std;

int main()
{
    /*int x=10;
    int y=20;
    cout << "x = " << x << " " << "y = " << y << endl;

    x=x+y;   //30
    y=x-y;    //30-20 = 10
    x=x-y;    //30-10 = 20

    cout << "x = " << x << " " << "y = " << y << endl;*/

    int n;
    cin >> n;

    int flag=0;

    if(n==1)
    {
        cout << "1 is neither prime nor composite" << endl;
    }
    else{

        for(int i=2;i<=(n/2);i++)
        {
            if(n%i==0)
            {
                cout << "Given number is composite" << endl;
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            cout << "Given number is prime" ;
        }
    }

    return 0;
}
