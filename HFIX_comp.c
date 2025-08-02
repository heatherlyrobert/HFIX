#include "HFIX.h"

/*
 * assumptions (of which i am completely in love with)
 *
 * -- all c-source named "project_file.c" -- exact same project as above
 * -- maximum source file name (w/o extension) is 18 characters
 *
 * -- project names are [A-Za-z0-9].*  no more than 10 characters long
 * -- very long project names (for me) polymnia (8), hephaestus (10)
 * -- programming directories are named "project.description"
 * -- programming directories are under "/home/system/"    (my stuff)
 * -- programming directories are under "/home/keepsake/"  (external keepers)
 *
 * -- file names are [A-Za-z0-9_].*  no more than 10 characters long
 * -- long file names (for me) 1prepare (8), gather (6), ySCORE (6)
 *
 * -- always use GNU/linux, GNU/gcc and GNU/make (don't need cool, need solid)
 * -- c-language is real programming (asm also), i support nothing else
 * -- koios (unit testing) produces c-language test files
 *
 */



char    s_compile     [MAX_ENTRY][LEN_DESC];
char    s_ncount      =   0;



char
COMP__base              (void)
{
   /*---(locals)-----------+-----+-----+-*/
   int         rc          =    0;
   char        rce         =  -10;
   DIR        *x_dir       = NULL;
   tDIRENT    *x_file      = NULL;
   char        x_name      [LEN_TITLE] = "";
   char        x_bit       [LEN_LABEL] = "";
   int         lb          =    0;
   int         le          =    0;
   int         l           =    0;
   char        x_full      [LEN_TITLE] = "";
   char        x_total     =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(quick_out)----------------------*/
   rc = s_compile [MAX_ENTRY - 1][8];
   DEBUG_HFIX   yLOG_char    ("count"      , rc);
   --rce;  if (rc != '-') {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(defense)------------------------*/
   DEBUG_HFIX   yLOG_info    ("my.m_whoami"   , my.m_whoami);
   lb = strlen (my.m_whoami);
   DEBUG_HFIX   yLOG_value   ("lb"         , lb);
   --rce;  if (lb     <= 3) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_info    ("my.m_ext"      , my.m_ext);
   le = strlen (my.m_ext);
   DEBUG_HFIX   yLOG_value   ("le"         , le);
   --rce;  if (le     <= 1) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(open dir)-----------------------*/
   x_dir = opendir(".");
   DEBUG_HFIX   yLOG_point   ("x_dir"      , x_dir);
   --rce;  if (x_dir == NULL) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_note    ("openned successfully");
   /*---(process entries)----------------*/
   DEBUG_HFIX   yLOG_note    ("processing entries");
   while (1) {
      /*---(read a directory entry)------*/
      x_file = readdir (x_dir);
      DEBUG_HFIX   yLOG_point   ("x_file"    , x_file);
      if (x_file == NULL)  break;
      ++x_total;
      /*---(filter by name)--------------*/
      strlcpy (x_name, x_file->d_name, LEN_TITLE);
      DEBUG_HFIX   yLOG_info    ("x_name"    , x_name);
      l = strlen (x_name);
      strlcpy (x_bit, x_name, lb + 1);
      DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
      if (strcmp (x_bit, my.m_whoami) != 0) {
         DEBUG_HFIX   yLOG_note    ("skipping, wrong base");
         continue;
      }
      strcpy (x_bit, x_name + l - le);
      DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
      if (strcmp (x_bit, my.m_ext) != 0) {
         DEBUG_HFIX   yLOG_note    ("skipping, wrong extention");
         continue;
      }
      x_name [l - le] = '\0';
      l = strlen (x_name);
      if (l > 5 && strcmp (x_name + l - 5, "_unit") == 0) {
         DEBUG_HFIX   yLOG_note    ("skipping, unit c file");
         continue;
      }
      /*---(place)-----------------------*/
      rc = BASE_entry ('c', s_ncount, x_name);
      DEBUG_HFIX   yLOG_value   ("entry"     , rc);
      ++s_ncount;
      /*---(done)------------------------*/
   }
   DEBUG_HFIX   yLOG_value   ("x_total"   , x_total);
   DEBUG_HFIX   yLOG_value   ("s_ncount"  , s_ncount);
   /*---(close dir)----------------------*/
   DEBUG_HFIX   yLOG_note    ("closing directory");
   rc = closedir (x_dir);
   DEBUG_HFIX   yLOG_value   ("close_rc"  , rc);
   /*---(sort-it)------------------------*/
   HFIX_sort ();
   /*---(update total)-------------------*/
   BASE_total ('t', s_ncount);
   /*> sprintf (x_bit, "%2d", s_ncount);                                              <* 
    *> if (x_bit [0] == ' ')  x_bit [0] = '·';                                        <* 
    *> if (x_bit [1] == ' ')  x_bit [1] = '·';                                        <* 
    *> if (s_ncount == 0)     x_bit [1] = '/';                                        <* 
    *> s_compile [MAX_ENTRY - 1][ 7] = x_bit [0];                                     <* 
    *> s_compile [MAX_ENTRY - 1][ 8] = x_bit [1];                                     <* 
    *> s_compile [MAX_ENTRY - 1][ 9] = 't';                                           <*/
   /*---(complete)------------------------------*/
   DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
   return s_ncount;
}

char
COMP__beg               (void)
{
   char        rc          =    0;
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   rc = yENV_rm  (HFIX_LOG);
   DEBUG_HFIX    yLOG_char    ("HFIX_LOG"  , rc);
   rc = yENV_rm  (HFIX_OUT);
   DEBUG_HFIX    yLOG_char    ("HFIX_OUT"  , rc);
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
COMP__chk               (void)
{
   char        rc          =    0;
   int         c           =    0;
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   rc = yENV_exists (HFIX_LOG);
   DEBUG_HFIX    yLOG_char    ("HFIX_LOG"  , rc);
   c  = yENV_lines  (HFIX_LOG);
   DEBUG_HFIX    yLOG_value   ("log lines" , c);
   rc = yENV_exists (HFIX_OUT);
   DEBUG_HFIX    yLOG_char    ("HFIX_OUT"  , rc);
   c  = yENV_lines  (HFIX_OUT);
   DEBUG_HFIX    yLOG_value   ("out lines" , c);
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
COMP_c_make             (char c_type, char c_phase)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_label     [LEN_LABEL] = "";
   char        rc_final    =    0;
   char        rc_num      =    1;
   int         i           =    0;
   char        x_bit       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX    yLOG_char    ("c_type"    , c_type);
   --rce;  if (c_type == 0 || strchr ("rcRC", c_type) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (c_phase == HFIX_BEG) {
      /*---(prepare buf)-----------------*/
      DEBUG_HFIX    yLOG_note    ("c recon/make request/fork");
      rc = COMP__beg ();
      rc = BASE_clear (my.m_desc);
      DEBUG_HFIX    yLOG_value   ("clear"     , rc);
      rc = COMP__base  ();
      DEBUG_HFIX    yLOG_value   ("base"      , rc);
      /*---(run make)--------------------*/
      my.m_beg  = my.m_cur  = time (NULL);
      DEBUG_HFIX    yLOG_value   ("my.m_beg"     , my.m_beg);
      switch (c_type) {
      case 'r'  :  my.m_rpid = yexec_ufork ("/bin/bash -c HFIX_reconc");  break;
      case 'c'  :  my.m_rpid = yexec_ufork ("/bin/bash -c HFIX_make");    break;
      }
      DEBUG_HFIX    yLOG_value   ("ufork"     , my.m_rpid);
      /*---(default check)---------------*/
      rc_final = HFIX_CHK;
      strcpy (x_label, "launched");
      /*---(done)------------------------*/
   } else if (c_phase == HFIX_CHK) {
      DEBUG_HFIX    yLOG_note    ("c recon/make update/wait");
      rc = EXIM_import ("");
      DEBUG_HFIX    yLOG_value   ("import"    , rc);
      DEBUG_HFIX    yLOG_value   ("my.m_rpid"    , my.m_rpid);
      if (my.m_rpid > 0) {
         usleep (500000);
         my.m_cur  = time (NULL);
         COMP__chk ();
         DEBUG_HFIX    yLOG_value   ("my.m_cur"     , my.m_cur);
         rc_final = yexec_uwait (my.m_rpid, x_label);
         DEBUG_HFIX    yLOG_char    ("uwait"     , rc_final);
         ACTS__progress ('1');
         /*> ++my.m_cnt;                                                                 <*/
      }
   } else {
      DEBUG_HFIX    yLOG_note    ("unknown request");
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_value   ("my.m_cnt"     , my.m_cnt);
   /*---(check status)--------------------------*/
   if (my.m_rpid > 0) {
      switch (rc_final) {
      case HFIX_CHK :  case 'r' :
         rc_num = 0;
         break;
      case '#' :
         strcpy (x_label, "DONE");
      default  :
         my.m_rpid = 0;
         my.m_done = 'Y';
         BASE_finishing ();
         break;
      }
      /*---(update elapsed)---------------------*/
      rc = BASE_result (rc_final, x_label, my.m_cur - my.m_beg);
      DEBUG_HFIX    yLOG_value   ("result"    , rc);
      /*> sprintf (x_bit, "  %c %-8.8s %4d  ", rc_final, x_label, my.m_cur - my.m_beg);     <* 
       *> for (i = 0; i < 18; ++i) s_compile [MAX_ENTRY - 2][4 + i] = x_bit [i];      <*/
      /*---(done)-------------------------------*/
   }
   /*---(show results)--------------------------*/
   rc = EXIM_export     ('r', 'p', "");
   DEBUG_HFIX    yLOG_value   ("export"    , rc);
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return rc_num;
}

char
COMP_c_compile          (char a_phase)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_label     [LEN_LABEL] = "";
   char        rc_final    =    0;
   char        rc_num      =    1;
   int         i           =    0;
   char        x_bit       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   if (a_phase == HFIX_BEG) {
      DEBUG_HFIX    yLOG_note    ("c compile request/fork");
      rc = COMP__beg ();
      my.m_beg  = my.m_cur  = time (NULL);
      DEBUG_HFIX    yLOG_value   ("my.m_beg"     , my.m_beg);
      my.m_rpid = yexec_ufork ("/bin/bash -c HFIX_make");
      DEBUG_HFIX    yLOG_value   ("ufork"     , my.m_rpid);
      rc_final = yexec_uwait (my.m_rpid, x_label);
      DEBUG_HFIX    yLOG_char    ("uwait"     , rc_final);
      COMP__chk ();
      rc_final = HFIX_CHK;
      strcpy (x_label, "launched");
   } else if (a_phase == HFIX_CHK) {
      DEBUG_HFIX    yLOG_note    ("c recon update/wait");
      rc = EXIM_import ("");
      DEBUG_HFIX    yLOG_value   ("import"    , rc);
      DEBUG_HFIX    yLOG_value   ("my.m_rpid"    , my.m_rpid);
      if (my.m_rpid > 0) {
         usleep (500000);
         my.m_cur  = time (NULL);
         COMP__chk ();
         DEBUG_HFIX    yLOG_value   ("my.m_cur"     , my.m_cur);
         rc_final = yexec_uwait (my.m_rpid, x_label);
         DEBUG_HFIX    yLOG_char    ("uwait"     , rc_final);
         ACTS__progress ('2');
         /*> ++my.m_cnt;                                                                 <*/
      }
   } else {
      DEBUG_HFIX    yLOG_note    ("unknown request");
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_value   ("my.m_cnt"     , my.m_cnt);
   /*---(check status)--------------------------*/
   if (my.m_rpid > 0) {
      switch (rc_final) {
      case HFIX_CHK :  case 'r' :
         rc_num = 0;
         break;
      case '#' :
         strcpy (x_label, "DONE");
      default  :
         my.m_rpid = 0;
         my.m_done = 'Y';
         BASE_finishing ();
         break;
      }
      /*---(update elapsed)---------------------*/
      rc = BASE_result (rc_final, x_label, my.m_cur - my.m_beg);
      DEBUG_HFIX    yLOG_value   ("result"    , rc);
      /*> sprintf (x_bit, "  %c %-8.8s %4d  ", rc_final, x_label, my.m_cur - my.m_beg);     <* 
       *> for (i = 0; i < 18; ++i) s_compile [MAX_ENTRY - 2][4 + i] = x_bit [i];      <*/
      /*---(done)-------------------------------*/
   }
   /*---(show results)--------------------------*/
   rc = EXIM_export     ('c', 'p', "");
   DEBUG_HFIX    yLOG_value   ("export"    , rc);
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return rc_num;
}
char
COMP_running       (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *f           = NULL;
   char        x_recd      [LEN_RECD]  = "";
   int         i           =    0;
   short       c           =    0;
   char        x_name      [LEN_TITLE] = "";
   char       *p           = NULL;
   char        x_bit       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(open)---------------------------*/
   rc = FILE_open  (HFIX_OUT, NULL, NULL, &f);
   DEBUG_HFIX  yLOG_value   ("open"      , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle lines)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      rc = FILE_read (f, NULL, NULL, x_recd);
      DEBUG_HFIX  yLOG_value   ("read"      , rc);
      if (rc == 0)   break;
      /*---(filter)----------------------*/
      if (strncmp ("gcc -c -std=", x_recd, 12) != 0) {
         DEBUG_HFIX  yLOG_note    ("filtered line");
         continue;
      }
      strlcpy (x_name, x_recd + 88, LEN_TITLE);
      p = strstr (x_name, ".c     ");
      if (p == NULL)     continue;
      p [0] = '\0';
      DEBUG_HFIX  yLOG_info    ("x_name"    , x_name);
      rc = BASE_mark (my.m_theme, x_name, 'n');
      DEBUG_HFIX  yLOG_value   ("marked"    , rc);
      ++c;
      /*---(done)------------------------*/
   }
   DEBUG_HFIX  yLOG_value   ("c"         , c);
   /*---(close)--------------------------*/
   rc = FILE_close (&f);
   DEBUG_HFIX  yLOG_value   ("close"     , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f != NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(update total)-------------------*/
   BASE_total ('n', c);
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return c;
}


char
RUN_clean          (void)
{
   /*> yexec_urun ("make --silent clean");                                            <*/
   return 0;
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
   char        x_nada      =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default/save)-------------------*/
   if (b_handled != NULL)  x_handled = *b_handled;
   if (b_shown   != NULL)  x_shown   = *b_shown;
   if (b_hidden  != NULL)  x_hidden  = *b_hidden;
   if (r_level   != NULL)  *r_level  = '-';
   if (r_show    != NULL)  strcpy (r_show, "");
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_point   ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("a_recd"    , a_recd);
   strlcpy (x_recd, a_recd, LEN_RECD);
   /*---(handle)-------------------------*/
   if      (strncmp (x_recd, "make:"      ,   5) == 0)          rc = MAKE_parse   (x_recd, &x_count, x_file, &x_type, &x_line, &x_col, &x_level, x_msg, x_flag, &x_nada);
   else if (strncmp (x_recd, "make["      ,   5) == 0)          rc = MAKE_parse   (x_recd, &x_count, x_file, &x_type, &x_line, &x_col, &x_level, x_msg, x_flag, &x_nada);
   else if (strncmp (x_recd, "/usr/libexec/gcc/",  16) == 0)    rc = LD_parse     (x_recd, &x_count, x_file, &x_type, &x_line, &x_col, &x_level, x_msg, x_flag);
   else                                                         rc = GCC_parse    (x_recd, &x_count, x_file, &x_type, &x_line, &x_col, &x_level, x_msg, x_flag);
   /*---(nothing to do)------------------*/
   if (x_nada == 'y') {
      if (r_level   != NULL)  *r_level   = 'm';
      return 0;
   }
   /*---(trouble)------------------------*/
   DEBUG_HFIX  yLOG_value   ("return"    , rc);
   if (rc <= 0) {
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   ++x_handled;
   /*---(classify)-----------------------*/
   DEBUG_HFIX  yLOG_info    ("c_filter"  , c_filter);
   DEBUG_HFIX  yLOG_value   ("c_pass"    , c_pass);
   if      (strchr (c_filter  , x_level) == NULL)  {  ++x_hidden;  }
   else if (c_pass == 0)                           {  ++x_shown;   }
   else                                            {  ++x_shown;  rc_final = 1; }
   /*---(show)---------------------------*/
   DEBUG_HFIX  yLOG_value   ("rc_final"  , rc_final);
   if (rc_final == 1)  strlcpy (x_show, SHOW_line (c_color, x_shown, x_type, x_file, x_line, x_col, x_level, x_msg, x_flag), LEN_FULL);
   /*---(save-back)----------------------*/
   if (b_handled != NULL)  *b_handled = x_handled;
   if (b_shown   != NULL)  *b_shown   = x_shown;
   if (b_hidden  != NULL)  *b_hidden  = x_hidden;
   if (r_level   != NULL)  *r_level   = x_level;
   if (r_show    != NULL)  strlcpy (r_show, x_show, LEN_FULL);
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
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
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(open)---------------------------*/
   rc = FILE_open (my.m_file, &x_total, &x_accept, &f);
   DEBUG_HFIX  yLOG_value   ("open"      , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle lines)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      rc = FILE_read (f, &x_total, &x_accept, x_recd);
      DEBUG_HFIX  yLOG_value   ("read"      , rc);
      if (rc == 0)   break;
      /*---(handle)----------------------*/
      rc = BASE__handle (c_pass, c_filter, c_color, x_recd, &x_handled, &x_shown, &x_hidden, &x_level, x_show);
      DEBUG_HFIX  yLOG_value   ("handle"    , rc);
      if (rc == 1)  printf ("%s\n", x_show);
      /*---(statistics)------------------*/
      DEBUG_HFIX  yLOG_char    ("level"     , x_level);
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
   rc = FILE_close (&f);
   DEBUG_HFIX  yLOG_value   ("close"     , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f != NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(totals)-------------------------*/
   printf ("%s\n", SHOW_totals (c_pass, c_color, x_shown, x_fail, x_errs, x_warn, x_waste, x_msgs, x_total));
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 0;
}

