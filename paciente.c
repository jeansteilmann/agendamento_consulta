#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

void cadastrarPaciente(Paciente** listaPacientes) {
    Paciente* novoPaciente = (Paciente*)malloc(sizeof(Paciente));
    novoPaciente->proximo = NULL;

    printf("=== Cadastro de Paciente ===\n");

    printf("CPF: ");
    scanf("%s",novoPaciente->cpf);

    printf("Nome: ");
    scanf(" %s", novoPaciente->nome);

    printf("Telefone: ");
    scanf(" %s", novoPaciente->telefone);

    if (*listaPacientes == NULL) {
        *listaPacientes = novoPaciente;
    } else {
        Paciente* temp = *listaPacientes;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
                temp->proximo = novoPaciente;
    }

    printf("Paciente cadastrado com sucesso!\n");
}

void listarPacientes(Paciente* listaPacientes) {
    if (listaPacientes == NULL) {
        printf("Nenhum paciente cadastrado.\n");
    } else {
        printf("=== Lista de Pacientes ===\n");
        Paciente* temp = listaPacientes;
        while (temp != NULL) {
            printf("CPF: %s\n", temp->cpf);
            printf("Nome: %s\n", temp->nome);
            printf("Telefone: %s\n", temp->telefone);
            printf("\n");
            temp = temp->proximo;
        }
    }
}