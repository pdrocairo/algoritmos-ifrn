#include "ordenacao.hpp"

bool ordenado(int a[],  unsigned int t){
    for (unsigned int i = 1; i < t; i++) {          //retorna false se ta desordenado e true se ta ordenado
        if (a[i]<a[i-1]) {
            return false;
        }
    }
    return true;
}

void selecao(int a[], unsigned int t){ 
    for (unsigned int i = 0; i < t - 1; i++) {
        unsigned int min = i;
        for (unsigned int j = i+1; j < t; j++) {  // se o proximo(j) for menor que o index atual(i), atualiza o menorindex para esse novo menor.
            if (a[j] < a[min]) {                  // e segue buscando ate o fim do loop j.
                min = j;                          // apos isso ele pega o valor do numero na posicao i (o maior)
            }                                     // e troca com o da posicao menor.
        }
        
        int aux = a[i];
        a[i] = a[min];
        a[min] = aux;
    }
    
}

void insercao(int a[], unsigned int t){  
    for (unsigned int i=1; i< t; i++){
            int idx = i;
            for (int j = i-1; j>-1;j--){           //compara com a posicao anterior ao index atual, se o atual for menor que o anterior troca posicao,
                if (a[idx]<a[j]){                  //decrementa 1 do index atual e decrementa 1 do anterior. se anterior for igual a -1, quebra o laco interno.
                    int aux = a[idx];              // laco externo nunca para, sempre segue a indo p direita, porem o index atual volta 1 casa se alterado a posicao do valor dele
                    a[idx] = a[j];                 // pois eh ele quem e comparado com o valor anterior
                    a[j] = aux;
                    idx--;
                }
                else{
                    break;
                }
            }

    }

    
}


void merge(int a[], int i1, int j1, int i2, int j2) {
    int *temp = new int[((j1 - i1) + (j2 - i2) + 2)];
    int i, j, k;
    i = i1;
    j = i2;
    k = 0;

    while (i <= j1 and j <= j2) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }

    while (i <= j1) {
        temp[k++] = a[i++];
    }

    while (j <= j2) {
        temp[k++] = a[j++];
    }

    for (i = i1, j = 0;i <= j2;i++, j++) {
        a[i] = temp[j];
    }

    delete[] temp;
}

void merge_sort_r(int a[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort_r(a, inicio, meio);
        merge_sort_r(a, meio + 1, fim);
        merge(a, inicio, meio, meio + 1, fim);      
    }
}

void merge_sort(int a[], unsigned int t) {
    if (t > 1) {
        merge_sort_r(a, 0, t - 1);
    }
};