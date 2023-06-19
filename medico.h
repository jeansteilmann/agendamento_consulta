#ifndef MEDICO_H
#define MEDICO_H

typedef struct Medico {
    char crm[13];
    char nome[100];
    char especialidade[100];
    char telefone[20];
    struct Medico* proximo;
} Medico;

void cadastrarMedico(Medico** listaMedicos);
void listarMedicos(Medico* listaMedicos);

#endif