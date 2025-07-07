#include "HFIX.h"



char        g_print    [LEN_RECD]  = "";

char        g_file     [LEN_HUND]  = "gcc.txt";
char        g_filter   [LEN_LABEL] = HFIX_ERRORS;
char        g_color    =  '-';
char        g_ylog     =  '-';

char        g_break    [LEN_FULL]  = "";



char
BASE__open              (char a_name [LEN_HUND], short *r_lines, short *r_accept, FILE **r_file)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   FILE       *f           = NULL;
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(default/save)-------------------*/
   if (r_lines  != NULL)   *r_lines  = 0;
   if (r_accept != NULL)   *r_accept = 0;
   /*---(defense)------------------------*/
   DEBUG_PROG  yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name  == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_info    ("a_name"    , a_name);
   --rce;  if (a_name [0] == '\0') {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_point   ("r_file"    , r_file);
   --rce;  if (r_file  == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_point   ("*r_file"   , *r_file);
   --rce;  if (*r_file != NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(open)---------------------------*/
   f = fopen (a_name, "rt");
   DEBUG_PROG  yLOG_point   ("f"         , f);
   --rce;  if (f == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_file  != NULL)  *r_file = f;
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE__close             (FILE **r_file)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_PROG  yLOG_point   ("r_file"    , r_file);
   --rce;  if (r_file  == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_point   ("*r_file"   , *r_file);
   --rce;  if (*r_file == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(close)--------------------------*/
   rc = fclose (*r_file);
   DEBUG_PROG  yLOG_value   ("fclose"    , rc);
   --rce;  if (rc != 0) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(ground)-------------------------*/
   if (r_file  != NULL)  *r_file = NULL;
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE__read              (FILE *f, short *b_lines, short *b_accept, char r_recd [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        rc_final    =    0;
   char        x_recd      [LEN_RECD]  = "";
   short       x_lines     =    0;
   short       x_accept    =    0;
   int         l           =    0;
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(default/save)-------------------*/
   if (b_lines  != NULL)  x_lines  = *b_lines;
   if (b_accept != NULL)  x_accept = *b_accept;
   if (r_recd   != NULL)  strcpy (r_recd, "");
   /*---(defense)------------------------*/
   DEBUG_PROG  yLOG_point   ("f"         , f);
   --rce;  if (f == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce; if (feof (f)) {
      DEBUG_PROG  yLOG_note    ("file already at end-of-file");
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(walk-records)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      fgets (x_recd, LEN_RECD, f);
      if (feof (f)) {
         DEBUG_PROG  yLOG_note    ("file reached end-of-file");
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
      ++x_accept;
      rc_final = 1;
      break;
      /*---(done)------------------------*/
   }
   /*---(save-back)----------------------*/
   if (b_lines  != NULL)  *b_lines  = x_lines;
   if (b_accept != NULL)  *b_accept = x_accept;
   if (r_recd   != NULL)  strlcpy (r_recd, x_recd, LEN_RECD);
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return rc_final;
}

char
BASE__handle            (char c_pass, char c_filter [LEN_LABEL], char c_color, char a_recd [LEN_RECD], short *b_handled, short *b_shown, short *b_hidden, char *r_level, char r_show [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        rc_final    =    0;
   short       x_count     =    0;
   short       x_handled   =    0;
   short       x_shown     =    0;
   short       x_hidden    =    0;
   char        x_recd      [LEN_RECD]  = "";
   char        x_file      [LEN_HUND]  = "";
   char        x_type      =  '-';
   short       x_line      =    0;
   short       x_col       =    0;
   char        x_level     =  '-';
   char        x_msg       [LEN_RECD]  = "";
   char        x_flag      [LEN_HUND]  = "";
   char        x_on        [LEN_TERSE] = "";
   char        x_off       [LEN_TERSE] = "";
   char        x_ln        [LEN_TERSE] = "";
   char        x_co        [LEN_TERSE] = "";
   char        x_show      [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(default/save)-------------------*/
   if (b_handled != NULL)  x_handled = *b_handled;
   if (b_shown   != NULL)  x_shown   = *b_shown;
   if (b_hidden  != NULL)  x_hidden  = *b_hidden;
   if (r_level   != NULL)  *r_level  = '-';
   if (r_show    != NULL)  strcpy (r_show, "");
   /*---(defense)------------------------*/
   DEBUG_PROG  yLOG_point   ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_info    ("a_recd"    , a_recd);
   strlcpy (x_recd, a_recd, LEN_RECD);
   /*---(handle)-------------------------*/
   if      (strncmp (x_recd, "make:"      ,   5) == 0)    rc = MAKE_parse   (x_recd, &x_count, x_file, &x_type, &x_line, &x_col, &x_level, x_msg, x_flag);
   else if (strncmp (x_recd, "make["      ,   5) == 0)    rc = MAKE_parse   (x_recd, &x_count, x_file, &x_type, &x_line, &x_col, &x_level, x_msg, x_flag);
   else if (strncmp (x_recd, "/usr/libexec/gcc/",  16) == 0)    rc = LD_parse     (x_recd, &x_count, x_file, &x_type, &x_line, &x_col, &x_level, x_msg, x_flag);
   /*> else if (strncmp (x_recd, "collect"          ,   7) == 0)    rc = MAKE_collect (x_recd     , &x_count, NULL, NULL, NULL, NULL);   <*/
   else                                                         rc = GCC_parse    (x_recd, &x_count, x_file, &x_type, &x_line, &x_col, &x_level, x_msg, x_flag);
   /*---(trouble)------------------------*/
   DEBUG_PROG  yLOG_value   ("return"    , rc);
   if (rc <= 0) {
      DEBUG_PROG  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(success)------------------------*/
   ++x_handled;
   DEBUG_PROG  yLOG_char    ("c_color"   , c_color);
   if (c_color == 'y') {
      switch (x_level) {
      case '!' :   strcpy (x_on, BOLD_CRI);   break;
      case 'E' :   strcpy (x_on, BOLD_RED);   break;
      case 'e' :   strcpy (x_on, BOLD_ORA);   break;
      case 'W' :   strcpy (x_on, BOLD_YEL);   break;
      case 'w' :   strcpy (x_on, BOLD_PUR);   break;
      case 'U' :   strcpy (x_on, BOLD_BLU);   break;
      case 'u' :   strcpy (x_on, BOLD_BRN);   break;
      case 'm' :   strcpy (x_on, BOLD_OFF);   break;
      }
      strcpy (x_off, BOLD_OFF);
   }
   /*---(classify)-----------------------*/
   DEBUG_PROG  yLOG_info    ("c_filter"  , c_filter);
   DEBUG_PROG  yLOG_value   ("c_pass"    , c_pass);
   if      (strchr (c_filter  , x_level) == NULL)  {  ++x_hidden;  }
   else if (c_pass == 0)                           {  ++x_shown;   }
   else                                            {  ++x_shown;  rc_final = 1; }
   /*---(show)---------------------------*/
   if (rc_final == 1) {
      SHOW_num (x_line, 4, x_ln);
      DEBUG_PROG  yLOG_info    ("x_ln"      , x_ln);
      SHOW_num (x_col , 3, x_co);
      DEBUG_PROG  yLOG_info    ("x_co"      , x_co);
      sprintf (x_show, "%s%-2.2s· - %c  %-30.30s %-4.4s %-3.3s %c   %-60.60s %-40.40s [%c]%s", x_on, SHOW_hint (x_shown - 1), x_type, x_file, x_ln, x_co, x_level, x_msg, x_flag, x_level, x_off);
      /*> sprintf (x_show, "%s%-2.2s· - %c  %-30.30s %4d %3d %c   %-60.60s %-40.40s [%c]%s", x_on, SHOW_hint (x_shown - 1), x_type, x_file, x_line, x_col, x_level, x_msg, x_flag, x_level, x_off);   <*/
   }
   DEBUG_PROG  yLOG_value   ("rc_final"  , rc_final);
   /*---(save-back)----------------------*/
   if (b_handled != NULL)  *b_handled = x_handled;
   if (b_shown   != NULL)  *b_shown   = x_shown;
   if (b_hidden  != NULL)  *b_hidden  = x_hidden;
   if (r_level   != NULL)  *r_level   = x_level;
   if (r_show    != NULL)  strlcpy (r_show, x_show, LEN_FULL);
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return rc_final;
}

char
BASE_pass               (char c_pass, char c_filter [LEN_LABEL], char c_color)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *f           = NULL;
   char        x_recd      [LEN_RECD]  = "";
   short       x_total     =    0;
   short       x_accept    =    0;
   short       x_handled   =    0;
   short       x_shown     =    0;
   short       x_hidden    =    0;
   char        x_level     =  '-';
   char        x_show      [LEN_FULL]  = "";
   int         x_fail      =    0;
   int         x_errs      =    0;
   int         x_warn      =    0;
   int         x_waste     =    0;
   int         x_msgs      =    0;
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(open)---------------------------*/
   rc = BASE__open (g_file, &x_total, &x_accept, &f);
   DEBUG_PROG  yLOG_value   ("open"      , rc);
   DEBUG_PROG  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle lines)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      rc = BASE__read (f, &x_total, &x_accept, x_recd);
      DEBUG_PROG  yLOG_value   ("read"      , rc);
      if (rc == 0)   break;
      /*---(handle)----------------------*/
      rc = BASE__handle (c_pass, c_filter, c_color, x_recd, &x_handled, &x_shown, &x_hidden, &x_level, x_show);
      DEBUG_PROG  yLOG_value   ("handle"    , rc);
      if (rc == 1)  printf ("%s\n", x_show);
      /*---(statistics)------------------*/
      DEBUG_PROG  yLOG_char    ("level"     , x_level);
      switch (x_level) {
      case '!' :            ++x_fail;   break;
      case 'E' : case 'e' : ++x_errs;   break;
      case 'W' : case 'w' : ++x_warn;   break;
      case 'U' : case 'u' : ++x_waste;  break;
      case 'm' :            ++x_msgs;   break;
      }
      /*---(done)------------------------*/
   }
   /*---(close)--------------------------*/
   rc = BASE__close (&f);
   DEBUG_PROG  yLOG_value   ("close"     , rc);
   DEBUG_PROG  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f != NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(totals)-------------------------*/
   printf ("%s\n", SHOW_totals (c_pass, c_color, x_shown, x_fail, x_errs, x_warn, x_waste, 0, x_total));
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 0;
}

