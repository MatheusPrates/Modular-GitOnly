/***************************************************************************
*  $MCI Módulo de implementação: BAR Módulo baralho
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
#include <stdlib.h>
#include <time.h>

#include "BARALHO.h"

#ifndef ASSERTIVA_BARALHO
#define ASSERTIVA_BARALHO
#define MAX_CARTAS 40
#define MAX_VALORES 10
#endif

/***********************************************************************
*
*  $TC Tipo de dados: CAR Carta
*
*
*  $ED Descrição do tipo
*     Descreve uma carta
*
***********************************************************************/	

struct carta {

	char valor;
	/*Valor da carta*/

	char naipe;
	/*Naipe da carta (representado pela primeira letra do naipe)*/

};

static Baralho baralhoDeCartas=NULL; // O baralho que efetivamente vai ser utilizado no jogo.

static Baralho preparado=NULL; //Um baralho auxiliar para poder embaralhar decentemente. É criado e destruido cada vez que o baralho precisar ser embaralhado.
static char valor[]={'4','5','6','7','Q','J','K','A','2','3'};
static char naipe[]={'O','E','C','P'};

/***** Protótipos das funções encapuladas no módulo *****/

static Carta* criaCarta(char valor,char naipe);
static BAR_CondRet TransformarCondRet(LIS_tpCondRet CondRet);
static BAR_CondRet Preparar(void);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR  &Criar Baralho
***************************************************************************/

BAR_CondRet BAR_CriarBaralho()
{
	if (baralhoDeCartas!=NULL)
	{
		return BAR_CondRetBaralhoJaExiste;
	}

	baralhoDeCartas = LIS_CriarLista(NULL);

	if (baralhoDeCartas==NULL)
	{
		return BAR_CondRetSemMemoria;
	}
	return BAR_CondRetOk ;
}/* Fim função: BAR  &Criar Baralho */

/***************************************************************************
*
*  Função: BAR  &Embaralhar
***************************************************************************/

BAR_CondRet BAR_Embaralhar(void)
{
	Carta* carta;
	LIS_tpCondRet condRet;
	BAR_CondRet barCondRet;
	int i,a;
	srand(time(NULL));
	barCondRet = Preparar();

	if (baralhoDeCartas==NULL ||barCondRet==BAR_CondRetSemMemoria)
	{
		return BAR_CondRetSemMemoria;
	}
	for (i=MAX_CARTAS-1;i>=0;i--)
	{
		a=rand()/ (RAND_MAX + 1.0) * (i+1);
		IrInicioLista(preparado);
		LIS_AvancarElementoCorrente(preparado,a);
		carta=(Carta*)LIS_ObterValor(preparado);
		LIS_ExcluirElemento(preparado);
		condRet = LIS_InserirElementoAntes(baralhoDeCartas,carta);

		if (TransformarCondRet(condRet)==BAR_CondRetSemMemoria)
		{
			return BAR_CondRetSemMemoria;
		}
	}
	LIS_DestruirLista(preparado);
	return BAR_CondRetOk;
}/* Fim função: BAR  &Criar Embaralhar */

/***************************************************************************
*
*  Função: BAR  &Retornar Valor Carta
***************************************************************************/

char BAR_RetornarValorCarta(Carta* carta)
{
	if(carta!=NULL)
	{
		return carta->valor;
	}

	return ' ';
}/* Fim função: BAR  &Retornar Valor Carta */

/***************************************************************************
*
*  Função: BAR  &Definir Valor Manilha
***************************************************************************/

char BAR_DefinirValorManilha(Carta* vira)
{
	int i;

	if (vira!=NULL)
	{
		for (i=0;i<=MAX_VALORES;i++)
		{
			if (vira->valor==valor[i])
			{
				return valor[(i+1)%MAX_VALORES];
			}
		}
	}
	return ' ';
}/* Fim função: BAR  &Definir Valor Manilha */

/***************************************************************************
*
*  Função: BAR  &DestruirCarta
***************************************************************************/

void BAR_DestruirCarta(Carta* carta)
{
	if(carta!=NULL)
	{
		free(carta);
	}

}/* Fim função: BAR  &Destruir Carta */

/***************************************************************************
*
*  Função: BAR  &Destruir Baralho
***************************************************************************/

