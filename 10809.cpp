#include <stdio.h>
int main() {
    char S[101];
    scanf("%s", S);
    int Apb[150];
    for (int i = 95; i < 130; i++)
        Apb[i] = -1;
    int tmp = 0, i = 0;
    while(1) {
        if (S[i] == '\0')
            break;
        tmp = S[i];
        if (Apb[tmp] == -1)
            Apb[tmp] = i++;
    }
    for (int i = 97; i < 123; i++) {
        if ( i != 122)
            printf("%d ", Apb[i]);
        else
            printf("%d", Apb[i]);
    }
    printf("\n");
    return 0;
}