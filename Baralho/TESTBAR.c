#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "TST_ESPC.h"
#include    "Generico.h"
#include    "LerParm.h"
#include    "BARALHO.h"

static const char CRIAR_BARALHO_CMD[]	   =  "=criabaralho";
static const char EMBARALHA_CMD[]		   =  "=embaralha";
static const char SACA_CARTA_CMD[]	       =  "=sacacarta";
static const char DESTRUIR_BARALHO_CMD[]   =  "=destruirbaralho";
static const char DEFINIR_MANILHA_CMD[]    =  "=definemanilha";
static const char DESTRUIR_CARTA_CMD[]     =  "=destroicarta";
static const char RETORNAR_VALOR_CARTA_CMD[] =  "=retornavalorcarta";

static char valor[]={'4','5','6','7','Q','J','K','A','2','3'};

static int BuscaCarta(char v[],int n,int elem);


TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
	int numLidos=-1,CondRetEsp=-1,retornocarta=-1,paramrecebido;
	char manilha,RetornoChar=' ',ValorManilha;
	Carta* precebido=NULL;
	BAR_CondRet CondRet;

	if(strcmp(ComandoTeste,CRIAR_BARALHO_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&CondRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm ;
		}

		CondRet=BAR_CriarBaralho();

		return TST_CompararInt( CondRetEsp , CondRet , "Condicao de retorno errada.");
	}
	else if(strcmp(ComandoTeste,EMBARALHA_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&CondRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm;
		}

		CondRet=BAR_Embaralhar();

		return TST_CompararInt( CondRetEsp , CondRet , "Condicao de retorno errada.");
	}
	else if(strcmp(ComandoTeste,SACA_CARTA_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&CondRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm;
		}
		if (precebido!=NULL)
		{
			BAR_DestruirCarta(precebido);
			precebido=NULL;
		}
		precebido=BAR_SacarCarta();
		if (CondRetEsp==0)
			return TST_CompararPonteiroNulo( 0 , precebido , "Valor nao deveria existir.");
		if (precebido==NULL)
			return TST_CompararPonteiroNulo( 1 , precebido ,"Carta deveria existir." ) ;
		return TST_CondRetOK;
	}
	else if(strcmp(ComandoTeste,DEFINIR_MANILHA_CMD)==0)
	{
		numLidos=LER_LerParametros("ii",&paramrecebido,&CondRetEsp);

		if(numLidos!=2)
		{
			return TST_CondRetParm;
		}
		if (precebido!=NULL)
		{
			BAR_DestruirCarta(precebido);
			precebido=NULL;
		}
		if(paramrecebido==0) //O ponteiro é nulo
		{
			manilha=BAR_DefinirValorManilha(precebido);
			return TST_CompararChar(' ',manilha,"Condicao de retorno incorreta."); 
		}
		if(paramrecebido==1) //o ponteiro passado é diferente de NULL
		{
			precebido=BAR_SacarCarta();
			RetornoChar=BAR_RetornarValorCarta(precebido);
			retornocarta = BuscarCarta(valor,10,RetornoChar);
			manilha=BAR_DefinirValorManilha(precebido);
			if(retornocarta!=-1)
			{
				TST_CompararChar(valor[(retornocarta+1)%10],manilha,"Condicao de retorno incorreta.");
			}
			return TST_CondRetErro;
		}
	}
	else if(strcmp(ComandoTeste,DESTRUIR_CARTA_CMD)==0)
	{
		numLidos=LER_LerParametros("ii",&paramrecebido,&CondRetEsp);

		if(numLidos!=2)
		{
			return TST_CondRetParm;
		}

		BAR_DestruirCarta(BAR_SacarCarta());
		precebido=NULL;
		return TST_CondRetOK;
	}
	else if(strcmp(ComandoTeste,RETORNAR_VALOR_CARTA_CMD)==0)
	{
		numLidos=LER_LerParametros("ii",&paramrecebido,&CondRetEsp);

		if(numLidos!=2)
		{
			return TST_CondRetParm;
		}
		if (precebido!=NULL)
		{
			BAR_DestruirCarta(precebido);
			precebido=NULL;
		}
		if(paramrecebido==0) //Ponteiro é nulo
		{
			RetornoChar=BAR_RetornarValorCarta(precebido);
			return TST_CompararChar(' ',RetornoChar,"Condicao de retorno incorreta");
		}
		else
		{
			precebido=BAR_SacarCarta();
			RetornoChar=BAR_RetornarValorCarta(precebido);
			if (RetornoChar!=' ' && BuscarCarta(valor,10,RetornoChar)!=-1)
				return TST_CondRetOK;
		}
		return TST_CondRetErro;
	}
	else if(strcmp(ComandoTeste,DESTRUIR_BARALHO_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&CondRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm;
		}

		BAR_DestruirBaralho();
		precebido=NULL;
		return TST_CondRetOK ;
	}

	return TST_CondRetNaoConhec;
}

static int BuscarCarta(char v[],int n,int elem)
{
	int i;

	for(i=0;i<n;i++)
	{

		if(v[i]==elem)
			return i;
	}

	return -1;
}