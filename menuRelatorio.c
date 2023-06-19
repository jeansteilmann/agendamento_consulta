#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "menuRelatorio.h"



void relatorioConsultasDia(Consulta* listaConsultas) {
    printf("=== Relatorio de Consultas por Dia ===\n");

    printf("Informe o dia (dia mes ano): ");
    int dia,mes,ano;
    scanf("%d %d %d", &dia,&mes,&ano);

    Consulta* consulta = listaConsultas;
    int encontradas = 0;

    while (consulta != NULL) {
        if (consulta->dia == dia,consulta->mes == mes,consulta->ano == ano) {
            printf("Paciente: %s\n", consulta->paciente->nome);
            printf("Medico: %s\n", consulta->medico->nome);
            printf("Data: %d/%d/%d\n", consulta->dia, consulta->mes, consulta->ano);
            printf("Horario: %d:%02d\n", consulta->hora, consulta->minuto);
            printf("Convenio: %s\n", consulta->convenio);
            printf("\n");
            encontradas = 1;
        }
        consulta = consulta->proximo;
    }

    if (!encontradas) {
        printf("Nenhuma consulta agendada para o dia %d.\n", dia);
    }
}

void relatorioConsultasPaciente(Consulta* listaConsultas) {
    printf("=== Relatorio de Consultas por Paciente ===\n");

    printf("Informe o CPF do paciente: ");
    char cpfPaciente[12];
    scanf(" %s", cpfPaciente);

    Consulta* consulta = listaConsultas;
    int encontradas = 0;

    while (consulta != NULL) {
        if (strcmp(consulta->paciente->cpf,cpfPaciente) == 0) {
            printf("Paciente: %s\n", consulta->paciente->nome);
            printf("Medico: %s\n", consulta->medico->nome);
            printf("Data: %d/%d/%d\n", consulta->dia, consulta->mes, consulta->ano);
            printf("Horario: %d:%02d\n", consulta->hora, consulta->minuto);
            printf("Convenio: %s\n", consulta->convenio);
            printf("Status: %s\n", consulta->status);
            printf("Descricao: %s\n", consulta->descricao);
            printf("\n");
            encontradas = 1;
        }
        consulta = consulta->proximo;
    }

    if (!encontradas) {
        printf("Nenhuma consulta encontrada para o paciente com CPF %s.\n", cpfPaciente);
    }
}

void relatorioDescricaoConsulta(Consulta* listaConsultas) {
    printf("=== Relatorio de Descricao de Consulta ===\n");

    printf("CPF do paciente: ");
    char cpfPaciente[12];
    scanf("%s", cpfPaciente);

    printf("Data (dia mes ano): ");
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    printf("Horario (hora minuto): ");
    int hora, minuto;
    scanf("%d %d", &hora, &minuto);

    Consulta* consulta = listaConsultas;
    while (consulta != NULL) {
        if (strcmp(consulta->paciente->cpf,cpfPaciente) == 0 &&
            consulta->dia == dia && consulta->mes == mes && consulta->ano == ano &&
            consulta->hora == hora && consulta->minuto == minuto) {
            printf("Paciente: %s\n", consulta->paciente->nome);
            printf("Medico: %s\n", consulta->medico->nome);
            printf("Data: %d/%d/%d", consulta->dia, consulta->mes, consulta->ano);
            printf(" %d:%02d\n", consulta->hora, consulta->minuto);
            printf("Descricao: %s\n", consulta->descricao);
            return;
        }
        consulta = consulta->proximo;
    }

    printf("Consulta nao encontrada.\n");
}
void relatorioPacientesPorEspecialidadeMes(Medico* listaMedicos, Consulta* listaConsultas) {
    printf("=== Relatorio de Pacientes por Especialidade e Mes ===\n");

    printf("Especialidade: ");
    char especialidade[100];
    scanf(" %s", especialidade);

    printf("Mes (1-12): ");
    int mes;
    scanf("%d", &mes);

    Medico* medico = listaMedicos;

    while (medico != NULL) {
        if (strcmp(medico->especialidade, especialidade) == 0) {
            printf("Medico: %s\n", medico->nome);

            Consulta* consulta = listaConsultas;
            int encontradas = 0;

            while (consulta != NULL) {
                if (consulta->medico == medico && consulta->mes == mes) {
                    printf("Paciente: %s\n", consulta->paciente->nome);
                    encontradas = 1;
                }
                consulta = consulta->proximo;
            }

            if (!encontradas) {
                printf("Nenhum paciente encontrado.\n");
            }

            printf("\n");
        }

        medico = medico->proximo;
    }
}

void relatorioPacientesPorMedico(Medico* listaMedicos, Consulta* listaConsultas) {
    printf("=== Relatorio de Pacientes por Medico ===\n");

    Medico* medico = listaMedicos;

    while (medico != NULL) {
        printf("Medico: %s\n", medico->nome);

        Consulta* consulta = listaConsultas;
        int encontradas = 0;

        while (consulta != NULL) {
            if (consulta->medico == medico) {
                printf("Paciente: %s\n", consulta->paciente->nome);
                encontradas = 1;
            }
            consulta = consulta->proximo;
        }

        if (!encontradas) {
            printf("Nenhum paciente encontrado.\n");
        }

        printf("\n");

        medico = medico->proximo;
    }
}

void menuRelatorio(Consulta* listaConsultas, Medico* listaMedicos) {
    int opcao;

    do {printf("=== Menu de Relatorios ===\n");
        printf("1) Listar todas as consultas agendadas para um certo dia\n");
        printf("2) Listar todas as consultas ja realizadas por um paciente\n");
        printf("3) Listar as descricoes textuais de uma determinada consulta\n");
        printf("4) Listar todos nomes de pacientes que consultaram na clinica com os medicos de uma determinada especialidade num determinado mes\n");
        printf("5) Para cada medico cadastrado, listar o nome de todos os pacientes que ja consultaram com ele na clinica\n");
        printf("0) Voltar\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                relatorioConsultasDia(listaConsultas);
                break;
            case 2:
                relatorioConsultasPaciente(listaConsultas);
                break;
            case 3:
                relatorioDescricaoConsulta(listaConsultas);
                break;
            case 4:
                relatorioPacientesPorEspecialidadeMes(listaMedicos, listaConsultas);
                break;
            case 5:
                relatorioPacientesPorMedico(listaMedicos, listaConsultas);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);
}