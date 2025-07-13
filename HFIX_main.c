#include "HFIX.h"


char
main               (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(startup)------------------------*/
   rc = PROG__urgs (a_argc, a_argv);
   rc = PROG__args (a_argc, a_argv);
   DEBUG_HFIX  yLOG_value   ("args"      , rc);
   /*---(run)----------------------------*/
   rc = PROG_handler (g_action);
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 0;
}
