#include <iostream>

struct Vector{

    private:
        int data[1000]; // inicializacao de um array com 
                        //armazenamento de 1000 inteiros
        
        unsigned int size_, capacity_; //unsigned permite apenas naturais

    public:
        Vector(){
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
        return ((double)size_ / capacity_) * 100;
    }

    bool insert_at(unsigned int index, int value){
        if (size_ < capacity_ && index <= size_) {
            for (int i = size_ -1; i >= index; i--){
                data[i+1] = data[i];
            }

            data[index] = value;
            size_++;
            return true;
        }
        return false;
    }

    bool remove_at(unsigned int index){
        if (size_ > 0 && index < size_) {
            for (int i = index; i < size_ -1; i++){
                data[i] = data[i+1];
            }
            size_ = size_ -1;
            return true;
        }
        return false;
    }

    void push_back(int value) {
        if (size_ < capacity_) {
            //size_ = size_ + 1
            //for (int i = 0; i < size_; i++)
                //if (i == size_ -1){
                    //data[i] = value;
            data[size_] = value;
            size_++;
                }
        }
            
    }

    int sum() {
        int total = 0;
        for (int i=0; i<size_; i++){
            total = total + data[i];
        }
        return total;
    }

    int find(int value) {
        if (size_ == 0) {
            return -1;
        }
        else {
            for (int i=0; i<size_;i++){
                if (data[i] == value){
                    return i;
                }
            }
            return -1;
        }
    }
    
    int count(int value){
        if (size_ == 0) {
            return 0;
        }
        int counter = 0;

        for (int i = 0; i< size_; i++){
            if (data[i] == value){
                counter++;
            }
        }
        return counter;
    }

    bool remove(int value) {
        int index = find(value);

        if (index == -1) {
            return false;
        }
        remove_at(index);
        return true;
    }

    int front(){
        if (size_ > 0){
            return data[0];
        }
        else {
            return -1;
        }
        
    }

    int back(){
        if (size_ > 0) {
            return data[size_ -1];
        }
        else{
            return -1;
        }
    }

    bool pop_front(){
        int value = front();
        if (size_ > 0){

            for (int i = 0; i< size_-1;i++){
                data[i] = data[i+1];
            }
            size_--;
            return true;
        }
        return false;
        

        //ou

 //     if (size_ > 0) {
 //         remove_at(0); 
 //         return true;
 //     }
 //     return false;
    }

    bool pop_back(){
        int index = data[size_-1];
        if (size_>0){
            size_--;
            return true;
        }
        return false;
    }

    void push_front(int value) {
        if (size_ < capacity_) {
            for (int i = size_ -1; i>=0;i--){
                data[i+1] = data[i];
            }
            data[0] = value;
            size_++;
        }
    }







}