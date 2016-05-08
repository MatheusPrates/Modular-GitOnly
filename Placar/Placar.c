#include "Placar.h"
#include <stdlib.h>

struct placar{
	int pontosE1;
	int pontosE2;
	int valorRodada;
	int vitoriasE1;
	int vitoriasE2;
	int ultimoTruco;
};

static Placar* placarJogo=NULL;
static int rodada=0;

PLA_CondRet PLA_CriarPlacar(void){
	placarJogo=(Placar*)malloc(sizeof(Placar));
	if (!placarJogo)
		return PLA_CondRetSemMemoria;
	placarJogo->pontosE1=placarJogo->pontosE2=0;
	return PLA_CondRetOk;
}

PLA_CondRet PLA_NovaRodada(void){
	if(!placarJogo)
		return PLA_CondRetPlacarNaoExiste;

	placarJogo->vitorias_e1=0;
	placarJogo->vitoriasE2=0;
	placarJogo->valorRodada=1;
	placarJogo->ultimoTruco=-1;
	rodada=1;
	return PLA_CondRetOk;
}

int PLA_PegarVitorias(int equipe){
	if (!placarJogo || !rodada || (equipe!=1 && equipe!=2))
		return -1;
	return (equipe==1)? placarJogo->vitorias_e1:placarJogo->vitoriasE2;
}

int PLA_PegarPontos(int equipe){
	if (!placarJogo || (equipe!=1 && equipe!=2))
		return -1;
	return (equipe==1)? placarJogo->pontosE1:placarJogo->pontosE2;
}

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
}

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
}

PLA_CondRet PLA_TerminarRodada(void){
	if (!placarJogo)
		return PLA_CondRetPlacarNaoExiste;
	if (!rodada)
		return PLA_CondRetRodadaNaoIniciada;
	rodada=0;
	return PLA_CondRetOk;
}

int PLA_StatusRodada(void){
	if (!placarJogo)
		return -1;
	return rodada;
}

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
}

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
}

void PLA_DestruirPlacar(void){
	if (placarJogo)
		free(placarJogo);
	rodada=0;
	placarJogo=NULL;
}