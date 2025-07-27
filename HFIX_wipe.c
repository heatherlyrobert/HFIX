#include "HFIX.h"



char
WIPE__prepare           (char c_super, char c_action, char *r_export, char *r_style, FILE **b_file)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *f           = NULL;
   char        x_export    =  '-';
   char        x_style     =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_export   != NULL)  *r_export = '-';
   if (b_file     != NULL)  *b_file = NULL;
   /*---(list making)--------------------*/
   DEBUG_HFIX   yLOG_char    ("c_super"    , c_super);
   DEBUG_HFIX   yLOG_char    ("c_action"   , c_action);
   if (c_super == 'w' && c_action == 'r')  x_export = 'y';
   if (c_super == 'W' && c_action == 'w')  x_export = 'y';
   if (c_super == 'i' && c_action == 'r')  x_export = 'y';
   if (c_super == 'I' && c_action == 'w')  x_export = 'y';
   if (c_super == 'r' && c_action == 'r')  x_export = 'y';
   if (c_super == 'R' && c_action == 'w')  x_export = 'y';
   DEBUG_HFIX   yLOG_char    ("x_export"   , x_export);
   /*---(set style)----------------------*/
   --rce;  switch (c_super) {
   case 'w' : case 'W':  x_style = 'w';  break;
   case 'i' : case 'I':  x_style = 'i';  break;
   case 'r' : case 'R':  x_style = 'r';  break;
   case 'm' : case 'M':  x_style = 'm';  break;
   default  :
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_char    ("x_style"    , x_style);
   /*---(remove old files)---------------*/
   rc = yENV_rm (HFIX_BUF);
   DEBUG_HFIX   yLOG_char    ("HFIX_BUF"   , rc);
   rc = yENV_rm (HFIX_LST);
   DEBUG_HFIX   yLOG_char    ("HFIX_LST"   , rc);
   /*---(prepare for recon)--------------*/
   if (c_action == 'r') {
      DEBUG_HFIX    yLOG_note    ("starting fresh");
      rc = COMP__clear ("wipe");
      DEBUG_HFIX    yLOG_value   ("clear"     , rc);
      s_beg  = time (NULL);
      DEBUG_HFIX    yLOG_value   ("s_beg"     , s_beg);
      rc = MAINT__base  (x_style);
      DEBUG_HFIX    yLOG_value   ("base"      , rc);
   }
   /*---(open list file)-----------------*/
   if (x_export == 'y') {
      DEBUG_HFIX    yLOG_note    ("openning list file");
      f = fopen (HFIX_LST, "wt");
      DEBUG_HFIX   yLOG_point   ("f"          , f);
      --rce;  if (f == NULL) {
         DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
         return  rce;
      }
   } else {
      DEBUG_HFIX    yLOG_note    ("not openning list file");
   }
   /*---(save-back)----------------------*/
   if (r_export   != NULL)  *r_export = x_export;
   if (b_file     != NULL)  *b_file = f;
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
WIPE__finalize          (char c_super, char c_action, int a_total, int a_count, int x_caution, llong a_all, llong a_wipe, char c_unit, char a_export, FILE **b_file)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        i           =    0;
   char        x_bit       [LEN_DESC]  = "";
   char        x_key       [LEN_TERSE] = "";
   char        x_cmp       [LEN_TERSE] = "";
   char        x_result    =  'p';
   char       *f           = NULL;
   char        x           =    0;
   char        x_check     [LEN_TERSE] = "·Û·";
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   DEBUG_HFIX   yLOG_char    ("c_super"    , c_super);
   DEBUG_HFIX   yLOG_char    ("c_action"   , c_action);
   DEBUG_HFIX   yLOG_char    ("a_export"   , a_export);
   /*---(show remaining------------------*/
   if (c_action == 'r') {
      sprintf (x_bit, "%4db·%4s· Œ ", a_total - a_count - x_caution, HFIX_size (a_all - a_wipe));
      if (x_bit [0] == ' ')  x_bit [0] = '·';
      if (x_bit [1] == ' ')  x_bit [1] = '·';
      if (x_bit [2] == ' ')  x_bit [2] = '·';
      if (x_bit [3] == ' ')  x_bit [3] = '·';
      DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
      for (i = 0; i < 14; ++i)  s_compile [MAX_ENTRY - 2][ 1 + i] = x_bit [i];
   }
   /*---(show total)---------------------*/
   if (c_action == 'r') {
      sprintf (x_bit, "%4dt·%4s", a_total, HFIX_size (a_all));
      if (x_bit [0] == ' ')  x_bit [0] = '·';
      if (x_bit [1] == ' ')  x_bit [1] = '·';
      if (x_bit [2] == ' ')  x_bit [2] = '·';
      if (x_bit [3] == ' ')  x_bit [3] = '·';
      DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
      for (i = 0; i < 10; ++i)  s_compile [MAX_ENTRY - 2][15 + i] = x_bit [i];
   }
   /*---(check each one)-----------------*/
   if (c_action == 'w') {
      DEBUG_HFIX    yLOG_note    ("compare recon, wipe, and verify details");
      strcpy (x_check, "·Û·");
      for (i = 0; i < MAX_ENTRY - 2; ++i) {
         /*---(check)--------------------*/
         DEBUG_HFIX    yLOG_value   ("i"         , i);
         if (s_compile [i][0] == '·')  continue;
         /*---(get recon)----------------*/
         strlcpy (x_key, s_compile [i] + 15, 3);
         DEBUG_HFIX    yLOG_info    ("x_key"     , x_key);
         /*---(check wipe)---------------*/
         strlcpy (x_cmp, s_compile [i] + 19, 3);
         DEBUG_HFIX    yLOG_info    ("x_cmp"     , x_cmp);
         if (strcmp (x_cmp, "·Ï") != 0) {
            if (strcmp (x_key, x_cmp) != 0)  x_result = 'E';
            else { for (x = 0; x < 3; ++x)  s_compile [i][19 + x] = x_check [x]; }
            DEBUG_HFIX    yLOG_char    ("x_result"  , x_result);
         }
         /*---(check verify)-------------*/
         strlcpy (x_cmp, s_compile [i] + 23, 3);
         DEBUG_HFIX    yLOG_info    ("x_cmp"     , x_cmp);
         if (strcmp (x_cmp, "·Ï") != 0) {
            if (strcmp (x_key, x_cmp) != 0)  x_result = 'E';
            else { for (x = 0; x < 3; ++x)  s_compile [i][23 + x] = x_check [x]; }
            DEBUG_HFIX    yLOG_char    ("x_result"  , x_result);
         }
         /*---(done)---------------------*/
      }
      s_done   = 'Y';
      s_result = x_result;
   }
   /*---(check totals)-------------------*/
   if (c_action == 'w') {
      strcpy (x_check, "··Û·");
      /*---(get recon)-------------------*/
      strlcpy (x_key, s_compile [MAX_ENTRY - 1] +  6, 4);
      DEBUG_HFIX    yLOG_info    ("x_key"     , x_key);
      /*---(check wipe)---------------*/
      strlcpy (x_cmp, s_compile [MAX_ENTRY - 1] + 11, 4);
      DEBUG_HFIX    yLOG_info    ("x_cmp"     , x_cmp);
      if (strcmp (x_key, x_cmp) != 0)  ; /* x_result = 'E'; */
      else { for (x = 0; x < 4; ++x)  s_compile [MAX_ENTRY - 1][11 + x] = x_check [x]; }
      /*---(check verify)-------------*/
      strlcpy (x_cmp, s_compile [MAX_ENTRY - 1] + 16, 4);
      DEBUG_HFIX    yLOG_info    ("x_cmp"     , x_cmp);
      if (strcmp (x_key, x_cmp) != 0)  ; /* x_result = 'E'; */
      else { for (x = 0; x < 4; ++x)  s_compile [MAX_ENTRY - 1][16 + x] = x_check [x]; }
      DEBUG_HFIX    yLOG_char    ("x_result"  , x_result);
   }
   /*---(handle duration)----------------*/
   s_end  = time (NULL);
   DEBUG_HFIX    yLOG_value   ("s_end"     , s_end);
   strcpy (x_bit, HFIX_age (s_beg, s_end));
   for (i = 0; i < 3; ++i) s_compile [MAX_ENTRY - 1][23 + i] = x_bit [i];
   /*---(save-back)----------------------*/
   if (a_export == 'y' && b_file != NULL) {
      fclose (*b_file);
      *b_file = NULL;
   }
   /*---(export)-------------------------*/
   if (a_export == 'y') {
      if (c_unit == 'y')  rc = EXIM_export     ('w', 'p', HFIX_BUF);
      else                rc = EXIM_export     ('w', 'p', "");
      DEBUG_HFIX    yLOG_value   ("export"    , rc);
   }
   /*---(save-back)----------------------*/
   rc = yENV_rm (HFIX_LST);
   DEBUG_HFIX   yLOG_char    ("HFIX_LST"   , rc);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
WIPE_pass               (char c_super, char c_action, char c_unit)
{
   /*---(locals)-----------+-----+-----+-*/
   int         rc          =    0;
   char        rce         =  -10;
   DIR        *x_dir       = NULL;
   tDIRENT    *x_file      = NULL;
   int         x_total     =    0;
   int         x_count     =    0;
   int         x_caution   =    0;
   char        x_rule      [LEN_LABEL] = "";
   char        i           =    0;
   char        x_bit       [LEN_DESC]  = "";
   long        x_size      =    0;
   llong       x_all       =    0;
   llong       x_wipe      =    0;
   FILE       *f           = NULL;
   char        x_export    =  '-';
   char        x_style     =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   rc = WIPE__prepare (c_super, c_action, &x_export, &x_style, &f);
   DEBUG_HFIX   yLOG_value   ("prepare"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_char    ("x_export"   , x_export);
   DEBUG_HFIX   yLOG_char    ("x_style"    , x_style);
   /*---(open dir)-----------------------*/
   x_dir = opendir(".");
   DEBUG_HFIX   yLOG_point   ("x_dir"      , x_dir);
   --rce;  if (x_dir == NULL) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_note    ("openned successfully");
   /*---(process entries)----------------*/
   DEBUG_HFIX   yLOG_note    ("processing entries");
   while (1) {
      /*---(read a directory entry)------*/
      x_file = readdir (x_dir);
      DEBUG_HFIX   yLOG_point   ("x_file"    , x_file);
      if (x_file == NULL) {
         DEBUG_HFIX   yLOG_note    ("null files means end of directory entries");
         break;
      }
      rc = yENV_size (x_file->d_name, &x_size);
      DEBUG_HFIX   yLOG_complex ("LOOP"      , "%3dt, %3dc, %c, %-30.30s, %ld", x_total, x_count, rc, x_file->d_name, x_size);
      if (rc != 'r') {
         DEBUG_HFIX   yLOG_note    ("ignore non-regular files");
         continue;
      }
      ++x_total;
      x_all  += x_size;
      /*----(filtering)------------------*/
      rc = MAINT__identify (c_super, x_file->d_name, s_whoami, x_rule);
      DEBUG_HFIX   yLOG_value   ("identify"  , rc);
      if (rc <= 0) {
         DEBUG_HFIX   yLOG_note    ("file not identified for removal");
         if (x_export == 'y') {
            DEBUG_HFIX   yLOG_note    ("export non-selected to list");
            fprintf (f, "%3d ---  ·  %-30.30s  ----------\n", x_total, x_file->d_name);
         }
         continue;
      }
      DEBUG_HFIX   yLOG_info    ("x_rule"    , x_rule);
      ++x_count;
      x_wipe += x_size;
      if (x_export == 'y') {
         DEBUG_HFIX   yLOG_note    ("export selected to list");
         fprintf (f, "%3d %3d  >  %-30.30s  %s\n", x_total, x_count, x_file->d_name, x_rule);
      }
      /*----(recon)----------------------*/
      if (c_action == 'r') {
         DEBUG_HFIX   yLOG_note    ("recon adds to totals");
         rc = MAINT__increment (c_action, x_rule, 'r');
         DEBUG_HFIX   yLOG_value   ("increment" , rc);
      }
      /*----(wipe)-----------------------*/
      if (c_action == 'w') {
         if (strchr ("Ww", c_super) != NULL) {
            if (strstr (x_rule, "CAUTION") == NULL) {
               DEBUG_HFIX   yLOG_note    ("wipe removes");
               rc = MAINT__increment (c_action, x_rule, 'w');
               rc = yENV_rm (x_file->d_name);
               if (rc == '-')   rc = MAINT__increment (c_action, x_rule, 'v');
            } else {
               DEBUG_HFIX   yLOG_note    ("CAUTION item, must be hand deleted");
               rc = MAINT__increment (c_action, x_rule, 'w');
               rc = MAINT__increment (c_action, x_rule, 'v');
               --x_count;
               x_wipe -= x_size;
               ++x_caution;
            }
         } else if (strchr ("Ii", c_super) != NULL) {
            DEBUG_HFIX   yLOG_note    ("install action not implemented yet");
         } else if (strchr ("Rr", c_super) != NULL) {
            DEBUG_HFIX   yLOG_note    ("remove action not implemented yet");
         } else {
            DEBUG_HFIX   yLOG_note    ("unknow c_super");
         }
      }
      /*---(done)------------------------*/
   }
   DEBUG_HFIX   yLOG_value   ("x_total"   , x_total);
   DEBUG_HFIX   yLOG_value   ("x_count"   , x_count);
   DEBUG_HFIX   yLOG_value   ("x_caution" , x_caution);
   /*---(close dir)----------------------*/
   DEBUG_HFIX   yLOG_note    ("closing directory");
   rc = closedir (x_dir);
   DEBUG_HFIX   yLOG_value   ("close_rc"  , rc);
   /*---(show remaining-------------------------*/
   rc = WIPE__finalize (c_super, c_action, x_total, x_count, x_caution, x_all, x_wipe, c_unit, x_export, &f);
   DEBUG_HFIX   yLOG_value   ("finalize"   , rc);
   /*---(complete)------------------------------*/
   DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
   return 1;
}


