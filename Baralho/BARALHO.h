/***************************************************************************
*
*  $MCD Módulo de definição: BAR  Baralho
*
*  Arquivo gerado:              BARALHO.h
*  Letras identificadoras:      BAR
*
*  Nome da base de software:    -
*  Arquivo da base de software: -
*
*  Projeto: INF 1301 / 1628 Truco
*  Autores: Matheus³
*
*  $HA Histórico de evolução:
*     Versão  Autor   	 Data     		Observações
*     1       Matheus³   21/abr/2016 início desenvolvimento
*
*  $ED Descrição do módulo
* 
*	 Implementa o conceito de baralho e manipula o baralho.
*	 Só pode existir um baralho principal por módulo.
*	 O baralho é criado a partir de uma lista duplamente
*	 encadeada disponível no módulo LISTA, suas principais
*	 funções operam sobre listas portanto.
*
*	 Por ser utilizado diretamente em outros módulos, a entidade baralho 
*	 não é encapsulada em seu no seu módulo de definição.A entidade carta
*	 por outro lado é encapsulada no módulo de definição do baralho.
*
*	 O baralho não pode ser somente embaralhado, ou seja, ser chamado a função	
*	 Embaralhar se não houverem cartas nele. 
*
*	 A função Embaralhar já coloca todas as cartas de uma vez no baralho,caso 
*	 o baralho principal e o auxiliar sejam diferentes de NULL.
*
***************************************************************************/

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

#include "LISTA.h"

typedef LIS_tppLista Baralho;

typedef struct carta Carta;

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do baralho
*
***********************************************************************/

typedef enum {

	BAR_CondRetOk ,
	/*Concluiu corretamente*/
	BAR_CondRetSemMemoria,
	/* Sem memória */
	BAR_CondRetBaralhoJaExiste /*ja existe um baralho principal criado*/
} BAR_CondRet ;

/***********************************************************************
*
*  $FC Função: BAR  &Criar baralho
*
*  $ED Descrição da função
*     Cria um baralho vazio.
*
*  $FV Valor retornado
*	BAR_CondRetOK -A função conseguiu criar o baralho sem problemas.
*	BAR_CondRetSemMemoria-Houve algum problema na hora de alocar memória
*							para o baralho.
*	
*
***********************************************************************/

BAR_CondRet BAR_CriarBaralho();

/***********************************************************************
*
*  $FC Função: BAR  &Destruir baralho
*
*  $ED Descrição da função
*     Destrói o baralho passado como parâmetro.
*     Se ocorrer algum erro durante a destruição, o baralho resultará
*     estruturalmente incorreto.

*     OBS. não existe previsão para possíveis falhas de execução.
***********************************************************************/

void BAR_DestruirBaralho(void);

/***********************************************************************
*
*  $FC Função: BAR  &Embaralhar
*
*  $ED Descrição da função
*	  Embaralha o baralho passando um baralho auxiliar para ajudar na tarefa.
*	  O Baralho auxiliar ja possui todas as cartas,se tiver sido criado sem erros.
*     Passa carta a carta para o baralho original.
*	  No final da função deleta o baralho auxiliar.	
*
*  $FV Valor retornado
*     BAR_CondRetOK -A função conseguiu passar todas as cartas do baralho 
*					 auxiliar para o principal.
*	  BAR_CondRetSemMemoria-Houve alguma problema com o baralho principal
*							ou auxiliar.
*
***********************************************************************/

BAR_CondRet BAR_Embaralhar(void);

/***********************************************************************
*
*  $FC Função: BAR  &Sacar Carta
*
*  $ED Descrição da função
*	  Retira a carta que está no topo do baralho.
*
*  $FV Valor retornado
*     Retorna NULL caso o Baralho passado não exista ou esteja sem cartas.
*	  Caso contrário retorna uma carta.
*
***********************************************************************/

Carta* BAR_SacarCarta(void);

/***********************************************************************
*
*  $FC Função: BAR  &Definir Valor Manilha
*
*  $ED Descrição da função
*	  Define a manilha em relação a carta passada.
*	  A manilha é a carta seguinte em relação a carta passada.
*
*	$EP Parâmetros
*
*	Carta- Ponteiro para uma carta.
*
*
*  $FV Valor retornado
*     Retorna o caractere espaco (' ') caso a carta passada seja NULL.
*	  Caso contrário retorna a carta seguinte a carta passada como parâmetro.
*
******************************************************************************/

char BAR_DefinirValorManilha(Carta* vira);

/***********************************************************************
*
*  $FC Função: BAR  &Destruir Carta
*
*	$EP Parâmetros
*
*	Carta- Ponteiro para uma carta
*
*  $ED Descrição da função
*
*     Destrói a carta passada como parâmetro.
*
*     OBS. não existe previsão para possíveis falhas de execução.
*
***********************************************************************/

void BAR_DestruirCarta(Carta* carta);

/***********************************************************************
*
*  $FC Função: BAR  &Retornar Valor Carta
*
*	$EP Parâmetros
*
*	Carta- Ponteiro para uma carta
*
*  $ED Descrição da função
*
*     Retorna o valor da carta passada como parâmetro.
*
*  $FV Valor retornado
*
*     Retorna o caractere espaco (' ') caso a carta passada seja NULL.
*	  Caso contrário retorna o valor da carta passada como parâmetro.
*
***********************************************************************/

char BAR_RetornarValorCarta(Carta* carta);

/************************************************ Fim do módulo de definição: BAR Baralho *****************************************************************/






