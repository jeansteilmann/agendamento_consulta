#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medico.h"

void cadastrarMedico(Medico** listaMedicos) {
    Medico* novoMedico = (Medico*)malloc(sizeof(Medico));
    novoMedico->proximo = NULL;

    printf("=== Cadastro de Medico ===\n");

    printf("CRM: ");
    scanf(" %s", novoMedico->crm);

    printf("Nome: ");
    scanf(" %s", novoMedico->nome);

    printf("Especialidade: ");
    scanf(" %s", novoMedico->especialidade);

    printf("Telefone: ");
    scanf(" %s", novoMedico->telefone);

    if (*listaMedicos == NULL) {
        *listaMedicos = novoMedico;
    } else {
        Medico* temp = *listaMedicos;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoMedico;
    }

    printf("Medico cadastrado com sucesso!\n");
}

void listarMedicos(Medico* listaMedicos) {
    if (listaMedicos == NULL) {
        printf("Nenhum medico cadastrado.\n");
    } else {
        printf("=== Lista de Medicos ===\n");
        Medico* temp = listaMedicos;
        while (temp != NULL) {
            printf("CRM: %s\n", temp->crm);
            printf("Nome: %s\n", temp->nome);
            printf("Especialidade: %s\n", temp->especialidade);
            printf("Telefone: %s\n", temp->telefone);
            printf("\n");
            temp = temp->proximo;
        }
    }
}