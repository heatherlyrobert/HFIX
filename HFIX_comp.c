#include "HFIX.h"
/*> #include "yEXEC_solo.h"                                                           <*/
/*> #include "yEXEC_uver.h"                                                           <*/

/*>                                                                                                                                                                     <* 
 *> 123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-                                                                                    <* 
 *> -------------------------  -------------------------  -------------------------                                                                                     <* 
 *> HFIX·gcc/make·(----)··chosen··(c:comp)·=·compile·only,·show·critical·only·······(0.00a)·······································································[?]   <* 
 *> HFIX_base··············n·c    HFIX_gcc··········n·123s·c    HFIX_ld···········n·123s·c                                                                                     <* 
 *> HFIX_main·········n·123s·c    HFIX_make·········n·123s·c    HFIX_prog·········n·123s·c                                                                                     <* 
 *> HFIX_run··········n·123s·c    HFIX_show·········n·123s·c    ··························                                                                                     <* 
 *> polymnia_testing···-·-··1m    ··························    ··························                                                                                    <* 
 *> ··························    ··························    ··························                                                                                    <* 
 *> ··························    ··························    ··························                                                                                    <* 
 *> ··························    ··························    TOTAL···9···-···-·····123s                                                                                  <* 
 *>                                                                                                                                                                         <* 
 *> exists                                                                                                                                                                  <* 
 *> needs-compiling                                                                                                                                                         <* 
 *> compilied                                                                                                                                                               <* 
 *>                                                                                                                                                                     <*/

char    s_compile     [MAX_LINES][LEN_DESC];
char    s_ncount      =   0;
int     s_pos         =   0;


char
COMP_clear              (void)
{
   char        i           =    0;
   for (i = 0; i < MAX_LINES; ++i) {
      strlcpy (s_compile [i], "··························    ", LEN_DESC);
   }
   s_compile [20][ 0] = 'T';
   s_compile [20][ 1] = 'O';
   s_compile [20][ 2] = 'T';
   s_compile [20][ 3] = 'A';
   s_compile [20][ 4] = 'L';
   s_compile [20][ 8] = '-';
   s_compile [20][12] = '-';
   s_compile [20][16] = '-';
   s_compile [20][24] = '-';
   s_ncount = 0;
   return 0;
}

