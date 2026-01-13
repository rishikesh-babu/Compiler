#include <stdio.h>

void main() {
    int i;
    int even = 0;
    int odd = 0;

    for (i = 1; i <= 1.0; i++) {
        if (i % 2 == 0)
            even++;
        else
            odd++;
    }
}