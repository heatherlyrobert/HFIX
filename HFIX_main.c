#include "HFIX.h"


char
main               (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(startup)------------------------*/
   rc = PROG__args (a_argc, a_argv);
   DEBUG_PROG  yLOG_value   ("args"      , rc);
   /*---(run)----------------------------*/
   rc = BASE_pass (0, g_filter, g_color);
   DEBUG_PROG  yLOG_value   ("header (0)", rc);
   rc = BASE_pass (1, g_filter, g_color);
   DEBUG_PROG  yLOG_value   ("detail (1)", rc);
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 0;
}
