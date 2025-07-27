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

char    s_whoami      [LEN_LABEL] = "";
char    s_ext         [LEN_TERSE] = "";
char    s_done        = '-';
char    s_status      = '-';
char    s_label       [LEN_LABEL] = "";
char    s_result      = '?';
char    s_error       = '-';

long    s_rpid        = 0;
long    s_cnt         = 0;
long    s_beg         = 0;
long    s_cur         = 0;
long    s_end         = 0;



char
COMP__clear             (char a_ext [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          =    0;
   char        i           =    0;
   char        x_title     [LEN_TERSE] = "TOTAL";
   char        x_whoami    [LEN_LABEL] = "";
   char        l           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   s_ncount = 0;
   s_rpid = s_cnt = s_beg = s_cur = s_end = 0;
   strcpy (s_whoami, "");
   strcpy (s_ext   , "");
   s_done = '-';
   /*---(clear entries)------------------*/
   for (i = 0; i < MAX_ENTRY; ++i) {
      strlcpy (s_compile [i], "··························   ", LEN_DESC);
   }
   /*---(defense)------------------------*/
   DEBUG_HFIX    yLOG_point   ("a_ext"     , a_ext);
   --rce;  if (a_ext     == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_info    ("a_ext"     , a_ext);
   /*---(add extension label)------------*/
   --rce; if (strcmp (a_ext, ".c")    == 0)  strcpy (x_title, "clang");
   else if   (strcmp (a_ext, ".unit") == 0)  strcpy (x_title, "UNITS");
   else if   (strcmp (a_ext, "wipe")  == 0)  strcpy (x_title, "wipe");
   else if   (strcmp (a_ext, "inst")  == 0)  strcpy (x_title, "inst");
   else if   (strcmp (a_ext, "remo")  == 0)  strcpy (x_title, "remo");
   else if   (strcmp (a_ext, "mans")  == 0)  strcpy (x_title, "mans");
   else {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX    yLOG_info    ("x_title"   , x_title);
   l = strlen (x_title);
   for (i = 0; i < l; ++i)   s_compile [MAX_ENTRY - 1][i] = x_title [i];
   /*---(add total marks)----------------*/
   s_compile [MAX_ENTRY - 1][ 8] = '-';
   s_compile [MAX_ENTRY - 1][13] = '-';
   s_compile [MAX_ENTRY - 1][18] = '-';
   s_compile [MAX_ENTRY - 1][24] = '-';
   /*---(add extension label)------------*/
   rc = HFIX_whoami (x_whoami);
   DEBUG_HFIX    yLOG_value   ("whoami"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_info    ("x_whoami"  , x_whoami);
   /*---(save-back)----------------------*/
   strlcpy (s_whoami, x_whoami, LEN_LABEL);
   strlcpy (s_ext   , a_ext   , LEN_TERSE);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

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
   DEBUG_HFIX   yLOG_info    ("s_whoami"   , s_whoami);
   lb = strlen (s_whoami);
   DEBUG_HFIX   yLOG_value   ("lb"         , lb);
   --rce;  if (lb     <= 3) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_info    ("s_ext"      , s_ext);
   le = strlen (s_ext);
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
      if (strcmp (x_bit, s_whoami) != 0) {
         DEBUG_HFIX   yLOG_note    ("skipping, wrong base");
         continue;
      }
      strcpy (x_bit, x_name + l - le);
      DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
      if (strcmp (x_bit, s_ext) != 0) {
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
      DEBUG_HFIX   yLOG_note    ("accepted and placing");
      snprintf (x_full , 19, "%s············································", x_name);
      sprintf  (s_compile [s_ncount], "%s·-·-··-·   ", x_full);
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
   sprintf (x_bit, "%2d", s_ncount);
   if (x_bit [0] == ' ')  x_bit [0] = '·';
   if (x_bit [1] == ' ')  x_bit [1] = '·';
   if (s_ncount == 0)     x_bit [1] = '/';
   s_compile [MAX_ENTRY - 1][ 7] = x_bit [0];
   s_compile [MAX_ENTRY - 1][ 8] = x_bit [1];
   s_compile [MAX_ENTRY - 1][ 9] = 't';
   /*---(complete)------------------------------*/
   DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
   return s_ncount;
}

char
COMP__exist             (char c_type, char a_name [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        i           =    0;
   char        l           =    0;
   char        x_name      [LEN_LABEL] = "";
   char        c           =    0;
   char        x_row, x_col;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX   yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name == NULL || a_name [0] == '\0') {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_info    ("a_name"    , a_name);
   --rce;  if (strchr (" ·", a_name [0]) != NULL) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(prepare lookup)-----------------*/
   DEBUG_HFIX   yLOG_char    ("c_type"    , c_type);
   switch (c_type) {
   case 'w' : case 'i' : case 'r' :
      l = 14; 
      break;
   default  :
      l = 18;
      break;
   }
   DEBUG_HFIX   yLOG_value   ("l"         , l);
   snprintf (x_name, LEN_LABEL - 1, "%s······························", a_name);
   DEBUG_HFIX   yLOG_info    ("x_name"    , x_name);
   /*---(prepare lookup)-----------------*/
   for (i = 0; i < MAX_ENTRY; ++i) {
      if (s_compile [i] [0] == '·')                  continue;
      ++c;
      if (strncmp (s_compile [i], x_name, l) != 0)   continue;
      /*---(complete)--------------------*/
      x_row = i / 3;
      x_col = i % 3;
      DEBUG_HFIX   yLOG_complex ("FOUND"     , "%2d#, %2dr, %2dc, filled %2d", i, x_row, x_col, c);
      DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
      return i + 1;
   }
   /*---(trouble)------------------------*/
   --rce;  
   DEBUG_HFIX    yLOG_note    ("name never found");
   DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
   return rce;
}

char
COMP__mark              (char a_name [LEN_TITLE], char a_mark)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        n           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(find)---------------------------*/
   n = COMP__exist ('c', a_name);
   DEBUG_HFIX   yLOG_value   ("n"         , n);
   --rce;  if (n < 0) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(mark)---------------------------*/
   DEBUG_HFIX   yLOG_char    ("a_mark"    , a_mark);
   --rce;  if (a_mark == 0 || strchr ("nbe", a_mark) == NULL) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   if      (a_mark == 'n')  s_compile [n - 1][19] = '³';
   else if (a_mark == 'b')  s_compile [n - 1][21] = ' ';
   else if (a_mark == 'e')  s_compile [n - 1][21] = 'Ï';
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
COMP__mark_done         (char a_status, char a_label [LEN_LABEL], int a_cnt)
{
   char        x_bit       [LEN_LABEL] = "";
   int         i           =    0;
   sprintf (x_bit, "  %c %-8.8s %4d  ", a_status, a_label, a_cnt);
   for (i = 0; i < 19; ++i) s_compile [MAX_ENTRY - 2][4 + i] = x_bit [i];
   return 0;
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
      rc = COMP__clear (".c");
      DEBUG_HFIX    yLOG_value   ("clear"     , rc);
      rc = COMP__base  ();
      DEBUG_HFIX    yLOG_value   ("base"      , rc);
      /*---(run make)--------------------*/
      s_beg  = s_cur  = time (NULL);
      DEBUG_HFIX    yLOG_value   ("s_beg"     , s_beg);
      switch (c_type) {
      case 'r'  :  s_rpid = yexec_ufork ("/bin/bash -c HFIX_reconc");  break;
      case 'c'  :  s_rpid = yexec_ufork ("/bin/bash -c HFIX_make");    break;
      }
      DEBUG_HFIX    yLOG_value   ("ufork"     , s_rpid);
      /*---(default check)---------------*/
      rc_final = HFIX_CHK;
      strcpy (x_label, "launched");
      /*---(done)------------------------*/
   } else if (c_phase == HFIX_CHK) {
      DEBUG_HFIX    yLOG_note    ("c recon/make update/wait");
      rc = EXIM_import ("");
      DEBUG_HFIX    yLOG_value   ("import"    , rc);
      DEBUG_HFIX    yLOG_value   ("s_rpid"    , s_rpid);
      if (s_rpid > 0) {
         usleep (500000);
         s_cur  = time (NULL);
         COMP__chk ();
         DEBUG_HFIX    yLOG_value   ("s_cur"     , s_cur);
         rc_final = yexec_uwait (s_rpid, x_label);
         DEBUG_HFIX    yLOG_char    ("uwait"     , rc_final);
         ACTS__progress ('1');
         /*> ++s_cnt;                                                                 <*/
      }
   } else {
      DEBUG_HFIX    yLOG_note    ("unknown request");
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_value   ("s_cnt"     , s_cnt);
   /*---(check status)--------------------------*/
   if (s_rpid > 0) {
      switch (rc_final) {
      case HFIX_CHK :  case 'r' :
         rc_num = 0;
         break;
      case '#' :
         strcpy (x_label, "DONE");
      default  :
         s_rpid = 0;
         s_end  = time (NULL);
         s_done = 'Y';
         strcpy (x_bit, HFIX_age (s_beg, s_end));
         for (i = 0; i < 3; ++i) s_compile [MAX_ENTRY - 1][23 + i] = x_bit [i];
         break;
      }
      /*---(update elapsed)---------------------*/
      sprintf (x_bit, "  %c %-8.8s %4d  ", rc_final, x_label, s_cur - s_beg);
      for (i = 0; i < 18; ++i) s_compile [MAX_ENTRY - 2][4 + i] = x_bit [i];
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
      s_beg  = s_cur  = time (NULL);
      DEBUG_HFIX    yLOG_value   ("s_beg"     , s_beg);
      s_rpid = yexec_ufork ("/bin/bash -c HFIX_make");
      DEBUG_HFIX    yLOG_value   ("ufork"     , s_rpid);
      rc_final = yexec_uwait (s_rpid, x_label);
      DEBUG_HFIX    yLOG_char    ("uwait"     , rc_final);
      COMP__chk ();
      rc_final = HFIX_CHK;
      strcpy (x_label, "launched");
   } else if (a_phase == HFIX_CHK) {
      DEBUG_HFIX    yLOG_note    ("c recon update/wait");
      rc = EXIM_import ("");
      DEBUG_HFIX    yLOG_value   ("import"    , rc);
      DEBUG_HFIX    yLOG_value   ("s_rpid"    , s_rpid);
      if (s_rpid > 0) {
         usleep (500000);
         s_cur  = time (NULL);
         COMP__chk ();
         DEBUG_HFIX    yLOG_value   ("s_cur"     , s_cur);
         rc_final = yexec_uwait (s_rpid, x_label);
         DEBUG_HFIX    yLOG_char    ("uwait"     , rc_final);
         ACTS__progress ('2');
         /*> ++s_cnt;                                                                 <*/
      }
   } else {
      DEBUG_HFIX    yLOG_note    ("unknown request");
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_value   ("s_cnt"     , s_cnt);
   /*---(check status)--------------------------*/
   if (s_rpid > 0) {
      switch (rc_final) {
      case HFIX_CHK :  case 'r' :
         rc_num = 0;
         break;
      case '#' :
         strcpy (x_label, "DONE");
      default  :
         s_rpid = 0;
         s_end  = time (NULL);
         s_done = 'Y';
         strcpy (x_bit, HFIX_age (s_beg, s_end));
         for (i = 0; i < 3; ++i) s_compile [MAX_ENTRY - 1][23 + i] = x_bit [i];
         break;
      }
      /*---(update elapsed)---------------------*/
      sprintf (x_bit, "  %c %-8.8s %4d  ", rc_final, x_label, s_cur - s_beg);
      for (i = 0; i < 18; ++i) s_compile [MAX_ENTRY - 2][4 + i] = x_bit [i];
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
   rc = BASE__open  (HFIX_OUT, NULL, NULL, &f);
   DEBUG_HFIX  yLOG_value   ("open"      , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle lines)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      rc = BASE__read (f, NULL, NULL, x_recd);
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
      rc = COMP__mark (x_name, 'n');
      DEBUG_HFIX  yLOG_value   ("marked"    , rc);
      ++c;
      /*---(done)------------------------*/
   }
   DEBUG_HFIX  yLOG_value   ("c"         , c);
   /*---(close)--------------------------*/
   rc = BASE__close (&f);
   DEBUG_HFIX  yLOG_value   ("close"     , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f != NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(update total)-------------------*/
   sprintf (x_bit, "%2d", c);
   if (x_bit [0] == ' ')  x_bit [0] = '·';
   if (x_bit [1] == ' ')  x_bit [1] = '·';
   if (c == 0)            x_bit [1] = '/';
   s_compile [MAX_ENTRY - 1][12] = x_bit [0];
   s_compile [MAX_ENTRY - 1][13] = x_bit [1];
   s_compile [MAX_ENTRY - 1][14] = 'n';
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
