#include "HFIX.h"


char
PROG__args              (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   char       *a           = NULL;          /* current argument               */
   char       *b           = NULL;          /* next argument                  */
   int         x_total     =    0;
   int         x_args      =    0;
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      a = a_argv [i];
      if (a == NULL) {
         yURG_err ('f', "arg %d is NULL", i);
         return rce;
      }
      ++x_total;
      if (a[0] == '@')  continue;
      DEBUG_ARGS  yLOG_info    ("cli arg", a);
      ++x_args;
      if (i < a_argc - 1)  b = a_argv [i + 1];
      else                 b = NULL;
      /*---(simple)----------------------*/
      if      (strcmp  (a, "--linker"       ) == 0)   strcpy (g_filter, HFIX_CRITICAL);
      else if (strcmp  (a, "--errors"       ) == 0)   strcpy (g_filter, HFIX_ERRORS);
      else if (strcmp  (a, "--error-only"   ) == 0)   strcpy (g_filter, HFIX_ERROR);
      else if (strcmp  (a, "--warnings"     ) == 0)   strcpy (g_filter, HFIX_WARNINGS);
      else if (strcmp  (a, "--waste-only"   ) == 0)   strcpy (g_filter, HFIX_WASTE);
      else if (strcmp  (a, "--all"          ) == 0)   strcpy (g_filter, HFIX_EVERYTHING);
      else if (strcmp  (a, "--color"        ) == 0)   g_color  = 'y';
      else if (strncmp (a, "--"          , 2) != 0)   strlcpy (g_file, a, LEN_FULL);
   }
   DEBUG_ARGS  yLOG_value  ("entries"   , x_total);
   DEBUG_ARGS  yLOG_value  ("arguments" , x_args);
   if (x_args == 0) {
      DEBUG_ARGS  yLOG_note   ("no arguments identified");
   }
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit  (__FUNCTION__);
   return rc;
}
