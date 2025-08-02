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
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_next  != NULL)  *r_next = b_beg;
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
   /*---(save-back)----------------------*/
   if (r_next  != NULL)  *r_next = n + 1;
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
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
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
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
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   p = a_recd;
   /*---(line)---------------------------*/
   rc  = LD__wasted   (p, &n);
   DEBUG_HFIX  yLOG_value   ("wasted"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(file)---------------------------*/
   p = n;
   rc  = GCC__file    ('l', p, &n, r_type, r_file);
   DEBUG_HFIX  yLOG_value   ("file"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(message)------------------------*/
   p = n;
   rc  = GCC__msg     ('l', p, b_count, r_msg, r_flag);
   DEBUG_HFIX  yLOG_value   ("msg/flag"  , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(regrade)------------------------*/
   rc  = GCC__regrade (my.m_ylog, r_msg, r_level);
   DEBUG_HFIX  yLOG_value   ("regrade"   , rc);
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

