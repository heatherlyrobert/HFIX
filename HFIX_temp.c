#include "HFIX.h"



static short   s_comp = 0;
static short   s_swap = 0;

char
HFIX__sort_mods         (char a_phase)
{
   int         i           =    0;
   int         j           =    0;
   char        x_ch        =  '·';
   for (i = 0; i < s_ncount; ++i) {
      for (j = 0; j < 18; ++j) {
         x_ch = s_compile [i][j];
         if (a_phase == 'b' && x_ch == '·')  x_ch = ' ';
         if (a_phase == 'a' && x_ch == ' ')  x_ch = '·';
         s_compile [i][j] = x_ch;
      }
   }
   return 0;
}

char
HFIX_sort               (void)
{
   /*---(locals)-----------+-----------+-*//*---------------------------------*/
   int         i           =  0;            /* loop iterator -- entry         */
   char       *a           = NULL;          /* comparison entry one           */
   char       *b           = NULL;          /* comparison entry two           */
   char        t           [LEN_DESC]  = "";
   int         tele        = -1;            /* teleport point to speed sort   */
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   HFIX__sort_mods ('b');
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
   /*---(prepare)------------------------*/
   HFIX__sort_mods ('a');
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
HFIX_whoami              (char r_name [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_home      [LEN_HUND]  = "";
   char        x_work      [LEN_HUND]  = "";
   char        x_name      [LEN_LABEL] = "";
   char       *p           = NULL;
   char       *q           = NULL;
   int         l           =    0;
   /*---(default)------------------------*/
   if (r_name != NULL)   strlcpy (r_name, "", LEN_LABEL);
   /*---(get the home)-------------------*/
   p = getcwd (x_home, LEN_HUND);
   --rce;  if (p == NULL)   return rce;
   l = strlen (x_home);
   /*> printf ("%3då%sæ\n", l, x_home);                                               <*/
   /*---(check valid areas)--------------*/
   --rce; if (l > 16 && strncmp ("/home/system/"         , x_home, 13) == 0) ;
   else if   (l > 19 && strncmp ("/home/keepsake/"       , x_home, 15) == 0) ;
   else if   (l >  8 && strncmp ("/tmp/"                 , x_home,  5) == 0) ;
   else return rce;
   /*---(prepare name)-------------------*/
   strlcpy (x_work, x_home, LEN_HUND);
   l = strlen (x_work);
   if (x_work [l - 1] == '/')  x_work [--l] = '\0';
   /*> printf ("%3då%sæ\n", l, x_work);                                               <*/
   /*---(get the project)----------------*/
   p = strrchr (x_work, '/');
   if (p == NULL)   p = x_work;
   else             ++p;
   /*> printf ("%3då%sæ\n", strlen (p), p);                                           <*/
   q = strchr  (p, '.');
   if (q != NULL)  q [0] = '\0';
   /*> printf ("%3då%sæ\n", strlen (p), p);                                           <*/
   snprintf (x_name, LEN_LABEL, "%s_", p);
   /*> printf ("%3då%sæ\n", strlen (x_name), x_name);                                 <*/
   /*---(save back)----------------------*/
   if (r_name != NULL)  strlcpy (r_name, x_name, LEN_LABEL);
   /*---(complete)-----------------------*/
   return 0;
}

char*
HFIX_age                 (ullong a_beg, ullong a_end)
{
   /*---(locals)-------------------------*/
   ullong      x_age       =    0;
   char        x_unit      =  's';
   static char x_pretty    [LEN_SHORT] = "  ·";
   /*---(defense)------------------------*/
   if (a_beg <= 0) return "#/b";   /* negative beginning */
   if (a_end <= 0) return "#/e";   /* negative ending */
   x_age = a_end - a_beg;
   if (x_age <  0) return "#/p";   /* cur < beg (past)   */
   /*---(handle tiny)--------------------*/
   if (x_age == 0) return "·<s";   /* less than a second */
   /*---(figure age)---------------------*/
   if (x_age >  90) {
      x_age /= 60; x_unit = 'm';  /* minutes */
      if (x_age >= 60) {
         x_age /= 60; x_unit = 'h';  /* hours */
         if (x_age >= 24) {
            x_age /= 24; x_unit = 'd';  /* days */
            if (x_age >= 30) {
               x_age /= 30; x_unit = 'M';  /* months avg 30 days */
               if (x_age >= 12) {
                  x_age /= 12; x_unit = 'Y';  /* year */
                  if (x_age >= 100) {
                     x_age /= 100; x_unit = 'ì';  /* century */
                     if (x_age >= 100) {
                        x_age /= 100; x_unit = 'ê';   /* myriad 10,000 */
                        if (x_age >= 100) {
                           x_age /= 100; x_unit = 'ò';   /* millions */
                           if (x_age >= 100) {
                              return "#/h";   /* huge date 100 years */
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   /*---(save-back)----------------------*/
   sprintf (x_pretty, "%2d%c", x_age, x_unit);
   if (x_pretty [0] == ' ')  x_pretty [0] = '·';
   /*---(complete)-----------------------*/
   return x_pretty;
}

char*
HFIX_size                (ullong a_bytes)
{
   /*---(locals)-------------------------*/
   ullong      x_size      =    0;
   char        x_unit      =  '´';
   int         x_mult      = 1000;
   static char x_pretty    [LEN_SHORT] = "··-·";
   /*---(weird byte number)--------------*/
   if (a_bytes <  0) {
      strcpy (x_pretty, "#/ne");
      return x_pretty;
   }
   x_size  = a_bytes;
   /*---(check trival size)--------------*/
   if (x_size == 0) {
      strcpy (x_pretty, "··<´");
      return x_pretty;
   }
   /*---(figure size)--------------------*/
   if (x_size >= x_mult) {
      x_size /= x_mult; x_unit  = 'k';
      if (x_size >= x_mult) {
         x_size /= x_mult; x_unit  = 'm';
         if (x_size >= x_mult) {
            x_size /= x_mult; x_unit  = 'g';
            if (x_size >= x_mult) {
               x_size /= x_mult; x_unit  = 't';
               if (x_size >= x_mult) {
                  x_size /= x_mult; x_unit  = 'p';
                  if (x_size >= x_mult) {
                     x_size /= x_mult; x_unit  = 'e';
                     if (x_size >= 10) {
                        strcpy (x_pretty, "#/hu");  /* 1,000+ exabytes */
                        return x_pretty;
                     }
                  }
               }
            }

         }
      }
   }
   /*---(save-back)----------------------*/
   sprintf (x_pretty, "%3d%c", x_size, x_unit);
   /*---(check for fill)-----------------*/
   if (x_pretty [0] == ' ')  x_pretty [0] = '·';
   if (x_pretty [1] == ' ')  x_pretty [1] = '·';
   /*---(complete)-----------------------*/
   return x_pretty;
}



