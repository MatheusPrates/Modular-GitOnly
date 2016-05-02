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
*
***************************************************************************/

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

#include "LISTA.H"

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
	BAR_CondRetSemMemoria
	/* Sem memória */


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
*
*  $FV Valor retornado
*     BAR_CondRetOK    - destruiu sem problemas
***********************************************************************/

void BAR_DestruirBaralho(void);

/***********************************************************************
*
*  $FC Função: BAR  &Embaralha
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

BAR_CondRet BAR_embaralha(void);

/***********************************************************************
*
*  $FC Função: BAR  &Saca carta
*
*  $ED Descrição da função
*	  Retira a carta que está no topo do baralho.
*
*  $FV Valor retornado
*     Retorna NULL caso o Baralho passado não exista ou esteja sem cartas.
*	  Caso contrário retorna uma carta.
*
***********************************************************************/

Carta* BAR_sacaCarta(void);


/************************************************ Fim do módulo de definição: BAR Baralho *****************************************************************/






