#include <iostream>
#include <unordered_set>


bool two_sum(int size_lista, int soma,int lista[100]) {
    std::unordered_set<int> numeros_vistos;

    for (int i=0; i< size_lista;i++){
        int numero_atual = lista[i];
        int complemento = soma - numero_atual;

        if (numeros_vistos.find(complemento) != numeros_vistos.end()) {
            return true;
        }

        numeros_vistos.insert(numero_atual);
    }

    return false;
}