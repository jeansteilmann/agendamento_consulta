#include <stdio.h>
#include <stdlib.h>
#include "medico.h"
#include "paciente.h"
#include "consulta.h"
#include "menuRelatorio.h"

int main() {
    Paciente* listaPacientes = NULL;
    Medico* listaMedicos = NULL;
    Consulta* listaConsultas = NULL;
    int opcao;

    do {
        printf("=== Menu ===\n");
        printf("1. Cadastrar medico\n");
        printf("2. Listar medicos\n");
        printf("3. Cadastrar paciente\n");
        printf("4. Listar pacientes\n");
        printf("5. Agendar consulta\n");
        printf("6. Apagar consulta\n");
        printf("7. Listar consultas\n");
        printf("8. Executar consulta\n");
        printf("9. Solicitar relatorios\n");
        printf("0. Sair\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarMedico(&listaMedicos);
                break;
            case 2:
                listarMedicos(listaMedicos);
                break;
            case 3:
                cadastrarPaciente(&listaPacientes);
                break;
            case 4:
                listarPacientes(listaPacientes);
                break;
            case 5:
                agendarConsulta(&listaConsultas, listaPacientes, listaMedicos);
                break;
            case 6:
                apagarConsulta(&listaConsultas);
                break;
            case 7:
                listarConsultas(listaConsultas);
                break;
            case 8:
                executarConsulta(listaConsultas);
                break;
            case 9:
                menuRelatorio(listaConsultas,listaMedicos);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }

        printf("\n");

    } while (opcao != 0);
    while (listaMedicos != NULL) {
        Medico* temp = listaMedicos;
        listaMedicos = listaMedicos->proximo;
        free(temp);
    }

    while (listaPacientes != NULL) {
        Paciente* temp = listaPacientes;
        listaPacientes = listaPacientes->proximo;
        free(temp);
    }

    while (listaConsultas != NULL) {
        Consulta* temp = listaConsultas;
        listaConsultas = listaConsultas->proximo;
        free(temp);
    }

    return 0;
}
