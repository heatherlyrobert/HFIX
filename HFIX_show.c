#include "HFIX.h"



char*        /*-> two-char, upper-case hint ----------------------------------*/
SHOW_hint               (int n)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         x_max       =    0;
   int         x_major     =    0;
   int         x_minor     =    0;
   char       *x_valid     = YSTR_UPPER;
   static char x_hint      [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   strcpy (x_hint, "··");
   /*---(defense)------------------------*/
   x_max = 26 * 26;
   --rce;  if (n <  0)      return "··";
   --rce;  if (n >= x_max)  return "´´";
   /*---(build major)--------------------*/
   x_major = n / 26;
   x_hint [0] = x_valid [x_major];
   /*---(build minor)--------------------*/
   x_minor = n - (x_major * 26);
   x_hint [1] = x_valid [x_minor];
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_sexit   (__FUNCTION__);
   return x_hint;
}

char
SHOW_num                (int a_num, int a_max, char r_out [LEN_TERSE])
{
   char        x_out       [LEN_TERSE] = "°";
   char        t           [LEN_LABEL] = "";
   char        i           =    0;
   int         l           =    0;
   DEBUG_HFIX  yLOG_senter  (__FUNCTION__);
   if (r_out != NULL)  strlcpy (r_out, x_out, LEN_TERSE);
   sprintf (t, "%d", a_num);
   l = strlen (t);
   if (a_max <= 0 || a_max > 9) {
      strcpy  (x_out, "°");
   } else if (a_num < 0 || l > a_max) {
      sprintf (x_out, "%*.*s", a_max, a_max, "´´´´´´´´´");
   } else {
      sprintf (x_out, "%*.*d", a_max, a_max, a_num);
      for (i = 0; i < a_max; ++i) {
         if (strchr ("0 ·", x_out [i]) == NULL) break;
         x_out [i] = '·';
      }
   }
   if (r_out != NULL)  strlcpy (r_out, x_out, LEN_TERSE);
   DEBUG_HFIX  yLOG_sexit   (__FUNCTION__);
   return 0;
}

