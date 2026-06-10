class ll_int {
    private:
        struct ll_int_node {
            int value; // o dado em si
            struct ll_int_node *next; // ponteiro: endereço do próximo nó
        };
        ll_int_node *first, *last; // ponteiros para o primeiro e último nó da lista

    public:
        ll_int() {
            this->first = nullptr;
            this->last = nullptr;
        }
        
        void push_front(int value) {
            ll_int_node *new_node = new ll_int_node;
            new_node->value = value;
            new_node->next = this->first;
            if (this->first == nullptr) {
                this->last = new_node;
            }
            this->first = new_node;
        }

        void push_back(int value) {
            ll_int_node *new_node = new ll_int_node; // aloca memória pra um novo nó
            new_node->value = value; // guarda o valor do nó
            new_node->next = nullptr; // é o último, não aponta pra ninguém
            if (this->first == nullptr) { // lista vazia?
                this->first = new_node; // ele é o primeiro também
            } else {
                this->last->next = new_node; // o antigo último aponta pro novo
            }
            this->last = new_node; // atualiza o último
        }

        void pop_front() {
            if (this->first == nullptr) {
                return;
            }
            ll_int_node *to_remove = this->first; // guarda quem vai ser deletado
            if (this->last == this->first) {
                this->last = nullptr;
            }
            this->first = this->first->next; // o segundo vira o novo primeiro
            delete to_remove; // libera a memória do nó removido
        }

        void pop_back() {
            if (this->last == nullptr) {
                return;
            }
            if (this->first == this->last) {
                delete this->first;
                this->first = nullptr;
                this->last = nullptr;
            }
            ll_int_node *current = this->first;
            while (current->next != this->last) {
                current = current->next;
            }
            current->next = nullptr;
            delete this->last;
            this->last = current;
        }

        int front() {
            if (this->first != nullptr) {
                return this->first->value;
            }
            return -1;
        }

        int back() {
            if (this->last != nullptr) {
                return this->last->value;
            }
            return -1;
        }

        int sum () {
            int ans = 0;
            ll_int_node *current = this->first;
            while (current != 0) {
                ans += current->value;
                current = current->next;
            }
            return ans;
        }
       
};