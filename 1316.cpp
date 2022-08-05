#include <stdio.h>
bool check[100];
int main() {
    int num;
    char word[100];
    scanf("%d", &num);
    int cnt = 0;
    for (int i = 0; i < num; i++) {
        scanf("%s", word);
        int tmp = 0;
        int j = 0;
        while(word[j] != 0) {
            if (j>=1 && (word[j] == word[j-1])) {
                j++;
                continue;
            }
            if ((check[word[j]-'a']) == 1) {
                tmp = -1;
                break;
            }
            check[word[j] - 'a'] = 1;
            j++;
        }
        for (int k = 0; k < 100; k++) {
            check[k] = 0;
        }
        if (tmp != -1)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}

