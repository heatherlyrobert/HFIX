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
   DEBUG_PROG  yLOG_senter  (__FUNCTION__);
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
   DEBUG_PROG  yLOG_sexit   (__FUNCTION__);
   return x_hint;
}

char
SHOW_num                (int a_num, int a_max, char r_out [LEN_TERSE])
{
   char        x_out       [LEN_TERSE] = "°";
   char        t           [LEN_LABEL] = "";
   char        i           =    0;
   int         l           =    0;
   DEBUG_PROG  yLOG_senter  (__FUNCTION__);
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
   DEBUG_PROG  yLOG_sexit   (__FUNCTION__);
   return 0;
}

char*
SHOW_totals             (char a_pass, int a_show, int a_fail, int a_errs, int a_warn, int a_waste, int a_msgs, int a_total)
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
   char        x_suffix    [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   if      (a_fail > 0) { strcpy (x_grade, "FAIL"); strcpy (x_suffix, "[!]"); /* strcpy (x_on, INVR_RED); */ }
   else if (a_errs > 0) { strcpy (x_grade, "ERRS"); strcpy (x_suffix, "[E]"); /* strcpy (x_on, INVR_RED); */ }
   else if (a_warn > 0) { strcpy (x_grade, "WARN"); strcpy (x_suffix, "[W]"); /* strcpy (x_on, INVR_YEL); */ }
   else                 { strcpy (x_grade, "pass"); strcpy (x_suffix, "[p]"); /* strcpy (x_on, INVR_GRN); */ }
   /*> strcpy (x_off, BACK_OFF);                                                      <*/
   SHOW_num (a_show , 4, x_show);
   SHOW_num (a_fail , 4, x_fail);
   SHOW_num (a_errs , 4, x_errs);
   SHOW_num (a_warn , 4, x_warn);
   SHOW_num (a_waste, 4, x_waste);
   SHOW_num (a_msgs , 4, x_msgs);
   SHOW_num (a_total, 4, x_total);
   sprintf (g_break, "%shnt -·---buffer--------------------- line col typ·---message-------------------------------------------------- ---gcc-flag-----------------------------%s", x_on, x_off);
   if (a_pass ==  0) {
      /*> printf ("%sgcc/make (help) q:quik f:full w:wipe a:ansi c:comp i:inst u:test m:manu Z:revw%s\n", x_on, x_off);   <*/
      sprintf (g_print, "%scompiler (%s) show=%s, fail=%s, errs=%s, warn=%s, wast=%s, msgs=%s, line=%s   (filter=%c)··············································· %s%s",
            x_on, x_grade,
            x_show, x_fail, x_errs, x_warn, x_waste, x_msgs, x_total,
            g_filter, x_suffix, x_off);
      /*> printf (g_break);                                                           <*/
   } else if (a_pass ==  1) {
      sprintf (g_print, "%send-of-data (%s) compiler feedback··················································································································· %s%s", x_on, x_grade, x_suffix, x_off);
   }
   DEBUG_PROG  yLOG_exit    (__FUNCTION__);
   return g_print;
}

