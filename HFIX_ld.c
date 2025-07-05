#include "HFIX.h"




char
LD_parse                (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, int *r_col, char *r_type, char r_msg [LEN_RECD], char r_flag [LEN_HUND])
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
