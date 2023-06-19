#ifndef MENURELATORIO_H
#define MENURELATORIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "medico.h"
#include "consulta.h"


void relatorioConsultasDia(Consulta* listaConsultas);
void relatorioConsultasPaciente(Consulta* listaConsultas);
void relatorioDescricaoConsulta(Consulta* listaConsultas);
void relatorioPacientesPorEspecialidadeMes(Medico* listaMedicos, Consulta* listaConsultas);
void relatorioPacientesPorMedico(Medico* listaMedicos, Consulta* listaConsultas);
void menuRelatorio(Consulta* listaConsultas, Medico* listaMedicos);


#endif