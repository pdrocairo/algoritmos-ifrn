#include <iostream>

struct Vector{

    private:
        int data[1000]; // inicializacao de um array com 
                        //armazenamento de 1000 inteiros
        
        unsigned int size_, capacity_; //unsigned permite apenas naturais

    public:
        vector(){
            this->size_ = 0; //tamanho da lista iniciando em 0
            this->capacity_=1000; //controla numero maximo de itens que pode ser armazenado no array
        }

    unsigned int size(){return size_;} //get_size

    unsigned int capacity(){return capacity_;} //get_capacity

    void clear(){
        size_ = 0;
    }

    int get_At(unsigned int index){
        if(size_ > 0 && index < size_){
            return data[index];
        }
        return -1;
    }

    double percent_occupied() {
        return (size_ / capacity_) * 100
    }

    bool insert_at(unsigned int index, int value){
        if (size_ < capacity_ && index <= size_) {
            for (int i = size_ -1; i >= index; i--){
                data[i+1] = data[i];
            }

            data[index] = value;
            size++;
            return true;
        }
        return false;
    }







}