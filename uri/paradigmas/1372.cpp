#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <memory.h>

#define FOR(i, a) for(int i = 0; i < a; i++)

using namespace std;

int M, N;
long long int tab[100000], linha[100000], linhas[100000];

void melhor_linha(int id) {

    if(tab[id] != -1) return;

    if(id >= N) {
            tab[id] = 0;
            return;
    }

    melhor_linha(id + 1);
    melhor_linha(id + 2);

    tab[id] = max(linha[id] + tab[id + 2], tab[id + 1]);
}

void melhor_grade(int linha) {

    if(tab[linha] != -1) return;

    if(linha >= M) {
            tab[linha] = 0;
            return;
    }

    melhor_grade(linha + 1);
    melhor_grade(linha + 2);

    tab[linha] = max(linhas[linha] + tab[linha + 2], tab[linha + 1]);

}

int main() {

    scanf("%d%d", &M, &N);

    while(M) {

        FOR(i, M) {
            memset(tab, -1, sizeof(tab));
            FOR(j, N) {
                scanf("%d", &linha[j]);
            }
            melhor_linha(0);
            linhas[i] = tab[0];
        }

        memset(tab, -1, sizeof(tab));

        melhor_grade(0);

        printf("%lld\n", tab[0]);

       scanf("%d%d", &M, &N);
    }

    return 0;
}