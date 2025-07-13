#include "HFIX.h"


char
MAKE__msg               (char a_type, char *b_beg, short *b_count, char r_msg [LEN_RECD], char r_flag [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *n           = NULL;
   int         l           =    0;
   int         x_count     =    0;
   char        x_msg       [LEN_RECD]  = "";
   char        x_flag      [LEN_HUND]  = "···";
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_msg   != NULL)  strcpy (r_msg , "");
   if (r_flag  != NULL)  strcpy (r_flag, "");
   /*---(defence)------------------------*/
   DEBUG_HFIX  yLOG_point   ("b_beg"     , b_beg);
   --rce;  if (b_beg  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("b_beg"     , b_beg);
   if (b_count != NULL)  x_count = *b_count;
   /*---(get object)---------------------*/
   if (b_beg [0] == ' ')  ++b_beg;
   n = strchr (b_beg, ']');
   --rce;  if (n == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n [0] = '\0';
   l = strlen (b_beg);
   --rce;  if (l < 3 || l >= LEN_HUND) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   switch (a_type) {
   case 'á' : strlcpy  (x_msg, "could not compile·····", LEN_RECD);  break;
   }
   strlcat (x_msg , b_beg, LEN_RECD);
   l = strlen (x_msg);
   DEBUG_HFIX  yLOG_complex ("MSG"       , "%3då%sæ\n", l, x_msg);
   /*---(error)--------------------------*/
   /*> n += 2;                                                                        <* 
    *> strlcpy (x_flag, n, LEN_HUND);                                                 <*/
   l = strlen (x_flag);
   DEBUG_HFIX  yLOG_complex ("FLAG"      , "%3då%sæ\n", l, x_flag);
   /*---(save-back)----------------------*/
   if (b_count != NULL)  *b_count = x_count + 1;
   if (r_msg   != NULL)  strlcpy (r_msg , x_msg , LEN_RECD);
   if (r_flag  != NULL)  strlcpy (r_flag, x_flag, LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
MAKE_parse              (char a_recd [LEN_RECD], short *b_count, char r_file [LEN_HUND], char *r_type, short *r_line, short *r_col, char *r_level, char r_msg [LEN_RECD], char r_flag [LEN_HUND], char *r_nada)
{
   /*---(design notes)-------------------*/
   /*
    *  make: *** [       is normal make linie
    *  make[1]: *** [    is recursively called
    *
    *
    */
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_pre       =   -1;
   char       *p           = NULL;
   char       *n           = NULL;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_file  != NULL)  strcpy (r_file, "");
   if (r_type  != NULL)  *r_type  =  '-';
   if (r_line  != NULL)  *r_line  =    0;
   if (r_col   != NULL)  *r_col   =    0;
   if (r_level != NULL)  *r_level =  '-';
   if (r_msg   != NULL)  strcpy (r_msg , "");
   if (r_flag  != NULL)  strcpy (r_flag, "");
   if (r_nada  != NULL)  *r_nada  =  '-';
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_point   ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   if (strstr (a_recd, "Nothing to be done for 'base'.") == 0) {
      if (r_nada  != NULL)  *r_nada  =  'y';
      if (r_level != NULL)  *r_level =  'm';
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(quick-out)----------------------*/
   --rce; if (strncmp (a_recd, "make:"         ,   5) == 0)   x_pre = 11;
   else if   (strncmp (a_recd, "make["         ,   5) == 0) {
      if      (a_recd [6] == ']')  x_pre = 14;
      else if (a_recd [7] == ']')  x_pre = 15;
   }
   if (x_pre <= 0) {
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   p = a_recd + x_pre;
   /*---(file)---------------------------*/
   rc  = GCC__file    ('m', p, &n, r_type, r_file);
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
   /*---(message)------------------------*/
   p = n;
   rc  = MAKE__msg    (*r_type, p, b_count, r_msg, r_flag);
   DEBUG_HFIX  yLOG_value   ("msg/flag"  , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_level != NULL)  *r_level = '!';
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}


