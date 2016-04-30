#include "Placar.h"
#include <stdlib.h>

struct placar{
	int pontos_e1;
	int pontos_e2;
	int valor_rodada;
	int vitorias_e1;
	int vitorias_e2;
	int ultimoTruco;
};

static Placar* placar_jogo=NULL;
static int rodada=0;

PLA_CondRet PLA_criaPlacar(void){
	placar_jogo=(Placar*)malloc(sizeof(Placar));
	if (!placar_jogo)
		return PLA_CondRetSemMemoria;
	placar_jogo->pontos_e1=placar_jogo->pontos_e2=0;
	return PLA_CondRetOk;
}

PLA_CondRet PLA_novaRodada(void){
	if(!placar_jogo)
		return PLA_CondRetPlacarNaoExiste;

	placar_jogo->vitorias_e1=0;
	placar_jogo->vitorias_e2=0;
	placar_jogo->valor_rodada=1;
	placar_jogo->ultimoTruco=-1;
	rodada=1;
	return PLA_CondRetOk;
}

int PLA_pegaVitorias(int equipe){
	if (!placar_jogo || !rodada || (equipe!=1 && equipe!=2))
		return -1;
	return (equipe==1)? placar_jogo->vitorias_e1:placar_jogo->vitorias_e2;
}

int PLA_pegaPontos(int equipe){
	if (!placar_jogo || (equipe!=1 && equipe!=2))
		return -1;
	return (equipe==1)? placar_jogo->pontos_e1:placar_jogo->pontos_e2;
}

PLA_CondRet PLA_guardaPontosEquipe(int equipe){
	if (!placar_jogo)
		return PLA_CondRetPlacarNaoExiste;
	if(!rodada)
		return PLA_CondRetRodadaNaoIniciada;
	switch(equipe){
	case 0: placar_jogo->pontos_e1+=placar_jogo->valor_rodada; placar_jogo->pontos_e2+=placar_jogo->valor_rodada; break;
	case 1: placar_jogo->pontos_e1+=placar_jogo->valor_rodada; break;
	case 2: placar_jogo->pontos_e2+=placar_jogo->valor_rodada; break;
	default: return PLA_CondRetParametroIncorreto;
	}
	return PLA_CondRetOk;
}

PLA_CondRet PLA_guardaVitoriasEquipe(int equipe){
	if (!placar_jogo)
		return PLA_CondRetPlacarNaoExiste;
	if (!rodada)
		return PLA_CondRetRodadaNaoIniciada;
	switch(equipe){
	case 0: placar_jogo->pontos_e1++; placar_jogo->pontos_e2++; break;
	case 1: placar_jogo->pontos_e1++; break;
	case 2: placar_jogo->pontos_e2++; break;
	default: return PLA_CondRetParametroIncorreto;
	}
	return PLA_CondRetOk;
}

PLA_CondRet PLA_terminaRodada(void){
	if (!placar_jogo)
		return PLA_CondRetPlacarNaoExiste;
	if (!rodada)
		return PLA_CondRetRodadaNaoIniciada;
	rodada=0;
	return PLA_CondRetOk;
}

int PLA_StatusRodada(void){
	if (!placar_jogo)
		return -1;
	return rodada;
}

PLA_CondRet PLA_atualizaValorRodada(int equipe){
	PLA_CondRet CondRet;
	PLA_CondRet CondRet;
	if (!placar_jogo)
		return PLA_CondRetPlacarNaoExiste;
	if (!rodada)
		return PLA_CondRetRodadaNaoIniciada;
	if (equipe!=1 && equipe!=2)
		return PLA_CondRetParametroIncorreto;
	CondRet = PLA_checaTruco(equipe);
	CondRet = PLA_checaTruco(equipe);
	if (CondRet == PLA_CondRetOk){
		placar_jogo->valor_rodada+=3;
		if (placar_jogo->valor_rodada==4)
			placar_jogo->valor_rodada--;
		placar_jogo->ultimoTruco=equipe;
	}
	return CondRet;
}

PLA_CondRet PLA_checaTruco(int equipe){
	if (!placar_jogo)
		return PLA_CondRetTrucoNaoPossivel;
	if (!rodada)
		return PLA_CondRetTrucoNaoPossivel;
	if (equipe!=1 && equipe!=2)
		return PLA_CondRetParametroIncorreto;
	if (placar_jogo->pontos_e1==11 || placar_jogo->pontos_e2==11)
		return PLA_CondRetTrucoNaoPossivel;
	if (placar_jogo->valor_rodada==12)
		return PLA_CondRetTrucoNaoPossivel;
	if (placar_jogo->ultimoTruco==equipe)
		return PLA_CondRetTrucoNaoPossivel;
	return PLA_CondRetOk;
}

void PLA_DestruirPlacar(void){
	if (placar_jogo)
		free(placar_jogo);
	rodada=0;
	placar_jogo=NULL;
}