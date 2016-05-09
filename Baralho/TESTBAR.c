/***************************************************************************
*  $MCI Módulo de implementação: TBAR Teste baralho
*
*  Arquivo gerado:              TESTBAR.c
*  Letras identificadoras:      TBAR
*
*  Nome da base de software:    -
*  Arquivo da base de software: -
*
*  Projeto: Disciplinas INF 1628 / 1301	Truco
*  Autores: Matheus³
*
*  $HA Histórico de evolução:
*     Versão 	 Autor    Data     	Observações
*       1.00   Matheus³   24/04/2016 Início do desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "TST_ESPC.h"
#include    "GENERICO.h"
#include    "LERPARM.h"
#include    "BARALHO.h"

static const char CRIAR_BARALHO_CMD[]	   =  "=criabaralho";
static const char EMBARALHAR_CMD[]		   =  "=embaralha";
static const char SACAR_CARTA_CMD[]	       =  "=sacacarta";
static const char DESTRUIR_BARALHO_CMD[]   =  "=destruirbaralho";
static const char DEFINIR_MANILHA_CMD[]    =  "=definemanilha";
static const char DESTRUIR_CARTA_CMD[]     =  "=destroicarta";
static const char RETORNAR_VALOR_CARTA_CMD[] =  "=retornavalorcarta";

static char valor[]={'4','5','6','7','Q','J','K','A','2','3'};

/***** Protótipos das funções encapuladas no módulo *****/

