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
   char        x_val       [LEN_LABEL] = "";
   long        p, n, b, c, e;
   /*---(default)------------------------*/
   if (r_rpid != NULL)     *r_rpid = 0;
   if (r_cnt  != NULL)     *r_cnt  = 0;
   if (r_beg  != NULL)     *r_beg  = 0;
   if (r_cur  != NULL)     *r_cur  = 0;
   if (r_end  != NULL)     *r_end  = 0;
   /*---(defense)------------------------*/
   --rce;  if (a_line == NULL)                          return rce;
   l = strlen (a_line);
   --rce;  if (l      <  86)                            return rce;
   /*---(rpid)---------------------------*/
   --rce;  if (strncmp (a_line +  0, "pid=",  4) != 0)  return rce;
   sprintf (x_val, "%10.10s", a_line +  4);
   p = atol (x_val);
   --rce;  if (p < 0)                                   return rce;
   --rce;  if (p == 0 && strncmp (x_val, "0", 1) != 0)  return rce;
   /*---(count)--------------------------*/
   --rce;  if (strncmp (a_line + 18, "cnt=", 4) != 0)   return rce;
   sprintf (x_val, "%10.10s", a_line + 22);
   n = atol (x_val);
   --rce;  if (n < 0)                                   return rce;
   --rce;  if (n == 0 && strncmp (x_val, "0", 1) != 0)  return rce;
   /*---(beg)----------------------------*/
   --rce;  if (strncmp (a_line + 36, "beg=",  4) != 0)  return rce;
   sprintf (x_val, "%10.10s", a_line + 40);
   b = atol (x_val);
   --rce;  if (b < 0)                                   return rce;
   --rce;  if (b == 0 && strncmp (x_val, "0", 1) != 0)  return rce;
   /*---(cur)----------------------------*/
   --rce;  if (strncmp (a_line + 54, "cur=", 4) != 0)   return rce;
   sprintf (x_val, "%10.10s", a_line + 58);
   c = atol (x_val);
   --rce;  if (c < 0)                                   return rce;
   --rce;  if (c == 0 && strncmp (x_val, "0", 1) != 0)  return rce;
   /*---(end)----------------------------*/
   --rce;  if (strncmp (a_line + 72, "end=", 4) != 0)   return rce;
   sprintf (x_val, "%10.10s", a_line + 76);
   e = atol (x_val);
   --rce;  if (e < 0)                                   return rce;
   --rce;  if (e == 0 && strncmp (x_val, "0", 1) != 0)  return rce;
   /*---(save-back)----------------------*/
   if (r_rpid != NULL)     *r_rpid = p;
   if (r_cnt  != NULL)     *r_cnt  = n;
   if (r_beg  != NULL)     *r_beg  = b;
   if (r_cur  != NULL)     *r_cur  = c;
   if (r_end  != NULL)     *r_end  = e;
   /*---(complete)-----------------------*/
   return 0;
}

