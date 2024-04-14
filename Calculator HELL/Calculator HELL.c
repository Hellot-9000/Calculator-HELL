#include <stdio.h> //basic C to invlude the stdio.h, this allows the program to run with the debugger
// these next two lines will initialize the external functions (Located in Source.asm) 
extern int add_asm(int a, int b); //Heres a breakdown, "Extern" well, external, "int" Initializes the function, "add_asm" is the fuction that is public inside of Source.asm, and int a and int b are the 2 numbers 
extern int sub_asm(int a, int b);
extern int mul_asm(int a, int b);
extern int div_asm(int a, int b);

int main() // this is where the program starts to run, this will open inside of the windows debugger (the black window terminal) 
{
    printf("My 'Simple' Calculator\n"); // Printf is the print function for C, This will display "My 'Simple' Calculator" the \n is just the programs way of making a new line, or pressing "enter"

    char operand; // this initalizes the character input called "operand". this can be named anything that we want to use, can be A thru Z, or whatever name we give it. It is just a name of the function
    printf("\nPlease enter the operand: "); // this is going to ask the user for input, THIS LINE DOES NOT ACCEPT INPUT, ONLY ASKES THE USER
    scanf_s(" %c", &operand, 1); // here using the scanf_s function we will accept an input, here we are asking for the operand, (+ - * /) we ask for %c as we want to capture the ascii character

    int number1 = 0; // now we initiallize number 1 and set it equal to zero, we will add a number to this "number1" later
    int number2 = 0; // same here
    printf("\nPlease enter the first number: "); // this is asking the user for the first numebr
    scanf_s("%d", &number1); // this is going to get the users input, the %d is c's way of wanting a number to be inputted, otherwise it will throw an error
    printf("\nPlease enter the second number: "); // asking for the users 2nd input
    scanf_s("%d", &number2); // scanning it for the 2nd number. 
// you may have noticed that I have &function instead of just the function, this is to tell c that we want to change the value of this function to what is scanned
   // here is the if and else if statements that check for each operand
    if (operand == '+') //checks for plus
    {
        printf("Addition result is %d\n", add_asm(number1, number2)); // goes to the Source.asm program and utilizes the add_asm program
    }
    else if (operand == '-') // checks for minus
    {
        printf("Subtraction result is %d\n", sub_asm(number1, number2)); // goes to the Source.asm program and ustilizes the sub_asm program
    }
    else if (operand == '*') // checks for multiplication
    {
        printf("Multiplication result is %d\n", mul_asm(number1, number2));// goes to the Source.asm program and ustilizes the mul_asm program
    }
    else if (operand == '/') //checks for division
    {
        printf("Division result is %d\n", div_asm(number1, number2));// goes to the Source.asm program and ustilizes the div_asm program
    }
    else // incase the user doesnt know what to input it will throw this case
    {
        printf("Invalid operand\n"); // HA! invalid lol
    }

    
    return 0; // returns zero to end the program
}
