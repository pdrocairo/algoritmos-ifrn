class listaLigada {
    private:
        struct node {                                                         // base para criacao de um no
            int value;                                                        // ele tem um valor
            struct node *next;                                                // e um endereco que leva para o no seguinte
        };
        node *first, *last;                                                   // tbm tera dois ponteiros apontando para o primeiro e ultimo para facilitar calculos

    public:
        listaLigada(){
            this->first = nullptr;                                            // o construtor inicializa eles como null
            this->last = nullptr;
        }

    void push_front(int value) {
        node *new_node = new node;                                            // cria novo no
        new_node->value = value;                                              // atribui ao value do no, o valor inserido na funcao
        new_node->next = this->first;                                         // o node.next agora aponta para o antigo primeiro no, que agora sera o segundo
        if (this->first == nullptr) {                                         // se nao houver nos ainda, o last apontara para o novo que sera o primeiro
            this->last = new_node;
        }
        this->first= new_node;                                                // o first agora aponta para o novo no, ja que ele sera o primeiro
    }

    void push_back (int value) {
        node *new_node = new node;                                            //cria novo no
        new_node->value = value;                                              //atribui ao value do no, o valor inserido na funcao
        new_node->next = nullptr;                                             //como o novo no sera o ultimo, o ponteiro do prxm no eh nulo
        if (this->first == nullptr) {                                         //caso seja o primeiro no criado, o first aponta para o novo no criado    
            this->first = new_node;                                           
        }
        else {
            this->last->next = new_node;                                      //se n for o primeiro no, o antigo ultimo node.next apontara para o novo no 
        }
        this->last = new_node;                                                //agora o novo no sera o last
    }

};