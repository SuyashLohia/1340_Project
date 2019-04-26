#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <cctype>

#include "product_list.cpp"
#include "utils.cpp"
#include "function_headers.h"
using namespace std;

//User interface
int main()
{
    init();
    
    int ch;
    char PWch;
    string PW ="";
    cout<<setw(50)<<"SUNDRY SHOP \n \n \n";
    do
    {
        cout<<"\n 1.Admin \n";
        cout<<"2.Customer \n";
        cout<<"3.Quit \n\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter password: ";
                cin >> PW;
                if(PW == "password"){
                    Admin();
                }
                else
                    cout<<"Incorrect password - *ACCESS DENIED*"<<endl;
            }
                break;
            case 2:
                Customer();
                break;
            case 3:
                cout<<"Quitting..." <<endl;
                return 0;
        }
    }while(ch!=3);
    cin >> ch;
}

void init () {
    product_list = (Product *) malloc(product_capacity*sizeof(Product));
    read_data_file ();
}

//Admin function gives access to modify the product database through the functions available.
void Admin()
{
    int ch;
    do
    {
        cout<<"\n 1.Add product \n";
        cout<<"2.Add quantity \n";
        cout<<"3.Delete \n";
        cout<<"4.Edit \n";
        cout<<"5.Search \n";
        cout<<"6.Display all \n";
        cout<<"7.Back \n";
        cout<<"\n Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:Add();
                break;
            case 2:AddQty1();
                break;
            case 3:Delete();
                break;
            case 4:Edit();
                break;
            case 5:Search();
                break;
            case 6:DisplayAll();
        }
    }while(ch!=7);
}
//This function enters the Customer interface in which customers can search for a existing product in our database.
void Customer()
{
    int Pnum,Bnum;
    for (int i = 0; i < product_count; i ++) {
        Product P = product_list [i];
        P.Output();
    }
    cout<<"\n Enter product number: ";
    cin>>Pnum;
    cout<<"Enter brand number: ";
    cin>>Bnum;
    Billing(Pnum,Bnum);
}
//Notifies how many pieces of product is available if the search returns true
void Billing(int Pnum,int Bnum)
{
    Product P;
    int Num,Found=0;
    double Total;
    for (int i = 0; i < product_count; i ++) {
        Product P = product_list [i];
        //cout << "Product: " << P.RPno() << P.RBno() << endl;
        if(P.RPno()==Pnum && P.RBno()==Bnum)
        {
            cout<<"\n Enter quantity: ";
            cin>>Num;
            if(Num < 0 || P.RQty()<Num) {
                cout<<endl<<Num<<" pieces unavailable"<<endl;
            }
            else
            {
                P.ReduceQty(Num);
                update(P);
                Total=CalculateTotal(Num,P.RPrice());
                Found++;
            }
        }
    }
    cout << fixed << setprecision(2);
    cout<<"\n Total price= HKD. "<<Total;
}
//Creating a new Produuct , take inputs and pass it to the create function to add to the database.
void Add()
{
    Product P;
    P.Input();
    create(P);
}
//Modifies an existing product available quantity and updates it to the database.
void AddQty1()
{
    Product P;
    int Pnum,Bnum,Num;
    
    for (int i = 0; i < product_count; i ++) {
        Product P = product_list [i];
        P.Output();
    }
    
    cout<<"\n Enter product number: ";
    cin>>Pnum;
    cout<<"Enter brand number: ";
    cin>>Bnum;
    
    for (int i = 0; i < product_count; i ++) {
        Product P = product_list [i];
        if(P.RPno()==Pnum && P.RBno()==Bnum)
        {
            cout<<"\n Add how many? ";
            cin>>Num;
            P.AddQty(Num);
            update(P);
        }
    }
}

