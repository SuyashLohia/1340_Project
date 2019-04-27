# Group 55 ENGG1340_Group_Project
Commodity Inventory Management System 

The old README.md file was erased by me due to my careless mistake of using --force to push files.
However, this will be the updated version of the README.md file.

Problem statement:

Sundry shops has also been an icon for rural businesses. As international students , we observed that there still exists a large population of sundry shops in our hometown. Coincidentally, they are identical to the dispensaries in Hong Kong. These sundry shops sells numerous amount of goods and yet still uses pen and paper for stock management, which is inefficient and non-environmental friendly. Moreover, customers will have to approach the storekeeper to check for stock availability and have to wait for the storekeeper to perform calculations in order to know the final price of product. As millenials are getting more impatient in purchases, a solution would have to be implemented to speed up this process. Hence to solve for the aforementioned issues at a low cost to the sundry shops, we came up with a commodity inventory system.

What the project does? (Features and functionalities)

Our project has 2 main components, Admin and Customer. The Admin component maintain its integrity of being independent from the Customer component by a password. Admin enables sundry shops owners to manage their stock directly on this program. Owners can choose to Add new products if it is newly introduced , Increase quantity when restocks occur, Delete a product when it is no longer available or Edit a product if there is a mistake in the details of a product. If customers ask for a specific product availability in the huge variety of goods sold in the sundry shop, the owner can simply use the Search function to search it up instead of looking physically through the varieties. Admin can also keep track of their stocks through the Display All function which shows the whole inventory. This can be useful to order restocks towards the end of the month. The Customer component displays the entire range of products sold by the shops. Then, customers will choose a product number and a brand number. If the product exists, customers will be asked to input the quantity required. If the quantity is valid, the price will be displayed to the customer so that customers can directly order from the storekeeper without much delay and pay without having to wait for calculations. Conversely, a customer can just browse through the entire range of products displayed in this function without having to order anything.

Why the project is useful?

Not only can this program is efficient for stock management by owners, it can also be used by customers on a separate component from the owners. The Customer component eases the ordering process for the customer and reduces unnecessary conversations between the customer and the storekeeper. Hence, increasing productivity of the storekeeper by focusing only on sales. It is also quick in displaying the total price cost of an available product that is soon to be ordered by the customer. This is also in line with helping sundry shops digitalize their system so it is more appealing to younger generations.

Assumptions:

Each product has its own unique product number. Brand number is not unique though. Each input is made by the user is sensible and does not corrupt the product database (Product.dat)

Input/Output Specifications:

When selecting a function, the user must input a integer that exists within the range displayed. For Product Number, Brand Number and Quantity, the data type is Integer. For Product Name and Brand Name, the data type is a C-String. For Price, the data type is a Double. The price displayed is set to 2 decimal places since money is always displayed to 2 decimal places. It is advised that the user keeps an eye on which components of a product to choose from as it differs between functions.

Compliation and execution instructions:

To compile, ensure that you are in the directory of this project, then , simply type ($make program) in terminal and a file named program will be compiled. 
To execute, type ($./program) in terminal.
To access the Admin component, the password is "password".


Who maintains and contributes to the project?

Suyash Lohia ( ) and Kwok Zi Xing ( 3035603813 )