char
COMP_show               (FILE *f)
{
   char        i           =    0;
   char        x_col, x_row;
   char        x_line      [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   for (i = 0; i <= MAX_LINES; ++i) {
      x_col = i % 3;
      x_row = i - (x_col * 3);
      DEBUG_YSCORE   yLOG_complex ("loop"      , "%2dri, %2dc, %2dr", i, x_col, x_row);
      if (x_col == 0 && x_row > 0) {
         if (f == NULL)  printf  (   "%s\n", x_line);
         else            fprintf (f, "%s\n", x_line);
      }
      if (i >= MAX_LINES)  break;
      if (x_col == 0)  strlcpy (x_line, s_compile [i], LEN_FULL);
      else             strlcat (x_line, s_compile [i], LEN_FULL);
   }
   /*---(complete)------------------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
COMP_base          (char a_base [LEN_LABEL], char a_ext [LEN_TERSE])
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
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_base"     , a_base);
   --rce;  if (a_base == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_YSCORE   yLOG_info    ("a_base"     , a_base);
   lb = strlen (a_base);
   DEBUG_YSCORE   yLOG_value   ("lb"         , lb);
   --rce;  if (lb     <= 3) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_YSCORE   yLOG_point   ("a_ext"      , a_ext);
   --rce;  if (a_ext  == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_YSCORE   yLOG_info    ("a_ext"      , a_ext);
   le = strlen (a_ext);
   DEBUG_YSCORE   yLOG_value   ("le"         , le);
   --rce;  if (le     <= 1) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(clear-out)----------------------*/
   COMP_clear ();
   /*---(open dir)-----------------------*/
   x_dir = opendir(".");
   DEBUG_YSCORE   yLOG_point   ("x_dir"      , x_dir);
   --rce;  if (x_dir == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_YSCORE   yLOG_note    ("openned successfully");
   /*---(process entries)----------------*/
   DEBUG_YSCORE   yLOG_note    ("processing entries");
   while (1) {
      /*---(read a directory entry)------*/
      x_file = readdir (x_dir);
      DEBUG_YSCORE   yLOG_point   ("x_file"    , x_file);
      if (x_file == NULL)  break;
      ++x_total;
      /*---(filter by name)--------------*/
      strlcpy (x_name, x_file->d_name, LEN_TITLE);
      DEBUG_YSCORE   yLOG_info    ("x_name"    , x_name);
      l = strlen (x_name);
      strlcpy (x_bit, x_name, lb + 1);
      DEBUG_YSCORE   yLOG_info    ("x_bit"     , x_bit);
      if (strcmp (x_bit, a_base) != 0) {
         DEBUG_YSCORE   yLOG_note    ("skipping, wrong base");
         continue;
      }
      strcpy (x_bit, x_name + l - le);
      DEBUG_YSCORE   yLOG_info    ("x_bit"     , x_bit);
      if (strcmp (x_bit, a_ext) != 0) {
         DEBUG_YSCORE   yLOG_note    ("skipping, wrong extention");
         continue;
      }
      x_name [l - le] = '\0';
      /*---(place)-----------------------*/
      DEBUG_YSCORE   yLOG_note    ("accepted and placing");
      snprintf (x_full , 19, "%s············································", x_name);
      sprintf  (s_compile [s_ncount], "%s·-·-··-·    ", x_full);
      ++s_ncount;
      /*---(done)------------------------*/
   }
   DEBUG_YSCORE   yLOG_value   ("x_total"   , x_total);
   DEBUG_YSCORE   yLOG_value   ("s_ncount"  , s_ncount);
   /*---(close dir)----------------------*/
   DEBUG_YSCORE   yLOG_note    ("closing directory");
   rc = closedir (x_dir);
   DEBUG_YSCORE   yLOG_value   ("close_rc"  , rc);
   /*---(sort-it)------------------------*/
   COMP_sort ();
   /*---(update total)-------------------*/
   sprintf (x_bit, "%2d", s_ncount);
   if (x_bit [0] == ' ')  x_bit [0] = '·';
   if (x_bit [1] == ' ')  x_bit [1] = '·';
   s_compile [20][ 7] = x_bit [0];
   s_compile [20][ 8] = x_bit [1];
   s_compile [20][ 9] = 't';
   /*---(complete)------------------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return s_ncount;
}

static short   s_comp = 0;
static short   s_swap = 0;

char
COMP_sort               (void)
{
   /*---(locals)-----------+-----------+-*//*---------------------------------*/
   int         i           =  0;            /* loop iterator -- entry         */
   char       *a           = NULL;          /* comparison entry one           */
   char       *b           = NULL;          /* comparison entry two           */
   char        t           [LEN_DESC]  = "";
   int         tele        = -1;            /* teleport point to speed sort   */
   /*---(header)-------------------------*/
   DEBUG_YSCORE    yLOG_enter   (__FUNCTION__);
   /*---(sort)---------------------------*/
   s_comp = s_swap = 0;
   i = 1;
   while (i < s_ncount) {
      /*---(load vars)-------------------*/
      a = s_compile [i - 1];
      b = s_compile [i];
      DEBUG_YSCORE    yLOG_complex ("current"   , "compare %3d (%3d)  %-100.100s vs %-100.100s", i, tele, a, b);
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
      DEBUG_YSCORE    yLOG_complex ("swapped"   , "now     %3d (%3d)  %-100.100s    %-100.100s", i, tele, a, b);
      /*---(update)----------------------*/
      if (tele < 0) tele = i;
      if (i > 1) --i;
   }
   DEBUG_YSCORE    yLOG_complex ("stats"     , "count = %3d, comps = %5d, swaps = %5d", s_ncount, s_comp, s_swap);
   /*---(complete)------------------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
COMP_by_name       (char a_name [LEN_TITLE], char a_type)
{
   char        i           =    0;
   char        l           =    0;
   l = strlen (a_name);
   for (i = 0; i < MAX_LINES; ++i) {
      if (strncmp (s_compile [i], a_name, l) != 0)  continue;
      if      (a_type == 'n')  s_compile [i][19] = '³';
      else if (a_type == 'c')  s_compile [i][21] = ' ';
      else if (a_type == 'd')  s_compile [i][21] = 'Ï';
      return 1;
   }
   return 0;
}

char
COMP_recon         (void)
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
   DEBUG_YSCORE    yLOG_enter   (__FUNCTION__);
   /*---(open)---------------------------*/
   rc = BASE__open  ("HFIX.out", NULL, NULL, &f);
   DEBUG_PROG  yLOG_value   ("open"      , rc);
   DEBUG_PROG  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle lines)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      rc = BASE__read (f, NULL, NULL, x_recd);
      DEBUG_PROG  yLOG_value   ("read"      , rc);
      if (rc == 0)   break;
      /*---(filter)----------------------*/
      if (strncmp ("gcc -c -std=", x_recd, 12) != 0) {
         DEBUG_PROG  yLOG_note    ("filtered line");
         continue;
      }
      strlcpy (x_name, x_recd + 88, LEN_TITLE);
      p = strstr (x_name, ".c     ");
      if (p == NULL)     continue;
      p [0] = '\0';
      DEBUG_PROG  yLOG_info    ("x_name"    , x_name);
      rc = COMP_by_name (x_name, 'n');
      DEBUG_PROG  yLOG_value   ("marked"    , rc);
      ++c;
      /*---(done)------------------------*/
   }
   DEBUG_PROG  yLOG_value   ("c"         , c);
   /*---(close)--------------------------*/
   rc = BASE__close (&f);
   DEBUG_PROG  yLOG_value   ("close"     , rc);
   DEBUG_PROG  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f != NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(update total)-------------------*/
   sprintf (x_bit, "%2d", c);
   if (x_bit [0] == ' ')  x_bit [0] = '·';
   if (x_bit [1] == ' ')  x_bit [1] = '·';
   s_compile [20][11] = x_bit [0];
   s_compile [20][12] = x_bit [1];
   s_compile [20][13] = 'n';
   /*---(complete)------------------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return c;
}


char
RUN_clean          (void)
{
   /*> yexec_urun ("make --silent clean");                                            <*/
   return 0;
}
