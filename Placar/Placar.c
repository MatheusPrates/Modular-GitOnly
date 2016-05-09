/***************************************************************************
*  $MCI Módulo de implementação: PLA  Placar
*
*  Arquivo gerado:              PLACAR.c
*  Letras identificadoras:      PLA
*
*  Nome da base de software:    -
*  Arquivo da base de software: -
*
*  Projeto: INF 1301 / 1628 Truco
*  Autores: Matheus Prates, Matheus Cunha, Matheus Suknaic
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       MMM   05/05/2016	Finalizou
***************************************************************************/

#include "Placar.h"
#include <stdlib.h>

/***********************************************************************
*
*  $TC Tipo de dados: PLA Placar
*
*
*  $ED Descrição do tipo
*     Descreve um placar
*
***********************************************************************/


struct placar{

	int pontosE1;
			/*Pontos da equipe 1*/
	int pontosE2;
			/*Pontos da equipe 2*/
	int valorRodada;
			/*Valor atual da rodada*/
	int vitoriasE1;
			/*Vitorias da equipe 1 no turno*/
	int vitoriasE2;
			/*Vitorias da equipe 2 no turno*/
	int ultimoTruco;
			/*Indica a ultima equipe que pediu truco*/
};

/***** Protótipos das funções encapuladas no módulo *****/

/*******************************************************/

static Placar* placarJogo=NULL;		//Placar que vai ser utilizado no jogo
static int rodada=0;				//variável que indica se a rodada foi criada ou nao

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: PLA  &Cria Placar
***************************************************************************/

PLA_CondRet PLA_CriarPlacar(void){

	placarJogo=(Placar*)malloc(sizeof(Placar));

	if (!placarJogo)
		return PLA_CondRetSemMemoria;

	placarJogo->pontosE1=placarJogo->pontosE2=0;

	return PLA_CondRetOk;

}/* Fim função:  PLA  &Cria Placar*/

/***************************************************************************
*
*  Função: PLA  &Nova Rodada
***********************************************************************/
PLA_CondRet PLA_NovaRodada(void){

	if(!placarJogo)
		return PLA_CondRetPlacarNaoExiste;

	placarJogo->vitorias_e1=0;
	placarJogo->vitoriasE2=0;
	placarJogo->valorRodada=1;
	placarJogo->ultimoTruco=-1;
	rodada=1;

	return PLA_CondRetOk;

}/* Fim função:  PLA  &Nova Rodada*/

/***************************************************************************
*
*  Função: PLA  &Pega Vitorias
***************************************************************************/

int PLA_PegarVitorias(int equipe){

	if (!placarJogo || !rodada || (equipe!=1 && equipe!=2))
		return -1;

	return (equipe==1)? placarJogo->vitorias_e1:placarJogo->vitoriasE2;

}/* Fim função: PLA  &Pega Vitorias*/

/***************************************************************************
*
*  Função: PLA  &Pega Pontos
***************************************************************************/

int PLA_PegarPontos(int equipe){

	if (!placarJogo || (equipe!=1 && equipe!=2))
		return -1;

	return (equipe==1)? placarJogo->pontosE1:placarJogo->pontosE2;

}/* Fim função: PLA  &Pega Pontos*/

/***************************************************************************
*
*  Função: PLA  &Guarda Pontos
***************************************************************************/

PLA_CondRet PLA_GuardarPontosEquipe(int equipe){

	if (!placarJogo)
		return PLA_CondRetPlacarNaoExiste;

	if(!rodada)
		return PLA_CondRetRodadaNaoIniciada;

	switch(equipe){
	case 0: placarJogo->pontosE1+=placarJogo->valorRodada; placarJogo->pontosE2+=placarJogo->valorRodada; break;
	case 1: placarJogo->pontosE1+=placarJogo->valorRodada; break;
	case 2: placarJogo->pontosE2+=placarJogo->valorRodada; break;
	default: return PLA_CondRetParametroIncorreto;
	}
	
	return PLA_TerminarRodada();
}/* Fim função: PLA  &Guarda Pontos*/

/***************************************************************************
*
*  Função: PLA  &Guarda Vitorias
***************************************************************************/

PLA_CondRet PLA_GuardarVitoriasEquipe(int equipe){

	if (!placarJogo)
		return PLA_CondRetPlacarNaoExiste;

	if (!rodada)
		return PLA_CondRetRodadaNaoIniciada;

	switch(equipe){
	case 0: placarJogo->pontosE1++; placarJogo->pontosE2++; break;
	case 1: placarJogo->pontosE1++; break;
	case 2: placarJogo->pontosE2++; break;
	default: return PLA_CondRetParametroIncorreto;
	}

	return PLA_CondRetOk;

}/* Fim função: PLA  &Guarda Vitorias*/

/***************************************************************************
*
*  Função: PLA  &Termina Rodada
***************************************************************************/

PLA_CondRet PLA_TerminarRodada(void){

	if (!placarJogo)
		return PLA_CondRetPlacarNaoExiste;

	if (!rodada)
		return PLA_CondRetRodadaNaoIniciada;

	rodada=0;

	return PLA_CondRetOk;

}/* Fim função: PLA  &Termina Rodada*/

/***************************************************************************
*
*  Função: PLA  &Status Rodada
***************************************************************************/

int PLA_StatusRodada(void){

	if (!placarJogo)
		return -1;

	return rodada;

}/* Fim função: PLA  &Status Rodada */

/***************************************************************************
*
*  Função: PLA  &Atualiza Valor Rodada
***************************************************************************/

PLA_CondRet PLA_AtualizarValorRodada(int equipe){

	PLA_CondRet CondRet;

	if (!placarJogo)
		return PLA_CondRetPlacarNaoExiste;

	if (!rodada)
		return PLA_CondRetRodadaNaoIniciada;

	if (equipe!=1 && equipe!=2)
		return PLA_CondRetParametroIncorreto;

	CondRet = PLA_ChecarTruco(equipe);

	if (CondRet == PLA_CondRetOk){

		placarJogo->valorRodada+=3;

		if (placarJogo->valorRodada==4)
			placarJogo->valorRodada--;

		placarJogo->ultimoTruco=equipe;
	}

	return CondRet;

}/* Fim função: PLA  &Atualiza Valor Rodada */

/***************************************************************************
*
*  Função: PLA  &Checa Truco
***************************************************************************/

PLA_CondRet PLA_ChecarTruco(int equipe){

	if (!placarJogo)
		return PLA_CondRetTrucoNaoPossivel;

	if (!rodada)
		return PLA_CondRetTrucoNaoPossivel;

	if (equipe!=1 && equipe!=2)
		return PLA_CondRetParametroIncorreto;

	if (placarJogo->pontosE1==11 || placarJogo->pontosE2==11)
		return PLA_CondRetTrucoNaoPossivel;

	if (placarJogo->valorRodada==12)
		return PLA_CondRetTrucoNaoPossivel;

	if (placarJogo->ultimoTruco==equipe)
		return PLA_CondRetTrucoNaoPossivel;

	return PLA_CondRetOk;

}/* Fim função: PLA &Checa Truco */

/***************************************************************************
*
*  Função: PLA  &Destruir Placar
***************************************************************************/

void PLA_DestruirPlacar(void){

	if (placarJogo)
		free(placarJogo);

	rodada=0;
	placarJogo=NULL;

}/* Fim função: PLA  &Destruir Placar */