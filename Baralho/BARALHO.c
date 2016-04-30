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
<<<<<<< HEAD
#include <assert.h>
=======
#include <stdlib.h>
#include <time.h>

>>>>>>> 7f0ce89719d660433dd14ac43098f4da68a39a8f

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


Baralho preparado; //Um baralho auxiliar para poder embaralhar decentemente. É criado e destruido cada vez que o baralho precisar ser embaralhado.

static Carta* cria_carta(char valor,char naipe)
{
	Carta* novo=(Carta*)malloc(sizeof(Carta));
	if(!novo)
		return NULL;
	novo->valor=valor;
	novo->naipe=naipe;
	return novo;
}

static void prepara(void)
{
	LIS_tpCondRet CondRet;
	Carta* uma_carta;
	int i,d;
	char tnaipe,tvalor;
	char valor[]={'3','2','A','K','J','Q','7','6','5','4'};
	char naipe[]={'O','E','C','P'};
	preparado=LIS_CriarLista(NULL);
	for (i=0;i<40;i++)
	{
		if (i>=10)
			d=i%10;
		else
			d=i;
		tvalor = valor[d];
		d=i/10;
		tnaipe=naipe[d];
		uma_carta = cria_carta(tvalor,tnaipe);
		if(uma_carta)
			CondRet = LIS_InserirElementoAntes(preparado,uma_carta);
	}

}

/***** Protótipos das funções encapuladas no módulo *****/

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR  &Criar baralho
***************************************************************************/

Baralho BAR_CriarBaralho()
{
	Baralho Novo_Baralho = LIS_CriarLista(NULL);

	return Novo_Baralho;	
}

void BAR_embaralha(Baralho baralho)
{
	Carta* carta;
	LIS_tpCondRet CondRet;
	int i,j,a;
	int n;
	srand(time(NULL));
	prepara();
	baralho=LIS_CriarLista(NULL);
	for (i=39;i>=0;i--)
	{
		a=rand()/ (RAND_MAX + 1.0) * (i - 0 + 1);
		IrInicioLista(preparado);
		LIS_AvancarElementoCorrente(preparado,a);
		carta=(Carta*)LIS_ObterValor(preparado);
		LIS_ExcluirElemento(preparado);
		LIS_InserirElementoAntes(baralho,carta);
	}
	LIS_DestruirLista(preparado);

}

















/***************************************************************************
*
*  Função: BAR  &Destruir baralho
***************************************************************************/

	void BAR_DestruirBaralho(Baralho Bar)
	{
		LIS_DestruirLista(Bar);
	}


