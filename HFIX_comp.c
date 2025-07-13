#include "HFIX.h"
#include "yEXEC_solo.h"
#include "yEXEC_uver.h"

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
int     s_pos         =   0;

char    s_whoami      [LEN_LABEL] = "";
char    s_ext         [LEN_TERSE] = "";

long    s_rpid        = 1234567890;
long    s_cnt         = 1234567890;
long    s_beg         = 1234567890;
long    s_cur         = 1234567890;
long    s_end         = 1234567890;



char
COMP__clear             (char a_ext [LEN_TERSE])
{
   char        i           =    0;
   char        x_title     [LEN_TERSE] = "TOTAL";
   char        l           =    0;
   if      (strcmp (a_ext, ".c")    == 0)  strcpy (x_title, "clang");
   else if (strcmp (a_ext, ".unit") == 0)  strcpy (x_title, "units");
   for (i = 0; i < MAX_ENTRY; ++i) {
      strlcpy (s_compile [i], "··························   ", LEN_DESC);
   }
   l = strlen (x_title);
   for (i = 0; i < l; ++i)   s_compile [MAX_ENTRY - 1][i] = x_title [i];
   s_compile [MAX_ENTRY - 1][ 8] = '-';
   s_compile [MAX_ENTRY - 1][13] = '-';
   s_compile [MAX_ENTRY - 1][18] = '-';
   s_compile [MAX_ENTRY - 1][24] = '-';
   s_ncount = 0;
   HFIX_whoami (s_whoami);
   strcpy (s_ext , a_ext);
   s_rpid = s_cnt = s_beg = s_cur = s_end = 0;
   return 0;
}

