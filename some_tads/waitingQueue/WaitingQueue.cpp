/* MODULO PARA IMPLEMENTACAO DE FUNCOES PARA O TAD WaitingQueue */


#include "WaitingQueue.h"


namespace WaitingQueueTAD {


    WaitingQueue* createQueue() {
        // Aloca memoria dinamicamente para a estrutura WaitingQueue
        WaitingQueue* queue = new WaitingQueue;

        // Verifica se a alocacao falhou
        if (!queue) {
            std::cout << "Nao conseguimos alocar memoria" << std::endl;
            return nullptr;
        }

        // Inicializa todos os contadores como zero
        queue->generalCount = queue->elderlyCount = queue->elderlyAttended = 0;

        // Inicializa os ponteiros das filas como nullptr (filas vazias)
        queue->elderlyFirst = queue->elderlyLast = nullptr;
        queue->generalFirst = queue->generalLast = nullptr;

        return queue;
    }


    void enqueue(WaitingQueue* queue, Client client) {
        // Verifica se o ponteiro da fila e valido
        if (!queue) {
            std::cout << "Fila invalida" << std::endl;
            return;
        }

        // Aloca memoria para um novo no
        QueueNode* node = new QueueNode;

        // Verifica se a alocacao do no falhou
        if (!node) {
            std::cout << "Nao conseguimos alocar memoria para o cliente" << std::endl;
            return;
        }

        node->client = client; // Armazena o cliente no no
        node->next = node->previous = nullptr; // Inicializa os ponteiros do no

        // Se o cliente for idoso (prioridade 1)
        if (client.priority == 1) {
            // Se a fila de idosos esta vazia, o no sera o primeiro e ultimo
            if (queue->elderlyFirst == nullptr) {
                queue->elderlyFirst = queue->elderlyLast = node;
            } else {
                // Adiciona o no ao final da fila de idosos
                queue->elderlyLast->next = node;
                node->previous = queue->elderlyLast;
                queue->elderlyLast = node;
            }
            queue->elderlyCount += 1; // Incrementa o contador de idosos

        } else {
            // Mesma logica para a fila geral
            if (queue->generalFirst == nullptr) {
                queue->generalFirst = queue->generalLast = node;
            } else {
                queue->generalLast->next = node;
                node->previous = queue->generalLast;
                queue->generalLast = node;
            }
            queue->generalCount += 1; // Incrementa o contador geral
        }
    }


    int peek(const WaitingQueue* queue, Client* returnClient) {
        // Verifica se a fila e invalida, vazia ou se o ponteiro de retorno e nulo
        if (!queue || (queue->elderlyCount == 0 && queue->generalCount == 0) || !returnClient) {
            std::cout << "Fila vazia ou invalida" << std::endl;
            return 0;
        }

        // Da prioridade aos idosos se menos de 2 foram atendidos
        if (queue->elderlyAttended < 2) {
            if (queue->elderlyCount == 0) {
                // Se nao ha idosos, pega o primeiro da fila geral
                if (!queue->generalFirst) {
                    std::cout << "Erro interno: fila geral vazia" << std::endl;
                    return 0;
                }
                *returnClient = queue->generalFirst->client;
            } else {
                // Pega o primeiro idoso
                if (!queue->elderlyFirst) {
                    std::cout << "Erro interno: fila de idosos vazia" << std::endl;
                    return 0;
                }
                *returnClient = queue->elderlyFirst->client;
            }

        } else {
            // Apos 2 idosos atendidos, prioriza a fila geral
            if (queue->generalCount == 0) {
                if (!queue->elderlyFirst) {
                    std::cout << "Erro interno: fila de idosos vazia" << std::endl;
                    return 0;
                }
                *returnClient = queue->elderlyFirst->client;
            } else {
                if (!queue->generalFirst) {
                    std::cout << "Erro interno: fila geral vazia" << std::endl;
                    return 0;
                }
                *returnClient = queue->generalFirst->client;
            }
        }
        
        // Exibe informacoes do proximo cliente
        std::cout << "Proximo atendimento:\n  * Nome: " << returnClient->name 
                << "\n  * Prioridade: " << (returnClient->priority == 1 ? "Idoso" : "Geral") << std::endl;

        return 1;
    }


    int dequeue(WaitingQueue* queue, Client* returnClient) {
        // Verifica se a fila e invalida, vazia ou se o ponteiro de retorno e nulo
        if (!queue || (queue->elderlyCount == 0 && queue->generalCount == 0) || !returnClient) {
            std::cout << "Nao conseguimos remover o proximo cliente a ser atendido" << std::endl;
            return 0;
        }

        // Prioridade para idosos se menos de 2 foram atendidos
        if (queue->elderlyAttended < 2) {
            if (queue->elderlyCount > 0) {
                QueueNode* aux1 = queue->elderlyFirst; // Pega o primeiro idoso
                *returnClient = aux1->client; // Copia os dados do cliente
                queue->elderlyFirst = aux1->next; // Atualiza o inicio da fila
                if (queue->elderlyFirst) queue->elderlyFirst->previous = nullptr; // Ajusta o ponteiro anterior
                else queue->elderlyLast = nullptr; // Se a fila ficou vazia, ajusta o fim
                delete aux1; // Libera o no removido
                queue->elderlyCount -= 1; // Decrementa o contador de idosos
                queue->elderlyAttended += 1; // Incrementa o contador de idosos atendidos
            } else {
                QueueNode* aux1 = queue->generalFirst; // Pega o primeiro da fila geral
                *returnClient = aux1->client;
                queue->generalFirst = aux1->next;
                if (queue->generalFirst) queue->generalFirst->previous = nullptr;
                else queue->generalLast = nullptr;
                delete aux1;
                queue->generalCount -= 1; // Decrementa o contador geral
            }

        } else {
            // Apos 2 idosos, atende a fila geral e reseta o contador de idosos atendidos
            QueueNode* aux1 = queue->generalFirst;
            *returnClient = aux1->client;
            queue->generalFirst = aux1->next;
            if (queue->generalFirst) queue->generalFirst->previous = nullptr;
            else queue->generalLast = nullptr;
            delete aux1;
            queue->generalCount -= 1;
            queue->elderlyAttended = 0; // Reseta a contagem de idosos atendidos
        }

        // Exibe informacoes do cliente atendido
        std::cout << "Cliente atendido:\n  * Nome: " << returnClient->name 
                << "\n  * Prioridade: " << (returnClient->priority == 1 ? "Idoso" : "Geral") << std::endl;

        return 1;
    }


