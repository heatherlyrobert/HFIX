#include "HFIX.h"



char
GCC__file               (char c_conf, char *b_beg, char **r_next, char *r_type, char r_file [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *n           = NULL;
   char       *s           = NULL;
   int         l           =    0;
   char        x_type      =  'á';
   char        x_file      [LEN_HUND]  = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_next  != NULL)  *r_next = b_beg;
   if (r_type  != NULL)  *r_type = '-';
   if (r_file  != NULL)  strcpy (r_file, "");
   /*---(defence)------------------------*/
   DEBUG_HFIX  yLOG_point   ("b_beg"     , b_beg);
   --rce;  if (b_beg  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("b_beg"     , b_beg);
   DEBUG_HFIX  yLOG_point   ("r_next"    , r_next);
   --rce;  if (r_next == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(leading space)------------------*/
   if (b_beg [0] == ' ')  ++b_beg;
   /*---(check delimiter)----------------*/
   n = strchr (b_beg , ':');
   DEBUG_HFIX  yLOG_point   ("n"         , n);
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   /*---(handle path)--------------------*/
   DEBUG_HFIX  yLOG_char    ("c_conf"    , c_conf);
   s = strrchr (b_beg, '/');
   if (s != NULL) {
      s [0] = '\0';
      b_beg = s + 1;
   }
   /*---(check size)---------------------*/
   l = strlen (b_beg);
   DEBUG_HFIX  yLOG_value   ("l"         , l);
   --rce;  if (l < 3 || l >= LEN_HUND) {
      n [0] = ':';  /* put it back to original conditions */
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("b_beg"     , b_beg);
   /*---(convert)------------------------*/
   if (c_conf == 'm')   strlcpy (x_file, "zeno_make·····················", LEN_HUND);
   else                 strlcpy (x_file, b_beg, LEN_HUND);
   DEBUG_ARGS  yLOG_complex ("FILE"      , "%3då%sæ", l, x_file);
   /*---(check file type)----------------*/
   --rce;  if (strchr ("gl", c_conf) != NULL) {
      DEBUG_HFIX  yLOG_info    ("suffix"    , x_file + l - 2);
      if      (l > 3 && strcmp (x_file + l - 2, ".c")     == 0)  x_type = 'c';
      else if (l > 4 && strcmp (x_file + l - 3, ".cs")    == 0)  x_type = 'c';
      else if (l > 3 && strcmp (x_file + l - 2, ".h")     == 0)  x_type = 'h';
      else if (l > 6 && strcmp (x_file + l - 5, ".unit")  == 0)  x_type = 'u';
      else if (l > 7 && strcmp (x_file + l - 6, ".munit") == 0)  x_type = 'm';
      else if (l > 3 && strcmp (x_file + l - 3, ".so")    == 0)  x_type = 's';
      else {
         n [0] = ':';  /* put it back to original conditions */
         DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(save-back)----------------------*/
   if (r_next  != NULL)  *r_next = n + 1;
   if (r_type  != NULL)  *r_type = x_type;
   if (r_file  != NULL)  strlcpy (r_file, x_file, LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
GCC__num                (char *b_beg, char **r_next, short *r_num)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *n           = NULL;
   int         l           =    0;
   short       x_num       =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_next  != NULL)  *r_next = b_beg;
   if (r_num   != NULL)  *r_num  = -1;
   /*---(defence)------------------------*/
   DEBUG_HFIX  yLOG_point   ("b_beg"     , b_beg);
   --rce;  if (b_beg  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("b_beg"     , b_beg);
   DEBUG_HFIX  yLOG_point   ("r_next"    , r_next);
   --rce;  if (r_next == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get line number)----------------*/
   n = strchr (b_beg , ':');
   DEBUG_HFIX  yLOG_point   ("n"         , n);
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   l = strlen (b_beg);
   DEBUG_HFIX  yLOG_value   ("l"         , l);
   --rce;  if (l < 1 || l > 5) {
      n [0] = ':';  /* put it back to original conditions */
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("b_beg"     , b_beg);
   /*---(convert)------------------------*/
   x_num  = atoi (b_beg);
   DEBUG_HFIX  yLOG_value   ("x_num"     , x_num);
   --rce;  if (x_num == 0 && strcmp (b_beg, "0") != 0) {
      n [0] = ':';  /* put it back to original conditions */
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (x_num <  0) {
      n [0] = ':';  /* put it back to original conditions */
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_ARGS  yLOG_value   ("LINE"      , x_num);
   /*---(save-back)----------------------*/
   if (r_next  != NULL)  *r_next = n + 1;
   if (r_num   != NULL)  *r_num  = x_num;
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
GCC__level              (char *b_beg, char **r_next, char *r_type)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *n           = NULL;
   int         l           =    0;
   char        x_type      =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_next  != NULL)  *r_next = b_beg;
   if (r_type  != NULL)  *r_type = '-';
   /*---(defence)------------------------*/
   DEBUG_HFIX  yLOG_point   ("b_beg"     , b_beg);
   --rce;  if (b_beg  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("b_beg"     , b_beg);
   DEBUG_HFIX  yLOG_point   ("r_next"    , r_next);
   --rce;  if (r_next == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get type)-----------------------*/
   n = strchr (b_beg , ':');
   DEBUG_HFIX  yLOG_point   ("n"         , n);
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   l = strlen (b_beg);
   DEBUG_HFIX  yLOG_value   ("l"         , l);
   --rce;  if (l < 6 || l > 10) {
      n [0] = ':';  /* put it back to original conditions */
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("b_beg"     , b_beg);
   --rce; if  (strcmp (b_beg, " warning") == 0)   x_type = 'W';
   else if    (strcmp (b_beg, " error"  ) == 0)   x_type = 'E';
   else {
      DEBUG_ARGS  yLOG_exitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_ARGS  yLOG_char    ("TYPE"      , x_type);
   /*---(save-back)----------------------*/
   if (r_next  != NULL)  *r_next = n + 1;
   if (r_type  != NULL)  *r_type = x_type;
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
GCC__msg                (char c_conf, char *b_beg, short *b_count, char r_msg [LEN_RECD], char r_flag [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *n           = NULL;
   int         l           =    0;
   char       *s           = NULL;
   int         x_count     =    0;
   char        x_msg       [LEN_RECD]  = "";
   char        x_flag      [LEN_HUND]  = "···";
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (b_count != NULL)  x_count = *b_count;
   if (r_msg   != NULL)  strcpy (r_msg , "");
   if (r_flag  != NULL)  strcpy (r_flag, "");
   /*---(defence)------------------------*/
   DEBUG_HFIX  yLOG_point   ("b_beg"     , b_beg);
   --rce;  if (b_beg  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("b_beg"     , b_beg);
   /*---(leading space)------------------*/
   if (b_beg [0] == ' ')  ++b_beg;
   /*---(get message)--------------------*/
   strlcpy (x_msg , b_beg, LEN_RECD);
   /*---(handle flag)--------------------*/
   if (c_conf == 'g') {
      s = strstr (x_msg, " [-W");
      if (s != NULL) {
         s [0] = '\0';
         strlcpy (x_flag, s + 2, LEN_HUND);
         l = strlen (x_flag);
         if (x_flag [l - 1] == ']')  x_flag [l - 1] = '\0';
      }
   } else if (c_conf == 'l') {
      s = strchr (x_msg, '\'');
      if (s != NULL)   s [0] = 'æ';
      s = strchr (x_msg, '`');
      if (s != NULL)   s [0] = 'å';
   } else if (c_conf == 'm') {
      s = strchr (x_msg, ']');
      if (s != NULL) {
         s [0] = '\0';
         strlcpy (x_flag, s + 2, LEN_HUND);
      }
   }
   /*---(display)------------------------*/
   l = strlen (x_msg);
   DEBUG_ARGS  yLOG_complex ("MSG"       , "%3då%sæ", l, x_msg);
   l = strlen (x_flag);
   DEBUG_ARGS  yLOG_complex ("FLAG"      , "%3då%sæ", l, x_flag);
   /*---(save-back)----------------------*/
   if (b_count != NULL)  *b_count = x_count + 1;
   if (r_msg   != NULL)  strlcpy (r_msg , x_msg , LEN_RECD);
   if (r_flag  != NULL)  strlcpy (r_flag, x_flag, LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
GCC__regrade            (char c_ylog, char b_msg [LEN_RECD], char *b_level)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_level     =  '-';
   char        x_quotes    =  '-';
   char       *p           = NULL;
   char        x_msg       [LEN_RECD]  = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(save)---------------------------*/
   if (b_level != NULL)  x_level = *b_level;
   /*---(defence)------------------------*/
   DEBUG_HFIX  yLOG_point   ("b_msg"     , b_msg);
   --rce;  if (b_msg  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("b_msg"     , b_msg);
   /*---(cut-out)------------------------*/
   --rce;  if (strncmp (b_msg, "'o___"       ,  5) == 0   ) {
      if (b_level != NULL)  *b_level = '-';
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(upgrades)-----------------------*/
   if      (strstr  (b_msg, "no previous prototype")  != NULL) { x_level = 'W';  x_quotes = ';'; strcpy  (x_msg, "no prototype for·····"); }
   else if (strstr  (b_msg, "implicit declaration")   != NULL) { x_level = 'W';  x_quotes = ';'; strcpy  (x_msg, "no header for········"); }
   /*---(downgrades)---------------------*/
   else if (strstr  (b_msg, "unused variable" )       != NULL) { x_level = 'U';  x_quotes = 'y'; strcpy  (x_msg, "unused variable······");  }
   else if (strstr  (b_msg, "unused parameter")       != NULL) { x_level = 'U';  x_quotes = 'y'; strcpy  (x_msg, "unused parameter·····");  }
   else if (strstr  (b_msg, "unused function" )       != NULL) { x_level = 'U';  x_quotes = 'y'; strcpy  (x_msg, "unused function······");  }
   /*---(clarifies)----------------------*/
   else if (strstr  (b_msg, "undefined reference to") != NULL) {                 x_quotes = 'L'; strcpy  (x_msg, "undefined ref··>>>>>·"); }
   else if (strstr  (b_msg, "too few arguments to")   != NULL) {                 x_quotes = 'y'; strcpy  (x_msg, "too few args·to······"); }
   else if (strstr  (b_msg, "too many arguments to")  != NULL) {                 x_quotes = 'y'; strcpy  (x_msg, "too many args to·····"); }
   else if (strstr  (b_msg, "discards 'const'")       != NULL) {
      if   (strstr  (b_msg, "yLOG_") == NULL || c_ylog == 'y') {                 x_quotes = 'Y'; sprintf (x_msg, "discards const (%c)···", b_msg [17]); }
      else                                                     { x_level = '-'; }
   }
   /*---(yLOG)---------------------------*/
   /*> else if (strstr  (b_msg, "yLOG_enter"      )       != NULL) {  if (c_ylog == 'y')  x_level = 'w';  else  x_level = '-';  }   <* 
    *> else if (strstr  (b_msg, "yLOG_exit"       )       != NULL) {  if (c_ylog == 'y')  x_level = 'w';  else  x_level = '-';  }   <* 
    *> else if (strstr  (b_msg, "yLOG_exitr"      )       != NULL) {  if (c_ylog == 'y')  x_level = 'w';  else  x_level = '-';  }   <*/
   else if (strstr  (b_msg, "yLOG_"           )       != NULL) {  if (c_ylog == 'y')  x_level = 'w';  else  x_level = '-';  }
   /*---(replace-quotes)-----------------*/
   if (strchr ("y;", x_quotes) != NULL) {
      if (x_quotes == ';') {
         p = strrchr (b_msg, ';');
         if (p != NULL)  p [0] = '\0';
      }
      p = strrchr (b_msg, '\'');
      if (p != NULL) {
         p [0] = '\0';
         p = strrchr (b_msg, '\'');
         if (p != NULL) {
            p [0] = '·';
            strlcat (x_msg, p, LEN_RECD);
            if (b_msg   != NULL)  strlcpy (b_msg, x_msg, LEN_RECD);
         }
      }
   } else if (x_quotes == 'Y') {
      p = strchr (b_msg, '\'');
      if (p != NULL) {
         p [0] = '·';
         strlcat (x_msg, p, LEN_RECD);
         p = strchr (x_msg, '\'');
         if (p != NULL) {
            p [0] = '\0';
            if (b_msg   != NULL)  strlcpy (b_msg, x_msg, LEN_RECD);
         }
      }
   } else if (x_quotes == 'L') {
      p = strchr (b_msg, 'æ');
      if (p != NULL) {
         p [0] = '\0';
         p = strrchr (b_msg, 'å');
         if (p != NULL) {
            p [0] = '·';
            strlcat (x_msg, p, LEN_RECD);
            if (b_msg   != NULL)  strlcpy (b_msg, x_msg, LEN_RECD);
         }
      }
   }
   /*---(save-back)----------------------*/
   if (b_level != NULL)  *b_level = x_level;
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
GCC_parse               (char a_recd [LEN_RECD], short *b_count, char r_file [LEN_HUND], char *r_type, short *r_line, short *r_col, char *r_level, char r_msg [LEN_RECD], char r_flag [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *p           = NULL;
   char       *n           = NULL;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_file  != NULL)  strcpy (r_file, "");
   if (r_type  != NULL)  *r_type  =  '-';
   if (r_line  != NULL)  *r_line  =   -1;
   if (r_col   != NULL)  *r_col   =   -1;
   if (r_level != NULL)  *r_level =  '-';
   if (r_msg   != NULL)  strcpy (r_msg , "");
   if (r_flag  != NULL)  strcpy (r_flag, "");
   /*---(file)---------------------------*/
   p = a_recd;
   rc  = GCC__file    ('g', p, &n, r_type, r_file);
   DEBUG_HFIX  yLOG_value   ("file"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(line)---------------------------*/
   p = n;
   rc  = GCC__num     (p, &n, r_line);
   DEBUG_HFIX  yLOG_value   ("line"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(column)-------------------------*/
   p = n;
   rc  = GCC__num     (p, &n, r_col);
   DEBUG_HFIX  yLOG_value   ("column"    , rc);
   /*---(level)--------------------------*/
   p = n;
   rc  = GCC__level   (p, &n, r_level);
   DEBUG_HFIX  yLOG_value   ("level"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(message)------------------------*/
   p = n;
   rc  = GCC__msg     ('g', p, b_count, r_msg, r_flag);
   DEBUG_HFIX  yLOG_value   ("msg/flag"  , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(regrade)------------------------*/
   rc  = GCC__regrade (g_ylog, r_msg, r_level);
   DEBUG_HFIX  yLOG_value   ("regrade"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}


