#include "HFIX.h"



char
FILE_open               (char a_name [LEN_HUND], short *r_lines, short *r_accept, FILE **r_file)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   FILE       *f           = NULL;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default/save)-------------------*/
   if (r_lines  != NULL)   *r_lines  = 0;
   if (r_accept != NULL)   *r_accept = 0;
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("a_name"    , a_name);
   --rce;  if (a_name [0] == '\0') {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_point   ("r_file"    , r_file);
   --rce;  if (r_file  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_point   ("*r_file"   , *r_file);
   --rce;  if (*r_file != NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(open)---------------------------*/
   f = fopen (a_name, "rt");
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (f == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_file  != NULL)  *r_file = f;
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
FILE_close              (FILE **r_file)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_point   ("r_file"    , r_file);
   --rce;  if (r_file  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_point   ("*r_file"   , *r_file);
   --rce;  if (*r_file == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(close)--------------------------*/
   rc = fclose (*r_file);
   DEBUG_HFIX  yLOG_value   ("fclose"    , rc);
   --rce;  if (rc != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(ground)-------------------------*/
   if (r_file  != NULL)  *r_file = NULL;
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 1;
}

char
FILE_read               (FILE *f, short *b_lines, short *b_accept, char r_recd [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        rc_final    =    0;
   char        x_recd      [LEN_RECD]  = "";
   short       x_lines     =    0;
   short       x_accept    =    0;
   int         l           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(default/save)-------------------*/
   if (b_lines  != NULL)  x_lines  = *b_lines;
   if (b_accept != NULL)  x_accept = *b_accept;
   if (r_recd   != NULL)  strcpy (r_recd, "");
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (f == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce; if (feof (f)) {
      DEBUG_HFIX  yLOG_note    ("file already at end-of-file");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(walk-records)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      fgets (x_recd, LEN_RECD, f);
      if (feof (f)) {
         DEBUG_HFIX  yLOG_note    ("file reached end-of-file");
         rc_final = 0;
         break;
      }
      ++x_lines;
      /*---(fix)-------------------------*/
      l = strlen (x_recd);
      if (l > 0 && x_recd [l - 1] == '\n')  x_recd [--l] = '\0';
      DEBUG_HFIX  yLOG_complex ("x_recd"    , "%3då%sæ", l, x_recd);
      /*---(filter)----------------------*/
      if (l < 10) {
         DEBUG_HFIX  yLOG_note    ("too short");
         continue;
      }
      if (x_recd [0] == ' ') {
         DEBUG_HFIX  yLOG_note    ("starts with space");
         continue;
      }
      /*---(accept)----------------------*/
      ++x_accept;
      rc_final = 1;
      break;
      /*---(done)------------------------*/
   }
   /*---(save-back)----------------------*/
   if (b_lines  != NULL)  *b_lines  = x_lines;
   if (b_accept != NULL)  *b_accept = x_accept;
   if (r_recd   != NULL)  strlcpy (r_recd, x_recd, LEN_RECD);
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return rc_final;
}
