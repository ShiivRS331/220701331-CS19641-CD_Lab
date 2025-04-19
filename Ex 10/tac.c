#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tempCount = 1;
int labelCount = 1;

char* newTemp() {
    static char temp[5];
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

char* newLabel() {
    static char label[5];
    sprintf(label, "L%d", labelCount++);
    return label;
}

void generateArithmeticTAC(char expr[]) {
    char a, b, c, op1, op2;
    sscanf(expr, "%c = %c %c %c %c %c", &a, &b, &op1, &c, &op2, &op2);
    if (strchr(expr, '*') && strchr(expr, '+')) {
        char t1[5], t2[5];
        strcpy(t1, newTemp());
        strcpy(t2, newTemp());
        printf("%s = c * d\n", t1);
        printf("%s = b + %s\n", t2, t1);
        printf("%c = %s\n", a, t2);
    }
    else if (strchr(expr, '+')) {
        char t1[5];
        strcpy(t1, newTemp());
        sscanf(expr, "%c = %c + %c", &a, &b, &c);
        printf("%s = %c + %c\n", t1, b, c);
        printf("%c = %s\n", a, t1);
    }
}

void generateIfElseTAC() {
    printf("Input: if (a > b) x = y + z; else x = y - z;\n");
    char *L1 = newLabel(), *L2 = newLabel(), *L3 = newLabel();
    char *t1 = newTemp(), *t2 = newTemp();
    printf("if a > b goto %s\n", L1);
    printf("goto %s\n", L2);
    printf("%s: %s = y + z\n", L1, t1);
    printf("x = %s\n", t1);
    printf("goto %s\n", L3);
    printf("%s: %s = y - z\n", L2, t2);
    printf("x = %s\n", t2);
    printf("%s:\n", L3);
}

void generateWhileTAC() {
    printf("Input: while (a < b) a = a + 1;\n");
    char *L1 = newLabel(), *L2 = newLabel();
    char *t1 = newTemp();
    printf("%s: if a >= b goto %s\n", L1, L2);
    printf("%s = a + 1\n", t1);
    printf("a = %s\n", t1);
    printf("goto %s\n", L1);
    printf("%s:\n", L2);
}

int main() {
    FILE *fp;
    char line[100];

    fp = fopen("input10.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    printf("Three Address Code Output:\n\n");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "if")) {
            generateIfElseTAC();
        } else if (strstr(line, "while")) {
            generateWhileTAC();
        } else if (strchr(line, '=')) {
            generateArithmeticTAC(line);
        }
    }
    fclose(fp);
    return 0;
}

