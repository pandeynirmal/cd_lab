#include <stdio.h>
#include <string.h>
#include <ctype.h>

void keyword(char *str) {
    if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 ||
        strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 ||
        strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 ||
        strcmp("case", str) == 0) {
        printf("\n%s is a keyword", str);
    } else {
        printf("\n%s is an identifier", str);
    }
}

int main() {
    FILE *f1, *f2, *f3;
    char str[10];
    int num[100], lineno = 0, tokenvalue = 0;
    int i = 0, j = 0, k = 0, c;

    printf("\nEnter the C program (Press Ctrl+D to save and exit):\n");
    f1 = fopen("input", "w");

    while ((c = getchar()) != EOF) {
        putc(c, f1);
  
