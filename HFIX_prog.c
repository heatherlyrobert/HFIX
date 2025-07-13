#include "HFIX.h"


char
PROG__urgs              (int argc, char *argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   /*---(initialize)---------------------*/
   rc = yURG_logger  (argc, argv);
   rc = yURG_urgs    (argc, argv);
   return 0;
}

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
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      a = a_argv [i];
      if (a == NULL) {
         yURG_err ('f', "arg %d is NULL", i);
         return rce;
      }
      ++x_total;
      if (a[0] == '@')  continue;
      DEBUG_HFIX  yLOG_info    ("cli arg", a);
      ++x_args;
      if (i < a_argc - 1)  b = a_argv [i + 1];
      else                 b = NULL;
      /*---(simple)----------------------*/
      if      (strcmp  (a, "--criticals"    ) == 0)  { g_action = 'c';  strcpy (g_filter, HFIX_CRITICAL);   }
      else if (strcmp  (a, "--errors"       ) == 0)  { g_action = 'c';  strcpy (g_filter, HFIX_ERRORS);     }
      else if (strcmp  (a, "--error-only"   ) == 0)  { g_action = 'c';  strcpy (g_filter, HFIX_ERROR);      }
      else if (strcmp  (a, "--warnings"     ) == 0)  { g_action = 'c';  strcpy (g_filter, HFIX_WARNINGS);   }
      else if (strcmp  (a, "--waste-only"   ) == 0)  { g_action = 'c';  strcpy (g_filter, HFIX_WASTE);      }
      else if (strcmp  (a, "--all"          ) == 0)  { g_action = 'c';  strcpy (g_filter, HFIX_EVERYTHING); }
      else if (strcmp  (a, "--color"        ) == 0)    g_color  = 'y';
      else if (strcmp  (a, "--ylog"         ) == 0)    g_ylog   = 'y';
      else if (strcmp  (a, "--vim-help"     ) == 0)    g_action = '?';
      else if (strcmp  (a, "--vim-action"   ) == 0)  { g_action = 'a';  strlcpy (g_data, b, LEN_FULL);      }
      else if (strcmp  (a, "--vim-simple"   ) == 0)  { g_action = 's'; }
      else if (strcmp  (a, "--clean"        ) == 0)  { g_action = 'w'; }
      else if (strcmp  (a, "--c_recon_beg"  ) == 0)  { g_action = 'r'; g_phase = '[';  }
      else if (strcmp  (a, "--c_recon_chk"  ) == 0)  { g_action = 'r'; g_phase = '>';  }
      else if (strncmp (a, "--"          , 2) != 0)   strlcpy (g_file, a, LEN_FULL);
   }
   DEBUG_HFIX  yLOG_value  ("entries"   , x_total);
   DEBUG_HFIX  yLOG_value  ("arguments" , x_args);
   if (x_args == 0) {
      DEBUG_HFIX  yLOG_note   ("no arguments identified");
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit  (__FUNCTION__);
   return rc;
}

char
PROG_handler            (char a_action)
{
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(select handler)-----------------*/
   switch (a_action) {
   case '?' :
      rc = SHOW_vim_help ();
      break;
   case 'a' :
      rc = SHOW_vim_action (g_data);
      break;
   case 's' :
      rc = SHOW_vim_simple ();
      break;
   case 'r' :
      rc = COMP_c_recon  (g_phase);
      break;
   case 'w' :
      /*> rc = COMP_clean    (0);                                                     <*/
      break;
   case 'c' :
      rc = BASE_pass (0, g_filter, g_color);
      rc = BASE_pass (1, g_filter, g_color);
      break;
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit  (__FUNCTION__);
   return rc;
}