char
COMP__base         (char a_base [LEN_LABEL], char a_ext [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   int         rc          =    0;          /* generic return code            */
   char        rce         =  -10;          /* return code for errors         */
   DIR        *x_dir       = NULL;          /* directory pointer              */
   tDIRENT    *x_file      = NULL;          /* directory entry pointer        */
   char        x_name      [LEN_TITLE];      /* file name                      */
   char        x_bit       [LEN_LABEL];
   int         lb          =    0;
   int         le          =    0;
   int         l           =    0;
   char        x_full      [LEN_TITLE] = "";
   char        x_total     =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX   yLOG_point   ("a_base"     , a_base);
   --rce;  if (a_base == NULL) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_info    ("a_base"     , a_base);
   lb = strlen (a_base);
   DEBUG_HFIX   yLOG_value   ("lb"         , lb);
   --rce;  if (lb     <= 3) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_point   ("a_ext"      , a_ext);
   --rce;  if (a_ext  == NULL) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_info    ("a_ext"      , a_ext);
   le = strlen (a_ext);
   DEBUG_HFIX   yLOG_value   ("le"         , le);
   --rce;  if (le     <= 1) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(clear-out)----------------------*/
   COMP__clear (a_ext);
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
      if (strcmp (x_bit, a_base) != 0) {
         DEBUG_HFIX   yLOG_note    ("skipping, wrong base");
         continue;
      }
      strcpy (x_bit, x_name + l - le);
      DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
      if (strcmp (x_bit, a_ext) != 0) {
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
   COMP__sort ();
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

static short   s_comp = 0;
static short   s_swap = 0;

char
COMP__sort              (void)
{
   /*---(locals)-----------+-----------+-*//*---------------------------------*/
   int         i           =  0;            /* loop iterator -- entry         */
   char       *a           = NULL;          /* comparison entry one           */
   char       *b           = NULL;          /* comparison entry two           */
   char        t           [LEN_DESC]  = "";
   int         tele        = -1;            /* teleport point to speed sort   */
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(sort)---------------------------*/
   s_comp = s_swap = 0;
   i = 1;
   while (i < s_ncount) {
      /*---(load vars)-------------------*/
      a = s_compile [i - 1];
      b = s_compile [i];
      DEBUG_HFIX    yLOG_complex ("current"   , "compare %3d (%3d)  %-100.100s vs %-100.100s", i, tele, a, b);
      /*---(compare)---------------------*/
      ++s_comp;
      if (i == 0 || strcmp (a, b) <= 0) {
         if (tele >= 0) {
            i    = tele;
            tele = -1;
         } else {
            ++i;
         }
         continue;
      }
      /*---(swap)------------------------*/
      ++s_swap;
      strlcpy (t, a, LEN_DESC);
      strlcpy (a, b, LEN_DESC);
      strlcpy (b, t, LEN_DESC);
      a = s_compile [i - 1];
      b = s_compile [i];
      DEBUG_HFIX    yLOG_complex ("swapped"   , "now     %3d (%3d)  %-100.100s    %-100.100s", i, tele, a, b);
      /*---(update)----------------------*/
      if (tele < 0) tele = i;
      if (i > 1) --i;
   }
   DEBUG_HFIX    yLOG_complex ("stats"     , "count = %3d, comps = %5d, swaps = %5d", s_ncount, s_comp, s_swap);
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
COMP__by_name           (char a_name [LEN_TITLE], char a_type)
{
   char        i           =    0;
   char        l           =    0;
   l = strlen (a_name);
   for (i = 0; i < MAX_ENTRY; ++i) {
      if (strncmp (s_compile [i], a_name, l) != 0)  continue;
      if      (a_type == 'n')  s_compile [i][19] = '³';
      else if (a_type == 'c')  s_compile [i][21] = ' ';
      else if (a_type == 'd')  s_compile [i][21] = 'Ï';
      return 1;
   }
   return 0;
}

char
COMP__recon             (void)
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
   rc = BASE__open  ("HFIX.out", NULL, NULL, &f);
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
      rc = COMP__by_name (x_name, 'n');
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
COMP_c_recon            (char a_phase)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        rc_final    =    0;
   int         i           =    0;
   char        x_bit       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   if (a_phase == '[') {
      DEBUG_HFIX    yLOG_note    ("c recon request/fork");
      rc = COMP__clear (".c");
      DEBUG_HFIX    yLOG_value   ("clear"     , rc);
      rc = COMP__base  (s_whoami, s_ext );
      DEBUG_HFIX    yLOG_value   ("base"      , rc);
      s_beg  = s_cur  = time (NULL);
      DEBUG_HFIX    yLOG_value   ("s_beg"     , s_beg);
      s_rpid = yexec_ufork ("bash -c HFIX_recon");
      DEBUG_HFIX    yLOG_value   ("ufork"     , s_rpid);
      rc = '-';
   } else if (a_phase == '>') {
      DEBUG_HFIX    yLOG_note    ("c recon update/wait");
      rc = EXIM_import ("");
      DEBUG_HFIX    yLOG_value   ("import"    , rc);
      /*> usleep (500000);                                                            <*/
      s_cur  = time (NULL);
      DEBUG_HFIX    yLOG_value   ("s_cur"     , s_cur);
      rc     = yexec_uwait (s_rpid);
      DEBUG_HFIX    yLOG_char    ("uwait"     , rc);
      ++s_cnt;
   } else {
      DEBUG_HFIX    yLOG_note    ("unknown request");
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_value   ("s_cnt"     , s_cnt);
   /*---(update elapsed)------------------------*/
   sprintf (x_bit, "  %c %4d  ", rc, s_cur - s_beg);
   for (i = 0; i < 10; ++i) s_compile [MAX_ENTRY - 2][6 + i] = x_bit [i];
   /*---(show results)--------------------------*/
   rc = SHOW_vim_action ("r");
   DEBUG_HFIX    yLOG_value   ("title"     , rc);
   rc = EXIM_export     ("");
   DEBUG_HFIX    yLOG_value   ("export"    , rc);
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return rc_final;
}

char
COMP_c_recon_n          (void)
{
   SHOW_vim_action ("r");
   COMP__recon     ();
   EXIM_export     ("");
   return 0;
}

char COMP_prep_c    (void) { COMP__clear (".c");    COMP__base  (s_whoami, s_ext ); return 0; }
char COMP_prep_u    (void) { COMP__clear (".unit"); COMP__base  (s_whoami, s_ext ); return 0; }

/*> char                                                                                                                                                        <* 
 *> COMP_clean_0            (void)                                                                                                                              <* 
 *> {                                                                                                                                                           <* 
 *>    char        rc         =    0;                                                                                                                           <* 
 *>    int         i          =    0;                                                                                                                           <* 
 *>    char        x_msg      [LEN_FULL] = "small clean underway";                                                                                              <* 
 *>    /+---(header)-------------------------+/                                                                                                                 <* 
 *>    SHOW_vim_action ("w");                                                                                                                                   <* 
 *>    /+---(launch)-------------------------+/                                                                                                                 <* 
 *>    if (n == 0) {                                                                                                                                            <* 
 *>       /+> strcpy (s_ext , ".c");                                                      <+/                                                                   <* 
 *>       COMP__clear (".c" );                                                                                                                                  <* 
 *>       /+> HFIX_whoami (s_whoami);                                                     <+/                                                                   <* 
 *>       COMP__base  (s_whoami, s_ext );                                                                                                                       <* 
 *>       COMP__recon ();                                                                                                                                       <* 
 *>       EXIM_export  ("");                                                                                                                                    <* 
 *>       /+> s_rpid = ufork ("make clean         > HFIX.out  2>&1");                      <+/                                                                  <* 
 *>    } else {                                                                                                                                                 <* 
 *>       EXIM_import ("");                                                                                                                                     <* 
 *>       /+> rc     = uwait (s_rpid);                                                     <+/                                                                  <* 
 *>    }                                                                                                                                                        <* 
 *>    /+> for (i = 0; i < n; ++i)  strlcat (x_msg, ".", LEN_FULL);                       <+/                                                                   <* 
 *>    /+> printf ("%-40.40s                                                                                                                     [?]");   <+/   <* 
 *>    /+> printf ("%d\n", x_rpid);                                                       <+/                                                                   <* 
 *>                                                                                                                                                             <* 
 *>    /+> system ("make clean         > HFIX.out  2>&1");                                <+/                                                                   <* 
 *>    /+> system ("make --recon base  > HFIX.out  2>&1");                                <+/                                                                   <* 
 *>    return 0;                                                                                                                                                <* 
 *> }                                                                                                                                                           <*/

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
   rc = BASE__open  ("HFIX.out", NULL, NULL, &f);
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
      rc = COMP__by_name (x_name, 'n');
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
