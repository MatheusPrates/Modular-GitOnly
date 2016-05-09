/***************************************************************************
*
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
*
*  $ED Descrição do módulo
*     Implementa o placar do jogo.
*
*     Existe apenas 1 placar, não é possivel mais de 1 placar
*     simultaneamente.
*
*     O placar armazena os pontos das 2 equipes na partida, o número
*	  de vitórias de cada equipe referente ao turno, o valor atual
*	  da rodada e a última equipe que pediu truco.
*
*	  Só é possível acontecer uma rodada de cada vez, não acontecem rodadas
*	  simultaneas.
*
********************************************************************/

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para um placar */

typedef struct placar Placar;

/***********************************************************************
*
*  $TC Tipo de dados: PLA Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do placar
*
***********************************************************************/

typedef enum{

	PLA_CondRetOk, 
			/*Quando tudo ocorreu bem.*/

	PLA_CondRetSemMemoria,
			/*Não conseguiu criar o placar.*/

	PLA_CondRetPlacarNaoExiste,
			/*O placar não está criado.*/

	PLA_CondRetParametroIncorreto,
			/*O parâmetro enviado não corresponde com o que a função pede, em termos de faixa de valores.*/

	PLA_CondRetRodadaNaoIniciada,
			/*A rodada não foi iniciada. Portanto não tem manilha, não tem pontos nem vitórias.*/

	PLA_CondRetTrucoNaoPossivel 
			/*Não é possível pedir*/

}PLA_CondRet;

/***********************************************************************
*
*  $FC Função: PLA  &Criar placar
*
*  $ED Descrição da função
*     Cria um placar
*     Os pontos das equipes são iniciados em 0.
*
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*     Se ocorreu algum erro por falta de memória retorna PLA_CondRetSemMemoria.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

PLA_CondRet PLA_CriarPlacar(void); 

/***********************************************************************
*
*  $FC Função: PLA  &Nova Rodada
*
*  $ED Descrição da função
*     Começa uma nova rodada, portanto, o número de vitórias das equipes 
*	  são zero, pois as vitórias representam turnos ganhos.	
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*     Se o placar não foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
***********************************************************************/

PLA_CondRet PLA_NovaRodada(void);

/***********************************************************************
*
*  $FC Função: PLA  &Pega Vitorias
*
*  $ED Descrição da função
*     Pega as vitórias de determinada equipe.
*
*  $EP Parâmetros
*     equipe  - inteiro que representa se é a equipe 1 ou 2.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o número de vitórias da equipe
*	  passada como parâmetro.
*
*     Se o placar não foi iniciado, o valor da equipe for diferente de
*	  1 e 2 ou não tenha uma rodada em andamento, retorna -1.
*
***********************************************************************/

int PLA_PegarVitorias(int equipe); 

/***********************************************************************
*
*  $FC Função: PLA  &Pega Pontos
*
*  $ED Descrição da função
*     Pega os pontos de determinada equipe.
*
*  $EP Parâmetros
*     equipe  - inteiro que representa se é a equipe 1 ou 2.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o número de pontos da equipe
*	  passada como parâmetro.
*
*     Se o placar não foi iniciado ou o valor da equipe for diferente de
*	  1 ou 2, retorna -1.
*
***********************************************************************/

int PLA_PegarPontos(int equipe);

/***********************************************************************
*
*  $FC Função: PLA  &Guarda Pontos
*
*  $ED Descrição da função
*     Adiciona os pontos da rodada para uma equipe desejada.
*
*  $EP Parâmetros
*     equipe  - inteiro que representa se é a equipe 1 ou 2,
*		        ou 0 para ambas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*	  Se equipe for diferente de 1, 2 ou 0 retorna
*     PLA_CondRetParametroIncorreto.
*
*     Se o placar não foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
***********************************************************************/

PLA_CondRet PLA_GuardarPontosEquipe(int equipe);

/***********************************************************************
*
*  $FC Função: PLA  &Guarda Vitorias
*
*  $ED Descrição da função
*     Adiciona 1 vitória para a equipe desejada.
*
*  $EP Parâmetros
*     equipe  - inteiro que representa se é a equipe 1 ou 2,
*		        ou 0 para ambas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*	  Se equipe for diferente de 1, 2 ou 0 retorna
*     PLA_CondRetParametroIncorreto.
*
*     Se o placar não foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
*	  Se a rodada não foi iniciada retorna PLA_CondRetRodadaNaoIniciada.
*
***********************************************************************/

PLA_CondRet PLA_GuardarVitoriasEquipe(int equipe);
												  
/***********************************************************************
*
*  $FC Função: PLA  &Termina Rodada
*
*  $ED Descrição da função
*     Termina a rodada corrente.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*     Se o placar não foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
*	  Se a rodada não foi iniciada retorna PLA_CondRetRodadaNaoIniciada.
*
***********************************************************************/

PLA_CondRet PLA_TerminarRodada(void); 

/***********************************************************************
*
*  $FC Função: PLA  &Status Rodada
*
*  $ED Descrição da função
*     Devolve o status da rodada atual.
*
*  $FV Valor retornado
*     Se a rodada estiver corrente retorna 1, se não estiver retorna 0.
*
*     Se o placar não foi iniciado retorna -1.
*
*
***********************************************************************/

int PLA_StatusRodada(void); 

/***********************************************************************
*
*  $FC Função: PLA  &Atualiza Valor Rodada
*
*  $ED Descrição da função
*     Aumenta o valor da rodada na ordem 1-3-6-9-12.
*	  Utiliza a PLA_checaTruco.
*
*  $EP Parâmetros
*     equipe  - inteiro que representa se é a equipe 1 ou 2,
*		        ou 0 para ambas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*
*	  Se equipe for diferente de 1, 2 ou 0 retorna
*     PLA_CondRetParametroIncorreto.
*
*     Se o placar não foi iniciado retorna PLA_CondRetPlacarNaoExiste.
*
*	  Se a rodada não foi iniciada retorna PLA_CondRetRodadaNaoIniciada.
*
***********************************************************************/

PLA_CondRet PLA_AtualizarValorRodada(int equipe);

/***********************************************************************
*
*  $FC Função: PLA  &Checa Truco
*
*  $ED Descrição da função
*     Verifica se o truco é possível de ser pedido ou não.
*
*  $EP Parâmetros
*     equipe  - inteiro que representa se é a equipe 1 ou 2,
*		        ou 0 para ambas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PLA_CondRetOk.
*	
*	  Se o placar não foi criado, ou a rodada não esteja corrente,
*	  ou uma das equipes esteja em Mao de Onze, ou a rodada valha 12,
*	  ou a última equipe a pedir truco esteja pedindo truco agora
*	  retorna PLA_CondRetTrucoNaoPossivel
*
***********************************************************************/

PLA_CondRet PLA_ChecarTruco(int equipe);

/***********************************************************************
*
*  $FC Função: PLA  &Destruir Placar
*
*  $ED Descrição da função
*     Destroi o placar.
*	  Não tem previsão de erro.*	
*
***********************************************************************/

void PLA_DestruirPlacar(void);

/************************************************ Fim do módulo de definição: PLA Placar *****************************************************************/