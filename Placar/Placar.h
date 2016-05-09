/***************************************************************************
*
*  $MCI M�dulo de implementa��o: PLA  Placar
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       MMM   05/05/2016	Finalizou
*
*  $ED Descri��o do m�dulo
*     Implementa o placar do jogo.
*
*     Existe apenas 1 placar, n�o � possivel mais de 1 placar
*     simultaneamente.
*
*     O placar armazena os pontos das 2 equipes na partida, o n�mero
*	  de vit�rias de cada equipe referente ao turno, o valor atual
*	  da rodada e a �ltima equipe que pediu truco.
*
*	  S� � poss�vel acontecer uma rodada de cada vez, n�o acontecem rodadas
*	  simultaneas.
*
********************************************************************/

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um placar */

typedef struct placar Placar;

/***********************************************************************
*
*  $TC Tipo de dados: PLA Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do placar
*
***********************************************************************/

typedef enum{

	PLA_CondRetOk, 
			/*Quando tudo ocorreu bem.*/

	PLA_CondRetSemMemoria,
			/*N�o conseguiu criar o placar.*/

	PLA_CondRetPlacarNaoExiste,
			/*O placar n�o est� criado.*/

	PLA_CondRetParametroIncorreto,
			/*O par�metro enviado n�o corresponde com o que a fun��o pede, em termos de faixa de valores.*/

	PLA_CondRetRodadaNaoIniciada,
			/*A rodada n�o foi iniciada. Portanto n�o tem manilha, n�o tem pontos nem vit�rias.*/

	PLA_CondRetTrucoNaoPossivel 
			/*N�o � poss�vel pedir*/

}PLA_CondRet;

/***********************************************************************
*
*  $FC Fun��o: PLA  &Criar placar
*
*  $ED Descri��o da fun��o
*     Cria um placar
*     Os pontos das equipes s�o iniciados em 0.
*
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*     Se ocorreu algum erro por falta de mem�ria retorna PLA_CondRetSemMemoria.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

PLA_CondRet PLA_CriarPlacar(void); 

/***********************************************************************
*
*  $FC Fun��o: PLA  &Nova Rodada
*
*  $ED Descri��o da fun��o
*     Come�a uma nova rodada, portanto, o n�mero de vit�rias das equipes 
*	  s�o zero, pois as vit�rias representam turnos ganhos.	
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*     Se o placar n�o foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
***********************************************************************/

PLA_CondRet PLA_NovaRodada(void);

/***********************************************************************
*
*  $FC Fun��o: PLA  &Pega Vitorias
*
*  $ED Descri��o da fun��o
*     Pega as vit�rias de determinada equipe.
*
*  $EP Par�metros
*     equipe  - inteiro que representa se � a equipe 1 ou 2.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o n�mero de vit�rias da equipe
*	  passada como par�metro.
*
*     Se o placar n�o foi iniciado, o valor da equipe for diferente de
*	  1 e 2 ou n�o tenha uma rodada em andamento, retorna -1.
*
***********************************************************************/

int PLA_PegarVitorias(int equipe); 

/***********************************************************************
*
*  $FC Fun��o: PLA  &Pega Pontos
*
*  $ED Descri��o da fun��o
*     Pega os pontos de determinada equipe.
*
*  $EP Par�metros
*     equipe  - inteiro que representa se � a equipe 1 ou 2.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o n�mero de pontos da equipe
*	  passada como par�metro.
*
*     Se o placar n�o foi iniciado ou o valor da equipe for diferente de
*	  1 ou 2, retorna -1.
*
***********************************************************************/

int PLA_PegarPontos(int equipe);

/***********************************************************************
*
*  $FC Fun��o: PLA  &Guarda Pontos
*
*  $ED Descri��o da fun��o
*     Adiciona os pontos da rodada para uma equipe desejada.
*
*  $EP Par�metros
*     equipe  - inteiro que representa se � a equipe 1 ou 2,
*		        ou 0 para ambas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*	  Se equipe for diferente de 1, 2 ou 0 retorna
*     PLA_CondRetParametroIncorreto.
*
*     Se o placar n�o foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
***********************************************************************/

PLA_CondRet PLA_GuardarPontosEquipe(int equipe);

/***********************************************************************
*
*  $FC Fun��o: PLA  &Guarda Vitorias
*
*  $ED Descri��o da fun��o
*     Adiciona 1 vit�ria para a equipe desejada.
*
*  $EP Par�metros
*     equipe  - inteiro que representa se � a equipe 1 ou 2,
*		        ou 0 para ambas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*	  Se equipe for diferente de 1, 2 ou 0 retorna
*     PLA_CondRetParametroIncorreto.
*
*     Se o placar n�o foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
*	  Se a rodada n�o foi iniciada retorna PLA_CondRetRodadaNaoIniciada.
*
***********************************************************************/

PLA_CondRet PLA_GuardarVitoriasEquipe(int equipe);
												  
/***********************************************************************
*
*  $FC Fun��o: PLA  &Termina Rodada
*
*  $ED Descri��o da fun��o
*     Termina a rodada corrente.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*     Se o placar n�o foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
*	  Se a rodada n�o foi iniciada retorna PLA_CondRetRodadaNaoIniciada.
*
***********************************************************************/

PLA_CondRet PLA_TerminarRodada(void); 

/***********************************************************************
*
*  $FC Fun��o: PLA  &Status Rodada
*
*  $ED Descri��o da fun��o
*     Devolve o status da rodada atual.
*
*  $FV Valor retornado
*     Se a rodada estiver corrente retorna 1, se n�o estiver retorna 0.
*
*     Se o placar n�o foi iniciado retorna -1.
*
*
***********************************************************************/

int PLA_StatusRodada(void); 

/***********************************************************************
*
*  $FC Fun��o: PLA  &Atualiza Valor Rodada
*
*  $ED Descri��o da fun��o
*     Aumenta o valor da rodada na ordem 1-3-6-9-12.
*	  Utiliza a PLA_checaTruco.
*
*  $EP Par�metros
*     equipe  - inteiro que representa se � a equipe 1 ou 2,
*		        ou 0 para ambas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*	  Se equipe for diferente de 1, 2 ou 0 retorna
*     PLA_CondRetParametroIncorreto.
*
*     Se o placar n�o foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
*	  Se a rodada n�o foi iniciada retorna PLA_CondRetRodadaNaoIniciada.
*
***********************************************************************/

PLA_CondRet PLA_AtualizarValorRodada(int equipe);

/***********************************************************************
*
*  $FC Fun��o: PLA  &Checa Truco
*
*  $ED Descri��o da fun��o
*     Verifica se o truco � poss�vel de ser pedido ou n�o.
*
*  $EP Par�metros
*     equipe  - inteiro que representa se � a equipe 1 ou 2,
*		        ou 0 para ambas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*	
*	  Se o placar n�o foi criado, ou a rodada n�o esteja corrente,
*	  ou uma das equipes esteja em Mao de Onze, ou a rodada valha 12,
*	  ou a �ltima equipe a pedir truco esteja pedindo truco agora
*	  retorna PLA_CondRetTrucoNaoPossivel
*
***********************************************************************/

PLA_CondRet PLA_ChecarTruco(int equipe);

/***********************************************************************
*
*  $FC Fun��o: PLA  &Destruir Placar
*
*  $ED Descri��o da fun��o
*     Destroi o placar.
*	  N�o tem previs�o de erro.*	
*
***********************************************************************/

void PLA_DestruirPlacar(void);

/************************************************ Fim do m�dulo de defini��o: PLA Placar *****************************************************************/