#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct Paciente {
    char cpf[12];
    char nome[100];
    char telefone[20];
    struct Paciente* proximo;
} Paciente;

void cadastrarPaciente(Paciente** listaPacientes);
void listarPacientes(Paciente* listaPacientes);

#endif