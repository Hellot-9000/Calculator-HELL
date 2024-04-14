#include <stdio.h>

extern int add_asm(int a, int b);
extern int sub_asm(int a, int b);
extern int mul_asm(int a, int b);
extern int div_asm(int a, int b);

int main()
{
    printf("My Simple Calculator\n");

    char operand;
    printf("\nPlease enter the operand: ");
    scanf_s(" %c", &operand, 1); // Added space before %c to consume newline character

    int number1 = 0;
    int number2 = 0;
    printf("\nPlease enter the first number: ");
    scanf_s("%d", &number1);
    printf("\nPlease enter the second number: ");
    scanf_s("%d", &number2);

    // Call the assembly language routine and print the calculator result back to the console
    if (operand == '+')
    {
        printf("Addition result is %d\n", add_asm(number1, number2));
    }
    else if (operand == '-')
    {
        printf("Subtraction result is %d\n", sub_asm(number1, number2));
    }
    else if (operand == '*')
    {
        printf("Multiplication result is %d\n", mul_asm(number1, number2));
    }
    else if (operand == '/')
    {
        printf("Division result is %d\n", div_asm(number1, number2));
    }
    else
    {
        printf("Invalid operand\n");
    }

    // Return all OK from this program
    return 0;
}
