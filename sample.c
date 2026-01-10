#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

int main() {
    char *c = "123";
    if (isdigit(c)) {
        printf("%s is a digit", c);
    } else {
        printf("%s is not a digit", c);
    }
    
    printf("Completed"); 
    return 0;
}