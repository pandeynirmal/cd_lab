#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char stack[20], ip[20], opt[10][10][2], ter[10]; 
    int i, j, k, n, top = 0, col, row;

    printf("Enter the number of terminals: ");
    scanf("%d", &n);

    printf("\nEnter the terminals (characters): ");
    for (i = 0; i < n; i++) {
        scanf(" %c", &ter[i]); 
    }


    printf("Enter the operator precedence table values:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter the value for %c%c (>, <, or =): ", ter[i], ter[j]);
            scanf(" %s", opt[i][j]); 
        }
    }

    printf("\nOperator precedence table:\n");
    printf("\t");
    for (i = 0; i < n; i++) {
        printf("%c\t", ter[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%c\t", ter[i]);
        for (j = 0; j < n; j++) {
            printf("%s\t", opt[i][j]);
        }
        printf("\n");
    }

    stack[top] = '$';
    printf("\nEnter the input string (append $ at the end): ");
    scanf("%s", ip);

    i = 0;
    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
    printf("\n%s\t\t\t%s\t\t\t", stack, ip);

    while (i <= strlen(ip)) {
        for (k = 0; k < n; k++) {
            if (stack[top] == ter[k]) {
                col = k;
            }
            if (ip[i] == ter[k]) {
                row = k;
            }
        }

        if (stack[top] == '$' && ip[i] == '$') {
            printf("String is accepted\n");
            break;
        } else if (opt[col][row][0] == '<' || opt[col][row][0] == '=') {
            stack[++top] = opt[col][row][0];
            stack[++top] = ip[i];
            printf("Shift %c ", ip[i]);
            i++;
        } else if (opt[col][row][0] == '>') {
             while (top > 0 && stack[top-1] != '<') { 
                --top;
            }
            if(top > 0) --top; 
            printf("Reduce. ");
            
        } else {
            printf("\nString is not accepted.\n");
            break;
        }

        printf("\n");
        for (k = 0; k <= top; k++) {
            printf("%c", stack[k]);
        }
        printf("\t\t\t");
        for (k = i; k < strlen(ip); k++) {
            printf("%c", ip[k]);
        }
        printf("\t\t\t");
    }

    return 0;
}
