#include "HFIX.h"



char
GCC__file               (char *b_beg, char **r_next, char *r_type, char r_file [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *n           = NULL;
   int         l           =    0;
   char        x_type      =  '-';
   char        x_file      [LEN_HUND]  = "";
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_next  != NULL)  *r_next = b_beg;
   if (r_type  != NULL)  *r_type = '-';
   if (r_file  != NULL)  strcpy (r_file, "");
   /*---(defence)------------------------*/
   DEBUG_PROG  yLOG_point   ("b_beg"     , b_beg);
   --rce;  if (b_beg  == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_info    ("b_beg"     , b_beg);
   DEBUG_PROG  yLOG_point   ("r_next"    , r_next);
   --rce;  if (r_next == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get file name)------------------*/
   n = strchr (b_beg , ':');
   DEBUG_PROG  yLOG_point   ("n"         , n);
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   l = strlen (b_beg);
   DEBUG_PROG  yLOG_value   ("l"         , l);
   --rce;  if (l < 3 || l >= LEN_HUND) {
      n [0] = ':';  /* put it back to original conditions */
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_info    ("b_beg"     , b_beg);
   /*---(convert)------------------------*/
   strlcpy (x_file, b_beg, LEN_HUND);
   DEBUG_ARGS  yLOG_complex ("FILE"      , "%3då%sæ", l, x_file);
   /*---(check file type)----------------*/
   DEBUG_PROG  yLOG_info    ("suffix"    , x_file + l - 2);
   --rce; if (l > 3 && strcmp (x_file + l - 2, ".c")     == 0)  x_type = 'c';
   else if   (l > 4 && strcmp (x_file + l - 3, ".cs")    == 0)  x_type = 'c';
   else if   (l > 3 && strcmp (x_file + l - 2, ".h")     == 0)  x_type = 'h';
   else if   (l > 6 && strcmp (x_file + l - 5, ".unit")  == 0)  x_type = 'u';
   else if   (l > 7 && strcmp (x_file + l - 6, ".munit") == 0)  x_type = 'm';
   else {
      n [0] = ':';  /* put it back to original conditions */
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_next  != NULL)  *r_next = n + 1;
   if (r_type  != NULL)  *r_type = x_type;
   if (r_file  != NULL)  strlcpy (r_file, x_file, LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
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
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_next  != NULL)  *r_next = b_beg;
   if (r_num   != NULL)  *r_num  = -1;
   /*---(defence)------------------------*/
   DEBUG_PROG  yLOG_point   ("b_beg"     , b_beg);
   --rce;  if (b_beg  == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_info    ("b_beg"     , b_beg);
   DEBUG_PROG  yLOG_point   ("r_next"    , r_next);
   --rce;  if (r_next == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get line number)----------------*/
   n = strchr (b_beg , ':');
   DEBUG_PROG  yLOG_point   ("n"         , n);
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   l = strlen (b_beg);
   DEBUG_PROG  yLOG_value   ("l"         , l);
   --rce;  if (l < 1 || l > 5) {
      n [0] = ':';  /* put it back to original conditions */
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_info    ("b_beg"     , b_beg);
   /*---(convert)------------------------*/
   x_num  = atoi (b_beg);
   DEBUG_PROG  yLOG_value   ("x_num"     , x_num);
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
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
GCC__level              (char *b_beg, char **r_next, char a_filter, char *r_type)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *n           = NULL;
   int         l           =    0;
   char        x_type      =  '-';
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_next  != NULL)  *r_next = b_beg;
   if (r_type  != NULL)  *r_type = '-';
   /*---(defence)------------------------*/
   DEBUG_PROG  yLOG_point   ("b_beg"     , b_beg);
   --rce;  if (b_beg  == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_info    ("b_beg"     , b_beg);
   DEBUG_PROG  yLOG_point   ("r_next"    , r_next);
   --rce;  if (r_next == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get type)-----------------------*/
   n = strchr (b_beg , ':');
   DEBUG_PROG  yLOG_point   ("n"         , n);
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   l = strlen (b_beg);
   DEBUG_PROG  yLOG_value   ("l"         , l);
   --rce;  if (l < 6 || l > 10) {
      n [0] = ':';  /* put it back to original conditions */
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_info    ("b_beg"     , b_beg);
   --rce; if  (strcmp (b_beg, " warning") == 0) {
      if (strchr ("Ww"  , a_filter) != NULL)  x_type = 'W';
      else {
         DEBUG_ARGS  yLOG_exit   (__FUNCTION__);
         return 0;
      }
   }
   else if    (strcmp (b_beg, " error"  ) == 0) {
      if (strchr ("EeWw", a_filter) != NULL)  x_type = 'E';
      else {
         DEBUG_ARGS  yLOG_exit   (__FUNCTION__);
         return 0;
      }
   }
   else {
      DEBUG_ARGS  yLOG_exitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_ARGS  yLOG_char    ("TYPE"      , x_type);
   /*---(save-back)----------------------*/
   if (r_next  != NULL)  *r_next = n + 1;
   if (r_type  != NULL)  *r_type = x_type;
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
GCC__msg                (char *b_beg, short *b_count, char r_msg [LEN_RECD], char r_flag [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *n           = NULL;
   int         l           =    0;
   int         x_count     =    0;
   char        x_msg       [LEN_RECD]  = "";
   char        x_flag      [LEN_HUND]  = "";
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_msg   != NULL)  strcpy (r_msg , "");
   if (r_flag  != NULL)  strcpy (r_flag, "");
   /*---(defence)------------------------*/
   DEBUG_PROG  yLOG_point   ("b_beg"     , b_beg);
   --rce;  if (b_beg  == NULL) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_PROG  yLOG_info    ("b_beg"     , b_beg);
   if (b_count != NULL)  x_count = *b_count;
   /*---(get message)--------------------*/
   if (b_beg [0] == ' ')  ++b_beg;
   strlcpy (x_msg , b_beg, LEN_RECD);
   n = strstr (x_msg, " [-W");
   if (n != NULL) {
      strlcpy (x_flag, n + 2, LEN_HUND);
      l = strlen (x_flag);
      if (x_flag [l - 1] == ']')  x_flag [l - 1] = '\0';
      n [0] = '\0';
      l = strlen (x_flag);
      DEBUG_ARGS  yLOG_complex ("FLAG"      , "%3då%sæ", l, x_flag);
   }
   l = strlen (x_msg);
   DEBUG_ARGS  yLOG_complex ("MSG"       , "%3då%sæ", l, x_msg);
   /*---(save-back)----------------------*/
   if (b_count != NULL)  *b_count = x_count + 1;
   if (r_msg   != NULL)  strlcpy (r_msg , x_msg , LEN_RECD);
   if (r_flag  != NULL)  strlcpy (r_flag, x_flag, LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
GCC__regrade            (char a_msg [LEN_RECD], char *b_level)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_level     =  '-';
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(save)---------------------------*/
   if (b_level != NULL)  x_level = *b_level;
   /*---(cut-out)------------------------*/
   --rce;  if (strncmp (a_msg, "'o___"       ,  5) == 0   ) {
      if (b_level != NULL)  *b_level = '-';
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(upgrades)-----------------------*/
   if (strstr  (a_msg, "no previous prototype") != NULL)  x_level = 'e';
   /*---(downgrades)---------------------*/
   if (strstr  (a_msg, "unused variable" )      != NULL)  x_level = 'U';
   if (strstr  (a_msg, "unused parameter")      != NULL)  x_level = 'U';
   if (strstr  (a_msg, "unused function" )      != NULL)  x_level = 'U';
   /*---(save-back)----------------------*/
   if (b_level != NULL)  *b_level = x_level;
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
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
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
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
   rc  = GCC__file    (p, &n, r_type, r_file);
   DEBUG_PROG  yLOG_value   ("file"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(line)---------------------------*/
   p = n;
   rc  = GCC__num     (p, &n, r_line);
   DEBUG_PROG  yLOG_value   ("line"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(column)-------------------------*/
   p = n;
   rc  = GCC__num     (p, &n, r_col);
   DEBUG_PROG  yLOG_value   ("column"    , rc);
   /*---(level)--------------------------*/
   p = n;
   rc  = GCC__level   (p, &n, g_filter, r_level);
   DEBUG_PROG  yLOG_value   ("level"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(message)------------------------*/
   p = n;
   rc  = GCC__msg     (p, b_count, r_msg, r_flag);
   DEBUG_PROG  yLOG_value   ("msg/flag"  , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(regrade)------------------------*/
   rc  = GCC__regrade (r_msg, r_level);
   DEBUG_PROG  yLOG_value   ("regrade"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

/*> char                                                                                                                                                                           <* 
 *> GCC_parse               (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, int *r_col, char *r_type, char r_msg [LEN_RECD], char r_flag [LEN_HUND])   <* 
 *> {                                                                                                                                                                              <* 
 *>    /+---(locals)-----------+-----+-----+-+/                                                                                                                                    <* 
 *>    char        rce         =  -10;                                                                                                                                             <* 
 *>    char        rc          =    0;                                                                                                                                             <* 
 *>    char        x_recd      [LEN_RECD]  = "";                                                                                                                                   <* 
 *>    char       *p           = NULL;                                                                                                                                             <* 
 *>    char       *n           = NULL;                                                                                                                                             <* 
 *>    int         i           =    0;                                                                                                                                             <* 
 *>    int         l           =    0;                                                                                                                                             <* 
 *>    int         x_count     =    0;                                                                                                                                             <* 
 *>    char        x_file      [LEN_HUND]  = "";                                                                                                                                   <* 
 *>    int         x_line      =    0;                                                                                                                                             <* 
 *>    int         x_col       =    0;                                                                                                                                             <* 
 *>    char        x_type      =  '-';                                                                                                                                             <* 
 *>    char        x_msg       [LEN_RECD]  = "";                                                                                                                                   <* 
 *>    char        x_flag      [LEN_HUND]  = "";                                                                                                                                   <* 
 *>    /+---(header)-------------------------+/                                                                                                                                    <* 
 *>    DEBUG_PROG  yLOG_enter   (__FUNCTION__);                                                                                                                                    <* 
 *>    /+---(default)------------------------+/                                                                                                                                    <* 
 *>    if (b_count != NULL)  x_count = *b_count;                                                                                                                                   <* 
 *>    if (r_file  != NULL)  strcpy (r_file, "");                                                                                                                                  <* 
 *>    if (r_line  != NULL)  *r_line = 0;                                                                                                                                          <* 
 *>    if (r_col   != NULL)  *r_col  = 0;                                                                                                                                          <* 
 *>    if (r_type  != NULL)  *r_type = '-';                                                                                                                                        <* 
 *>    if (r_msg   != NULL)  strcpy (r_msg , "");                                                                                                                                  <* 
 *>    if (r_flag  != NULL)  strcpy (r_flag, "");                                                                                                                                  <* 
 *>    /+---(defence)------------------------+/                                                                                                                                    <* 
 *>    --rce;  if (a_recd     == NULL)  return rce;                                                                                                                                <* 
 *>    --rce;  if (a_recd [0] == '\0')  return rce;                                                                                                                                <* 
 *>    --rce;  if (a_recd [0] == ' ')   return rce;                                                                                                                                <* 
 *>    l = strlen (a_recd);                                                                                                                                                        <* 
 *>    --rce;  if (l < 10)              return rce;                                                                                                                                <* 
 *>    /+---(prepare)------------------------+/                                                                                                                                    <* 
 *>    strlcpy (x_recd, a_recd, LEN_RECD);                                                                                                                                         <* 
 *>    p = x_recd;                                                                                                                                                                 <* 
 *>    /+---(get file name)------------------+/                                                                                                                                    <* 
 *>    n = strchr (p, ':');                                                                                                                                                        <* 
 *>    --rce;  if (n == NULL) {                                                                                                                                                    <* 
 *>       DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);                                                                                                                            <* 
 *>       return rce;                                                                                                                                                              <* 
 *>    }                                                                                                                                                                           <* 
 *>    n [0] = '\0';                                                                                                                                                               <* 
 *>    l = strlen (p);                                                                                                                                                             <* 
 *>    --rce;  if (l < 3 || l >= LEN_HUND) {                                                                                                                                       <* 
 *>       DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);                                                                                                                            <* 
 *>       return rce;                                                                                                                                                              <* 
 *>    }                                                                                                                                                                           <* 
 *>    strlcpy (x_file, p, LEN_HUND);                                                                                                                                              <* 
 *>    DEBUG_ARGS  yLOG_complex ("FILE"      , "%3då%sæ\n", l, x_file);                                                                                                            <* 
 *>    p = n + 1;                                                                                                                                                                  <* 
 *>    /+---(get line number)----------------+/                                                                                                                                    <* 
 *>    n = strchr (p, ':');                                                                                                                                                        <* 
 *>    --rce;  if (n == NULL) {                                                                                                                                                    <* 
 *>       DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);                                                                                                                            <* 
 *>       return rce;                                                                                                                                                              <* 
 *>    }                                                                                                                                                                           <* 
 *>    n [0] = '\0';                                                                                                                                                               <* 
 *>    l = strlen (p);                                                                                                                                                             <* 
 *>    --rce;  if (l < 1 || l > 5) {                                                                                                                                               <* 
 *>       DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);                                                                                                                            <* 
 *>       return rce;                                                                                                                                                              <* 
 *>    }                                                                                                                                                                           <* 
 *>    x_line = atoi (p);                                                                                                                                                          <* 
 *>    DEBUG_ARGS  yLOG_value   ("LINE"      , x_line);                                                                                                                            <* 
 *>    p = n + 1;                                                                                                                                                                  <* 
 *>    /+---(get column number)--------------+/                                                                                                                                    <* 
 *>    n = strchr (p, ':');                                                                                                                                                        <* 
 *>    --rce;  if (n == NULL) {                                                                                                                                                    <* 
 *>       DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);                                                                                                                            <* 
*>       return rce;                                                                                                                                                              <* 
*>    }                                                                                                                                                                           <* 
*>    n [0] = '\0';                                                                                                                                                               <* 
*>    l = strlen (p);                                                                                                                                                             <* 
*>    --rce;  if (l < 1 || l > 3) {                                                                                                                                               <* 
   *>       DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);                                                                                                                            <* 
      *>       return rce;                                                                                                                                                              <* 
      *>    }                                                                                                                                                                           <* 
      *>    x_col  = atoi (p);                                                                                                                                                          <* 
      *>    DEBUG_ARGS  yLOG_value   ("COL"       , x_col);                                                                                                                             <* 
      *>    p = n + 1;                                                                                                                                                                  <* 
      *>    /+---(get type)-----------------------+/                                                                                                                                    <* 
      *>    n = strchr (p, ':');                                                                                                                                                        <* 
      *>    --rce;  if (n == NULL) {                                                                                                                                                    <* 
         *>       DEBUG_ARGS  yLOG_exitr  (__FUNCTION__, rce);                                                                                                                             <* 
            *>       return rce;                                                                                                                                                              <* 
            *>    }                                                                                                                                                                           <* 
            *>    n [0] = '\0';                                                                                                                                                               <* 
            *>    l = strlen (p);                                                                                                                                                             <* 
            *>    --rce;  if (l < 3 || l >= LEN_LABEL) {                                                                                                                                      <* 
               *>       DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);                                                                                                                            <* 
                  *>       return rce;                                                                                                                                                              <* 
                  *>    }                                                                                                                                                                           <* 
                  *>    --rce; if  (strcmp (p, " warning") == 0 && strchr ("Ww"  , g_filter) != NULL)  x_type = 'W';                                                                                <* 
                  *>    else if    (strcmp (p, " error"  ) == 0 && strchr ("EeWw", g_filter) != NULL)  x_type = 'E';                                                                                <* 
                  *>    else {                                                                                                                                                                      <* 
                     *>       DEBUG_ARGS  yLOG_exitr  (__FUNCTION__, rce);                                                                                                                             <* 
                        *>       return rce;                                                                                                                                                              <* 
                        *>    }                                                                                                                                                                           <* 
                        *>    DEBUG_ARGS  yLOG_char    ("TYPE"      , x_type);                                                                                                                            <* 
                        *>    p = n + 1;                                                                                                                                                                  <* 
                        *>    /+---(get message)--------------------+/                                                                                                                                    <* 
                        *>    ++p;                                                                                                                                                                        <* 
                        *>    strlcpy (x_msg , p, LEN_RECD);                                                                                                                                              <* 
                        *>    n = strstr (x_msg, " [-W");                                                                                                                                                 <* 
                        *>    if (n != NULL) {                                                                                                                                                            <* 
                           *>       strlcpy (x_flag, n + 2, LEN_HUND);                                                                                                                                       <* 
                              *>       l = strlen (x_flag);                                                                                                                                                     <* 
                              *>       if (x_flag [l - 1] == ']')  x_flag [l - 1] = '\0';                                                                                                                       <* 
                              *>       n [0] = '\0';                                                                                                                                                            <* 
                              *>       l = strlen (x_flag);                                                                                                                                                     <* 
                              *>       DEBUG_ARGS  yLOG_complex ("FLAG"      , "%3då%sæ\n", l, x_flag);                                                                                                         <* 
                              *>    }                                                                                                                                                                           <* 
                              *>    l = strlen (x_msg);                                                                                                                                                         <* 
                              *>    DEBUG_ARGS  yLOG_complex ("MSG"       , "%3då%sæ\n", l, x_msg);                                                                                                             <* 
                              *>    ++x_count;                                                                                                                                                                  <* 
                              *>    /+---(cut-out)------------------------+/                                                                                                                                    <* 
                              *>    --rce;  if (strncmp (x_msg, "'o___"       ,  5) == 0   )  return rce;                                                                                                       <* 
                              *>    /+---(upgrades)-----------------------+/                                                                                                                                    <* 
                              *>    if (strstr (x_msg, "no previous prototype") != NULL)  x_type = 'e';                                                                                                         <* 
                              *>    /+---(downgrades)---------------------+/                                                                                                                                    <* 
                              *>    if (strstr  (x_msg, "unused variable" ) != NULL)  x_type = 'U';                                                                                                             <* 
                              *>    if (strstr  (x_msg, "unused parameter") != NULL)  x_type = 'U';                                                                                                             <* 
                              *>    if (strstr  (x_msg, "unused function" ) != NULL)  x_type = 'U';                                                                                                             <* 
                              *>    /+---(save-back)----------------------+/                                                                                                                                    <* 
                              *>    if (b_count != NULL)  *b_count = x_count;                                                                                                                                   <* 
                              *>    if (r_file  != NULL)  strlcpy (r_file, x_file, LEN_HUND);                                                                                                                   <* 
                              *>    if (r_line  != NULL)  *r_line  = x_line;                                                                                                                                    <* 
                              *>    if (r_col   != NULL)  *r_col   = x_col;                                                                                                                                     <* 
                              *>    if (r_type  != NULL)  *r_type  = x_type;                                                                                                                                    <* 
                              *>    if (r_msg   != NULL)  strlcpy (r_msg , x_msg , LEN_RECD);                                                                                                                   <* 
                              *>    if (r_flag  != NULL)  strlcpy (r_flag, x_flag, LEN_HUND);                                                                                                                   <* 
                              *>    /+---(complete)-----------------------+/                                                                                                                                    <* 
                              *>    DEBUG_PROG  yLOG_exit    (__FUNCTION__);                                                                                                                                    <* 
                              *>    return 1;                                                                                                                                                                   <* 
                              *> }                                                                                                                                                                              <*/