    int removeClient(WaitingQueue* queue, char* name) {
        // Verifica se a fila e invalida ou vazia
        if (!queue || (queue->elderlyCount == 0 && queue->generalCount == 0)) {
            std::cout << "Fila vazia ou invalida.\n";
            return 0;
        }

        // Procura na fila de idosos
        QueueNode* current = queue->elderlyFirst;

        while (current != nullptr) {
            // Compara o nome do cliente atual com o fornecido
            if (strcmp(current->client.name, name) == 0) {
                // Se for o primeiro da fila
                if (current == queue->elderlyFirst) {
                    queue->elderlyFirst = current->next;
                    if (queue->elderlyFirst) queue->elderlyFirst->previous = nullptr;
                    else queue->elderlyLast = nullptr; // Fila vazia
                } else if (current == queue->elderlyLast) {
                    // Se for o ultimo da fila
                    queue->elderlyLast = current->previous;
                    queue->elderlyLast->next = nullptr;
                } else {
                    // Se estiver no meio da fila
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                }
                std::cout << "Cliente removido com sucesso:\n";
                std::cout << "  * Nome: " << current->client.name 
                        << "\n  * Prioridade: " << (current->client.priority == 1 ? "Idoso" : "Geral") << std::endl;
                delete current; // Libera o no removido
                queue->elderlyCount -= 1; // Decrementa o contador
                return 1; // Retorna 1 para sucesso
            }
            current = current->next; // Avanca para o proximo no
        }

        // Procura na fila geral
        current = queue->generalFirst;
        while (current != nullptr) {
            if (strcmp(current->client.name, name) == 0) {
                if (current == queue->generalFirst) {
                    queue->generalFirst = current->next;
                    if (queue->generalFirst) queue->generalFirst->previous = nullptr;
                    else queue->generalLast = nullptr;
                } else if (current == queue->generalLast) {
                    queue->generalLast = current->previous;
                    queue->generalLast->next = nullptr;
                } else {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                }
                std::cout << "Cliente removido com sucesso:\n";
                std::cout << "  * Nome: " << current->client.name 
                        << "\n  * Prioridade: " << (current->client.priority == 1 ? "Idoso" : "Geral") << std::endl;
                delete current;
                queue->generalCount -= 1;
                return 1;
            }
            current = current->next;
        }

        std::cout << "Cliente nao encontrado.\n";

        return 0;
    }


    Client* getQueueOrder(const WaitingQueue* queue, int* numClients) {
        // Verifica se a fila e invalida, vazia ou se o ponteiro de tamanho e nulo
        if (!queue || (queue->elderlyCount == 0 && queue->generalCount == 0) || !numClients) {
            return nullptr;
        }

        *numClients = queue->elderlyCount + queue->generalCount; // Calcula o total de clientes
        Client* clientOrder = new Client[*numClients]; // Aloca array para os clientes
        WaitingQueue* copyQueue = createQueue();  // Cria uma copia da fila para nao modificar a original

        QueueNode* current = queue->elderlyFirst;  // Copia os clientes da fila de idosos
        while (current) {
            enqueue(copyQueue, current->client);
            current = current->next;
        }

        // Copia os clientes da fila geral
        current = queue->generalFirst;
        while (current) {
            enqueue(copyQueue, current->client);
            current = current->next;
        }

        Client nextClient; // Variavel temporaria para armazenar clientes removidos

        // Remove cada cliente da copia e adiciona ao array
        for (int i = 0; i < *numClients; i++) {
            dequeue(copyQueue, &nextClient);
            clientOrder[i] = nextClient;
        }

        deleteQueue(copyQueue); // Libera a copia da fila

        return clientOrder;
    }


    void deleteQueue(WaitingQueue* queue) {
        // Verifica se a fila e valida
        if (!queue) return;

        // Libera todos os nos da fila de idosos
        QueueNode* aux1 = queue->elderlyFirst;

        while (aux1) {
            QueueNode* nextOne1 = aux1->next; // Salva o proximo antes de liberar
            delete aux1; // Libera o no atual
            aux1 = nextOne1; // Avanca para o proximo
        }

        // Libera todos os nos da fila geral
        QueueNode* aux2 = queue->generalFirst;
        while (aux2) {
            QueueNode* nextOne2 = aux2->next;
            delete aux2;
            aux2 = nextOne2;
        }

        delete queue;
    }

} // Namespace WaitingQueueTAD
