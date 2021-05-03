#include<iostream>
#include "cypher.hpp"

int main() {
    //declare and initialize a cypher object.
    cypher code="Lousy donkey!";

    //call the encode funtion to encode the string.
    code.encode();
    //display the string on the console.
    std::cout <<"\n\n"<< code;

    //call the decode function to decode the string
    code.decode();
    
    //display the string on the console.
    std::cout << "\n\n" << code;


    std::cin.get();

}