//Searches for a product to be deleted and updates the database.
void Delete()
{
    int num=0;
    cout<<"Enter product number to be deleted: ";
    cin>>num;
    remove(num);
}
//Searches for an existing product number and edits the content of the product.
void Edit()
{
    Product P;
    int Num,Found=0,choice,temp;
    double temp2;
    string buffer;
    DisplayAll();
    cout<<"\n Enter product number to modify: ";
    cin>>Num;
    for (int i = 0; i < product_count; i ++) {
        Product P = product_list [i];
        if(P.RPno()==Num)
        {
            cout << "Currently editing product number " << Num << endl;
            cout << "Take note that product number cannot be changed." << endl;
            cout<<"\n Which category do you want to edit? \n 1.Product name \n 2.Brand number \n 3.Brand name \n 4.Price \n 5.Quantity \n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:
                    cout<<"What is the new product name?" << endl;
                    cin.ignore();
                    std::getline(cin, buffer);
                    std::strcpy(P.Pname, buffer.c_str());
                    break;
                case 2:
                    cout<<"What is the new brand number?" << endl;
                    cin >> temp;
                    P.Bno = temp;
                    break;
                case 3:
                    cout<<"What is the new brand name?" << endl;
                    cin.ignore();
                    std::getline(cin, buffer);
                    std::strcpy(P.Brand, buffer.c_str());
                    break;
                case 4:
                    cout<<"What is the new price?" << endl;
                    cin >> temp2;
                    P.Price = temp2;
                    break;
                case 5:
                    cout<<"What is the new quantity?" << endl;
                    cin >> temp;
                    P.Qty = temp;
                    break;
                    
            }
            update(P);
            cout << "Product number: " << Num << " is succesfully modified." << endl;
            Found++;
        }
        if(Found)
            cout<<"Record edited" <<endl;
    }
    if (!Found){
        cout <<"No product number exists, no records edited" << endl;
    }
}
//Searches for a product in the database to display.
void Search()
{
    int ch;
    cout<<"\n Search products by: \n 1.Product number \n 2.Product name \n 3.Brand number \n 4.Brand name \n 5.Price \n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            int Num;
            cout<<"\n Enter product number to be searched: ";
            cin>>Num;
            for (int i = 0; i < product_count; i ++) {
                Product P = product_list [i];
                if(P.RPno()==Num)
                    P.Output();
            }
        }
            break;
        case 2:
        {
            //Implement a function such that if a segment of string is detected in the Pname, returns the product.
            char Name[100];
            string temp;
            cout<<"\n Enter product name to be searched: ";
            cin.ignore();
            std::getline(cin, temp);
            std::strcpy(Name, temp.c_str());
            for (int i = 0; i < product_count; i ++) {
                Product P = product_list [i];
                if(strcmp2(P.RPname(),Name)){
                    P.Output();
                }
            }
        }
            break;
        case 3:
        {
            int Num;
            cout<<"\n Enter brand number to be searched: ";
            cin>>Num;
            for (int i = 0; i < product_count; i ++) {
                Product P = product_list [i];
                if(P.RBno()== Num)
                    P.Output();
            }
        }
            break;
        case 4:
        {
            char Name[100];
            string temp;
            cout<<"\n Enter brand name to be searched: ";
            cin.ignore();
            std::getline(cin, temp);
            std::strcpy(Name, temp.c_str());
            for (int i = 0; i < product_count; i ++) {
                Product P = product_list [i];
                if(strcmp2(P.RBrand(),Name))
                    P.Output();
            }
        }
            break;
        case 5:
        {
            double Num;
            cout<<"\n Enter price to be searched: ";
            cin>>Num;
            for (int i = 0; i < product_count; i ++) {
                Product P = product_list [i];
                if(P.RPrice()==Num)
                    P.Output();
            }
        }
    }
}
//This function displays the entire product database.
void DisplayAll()
{
    for (int i = 0; i < product_count; i ++) {
        Product P = product_list [i];
        P.Output();
    }
}

double CalculateTotal(int Num,double Price)
{
    double Total=Num*Price;
    return Total;
}
