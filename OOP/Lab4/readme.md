# CoffeeMachine Application

## Overview
This application simulates a basic coffee shop ordering system. It allows customers to place orders for different types of coffee, tracks the total amount spent, and calculates loyalty points based on the size of the coffee ordered. After each order, a receipt is printed, displaying the customer's name, the total amount spent, the loyalty points earned, and the details of the coffee order.

## Features
- Selection of coffee items with different sizes and prices.
- Calculation of total amount spent on orders.
- Loyalty points system based on the size of coffee ordered.
- Input validation for customer names (accepts only alphabetic characters).
- Printing of a formatted receipt after each order, including a unique receipt number.

## Compilation and Execution
This application is written in C++. To compile and run the program, you will need a C++ compiler like `g++`. 

1. Save the code in a file named `CoffeeMachine.cpp`.
2. Open a terminal or command prompt.
3. Navigate to the directory containing `CoffeeMachine.cpp`.
4. Compile the program: `g++ CoffeeMachine.cpp -o coffee_shop`
5. Run the executable: `./coffee_shop`


## Usage Example
1. When prompted, enter a valid one-word, alphabetic name for the customer.
2. Choose a coffee from the displayed menu by entering the corresponding number.
3. After each order, a receipt is printed with the order details.
4. You can order another coffee or exit the program.


## Notes
- The application does not persist data across runs.
- Loyalty points and total amount spent are calculated for each session only.