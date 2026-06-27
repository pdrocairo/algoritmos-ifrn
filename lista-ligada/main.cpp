#include "listaLigada.h"
#include <iostream>

void imprimir_lista(listaLigada &lista) {
    std::cout << "[ ";
    for (int i = 0; i < lista.size(); i++)
    {
            std::cout <<lista.get_at(i) << " ";
    }
    
    std::cout << "]\n";
}

int main(){
    listaLigada lista1;
    lista1.push_back(223);
    lista1.push_back(81);
    lista1.push_back(53);
    lista1.push_back(201);
    lista1.push_back(1);

    std::cout << "Lista Original: ";
    imprimir_lista(lista1);

    lista1.move_min_to_first();
    std::cout << "Lista com menor vindo primeiro: ";
    imprimir_lista(lista1);


    listaLigada lista2;
    lista2.push_back(1);
    lista2.push_back(5);
    lista2.push_back(7);
    lista2.push_back(15421);
    lista2.push_back(3);

    unsigned int comuns = lista1.contar_numeros(lista2);
    std::cout << "Quantidade de numeros comuns: " << comuns << "\n";

    std::cout << "Juntando as duas listas...";
    lista1.push_back_list(lista2);
    std::cout << "lista final";
    imprimir_lista(lista1);

    

}