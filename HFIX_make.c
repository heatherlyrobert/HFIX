#include "HFIX.h"



char
MAKE_parse              (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, int *r_col, char *r_type, char r_msg [LEN_RECD], char r_flag [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_recd      [LEN_RECD]  = "";
   char       *p           = NULL;
   char       *n           = NULL;
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
   printf (x_recd);
   /*---(get file name)------------------*/
   n = strchr (p, ':');
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   l = strlen (p);
   --rce;  if (l < 3 || l >= LEN_HUND) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*> strlcpy (x_file, p, LEN_HUND);                                                 <*/
   strlcpy (x_file, "zeno_make······································", LEN_HUND);
   DEBUG_ARGS  yLOG_complex ("FILE"      , "%3då%sæ\n", l, x_file);
   p = n + 1;
   /*---(get line number)----------------*/
   n = strchr (p, ':');
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   l = strlen (p);
   --rce;  if (l < 1 || l > 5) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_line = atoi (p);
   DEBUG_ARGS  yLOG_value   ("LINE"      , x_line);
   p = n + 1;
   /*---(get object)---------------------*/
   n = strchr (p, ']');
   --rce;  if (n == NULL) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   ++p;
   l = strlen (p);
   --rce;  if (l < 3 || l >= LEN_HUND) {
      DEBUG_ARGS  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   strlcpy (x_msg , p, LEN_HUND);
   DEBUG_ARGS  yLOG_complex ("MSG"       , "%3då%sæ\n", l, x_msg);
   /*---(error)--------------------------*/
   p = n + 2;
   strlcpy (x_flag, p, LEN_HUND);
   l = strlen (x_flag);
   DEBUG_ARGS  yLOG_complex ("FLAG"      , "%3då%sæ\n", l, x_flag);
   ++x_count;
   /*---(save-back)----------------------*/
   if (b_count != NULL)  *b_count = *b_count + 1;
   if (r_file  != NULL)  strlcpy (r_file, x_file, LEN_HUND);
   if (r_line  != NULL)  *r_line  = x_line;
   if (r_col   != NULL)  *r_col   = 0;
   if (r_type  != NULL)  *r_type  = '!';
   if (r_msg   != NULL)  strlcpy (r_msg , x_msg , LEN_RECD);
   if (r_flag  != NULL)  strlcpy (r_flag, x_flag, LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
MAKE_collect            (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, char *r_type, char r_msg [LEN_RECD])
{
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return -1;
}

