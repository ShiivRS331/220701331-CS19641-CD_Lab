#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char lhs[10], op1[10], op[5], op2[10];
    int isUsed;
} Statement;

Statement code[MAX];
int count = 0;

// Parse each line into TAC format
void parse(char *line) {
    sscanf(line, "%s = %s %s %s", code[count].lhs, code[count].op1, code[count].op, code[count].op2);
    if (strlen(code[count].op) == 0) strcpy(code[count].op2, "");
    code[count].isUsed = 0;
    count++;
}

// Copy Propagation
void copyPropagation() {
    for (int i = 0; i < count; i++) {
        if (strlen(code[i].op) == 0) {
            for (int j = i + 1; j < count; j++) {
                if (strcmp(code[j].op1, code[i].lhs) == 0)
                    strcpy(code[j].op1, code[i].op1);
                if (strcmp(code[j].op2, code[i].lhs) == 0)
                    strcpy(code[j].op2, code[i].op1);
            }
        }
    }
}

// Common Subexpression Elimination
void commonSubexprElimination() {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(code[i].op, code[j].op) == 0 &&
                strcmp(code[i].op1, code[j].op1) == 0 &&
                strcmp(code[i].op2, code[j].op2) == 0) {
                char temp[10];
                strcpy(temp, code[j].lhs);
                strcpy(code[j].lhs, code[i].lhs);
                for (int k = j + 1; k < count; k++) {
                    if (strcmp(code[k].op1, temp) == 0)
                        strcpy(code[k].op1, code[i].lhs);
                    if (strcmp(code[k].op2, temp) == 0)
                        strcpy(code[k].op2, code[i].lhs);
                }
            }
        }
    }
}

// Dead Code Elimination
void deadCodeElimination() {
    for (int i = count - 1; i >= 0; i--) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(code[j].op1, code[i].lhs) == 0 || strcmp(code[j].op2, code[i].lhs) == 0) {
                code[i].isUsed = 1;
                break;
            }
        }
    }
}

// Display optimized code only
void printOptimizedCode() {
    for (int i = 0; i < count; i++) {
        if (code[i].isUsed || i == count - 1) {
            if (strlen(code[i].op) == 0)
                printf("%s = %s\n", code[i].lhs, code[i].op1);
            else
                printf("%s = %s %s %s\n", code[i].lhs, code[i].op1, code[i].op, code[i].op2);
        }
    }
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    char line[50];

    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp))
        parse(line);
    fclose(fp);

    copyPropagation();
    commonSubexprElimination();
    deadCodeElimination();
    printOptimizedCode();

    return 0;
}
