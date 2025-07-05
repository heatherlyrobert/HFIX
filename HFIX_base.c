#include "HFIX.h"



char        g_print  [LEN_RECD]  = "";
char        g_file   [LEN_HUND]  = "gcc.txt";
char        g_filter   =  'e';
char        g_break  [LEN_FULL]  = "";




char
BASE_pass          (char a_pass)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *f           = NULL;
   char        x_recd      [LEN_RECD]  = "";
   int         l           =    0;
   int         x_count     =    0;
   char        x_file      [LEN_HUND]  = "";
   int         x_line      =    0;
   int         x_col       =    0;
   char        x_type      =  '-';
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
      if      (strncmp (x_recd, "make: *** ["      ,  11) == 0)    rc = MAKE_parse   (x_recd + 11, &x_count, x_file, &x_line, &x_col, &x_type, x_msg, x_flag);
      else if (strncmp (x_recd, "/usr/libexec/gcc/",  16) == 0)    rc = LD_parse     (x_recd     , &x_count, x_file, &x_line, &x_col, &x_type, x_msg, x_flag);
      else if (strncmp (x_recd, "collect"          ,   7) == 0)    rc = MAKE_collect (x_recd     , &x_count, NULL, NULL, NULL, NULL);
      else                                                         rc = GCC_parse    (x_recd     , &x_count, x_file, &x_line, &x_col, &x_type, x_msg, x_flag);
      if (rc < 0)  continue;
      /*> if ((x_count - 1) % 5 == 0)  printf (g_break);                              <*/
      switch (x_type) {
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
            if       (g_filter == 'e' && strchr ("!EeWw"   , x_type) == NULL)  ;
            else if  (g_filter == 'w' && strchr ("!EeWwUu" , x_type) == NULL)  ;
            else     printf ("%s%-2.2s· - %-30.30s %-4.4s %-3.3s (%c) %-60.60s %-40.40s [%c]%s\n", x_on, SHOW_hint (x_count - 1), x_file, x_ln, x_co, x_type, x_msg, x_flag, x_type, x_off);
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

