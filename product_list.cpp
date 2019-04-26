#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

#include "product_data_file.cpp"

using namespace std;

//Making a dynamic array product_list of products (DYNAMIC MEMORY MANAGEMENT)
Product * product_list;
int product_count = 0;



// implementation detail
int product_capacity = 10;

void expand_capacity_if_needed();

//Reading the current product database into the program. (File input)
void read_data_file () {
    fstream data_file;
    data_file.open("Product.dat",ios::in);
    
    data_file.seekg(0, std::ios::end);
    streampos end = data_file.tellg();
    data_file.seekg(0, std::ios::beg);
    
    while(!data_file.eof() && !data_file.fail() && data_file.tellg() != end)
    {
        stringstream ss;
        
        Product p = * (new Product);
        
        string buffer;
        int temp;
        double temp1;
        
        
        // Strings work now but not integers and double
        std::getline(data_file, buffer, ';');
        ss << buffer;
        temp = stoi(buffer);
        p.Pno = temp;
        std::getline(data_file, buffer, ';');
        ss << buffer;
        std::strcpy(p.Pname, buffer.c_str());
        std::getline(data_file, buffer, ';');
        ss << buffer;
        temp = stoi(buffer);
        p.Bno = temp;
        std::getline(data_file, buffer, ';');
        ss << buffer;
        std::strcpy(p.Brand, buffer.c_str());
        std::getline(data_file, buffer, ';');
        ss << buffer;
        temp1 = atof(buffer.c_str());
        p.Price = temp1;
        std::getline(data_file, buffer, ';');
        ss << buffer;
        temp = stoi(buffer);
        p.Qty = temp;
        
        expand_capacity_if_needed ();
        
        product_list[product_count] = p;
        product_count = product_count + 1;
    }
    
    data_file.close();
}
//This function writes the dynamic array to the product database when called to update the products (File output)
void write_data_file () {
    fstream data_file;
    data_file.open("Product.dat",ios::out);
    
    for (int i = 0; i < product_count; i ++) {
        Product p = product_list [i];
        data_file << p.Pno << ";" << p.Pname << ";" << p.Bno << ";" << p.Brand << ";" << p.Price << ";" << p.Qty << ";";
        if (i < product_count - 1) {
            data_file << endl;
        }
    }
    
    data_file.close();
}

//Creating a new product to be added (Data Manipulation)
void create(Product p) {
    expand_capacity_if_needed ();
    
    product_list[product_count] = p;
    product_count = product_count + 1;
    
    write_data_file ();
}
//Update any changes made to a product, copying the old array without changes and appending the modified product in the position of the old product (Data manipulation)
void update(Product p) {
    for (int i = 0; i < product_count; i ++) {
        Product existing_product = product_list [i];
        if (existing_product.RPno() == p.RPno()) {
            product_list[i] = p;
        }
    }
    
    write_data_file ();
}
//Deleting a product by shifting the dynamic array of n+1 to n to replace the product to be removed. (Data manipulation)
void remove(int product_number) {
    for (int i = 0; i < product_count; i ++) {
        Product existing_product = product_list [i];
        if (existing_product.RPno() == product_number) {
            for (int j = i + 1; j < product_count; j ++) {
                product_list [j - 1] = product_list [j];
            }
            
            product_count = product_count - 1;
            break;
        }
    }
    
    write_data_file ();
}
//This function takes care of expanding the size of the dynamic array if capacity is met. (Dynamic Memory Management)
void expand_capacity_if_needed () {
    if (product_count == product_capacity) {
        Product * new_list = (Product *) malloc(2*product_capacity*sizeof(Product));
        memcpy(new_list, product_list, product_capacity*sizeof(Product));
        free(product_list);
        product_list = new_list;
        product_capacity = 2*product_capacity;
    }
}