char*
SHOW_line               (char c_color, short a_shown, char a_type, char a_file [LEN_HUND], short a_line, short a_col, char a_level, char a_msg [LEN_RECD], char a_flag [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_on        [LEN_TERSE] = "";
   char        x_off       [LEN_TERSE] = "";
   char        x_ln        [LEN_TERSE] = "";
   char        x_co        [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_point   ("a_file"    , a_file);
   --rce;  if (a_file == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_point   ("a_msg"     , a_msg);
   --rce;  if (a_msg  == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX  yLOG_point   ("a_flag"    , a_flag);
   --rce;  if (a_flag == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(colorize)-----------------------*/
   DEBUG_HFIX  yLOG_char    ("c_color"   , c_color);
   if (c_color == 'y') {
      switch (a_level) {
      case '!' :   strcpy (x_on, BOLD_CRI);   break;
      case 'E' :   strcpy (x_on, BOLD_RED);   break;
      case 'e' :   strcpy (x_on, BOLD_ORA);   break;
      case 'W' :   strcpy (x_on, BOLD_YEL);   break;
      case 'w' :   strcpy (x_on, BOLD_PUR);   break;
      case 'U' :   strcpy (x_on, BOLD_BLU);   break;
      case 'u' :   strcpy (x_on, BOLD_BRN);   break;
      case 'm' :   strcpy (x_on, BOLD_OFF);   break;
      }
      strcpy (x_off, BOLD_OFF);
   }
   /*---(format numbes)------------------*/
   SHOW_num (a_line, 4, x_ln);
   DEBUG_HFIX  yLOG_info    ("x_ln"      , x_ln);
   SHOW_num (a_col , 3, x_co);
   DEBUG_HFIX  yLOG_info    ("x_co"      , x_co);
   /*---(create line)--------------------*/
   sprintf (g_print, "%s%-2.2s· - %c  %-30.30s %-4.4s %-3.3s %c   %-60.60s %-40.40s [%c]%s", x_on, SHOW_hint (a_shown - 1), a_type, a_file, x_ln, x_co, a_level, a_msg, a_flag, a_level, x_off);
   /*> sprintf (x_show, "%s%-2.2s· - %c  %-30.30s %4d %3d %c   %-60.60s %-40.40s [%c]%s", x_on, SHOW_hint (a_shown - 1), a_type, a_file, a_line, a_col, a_level, a_msg, a_flag, a_level, x_off);   <*/
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return g_print;
}

char*
SHOW_totals             (char c_pass, char c_color, short a_show, short a_fail, short a_errs, short a_warn, short a_waste, short a_msgs, short a_total)
{
   char        x_grade     [LEN_TERSE] = "----";
   char        x_on        [LEN_TERSE] = "";
   char        x_off       [LEN_TERSE] = "";
   char        x_show      [LEN_TERSE] = "····";
   char        x_fail      [LEN_TERSE] = "····";
   char        x_errs      [LEN_TERSE] = "····";
   char        x_warn      [LEN_TERSE] = "····";
   char        x_waste     [LEN_TERSE] = "····";
   char        x_msgs      [LEN_TERSE] = "····";
   char        x_total     [LEN_TERSE] = "····";
   char        x_filter    [LEN_HUND]  = "";
   char        x_suffix    [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX  yLOG_enter   (__FUNCTION__);
   if      (a_fail > 0) { strcpy (x_grade, "FAIL");  strcpy (x_suffix, "[!]");  if (c_color == 'y')  strcpy (x_on, INVR_CRI);  }
   else if (a_errs > 0) { strcpy (x_grade, "ERRS");  strcpy (x_suffix, "[E]");  if (c_color == 'y')  strcpy (x_on, INVR_RED);  }
   else if (a_warn > 0) { strcpy (x_grade, "WARN");  strcpy (x_suffix, "[W]");  if (c_color == 'y')  strcpy (x_on, INVR_YEL);  }
   else if (a_msgs > 0) { strcpy (x_grade, "----");  strcpy (x_suffix, "[m]");  if (c_color == 'y')  strcpy (x_on, INVR_BRN);  }
   else                 { strcpy (x_grade, "pass");  strcpy (x_suffix, "[p]");  if (c_color == 'y')  strcpy (x_on, INVR_GRN);  }
   if (c_color == 'y')  strcpy (x_off, BACK_OFF);
   SHOW_num (a_show , 4, x_show);
   SHOW_num (a_fail , 4, x_fail);
   SHOW_num (a_errs , 4, x_errs);
   SHOW_num (a_warn , 4, x_warn);
   SHOW_num (a_waste, 4, x_waste);
   SHOW_num (a_msgs , 4, x_msgs);
   SHOW_num (a_total, 5, x_total);
   sprintf (g_break, "%shnt -·---buffer--------------------- line col typ·---message-------------------------------------------------- ---gcc-flag-----------------------------%s", x_on, x_off);
   if (c_pass ==  0) {
      /*> printf ("%sgcc/make (help) q:quik f:full w:wipe a:ansi c:comp i:inst u:test m:manu Z:revw%s\n", x_on, x_off);   <*/
      sprintf (x_filter, "filter=%s···········································································", g_filter);
      /*> sprintf (g_print, "%scompiler (%s) show=%s, fail=%s, errs=%s, warn=%s, wast=%s, msgs=%s, line=%s   %-59.59s %s%s",   <*/
      sprintf (g_print, "%sHFIX·gcc/make·(%s)·show=%s,·fail=%s,·errs=%s,·warn=%s,·wast=%s,·msgs=%s,·line=%s···%-54.54s·%s%s",
            x_on, x_grade,
            x_show, x_fail, x_errs, x_warn, x_waste, x_msgs, x_total,
            x_filter, x_suffix, x_off);
   } else if (c_pass ==  1) {
      sprintf (g_print, "%send-of-data (%s) compiler feedback···········································(v%-4.4s)·····································································%s%s", x_on, x_grade, P_VERNUM, x_suffix, x_off);
   }
   DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
   return g_print;
}

char
SHOW_vim_simple         (void)
{
   printf ("HFIX·gcc/make·····,qw·wipe··,qc·comp··,qi·inst··,qu·unit··,qm·manu··,q?·help····(%-4.4s)·······································································[?]\n", P_VERNUM);
   exit (0);
}

char
SHOW_vim_action         (char a_opt [LEN_TERSE])
{
   switch (a_opt [0]) {
   case 'w' :  printf ("HFIX·gcc/make·(----)··chosen··(w:wipe)·=·small·clean·(opject/exec)··············(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'b' :  printf ("HFIX·gcc/make·(----)··chosen··(b:big)··=·big·clean·(all·temp/waste)·············(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'r' :  printf ("HFIX·gcc/make·(----)··chosen··(r:reco)·=·recon·files·to·be·compilied············(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'q' :  printf ("HFIX·gcc/make·(----)··chosen··(q:quik)·=·compile·and·install·code···············(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'c' :  printf ("HFIX·gcc/make·(----)··chosen··(c:comp)·=·compile·only,·show·critical·only·······(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'C' :  printf ("HFIX·gcc/make·(----)··chosen··(E:errr)·=·compile·only,·show errors··············(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'W' :  printf ("HFIX·gcc/make·(----)··chosen··(W:warn)·=·compile·only,·show errors/warnings·····(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case '*' :  printf ("HFIX·gcc/make·(----)··chosen··(*:evry)·=·compile·only, show every·valid·········(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'i' :  printf ("HFIX·gcc/make·(----)··chosen··(i:inst)·=·install·code·only······················(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'm' :  printf ("HFIX·gcc/make·(----)··chosen··(m:mans)·=·install·manuals·only···················(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'u' :  printf ("HFIX·gcc/make·(----)··chosen··(u:unit)·=·compile·units·only·····················(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   case 'U' :  printf ("HFIX·gcc/make·(----)··chosen··(U:cert)·=·compile·units·and·certify··············(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   default  :  printf ("HFIX·gcc/make·(----)··chosen··unknown·option····································(%-4.4s)·······································································[?]\n", P_VERNUM);  break;
   }
   return 0;
}

char
SHOW_vim_help           (void)
{
   printf ("HFIX·gcc/make·(help)············································quick·reminders·(%-4.4s)·······································································[?]\n", P_VERNUM);
   printf ("   1) cleaning      (2)   ,qw wipe    ,qb big      ƒ NO cleaning          ,qr recon                                                                          [?]\n");
   printf ("   2) making        (2)   ,qc comp    ,qq quik·····† gnu89 compile   (c)                                                                                     [?]\n");
   printf ("   3) installing    (2)   ,qi inst    ,qm mans      install w/mans  (i)+(m)                                                                                 [?]\n");
   printf ("   4) unit-tests    (2)   ,qu unit    ,q* cert     „ NO unit actions                                                                                         [?]\n");
   printf ("   5)·hints·········(1)·······;;AA·=·go·directly·to·buffer/position·of·hint·AA···············································································[?]\n");
   printf ("   6) cursoring     (5)   ,q[ head    ,q< prev    ,q. curr    ,q> next    ,q] last                                                                           [?]\n");
   printf ("   7) configure     (4)   ,q  show    ,qh hide    ,q+ more    ,q- less    ,q# this                                                                           [?]\n");
   printf ("   8)·bag-of-chips··(1)···,qQ·deep·clean,·full·compile/install,·and·certification············································································[?]\n");
   printf ("   9) help          (2)   ,q? help    ,qC crit    ,qE errs    ,qW warn    ,q* every                                                                          [?]\n");
   exit (0);
}

/*> char                                                                                        <* 
 *> SHOW_vim_recon          (void)                                                              <* 
 *> {                                                                                           <* 
 *>    /+> rc = system ("make --recon");                                                  <+/   <* 
 *>    exit (0);                                                                                <* 
 *> }                                                                                           <*/

