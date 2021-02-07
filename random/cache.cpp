#include <iostream>
#include <string>
#include <chrono> 
#include <vector> 

using namespace std;
using namespace std::chrono;

#define comecaContagem high_resolution_clock::now
#define duracao(a) duration_cast<milliseconds>(a).count()
#define finalizaContagem(a) duracao(comecaContagem() - a)
#define imprimeTempo(a, b) cout << a << b << " ms" << endl

int main() {
    int n = 10000;
    vector<int> lista(n*n);

    auto inicio_1 = comecaContagem();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            lista[n * i + j] = 1;
    }

    auto tempo_1 = finalizaContagem(inicio_1);
    imprimeTempo("Tempo com cache: ", tempo_1);

    auto inicio_2 = comecaContagem();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            lista[i + n * j] = 1;
    }

    auto tempo_2 = finalizaContagem(inicio_2);
    imprimeTempo("Tempo sem cache: ", tempo_2);

    return 0;
}