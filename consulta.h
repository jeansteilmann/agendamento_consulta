#ifndef CONSULTA_H
#define CONSULTA_H

#include "medico.h"
#include "paciente.h"

typedef struct Consulta {
    Paciente* paciente;
    Medico* medico;
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    char convenio[100];
    char status[20];
    char descricao[500];
    struct Consulta* proximo;
} Consulta;

void agendarConsulta(Consulta** listaConsultas, Paciente* listaPacientes, Medico* listaMedicos);
void apagarConsulta(Consulta** listaConsultas);
void listarConsultas(Consulta* listaConsultas);
void executarConsulta(Consulta* listaConsultas);
int verificaHora(int hora,int minuto);

#endif