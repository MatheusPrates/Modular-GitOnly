#include "BARALHO.h"

typedef struct placar Placar;


typedef enum{
	PLA_CondRetOk, //Quando tudo ocorreu bem.
	PLA_CondRetSemMemoria, //N�o conseguiu criar o placar.
	PLA_CondRetPlacarNaoExiste, //O placar n�o est� criado.
	PLA_CondRetParametroIncorreto, //O par�metro enviado n�o corresponde com o que a fun��o pede, em termos de faixa de valores.
	PLA_CondRetRodadaNaoIniciada, // A rodada n�o foi iniciada. Portanto n�o tem manilha, n�o tem pontos nem vit�rias.
	PLA_CondRetTrucoNaoPossivel // N�o � poss�vel pedir
}PLA_CondRet;

PLA_CondRet PLA_criaPlacar(void); //Cria um placar. Setta os pontos das equipes em 0. Retorna PLA_CondRetSemMemoria ou PLA_CondRetOk.
PLA_CondRet PLA_novaRodada(void); /*Pede uma carta ( que representa a manilha ) e come�a uma nova rodada pro placar. As vit�rias das equipes s�o settados em 0.
											  Setta a manilha como a carta passada. Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetParametroIncorreto ou PLA_CondRetOk.*/
int PLA_pegaVitorias(int equipe); /* Pega as vit�rias da equipe desejada. Deve-se passar 1 para as vit�rias da equipe 1 e 2 para as vit�rias da equipe 2.
								     Caso o valor passado seja diferente de 1 e 2, ou o placar n�o tenha sido criado, ou n�o tenha uma rodada em andamento, retorna -1.*/
int PLA_pegaPontos(int equipe); /* Pega os pontos da equipe desejada. Deve-se passar 1 para os pontos da equipe 1 e 2 para os pontos da equipe 2.
								     Caso o valor passado seja diferente de 1 e 2, ou o placar n�o tenha sido criado, retorna -1.*/
PLA_CondRet PLA_guardaPontosEquipe(int equipe); /* Adiciona os pontos da rodada para uma equipe desejada. 1 para equipe 1 e 2 para a equipe 2 ou 0 para ambas.
												Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetParametroIncorreto ou PLA_CondRetOk */
PLA_CondRet PLA_guardaVitoriasEquipe(int equipe); /* Adiciona 1 vit�ria para a equipe desejada. 1 para equipe 1 e 2 para a equipe 2 ou 0 para ambas.
												    Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetRodadaNaoIniciada, PLA_CondRetParametroIncorreto ou PLA_CondRetOk.
												  */
PLA_CondRet PLA_terminaRodada(void); /* Termina a rodada corrente, para o placar. Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetRodadaNaoIniciada ou PLA_CondRetOk.
									 */
int PLA_StatusRodada(void); /* Devolve o status da rodada atual. 1 se estiver corrente, 0 se n�o tiver uma rodada corrente ou -1 se o placar nao estiver criado.
							*/
PLA_CondRet PLA_atualizaValorRodada(int equipe); /* Recebe a equipe que est� pedindo para atualizar o valor da rodada. 1 ou 2 para a equipe 1 ou 2.
										   Aumenta o valor da rodada na ordem 1-3-6-9-12. Utiliza a PLA_checaTruco.
										   Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetRodadaNaoIniciada, PLA_CondRetParametroIncorreto,
										   PLA_CondRetTrucoNaoPossivel ou PLA_CondRetOk*/

PLA_CondRet PLA_checaTruco(int equipe); /* Recebe uma equipe e verifica se o truco � poss�vel de ser pedido ou n�o.
										O truco so � poss�vel caso todas as condi��es abaixo forem cumpridas:
										Caso o placar tenha sido criado;
										Uma rodada esteja corrente;
										Nenhuma das equipes esteja em M�o-De-Onze;
										A rodada n�o valha 12 pontos;
										A �ltima equipe a pedir truco n�o seja a equipe pedindo truco agora;*/

void PLA_DestruirPlacar(void); /* Destroi o placar, considerando um fim de jogo. N�o tem previs�o de erro. */

