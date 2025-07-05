#include "HFIX.h"



char        g_print    [LEN_RECD]  = "";
char        g_file     [LEN_HUND]  = "gcc.txt";
char        g_filter   =  'E';
char        g_break    [LEN_FULL]  = "";

char
BASE__read              (FILE *f, short *b_lines, char r_recd [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        rc_final    =    0;
   char        x_recd      [LEN_RECD]  = "";
   short       x_lines     =    0;
   int         l           =    0;
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(default/save)-------------------*/
   if (b_lines != NULL)  x_lines = *b_lines;
   if (r_recd  != NULL)  strcpy (r_recd, "");
   /*---(defense)------------------------*/
   DEBUG_PROG  yLOG_point   ("f"         , f);
   --rce;  if (f == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(walk-records)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      fgets (x_recd, LEN_RECD, f);
      if (feof (f)) {
         DEBUG_PROG  yLOG_note    ("end-of-file");
         rc_final = 0;
         break;
      }
      ++x_lines;
      /*---(fix)-------------------------*/
      l = strlen (x_recd);
      if (l > 0 && x_recd [l - 1] == '\n')  x_recd [--l] = '\0';
      DEBUG_PROG  yLOG_complex ("x_recd"    , "%3då%sæ", l, x_recd);
      /*---(filter)----------------------*/
      if (l < 10) {
         DEBUG_PROG  yLOG_note    ("too short");
         continue;
      }
      if (x_recd [0] == ' ') {
         DEBUG_PROG  yLOG_note    ("starts with space");
         continue;
      }
      /*---(accept)----------------------*/
      rc_final = 1;
      /*---(done)------------------------*/
   }
   /*---(save-back)----------------------*/
   if (b_lines != NULL)  *b_lines = x_lines;
   if (r_recd  != NULL)  strcpy (r_recd, "");
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return rc_final;
}



char
BASE_pass          (char a_pass)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *f           = NULL;
   char        x_recd      [LEN_RECD]  = "";
   int         l           =    0;
   short       x_count     =    0;
   char        x_file      [LEN_HUND]  = "";
   char        x_type      =  '-';
   short       x_line      =    0;
   short       x_col       =    0;
   char        x_level     =  '-';
   char        x_msg       [LEN_RECD]  = "";
   char        x_flag      [LEN_HUND]  = "";
   int         x_total     =    0;
   int         x_fail      =    0;
   int         x_errs      =    0;
   int         x_warn      =    0;
   int         x_waste     =    0;
   int         x_msgs      =    0;
   char        x_on        [LEN_TERSE] = "";
   char        x_off       [LEN_TERSE] = "";
   char        x_ln        [LEN_TERSE] = "";
   char        x_co        [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   f = fopen (g_file, "rt");
   --rce;  if (f == NULL)  return rce;
   while (1) {
      fgets (x_recd, LEN_RECD, f);
      if (feof (f))  break;
      ++x_total;
      l = strlen (x_recd);
      if (l > 0 && x_recd [l - 1] == '\n')  x_recd [--l] = '\0';
      x_type = '-';
      if      (strncmp (x_recd, "make: *** ["      ,  11) == 0)    rc = MAKE_parse   (x_recd + 11, &x_count, x_file, &x_line, &x_col, &x_level, x_msg, x_flag);
      else if (strncmp (x_recd, "/usr/libexec/gcc/",  16) == 0)    rc = LD_parse     (x_recd     , &x_count, x_file, &x_line, &x_col, &x_level, x_msg, x_flag);
      else if (strncmp (x_recd, "collect"          ,   7) == 0)    rc = MAKE_collect (x_recd     , &x_count, NULL, NULL, NULL, NULL);
      else                                                         rc = GCC_parse    (x_recd     , &x_count, x_file, &x_type, &x_line, &x_col, &x_level, x_msg, x_flag);
      if (rc < 0)  continue;
      /*> if ((x_count - 1) % 5 == 0)  printf (g_break);                              <*/
      switch (x_level) {
      case '!' :            ++x_fail; /*  strcpy (x_on, BOLD_CRI); */ break;
      case 'E' : case 'e' : ++x_errs; /*  strcpy (x_on, BOLD_RED); */ break;
      case 'W' : case 'w' : ++x_warn; /*  strcpy (x_on, BOLD_YEL); */ break;
      case 'U' : case 'u' : ++x_waste;/*  strcpy (x_on, BOLD_BLU); */ break;
      case 'm' :            ++x_msgs; /*  strcpy (x_on, BOLD_OFF); */ break;
      }
      /*> strcpy (x_off, BOLD_OFF);                                                   <*/
      SHOW_num (x_line, 4, x_ln);
      SHOW_num (x_col , 3, x_co);
      if (a_pass == 1) {
         if (rc > 0) {
            if       (g_filter == 'e' && strchr ("!EeWw"   , x_level) == NULL)  ;
            else if  (g_filter == 'w' && strchr ("!EeWwUu" , x_level) == NULL)  ;
            else     printf ("%s%-2.2s· - %-30.30s %c %-4.4s %-3.3s (%c) %-60.60s %-40.40s [%c]%s\n", x_on, SHOW_hint (x_count - 1), x_file, x_type, x_ln, x_co, x_level, x_msg, x_flag, x_level, x_off);
         }
      }
   }
   rc = fclose (f);
   f = NULL;
   printf ("%s\n", SHOW_totals (a_pass, x_count, x_fail, x_errs, x_warn, x_waste, 0, x_total));
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 0;
}

