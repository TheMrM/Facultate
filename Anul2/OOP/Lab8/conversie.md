Include the iostream library for input and output

Define a class named stringA
    Define a private string variable 'a' initialized to "ThisIsJustAString"
    
    Define a public method getString
        Return the value of string 'a'

    Define a public method display
        Print the value of string 'a'

Define a class named stringB
    Define a private string variable 'b'
    
    Define a public method to overload the assignment operator
        Accept a constant reference to a stringA object
        Assign the string from the stringA object to string 'b' using getString method

    Define a public method display
        Print the value of string 'b'

Define the main function
    Create an object 'a' of class stringA
    Create an object 'b' of class stringB

    Assign the value of object 'a' to object 'b' using the overloaded assignment operator

    Call the display method on object 'a'
    Call the display method on object 'b'

    End of the main function