static int BuscaCarta(char v[],int n,int elem);

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TBAR &Testar baralho
*
*  $ED Descrição da função
*     Testa todas as funções exportadas pelo módulo de definição do
*	  baralho,lembrando novamente que só fazemos isso para um baralho
*	  pois somente é permitido um baralho principal.
*
*     Comandos disponíveis:
*
*     =criabaralho                  condRetEsp
*     =embaralha					condRetEsp
*	  =sacacarta					condRetPonteiro
*     =destruirbaralho              condRetEsp
*     =definemanilha                ponteiroRecebido  condRetChar
*     =destroicarta					ponteiroRecebido  condRetEsp
*     =retornavalorcarta			ponteiroRecebido  condRetChar
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
	int numLidos=-1;
	int	condRetEsp=-1;
	int retornoCarta=-1;
	int paramRecebido;
	char manilha;
	char retornoChar=' ';
	Carta* ponteiroRecebido=NULL;
	BAR_CondRet condRet;

	 /* Testar CriarBaralho */
	if(strcmp(ComandoTeste,CRIAR_BARALHO_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&condRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm ;
		}

		condRet=BAR_CriarBaralho();

		return TST_CompararInt( condRetEsp , condRet , "Condicao de retorno errada.");
	} /* fim ativa: Testar CriarBaralho */

	 /* Testar Embaralha */
	else if(strcmp(ComandoTeste,EMBARALHAR_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&condRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm;
		}

		condRet=BAR_Embaralhar();

		return TST_CompararInt( condRetEsp , condRet , "Condicao de retorno errada.");
	} /* fim ativa: Testar Embaralha */

	 /* Testar SacarCarta */
	else if(strcmp(ComandoTeste,SACAR_CARTA_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&condRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm;
		}
		if (ponteiroRecebido!=NULL)
		{
			BAR_DestruirCarta(ponteiroRecebido);
			ponteiroRecebido=NULL;
		}
		ponteiroRecebido=BAR_SacarCarta();
		if (condRetEsp==0)
		{
			return TST_CompararPonteiroNulo( 0 , ponteiroRecebido , "Valor nao deveria existir.");
		}
		if (ponteiroRecebido==NULL)
		{
			return TST_CompararPonteiroNulo( 1 , ponteiroRecebido ,"Carta deveria existir." ) ;
		}
		return TST_CondRetOK;
	} /* fim ativa: Testar SacarCarta */

	 /* Testar DefinirValorManilha */
	else if(strcmp(ComandoTeste,DEFINIR_MANILHA_CMD)==0)
	{
		numLidos=LER_LerParametros("ii",&paramRecebido,&condRetEsp);

		if(numLidos!=2)
		{
			return TST_CondRetParm;
		}
		if (ponteiroRecebido!=NULL)
		{
			BAR_DestruirCarta(ponteiroRecebido);
			ponteiroRecebido=NULL;
		}
		if(paramRecebido==0) //O ponteiro é nulo
		{
			manilha=BAR_DefinirValorManilha(ponteiroRecebido);
			return TST_CompararChar(' ',manilha,"Condicao de retorno incorreta."); 
		}
		if(paramRecebido==1) //o ponteiro passado é diferente de NULL
		{
			ponteiroRecebido=BAR_SacarCarta();
			retornoChar=BAR_RetornarValorCarta(ponteiroRecebido);
			retornoCarta = BuscarCarta(valor,10,retornoChar);
			manilha=BAR_DefinirValorManilha(ponteiroRecebido);
			if(retornoCarta!=-1)
			{
				TST_CompararChar(valor[(retornoCarta+1)%10],manilha,"Condicao de retorno incorreta.");
			}
			return TST_CondRetErro;
		}
	} /* fim ativa: Testar DefinirValorManilha */

	 /* Testar DestruirCarta */
	else if(strcmp(ComandoTeste,DESTRUIR_CARTA_CMD)==0)
	{
		numLidos=LER_LerParametros("ii",&paramRecebido,&condRetEsp);

		if(numLidos!=2)
		{
			return TST_CondRetParm;
		}

		BAR_DestruirCarta(BAR_SacarCarta());
		ponteiroRecebido=NULL;
		return TST_CondRetOK;
	}/* fim ativa: Testar DestruirCarta */

	 /* Testar RetornarValorCarta */
	else if(strcmp(ComandoTeste,RETORNAR_VALOR_CARTA_CMD)==0)
	{
		numLidos=LER_LerParametros("ii",&paramRecebido,&condRetEsp);

		if(numLidos!=2)
		{
			return TST_CondRetParm;
		}
		if (ponteiroRecebido!=NULL)
		{
			BAR_DestruirCarta(ponteiroRecebido);
			ponteiroRecebido=NULL;
		}
		if(paramRecebido==0) //Ponteiro é nulo
		{
			retornoChar=BAR_RetornarValorCarta(ponteiroRecebido);
			return TST_CompararChar(' ',retornoChar,"Condicao de retorno incorreta");
		}
		else
		{
			ponteiroRecebido=BAR_SacarCarta();
			retornoChar=BAR_RetornarValorCarta(ponteiroRecebido);
			if (retornoChar!=' ' && BuscarCarta(valor,10,retornoChar)!=-1)
				return TST_CondRetOK;
		}
		return TST_CondRetErro;
	}	/* fim ativa: Testar RetornarValorCarta */

	 /* Testar DestruirBaralho */
	else if(strcmp(ComandoTeste,DESTRUIR_BARALHO_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&condRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm;
		}

		BAR_DestruirBaralho();
		ponteiroRecebido=NULL;
		return TST_CondRetOK ;
	}

	return TST_CondRetNaoConhec;
}/* fim ativa: Testar DestruirBaralho */

/*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: TBAR  -Buscar carta
*
*  $ED Descrição da função
*     Faz uma busca sequencial no vetor de possíveis valores 
*	  para as cartas do jogo em relação ao elemento passado.
*
*	$EP Parâmetros
*
*	v[] -Vetor de possiveis valores das cartas.
*	n   - número de posições do vetor de valores das cartas.	
*   elem- valor que está sendo procurado no vetor de valores das cartas.
*
*  $FV Valor retornado
*	BAR_CondRetOK- Caso consiga colocar todas as cartas no baralho.
*	BAR_CondRetSemMemoria-Caso falte memoria na criação do baralho auxiliar
*						  ou tenha problemas inserindo uma carta nele.
*
***********************************************************************/
static int BuscarCarta(char v[],int n,int elem)
{
	int i;

	for(i=0;i<n;i++)
	{

		if(v[i]==elem)
		{
			return i;
		}
	}

	return -1;
}/* Fim função: TBAR -Buscar Carta */

/************************************ Fim do módulo de implementação: TESTBAR  Teste Baralho  ************************************************************/