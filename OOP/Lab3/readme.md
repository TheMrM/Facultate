# Complex Number Class in C++

This is a simple C++ program that defines a class called "Complex" for working with complex numbers. The class includes constructors, member functions, and a destructor to demonstrate the fundamental concepts of object-oriented programming in C++.

## Table of Contents
- [Overview](#overview)
- [Class Structure](#class-structure)
- [How to Use](#how-to-use)

## Overview

The program defines a C++ class, "Complex," which represents complex numbers. Each complex number has a real part (`re`) and an imaginary part (`im`). The class includes several methods for setting and getting these parts, as well as a print method to display the complex number's value. 

## Class Structure

The `Complex` class includes the following key components:

- `Complex()`: Default constructor that initializes an instance of the class.
- `Complex(float a, float b)`: Parameterized constructor that sets the real and imaginary parts using provided values.
- `Complex(const Complex& source)`: Copy constructor to create a copy of an existing `Complex` object.
- `~Complex()`: Destructor that provides a message when an instance is being destroyed.
- `void tiparire()`: Method to print the real and imaginary parts.
- `void setRe(float a)`: Method to set the real part.
- `float getRe()`: Method to get the real part.
- `void setIm(float b)`: Method to set the imaginary part.
- `float setIm()`: Method to get the imaginary part.

## How to Use

1. Clone or download the repository to your local machine.
2. Compile the C++ program using your preferred C++ compiler. For example, you can use g++, like this:

   ```sh
   g++ main.cpp -o complex_program
