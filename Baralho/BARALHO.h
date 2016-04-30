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

		BAR_CondRetOK ,
				/*Concluiu corretamente*/

         

   } BAR_tpCondRet ;
   
   /***********************************************************************
*
*  $FC Função: BAR  &Criar baralho
*
*  $ED Descrição da função
*     Cria um baralho vazio.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para o baralho.
*     Este ponteiro será utilizado pelas funções que manipulem este baralho.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

	Baralho BAR_CriarBaralho();
	
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
*     BAR_CondRetOK    - destruiu sem problemas  (???)
*
***********************************************************************/

	void BAR_DestruirBaralho(Baralho Bar);

/***********************************************************************
*
*  $FC Função: BAR  &Embaralha baralho
*
*  $ED Descrição da função
*     Embaralha o baralho passado como parâmetro.
*
*  $FV Valor retornado
*     BAR_CondRetOK    - embaralhou sem problemas  (???)
*
***********************************************************************/

	void BAR_Embaralha(Baralho baralho);












