#include "HFIX.h"



char
WIPE__prepare           (char c_pass, char c_desc [LEN_TERSE], char c_export, char c_maintset, FILE **b_file)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *f           = NULL;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (b_file     != NULL)  *b_file = NULL;
   /*---(remove old files)---------------*/
   rc = yENV_rm (HFIX_BUF);
   DEBUG_HFIX   yLOG_char    ("HFIX_BUF"   , rc);
   rc = yENV_rm (HFIX_LST);
   DEBUG_HFIX   yLOG_char    ("HFIX_LST"   , rc);
   /*---(prepare for recon)--------------*/
   if (c_pass == HFIX_RECON) {
      rc = BASE_starting ();
      DEBUG_HFIX    yLOG_note    ("starting fresh");
      rc = BASE_clear (c_desc);
      DEBUG_HFIX    yLOG_value   ("clear"     , rc);
      rc = MAINT__base  (c_maintset);
      DEBUG_HFIX    yLOG_value   ("base"      , rc);
   }
   /*---(open list file)-----------------*/
   DEBUG_HFIX   yLOG_char    ("c_export"   , c_export);
   if (c_export == 'y') {
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
   if (b_file     != NULL)  *b_file = f;
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
WIPE__finalize          (char c_super, char c_pass, int a_total, int a_count, int a_caution, llong a_all, llong a_wipe, char c_export, char c_unit, FILE **b_file)
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
   DEBUG_HFIX   yLOG_char    ("c_pass"     , c_pass);
   /*---(show remaining------------------*/
   if (c_pass == HFIX_RECON) {
      rc = BASE_size ('b', a_total - a_count - a_caution, a_all - a_wipe);
      DEBUG_HFIX    yLOG_value   ("base"      , rc);
   }
   /*---(show total)---------------------*/
   if (c_pass == HFIX_RECON) {
      rc = BASE_size ('t', a_total, a_all);
      DEBUG_HFIX    yLOG_value   ("total"     , rc);
      if (c_export == 'y')   BASE_done ('p');
   }
   /*---(check each one)-----------------*/
   if (c_pass == HFIX_EXEC) {
      DEBUG_HFIX    yLOG_note    ("compare recon, wipe, and verify details");
      strcpy (x_check, "·Û·");
      for (i = 0; i < MAX_ENTRY - 2; ++i) {
         rc = BASE_matching (i, &x_result);
         DEBUG_HFIX    yLOG_complex ("match"     , "%2d, %d, %c", i, rc, x_result);
      }
      BASE_done (x_result);
   }
   /*---(check totals)-------------------*/
   if (c_pass == HFIX_EXEC) {
      rc = BASE_matching (MAX_ENTRY - 1, &x_result);
      DEBUG_HFIX    yLOG_complex ("match"     , "%2d, %d, %c", MAX_ENTRY - 1, rc, x_result);
   }
   /*---(handle duration)----------------*/
   rc = BASE_finishing ();
   /*---(save-back)----------------------*/
   if (c_export == 'y' && b_file != NULL) {
      fclose (*b_file);
      *b_file = NULL;
   }
   /*---(export)-------------------------*/
   DEBUG_HFIX   yLOG_char    ("c_export"   , c_export);
   if (c_export == 'y') {
      if (c_unit == 'y')  rc = EXIM_export     (c_super, 'p', HFIX_BUF);
      else                rc = EXIM_export     (c_super, 'p', "");
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
WIPE_pass               (char c_super, char c_major, char c_minor, char c_phase, char c_unit)
{
   /*---(locals)-----------+-----+-----+-*/
   int         rc          =    0;
   char        rce         =  -10;
   /*---(context)------------------------*/
   char        x_whoami    [LEN_LABEL] = "";
   char        x_desc      [LEN_TERSE] = "";
   char        x_theme     =  '-';
   char        x_layout    =  '-';
   char        x_pass      =  '-';
   char        x_ext       [LEN_TERSE] = "";
   char        x_export    =  '-';
   char        x_maintset  =  '-';
   /*---(normal)-------------------------*/
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
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(precheck)-----------------------*/
   DEBUG_HFIX   yLOG_complex ("args"       , "%c, %c, %c, %c, %c", c_super, c_major, c_minor, c_phase, c_unit);
   rc = BASE_precheck (c_super, c_major, c_minor, c_phase, HFIX_NONE, x_whoami, x_desc, &x_theme, &x_layout, &x_pass, x_ext, &x_export, &x_maintset, c_unit);
   DEBUG_HFIX   yLOG_char    ("precheck"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_char    ("x_pass"     , x_pass);
   DEBUG_HFIX   yLOG_char    ("x_export"   , x_export);
   /*---(prepare)------------------------*/
   rc = WIPE__prepare (x_pass, x_desc, x_export, x_maintset, &f);
   DEBUG_HFIX   yLOG_value   ("prepare"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_point   ("f"          , f);
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
      rc = MAINT__identify (c_super, x_file->d_name, x_whoami, x_rule);
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
      if (x_pass == HFIX_RECON) {
         DEBUG_HFIX   yLOG_note    ("recon adds to totals");
         rc = BASE_increment (x_theme, x_rule, HFIX_RECON);
         DEBUG_HFIX   yLOG_value   ("increment" , rc);
      }
      /*----(wipe)-----------------------*/
      if (x_pass == HFIX_EXEC) {
         if (strchr ("Ww", c_super) != NULL) {
            if (strstr (x_rule, "CAUTION") == NULL) {
               DEBUG_HFIX   yLOG_note    ("wipe removes");
               rc = BASE_increment (x_theme, x_rule, HFIX_EXEC);
               rc = yENV_rm (x_file->d_name);
               if (rc == '-')   rc = BASE_increment (x_theme, x_rule, HFIX_VERIFY);
            } else {
               DEBUG_HFIX   yLOG_note    ("CAUTION item, must be hand deleted");
               rc = BASE_increment (x_theme, x_rule, HFIX_EXEC);
               rc = BASE_increment (x_theme, x_rule, HFIX_VERIFY);
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
   rc = WIPE__finalize (c_super, x_pass, x_total, x_count, x_caution, x_all, x_wipe, x_export, c_unit, &f);
   DEBUG_HFIX   yLOG_value   ("finalize"   , rc);
   /*---(complete)------------------------------*/
   DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
   return 1;
}