char
EXIM__import_whoami     (char a_line [LEN_FULL], char r_whoami [LEN_LABEL], char r_ext [LEN_TERSE], char *r_done)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         l           =    0;
   char        x_whoami    [LEN_LABEL] = "";
   char        x_ext       [LEN_TERSE] = "";
   char        x_done      =  '∑';
   char       *p           = NULL;
   int         i           =    0;
   /*---(default)------------------------*/
   if (r_whoami != NULL)     strcpy (r_whoami, "");
   if (r_ext    != NULL)     strcpy (r_ext   , "");
   if (r_done   != NULL)    *r_done  = '∑';
   /*---(defense)------------------------*/
   --rce;  if (a_line == NULL)                          return rce;
   l = strlen (a_line);
   --rce;  if (l      <  86)                            return rce;
   /*---(whoami)-------------------------*/
   --rce;  if (strncmp (a_line +  0, "who=",  4) != 0)  return rce;
   sprintf (x_whoami, "%14.14s", a_line +  4);
   p = strchr (x_whoami, ' ');
   --rce;  if (p == NULL)                               return rce;
   p [0] = '\0';
   l = strlen (x_whoami);
   for (i = 0; i < l; ++i) {
      if (strchr (YSTR_ALNUM, x_whoami [i]) == NULL)    return rce;
   }
   if (x_whoami [l - 1] != '_')                         return rce;
   /*---(type)---------------------------*/
   --rce;  if (strncmp (a_line + 18, "ext=",  4) != 0)  return rce;
   sprintf (x_ext   , "%9.9s"  , a_line + 22);
   p = strchr (x_ext   , ' ');
   --rce;  if (p == NULL)                               return rce;
   p [0] = '\0';
   --rce; if (strcmp (x_ext, ".c"       ) == 0)   ;
   else if   (strcmp (x_ext, ".unit"    ) == 0)   ;
   else                                                 return rce;
   /*---(done)---------------------------*/
   --rce;  if (strncmp (a_line + 36, "don=",  4) != 0)  return rce;
   x_done = a_line [40];
   --rce;  if (strchr  ("-Y", x_done) == NULL)          return rce;
   /*---(save-back)----------------------*/
   if (r_whoami != NULL)     strlcpy (r_whoami, x_whoami, LEN_LABEL);
   if (r_ext    != NULL)     strlcpy (r_ext   , x_ext   , LEN_TERSE);
   if (r_done   != NULL)    *r_done  = x_done;
   /*---(complete)-----------------------*/
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
    *>    if (x_entry [18] != '∑')  x_bad = 'y';                                      <* 
    *>    if (x_entry [20] != '∑')  x_bad = 'y';                                      <* 
    *>    if (x_entry [22] != '∑')  x_bad = 'y';                                      <* 
    *>    if (x_entry [26] != ' ')  x_bad = 'y';                                      <* 
    *>    if (x_entry [27] != ' ')  x_bad = 'y';                                      <* 
    *>    if (x_entry [28] != 'Å')  x_bad = 'y';                                      <* 
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
      if (x_pos < MAX_ENTRY - 1 && x_entry [0] != '∑') ++c;
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
   if (strcmp (a_file, "") != 0) {
      DEBUG_HFIX  yLOG_note    ("using a real file");
      f = fopen (a_file, "rt");
      DEBUG_HFIX  yLOG_point   ("f"         , f);
      --rce;  if (f == NULL) {
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
      if (strncmp (x_line, "HFIX∑gcc/make∑", 14) == 0) {
         DEBUG_HFIX  yLOG_note    ("ignore header");
         x_top = 10;
         continue;
      }
      rc = EXIM__import_entries (x_line, x_row, s_compile, &c);
      DEBUG_HFIX  yLOG_value   ("entries"   , rc);
      ++x_row;
   }
   /*---(gather timings)-----------------*/
   if (f == NULL)  p = fgets (x_line, LEN_FULL, stdin);
   else            p = fgets (x_line, LEN_FULL, f);
   DEBUG_HFIX  yLOG_point   ("fgets"     , p);
   if (p != NULL) {
      DEBUG_HFIX  yLOG_info    ("fgets"     , p);
      rc = EXIM__import_time  (x_line, &s_rpid, &s_cnt, &s_beg, &s_cur, &s_end);
      DEBUG_HFIX  yLOG_complex ("time"      , "%4drc, %6dr, %4dc, %10ldb, %10ldc, %10lde", rc, s_rpid, s_cnt, s_beg, s_cur, s_end);
   }
   /*---(gather whoami)------------------*/
   if (f == NULL)  p = fgets (x_line, LEN_FULL, stdin);
   else            p = fgets (x_line, LEN_FULL, f);
   DEBUG_HFIX  yLOG_point   ("fgets"     , p);
   if (p != NULL) {
      DEBUG_HFIX  yLOG_info    ("fgets"     , p);
      rc = EXIM__import_whoami (x_line, s_whoami, s_ext , &s_done);
      DEBUG_HFIX  yLOG_complex ("time"      , "%4drc, %10.10s, %10.10s, %c", rc, s_whoami, s_ext, s_done);
   }
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
   return c;
}



/*====================------------------------------------====================*/
/*===----                    exporting build status                    ----===*/
/*====================------------------------------------====================*/
static void  o___EXPORT__________o () { return; }

char*
EXIM__export_time       (long a_rpid, long a_cnt, long a_beg, long a_cur, long a_end)
{
   sprintf  (g_print, "pid=%-10ld    cnt=%-10ld    beg=%-10ld    cur=%-10ld    end=%-10ld                                                                       [?]", a_rpid, a_cnt, a_beg, a_cur, a_end);
   return g_print;
}

char*
EXIM__export_whoami     (char a_whoami [LEN_LABEL], char a_ext [LEN_TERSE], char a_done)
{
   sprintf  (g_print, "who=%-10.10s    ext=%-10.10s    don=%c                                                                                                                    [?]", a_whoami, a_ext, a_done);
   return g_print;
}

char
EXIM_export             (char a_file [LEN_PATH])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        i           =    0;
   char        x_col, x_row;
   char        x_line      [LEN_FULL]  = "";
   FILE       *f           = NULL;
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
   if (strcmp (a_file, "") != 0) {
      f = fopen (a_file, "wt");
      DEBUG_HFIX  yLOG_point   ("f"         , f);
      --rce;  if (f == NULL) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   /*---(walk-records)-------------------*/
   for (i = 0; i <= MAX_ENTRY; ++i) {
      x_col = i % 3;
      x_row = (char) i / 3;
      DEBUG_HFIX   yLOG_complex ("loop"      , "%2dri, %2dc, %2dr", i, x_col, x_row);
      if (x_col == 0 && x_row > 0) {
         DEBUG_HFIX   yLOG_info    ("line"      , x_line);
         if (f == NULL)  printf  (   "%s                                                                   [?]\n", x_line);
         else            fprintf (f, "%s                                                                   [?]\n", x_line);
      }
      if (i >= MAX_ENTRY)  break;
      if (x_col == 0)  strlcpy (x_line, s_compile [i], LEN_FULL);
      else             strlcat (x_line, s_compile [i], LEN_FULL);
   }
   /*---(write timings)------------------*/
   if (f == NULL) {
      printf  (   "%s\n", EXIM__export_time   (s_rpid, s_cnt, s_beg, s_cur, s_end));
   } else {
      fprintf (f, "%s\n", EXIM__export_time   (s_rpid, s_cnt, s_beg, s_cur, s_end));
   }
   /*---(identity)-----------------------*/
   if (f == NULL) {
      printf  (   "%s\n", EXIM__export_whoami (s_whoami, s_ext , s_done));
   } else {
      fprintf (f, "%s\n", EXIM__export_whoami (s_whoami, s_ext , s_done));
   }
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


