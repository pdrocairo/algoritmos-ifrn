//EXCALIDRAW LINK: https://excalidraw.com/#json=ZcLExLzsjHwv_xzE-JJqF,mdDk-0TtevnRWOtvJoKmPg

// A função recebe a matriz (labirinto), tamanho de (linha e coluna) e a posição atual (l e c)
int labirinto_bt(int labirinto[20][20], int linha, int coluna, int l, int c) { 
    
    // 1. False se saiu dos limites da matriz ou encontrou uma parede ou celula ja visitada
    //0 significa caminho livre, qualquer outro número barra passagem.
    if (l == -1 or c == -1 or l == linha or c == coluna or labirinto[l][c] != 0) {
        return 0; // Nenhum caminho foi achado soma 0 na recursao
    } 
    
    // 2. True se chegou exatamente na última célula do labirinto
    if (l == linha - 1 and c == coluna - 1) {
        return 1; // Encontrou 1 caminho soma 1 na recursao
    } 
    

    // Marca a celula atual para avisar que ja passou e evitar ciclos, como joao e maria que deixava pedrinhas no caminho..
    labirinto[l][c] = 9; 
    
    // chamadas recursivas para as 4 direções
    // A recursao "pausa" a execução atual, chama a próxima e guarda o resultado.
    int ans = labirinto_bt(labirinto, linha, coluna, l + 1, c) + // Baixo
              labirinto_bt(labirinto, linha, coluna, l, c + 1) + // Direita
              labirinto_bt(labirinto, linha, coluna, l, c - 1) + // Esquerda
              labirinto_bt(labirinto, linha, coluna, l - 1, c);  // Cima
              
    // BACKTRACKING: Após tentar de tudo a partir daqui, "desmarcamos" a célula
    // restaurando seu valor original para que outros caminhos alternativos possam usá-la.

    labirinto[l][c] = 0; 
    
    return ans; // retorna o total de caminhos encontrados
}



// ====================================================== MAIN =======================================================================//
int main() {
    int labirinto[20][20] = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 0, 0}
    };
    
    // Chama a função começando na posição (0, 0)
    int totalCaminhos = labirinto_bt(labirinto, 4, 4, 0, 0);
    std::cout << "Total de caminhos para sair: " << totalCaminhos << std::endl;
    
    return 0;
}// ====================================================== MAIN =======================================================================//
