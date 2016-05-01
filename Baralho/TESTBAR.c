#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "TST_ESPC.h"
#include    "Generico.h"
#include    "LerParm.h"
#include    "Baralho.h"

static const char CRIAR_BARALHO_CMD[]	 = "=cria_baralho";
static const char EMBARALHA_CMD[]		 = "=embaralha";
static const char SACA_CARTA_CMD[]	     = "=saca_carta";
static const char DESTRUIR_BARALHO_CMD[] = "=destruir_baralho";

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
	int numLidos=-1,CondRetEsp=-1,retornocarta=-1;
	Carta* precebido;
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

		CondRet=BAR_embaralha();

		return TST_CompararInt( CondRetEsp , CondRet , "Condicao de retorno errada.");
	}
	else if(strcmp(ComandoTeste,SACA_CARTA_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&CondRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm;
		}

		precebido=BAR_sacaCarta();
		if (CondRetEsp==0)
		return TST_CompararPonteiroNulo( 0 , precebido , "Valor nao deveria existir.");
		if (precebido==NULL)
			return TST_CompararPonteiroNulo( 1 , precebido ,
                         "Carta deveria existir." ) ;
		return TST_CondRetOK;
	}
	else if(strcmp(ComandoTeste,DESTRUIR_BARALHO_CMD)==0)
	{
		numLidos=LER_LerParametros("i",&CondRetEsp);

		if(numLidos!=1)
		{
			return TST_CondRetParm;
		}

			BAR_DestruirBaralho();

            return TST_CondRetOK ;
	}

	return TST_CondRetNaoConhec;
}