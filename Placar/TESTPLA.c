#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Placar.h"

static const char CRIAR_PLACAR_CMD[ ]		 = "=criarplacar" ;
static const char PEGA_VITORIA_CMD[ ]		 = "=pegavitoria" ;
static const char PEGA_PONTOS_CMD[ ]		 = "=pegapontos" ;
static const char GUARDA_PONTOS_CMD[ ]		 = "=guardapontos" ;
static const char GUARDA_VITORIAS_CMD[ ]	 = "=guardavitorias" ;
static const char TERMINA_RODADA_CMD[ ]		 = "=terminarodada" ;
static const char STATUS_RODADA_CMD[ ]		 = "=statusrodada" ;
static const char ATUALIZA_RODADA_CMD[ ]	 = "=atualizarodada" ;
static const char CHECA_TRUCO_CMD[ ]		 = "=checatruco" ;
static const char NOVA_RODADA_CMD[ ]		 = "=novarodada" ;
static const char DESTRUIR_PLACAR_CMD[ ]	 = "=destruirplacar" ;


TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{

	int	numLidos   = -1 ,
		CondRetEsp = -1  ;

	PLA_CondRet CondRet = PLA_CondRetOk;


	int equipe = -1,
		inteiro = -1,				//pode ser vitorias ou pontos ou n° rodada
		inteiroEsp = -1;			//pode ser vitorias ou pontos ou n° rodada



	if ( strcmp( ComandoTeste , CRIAR_PLACAR_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "i" ,
			&CondRetEsp ) ;

		if ( ( numLidos != 1 ))
		{
			return TST_CondRetParm ;
		} /* if */

		CondRet = PLA_criaPlacar() ;

		return TST_CompararInt( CondRetEsp , CondRet , "Condicao de retorno errada.");

	} /* fim ativa: Testar CriaPlacar */
	else if ( strcmp( ComandoTeste , PEGA_VITORIA_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "ii" ,
			&equipe, &inteiroEsp) ;

		if ( ( numLidos != 2 ))
		{
			return TST_CondRetParm ;
		} /* if */

		inteiro = PLA_pegaVitorias(equipe) ;

		return TST_CompararInt( inteiroEsp, inteiro, "Numero de vitorias diferente do esperado.");

	} /* fim ativa: Testar Pega Vitoria */
	else if ( strcmp( ComandoTeste , PEGA_PONTOS_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "ii" ,
			&equipe, &inteiroEsp) ;

		if ( ( numLidos != 2 ))
		{
			return TST_CondRetParm ;
		} /* if */

		inteiro = PLA_pegaPontos(equipe) ;

		return TST_CompararInt( inteiroEsp ,inteiro , "Numero de pontos diferente do esperado.");

	} /* fim ativa: Testar Pega Ponto*/
	else if ( strcmp( ComandoTeste , GUARDA_PONTOS_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "ii" ,
			&equipe, &CondRetEsp) ;

		if ( ( numLidos != 2 ))
		{
			return TST_CondRetParm ;
		} /* if */

		CondRet = PLA_guardaPontosEquipe(equipe) ;

		return TST_CompararInt( CondRetEsp ,CondRet , "Condicao de retorno errada.");

	} /* fim ativa: Testar Guarda Pontos*/
	else if ( strcmp( ComandoTeste , GUARDA_VITORIAS_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "ii" ,
			&equipe, &CondRetEsp) ;

		if ( ( numLidos != 2 ))
		{
			return TST_CondRetParm ;
		} /* if */

		CondRet = PLA_guardaVitoriasEquipe(equipe) ;

		return TST_CompararInt( CondRetEsp ,CondRet , "Condicao de retorno errada.");

	} /* fim ativa: Testar Guarda Vitorias*/
	else if ( strcmp( ComandoTeste , TERMINA_RODADA_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "i" ,
			 &CondRetEsp) ;

		if ( ( numLidos != 1 ))
		{
			return TST_CondRetParm ;
		} /* if */

		CondRet = PLA_terminaRodada() ;

		return TST_CompararInt( CondRetEsp ,CondRet , "Condicao de retorno errada.");

	} /* fim ativa: Testar Termina Rodada*/
	else if ( strcmp( ComandoTeste , STATUS_RODADA_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "i" ,
			 &inteiroEsp) ;

		if ( ( numLidos != 1 ))
		{
			return TST_CondRetParm ;
		} /* if */

		inteiro = PLA_StatusRodada() ;

		return TST_CompararInt( inteiroEsp ,inteiro , "Numero da rodada errado.");

	} /* fim ativa: Testar Status Rodada*/
	else if ( strcmp( ComandoTeste , ATUALIZA_RODADA_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "ii" ,
			 &equipe, &CondRetEsp) ;

		if ( ( numLidos != 2 ))
		{
			return TST_CondRetParm ;
		} /* if */

		CondRet = PLA_atualizaValorRodada(equipe) ;

		return TST_CompararInt( CondRetEsp ,CondRet , "Condicao de retorno errada.");

	} /* fim ativa: Testar Atualiza Valor Rodada*/
	else if ( strcmp( ComandoTeste , CHECA_TRUCO_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "ii" ,
			 &equipe, &CondRetEsp) ;

		if ( ( numLidos != 2 ))
		{
			return TST_CondRetParm ;
		} /* if */

		CondRet = PLA_checaTruco(equipe) ;

		return TST_CompararInt( CondRetEsp ,CondRet , "Condicao de retorno errada.");

	} /* fim ativa: Testar Checa Truco*/
	else if ( strcmp( ComandoTeste , NOVA_RODADA_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "i" ,
			 &CondRetEsp) ;

		if ( ( numLidos != 1 ))
		{
			return TST_CondRetParm ;
		} /* if */
			

		CondRet = PLA_novaRodada() ;

		return TST_CompararInt( CondRetEsp ,CondRet , "Condicao de retorno errada.");

	} /* fim ativa: Testar Nova Rodada*/
	else if ( strcmp( ComandoTeste , DESTRUIR_PLACAR_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsp ) ;

            if ( ( numLidos != 1 ))
            {
               return TST_CondRetParm ;
            } /* if */

            PLA_DestruirPlacar();

            return TST_CondRetOK ;

         } /* fim ativa: Testar Destruir placar */



	return TST_CondRetNaoConhec;
}