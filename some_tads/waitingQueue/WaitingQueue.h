/* MODULO PARA DECLARACAO DE FUNCOES E ESTRUTURAS DE DADOS PARA O TAD WaitingQueue */


#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H


//Bibliotecas necessarias
#include <iostream>
#include <string>
#include <cstring>

//Namespace
namespace WaitingQueueTAD {

    //Structs

    struct Client {
        char name[50];        // Nome do cliente, todos distintos
        int priority;         // 0 = Geral e 1 = Idoso
    };
    struct QueueNode {
        Client client;        // Estrutura para armazenar as informaçoes do cliente
        QueueNode* next;      // Ponteiro para a proxima pessoa que chegar
        QueueNode* previous;  // Ponteiro para o cliente imediatamente anterior
    };
    struct WaitingQueue {
        int generalCount;            // Contagem das pessoas de prioridade 0 (geral) 
        int elderlyCount;            // Contagem das pessoas de prioridade 1 (idoso)
        int elderlyAttended;         // Inteiro que conta quantos idosos foram atendidos (0, 1, 2)
        QueueNode* elderlyFirst;     // Ponteiro para a frente da fila de idosos
        QueueNode* elderlyLast;      // Ponteiro para o final da fila de idosos
        QueueNode* generalFirst;     // Ponteiro para a frente da fila de geral
        QueueNode* generalLast;      // Ponteiro para o final da fila de geral
    };


    //Funcoes TAD

    /**
     * @brief Inicializa a fila de espera.
     * @return Ponteiro para a fila de espera inicializada.
     */
    WaitingQueue* createQueue();

    /**
     * @brief Insere um cliente na fila de espera.
     * @param queue Ponteiro para a condicao atual da fila de espera.
     * @param client Cliente a ser adicionado.
     */   
    void enqueue(WaitingQueue* queue, Client client);

    /**
     * @brief Encontra a proxima pessoa a ser atendida (dadas as restricoes), sem alterar a fila.
     * @param queue Ponteiro para a condicao atual da fila de espera.
     * @param returnClient Ponteiro para reservar o proximo cliente a ser atendido.
     * @return 1 se a fila não etiver vazia ou 0 caso contrario.
     */
    int peek(const WaitingQueue* queue, Client* returnClient);

    /**
     * @brief Remove o proximo da fila, apos o atendimento.
     * @param queue Ponteiro para a condicao atual da fila de espera.
     * @param returnClient Ponteiro para reservar o cliente a ser removido.
     * @return 1 se a fila não etiver vazia ou 0 se a fila estiver vazia.
     */
    int dequeue(WaitingQueue* queue, Client* returnClient);

    /**
     * @brief Remove um cliente especifico da fila de espera.
     * @param queue Ponteiro para a condicao atual da fila de espera.
     * @param name Ponteiro para o nome do cliente (dado que nenhum cliente tem o nome igual).
     * @return 1 se o cliente foi removido com sucesso ou 0 caso contrário.
     */
    int removeClient(WaitingQueue* queue, char* name);

    /**
     * @brief Retorna a sequência de prioridade de clientes a serem atendidos, sem alterar a fila.
     * @param queue Ponteiro para a condicao atual da fila de espera.
     * @param numClients Ponteiro para reservar o número de clientes existentes.
     * @return Ponteiro para a ordem de clientes a serem atendidos.
     */
    Client* getQueueOrder(const WaitingQueue* queue, int* numClients);

    /**
     * @brief Deletar toda a fila e liberar a memória.
     * @param queue Ponteiro para a condicao atual da fila de espera.
     */
    void deleteQueue(WaitingQueue* queue);


} // Namespace WaitingQueueTAD

#endif
