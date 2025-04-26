#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100
// Predefined list of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
const int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

int isKeyword(const char *token) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1; // True
        }
    }
    return 0; // False
}

int isIdentifier(char *token) {
    if (!isalpha(token[0]) && token[0] != '_') {
        return 0; // Identifier must start with a letter or underscore
    }
    for (int i = 1; token[i] != '\0'; i++) {
        if (!isalnum(token[i]) && token[i] != '_') {
            return 0; // Identifier can only contain letters, numbers, and underscores
        }
    }
    return 1; // It's a valid identifier if it's not a keyword
}

int isOperator(char ch) {
    return strchr("+-*/=<>!&|", ch) != NULL;
}

int isSpecialSymbol(char ch) {
    return strchr("(){}[],;", ch) != NULL;
}

int main() {
    char code[1024] = "";
    char tokens[MAX_TOKENS][50];
    int tokenCount = 0;
    printf("Enter code Snippet: ");
    while (1) {
        char temp[256];
        if (scanf("%[^\n]", temp) != 1) break;
        if (strlen(temp) == 1) break;
        strcat(code, temp);
        strcat(code, " ");
    }

    char *token = strtok(code, " \n\t");
    while (token != NULL && tokenCount < MAX_TOKENS) {
        strcpy(tokens[tokenCount++], token);
        token = strtok(NULL, " \n\t");
    }
    printf("Categorized Token: \n");
    for (int i = 0; i < tokenCount; i++) {
        if (isKeyword(tokens[i])) printf("Keyword: %s\n", tokens[i]);
        else if (strlen(tokens[i]) == 1 && isOperator(tokens[i][0])) printf("Operator: %s\n", tokens[i]); // CHANGED
        else if (strlen(tokens[i]) == 1 && isSpecialSymbol(tokens[i][0])) printf("Special Symbol: %s\n", tokens[i]); //CHANGED
        else if (isIdentifier(tokens[i])) printf("Identifier: %s\n", tokens[i]);
        else printf("Unknown Token: %s\n", tokens[i]);
    }
    return 0;
}
