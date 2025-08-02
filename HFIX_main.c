#include "HFIX.h"


char
main               (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(run)----------------------------*/
   rc = PROG_psuedo (a_argc, a_argv);
   DEBUG_HFIX  yLOG_value   ("psuedo"    , rc);
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return rc;
}
