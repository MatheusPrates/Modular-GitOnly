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

#include <assert.h>

#include <stdlib.h>
#include <time.h>

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

struct carta {

	char valor;
	/*Valor da carta*/

	char naipe;
	/*Naipe da carta (representado pela primeira letra do naipe)*/

};

Baralho BaralhoDeCartas=NULL; // O baralho que efetivamente vai ser utilizado no jogo.

Baralho preparado=NULL; //Um baralho auxiliar para poder embaralhar decentemente. É criado e destruido cada vez que o baralho precisar ser embaralhado.

/***** Protótipos das funções encapuladas no módulo *****/

static Carta* cria_carta(char valor,char naipe);
static BAR_CondRet Transforma_CondRet(LIS_tpCondRet CondRet);
static BAR_CondRet prepara(void);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR  &Criar baralho
***************************************************************************/

BAR_CondRet BAR_CriarBaralho()
{
	BaralhoDeCartas = LIS_CriarLista(NULL);
	if (!BaralhoDeCartas)
		return BAR_CondRetSemMemoria;
	return BAR_CondRetOk ;	
}

/***************************************************************************
*
*  Função: BAR  &Embaralha
***************************************************************************/

BAR_CondRet BAR_embaralha(void)
{
	Carta* carta;
	LIS_tpCondRet CondRet;
	BAR_CondRet BarCondRet;
	int i,a;
	srand(time(NULL));
	BarCondRet = prepara();
	if (!BaralhoDeCartas ||BarCondRet==BAR_CondRetSemMemoria)
		return BAR_CondRetSemMemoria;
	for (i=39;i>=0;i--)
	{
		a=rand()/ (RAND_MAX + 1.0) * (i+1);
		IrInicioLista(preparado);
		LIS_AvancarElementoCorrente(preparado,a);
		carta=(Carta*)LIS_ObterValor(preparado);
		LIS_ExcluirElemento(preparado);
		CondRet = LIS_InserirElementoAntes(BaralhoDeCartas,carta);
		if (Transforma_CondRet(CondRet)==BAR_CondRetSemMemoria)
			return BAR_CondRetSemMemoria;
	}
	LIS_DestruirLista(preparado);
	return BAR_CondRetOk;
}


/***************************************************************************
*
*  Função: BAR  &Destruir baralho
***************************************************************************/

void BAR_DestruirBaralho(void)
{
	Carta* carta;
	IrInicioLista(BaralhoDeCartas);
	carta=(Carta*)LIS_ObterValor(BaralhoDeCartas);
	while(carta!=NULL){
		free(carta);
		carta=NULL;
		LIS_ExcluirElemento(BaralhoDeCartas);
		carta=(Carta*)LIS_ObterValor(BaralhoDeCartas);
	}
	LIS_DestruirLista(BaralhoDeCartas);
	BaralhoDeCartas=NULL;
}
/***************************************************************************
*
*  Função: BAR  &Saca carta
***************************************************************************/

Carta* BAR_sacaCarta(void){
	Carta* carta;
	if(!BaralhoDeCartas)
		return NULL;
	IrInicioLista(BaralhoDeCartas);
	carta=LIS_ObterValor(BaralhoDeCartas);
	LIS_ExcluirElemento(BaralhoDeCartas);
	return carta;
}
/*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: BAR  -Cria Carta
*
*  $ED Descrição da função
*     Cria uma carta que posteriormente será inserida no baralho.
*     
*  $FV Valor retornado
*	Se nao conseguir alocar memória retorna um ponteiro NULL.
*	Caso contrário, retorna uma carta.
*
***********************************************************************/

static Carta* cria_carta(char valor,char naipe)
{
	Carta* novo=(Carta*)malloc(sizeof(Carta));
	if(!novo)
		return NULL;
	novo->valor=valor;
	novo->naipe=naipe;
	return novo;
}

/***********************************************************************
*
*  $FC Função: BAR  Transforma condição de retorno
*
*  $ED Descrição da função
*     Transforma  as condições de retorno de Lista para  as condições 
*		 de retorno de Baralho.
*     
*  $FV Valor retornado
*	BAR_CondRetOK- Caso receba LIS_CondRetOK ou caia no caso default.
*	BAR_CondRetSemMemoria-Caso receba LIS_CondRetFaltouMemoria 
*
***********************************************************************/

static BAR_CondRet Transforma_CondRet(LIS_tpCondRet CondRet){
	switch(CondRet){
	case LIS_CondRetOK: return BAR_CondRetOk;
	case LIS_CondRetFaltouMemoria: return BAR_CondRetSemMemoria;
	default: return BAR_CondRetOk;
	}

}

/***********************************************************************
*
*  $FC Função: BAR  Prepara Baralho
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

static BAR_CondRet prepara(void)
{
	LIS_tpCondRet CondRet;
	Carta* uma_carta;
	int i,d;
	char tnaipe,tvalor;
	char valor[]={'3','2','A','K','J','Q','7','6','5','4'};
	char naipe[]={'O','E','C','P'};
	preparado=LIS_CriarLista(NULL);
	if (!preparado)
		return BAR_CondRetSemMemoria;
	for (i=0;i<40;i++)
	{
		d=i;
		if (i>=10)
			d%=10;
		tvalor = valor[d];
		d=i/10;
		tnaipe=naipe[d];
		uma_carta = cria_carta(tvalor,tnaipe);
		if(uma_carta)
		{
			CondRet = LIS_InserirElementoAntes(preparado,uma_carta);
			if (CondRet==LIS_CondRetFaltouMemoria)
				return Transforma_CondRet(CondRet);
		}
	}
	return Transforma_CondRet(CondRet);

}

/************************************ Fim do módulo de implementação: BAR  Baralho  **********************************************************************/