/* MODULO DE TESTE DAS FUNCOES */

#include <iostream>
#include "PatientArray.h"

using namespace PatientArrayTAD;

int main() {

    // Inicializa o PatientArray
    PatientArrayTAD::PatientArray *pa = initializePatientArray();
    std::cout << "PatientArray inicializado!" << std::endl;

    // Criando pacientes
    Patient p1 = {"Alice", 3, "10h30"};
    Patient p2 = {"Bob", 5, "09h15"};
    Patient p3 = {"Charlie", 5, "08h45"};
    Patient p4 = {"David", 2, "11h00"};
    Patient p5 = {"Eve", 4, "07h30"};

    // Inserindo pacientes
    insertPatient(pa, p1);
    insertPatient(pa, p2);
    insertPatient(pa, p3);
    insertPatient(pa, p4);
    insertPatient(pa, p5);

    // Exibindo lista de pacientes
    printPatients(pa);

    // Buscando proximo paciente
    int nextIndex = findNextPatient(pa);
    std::cout << "\nProximo paciente a ser atendido: " << pa->patients[nextIndex].name << std::endl;

    // Removendo um paciente
    std::cout << "\nRemovendo paciente menos urgente..." << std::endl;
    removePatient(pa, 3);
    printPatients(pa);

    // Removendo e retornando o próximo paciente mais urgente
    std::cout << "\nAtendendo paciente mais urgente..." << std::endl;
    Patient attended = popNextPatient(pa);
    std::cout << "Paciente atendido: " << attended.name << " (Gravidade: " << attended.severity << ", Hora: " << attended.arrival_time << ")" << std::endl;
    
    // Exibir lista após atendimento
    std::cout << "\nLista apos atendimento:" << std::endl;
    printPatients(pa);

    std::cout << "\nAtendimento finalizado!" << std::endl;

    // Liberar memória
    delete[] pa->patients;
    delete pa;

    return 0;
}
