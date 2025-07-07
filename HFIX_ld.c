#include "HFIX.h"



char
LD__wasted              (char *b_beg, char **r_next)
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
   /*---(save-back)----------------------*/
   if (r_next  != NULL)  *r_next = n + 1;
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
LD_parse                (char a_recd [LEN_RECD], short *b_count, char r_file [LEN_HUND], char *r_type, short *r_line, short *r_col, char *r_level, char r_msg [LEN_RECD], char r_flag [LEN_HUND])
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
   if (r_type  != NULL)  *r_type  =  'á';
   if (r_line  != NULL)  *r_line  =    0;
   if (r_col   != NULL)  *r_col   =    0;
   if (r_level != NULL)  *r_level =  '-';
   if (r_msg   != NULL)  strcpy (r_msg , "");
   if (r_flag  != NULL)  strcpy (r_flag, "");
   /*---(quick-out)----------------------*/
   if (strncmp (a_recd, "/usr/libexec/gcc/",  16) != 0) {
      DEBUG_PROG  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   p = a_recd;
   /*---(line)---------------------------*/
   rc  = LD__wasted   (p, &n);
   DEBUG_PROG  yLOG_value   ("wasted"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(file)---------------------------*/
   p = n;
   rc  = GCC__file    ('l', p, &n, r_type, r_file);
   DEBUG_PROG  yLOG_value   ("file"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(message)------------------------*/
   p = n;
   rc  = GCC__msg     ('l', p, b_count, r_msg, r_flag);
   DEBUG_PROG  yLOG_value   ("msg/flag"  , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_level != NULL)  *r_level = '!';
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
LD_parse_OLD            (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, int *r_col, char *r_type, char r_msg [LEN_RECD], char r_flag [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_recd      [LEN_RECD]  = "";
   char       *p           = NULL;
   char       *n           = NULL;
   char       *s           = NULL;
   int         i           =    0;
   int         l           =    0;
   int         x_count     =    0;
   char        x_file      [LEN_HUND]  = "";
   int         x_line      =    0;
   int         x_col       =    0;
   char        x_type      =  '-';
   char        x_msg       [LEN_RECD]  = "";
   char        x_flag      [LEN_HUND]  = "";
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (b_count != NULL)  x_count = *b_count;
   if (r_file  != NULL)  strcpy (r_file, "");
   if (r_line  != NULL)  *r_line = 0;
   if (r_col   != NULL)  *r_col  = 0;
   if (r_type  != NULL)  *r_type = '-';
   if (r_msg   != NULL)  strcpy (r_msg , "");
   if (r_flag  != NULL)  strcpy (r_flag, "");
   /*---(defence)------------------------*/
   --rce;  if (a_recd == NULL)  return rce;
   strlcpy (x_recd, a_recd, LEN_RECD);
   p = x_recd;
   /*---(wasted)-------------------------*/
   n = strchr (p, ':');
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   p = n + 1;
   /*---(source)-------------------------*/
   n = strchr (p, ':');
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   s = strrchr (p, '/');
   if (s != NULL) {
      s [0] = '\0';
      p = s + 1;
   }
   l = strlen (p);
   --rce;  if (l < 3 || l >= LEN_HUND) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   strlcpy (x_file, p, LEN_HUND);
   DEBUG_ARGS  yLOG_complex ("FILE"      , "%3då%sæ\n", l, x_file);
   p = n + 1;
   /*---(get message)--------------------*/
   ++p;
   strlcpy (x_msg , p, LEN_RECD);
   l = strlen (x_msg);
   DEBUG_ARGS  yLOG_complex ("MSG"       , "%3då%sæ\n", l, x_msg);
   p = strchr (x_msg, '`');
   if (p != NULL)   p [0] = 'å';
   p = strchr (x_msg, '\'');
   if (p != NULL)   p [0] = 'æ';
   ++x_count;
   /*---(save-back)----------------------*/
   if (b_count != NULL)  *b_count = x_count;
   if (r_file  != NULL)  strlcpy (r_file, x_file, LEN_HUND);
   if (r_line  != NULL)  *r_line  = -1;
   if (r_col   != NULL)  *r_col   = -1;
   if (r_type  != NULL)  *r_type  = '!';
   if (r_msg   != NULL)  strlcpy (r_msg , x_msg , LEN_RECD);
   if (r_flag  != NULL)  strlcpy (r_flag, "", LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

