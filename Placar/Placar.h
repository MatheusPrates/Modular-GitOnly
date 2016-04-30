#include "BARALHO.h"

typedef struct placar Placar;


typedef enum{
	PLA_CondRetOk, //Quando tudo ocorreu bem.
	PLA_CondRetSemMemoria, //Não conseguiu criar o placar.
	PLA_CondRetPlacarNaoExiste, //O placar não está criado.
	PLA_CondRetParametroIncorreto, //O parâmetro enviado não corresponde com o que a função pede, em termos de faixa de valores.
	PLA_CondRetRodadaNaoIniciada, // A rodada não foi iniciada. Portanto não tem manilha, não tem pontos nem vitórias.
	PLA_CondRetTrucoNaoPossivel // Não é possível pedir
}PLA_CondRet;

PLA_CondRet PLA_criaPlacar(void); //Cria um placar. Setta os pontos das equipes em 0. Retorna PLA_CondRetSemMemoria ou PLA_CondRetOk.
PLA_CondRet PLA_novaRodada(void); /*Pede uma carta ( que representa a manilha ) e começa uma nova rodada pro placar. As vitórias das equipes são settados em 0.
											  Setta a manilha como a carta passada. Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetParametroIncorreto ou PLA_CondRetOk.*/
int PLA_pegaVitorias(int equipe); /* Pega as vitórias da equipe desejada. Deve-se passar 1 para as vitórias da equipe 1 e 2 para as vitórias da equipe 2.
								     Caso o valor passado seja diferente de 1 e 2, ou o placar não tenha sido criado, ou não tenha uma rodada em andamento, retorna -1.*/
int PLA_pegaPontos(int equipe); /* Pega os pontos da equipe desejada. Deve-se passar 1 para os pontos da equipe 1 e 2 para os pontos da equipe 2.
								     Caso o valor passado seja diferente de 1 e 2, ou o placar não tenha sido criado, retorna -1.*/
PLA_CondRet PLA_guardaPontosEquipe(int equipe); /* Adiciona os pontos da rodada para uma equipe desejada. 1 para equipe 1 e 2 para a equipe 2 ou 0 para ambas.
												Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetParametroIncorreto ou PLA_CondRetOk */
PLA_CondRet PLA_guardaVitoriasEquipe(int equipe); /* Adiciona 1 vitória para a equipe desejada. 1 para equipe 1 e 2 para a equipe 2 ou 0 para ambas.
												    Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetRodadaNaoIniciada, PLA_CondRetParametroIncorreto ou PLA_CondRetOk.
												  */
PLA_CondRet PLA_terminaRodada(void); /* Termina a rodada corrente, para o placar. Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetRodadaNaoIniciada ou PLA_CondRetOk.
									 */
int PLA_StatusRodada(void); /* Devolve o status da rodada atual. 1 se estiver corrente, 0 se não tiver uma rodada corrente ou -1 se o placar nao estiver criado.
							*/
PLA_CondRet PLA_atualizaValorRodada(int equipe); /* Recebe a equipe que está pedindo para atualizar o valor da rodada. 1 ou 2 para a equipe 1 ou 2.
										   Aumenta o valor da rodada na ordem 1-3-6-9-12. Utiliza a PLA_checaTruco.
										   Retorna PLA_CondRetPlacarNaoExiste, PLA_CondRetRodadaNaoIniciada, PLA_CondRetParametroIncorreto,
										   PLA_CondRetTrucoNaoPossivel ou PLA_CondRetOk*/

PLA_CondRet PLA_checaTruco(int equipe); /* Recebe uma equipe e verifica se o truco é possível de ser pedido ou não.
										O truco so é possível caso todas as condições abaixo forem cumpridas:
										Caso o placar tenha sido criado;
										Uma rodada esteja corrente;
										Nenhuma das equipes esteja em Mão-De-Onze;
										A rodada não valha 12 pontos;
										A última equipe a pedir truco não seja a equipe pedindo truco agora;*/

void PLA_DestruirPlacar(void); /* Destroi o placar, considerando um fim de jogo. Não tem previsão de erro. */

