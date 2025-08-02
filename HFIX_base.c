#include "HFIX.h"



tMY         my;
char        g_print    [LEN_RECD]  = "";



/*====================------------------------------------====================*/
/*===----                      overall defense                         ----===*/
/*====================------------------------------------====================*/
static void  o___DEFENSE_________o () { return; }

char
BASE__legal             (char c_super, char c_major, char c_minor, char c_phase, char c_unit, char r_msg [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_msg      != NULL)  strcpy (r_msg, "");
   /*---(singular)-----------------------*/
   DEBUG_HFIX    yLOG_char    ("c_super"   , c_super);
   --rce;  if (c_super   == 0 || strchr (HFIX_SUPERS, c_super) == NULL) {
      if (r_msg != NULL)  snprintf (r_msg, LEN_HUND, "c_super (%s) is not legal å%sæ", HFIX_chrvisible (c_super), HFIX_SUPERS);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_major"   , c_major);
   --rce;  if (c_major   == 0 || strchr (HFIX_ACTIONS "ÿ", c_major) == NULL) {
      if (r_msg != NULL)  snprintf (r_msg, LEN_HUND, "c_major (%s) is not legal å%sæ", HFIX_chrvisible (c_major), HFIX_ACTIONS);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_minor"   , c_minor);
   --rce;  if (c_minor   == 0 || strchr (HFIX_ACTIONS "ÿ", c_minor) == NULL) {
      if (r_msg != NULL)  snprintf (r_msg, LEN_HUND, "c_minor (%s) is not legal å%sæ", HFIX_chrvisible (c_minor), HFIX_ACTIONS);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_phase"   , c_phase);
   --rce;  if (c_phase == 0 || strchr (HFIX_PHASES, c_phase) == NULL) {
      if (r_msg != NULL)  snprintf (r_msg, LEN_HUND, "c_phase (%s) is not legal å%sæ", HFIX_chrvisible (c_phase), HFIX_PHASES);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_unit"    , c_unit);
   --rce;  if (c_unit  == 0 || strchr ("y-", c_unit) == NULL) {
      if (r_msg != NULL)  snprintf (r_msg, LEN_HUND, "c_unit (%s) is not legal å%sæ", HFIX_chrvisible (c_unit), "y-");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE__super_major_minor (char c_super, char c_major, char c_minor, char r_desc [LEN_TERSE], char r_msg [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_desc      [LEN_TERSE] = "";
   char        x_majors    [LEN_LABEL] = "";
   char        x_minors    [LEN_LABEL] = "";
   char        x_sup       [LEN_TERSE] = "";
   char        x_maj       [LEN_TERSE] = "";
   char        x_min       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_desc     != NULL)  strcpy (r_desc, "");
   if (r_msg      != NULL)  strcpy (r_msg , "");
   /*---(verify)-------------------------*/
   DEBUG_HFIX    yLOG_char    ("c_super"   , c_super);
   /*---(check combination)--------------*/
   switch (c_super) {
   case 'w'  :  strcpy (x_desc, "wipe");  strcpy (x_majors, "w"    );  strcpy (x_minors, "w"           );  break;
   case 'W'  :  strcpy (x_desc, "WIPE");  strcpy (x_majors, "wW"   );  strcpy (x_minors, "wW"          );  break;
   case 'c'  :  strcpy (x_desc, "comp");  strcpy (x_majors, "c"    );  strcpy (x_minors, "c"           );  break;
   case 'C'  :  strcpy (x_desc, "COMP");  strcpy (x_majors, "cC"   );  strcpy (x_minors, "cC"          );  break;
   case 'i'  :  strcpy (x_desc, "inst");  strcpy (x_majors, "i"    );  strcpy (x_minors, "i"           );  break;
   case 'I'  :  strcpy (x_desc, "INST");  strcpy (x_majors, "iI"   );  strcpy (x_minors, "iI"          );  break;
   case 'u'  :  strcpy (x_desc, "unit");  strcpy (x_majors, "u"    );  strcpy (x_minors, "u"           );  break;
   case 'U'  :  strcpy (x_desc, "UNIT");  strcpy (x_majors, "uU"   );  strcpy (x_minors, "uU"          );  break;
   case 'r'  :  strcpy (x_desc, "remv");  strcpy (x_majors, "r"    );  strcpy (x_minors, "r"           );  break;
   case 'R'  :  strcpy (x_desc, "REMV");  strcpy (x_majors, "rR"   );  strcpy (x_minors, "rR"          );  break;
   case 'm'  :  strcpy (x_desc, "mans");  strcpy (x_majors, "m"    );  strcpy (x_minors, "m"           );  break;
   case 'M'  :  strcpy (x_desc, "MANS");  strcpy (x_majors, "mM"   );  strcpy (x_minors, "mM"          );  break;
   case 'g'  :  strcpy (x_desc, "gitv");  strcpy (x_majors, "g"    );  strcpy (x_minors, "g"           );  break;
   case 'G'  :  strcpy (x_desc, "GITV");  strcpy (x_majors, "gG"   );  strcpy (x_minors, "gG"          );  break;
   case 't'  :  strcpy (x_desc, "test");  strcpy (x_majors, "t"    );  strcpy (x_minors, "t"           );  break;
   case 'T'  :  strcpy (x_desc, "TEST");  strcpy (x_majors, "tT"   );  strcpy (x_minors, "tT"          );  break;
   case 'q'  :  strcpy (x_desc, "quik");  strcpy (x_majors, "CI"   );  strcpy (x_minors, "cCiImM"      );  break;
   case 'Q'  :  strcpy (x_desc, "QUIK");  strcpy (x_majors, "CIU"  );  strcpy (x_minors, "cCiImMuU"    );  break;
   case 'f'  :  strcpy (x_desc, "full");  strcpy (x_majors, "WCIU" );  strcpy (x_minors, "wWcCiImMuU"  );  break;
   case 'F'  :  strcpy (x_desc, "FULL");  strcpy (x_majors, "WCIUT");  strcpy (x_minors, "wWcCimMuIUtT");  break;
   }
   DEBUG_HFIX    yLOG_info    ("x_desc"    , x_desc);
   /*---(verify major allowed)-----------*/
   DEBUG_HFIX    yLOG_char    ("c_major"   , c_major);
   DEBUG_HFIX    yLOG_info    ("x_majors"  , x_majors);
   if (strchr (x_majors, c_major) == NULL) {
      strcpy (x_sup, HFIX_chrvisible (c_super));
      DEBUG_HFIX    yLOG_info    ("x_sup"     , x_sup);
      strcpy (x_maj, HFIX_chrvisible (c_major));
      DEBUG_HFIX    yLOG_info    ("x_maj"     , x_maj);
      if (r_msg != NULL)  snprintf (r_msg, LEN_HUND, "c_super (%s) can not combine with c_major (%s), only allow å%sæ", x_sup, x_maj, x_majors);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(verify minor allowed)-----------*/
   DEBUG_HFIX    yLOG_char    ("c_minor"   , c_minor);
   DEBUG_HFIX    yLOG_info    ("x_minors"  , x_minors);
   if (strchr (x_minors, c_minor) == NULL) {
      strcpy (x_sup, HFIX_chrvisible (c_super));
      DEBUG_HFIX    yLOG_info    ("x_sup"     , x_sup);
      strcpy (x_min, HFIX_chrvisible (c_minor));
      DEBUG_HFIX    yLOG_info    ("x_min"     , x_min);
      if (r_msg != NULL)  snprintf (r_msg, LEN_HUND, "c_super (%s) can not combine with c_minor (%s), only allow å%sæ", x_sup, x_min, x_minors);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_desc     != NULL)   strcpy (r_desc, x_desc);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE__minor_phase       (char c_minor, char c_phase, char a_ephase, char r_msg [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_allow     [LEN_TERSE] = "";
   char        x_min       [LEN_TERSE] = "";
   char        x_pha       [LEN_TERSE] = "";
   char        x_exp       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_msg      != NULL)  strcpy (r_msg , "");
   /*---(verify)-------------------------*/
   DEBUG_HFIX    yLOG_char    ("c_minor"   , c_minor);
   DEBUG_HFIX    yLOG_char    ("c_phase"   , c_phase);
   /*---(check combination)--------------*/
   switch (c_minor) {
   case 'w'  :  case 'W'  :  strcpy (x_allow, "-"    );   break;
   case 'c'  :  case 'C'  :  strcpy (x_allow, "[>"   );   break;
   case 'i'  :  case 'I'  :  strcpy (x_allow, "-"    );   break;
   case 'u'  :  case 'U'  :  strcpy (x_allow, "[>"   );   break;
   case 'r'  :  case 'R'  :  strcpy (x_allow, "-"    );   break;
   case 'm'  :  case 'M'  :  strcpy (x_allow, "-"    );   break;
   case 'g'  :  case 'G'  :  strcpy (x_allow, "[>"   );   break;
   case 't'  :  case 'T'  :  strcpy (x_allow, "[>"   );   break;
   }
   DEBUG_HFIX    yLOG_info    ("x_allow"   , x_allow);
   if (strchr (x_allow, c_phase) == NULL) {
      strcpy (x_min, HFIX_chrvisible (c_minor));
      DEBUG_HFIX    yLOG_info    ("x_min"     , x_min);
      strcpy (x_pha, HFIX_chrvisible (c_phase));
      DEBUG_HFIX    yLOG_info    ("x_pha"     , x_pha);
      if (r_msg != NULL)  snprintf (r_msg, LEN_HUND, "c_minor (%s) can not combine with c_phase (%s), only allow å%sæ", x_min, x_pha, x_allow);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(expected phase)-----------------*/
   DEBUG_HFIX    yLOG_char    ("a_ephase"  , a_ephase);
   --rce;  if (c_phase != a_ephase) {
      strcpy (x_pha, HFIX_chrvisible (c_phase));
      DEBUG_HFIX    yLOG_info    ("x_pha"     , x_pha);
      strcpy (x_exp, HFIX_chrvisible (a_ephase));
      DEBUG_HFIX    yLOG_info    ("x_exp"     , x_exp);
      if (r_msg != NULL)  snprintf (r_msg, LEN_HUND, "c_phase (%s) does not match expected (%s)", x_pha, x_exp);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE__export            (char c_major, char c_minor, char *r_theme, char *r_layout, char *r_pass, char r_ext [LEN_TERSE], char *r_export, char *r_maintset)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_theme     =  '-';
   char        x_layout    =  '-';
   char        x_pass      =  '-';
   char        x_export    =  '-';
   char        x_maintset  =  '-';
   char        x_ext       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_theme    != NULL)  *r_theme    = '-';
   if (r_layout   != NULL)  *r_layout   = '-';
   if (r_pass     != NULL)  *r_pass     = '-';
   if (r_ext      != NULL)  strcpy (r_ext, "");
   if (r_export   != NULL)  *r_export   = '-';
   if (r_maintset != NULL)  *r_maintset = '-';
   /*---(determining theme)--------------*/
   if      (strchr ("Ww", c_minor) != NULL)     x_theme  = HFIX_WIPE;
   else if (strchr ("Cc", c_minor) != NULL)  {  x_theme  = HFIX_COMP;  strcpy (x_ext, ".c");    }
   else if (strchr ("Ii", c_minor) != NULL)     x_theme  = HFIX_INST;
   else if (strchr ("Uu", c_minor) != NULL)  {  x_theme  = HFIX_UNIT;  strcpy (x_ext, ".unit"); }
   else if (strchr ("Rr", c_minor) != NULL)     x_theme  = HFIX_REMV;
   else if (strchr ("Mm", c_minor) != NULL)     x_theme  = HFIX_MANS;
   else if (strchr ("Gg", c_minor) != NULL)     x_theme  = HFIX_GITV;
   else if (strchr ("Tt", c_minor) != NULL)     x_theme  = HFIX_TEST;
   DEBUG_HFIX    yLOG_char    ("x_theme"   , x_theme);
   /*---(layouts)------------------------*/
   if (strchr (HFIX_MAINTS, c_minor) != NULL) x_layout = HFIX_COUNT;
   else                                       x_layout = HFIX_MARKS;
   /*---(passes)-------------------------*/
   if (c_minor == tolower (c_minor))          x_pass   = HFIX_RECON;
   else                                       x_pass   = HFIX_EXEC;
   DEBUG_HFIX    yLOG_char    ("x_pass"    , x_pass);
   /*---(export)-------------------------*/
   if (c_major == toupper (c_major)) {
      if (x_pass  == HFIX_EXEC)     x_export = 'y';
      else                          x_export = '-';
   } else {
      x_export = 'y';
   }
   DEBUG_HFIX    yLOG_char    ("x_export"  , x_export);
   /*---(determine maint subset)---------*/
   if      (strchr ("Ww"    , c_minor) != NULL)  x_maintset  = 'w';
   else if (strchr ("IiRrMm", c_minor) != NULL)  x_maintset  = 'i';
   else                                          x_maintset  = '-';
   /*---(save-back)----------------------*/
   if (r_theme    != NULL)  *r_theme    = x_theme;
   if (r_layout   != NULL)  *r_layout   = x_layout;
   if (r_pass     != NULL)  *r_pass     = x_pass;
   if (r_ext      != NULL)  strlcpy (r_ext, x_ext, LEN_TERSE);
   if (r_export   != NULL)  *r_export   = x_export;
   if (r_maintset != NULL)  *r_maintset = x_maintset;
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE_precheck           (char c_super, char c_major, char c_minor, char c_phase, char a_ephase, char r_whoami [LEN_LABEL], char r_desc [LEN_TERSE], char *r_theme, char *r_layout, char *r_pass, char r_ext [LEN_TERSE], char *r_export, char *r_maintset, char c_unit)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_whoami    [LEN_LABEL] = "";
   char        x_theme     =  '-';
   char        x_layout    =  '-';
   char        x_pass      =  '-';
   char        x_ext       [LEN_TERSE] = "";
   char        x_export    =  '-';
   char        x_maintset  =  '-';
   char        x_desc      [LEN_TERSE] = "";
   char        x_msg       [LEN_HUND]  = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_whoami   != NULL)  strcpy (r_whoami, "");
   if (r_desc     != NULL)  strcpy (r_desc  , "");
   if (r_theme    != NULL)  *r_theme    = '-';
   if (r_layout   != NULL)  *r_layout   = '-';
   if (r_pass     != NULL)  *r_pass     = '-';
   if (r_ext      != NULL)  strcpy (r_ext   , "");
   if (r_export   != NULL)  *r_export   = '-';
   if (r_maintset != NULL)  *r_maintset = '-';
   /*---(who am i)-----------------------*/
   rc = HFIX_whoami (x_whoami);
   DEBUG_HFIX    yLOG_value   ("whoami"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_info    ("x_whoami"  , x_whoami);
   /*---(legal checks)-------------------*/
   rc = BASE__legal (c_super, c_major, c_minor, c_phase, c_unit, x_msg);
   DEBUG_HFIX    yLOG_value   ("legal"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX    yLOG_info    ("x_msg"     , x_msg);
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, x_msg);
      else                   EXIM_trouble (""      , x_msg);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(super/action)-------------------*/
   rc = BASE__super_major_minor (c_super, c_major, c_minor, x_desc, x_msg);
   DEBUG_HFIX    yLOG_value   ("sup/maj"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX    yLOG_info    ("x_msg"     , x_msg);
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, x_msg);
      else                   EXIM_trouble (""      , x_msg);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(phases with c_actions)----------*/
   rc = BASE__minor_phase (c_minor, c_phase, a_ephase, x_msg);
   DEBUG_HFIX    yLOG_value   ("min/pha"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX    yLOG_info    ("x_msg"     , x_msg);
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, x_msg);
      else                   EXIM_trouble (""      , x_msg);
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(determining theme)--------------*/
   rc = BASE__export (c_major, c_minor, &x_theme, &x_layout, &x_pass, x_ext, &x_export, &x_maintset);
   DEBUG_HFIX    yLOG_value   ("export"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_whoami   != NULL)  strlcpy (r_whoami, x_whoami, LEN_LABEL);
   if (r_desc     != NULL)  strlcpy (r_desc  , x_desc  , LEN_TERSE);
   if (r_theme    != NULL)  *r_theme    = x_theme;
   if (r_layout   != NULL)  *r_layout   = x_layout;
   if (r_pass     != NULL)  *r_pass     = x_pass;
   if (r_ext      != NULL)  strlcpy (r_ext   , x_ext   , LEN_TERSE);
   if (r_export   != NULL)  *r_export   = x_export;
   if (r_maintset != NULL)  *r_maintset = x_maintset;
   /*---(save-globally)------------------*/
   strlcpy (my.m_whoami, x_whoami, LEN_LABEL);
   my.m_super    = c_super;
   my.m_major    = c_major;
   my.m_minor    = c_minor;
   my.m_phase    = c_phase;
   strlcpy (my.m_desc, x_desc, LEN_TERSE);
   my.m_theme    = x_theme;
   my.m_layout   = x_layout;
   my.m_pass     = x_pass;
   strlcpy (my.m_ext , x_ext , LEN_TERSE);
   my.m_export   = x_export;
   my.m_set      = x_maintset;
   my.m_unit     = c_unit;
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE_ready              (char c_super, char c_major, char c_minor, char c_phase, char c_unit)
{
   return  BASE_precheck (c_super, c_major, c_minor, c_phase, c_phase, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, c_unit);
}



/*====================------------------------------------====================*/
/*===----                      laying base layer                       ----===*/
/*====================------------------------------------====================*/
static void  o___BASE____________o () { return; }

char
BASE_clear              (char a_desc [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          =    0;
   char        i           =    0;
   char        l           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defaults)-----------------------*/
   s_ncount = 0;
   /*---(clear entries)------------------*/
   for (i = 0; i < MAX_ENTRY; ++i) {
      strlcpy (s_compile [i], "··························   ", LEN_DESC);
   }
   /*---(defense)------------------------*/
   DEBUG_HFIX    yLOG_point   ("a_desc"    , a_desc);
   --rce;  if (a_desc    == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_info    ("a_desc"    , a_desc);
   /*---(place description)--------------*/
   l = strlen (a_desc);
   for (i = 0; i < l; ++i)   s_compile [MAX_ENTRY - 1][i] = a_desc [i];
   /*---(add total marks)----------------*/
   s_compile [MAX_ENTRY - 1][ 8] = '-';
   s_compile [MAX_ENTRY - 1][13] = '-';
   s_compile [MAX_ENTRY - 1][18] = '-';
   s_compile [MAX_ENTRY - 1][24] = '-';
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
BASE_entry              (char c_maintset, char n, char a_name [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        l           =    0;
   char        x_suffix    [LEN_LABEL] = "";
   char        x_full      [LEN_TITLE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defence)------------------------*/
   DEBUG_HFIX    yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name == NULL || a_name [0] == '\0') {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_info    ("a_name"    , a_name);
   DEBUG_HFIX    yLOG_value   ("n"         , n);
   --rce;  if (n < 0 || n >= MAX_ENTRY - 2) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(setup)--------------------------*/
   DEBUG_HFIX    yLOG_char    ("c_maintset", c_maintset);
   switch (c_maintset) {
   case 'c' :
      l = 19;
      strcpy (x_suffix, "-·-··-·   ");
      break;
   case 'm' :
      l = 16;
      strcpy (x_suffix, "-···-···-·   ");
      break;
   default  :
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_value   ("l"         , l);
   DEBUG_HFIX    yLOG_info    ("x_suffix"  , x_suffix);
   /*---(comp)---------------------------*/
   snprintf (x_full , l, "%s············································", a_name);
   DEBUG_HFIX    yLOG_info    ("x_full"    , x_full);
   sprintf  (s_compile [n], "%s·%s", x_full, x_suffix);
   DEBUG_HFIX    yLOG_info    ("final"     , s_compile [n]);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE_exist              (char c_theme, char a_name [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        i           =    0;
   char        l           =    0;
   char        x_name      [LEN_LABEL] = "";
   char        c           =    0;
   char        x_row, x_col;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX   yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name == NULL || a_name [0] == '\0') {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_info    ("a_name"    , a_name);
   --rce;  if (strchr (" ·", a_name [0]) != NULL) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(prepare lookup)-----------------*/
   DEBUG_HFIX   yLOG_char    ("c_theme"   , c_theme);
   switch (c_theme) {
   case 'w' : case 'i' : case 'r' : case 'm' :
      l = 14; 
      break;
   default  :
      l = 18;
      break;
   }
   DEBUG_HFIX   yLOG_value   ("l"         , l);
   snprintf (x_name, LEN_LABEL - 1, "%s······························", a_name);
   DEBUG_HFIX   yLOG_info    ("x_name"    , x_name);
   /*---(prepare lookup)-----------------*/
   for (i = 0; i < MAX_ENTRY; ++i) {
      if (s_compile [i] [0] == '·')                  continue;
      ++c;
      if (strncmp (s_compile [i], x_name, l) != 0)   continue;
      /*---(complete)--------------------*/
      x_row = i / 3;
      x_col = i % 3;
      DEBUG_HFIX   yLOG_complex ("FOUND"     , "%2d#, %2dr, %2dc, filled %2d", i, x_row, x_col, c);
      DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
      return i + 1;
   }
   /*---(trouble)------------------------*/
   --rce;  
   DEBUG_HFIX    yLOG_note    ("name never found");
   DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
   return rce;
}

char
BASE_recon_done         (char c_super)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_ch        =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(check for super)----------------*/
   x_ch = s_compile [MAX_ENTRY - 1][0];
   DEBUG_HFIX  yLOG_char    ("super"     , x_ch);
   if (x_ch != c_super) {
      DEBUG_HFIX  yLOG_note    ("not on the right super");
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return '-';
   }
   /*---(grab recon)---------------------*/
   x_ch = s_compile [MAX_ENTRY - 1][13];
   DEBUG_HFIX  yLOG_char    ("recon"     , x_ch);
   /*---(check for flag)-----------------*/
   if (x_ch == '-') {
      DEBUG_HFIX  yLOG_note    ("recon not showing");
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return '-';
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX  yLOG_note    ("found recon flag");
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 'y';
}



/*====================------------------------------------====================*/
/*===----                        marking entries                       ----===*/
/*====================------------------------------------====================*/
static void  o___MARK____________o () { return; }

char
BASE_mark               (char c_theme, char a_name [LEN_TITLE], char a_mark)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        n           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(find)---------------------------*/
   n = BASE_exist (c_theme, a_name);
   DEBUG_HFIX   yLOG_value   ("n"         , n);
   --rce;  if (n < 0) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(mark)---------------------------*/
   DEBUG_HFIX   yLOG_char    ("a_mark"    , a_mark);
   --rce;  if (a_mark == 0 || strchr ("nbe", a_mark) == NULL) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   if      (a_mark == 'n')  s_compile [n - 1][19] = '³';
   else if (a_mark == 'b')  s_compile [n - 1][21] = ' ';
   else if (a_mark == 'e')  s_compile [n - 1][21] = 'Ï';
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE_result             (uchar a_status, char a_label [LEN_LABEL], int a_cnt)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   char        x_off       =    4;
   char        l           =    0;
   char        x_cnt       [LEN_TERSE] = "";
   char        x_label     [LEN_LABEL] = "";
   char        x_full      [LEN_DESC]  = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(create status)------------------*/
   DEBUG_HFIX   yLOG_value   ("a_status"  , a_status);
   if      (a_status <=  32)  a_status = '¢';
   else if (a_status == 127)  a_status = '¢';
   DEBUG_HFIX   yLOG_value   ("a_status"  , a_status);
   /*---(create status)------------------*/
   DEBUG_HFIX   yLOG_point   ("a_label"   , a_label);
   if      (a_label == NULL)      strlcpy  (x_label, "(null)··············", LEN_LABEL);
   else if (a_label [0] == '\0')  strlcpy  (x_label, "(empty)·············", LEN_LABEL);
   else                           snprintf (x_label, LEN_LABEL, "%s···············", a_label);
   DEBUG_HFIX   yLOG_value   ("x_label"   , x_label);
   /*---(check count)--------------------*/
   DEBUG_HFIX   yLOG_value   ("a_cnt"     , a_cnt);
   if      (a_cnt <  0 )    strcpy (x_cnt, "·NEGß");
   else if (a_cnt == 0 )    strcpy (x_cnt, "···/ß");
   else if (a_cnt > 999)    strcpy (x_cnt, "****ß");
   else {
      sprintf (x_cnt, "%4dß", a_cnt);
      if (x_cnt [0] == ' ')  x_cnt [0] = '·';
      if (x_cnt [1] == ' ')  x_cnt [1] = '·';
      if (x_cnt [2] == ' ')  x_cnt [2] = '·';
      if (x_cnt [3] == ' ')  x_cnt [3] = '·';
   }
   DEBUG_HFIX   yLOG_info    ("x_cnt"     , x_cnt);
   /*---(create text---------------------*/
   sprintf (x_full, "·%c·%-8.8s·%s·", a_status, x_label, x_cnt);
   DEBUG_HFIX   yLOG_info    ("x_full"    , x_full);
   /*---(place it)-----------------------*/
   l = strlen (x_full);
   for (i = 0; i < l; ++i) s_compile [MAX_ENTRY - 2][x_off + i] = x_full [i];
   DEBUG_HFIX   yLOG_info    ("s_compile" , s_compile [MAX_ENTRY - 2]);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE_done               (char a_result)
{
   my.m_done   = 'Y';
   my.m_result = a_result;
   return 1;
}



/*====================------------------------------------====================*/
/*===----                        counting matches                      ----===*/
/*====================------------------------------------====================*/
static void  o___COUNT___________o () { return; }

char
BASE__inc_single        (char n, char a_slot, char a_off)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_bit       [LEN_SHORT] = "";
   int         x_val       =    0;
   char        i           =    0;
   char        l           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(get existing)-------------------*/
   DEBUG_HFIX   yLOG_value   ("n"         , n);
   DEBUG_HFIX   yLOG_value   ("a_off"     , a_off);
   if (n == MAX_ENTRY)  l = 4;
   else                 l = 3;
   DEBUG_HFIX   yLOG_value   ("l"         , l);
   strlcpy (x_bit, s_compile [n - 1] + a_off, l);
   DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
   if (x_bit [0] == '·')  x_bit [0] = ' ';
   if (x_bit [1] == '·')  x_bit [1] = ' ';
   if (x_bit [1] == '-')  x_bit [1] = ' ';
   if (x_bit [2] == '·')  x_bit [2] = ' ';
   if (x_bit [2] == '-')  x_bit [2] = ' ';
   DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
   /*---(convert to number)--------------*/
   x_val = atoi (x_bit);
   DEBUG_HFIX   yLOG_value   ("x_val"     , x_val);
   ++x_val;
   if (l == 3 && x_val >=  99)  x_val =  99;
   if (l == 4 && x_val >= 999)  x_val = 999;
   DEBUG_HFIX   yLOG_value   ("x_val"     , x_val);
   /*---(put it back)--------------------*/
   sprintf (x_bit, "%*d%c", l - 1, x_val, a_slot);
   if (x_bit [0] == ' ')  x_bit [0] = '·';
   if (x_bit [1] == ' ')  x_bit [1] = '·';
   DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
   for (i = 0; i < l; ++i)  s_compile [n - 1][a_off + i] = x_bit [i];
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE_increment          (char c_theme, char a_name [LEN_TITLE], char a_slot)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        n           =    0;
   char        x_col       =    0;
   char        x_tot       =    0;
   char        x_caution   =  '-';
   char        x_suffix    =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(find)---------------------------*/
   n = BASE_exist (c_theme, a_name);
   DEBUG_HFIX   yLOG_value   ("n"         , n);
   --rce;  if (n < 0) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(check caution)------------------*/
   if (strstr (a_name, "CAUTION") != NULL)  x_caution = 'y';
   DEBUG_HFIX   yLOG_char    ("x_caution" , x_caution);
   /*---(find)---------------------------*/
   DEBUG_HFIX   yLOG_char    ("a_slot"    , a_slot);
   DEBUG_HFIX   yLOG_info    ("valid"     , HFIX_SLOTS);
   --rce; switch (a_slot) {
   case HFIX_RECON  :  x_col = 15;  x_tot =  6;  x_suffix = HFIX_TRECON;   break;
   case HFIX_EXEC   :  x_col = 19;  x_tot = 11;  x_suffix = HFIX_TEXEC;    break;
   case HFIX_VERIFY :  x_col = 23;  x_tot = 16;  x_suffix = HFIX_TVERIFY;  break;
   default   :
                       DEBUG_HFIX   yLOG_note    ("unknown slot");
                       DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
                       return  rce;
   }
   DEBUG_HFIX   yLOG_value   ("x_col"     , x_col);
   DEBUG_HFIX   yLOG_char    ("x_suffix"  , x_suffix);
   /*---(get existing)-------------------*/
   DEBUG_HFIX   yLOG_info    ("before"    , s_compile [n - 1]);
   if (x_caution == '-' || a_slot == HFIX_RECON) {
      DEBUG_HFIX   yLOG_note    ("normal/recon handling");
      BASE__inc_single (n        , x_suffix, x_col);
      BASE__inc_single (MAX_ENTRY, x_suffix, x_tot);
   } else {
      DEBUG_HFIX   yLOG_note    ("caution handling");
      s_compile [n - 1][x_col + 1] = 'Ï';
   }
   DEBUG_HFIX   yLOG_info    ("after"     , s_compile [n - 1]);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE_matching           (char n, char *b_result)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        l           =    0;
   char        x_key       [LEN_TERSE] = "";
   char        x_cmp       [LEN_TERSE] = "";
   char        x_check     [LEN_TERSE] = "·Û·";
   char        x           =    0;
   char        x_result    =  'p';
   char        x_lef, x_mid, x_rig;
   char        x_skip      = '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (b_result != NULL)  x_result = *b_result;
   /*---(defense)------------------------*/
   DEBUG_HFIX    yLOG_value   ("n"         , n);
   --rce;  if (n < 0 || n >= MAX_ENTRY) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce; if (n <  MAX_ENTRY - 2) {
      l = 3;
      x_lef = 15; x_mid = 19; x_rig = 23;
      strcpy (x_check, "·Û·");
   }
   else if   (n == MAX_ENTRY - 1) {
      l = 4;
      x_lef =  6; x_mid = 11; x_rig = 16;
      strcpy (x_check, "··Û·");
   }
   else {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check)--------------------*/
   DEBUG_HFIX    yLOG_value   ("n"         , n);
   if (s_compile [n][0] == '·') {
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_HFIX    yLOG_info    ("s_compile" , s_compile [n]);
   /*---(check special lines)------*/
   if (strstr (s_compile [n], "CAUTION") != NULL) {
      strcpy (x_check, "·Ï·");
      for (x = 0; x < l; ++x)  s_compile [n][x_mid + x] = x_check [x];
      for (x = 0; x < l; ++x)  s_compile [n][x_rig + x] = x_check [x];
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(get recon)----------------*/
   strlcpy (x_key, s_compile [n] + x_lef, l);
   DEBUG_HFIX    yLOG_info    ("x_key"     , x_key);
   if (strcmp (x_key, "·-") == 0 || strcmp (x_key, "··-") == 0) {
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(check wipe)---------------*/
   strlcpy (x_cmp, s_compile [n] + x_mid, l);
   DEBUG_HFIX    yLOG_info    ("x_cmp"     , x_cmp);
   if (strcmp (x_cmp, "·Ï") != 0) {
      if (strcmp (x_key, x_cmp) != 0) {
         if (strstr (s_compile [n], "LINKS") == NULL) x_result = 'E';
      } else {
         for (x = 0; x < l; ++x)  s_compile [n][x_mid + x] = x_check [x];
      }
      DEBUG_HFIX    yLOG_char    ("x_result"  , x_result);
   }
   /*---(check verify)-------------*/
   strlcpy (x_key, x_cmp, l);
   strlcpy (x_cmp, s_compile [n] + x_rig, l);
   DEBUG_HFIX    yLOG_info    ("x_cmp"     , x_cmp);
   if (strcmp (x_cmp, "·Ï") != 0) {
      if (strcmp (x_key, x_cmp) != 0) {
         if (strstr (s_compile [n], "LINKS") == NULL) x_result = 'E';
      } else {
         for (x = 0; x < l; ++x)  s_compile [n][x_rig + x] = x_check [x];
      }
      DEBUG_HFIX    yLOG_char    ("x_result"  , x_result);
   }
   /*---(show after)---------------------*/
   DEBUG_HFIX    yLOG_info    ("s_compile" , s_compile [n]);
   /*---(save-back)----------------------*/
   if (b_result != NULL)  *b_result = x_result;
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}



/*====================------------------------------------====================*/
/*===----                     writing summaries                        ----===*/
/*====================------------------------------------====================*/
static void  o___SUMMARY_________o () { return; }

char
BASE_total              (char c_type, int a_value)
{  /*
    *   COMP uses   t   all source files
    *     UNIT      n   make says they need re-compiling
    *               c   successfully compiled
    *
    *   MAINT uses  r   recon'd
    *     WIPE      w   wiped
    *     INST      x   removed/deleted
    *     REMV      i   installed exec/manuals
    *     MANS      v   validated
    *
    *   GITV        >   changed/may need to be pushed
    *               ?   not tracked in git
    *               p   successfully pushed
    *
    *   TEST        t   count of all units
    *               n   number ran
    *               p   number passed/certified
    *
    */
   /*---(locals)-----------+-----+-----+-*/
   char        i           =    0;
   char        x_bit       [LEN_DESC]  = "";
   char        x_off       =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(create string)------------------*/
   DEBUG_HFIX   yLOG_value   ("a_value"   , a_value);
   if      (a_value <  0 )    strcpy (x_bit, "NEG");
   else if (a_value == 0 )    strcpy (x_bit, "··/");
   else if (a_value > 999)    strcpy (x_bit, "***");
   else {
      sprintf (x_bit, "%3d", a_value);
      if (x_bit [0] == ' ')  x_bit [0] = '·';
      if (x_bit [1] == ' ')  x_bit [1] = '·';
      if (x_bit [2] == ' ')  x_bit [2] = '·';
   }
   DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
   /*---(determine offset)---------------*/
   DEBUG_HFIX   yLOG_char    ("c_type"    , c_type);
   switch (c_type) {
   case 't' : case 'r' : case '>' :
      x_off =  6;
      break;
   case 'n' : case 'w' : case 'x' : case 'i' : case '?' :
      x_off = 11;
      break;
   case 'c' : case 'v' : case 'p' :
      x_off = 16;
      break;
   default  :
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_HFIX   yLOG_value   ("x_off"     , x_off);
   /*---(write the value)----------------*/
   for (i = 0; i < 3; ++i)  s_compile [MAX_ENTRY - 1][x_off + i] = x_bit [i];
   s_compile [MAX_ENTRY - 1][x_off + 3] = c_type;
   DEBUG_HFIX   yLOG_info    ("s_compile" , s_compile [MAX_ENTRY - 1]);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE_size               (char c_type, int a_value, llong a_size)
{
   /*---(locals)-----------+-----+-----+-*/
   char        i           =    0;
   char        x_bit       [LEN_TERSE] = "";
   char        x_size      [LEN_TERSE] = "";
   char        x_full      [LEN_LABEL] = "";
   char        x_off       =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(determine offset)---------------*/
   DEBUG_HFIX   yLOG_char    ("c_type"    , c_type);
   switch (c_type) {
   case 'b' :
      x_off =  1;
      strcpy (x_bit, "····b");
      break;
   case 't' :
      x_off = 15;
      strcpy (x_bit, "····t");
      break;
   default  :
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_HFIX   yLOG_value   ("x_off"     , x_off);
   /*---(set count)----------------------*/
   DEBUG_HFIX   yLOG_value   ("a_value"   , a_value);
   if      (a_value <  0  )  { x_bit [0] = '·'; x_bit [1] = 'N'; x_bit [2] = 'E'; x_bit [3] = 'G'; }
   else if (a_value == 0  )  { x_bit [0] = '·'; x_bit [1] = '·'; x_bit [2] = '·'; x_bit [3] = '/'; } 
   else if (a_value > 9999)  { x_bit [0] = '*'; x_bit [1] = '*'; x_bit [2] = '*'; x_bit [3] = '*'; } 
   else {
      sprintf (x_bit, "%4d%c", a_value, c_type);
      if (x_bit [0] == ' ')  x_bit [0] = '·';
      if (x_bit [1] == ' ')  x_bit [1] = '·';
      if (x_bit [2] == ' ')  x_bit [2] = '·';
      if (x_bit [3] == ' ')  x_bit [3] = '·';
   }
   DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
   /*---(set size)-----------------------*/
   sprintf (x_size, "%4s", HFIX_size (a_size));
   DEBUG_HFIX   yLOG_info    ("x_size"    , x_size);
   /*---(transfer to base)---------------*/
   sprintf (x_full, "%s·%s", x_bit, x_size);
   DEBUG_HFIX   yLOG_info    ("x_full"    , x_full);
   for (i = 0; i < 10; ++i)  s_compile [MAX_ENTRY - 2][x_off + i] = x_full [i];
   /*---(add divider)--------------------*/
   strcpy (x_bit, " Œ ");
   for (i = 0; i < 3; ++i)  s_compile [MAX_ENTRY - 2][12 + i] = x_bit [i];
   /*---(show full)----------------------*/
   DEBUG_HFIX   yLOG_info    ("s_compile" , s_compile [MAX_ENTRY - 2]);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}



/*====================------------------------------------====================*/
/*===----                      dealing with time                       ----===*/
/*====================------------------------------------====================*/
static void  o___TIME____________o () { return; }

char
BASE__duration          (long a_beg, long a_end)
{
   /*---(locals)-----------+-----+-----+-*/
   char        i           =    0;
   char        x_bit       [LEN_DESC]  = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(duration)-----------------------*/
   DEBUG_HFIX    yLOG_value   ("a_beg"     , a_beg);
   DEBUG_HFIX    yLOG_value   ("a_end"     , a_end);
   strcpy (x_bit, HFIX_age (a_beg, a_end));
   for (i = 0; i < 3; ++i) s_compile [MAX_ENTRY - 1][23 + i] = x_bit [i];
   /*---(show full)----------------------*/
   DEBUG_HFIX   yLOG_info    ("s_compile" , s_compile [MAX_ENTRY - 1]);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
BASE__time              (char a_type, long a_epoch)
{ 
   switch (a_type) {
   case 'b' :
      my.m_beg = a_epoch;
      DEBUG_HFIX    yLOG_value   ("my.m_beg"     , my.m_beg);
      break;
   case 'c' :
      my.m_cur = a_epoch;
      DEBUG_HFIX    yLOG_value   ("my.m_cur"     , my.m_cur);
      break;
   case 'e' :
      my.m_end = a_epoch;
      DEBUG_HFIX    yLOG_value   ("my.m_end"     , my.m_end);
      BASE__duration (my.m_beg, my.m_end);
      break;
   }
   return 1;
}

char BASE_starting  (void)   { return BASE__time ('b', time (NULL)); }
char BASE_finishing (void)   { return BASE__time ('e', time (NULL)); }


