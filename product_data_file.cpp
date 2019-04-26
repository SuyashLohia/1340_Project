#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

//Initiating a class of Product in which the Product Number of each product is unique!
class Product
{
	public:
		int Pno,Bno,Qty;
		char Pname[100],Brand[100];
		double Price;
		void Input();
		void Output();
		void AddQty(int);
		void ReduceQty(int);
		int RPno(){return Pno;}
		int RBno(){return Bno;}
		char* RPname(){return Pname;}
		char* RBrand(){return Brand;}
		double RPrice(){return Price;}
		int RQty(){return Qty;}
};

//Class product functions to handle inputs from the user.
void Product::Input()
{
    string buffer;
    
    cout<<"Product number: ";
    cin>> Pno;
    cout<<"Product name: ";
    cin.ignore();
    std::getline(cin, buffer);
    std::strcpy(Pname, buffer.c_str());
    cout<<"Brand number: ";
    cin >> Bno;
    cout<<"Brand: ";
    cin.ignore();
    std::getline(cin, buffer);
    std::strcpy(Brand, buffer.c_str());
    cout<<"Price: ";
    cin>>Price;
    if (Price <= 0){
        Price = 0;
    }
    cout<<"Quantity: ";
    cin>>Qty;
    if (Qty <= 0){
        Qty = 0;
    }
}
//Handles the display of product information to the user
void Product::Output()
{
    cout<<endl<<Pno<<endl;
    puts(Pname);
    cout<<Bno<<endl;
    puts(Brand);
    cout << fixed << setprecision(2);
    cout<<"HKD "<<Price<<endl;
    if (Qty == 0){
        cout << "Out of stock" << endl;
    }
    else{
        cout<<Qty<<endl;
    }
}

void Product::AddQty(int Num)
{
    Qty=Qty+Num;
}

void Product::ReduceQty(int Num)
{
    Qty=Qty-Num;
}

