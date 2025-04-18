/* MODULO PARA IMPLEMENTACAO DE FUNCOES PARA O TAD PatientArray */

#include "PatientArray.h"

namespace PatientArrayTAD {

    PatientArray *initializePatientArray() {

        // Inicializando o PatientArray com capacidade 4 e sem pacientes
        PatientArray *pa = new PatientArray;
        pa->capacity = 4;
        pa->size = 0;
        pa->patients = new Patient[pa->capacity];
        return pa;
    }


    void insertPatient(PatientArray *pa, Patient p) {

        // Verificacoes basicas (tipo de entrada)
        if (typeid(p) != typeid(Patient) || typeid(*pa) != typeid(PatientArray)) {
            std::cout << "Tipo de entrada invalida" << std::endl;
            return;
        }

        // Inserindo o paciente no final do array
        pa->patients[pa->size] = p;
        pa->size += 1;

        // Dobrando a capacidade do array se ele estiver com 75% ou mais da capacidade
        if ( pa->size >= 0.75 * pa->capacity ) {
            Patient *new_patients = new Patient[2 * pa->capacity];
            for ( int i = 0; i < pa->size; i++ ) {
                new_patients[i] = pa->patients[i];
            }
            delete[] pa->patients;
            pa->patients = new_patients;
            pa->capacity *= 2;
        }
    }


    void printPatients(PatientArray *pa) {

        // Verificacoes basicas (ponteiro nulo e tipo de entrada)
        if (pa->patients == nullptr) {
            std::cout << "Nao ha pacientes" << std::endl;
        }
        if (typeid(*pa) != typeid(PatientArray)) {
            std::cout << "Tipo de entrada invalida" << std::endl;
            return;
        }

        // Mostrando as caracteristicas do PatientArray
        std::cout << "Capacity: " << pa->capacity << std::endl;
        std::cout << "Current size: " << pa->size << std::endl;
        std::cout << "\nPatients:" << std::endl;
        for ( int i = 0; i < pa->size; i++ ) {    
            std::cout << "*  " << pa->patients[i].arrival_time << " | " << pa->patients[i].severity << " | " << pa->patients[i].name << std::endl;
        }
    }


    int comparePatients(Patient p1, Patient p2) {

        // Verificacoes basicas (tipo de entrada)
        if (typeid(p1) != typeid(Patient) || typeid(p2) != typeid(Patient)) {
            std::cout << "Tipo de entrada invalida" << std::endl;
            return 0;
        }

        // Comparando, primeiramente, a severidade dos pacientes
        if (p1.severity > p2.severity) {
            return -1;
        } else if (p1.severity < p2.severity) {
            return 1;

        // Caso a severidade seja igual, comparamos o horario de chegada com strcmp
        } else {
            if (strcmp(p1.arrival_time, p2.arrival_time) < 0) {  // p1 mais urgente (chegou primeiro)
                return -1;
            } else if (strcmp(p1.arrival_time, p2.arrival_time) > 0) { // p2 mais urgente (chegou primeiro)
                return 1;
            } else {
                return 0;  // Nao sera usado (os horarios de chegada sao diferentes), mas coloquei por convencao
            }
        }
    }


    int findNextPatient(PatientArray *pa) {
        
        // Verificaoes basicas (ponteiro nulo e tipo de entrada)
        if (pa->patients == nullptr) {
            std::cout << "Nao ha pacientes" << std::endl;
            return -1;
        }
        if (typeid(*pa) != typeid(PatientArray)) {
            std::cout << "Tipo de entrada invalida" << std::endl;
            return -1;
        }

        // Retorna -1 se o array estiver vazio
        if (pa->size == 0) {
            return -1;
        }

        // Inicializando o indice do paciente mais urgente
        int best_idx = 0;

        // Procurando o paciente mais urgente
        for (int i = 0; i < pa->size; i++) {
            if (comparePatients(pa->patients[i], pa->patients[best_idx]) == -1) {
                best_idx = i;
            }
        }

        return best_idx;
    }


    void removePatient(PatientArray *pa, int index) {

        // Verificacoes basicas (ponteiro nulo, indice invalido e tipo de entrada)
        if (pa->patients == nullptr) {
            std::cout << "Nao ha pacientes" << std::endl;
            return;
        }
        int soma = 0;
        for (int i = 0; i < pa->size; i++) {
            soma += 1;
        }
        if (index < 0 || index >= soma) {
            std::cout << "Indice invalido" << std::endl;
            return;
        }
        if (typeid(*pa) != typeid(PatientArray) || typeid(index) != typeid(int)) {
            std::cout << "Tipo de entrada invalida" << std::endl;
            return;
        }

        // Removendo o paciente do indice indicado
        for ( int i = index; i < pa->size-1; i++ ) {
            pa->patients[i] = pa->patients[i+1];
        }
        pa->size--;

        // Dividindo a capacidade do array pela metade se ele estiver com 25% ou menos da capacidade
        if (pa->size <= 0.25*pa->capacity && pa->capacity >= 4) {
            Patient *new_patients = new Patient[pa->capacity/2];
            for (int i = 0; i < pa->size; i++) {
                new_patients[i] = pa->patients[i];
            }
            delete[] pa->patients;
            pa->patients = new_patients;
            pa->capacity /= 2;
        }

        // Caso a capacidade do array seja menor que 4, a capacidade se mantem em 4
        if (pa->capacity < 4) {
            pa->capacity = 4;
            Patient *new_patients = new Patient[pa->capacity];
            for (int i = 0; i < pa->size; i++) {
                new_patients[i] = pa->patients[i];
            }
            delete[] pa->patients;
            pa->patients = new_patients;
        }
    }


    Patient popNextPatient(PatientArray *pa) {

        // Verificacoes basicas (ponteiro nulo e tipo de entrada)
        if (pa->patients == nullptr) {
            std::cout << "Nao ha pacientes" << std::endl;
            return {"", 0, ""};
        }
        if (typeid(*pa) != typeid(PatientArray)) {
            std::cout << "Tipo de entrada invalida" << std::endl;
            return {"", 0, ""};
        }

        // Defino o paciente mais urgente e o removo da lista
        int index = findNextPatient(pa);

        // Retorna um aviso se o array estiver vazio
        if (index == -1) {
            std::cout << "Nao ha pacientes para atender" << std::endl;
            return {"", 0, ""};
        }

        // Retorna o paciente mais urgente e o remove do array
        Patient p = pa->patients[index];
        removePatient(pa, index);
        return p;
    }

}  // namespace PatientArrayTAD
