utils.o: utils.cpp
	g++ -c utils.cpp

product_list.o: product_list.cpp product_data_file.o
	g++ -c product_list.cpp

product_data_file.o: product_data_file.cpp
	g++ -c product_data_file.cpp

program: program.cpp product_list.o utils.o function_headers.h
	g++ program.cpp -o program
