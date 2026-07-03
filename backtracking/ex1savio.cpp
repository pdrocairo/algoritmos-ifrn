#include <iostream>
int caminho (int mapa[10][10], int linha, int coluna, int l, int c){
    if (l == linha || c == coluna || c == -1 || l == -1) {
        return 0;
    }
    if (mapa[l][c] == 1 && mapa[l][c] == 9){
        return 0;
    }
    if(l == linha-1 && c == coluna-1){
        return 1;
    }
    mapa[l][c] = 9;

    int caminhos = caminho(mapa, linha, coluna, l+1, c) +
                    caminho(mapa, linha, coluna, l, c+1) +
                    caminho(mapa, linha, coluna l-1, c) +
                    caminho(mapa, linha, coluna, l, c-1);
    mapa [l][c] = 0;
    return caminhos;

}