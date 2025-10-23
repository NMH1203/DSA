#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 


int main() {
    int n;
    char ns[100]; 

    scanf("%d", &n);
    sprintf(ns, "%d", n);
    int l = strlen(ns);
    
    if (l > 1) {
        char temp = ns[0];
        ns[0] = ns[l - 1];
        ns[l - 1] = temp;
    }
    n = atoi(ns);

    printf("%d", n);

    return 0;
}
