#include <iostream>


struct Calcular{
    // int num, num2;

    void palindromo(std::string text){
        for (int i = 0;)
    }

    void tabuada(double num){
        
        for (int i =1; i<=10; i++){
		    std::cout << num << " x " << i << " = " << (num * i) << std::endl;
        }
    }

    void runMethod() {
        std::cout << "METODO DENTRO DO STRUCT ESTA RODANDO PERFEITAMENTE" << std::endl;
    }

};

int main(){
    Calcular obj;
    obj.runMethod();
    obj.tabuada(5);
    return 0;
}