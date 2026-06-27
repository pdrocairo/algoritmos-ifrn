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

        ~listaLigada() {
            node *current = this->first;
            while (current != nullptr) {
                node *next_node = current->next;
                delete current;
                current = next_node;
            }
        }

    int front() {
        if (this->first != nullptr) {
            return this->first->value;                                        // se o primeiro nó nao for nulo, retorna o valor do primeiro nó
        }                                                                     // caso contrario, retorna -1 como um erro
        return -1;
    }

    int back() {
        if (this->last != nullptr) {
            return this->last->value;                                        // se o ultimo nó nao for nulo, retorna o valor do primeiro nó
        }                                                                    // caso contrario, retorna -1 como um erro
        return -1;
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

    int sum() {
        int ans = 0;                                                          // criamos um acumulador para contar
        node *current = this->first;                                          // criamos um ponteiro current para ir pulando de nó em nó
        while (current !=nullptr) {                                           // enquanto o current nao for nulo, ou seja, nao estiver no this->last->next ele vai somando os values de cada nó percorrido
            ans += current->value;
            current = current->next;
        }
        return ans;
    }

    int size() {
        int ans = 0;                                                          // criamos um acumulador para contar
        node *current = this->first;                                          // criamos um ponteiro current para ir pulando de nó em nó
        while (current != nullptr) {                                          // enquanto o current nao for nulo, ou seja, nao estiver no this->last->next ele vai contando quantos nós têm durante o percurso
            ans += 1;
            current = current->next;
        }
        return ans;
    }

    int get_at(int i){ 
        int ans = 0;                                                         // criamos um ans para iterar durante o while
        if (i < 0) {                                                          // se o indice pedido for igual ao ans ele para o while, pois achou o valor.
            return -1;
        }

        node *current = this-> first;                                         // o ponteiro current comeca no primeiro e vai ate o this->last->next, que e nulo

        while (current != nullptr) {
            
            if (i == ans) {
                return current->value;                                        // se o indice for encontrado, retorna o valor do nó nesse indice
            }

            current = current->next;                                          // pula para o proximo nó
            ans+=1;                                                           // adiciona mais 1 ao contador
        }
        
        return -1;                                                            // caso nao retorne nada no while, retorna -1 para dizer que nao há valores (trocar futuramente)
    }

    bool set_at(int i, int value) {
        if (i < 0) {
            return false;
        }
        int ans = 0;

        node *current = this-> first;

        while (current != nullptr) {
            if (i==ans) {
                current->value = value;
                return true;
            }

            current = current->next;
            ans +=1;
        }

        return false;
    }

    void insert_after(unsigned int x, int value) {
        node *current = this->first;

        while (current != nullptr) {
            if (current->value == x){
                if (current == this->last){
                    this->push_back(value);
                    return;
                }

                node *new_node = new node;
                new_node->value = value;
                new_node->next = current->next;
                current->next = new_node;
                return;
            }
            current = current->next;
        }
        this->push_back(value);
    }

    bool remove_at(int i) {
        if (i < 0 || i >= this->size()) {
            return false;
        } 

        if (i == 0){
            node *deletar = this->first;
            this->first = this->first->next;
            delete deletar;

            if (this->first == nullptr){
                this->last = nullptr;
            }
            return true;
        }

        node *current = this->first;
        for (int ans = 0; ans < i - 1; ans++) {
            current = current->next;                       
        }

        node *deletar = current->next;
        current->next = deletar->next;            
        
        if (deletar == this->last){
            this->last = current;
        }

        delete deletar;
        return true;
    }

    void move_min_to_first() {

        if (this->first == nullptr) {
            return;
        }
        node *current = this->first->next;              //comeca o loop do segundo item da lista
        node *menor = this->first;

        while (current != nullptr) {
            if (menor->value > current->value) {
                menor = current;
            }

            current = current->next;
        }
        
        int temporario = this->first->value;
        this->first->value = menor->value;
        menor->value = temporario;
    }

    unsigned int contar_numeros(const listaLigada &other) {
        node *current = this->first;
        
        int qtd = 0;
        while (current != nullptr) {
            node *current_other = other.first;
            while (current_other != nullptr) {
                if (current->value == current_other->value) {
                    qtd += 1;
                }
                current_other = current_other->next;
            }
            current = current->next;
            
        }
        return qtd;
    }

        void push_back_list(const listaLigada &other) {
            node *current = other.first;
            while (current != nullptr) {
                this->push_back(current->value);
                current = current->next;
            }
        }

};
