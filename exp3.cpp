 #include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100]; // Increased buffer size for better handling
int i, error;

void E();
void T();
void Eprime();
void Tprime();
void F();

int main()
{
    i = 0;
    error = 0;

    printf("\nEnter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin); // Safer than gets()
    
    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    E();

    if (strlen(input) == i && error == 0) {
        printf("\nAccepted..!!!\n");
    } else {
        printf("\nRejected..!!!\n");
    }

    return 0;
}

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if (input[i] == '+')
    {
        i++;
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if (input[i] == '*')
    {
        i++;
        F();
        Tprime();
    }
}

void F()
{
    if (isalnum(input[i])) // If the character is a letter or digit
    {
        i++;
    }
    else if (input[i] == '(') // Handle parentheses
    {
        i++;
        E();
        if (input[i] == ')')
        {
            i++;
        }
        else
        {
            error = 1; // Mismatched parentheses
        }
    }
    else
    {
        error = 1; // Invalid character
    }
}
