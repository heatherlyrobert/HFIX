#include "HFIX.h"



/*====================------------------------------------====================*/
/*===----                    importing build status                    ----===*/
/*====================------------------------------------====================*/
static void  o___IMPORT__________o () { return; }

char
EXIM__import_time       (char a_line [LEN_FULL], long *r_rpid, long *r_cnt, long *r_beg, long *r_cur, long *r_end)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         l           =    0;
   char        x_label     [LEN_TERSE] = "";
   char       *x_pos       =    0;
   char        x_val       [LEN_LABEL] = "";
   long        p, n, b, c, e;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_rpid != NULL)     *r_rpid = 0;
   if (r_cnt  != NULL)     *r_cnt  = 0;
   if (r_beg  != NULL)     *r_beg  = 0;
   if (r_cur  != NULL)     *r_cur  = 0;
   if (r_end  != NULL)     *r_end  = 0;
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_point   ("a_line"    , a_line);
   --rce;  if (a_line == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("a_line"    , a_line);
   l = strlen (a_line);
   DEBUG_HFIX  yLOG_value   ("l"         , l);
   --rce;  if (l      <  86) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(rpid)---------------------------*/
   x_pos  = a_line;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("rpid"      , x_label);
   --rce;  if (strcmp (x_label, "pid=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   sprintf (x_val, "%10.10s", x_pos);
   DEBUG_HFIX  yLOG_info    ("x_val"     , x_val);
   p = atol (x_val);
   DEBUG_HFIX  yLOG_value   ("p"         , p);
   --rce;  if (p < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (p == 0 && strncmp (x_val, "0", 1) != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(count)--------------------------*/
   x_pos += 14;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("cnt"       , x_label);
   --rce;  if (strcmp (x_label, "cnt=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   sprintf (x_val, "%10.10s", x_pos);
   DEBUG_HFIX  yLOG_info    ("x_val"     , x_val);
   n = atol (x_val);
   DEBUG_HFIX  yLOG_value   ("n"         , n);
   --rce;  if (n < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (n == 0 && strncmp (x_val, "0", 1) != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(beg)----------------------------*/
   x_pos += 14;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("beg"       , x_label);
   --rce;  if (strcmp (x_label, "beg=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   sprintf (x_val, "%10.10s", x_pos);
   DEBUG_HFIX  yLOG_info    ("x_val"     , x_val);
   b = atol (x_val);
   DEBUG_HFIX  yLOG_value   ("b"         , b);
   --rce;  if (b < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (b == 0 && strncmp (x_val, "0", 1) != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(cur)----------------------------*/
   x_pos += 14;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("cur"       , x_label);
   --rce;  if (strcmp (x_label, "cur=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   sprintf (x_val, "%10.10s", x_pos);
   DEBUG_HFIX  yLOG_info    ("x_val"     , x_val);
   c = atol (x_val);
   DEBUG_HFIX  yLOG_value   ("c"         , c);
   --rce;  if (c < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (c == 0 && strncmp (x_val, "0", 1) != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(end)----------------------------*/
   x_pos += 14;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("end"       , x_label);
   --rce;  if (strcmp (x_label, "end=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   sprintf (x_val, "%10.10s", x_pos);
   DEBUG_HFIX  yLOG_info    ("x_val"     , x_val);
   e = atol (x_val);
   DEBUG_HFIX  yLOG_value   ("e"         , e);
   --rce;  if (e < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (e == 0 && strncmp (x_val, "0", 1) != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_rpid != NULL)     *r_rpid = p;
   if (r_cnt  != NULL)     *r_cnt  = n;
   if (r_beg  != NULL)     *r_beg  = b;
   if (r_cur  != NULL)     *r_cur  = c;
   if (r_end  != NULL)     *r_end  = e;
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 0;
}

char
EXIM__import_whoami     (char a_line [LEN_FULL], char r_whoami [LEN_LABEL], char r_ext [LEN_TERSE], char *r_done, char *r_status, char *r_result, char *r_error)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         l           =    0;
   char        x_label     [LEN_TERSE] = "";
   char        x_whoami    [LEN_LABEL] = "";
   char        x_ext       [LEN_TERSE] = "";
   char        x_done      =  '·';
   char        x_status    =  '·';
   char        x_result    =  '·';
   char        x_error     =  '·';
   char       *x_pos       = NULL;
   char       *p           = NULL;
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_whoami != NULL)     strcpy (r_whoami, "");
   if (r_ext    != NULL)     strcpy (r_ext   , "");
   if (r_done   != NULL)    *r_done   = '·';
   if (r_status != NULL)    *r_status = '·';
   if (r_result != NULL)    *r_result = '·';
   if (r_error  != NULL)    *r_error  = '·';
   /*---(defense)------------------------*/
   --rce;  if (a_line == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   l = strlen (a_line);
   --rce;  if (l      <  86) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(whoami)-------------------------*/
   x_pos  = a_line;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("who"       , x_label);
   --rce;  if (strcmp (x_label, "who=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   sprintf (x_whoami, "%14.14s", x_pos);
   DEBUG_HFIX  yLOG_info    ("x_whoami"  , x_whoami);
   p = strchr (x_whoami, ' ');
   --rce;  if (p == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   p [0] = '\0';
   l = strlen (x_whoami);
   --rce;  for (i = 0; i < l - 1; ++i) {
      if (strchr (YSTR_ALNUM, x_whoami [i]) == NULL) {
         DEBUG_HFIX  yLOG_note    ("bad character in name");
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   --rce;  if (x_whoami [l - 1] != '_') {
      DEBUG_HFIX  yLOG_note    ("no underscore at end");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(type)---------------------------*/
   x_pos += 14;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("ext"       , x_label);
   --rce;  if (strcmp (x_label, "ext=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   sprintf (x_ext   , "%9.9s"  , x_pos);
   DEBUG_HFIX  yLOG_info    ("x_ext"     , x_ext);
   p = strchr (x_ext   , ' ');
   --rce;  if (p == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   p [0] = '\0';
   --rce; if (strcmp (x_ext, ".c"       ) == 0)  ;
   else if   (strcmp (x_ext, ".unit"    ) == 0)  ;
   else {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
      
   /*---(done)---------------------------*/
   x_pos += 14;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("don"       , x_label);
   --rce;  if (strcmp (x_label, "don=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   x_done = x_pos [0];
   DEBUG_HFIX  yLOG_char    ("x_done"    , x_done);
   --rce;  if (strchr  ("Yy-", x_done) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(status)-------------------------*/
   x_pos += 11;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("sta"       , x_label);
   --rce;  if (strcmp (x_label, "sta=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   x_status = x_pos [0];
   DEBUG_HFIX  yLOG_char    ("x_status"  , x_status);
   /*---(result)-------------------------*/
   x_pos += 11;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("res"       , x_label);
   --rce;  if (strcmp (x_label, "res=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   x_result = x_pos [0];
   DEBUG_HFIX  yLOG_char    ("x_result"  , x_result);
   --rce;  if (strchr  ("Yy-rpWE?X", x_result) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(error)--------------------------*/
   x_pos += 11;
   strlcpy (x_label, x_pos, 5);
   DEBUG_HFIX  yLOG_info    ("err"       , x_label);
   --rce;  if (strcmp (x_label, "err=") != 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pos +=  4;
   x_error  = x_pos [0];
   DEBUG_HFIX  yLOG_char    ("x_error"   , x_error);
   --rce;  if (strchr  ("-y"      , x_error)  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_whoami != NULL)     strlcpy (r_whoami, x_whoami, LEN_LABEL);
   if (r_ext    != NULL)     strlcpy (r_ext   , x_ext   , LEN_TERSE);
   if (r_done   != NULL)    *r_done   = x_done;
   if (r_status != NULL)    *r_status = x_status;
   if (r_result != NULL)    *r_result = x_result;
   if (r_error  != NULL)    *r_error  = x_error;
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return 0;
}

char
EXIM__import_entries    (char a_line [LEN_FULL], char a_row, char r_table [MAX_ENTRY][LEN_DESC], char *b_count)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         l           =    0;
   char        x_col, x_pos;
   int         x_off       =    0;
   char        x_entry     [LEN_DESC]  = "";
   char        c           =    0;
   char        x_bad       =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (b_count != NULL)  c = *b_count;
   DEBUG_HFIX  yLOG_value   ("c"         , c);
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_point   ("a_line"    , a_line);
   --rce;  if (a_line == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   l = strlen (a_line);
   DEBUG_HFIX  yLOG_value   ("l"         , l);
   --rce;  if (l      <  86) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_point   ("r_table"   , r_table);
   --rce;  if (r_table == NULL)  {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check markers)------------------*/
   /*> --rce;  for (x_col = 0; x_col < 3; ++x_col) {                                  <* 
    *>    strlcpy (x_entry, a_line + (x_col * 30), 31);                               <* 
    *>    if (x_entry [18] != '·')  x_bad = 'y';                                      <* 
    *>    if (x_entry [20] != '·')  x_bad = 'y';                                      <* 
    *>    if (x_entry [22] != '·')  x_bad = 'y';                                      <* 
    *>    if (x_entry [26] != ' ')  x_bad = 'y';                                      <* 
    *>    if (x_entry [27] != ' ')  x_bad = 'y';                                      <* 
    *>    if (x_entry [28] != '')  x_bad = 'y';                                      <* 
    *>    if (x_entry [29] != ' ')  x_bad = 'y';                                      <* 
    *>    if (x_bad == 'y') {                                                         <* 
    *>       DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);                            <* 
    *>       return rce;                                                              <* 
    *>    }                                                                           <* 
    *> }                                                                              <* 
    *> rce += 21;                                                                     <*/
   /*---(handle entries)-----------------*/
   DEBUG_HFIX  yLOG_note    ("parse entries");
   DEBUG_HFIX  yLOG_value   ("a_row"     , a_row);
   for (x_col = 0; x_col < 3; ++x_col) {
      DEBUG_HFIX  yLOG_value   ("x_col"     , x_col);
      x_off = x_col * 30;
      DEBUG_HFIX  yLOG_value   ("x_off"     , x_off);
      strlcpy (x_entry, a_line + (x_col * 30), 31);
      DEBUG_HFIX  yLOG_info    ("x_entry"   , x_entry);
      x_pos = (a_row * 3) + x_col;
      DEBUG_HFIX  yLOG_value   ("x_pos"     , x_pos);
      strcpy (r_table [x_pos], x_entry);
      if (x_pos < MAX_ENTRY - 1 && x_entry [0] != '·') ++c;
      DEBUG_HFIX  yLOG_value   ("c"         , c);
   }
   /*---(save-back)----------------------*/
   if (b_count != NULL)  *b_count = c;
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return c;
}

char
EXIM_import             (char a_file [LEN_PATH])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        i           =    0;
   int         n           =    0;
   char        x_row       =    0;
   char        x_col       =    0;
   char        x_pos       =    0;
   char        x_line      [LEN_FULL]  = "";
   int         l           =    0;
   char        x_entry     [LEN_DESC]  = "";
   char        x_val       [LEN_LABEL] = "";
   char        c           =    0;
   FILE       *f           = NULL;
   char       *p           = NULL;
   char        x_top       =    9;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(defenses)-----------------------*/
   DEBUG_HFIX  yLOG_point   ("a_file"    , a_file);
   --rce;  if (a_file  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("a_file"    , a_file);
   /*---(open-file)----------------------*/
   --rce;  if (strcmp (a_file, "") != 0) {
      DEBUG_HFIX  yLOG_note    ("using a real file");
      f = fopen (a_file, "rt");
      DEBUG_HFIX  yLOG_point   ("f"         , f);
      if (f == NULL) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   } else {
      DEBUG_HFIX  yLOG_note    ("using stdin");
   }
   /*---(walk-records)-------------------*/
   for (i = 0; i < x_top; ++i) {
      if (f == NULL)  p = fgets (x_line, LEN_FULL, stdin);
      else            p = fgets (x_line, LEN_FULL, f);
      DEBUG_HFIX  yLOG_point   ("fgets"     , p);
      if (p == NULL) {
         DEBUG_HFIX  yLOG_note    ("read a null line, break");
         break;
      }
      DEBUG_HFIX  yLOG_info    ("fgets"     , p);
      l = strlen (x_line);
      DEBUG_HFIX  yLOG_value   ("l"         , l);
      if (x_line [l - 1] == '\n')  x_line [l - 1] = '\0';
      l = strlen (x_line);
      DEBUG_HFIX  yLOG_value   ("l"         , l);
      if (f != NULL && feof (f)) {
         DEBUG_HFIX  yLOG_note    ("read end-of-file");
         break;
      }
      if (strncmp (x_line, "HFIX·gcc/make·", 14) == 0) {
         DEBUG_HFIX  yLOG_note    ("ignore header");
         x_top = 10;
         continue;
      }
      rc = EXIM__import_entries (x_line, x_row, s_compile, &c);
      DEBUG_HFIX  yLOG_value   ("entries"   , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      ++x_row;
   }
   /*---(gather timings)-----------------*/
   if (f == NULL)  p = fgets (x_line, LEN_FULL, stdin);
   else            p = fgets (x_line, LEN_FULL, f);
   DEBUG_HFIX  yLOG_point   ("fgets"     , p);
   --rce;  if (p != NULL) {
      DEBUG_HFIX  yLOG_info    ("fgets"     , p);
      rc = EXIM__import_time  (x_line, &s_rpid, &s_cnt, &s_beg, &s_cur, &s_end);
      DEBUG_HFIX  yLOG_complex ("time"      , "%4drc, %6dr, %4dc, %10ldb, %10ldc, %10lde", rc, s_rpid, s_cnt, s_beg, s_cur, s_end);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(gather whoami)------------------*/
   if (f == NULL)  p = fgets (x_line, LEN_FULL, stdin);
   else            p = fgets (x_line, LEN_FULL, f);
   DEBUG_HFIX  yLOG_point   ("fgets"     , p);
   --rce;  if (p != NULL) {
      DEBUG_HFIX  yLOG_info    ("fgets"     , p);
      rc = EXIM__import_whoami (x_line, s_whoami, s_ext , &s_done, &s_status, &s_result, &s_error);
      DEBUG_HFIX  yLOG_complex ("whoami"    , "%4drc, %10.10s, %10.10s, %c, %c, %c, %c", rc, s_whoami, s_ext, s_done, s_status, s_result, s_error);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(close-file)---------------------*/
   --rce;  if (strcmp (a_file, "") != 0) {
      rc = fclose (f);
      DEBUG_HFIX  yLOG_value   ("rc"        , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return c;
}



/*====================------------------------------------====================*/
/*===----                    exporting build status                    ----===*/
/*====================------------------------------------====================*/
static void  o___EXPORT__________o () { return; }

char*
EXIM__export_time       (long a_rpid, long a_cnt, long a_beg, long a_cur, long a_end, char a_result)
{
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   sprintf  (g_print, "pid=%-10ld    cnt=%-10ld    beg=%-10ld    cur=%-10ld    end=%-10ld                                                                       [%c]", a_rpid, a_cnt, a_beg, a_cur, a_end, a_result);
   DEBUG_HFIX   yLOG_info    ("g_print"   , g_print);
   DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
   return g_print;
}

char*
EXIM__export_whoami     (char a_whoami [LEN_LABEL], char a_ext [LEN_TERSE], char a_done, char a_status, char a_result, char a_error)
{
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   sprintf  (g_print, "who=%-10.10s    ext=%-10.10s    don=%c ········ sta=%c ········ res=%c ········ err=%c                                                                       [%c]", a_whoami, a_ext, a_done, a_status, a_result, a_error, a_result);
   DEBUG_HFIX   yLOG_info    ("g_print"   , g_print);
   DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
   return g_print;
}

char
EXIM__export_list       (FILE *a_buf)
{
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *x_list      = NULL;
   char        x_line      [LEN_FULL]  = "";
   int         l           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   rc = yENV_exists (HFIX_LST);
   DEBUG_HFIX  yLOG_char    ("exists"    , rc);
   if (rc == '-')  {
      DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   x_list =  fopen (HFIX_LST, "rt");
   DEBUG_HFIX  yLOG_point   ("x_list"    , x_list);
   --rce;  if (x_list == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   while (1) {
      fgets (x_line, LEN_FULL, x_list);
      if (feof (x_list)) {
         DEBUG_HFIX  yLOG_note    ("reached end-of-file");
         break;
      }
      l = strlen (x_line);
      DEBUG_HFIX  yLOG_value   ("l"         , l);
      if (x_line [l - 1] == '\n')  x_line [l - 1] = '\0';
      DEBUG_HFIX  yLOG_info    ("fgets"     , x_line);
      if (a_buf == NULL)   printf  (       "%s\n", x_line);
      else                 fprintf (a_buf, "%s\n", x_line);
   }
   fclose (x_list);
   DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
EXIM_export             (char a_super, char a_result, char a_file [LEN_PATH])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        i           =    0;
   char        x_col, x_row;
   char        x_line      [LEN_FULL]  = "";
   FILE       *f           = NULL;
   char        x_result    =  '?';
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(defenses)-----------------------*/
   DEBUG_HFIX  yLOG_point   ("a_file"    , a_file);
   --rce;  if (a_file  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("a_file"    , a_file);
   /*---(check result)-------------------*/
   switch (a_result) {
   case '?'  : x_result = '?';  break;
   case '!'  : x_result = '?';  break;
   case 'p'  : x_result = 'p';  break;
   case 'E'  : x_result = 'E';  break;
   default   : x_result = 'W';  break;
   }
   /*---(open-file)----------------------*/
   if (strcmp (a_file, "") != 0) {
      f = fopen (a_file, "wt");
      DEBUG_HFIX  yLOG_point   ("f"         , f);
      --rce;  if (f == NULL) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   /*---(write title)--------------------*/
   if (f == NULL)  printf  (   "%s\n", SHOW_action (a_super, s_result));
   else            fprintf (f, "%s\n", SHOW_action (a_super, s_result));
   /*---(walk-records)-------------------*/
   for (i = 0; i <= MAX_ENTRY; ++i) {
      x_col = i % 3;
      x_row = (char) i / 3;
      DEBUG_HFIX   yLOG_complex ("loop"      , "%2dri, %2dc, %2dr", i, x_col, x_row);
      if (x_col == 0 && x_row > 0) {
         DEBUG_HFIX   yLOG_info    ("line"      , x_line);
         if (f == NULL)  printf  (   "%s                                                                   [%c]\n", x_line, s_result);
         else            fprintf (f, "%s                                                                   [%c]\n", x_line, s_result);
      }
      if (i >= MAX_ENTRY)  break;
      if (x_col == 0)  strlcpy (x_line, s_compile [i], LEN_FULL);
      else             strlcat (x_line, s_compile [i], LEN_FULL);
   }
   /*---(write timings)------------------*/
   if (f == NULL) printf  (   "%s\n", EXIM__export_time   (s_rpid, s_cnt, s_beg, s_cur, s_end, s_result));
   else           fprintf (f, "%s\n", EXIM__export_time   (s_rpid, s_cnt, s_beg, s_cur, s_end, s_result));
   /*---(identity)-----------------------*/
   if (f == NULL) printf  (   "%s\n", EXIM__export_whoami (s_whoami, s_ext , s_done, s_status, s_result, s_error));
   else           fprintf (f, "%s\n", EXIM__export_whoami (s_whoami, s_ext , s_done, s_status, s_result, s_error));
   /*---(export list)--------------------*/
   rc = EXIM__export_list (f);
   DEBUG_HFIX  yLOG_value   ("list"      , rc);
   /*---(close-file)---------------------*/
   if (strcmp (a_file, "") != 0) {
      rc = fclose (f);
      DEBUG_HFIX  yLOG_value   ("rc"        , rc);
      --rce;  if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(always wipe list file)-----------------*/
   rc = yENV_rm (HFIX_LST);
   DEBUG_HFIX  yLOG_char    ("remove"    , rc);
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
EXIM_trouble            (char a_file [LEN_PATH], char a_message [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        i           =    0;
   FILE       *f           = NULL;
   /*---(defenses)-----------------------*/
   DEBUG_HFIX  yLOG_point   ("a_file"    , a_file);
   --rce;  if (a_file  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_info    ("a_file"    , a_file);
   /*---(open-file)----------------------*/
   if (strcmp (a_file, "") != 0) {
      f = fopen (a_file, "wt");
      DEBUG_HFIX  yLOG_point   ("f"         , f);
      --rce;  if (f == NULL) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   /*---(write title)--------------------*/
   if (f == NULL)  printf  (   "%s\n", SHOW_action ('ÿ', '-'));
   else            fprintf (f, "%s\n", SHOW_action ('ÿ', '-'));
   /*---(build little gap)---------------*/
   if (f == NULL)  printf  (   "\n");
   else            fprintf (f, "\n");
   /*---(write message)------------------*/
   if (f == NULL)  printf  (   "   %-154.154s[E]\n", a_message);
   else            fprintf (f, "   %-154.154s[E]\n", a_message);
   /*---(close-file)---------------------*/
   if (strcmp (a_file, "") != 0) {
      rc = fclose (f);
      DEBUG_HFIX  yLOG_value   ("rc"        , rc);
      --rce;  if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

