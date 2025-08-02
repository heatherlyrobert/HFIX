#include "HFIX.h"



/*====================------------------------------------====================*/
/*===----                        debugging setup                       ----===*/
/*====================------------------------------------====================*/
static void      o___DEBUGGING__________o (void) {;}

char
PROG_debugging          (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(initialize)---------------------*/
   yURG_all_mute ();
   rc = yURG_logger  (a_argc, a_argv);
   DEBUG_HFIX  yLOG_value   ("logger"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }

   rc = yURG_urgs    (a_argc, a_argv);
   DEBUG_HFIX  yLOG_value   ("urgs"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit  (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      program startup                         ----===*/
/*====================------------------------------------====================*/
static void      o___STARTUP____________o (void) {;}

char
PROG__init              (int a_argc, char *a_argv[])
{
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(master conf)--------------------*/
   my.m_super    = '-';
   my.m_major    = '-';
   my.m_minor    = '-';
   my.m_phase    = '-';
   strcpy (my.m_desc  , "");
   my.m_theme    = '-';
   my.m_layout   = '-';
   my.m_pass     = '-';
   my.m_export   = '-';
   my.m_set      = '-';
   my.m_unit     = '-';
   /*---(process)------------------------*/
   my.m_rpid     = 0;
   my.m_cnt      = 0;
   my.m_beg      = 0;
   my.m_cur      = 0;
   my.m_end      = 0;
   /*---(context)------------------------*/
   strcpy (my.m_whoami, "");
   strcpy (my.m_ext   , "");
   my.m_done     = '-';
   my.m_status   = '-';
   strcpy (my.m_label , "");
   my.m_result   = '-';
   my.m_error    = '-';
   /*---(overall)------------------------*/
   strcpy (my.m_file  , "");
   strcpy (my.m_filter, "");
   my.m_color    = '-';
   strcpy (my.m_break , "");
   my.m_ylog     = '-';
   strcpy (my.m_data , "");
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit  (__FUNCTION__);
   return 1;
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
   char        x_super     =  '-';
   char        x_major     =  '-';
   char        x_phase     =  '-';
   char        x_data      [LEN_FULL]  = "";
   char        x_unit      =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      a = a_argv [i];
      if (a == NULL) {
         yURG_err ('f', "arg %d is NULL", i);
         DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      ++x_total;
      if (a[0] == '@')  continue;
      DEBUG_HFIX  yLOG_info    ("cli arg", a);
      ++x_args;
      if (i < a_argc - 1)  b = a_argv [i + 1];
      else                 b = NULL;
      /*---(simple)----------------------*/
      if      (strcmp  (a, "--help"         ) == 0)  {  x_super = x_major = '?';  }
      else if (strcmp  (a, "--reset"        ) == 0)  {  x_super = x_major = '!';  }
      else if (strcmp  (a, "--unit"         ) == 0)  {  x_unit  = 'y';  }
      else if (strcmp  (a, "--vim-action"   ) == 0)  {  x_super = x_major = 'a';  strlcpy (x_data, b, LEN_FULL);      }
      /*---(wipe)------------------------*/
      else if (strcmp  (a, "--wipe"         ) == 0)  {  x_super = x_major = 'w';  }
      else if (strcmp  (a, "--WIPE"         ) == 0)  {  x_super = x_major = 'W';  }
      /*---(c-language)------------------*/
      else if (strcmp  (a, "--comp1"        ) == 0)  {  x_super = x_major = 'c';  x_phase = '[';  }
      else if (strcmp  (a, "--comp2"        ) == 0)  {  x_super = x_major = 'c';  x_phase = '>';  }
      else if (strcmp  (a, "--COMP1"        ) == 0)  {  x_super = x_major = 'C';  x_phase = '[';  }
      else if (strcmp  (a, "--COMP2"        ) == 0)  {  x_super = x_major = 'C';  x_phase = '>';  }
      /*---(install)---------------------*/
      else if (strcmp  (a, "--inst"         ) == 0)  {  x_super = x_major = 'i';  }
      else if (strcmp  (a, "--INST"         ) == 0)  {  x_super = x_major = 'I';  }
      /*---(unit-test)-------------------*/
      else if (strcmp  (a, "--unit1"        ) == 0)  {  x_super = x_major = 'u';  x_phase = '[';  }
      else if (strcmp  (a, "--unit2"        ) == 0)  {  x_super = x_major = 'u';  x_phase = '>';  }
      else if (strcmp  (a, "--UNIT1"        ) == 0)  {  x_super = x_major = 'U';  x_phase = '[';  }
      else if (strcmp  (a, "--UNIT2"        ) == 0)  {  x_super = x_major = 'U';  x_phase = '>';  }
      /*---(remove)----------------------*/
      else if (strcmp  (a, "--remv"         ) == 0)  {  x_super = x_major = 'r';  }
      else if (strcmp  (a, "--REMV"         ) == 0)  {  x_super = x_major = 'R';  }
      /*---(manuals)---------------------*/
      else if (strcmp  (a, "--mans"         ) == 0)  {  x_super = x_major = 'm';  }
      else if (strcmp  (a, "--MANS"         ) == 0)  {  x_super = x_major = 'M';  }
      /*---(git-version)-----------------*/
      else if (strcmp  (a, "--gitv1"        ) == 0)  {  x_super = x_major = 'g';  x_phase = '[';  }
      else if (strcmp  (a, "--gitv2"        ) == 0)  {  x_super = x_major = 'g';  x_phase = '>';  }
      else if (strcmp  (a, "--GITV1"        ) == 0)  {  x_super = x_major = 'G';  x_phase = '[';  }
      else if (strcmp  (a, "--GITV2"        ) == 0)  {  x_super = x_major = 'G';  x_phase = '>';  }
      /*---(test/certify)----------------*/
      else if (strcmp  (a, "--test1"        ) == 0)  {  x_super = x_major = 't';  x_phase = '[';  }
      else if (strcmp  (a, "--test2"        ) == 0)  {  x_super = x_major = 't';  x_phase = '>';  }
      else if (strcmp  (a, "--TEST1"        ) == 0)  {  x_super = x_major = 'T';  x_phase = '[';  }
      else if (strcmp  (a, "--TEST2"        ) == 0)  {  x_super = x_major = 'T';  x_phase = '>';  }
      /*---(files)-----------------------*/
      else if (strncmp (a, "--"          , 2) != 0)   strlcpy (my.m_file, a, LEN_FULL);
      /*---(done)------------------------*/
   }
   DEBUG_HFIX  yLOG_value  ("entries"   , x_total);
   DEBUG_HFIX  yLOG_value  ("arguments" , x_args);
   DEBUG_HFIX  yLOG_char   ("x_super"   , x_super);
   DEBUG_HFIX  yLOG_char   ("x_major"   , x_major);
   DEBUG_HFIX  yLOG_char   ("x_phase"   , x_phase);
   if (x_args == 0) {
      DEBUG_HFIX  yLOG_note   ("no arguments identified");
   }
   /*---(save-globally)------------------*/
   my.m_super = x_super;
   my.m_major = x_major;
   my.m_phase = x_phase;
   strlcpy (my.m_data, x_data, LEN_FULL);
   my.m_unit  = x_unit;
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit  (__FUNCTION__);
   return 1;
}

char
PROG__begin             (void)
{
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit  (__FUNCTION__);
   return 1;
}

char
PROG_startup            (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   yURG_stage_check (YURG_BEG);
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(initialize)---------------------*/
   if (rc >= 0) {
      rc = PROG__init    (a_argc, a_argv);
      DEBUG_PROG  yLOG_value   ("init"      , rc);
   }
   /*---(arguments)----------------------*/
   if (rc >= 0) {
      rc = PROG__args    (a_argc, a_argv);
      DEBUG_PROG  yLOG_value   ("args"      , rc);
   }
   /*---(begin)--------------------------*/
   if (rc >= 0) {
      rc = PROG__begin   ();
      DEBUG_PROG  yLOG_value   ("args"      , rc);
   }
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit  (__FUNCTION__);
   yURG_stage_check (YURG_MID);
   return rc;
}



/*====================------------------------------------====================*/
/*===----                      program driver                          ----===*/
/*====================------------------------------------====================*/
static void      o___DRIVER_____________o (void) {;}

char
PROG_handler            (char c_super, char c_unit)
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
      printf ("%s\n", SHOW_title  ('!', '?'));
      break;
   case 'c' : case 'u' :
      DEBUG_HFIX  yLOG_note   ("handling wcu recon");
      rc = ACTS_single (c_super, c_super, my.m_phase);
      DEBUG_HFIX    yLOG_char    ("single"    , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         BASE_result ('R', "RCE", my.m_cnt);
      }
      break;
   case 'C' : case 'U' :
      DEBUG_HFIX  yLOG_note   ("handling WCU make");
      rc = ACTS_single (c_super, c_super, my.m_phase);
      DEBUG_HFIX    yLOG_char    ("single"    , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         BASE_result ('R', "RCE", my.m_cnt);
      }
      break;
   case 'w' :
      DEBUG_HFIX  yLOG_note   ("handling wipe");
      rc = WIPE_pass (c_super, HFIX_WIPE , HFIX_WIPE , '-', c_unit);
      DEBUG_HFIX    yLOG_char    ("recon"     , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         BASE_result ('R', "RCE", my.m_cnt);
      }
      break;
   case 'W' :
      DEBUG_HFIX  yLOG_note   ("handling WIPE");
      rc = WIPE_pass (c_super, HFIX_WIPEF, HFIX_WIPE , '-', c_unit);
      DEBUG_HFIX    yLOG_char    ("recon"     , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         BASE_result ('R', "RCE", my.m_cnt);
      }
      rc = WIPE_pass (c_super, HFIX_WIPEF, HFIX_WIPEF, '-', c_unit);
      DEBUG_HFIX    yLOG_char    ("wipe"      , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_note   ("marking internal error");
         BASE_result ('R', "RCE", my.m_cnt);
      }
      break;
   case 'a' :
      printf ("%s¦", SHOW_title  (my.m_data [0], '?'));
      break;
      /*> case 'c' :                                                                     <* 
       *>    rc = BASE_pass (0, my.m_filter, my.m_color);                                      <* 
       *>    rc = BASE_pass (1, my.m_filter, my.m_color);                                      <* 
       *>    break;                                                                      <*/
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit  (__FUNCTION__);
   return rc;
}



/*====================------------------------------------====================*/
/*===----                        program shutdown                      ----===*/
/*====================------------------------------------====================*/
static void      o___SHUTDOWN___________o (void) {;}

char
PROG__end               (void)
{
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   DEBUG_PROG   yLOGS_end    ();
   return 0;
}

char
PROG_shutdown           (void)
{
   yURG_stage_check (YURG_END);
   return PROG__end ();
}



/*====================------------------------------------====================*/
/*===----                     program pseudo-main                      ----===*/
/*====================------------------------------------====================*/
static void      o___PSEUDO_____________o (void) {;}

char
PROG_psuedo             (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(startup)------------------------*/
   rc = PROG_debugging (a_argc, a_argv);
   DEBUG_HFIX  yLOG_value     ("debugging" , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   rc = PROG_startup   (a_argc, a_argv);
   DEBUG_HFIX  yLOG_value     ("startup"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(run)----------------------------*/
   rc = PROG_handler (my.m_super, my.m_unit);
   DEBUG_HFIX    yLOG_value   ("handler"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(shutdown)-----------------------*/
   rc = PROG_shutdown  ();
   DEBUG_HFIX    yLOG_value   ("shutdown"  , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 0;
}


