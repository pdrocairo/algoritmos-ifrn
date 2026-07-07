#include <iostream>

int labirinto_bt(int labirinto[20][20], int linha, int coluna, int l, int c) {
	if (l == linha || c == coluna || l == -1 || c == -1) {
		return 0;
	}

	if (labirinto[l][c] == 1 || labirinto[l][c] == 9) {
		return 0;
	}
	
	if (c == coluna -1 && l == linha -1) {
		return 1;
	}
	
	labirinto[l][c] = 9;

	int ans = labirinto_bt(labirinto, linha, coluna, l+1, c) +   // baixo
			  labirinto_bt(labirinto, linha, coluna, l, c + 1) + // direita
              labirinto_bt(labirinto, linha, coluna, l, c - 1) + // esquerda
              labirinto_bt(labirinto, linha, coluna, l - 1, c);  // cima
	
	labirinto[l][c] = 0;
	
	return ans;
}	
	
	
int main(){
	
	int labirinto[20][20] = {
		
		{0,1,0,1},
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0}
	};
	
	int caminhos = labirinto_bt(labirinto,4,4,0,0);
	std::cout << "Total de caminhos para sair: " << caminhos << std::endl;
	
	return 0;
};