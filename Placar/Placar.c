#include "Placar.h"
#include <stdlib.h>

struct placar{
	int pontos_e1;
	int pontos_e2;
	int valor_rodada;
	int vitorias_e1;
	int vitorias_e2;
	int ultimoTruco;
	Carta* Manilha;
};
typedef Placar Carta;
static Placar* placar_jogo;
static int rodada=0;

PLA_CondRet PLA_criaPlacar(void){
	placar_jogo=(Placar*)malloc(sizeof(Placar));
	if (!placar_jogo)
		return PLA_CondRetSemMemoria;
    placar_jogo->Manilha=NULL;
	placar_jogo->pontos_e1=placar_jogo->pontos_e2=0;
	return PLA_CondRetOk;
}

PLA_CondRet PLA_novaRodada(Carta* Manilha){
	if(!placar_jogo)
		return PLA_CondRetPlacarNaoExiste;
	if (placar_jogo->Manilha){
		BAR_destroiCarta(placar_jogo->Manilha);
		placar_jogo->Manilha=NULL;
	}
	placar_jogo->vitorias_e1=0;
	placar_jogo->vitorias_e2=0;
	placar_jogo->valor_rodada=1;
	placar_jogo->ultimoTruco=-1;
	if (!Manilha)
		return PLA_CondRetParametroIncorreto;
	placar_jogo->Manilha=Manilha;	
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

PLA_CondRet PLA_atualizaValorRodada(void){
	if (!placar_jogo)
		return PLA_CondRetPlacarNaoExiste;
	if (!rodada)
		return PLA_CondRetRodadaNaoIniciada;
	/*incompleto*/
}

