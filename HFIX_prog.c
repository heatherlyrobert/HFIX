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
      if      (strcmp  (a, "--help"         ) == 0)  {  g_super = '?';  }
      else if (strcmp  (a, "--reset"        ) == 0)  {  g_super = '!';  }
      else if (strcmp  (a, "--vim-action"   ) == 0)  {  g_super = 'a';  strlcpy (g_data, b, LEN_FULL);      }
      /*> if      (strcmp  (a, "--criticals"    ) == 0)  { g_super = 'c';  strcpy (g_filter, HFIX_CRITICAL);   }   <* 
       *> else if (strcmp  (a, "--errors"       ) == 0)  { g_super = 'c';  strcpy (g_filter, HFIX_ERRORS);     }   <* 
       *> else if (strcmp  (a, "--error-only"   ) == 0)  { g_super = 'c';  strcpy (g_filter, HFIX_ERROR);      }   <* 
       *> else if (strcmp  (a, "--warnings"     ) == 0)  { g_super = 'c';  strcpy (g_filter, HFIX_WARNINGS);   }   <* 
       *> else if (strcmp  (a, "--waste-only"   ) == 0)  { g_super = 'c';  strcpy (g_filter, HFIX_WASTE);      }   <* 
       *> else if (strcmp  (a, "--all"          ) == 0)  { g_super = 'c';  strcpy (g_filter, HFIX_EVERYTHING); }   <* 
       *> else if (strcmp  (a, "--color"        ) == 0)    g_color  = 'y';                                          <* 
       *> else if (strcmp  (a, "--ylog"         ) == 0)    g_ylog   = 'y';                                          <*/
      /*---(wipe)------------------------*/
      else if (strcmp  (a, "--wipe"         ) == 0)  {  g_super = 'w';  }
      else if (strcmp  (a, "--WIPE"         ) == 0)  {  g_super = 'W';  }
      /*---(install)---------------------*/
      else if (strcmp  (a, "--inst"         ) == 0)  {  g_super = 'i';  }
      else if (strcmp  (a, "--INSTT"        ) == 0)  {  g_super = 'I';  }
      /*---(c-language)------------------*/
      else if (strcmp  (a, "--c_reco_beg"   ) == 0)  {  g_super = 'c';  g_phase = '[';  }
      else if (strcmp  (a, "--c_reco_chk"   ) == 0)  {  g_super = 'c';  g_phase = '>';  }
      else if (strcmp  (a, "--c_make_beg"   ) == 0)  {  g_super = 'C';  g_phase = '[';  }
      else if (strcmp  (a, "--c_make_chk"   ) == 0)  {  g_super = 'C';  g_phase = '>';  }
      /*---(unit-test)-------------------*/
      else if (strcmp  (a, "--u_reco_beg"   ) == 0)  {  g_super = 'u';  g_phase = '[';  }
      else if (strcmp  (a, "--u_reco_chk"   ) == 0)  {  g_super = 'u';  g_phase = '>';  }
      else if (strcmp  (a, "--u_make_beg"   ) == 0)  {  g_super = 'U';  g_phase = '[';  }
      else if (strcmp  (a, "--u_make_chk"   ) == 0)  {  g_super = 'U';  g_phase = '>';  }
      /*---(files)-----------------------*/
      else if (strncmp (a, "--"          , 2) != 0)   strlcpy (g_file, a, LEN_FULL);
      /*---(done)------------------------*/
   }
   DEBUG_HFIX  yLOG_value  ("entries"   , x_total);
   DEBUG_HFIX  yLOG_value  ("arguments" , x_args);
   DEBUG_HFIX  yLOG_char   ("g_super"   , g_super);
   DEBUG_HFIX  yLOG_char   ("g_phase"   , g_phase);
   if (x_args == 0) {
      DEBUG_HFIX  yLOG_note   ("no arguments identified");
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit  (__FUNCTION__);
   return rc;
}

char
PROG_handler            (char c_super)
{
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(select handler)-----------------*/
   DEBUG_HFIX    yLOG_char    ("c_super"   , c_super);
   switch (c_super) {
   case '?' :
      DEBUG_HFIX  yLOG_note   ("handling ? help");
      rc = SHOW_vim_help ();
      break;
   case '!' :
      DEBUG_HFIX  yLOG_note   ("handling ! reset");
      printf ("%s\n", SHOW_action ('!', '?'));
      break;
   case 'c' : case 'u' :
      DEBUG_HFIX  yLOG_note   ("handling wcu recon");
      rc = ACTS_single (c_super, c_super, g_phase);
      DEBUG_HFIX    yLOG_char    ("single"    , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         COMP__mark_done ('R', "RCE", s_cnt);
      }
      break;
   case 'C' : case 'U' :
      DEBUG_HFIX  yLOG_note   ("handling WCU make");
      rc = ACTS_single (c_super, c_super, g_phase);
      DEBUG_HFIX    yLOG_char    ("single"    , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         COMP__mark_done ('R', "RCE", s_cnt);
      }
      break;
   case 'w' :  case 'i' :
      DEBUG_HFIX  yLOG_note   ("handling recon");
      rc = WIPE_pass (c_super, 'r', '-');
      DEBUG_HFIX    yLOG_char    ("recon"     , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         COMP__mark_done ('R', "RCE", s_cnt);
      }
      break;
   case 'W' :
      DEBUG_HFIX  yLOG_note   ("handling WIPE");
      rc = WIPE_pass (c_super, 'r', '-');
      DEBUG_HFIX    yLOG_char    ("recon"     , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         COMP__mark_done ('R', "RCE", s_cnt);
      }
      rc = WIPE_pass (c_super, 'w', '-');
      DEBUG_HFIX    yLOG_char    ("wipe"      , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         COMP__mark_done ('R', "RCE", s_cnt);
      }
      break;
   case 'a' :
      printf ("%s\n", SHOW_action (g_data [0], '?'));
      break;
      /*> case 'c' :                                                                     <* 
       *>    rc = BASE_pass (0, g_filter, g_color);                                      <* 
       *>    rc = BASE_pass (1, g_filter, g_color);                                      <* 
       *>    break;                                                                      <*/
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit  (__FUNCTION__);
   return rc;
}
