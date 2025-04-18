/* MODULO PARA TESTE DAS FUNCOES */


#include "WaitingQueue.h"


using namespace WaitingQueueTAD;


int main() {
    WaitingQueue* queue = createQueue();
    if (queue) {
        std::cout << "Fila criada com sucesso!" << std::endl;
    } else {
        std::cout << "Falha ao criar a fila. Encerrando..." << std::endl;
        return 1;
    }

    Client c1 = {"Joao", 1}; 
    Client c2 = {"Maria", 1};
    Client c3 = {"Pedro", 0};
    Client c4 = {"Ana", 0};

    std::cout << "\nAdicionando clientes a fila\n";
    enqueue(queue, c1);
    enqueue(queue, c2);
    enqueue(queue, c3);
    enqueue(queue, c4);

    std::cout << "\nConsultando o proximo cliente (peek):\n";
    Client nextClient;
    peek(queue, &nextClient);

    std::cout << "\nAtendendo clientes com dequeue:\n";
    for (int i = 0; i < 3; i++) {
        dequeue(queue, &nextClient);
    }

    char removeClient1[4] = "Ana";
    std::cout << "\nRemovendo cliente 'Ana' da fila:\n";
    if (removeClient(queue, removeClient1)) {
        std::cout << "Remocao realizada com sucesso.\n";
    } else {
        std::cout << "Falha na remocao.\n";
    }

    Client c5 = {"Carlos", 1};
    Client c6 = {"Beatriz", 0};
    std::cout << "\nAdicionando mais clientes\n";
    enqueue(queue, c5);
    enqueue(queue, c6);

    std::cout << "\nObtendo a ordem da fila:\n";
    int numClients;
    Client* order = getQueueOrder(queue, &numClients);
    if (order) {
        for (int i = 0; i < numClients; i++) {
            std::cout 
            << "Cliente " << i + 1 << ": " << order[i].name 
            << " (Prioridade: " << (order[i].priority == 1 ? "Idoso" : "Geral") << ")\n";
        }
        delete[] order;
    } else {
        std::cout << "Falha ao obter a ordem da fila.\n";
    }

    std::cout << "\nLiberando a fila e encerrando o atendimento\n";
    deleteQueue(queue);

    return 0;
}
