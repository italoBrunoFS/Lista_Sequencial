#include <iostream>
#include <stdexcept>

class ListaSequencial {
private:
    int Array_Lista[100];
    int tamanho;

public:
    ListaSequencial() : tamanho(0) {}

    int GetTamanho() { return tamanho; }
    bool ListaVazia() { return tamanho == 0; }
    bool ListaCheia() { return tamanho == 100; }

    int ObterValor(int pos) {
        if (!ListaVazia() && pos > 0 && pos <= tamanho) {
            return Array_Lista[pos - 1];
        }
        throw std::invalid_argument("Posição Inválida ou Lista Vazia");
    }

    void ModificarLista(int pos, int n) {
        if (!ListaVazia() && pos > 0 && pos <= tamanho) {
            Array_Lista[pos - 1] = n;
        } else {
            throw std::invalid_argument("Posição Inválida ou Lista Vazia");
        }
    }

    void InserirElemento(int n, int pos) {
        if (!ListaCheia() && pos > 0 && pos <= tamanho + 1) {
            for (int i = tamanho; i >= pos; i--) {
                Array_Lista[i] = Array_Lista[i - 1];
            }
            Array_Lista[pos - 1] = n;
            tamanho++;
        } else {
            throw std::invalid_argument("Posição Inválida ou Lista Cheia");
        }
    }

    void RemoverElemento(int pos) {
        if (!ListaVazia() && pos > 0 && pos <= tamanho) {
            for (int i = pos - 1; i < tamanho - 1; i++) {
                Array_Lista[i] = Array_Lista[i + 1];
            }
            tamanho--;
        } else {
            throw std::invalid_argument("Posição Inválida ou Lista Vazia");
        }
    }
};

int main() {
    ListaSequencial lista;
    int n;
    std::cout << "Nova lista criada!\nMenu:\n";
    std::cout << "1- Inserir Elemento\n2- Remover Elemento\n3- Modificar Elemento\n4- Obter Elemento\n5- Verificar se a Lista está Vazia\n6- Verificar se a Lista está Cheia\n7- Exibir Lista\n8- Sair\n";
    
    while (std::cin >> n && n != 8) {
        try {
            if (n == 1) {
                int NumElementos;
                std::cout << "Digite quantos elementos quer inserir na lista: ";
                std::cin >> NumElementos;
                for (int i = 0; i < NumElementos; i++) {
                    int Elemento, pos1;
                    std::cout << "Digite o elemento que deseja adicionar: ";
                    std::cin >> Elemento;
                    std::cout << "Digite a posição: ";
                    std::cin >> pos1;
                    lista.InserirElemento(Elemento, pos1);
                }
                std::cout << "Todos os Elementos inseridos com Sucesso!\n";
            } else if (n == 2) {
                int pos;
                std::cout << "Digite a posição do elemento que quer remover: ";
                std::cin >> pos;
                lista.RemoverElemento(pos);
                std::cout << "Removido Com Sucesso!\n";
            } else if (n == 3) {
                int pos, valor;
                std::cout << "Digite a posição do elemento que quer modificar: ";
                std::cin >> pos;
                std::cout << "Digite o novo valor: ";
                std::cin >> valor;
                lista.ModificarLista(pos, valor);
                std::cout << "Modificado Com Sucesso!\n";
            } else if (n == 4) {
                int pos;
                std::cout << "Digite a posição do elemento que quer obter: ";
                std::cin >> pos;
                std::cout << "Valor: " << lista.ObterValor(pos) << "\n";
            } else if (n == 5) {
                std::cout << (lista.ListaVazia() ? "A lista está vazia.\n" : "A lista não está vazia.\n");
            } else if (n == 6) {
                std::cout << (lista.ListaCheia() ? "A lista está cheia.\n" : "A lista não está cheia.\n");
            } else if (n == 7) {
                for (int i = 1; i <= lista.GetTamanho(); i++) {
                    std::cout << lista.ObterValor(i) << " ";
                }
                std::cout << "\n";
            } else {
                std::cout << "Opção Inválida!\n";
            }
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }
    return 0;
}
