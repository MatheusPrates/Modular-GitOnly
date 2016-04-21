/***************************************************************************
*  $MCI Módulo de implementação: Módulo baralho
*
*  Arquivo gerado:              BARALHO.C
*  Letras identificadoras:      BAR
*
*  Nome da base de software:    -
*  Arquivo da base de software: -
*
*  Projeto: Disciplinas INF 1628 / 1301	Truco
*  Autores: Matheus³
*
*  $HA Histórico de evolução:
*     Versão 	 Autor    Data     	Observações
*       1.00   Matheus³   21/04/2016 Início do desenvolvimento
*
***************************************************************************/

#include <malloc.h>
#include <stdio.h>

#include "BARALHO.h"

/***********************************************************************
*
*  $TC Tipo de dados: CAR Carta
*
*
*  $ED Descrição do tipo
*     Descreve uma carta
*
***********************************************************************/	

	typedef struct carta {
	
		char valor;
			/*Valor da carta*/
			
		char naipe;
			/*Naipe da carta (representado pela primeira letra do naipe)*/
		
	} Carta;
	
/***** Protótipos das funções encapuladas no módulo *****/

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR  &Criar baralho
*  ************************************************************************/

	Baralho BAR_CriarBaralho()
	{
		Baralho Novo_Baralho = LIS_CriarLista(NULL);
		
		return Novo_Baralho;	
	}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	