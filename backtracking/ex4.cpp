#include <iostream>

int labirinto(int mapa[20][20], int linha, int coluna, int l_inicio, int c_inicio, int l_fim, int c_fim) {
    int l, c;
    
    if (mapa[l_fim][c_fim] == 1) return 0;

    if (l_inicio == -1 || c_inicio == -1 || c_inicio == coluna || l_inicio == linha) {
        return 0;
    }

    if (mapa[l_inicio][c_inicio] == 1 || mapa[l_inicio][c_inicio] == 9) {
        return 0;
    }


    if (l_inicio == l_fim & c_inicio == c_fim) {
        return 1;
    }

    mapa[l_inicio][c_inicio] = 9;

    int ans = labirinto(mapa, linha, coluna, l_inicio+1, c_inicio, l_fim, c_fim);
              
    if (ans == 0){
        labirinto(mapa, linha, coluna, l_inicio-1, c_inicio, l_fim, c_fim);
    };
    if (ans == 0) {
        labirinto(mapa, linha, coluna, l_inicio, c_inicio+1, l_fim, c_fim);
    }
    if (ans == 0) {
        labirinto(mapa, linha, coluna, l_inicio, c_inicio-1, l_fim, c_fim);
    }              

    mapa[l_inicio][c_inicio] = 0;

    return ans;
}

int main(){
    int l, c;
    std::cin >> l >> c;

    int l_inicio, c_inicio;
    std::cin >> l_inicio >> c_inicio;

    int l_fim, c_fim;
    std::cin >> l_fim >> c_fim;

    int mapa[20][20];
    for (int i=0; i< l; i++){
        for (int j=0; j<c; j++){
            std::cin >> mapa[i][j];
        }
    }

    int ans = labirinto(mapa, l, c, l_inicio, c_inicio, l_fim, c_fim);

    std::cout << ans << std::endl;

    return 0;
}