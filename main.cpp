#include <iostream>
#include "BigInt.h"
using namespace std;


ostream& operator<<(ostream& out, const BigInt& in )
{
    out<<in.decStr;
    return out;
}
istream& operator>>(istream& in, BigInt& number)
{
    in>>number.decStr ;
    return in ;
}

int main()
{

    int choice;
    string infile,outfile;
    cout<<"1 for input, 2 for file";
    string in1,in2;
    cin>>choice;
    if (choice==1)
    {
        cout<<"Enter the First Number\n";
        cin>>in1;
        cout<<"Enter the Second Number\n";
        cin>>in2;
        BigInt n1(in1);
        BigInt n2(in2);
        BigInt n4=n1-n2,
        n3=n2+n1;

        cout<<n1<<"-"<<n2<<"="<<n4<<endl;
        cout<<n2<<"+"<<n1<<"="<<n3<<endl;
      //  cout<<"POSTFIX: n4++: "<<n4++<<endl<<"POSTFIX: n4--"<<n4--<<endl<<"n4 now is "<<n4<<endl;
        cout<<endl<<endl;;
      /*  if (n1<n2)
        {
            cout<<"n1 < n2"<<endl;
        }
        if (n1!=n2)
        {
            cout<<"Not Equal"<<endl;
        }
        if (n1>n2)
        {
            cout<<"n1 > n2"<<endl;
        }

        if (n1==n2)
        {
            cout<<"EQUAL"<<endl;
        }*/
    }
    else if (choice ==2)
    {
        cout<<"Enter the name for your output file such as \"name.txt\"";
        cin>>outfile;
        ifstream filein ("numbers.txt",ios::in);
        ofstream fileout (outfile.c_str(),ios::out);
        filein>>in1>>in2;
        BigInt n1(in1);
        BigInt n2(in2);
        BigInt n4=n2-n1,n3=n2+n1;
        fileout<<n1<<"-"<<n2<<"="<<n4<<endl;
        fileout<<n2<<"+"<<n1<<"="<<n3<<endl;
        fileout<<"POSTFIX: n4++: "<<n4++<<endl;
               fileout<<"POSTFIX: n4--: "<<n4++<<endl<<"NEW n4: "<<n4<<endl;
        if (n1<n2)
        {
            fileout<<"n1 < n2"<<endl;
        }
        if (n1!=n2)
        {
            fileout<<"Not Equal"<<endl;
        }
        if (n1>n2)
        {
            fileout<<"n1 > n2"<<endl;
        }

        if (n1==n2)
        {
            fileout<<"EQUAL"<<endl;
        }
        filein.close();
        fileout.close();
    }


    return 0;
}