void BAR_DestruirBaralho(void)
{
	Carta* carta;

	IrInicioLista(baralhoDeCartas);
	carta=(Carta*)LIS_ObterValor(baralhoDeCartas);
	
	while(carta!=NULL)
	{
		free(carta);
		carta=NULL;
		LIS_ExcluirElemento(baralhoDeCartas);
		carta=(Carta*)LIS_ObterValor(baralhoDeCartas);
	}
	LIS_DestruirLista(baralhoDeCartas);
	baralhoDeCartas=NULL;
}/* Fim função: BAR  &Destruir Baralho */

/***************************************************************************
*
*  Função: BAR  &Sacar Carta
***************************************************************************/

Carta* BAR_SacarCarta(void)
{
	Carta* carta;

	if(baralhoDeCartas==NULL)
	{
		return NULL;
	}

	IrInicioLista(baralhoDeCartas);
	carta=(Carta*)LIS_ObterValor(baralhoDeCartas);
	LIS_ExcluirElemento(baralhoDeCartas);

	return carta;
}/* Fim função: BAR  &Sacar Carta */

/*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: BAR  -Criar Carta
*
*  $ED Descrição da função
*     Cria uma carta que posteriormente será inserida no baralho.
*   
*  $EP Parâmetros
*	
*	Valor- Valor de uma carta.
*	Naipe- Naipe de uma carta.
*
*  $FV Valor retornado
*	Se nao conseguir alocar memória retorna um ponteiro NULL.
*	Caso contrário, retorna uma carta.
*
***********************************************************************/

static Carta* CriarCarta(char valor,char naipe)
{
	Carta* novo=(Carta*)malloc(sizeof(Carta));

	if(novo==NULL)
	{
		return NULL;
	}

	novo->valor=valor;
	novo->naipe=naipe;

	return novo;
}/* Fim função: BAR  -Criar Carta */

/***********************************************************************
*
*  $FC Função: BAR  -Transformar condição de retorno
*
*  $ED Descrição da função
*     Transforma  as condições de retorno de Lista para  as condições 
*		 de retorno de Baralho.
*
*  $EP Parâmetros
*	 
*	LIS_tpCondret- Condição de retorno de uma lista.
*     
*  $FV Valor retornado
*	BAR_CondRetOK- Caso receba LIS_CondRetOK ou caia no caso default.
*	BAR_CondRetSemMemoria-Caso receba LIS_CondRetFaltouMemoria 
*
***********************************************************************/

static BAR_CondRet TransformarCondRet(LIS_tpCondRet CondRet)
{
	switch(CondRet)
	{
		case LIS_CondRetOK: return BAR_CondRetOk;
		case LIS_CondRetFaltouMemoria: return BAR_CondRetSemMemoria;
		default: return BAR_CondRetOk;
	}

}/* Fim função: BAR  -Transformar condição de retorno */

/***********************************************************************
*
*  $FC Função: BAR  -Preparar Baralho
*
*  $ED Descrição da função
*     Coloca todas as cartas presentes do jogo no baralho auxiliar.
*     
*  $FV Valor retornado
*	BAR_CondRetOK- Caso consiga colocar todas as cartas no baralho.
*	BAR_CondRetSemMemoria-Caso falte memoria na criação do baralho auxiliar
*						  ou tenha problemas inserindo uma carta nele.
*
***********************************************************************/

static BAR_CondRet Preparar(void)
{
	LIS_tpCondRet condRet;
	Carta* umaCarta;
	int i,d;
	char tNaipe,tValor;

	preparado=LIS_CriarLista(NULL);

	if (preparado==NULL)
	{
		return BAR_CondRetSemMemoria;
	}
	
	for (i=0;i<MAX_CARTAS;i++)
	{
		d=i;
		if (i>=MAX_VALORES)
		{
			d%=MAX_VALORES;
		}

		tValor = valor[d];
		d=i/MAX_VALORES;
		tNaipe=naipe[d];
		umaCarta = CriarCarta(tValor,tNaipe);

		if(umaCarta!=NULL)
		{
			condRet = LIS_InserirElementoAntes(preparado,umaCarta);

			if (condRet==LIS_CondRetFaltouMemoria)
			{
				return TransformarCondRet(condRet);
			}
		}
	}
	return TransformarCondRet(condRet);

}/* Fim função: BAR -Preparar Baralho */

#ifdef ASSERTIVA BARALHO
#undef ASSERTIVA_BARALHO
#endif

/************************************ Fim do módulo de implementação: BAR  Baralho  ************************************************************/