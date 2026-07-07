#include <iostream>

int labirinto(int mapa[20][20], int linha, int coluna, int l, int c) {
    if (l == linha || c == coluna || l == -1 || c == -1) {
        return 999999;
    }

    if (mapa[l][c] == 1 || mapa[l][c] == 9){
        return 999999;
    }

    if (l == linha -1 && c == coluna -1) {
        return 1;
    }

    mapa[l][c] = 9;

    int baixo = labirinto(mapa, linha, coluna, l+1, c);//baixo
    int cima = labirinto(mapa, linha, coluna, l-1, c); //cima
    int direita = labirinto(mapa, linha, coluna, l, c+1); //direita 
    int esquerda = labirinto(mapa, linha, coluna, l, c-1);  //esquerda

    mapa[l][c] = 0;

    int menor = std::min(std::min(baixo,cima), std::min(esquerda,direita));

    if (menor == 999999) return 999999;
    return menor + 1;

    
}

int main(){
    int l, c;
    std::cin >> l >> c;
    int mapa[20][20];
    for (int i=0; i< l; i++){
        for (int j=0; j<c; j++){
            std::cin >> mapa[i][j];
        }
    }

    int ans = labirinto(mapa, l, c, 0, 0);

    std::cout << ans << std::endl;

    return 0;
}

