/* MODULO PARA DECLARACAO DE FUNCOES E ESTRUTURAS DE DADOS PARA O TAD PatientArray */

#ifndef PATIENTARRAY_H
#define PATIENTARRAY_H


//Bibliotecas necessarias
#include <iostream>
#include <cstring>
#include <string>
#include <typeinfo>


//Criando um namespace
namespace PatientArrayTAD {

    //Structs
    
    struct Patient {
        char name[50];          //Nome do paciente.
        unsigned int severity;  //Número positivo. Quanto maior, mais severo.
        char arrival_time[6];   //Formato "XXhYY"
    };
    struct PatientArray {
        Patient *patients;  // Ponteiro para o array de pacientes
        int size;           // Número atual de pacientes armazenados
        int capacity;       // Capacidade total do array
    };

    //Funcoes TAD

    /**
     * @brief Inicializa o array com capcidade igual a 4 e sem nenhum paciente.
     * @return Objeto PatientArray por referencia.
     */
    PatientArray *initializePatientArray();


    /**
     * @brief Mostra as caracteristicas atuais de PatientArray (capcidade e tamanho atuais e os pacientes).
     * @param pa Ponteiro para a condicao atual do PatientArray.
     */
    void printPatients(PatientArray *pa);


    /**
     * @brief Insere um paciente no final do Array. Se o array estiver com 75% ou mais da capacidade, dobramos ela.
     * @param pa Ponteiro para a condicao atual do PatientArray.
     * @param p Paciente a ser adicionado.
     */
    void insertPatient(PatientArray *pa, Patient p);


    /**
     * @brief Busco no PatientArray o paciente com maior grau de severidade para ser o proximo atendido.
     * @param pa Ponteiro para a condicao atual do PatientArray.
     * @return Inteiro correspondente à posicao do paciente.
     */
    int findNextPatient(PatientArray *pa);


    /**
     * @brief Remove o paciente do indice indicado. Se o array estiver com 25% ou menos da capacidade, dividimos pela metade (mas nunca menor que 4).
     * @param pa Ponteiro para a condicao atual do PatientArray.
     * @param index Posicao do paciente em PatientArray.
     */
    void removePatient(PatientArray *pa, int index);


    /**
     * @brief Encontra o paciente mais urgente e o remove da lista.
     * @param pa Ponteiro para a condicao atual do PatientArray.
     * @return Objeto Patient por referencia.
     */
    Patient popNextPatient(PatientArray *pa);


    //Funcoes auxiliares

    /**
     * @brief (Funcao auxiliar) Compara dois pacientes e retorna -1 se p1 é mais urgente, 1 se p2 é mais urgente e 0 se são iguais.
     * @param p1 Paciente 1.
     * @param p2 Paciente 2.
     * @return Inteiro correspondente à urgencia.
     */
    int comparePatients(Patient p1, Patient p2);
    
}  // namespace PatientArray


#endif
