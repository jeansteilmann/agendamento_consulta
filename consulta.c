#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta.h"

int verificaHora(int hora, int minuto){

    if((minuto == 30) || (minuto == 0)){
        if((hora >= 8 && hora < 12) || (hora >= 14 && hora < 18)){
            return 1;
        }
    }
    return 0;
}
void agendarConsulta(Consulta** listaConsultas, Paciente* listaPacientes, Medico* listaMedicos) {
    Consulta* novaConsulta = (Consulta*)malloc(sizeof(Consulta));
    novaConsulta->proximo = NULL;

    printf("=== Agendamento de Consulta ===\n");

    printf("CPF do paciente: ");
    char cpfPaciente[12];
    scanf("%s", cpfPaciente);

    Paciente* paciente = listaPacientes;
    while (paciente != NULL) {
        if (strcmp(paciente->cpf,cpfPaciente) == 0) {
            novaConsulta->paciente = paciente;
            break;
        }
        paciente = paciente->proximo;
    }

    if (paciente == NULL) {
        printf("Paciente nao encontrado.\n");
        free(novaConsulta);
        return;
    }

    printf("CRM do medico: ");
    char crmMedico[13];
    scanf("%s", crmMedico);

    Medico* medico = listaMedicos;
    while (medico != NULL) {
        if (strcmp(medico->crm,crmMedico) == 0) {
            novaConsulta->medico = medico;
            break;
        }
        medico = medico->proximo;
    }

    if (medico == NULL) {
        printf("Medico nao encontrado.\n");
        free(novaConsulta);
        return;
    }
    
        printf("Data (dia mes ano): ");
        scanf("%d %d %d", &(novaConsulta->dia), &(novaConsulta->mes), &(novaConsulta->ano));
    
    
        printf("Horario (hora minuto)Consultas a cada 30min, entre 08 e 12 e 14 e 18. Ex 8 30:");
        scanf("%d %d", &(novaConsulta->hora), &(novaConsulta->minuto));
    
    
    if(verificaHora(novaConsulta->hora,novaConsulta->minuto) == 0){
        printf("Digite um horario valido!\n");
        printf("Horario (hora minuto): ");
        scanf("%d %d", &(novaConsulta->hora), &(novaConsulta->minuto));
    }
    printf("Convenio: ");
    scanf(" %s", novaConsulta->convenio);

    Consulta* temp = *listaConsultas;
    while (temp != NULL) {
        if (temp->medico == medico && temp->dia == novaConsulta->dia &&
            temp->mes == novaConsulta->mes && temp->ano == novaConsulta->ano &&
            temp->hora == novaConsulta->hora && temp->minuto == novaConsulta->minuto) {
            printf("Nao foi possível agendar a consulta. O horario já esta ocupado.\n");
            free(novaConsulta);
            return;
        }
        temp = temp->proximo;
    }

    strcpy(novaConsulta->status, "agendada");

    printf("Consulta agendada com sucesso!\n");

    if (*listaConsultas == NULL) {
        *listaConsultas = novaConsulta;
    } else {
                Consulta* temp = *listaConsultas;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novaConsulta;
    }
}

void apagarConsulta(Consulta** listaConsultas) {
    printf("=== Desmarcacao de Consulta ===\n");

    printf("CPF do paciente: ");
    char cpfPaciente[12];
    scanf("%s", cpfPaciente);

    printf("CRM do medico: ");
    char crmMedico[13];
    scanf("%s",crmMedico);
    printf("Data (dia mes ano): ");
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    printf("Horario (hora minuto): ");
    int hora, minuto;
    scanf("%d %d", &hora, &minuto);

    Consulta* anterior = NULL;
    Consulta* atual = *listaConsultas;

    while (atual != NULL) {
        if (strcmp(atual->paciente->cpf,cpfPaciente) == 0 && atual->dia == dia &&
            atual->mes == mes && atual->ano == ano &&
            atual->hora == hora && atual->minuto == minuto && strcmp(atual->medico->crm,crmMedico) == 0) {
            if (anterior == NULL) {
                *listaConsultas = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Consulta desmarcada com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Consulta nao encontrada.\n");
}

void listarConsultas(Consulta* listaConsultas) {
    if (listaConsultas == NULL) {
        printf("Nenhuma consulta agendada.\n");
    } else {
        printf("=== Lista de Consultas ===\n");
        Consulta* temp = listaConsultas;
        while (temp != NULL) {
            printf("Paciente: %s\n", temp->paciente->nome);
            printf("Medico: %s\n", temp->medico->nome);
            printf("Data: %d/%d/%d\n", temp->dia, temp->mes, temp->ano);
            printf("Horario: %d:%02d\n", temp->hora, temp->minuto);
            printf("Convenio: %s\n", temp->convenio);
            printf("Status: %s\n", temp->status);
            printf("Descricao: %s\n", temp->descricao);
            printf("\n");
            temp = temp->proximo;
        }
    }
}

void executarConsulta(Consulta* listaConsultas) {
    printf("=== Execucao de Consulta ===\n");

    printf("CPF do paciente: ");
    char cpfPaciente[12];
    scanf("%s", cpfPaciente);

    printf("Nome do medico: ");
    char nomeMedico[100];
    scanf(" %s", nomeMedico);

    printf("Data (dia mes ano): ");
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    printf("Horario (hora minuto): ");
    int hora, minuto;
    scanf("%d %d", &hora, &minuto);

    Consulta* consulta = listaConsultas;

    while (consulta != NULL) {
        if (strcmp(consulta->paciente->cpf,cpfPaciente) == 0 &&
            strcmp(consulta->medico->nome, nomeMedico) == 0 &&
            consulta->dia == dia && consulta->mes == mes && consulta->ano == ano &&
            consulta->hora == hora && consulta->minuto == minuto) {
            printf("Descricao: ");
            fflush(stdin);
            fgets(consulta->descricao,500,stdin);
            strcpy(consulta->status, "executada");
            printf("Consulta executada com sucesso!\n");
            return;
        }
        consulta = consulta->proximo;
    }

    printf("Consulta nao encontrada.\n");
}
