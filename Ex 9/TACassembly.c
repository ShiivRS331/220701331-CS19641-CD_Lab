#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trim_newline(char *str) {
    int len = strlen(str);
    if(len > 0 && str[len-1] == '\n')
        str[len-1] = '\0';
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void generateAssembly(char *tac) {
    char lhs[20], op1[20], op2[20], operator;

    if (sscanf(tac, "%s = %s %c %s", lhs, op1, &operator, op2) == 4) {
        if (operator == '+') {
            printf("MOV AX, [%s]\n", op1);
            printf("ADD AX, [%s]\n", op2);
            printf("MOV [%s], AX\n", lhs);
        }
        else if (operator == '-') {
            printf("MOV AX, [%s]\n", op1);
            printf("SUB AX, [%s]\n", op2);
            printf("MOV [%s], AX\n", lhs);
        }
        else if (operator == '*') {
            printf("MOV AX, [%s]\n", op1);
            printf("MOV BX, [%s]\n", op2);
            printf("MUL BX\n");
            printf("MOV [%s], AX\n", lhs);
        }
        else if (operator == '/') {
            printf("MOV AX, [%s]\n", op1);
            printf("MOV DX, 0\n");
            printf("MOV BX, [%s]\n", op2);
            printf("DIV BX\n");
            printf("MOV [%s], AX\n", lhs);
        }
    }
        else if (sscanf(tac, "%s = %s", lhs, op1) == 2) {
        printf("MOV AX, [%s]\n", op1);
        printf("MOV [%s], AX\n", lhs);
    } else {
        printf(" Unsupported TAC format: %s\n", tac);
    }
}

int main() {
    int n;
    printf("Enter the number of TAC instructions: ");
    scanf("%d", &n);
    getchar();
    char tac[100];

    printf("\nEnter the TAC instructions (e.g., t0 = a + b):\n");
    for(int i = 0; i < n; i++) {
        printf("TAC %d: ", i+1);
        fgets(tac, sizeof(tac), stdin);
        trim_newline(tac);
        generateAssembly(tac);
    }

    return 0;
}


