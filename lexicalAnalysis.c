#include <stdio.h>
#include <ctype.h> 
#include <string.h> 

int isKeyword(char *word) { 
    char keywords[][10] = {"int", "void", "float", "if", "else", "while", "for", "return"}; 
    int length = sizeof(keywords) / sizeof(keywords[0]); 
    
    for (int i = 0; i < length; ++i) { 
        if (strcmp(word, keywords[i]) == 0) { 
            return 1; 
        }
    }

    return 0; 
}

int isHeader(char *word) { 
    char headers[][10] = {"stdio.h"} ; 
    int length = sizeof(headers) / sizeof(headers[0]); 

    for (int i = 0; i < length; ++i) { 
        if (strcmp(word, headers[i]) == 0) { 
            return 1; 
        }
    }

    return 0; 
}

int isOperator(char c) { 
    char operators[] = {'+', '-', '*', '/', '<', '>', '=', '|', '&', '%', '!'}; 
    int length = sizeof(operators) / sizeof(operators[0]); 

    for (int i = 0; i < length; ++i) { 
        if (c == operators[i]) { 
            return 1; 
        }
    }

    return 0; 
}

int isPunctuators(char c) { 
    char punctuators[] = {'(', ')', '[', ']', '{', '}', ',', ';'}; 
    int length = sizeof(punctuators) / sizeof(punctuators[0]); 

    for (int i = 0; i < length; ++i) { 
        if (c == punctuators[i]) { 
            return 1; 
        }
    }

    return 0; 
}

int main() { 
    char line[100], word[10]; 

    FILE *input, *output; 
    input = fopen("input.c", "r"); 
    output = fopen("output.txt", "w"); 

    while (fscanf(input, "%s", line) == 1) { 
        int i = 0; 
        
        while (line[i] != '\0') {
            int check = 0; 
            int j = 0; 

            while (line[i] != '\0') { 
                if (isalnum(line[i]) || line[i] == '_' || line[i] == '#' || line[i] == '.') { 
                    word[j++] = line[i]; 
                    ++i; 
                } else { 
                    check = 1;  
                    break; 
                }
            }
            word[j] = '\0';
            
            if (j > 0) { 
                int isNumber = 1; 
                for (int i = 0; i < word[i] != '\0'; ++i) { 
                    if (!isdigit(word[i]) && word[i] != '.') { 
                        isNumber = 0; 
                        break; 
                    }
                }
                
                if (isNumber) { 
                    printf("<number, %s> \n", word); 
                    fprintf(output, "<number, %s> \n", word); 
                } else { 
                    if (isKeyword(word)) { 
                        printf("<keyword, %s> \n", word); 
                        fprintf(output, "<keyword, %s> \n", word); 
                    } else if (word[0] == '#') {
                        printf("<preprocessor, %s> \n", word); 
                        fprintf(output, "<preprocessor, %s> \n", word); 
                    } else if (isHeader(word)) {
                        printf("<header, %s> \n", word); 
                        fprintf(output, "<header, %s> \n", word); 
                    } else { 
                        printf("<identifier, %s> \n", word); 
                        fprintf(output, "<identifier, %s> \n", word); 
                    }
                }
            }
            
            if (check) { 
                char c;  
                c = line[i]; 
                
                if (isPunctuators(c)) { 
                    printf("<punctuator, %c> \n", c); 
                    fprintf(output, "<punctuator, %c> \n", c); 
                } else if (isOperator(c)) {
                    printf("<operator, %c> \n", c); 
                    fprintf(output, "<operators, %c> \n", c); 
                } else { 
                    printf("<invalid, %c> \n", c); 
                    fprintf(output, "<invalid, %c> \n", c); 
                } 
                
                ++i; 
            }
        }
    }

    return 0; 
}