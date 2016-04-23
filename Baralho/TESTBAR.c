/***************************************************************************
*  $MCI Módulo de implementação: TBAR Teste baralho
*
*  Arquivo gerado:              TESTBAR.c
*  Letras identificadoras:      TBAR
*
*  Nome da base de software:    -
*  Arquivo da base de software: -
*
*  Projeto: INF 1301 / 1628 Truco
*  Gestor:  -
*  Autores: Matheus³
*
*  $HA Histórico de evolução:
*     Versão  Autor    		Data     		Observações 
*     1       Matheus³   21/abr/2016 	início desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include "BARALHO.h"

static const char CRIAR_BARALHO_CMD[] = "=criarbaralho";
static const char DESTRUIR_BARALHO_CMD[] = "=destruirbaralho";


#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

Baralho BaralhoDeCartas;


	 TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
		int inxLista  = -1 ,
			numLidos   = -1 ,
			validaBaralho = FALSE;			/*variavel para saber se o baralho pode */

      
      
   
		/* Testar CriarBaralho */
   
		 if ( strcmp( ComandoTeste , CRIAR_BARALHO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros("") ;
            if ( ( numLidos != 0 )			/*se o numero de parametros nao e zero ou caso a valida baralho seja TRUE*/
              || validaBaralho==TRUE)
            {
               return TST_CondRetParm ;
            } /* if */

            BaralhoDeCartas	 =  BAR_CriarBaralho() ;

			validaBaralho =  TRUE;		//???
			
            return TST_CompararPonteiroNulo( 1 , BaralhoDeCartas ,
               "Erro em ponteiro de novo baralho\n."  ) ;

         } /* fim ativa: Testar CriarLista */
		

		 /* Testar DestruirBaralho */

		 else if ( strcmp( ComandoTeste , DESTRUIR_BARALHO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros("") ;

            if ( ( numLidos != 0 )
              || (!validaBaralho))       //??????
            {
               return TST_CondRetParm ;
            } /* if */

            BAR_DestruirBaralho(BaralhoDeCartas) ;
            BaralhoDeCartas = NULL ;


            return TST_CondRetOK ;

         } /* fim ativa: Testar Destruir baralho */
	}	 
		 

	 // Testando aqui.