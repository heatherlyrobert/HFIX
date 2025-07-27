#include "HFIX.h"
#include "yEXEC_solo.h"
#include "yEXEC_uver.h"



char
ACTS__precheck          (char c_super, char c_action, char c_phase, char c_unit)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        x_fail      =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(singular)-----------------------*/
   DEBUG_HFIX    yLOG_char    ("c_super"   , c_super);
   --rce;  if (c_super   == 0 || strchr (HFIX_SUPERS, c_super) == NULL) {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_super is not understood");
      else                   EXIM_trouble (""      , "c_super is not understood");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_action"  , c_action);
   --rce;  if (c_action  == 0 || strchr (HFIX_ACTION "ÿ", c_action) == NULL) {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_action is not understood");
      else                   EXIM_trouble (""      , "c_action is not understood");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_phase"   , c_phase);
   --rce;  if (c_phase == 0 || strchr (HFIX_PHASES, c_phase) == NULL) {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_phase is not understood");
      else                   EXIM_trouble (""      , "c_phase is not understood");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_unit"    , c_unit);
   --rce;  if (c_unit  == 0 || strchr ("y-", c_unit) == NULL) {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_unit is not understood");
      else                   EXIM_trouble (""      , "c_unit is not understood");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(super/action)-------------------*/
   switch (c_super) {
   case 'w'  :  if (strchr ("w"    , c_action) == NULL)  x_fail = 'y';   break;
   case 'W'  :  if (strchr ("wW"   , c_action) == NULL)  x_fail = 'y';   break;
   case 'c'  :  if (strchr ("c"    , c_action) == NULL)  x_fail = 'y';   break;
   case 'C'  :  if (strchr ("cC"   , c_action) == NULL)  x_fail = 'y';   break;
   case 'i'  :  if (strchr ("i"    , c_action) == NULL)  x_fail = 'y';   break;
   case 'I'  :  if (strchr ("iI"   , c_action) == NULL)  x_fail = 'y';   break;
   case 'u'  :  if (strchr ("u"    , c_action) == NULL)  x_fail = 'y';   break;
   case 'U'  :  if (strchr ("uU"   , c_action) == NULL)  x_fail = 'y';   break;
   case 'r'  :  if (strchr ("r"    , c_action) == NULL)  x_fail = 'y';   break;
   case 'R'  :  if (strchr ("rR"   , c_action) == NULL)  x_fail = 'y';   break;
   case 'm'  :  if (strchr ("m"    , c_action) == NULL)  x_fail = 'y';   break;
   case 'M'  :  if (strchr ("mM"   , c_action) == NULL)  x_fail = 'y';   break;
   case 'g'  :  if (strchr ("g"    , c_action) == NULL)  x_fail = 'y';   break;
   case 'G'  :  if (strchr ("gG"   , c_action) == NULL)  x_fail = 'y';   break;
   }
   DEBUG_HFIX    yLOG_char    ("combos"    , x_fail);
   --rce;  if (x_fail == 'y') {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "bad combination of c_super and c_action");
      else                   EXIM_trouble (""      , "bad combination of c_super and c_action");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(phases with c_actions)----------*/
   switch (c_action) {
   case 'w'  :  case 'W'  :  if (strchr ("-"    , c_phase) == NULL)  x_fail = 'y';   break;
   case 'c'  :  case 'C'  :  if (strchr ("[>"   , c_phase) == NULL)  x_fail = 'y';   break;
   case 'i'  :  case 'I'  :  if (strchr ("-"    , c_phase) == NULL)  x_fail = 'y';   break;
   case 'u'  :  case 'U'  :  if (strchr ("[>"   , c_phase) == NULL)  x_fail = 'y';   break;
   case 'r'  :  case 'R'  :  if (strchr ("-"    , c_phase) == NULL)  x_fail = 'y';   break;
   case 'm'  :  case 'M'  :  if (strchr ("-"    , c_phase) == NULL)  x_fail = 'y';   break;
   case 'g'  :  case 'G'  :  if (strchr ("[>"   , c_phase) == NULL)  x_fail = 'y';   break;
   }
   DEBUG_HFIX    yLOG_char    ("phases"    , x_fail);
   --rce;  if (x_fail == 'y') {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "bad combination of c_action and c_phase");
      else                   EXIM_trouble (""      , "bad combination of c_action and c_phase");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
ACTS__which             (char c_action, char r_cmd [LEN_HUND], char r_ext [LEN_TERSE], char c_unit)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        x_cmd       [LEN_HUND]  = "";
   char        x_ext       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_cmd   != NULL)   strcpy (r_cmd, "");
   if (r_ext   != NULL)   strcpy (r_ext, "");
   /*---(set values)---------------------*/
   --rce;  switch (c_action) {
   case 'w'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_wipe"     , LEN_HUND);  strcpy (x_ext, "wipe");   break;
   case 'W'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_WIPE"     , LEN_HUND);  strcpy (x_ext, "WIPE");   break;
   case 'c'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_comp"     , LEN_HUND);  strcpy (x_ext, ".c");     break;
   case 'C'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_COMP"     , LEN_HUND);  strcpy (x_ext, ".c");     break;
   case 'i'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_inst"     , LEN_HUND);  strcpy (x_ext, "inst");   break;
   case 'I'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_INST"     , LEN_HUND);  strcpy (x_ext, "INST");   break;
   case 'u'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_unit"     , LEN_HUND);  strcpy (x_ext, ".unit");  break;
   case 'U'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_UNIT"     , LEN_HUND);  strcpy (x_ext, ".unit");  break;
   case 'r'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_remv"     , LEN_HUND);  strcpy (x_ext, "remv");   break;
   case 'R'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_REMV"     , LEN_HUND);  strcpy (x_ext, "REMV");   break;
   case 'm'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_mans"     , LEN_HUND);  strcpy (x_ext, "mans");   break;
   case 'M'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_MANS"     , LEN_HUND);  strcpy (x_ext, "MANS");   break;
   case 'g'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_git"      , LEN_HUND);  strcpy (x_ext, "git");    break;
   case 'G'  :  strlcpy (x_cmd, "/bin/bash -c HFIX_GIT"      , LEN_HUND);  strcpy (x_ext, "GIT");    break;
   case 'ÿ'  :  strlcpy (x_cmd, "boomy     -c HFIX_testing"  , LEN_HUND);  strcpy (x_ext, ".c");     break;
   default   :
                DEBUG_HFIX  yLOG_note    ("c_action code not found");
                if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_action is not understood");
                else                   EXIM_trouble (""      , "c_action is not understood");
                DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
                return rce;
   }
   DEBUG_HFIX    yLOG_info    ("x_cmd"     , x_cmd);
   DEBUG_HFIX    yLOG_info    ("x_ext"     , x_ext);
   /*---(save-back)----------------------*/
   if (r_cmd   != NULL)   strlcpy (r_cmd, x_cmd, LEN_HUND);
   if (r_ext   != NULL)   strlcpy (r_ext, x_ext, LEN_TERSE);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
ACTS__begin             (char c_super, char c_action, char c_phase, char c_unit, int a_rpid)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_cmd       [LEN_HUND]  = "";
   char        x_ext       [LEN_TERSE] = "";
   char        x_bit       [LEN_LABEL] = "";
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX    yLOG_char    ("c_super"   , c_super);
   --rce;  if (c_super   == 0 || strchr (HFIX_SUPERS, c_super) == NULL) {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_super is not understood");
      else                   EXIM_trouble (""      , "c_super is not understood");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_action"  , c_action);
   --rce;  if (c_action  == 0 || strchr (HFIX_ACTION "ÿ", c_action) == NULL) {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_action is not understood");
      else                   EXIM_trouble (""      , "c_action is not understood");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_phase"   , c_phase);
   --rce;  if (c_phase != HFIX_BEG) {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_phase is not begin ([)");
      else                   EXIM_trouble (""      , "c_phase is not begin ([)");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(master data)--------------------*/
   rc = ACTS__which (c_action, x_cmd, x_ext, c_unit);
   DEBUG_HFIX    yLOG_value   ("which"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(clear files)--------------------*/
   rc = yENV_rm  (HFIX_LOG);
   DEBUG_HFIX    yLOG_char    ("HFIX_LOG"  , rc);
   rc = yENV_rm  (HFIX_OUT);
   DEBUG_HFIX    yLOG_char    ("HFIX_OUT"  , rc);
   rc = yENV_rm  (HFIX_BUF);
   DEBUG_HFIX    yLOG_char    ("HFIX_BUF"  , rc);
   /*---(prepare buf)--------------------*/
   if (strchr ("CU", c_action) != NULL) {
      DEBUG_HFIX    yLOG_note    ("continue from existing");
      if (c_unit == 'y')     rc = EXIM_import     (HFIX_BUF);
      else                   rc = EXIM_import     ("");
      DEBUG_HFIX    yLOG_value   ("import"    , rc);
      s_rpid = s_cur = s_end = 0;
      s_done = s_status = s_result = s_error = '-';
      s_result = '?';
      strcpy (s_label, "");
      ++s_cnt;
   } else {
      DEBUG_HFIX    yLOG_note    ("starting fresh");
      rc = COMP__clear (x_ext);
      DEBUG_HFIX    yLOG_value   ("clear"     , rc);
      rc = COMP__base  ();
      DEBUG_HFIX    yLOG_value   ("base"      , rc);
      /*---(log time)-----------------------*/
      s_beg  = time (NULL);
      DEBUG_HFIX    yLOG_value   ("s_beg"     , s_beg);
   }
   /*---(fork)---------------------------*/
   --rce; if (c_unit == 'y') {
      DEBUG_HFIX    yLOG_note    ("unit-test version, no fork/launch");
      s_rpid = a_rpid;
   } else {
      DEBUG_HFIX    yLOG_note    ("production version, fork/launch");
      s_rpid = yexec_ufork (x_cmd);
      if (s_rpid < 0) {
         DEBUG_HFIX    yLOG_note    ("fork/launch was unsuccessful");
         if (c_action == 'ÿ')   EXIM_trouble (HFIX_BUF, "fork/launch failed");
         else                   EXIM_trouble (""      , "fork/launch failed");
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      DEBUG_HFIX    yLOG_value   ("ufork"     , s_rpid);
      usleep (100000);  /*  0.1 second */
      rc     = yexec_uwait (s_rpid, s_label);
      DEBUG_HFIX    yLOG_char    ("uwait"     , rc);
      if      (rc == 0)                   ;
      else if (strchr ("r" , rc) != NULL) ;
      else if (strchr ("n#", rc) != NULL) ;
      else {
         DEBUG_HFIX    yLOG_note    ("fork/launch split but failed");
         if (c_action == 'ÿ')   EXIM_trouble (HFIX_BUF, "fork/launch split but failed");
         else                   EXIM_trouble (""      , "fork/launch split but failed");
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      DEBUG_HFIX    yLOG_note    ("successful fook/launch");
   }
   /*---(add progress label)-------------*/
   rc = COMP__mark_done ('[', "launched", 0);
   /*---(show results)-------------------*/
   if (c_unit == 'y')     rc = EXIM_export     (c_super, '?', HFIX_BUF);
   else                   rc = EXIM_export     (c_super, '?', "");
   DEBUG_HFIX    yLOG_value   ("export"    , rc);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return '-';
}

char
ACTS__result            (char a_done, char a_status, char a_error, char *r_result, char b_label [LEN_LABEL])
{
   /*---(locals)-----------+-----------+-*/
   char        x_result    =  '?';
   char        x_label     [LEN_LABEL] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_result != NULL)  *r_result = '?';
   if (b_label  != NULL)  strlcpy (x_label, b_label, LEN_LABEL);
   /*---(run-time)-----------------------*/
   DEBUG_HFIX    yLOG_char    ("a_done"    , a_done);
   DEBUG_HFIX    yLOG_char    ("a_status"  , a_status);
   if      (strchr ("r" , a_status) != NULL)         x_result = '?';
   else if (strchr ("n#", a_status) != NULL) {
      if (a_done == 'Y')  x_result = 'p';
      else                x_result = '?';
   }
   else if (strchr (YEXEC_FAILS, a_status) != NULL)  x_result = 'E';
   else if (strchr (YEXEC_BADDS, a_status) != NULL)  x_result = 'W';
   else if (strchr (YEXEC_BOOMS, a_status) != NULL)  x_result = 'W';
   else if (strchr (YEXEC_KILLS, a_status) != NULL)  x_result = 'W';
   else                                              x_result = 'X';
   DEBUG_HFIX    yLOG_char    ("x_result"  , x_result);
   /*---(done)---------------------------*/
   DEBUG_HFIX    yLOG_char    ("a_error"   , a_error);
   if (a_done == 'Y' && strchr ("EWX", x_result) == NULL) {
      if (a_error != '-') {
         x_result = a_error;
         strlcpy (x_label, "DONE", LEN_LABEL);
      }
   }
   DEBUG_HFIX    yLOG_char    ("x_result"  , x_result);
   /*---(save-back)----------------------*/
   if (r_result != NULL)  *r_result = x_result;
   if (b_label  != NULL)  strlcpy (b_label, x_label, LEN_LABEL);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
ACTS__check             (char c_super, char c_action, char c_phase, char c_unit, char a_status, char a_label [LEN_LABEL])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        rc_num      =    1;
   char        x_bit       [LEN_LABEL] = "";
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX    yLOG_char    ("c_super"   , c_super);
   --rce;  if (c_super   == 0 || strchr (HFIX_SUPERS, c_super) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_super is not understood");
      else                   EXIM_trouble (""      , "c_super is not understood");
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_action"  , c_action);
   --rce;  if (c_action  == 0 || strchr (HFIX_ACTION, c_action) == NULL) {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_action is not understood");
      else                   EXIM_trouble (""      , "c_action is not understood");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_phase"   , c_phase);
   --rce;  if (c_phase != HFIX_CHK) {
      if (c_unit == 'y')     EXIM_trouble (HFIX_BUF, "c_phase is not check (>)");
      else                   EXIM_trouble (""      , "c_phase is not check (>)");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(impport)------------------------*/
   if (c_unit == 'y') {
      rc = EXIM_import     (HFIX_BUF);
      DEBUG_HFIX    yLOG_value   ("import"    , rc);
   }
   /*---(new loop)-----------------------*/
   ++s_cnt;
   DEBUG_HFIX    yLOG_value   ("s_cnt"     , s_cnt);
   /*---(log time)-----------------------*/
   usleep (500000);  /* 0.5s */
   /*> sleep (1);                                                                     <*/
   s_cur  = time (NULL);
   DEBUG_HFIX    yLOG_value   ("s_cur"     , s_cur);
   /*---(check)--------------------------*/
   DEBUG_HFIX    yLOG_char    ("s_done"    , s_done);
   DEBUG_HFIX    yLOG_value   ("s_rpid"    , s_rpid);
   if (s_rpid > 0 && strchr ("Yy", s_done) == NULL) {
      /*---(check files)-----------------*/
      COMP__chk ();
      /*---(check process)---------------*/
      if (c_unit == 'y') {
         s_status = a_status;
         strlcpy (s_label, a_label, LEN_LABEL);
      } else  {
         s_status = yexec_uwait (s_rpid, s_label);
      }
      DEBUG_HFIX    yLOG_char    ("uwait"     , s_status);
      DEBUG_HFIX    yLOG_info    ("s_label"   , s_label);
      /*---(relabel updates)-------------*/
      if (s_status == '#') strcpy (s_label, "DONE");
      /*---(handle compelete)------------*/
      if (s_status != 'r') {
         s_done   = 'y';
         s_rpid   =  0;
      }
      /*---(result assignment)-----------*/
      rc = ACTS__result  (s_done, s_status, s_error, &s_result, s_label);
      /*> if      (strchr ("r" , s_status) != NULL)         s_result = '?';           <* 
       *> else if (strchr ("n#", s_status) != NULL)         s_result = 'p';           <* 
       *> else if (strchr (YEXEC_FAILS, s_status) != NULL)  s_result = 'E';           <* 
       *> else if (strchr (YEXEC_BADDS, s_status) != NULL)  s_result = 'W';           <* 
       *> else if (strchr (YEXEC_BOOMS, s_status) != NULL)  s_result = 'W';           <* 
       *> else if (strchr (YEXEC_KILLS, s_status) != NULL)  s_result = 'W';           <* 
       *> else                                              s_result = 'X';           <*/
      DEBUG_HFIX    yLOG_char    ("s_result"  , s_result);
      /*---(update elapsed)--------------*/
      rc = COMP__mark_done (s_status, s_label, s_cnt);
      /*---(done)------------------------*/
   }
   /*---(show results)-------------------*/
   if (c_unit == 'y') {
      rc = EXIM_export     (c_super, s_result, HFIX_BUF);
      DEBUG_HFIX    yLOG_value   ("export"    , rc);
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return s_done;
}

char
ACTS__find_ends         (char c_action, char a_recd [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        l           =    0;
   char        x_beg       [LEN_DESC]  = "";
   char        x_end       [LEN_DESC]  = "";
   char        x_tmp       [LEN_DESC]  = "";
   char        x_make      =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX    yLOG_char    ("c_action"  , c_action);
   --rce;  if (c_action == 0 || strchr ("cCuUiImMwW", c_action) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_point   ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_info    ("a_recd"    , a_recd);
   /*---(set endpoints)------------------*/
   --rce;  switch (c_action) {
   case 'c' : case 'C' :
      DEBUG_HFIX  yLOG_note    ("ends are code types");
      strlcpy (x_beg, "##===[[ CODE_BEGIN ]]=======", LEN_DESC);
      strlcpy (x_end, "##---[[ CODE_END ]]---------", LEN_DESC);
      break;
   case 'u' : case 'U' :
      DEBUG_HFIX  yLOG_note    ("ends are unit types");
      strlcpy (x_beg, "##===[[ UNIT_BEGIN ]]=======", LEN_DESC);
      strlcpy (x_end, "##---[[ UNIT_END ]]---------", LEN_DESC);
      break;
   case 'i' : case 'I' :
      DEBUG_HFIX  yLOG_note    ("ends are install types");
      strlcpy (x_beg, "##===[[ INST_BEGIN ]]=======", LEN_DESC);
      strlcpy (x_end, "##---[[ INST_END ]]---------", LEN_DESC);
      break;
   case 'm' : case 'M' :
      DEBUG_HFIX  yLOG_note    ("ends are manual types");
      strlcpy (x_beg, "##===[[ MANS_BEGIN ]]=======", LEN_DESC);
      strlcpy (x_end, "##---[[ MANS_END ]]---------", LEN_DESC);
      break;
   case 'w' : case 'W' :
      DEBUG_HFIX  yLOG_note    ("ends are clean/wipe types");
      strlcpy (x_beg, "##===[[ WIPE_BEGIN ]]=======", LEN_DESC);
      strlcpy (x_end, "##---[[ WIPE_END ]]---------", LEN_DESC);
      break;
   default  :
      DEBUG_HFIX  yLOG_note    ("c_action not known");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(update for recons)--------------*/
   if (tolower (c_action) == c_action) {
      DEBUG_HFIX  yLOG_note    ("lower case action, need to prefix strings");
      snprintf (x_tmp, LEN_DESC, "printf \"\\n%s", x_beg);
      strlcpy  (x_beg, x_tmp, LEN_DESC);
      snprintf (x_tmp, LEN_DESC, "printf \"\\n%s", x_end);
      strlcpy  (x_end, x_tmp, LEN_DESC);
   }
   /*---(display)------------------------*/
   DEBUG_HFIX    yLOG_info    ("x_beg"     , x_beg);
   DEBUG_HFIX    yLOG_info    ("x_end"     , x_end);
   /*---(check endpoints)----------------*/
   l = strlen (x_beg);
   if (strncmp (a_recd, x_beg, l) == 0) {
      DEBUG_HFIX  yLOG_note    ("beginning matched");
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 'b';
   }
   l = strlen (x_end);
   if (strncmp (a_recd, x_end, l) == 0) {
      DEBUG_HFIX  yLOG_note    ("end matched");
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 'e';
   }
   /*---(filter other titles)------------*/
   if (strncmp (a_recd, "##===[[ ", 8) == 0) {
      DEBUG_HFIX  yLOG_note    ("unclaimed begin prod-title lines");
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 1;
   }
   if (strncmp (a_recd, "##---[[ ", 8) == 0) {
      DEBUG_HFIX  yLOG_note    ("unclaimed end prod-title lines");
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 1;
   }
   if (strncmp (a_recd, "printf ", 7) == 0) {
      DEBUG_HFIX  yLOG_note    ("unclaimed printf/recon-title lines");
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(check for make done)------------*/
   if (strncmp ("make", a_recd, 4) == 0)     x_make  = 1;
   DEBUG_HFIX    yLOG_value   ("x_make"    , x_make);
   if (x_make) {
      if (strstr  (a_recd, " Nothing to be done for ") != NULL) {
         DEBUG_HFIX  yLOG_note    ("make reports nothing to do (4)");
         DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
         return 'e';
      }
      if (strstr  (a_recd, "Leaving directory ") != 0) {
         DEBUG_HFIX  yLOG_note    ("hit final gcc/make line in file");
         DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
         return 'e';
      }
      if (strstr  (a_recd, " Error ")!= 0) {
         DEBUG_HFIX  yLOG_note    ("hit final fatal make error in file");
         DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
         return 'E';
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
ACTS__filter_gcc        (char c_action, char a_recd [LEN_RECD], char **r_namish)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *p           = NULL;
   char       *q           = NULL;
   char        l           =    0;
   char        x_whoami    [LEN_LABEL] = "";
   char        x_final     [LEN_LABEL] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_namish  != NULL)   *r_namish  = NULL;
   /*---(defense)------------------------*/
   DEBUG_HFIX    yLOG_char    ("c_action"  , c_action);
   --rce;  if (c_action == 0 || strchr ("cCuU", c_action) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_point   ("a_recd"    , a_recd);
   --rce;  if (a_recd == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_info    ("a_recd"    , a_recd);
   /*---(prepare)---------------------*/
   strlcpy (x_whoami, s_whoami, LEN_LABEL);
   DEBUG_HFIX    yLOG_info    ("x_whoami"  , x_whoami);
   l = strlen (x_whoami);
   if (x_whoami [l - 1] == '_')  x_whoami [l - 1] = '\0';
   sprintf (x_final, "gcc  -o %s ", x_whoami);
   DEBUG_HFIX    yLOG_info    ("x_final"   , x_final);
   l = strlen (x_final);
   /*---(true end of process)---------*/
   if (strncmp  (a_recd, x_final, l) == 0) {
      DEBUG_HFIX  yLOG_note    ("hit final useful recon line in file (2)");
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 'e';
   }
   /*---(only gcc lines)-----------------*/
   if (strncmp ("gcc -std=", a_recd,  9) != 0) {
      DEBUG_HFIX  yLOG_note    ("does not start with ¶gcc -std=¶ (0)");
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 0;
   }
   p = strstr (a_recd, " -c ");
   DEBUG_HFIX    yLOG_point   ("p"         , p);
   if (p == NULL)  {
      DEBUG_HFIX  yLOG_note    ("no ¶-c¶ option request");
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 0;
   }
   p += 4;
   /*---(skip ahead for library)------*/
   q = strstr (a_recd, " -fPIC ");
   DEBUG_HFIX    yLOG_point   ("q"         , q);
   if (q != NULL)  {
      DEBUG_HFIX  yLOG_note    ("found and adjusted for ¶-fPIC¶ field");
      p = q + 7;
   }
   /*---(save-back)----------------------*/
   if (r_namish  != NULL)   *r_namish  = p;
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
ACTS__filename          (char c_action, char *a_start, char r_name [LEN_TITLE], char *r_style, char *r_type)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        x_type      =  '-';
   char        x_style     =  'r';
   char        x_beg       [LEN_LABEL] = "";
   char        x_end       [LEN_LABEL] = "";
   char        x_name      [LEN_TITLE] = "";
   int         i           =    0;
   char       *p           = NULL;
   char       *q           = NULL;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_name   != NULL)  strcpy (r_name, "");
   if (r_style  != NULL)  *r_style = '-';
   if (r_type   != NULL)  *r_type  = '-';
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_char    ("c_action"  , c_action);
   --rce;  if (c_action  == 0 || strchr ("cCuU", c_action) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_point   ("a_start"   , a_start);
   --rce;  if (a_start == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_info    ("a_start"   , a_start);
   /*---(prepare)------------------------*/
   --rce;  switch (c_action) {
   case 'c' : case 'u' :  /* recon */
      x_style = 'r';
      break;
   case 'C' : case 'U' :  /* make  */
      x_style = 'm';
      break;
   default  :
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("x_style"   , x_style);
   --rce;  switch (c_action) {
   case 'c' : case 'C' :  /* c-sources    */
      strcpy (x_beg, ".c ");
      strcpy (x_end, ".cs ");
      break;
   case 'u' : case 'U' :  /* unit testing */
      strcpy (x_beg, "_unit.c ");
      strcpy (x_end, "_unit.cs ");
      break;
   default  :
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_info    ("x_beg"     , x_beg);
   DEBUG_HFIX    yLOG_info    ("x_end"     , x_end);
   /*---(check source type)--------------*/
   q = strstr (a_start, x_beg);
   DEBUG_HFIX    yLOG_point   ("q"         , q);
   if (q != NULL)  {
      DEBUG_HFIX  yLOG_note    ("found ¶.c¶ or ¶_unit.c¶ compile beginning line");
      x_type = 'b';
   } else {
      q = strstr (a_start, x_end);
      DEBUG_HFIX    yLOG_point   ("q"         , q);
      if (q != NULL)  {
         DEBUG_HFIX  yLOG_note    ("found ¶.cs¶ or ¶_unit.cs¶ compile ending line");
         x_type = 'e';
      } else {
         DEBUG_HFIX  yLOG_note    ("source extension is not ¶.c¶ or ¶.cs¶");
         DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
         return 0;
      }
   }
   DEBUG_HFIX    yLOG_char    ("x_type"    , x_type);
   /*---(cut off extension)--------------*/
   q [0] = '\0';
   p     = q;
   DEBUG_HFIX  yLOG_info    ("p"         , p);
   if (x_type == 'e' && x_style == 'r') {
      DEBUG_HFIX  yLOG_note    ("recon does not care about ends");
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(parse)--------------------------*/
   for (i = -1; i > -30; --i) {
      --p;
      DEBUG_HFIX  yLOG_char    ("p [0]"     , p [0]);
      if (p [0] == ' ') {
         strlcpy (x_name, p + 1, LEN_TITLE);
         break;
      }
   }
   /*---(check name)---------------------*/
   DEBUG_HFIX  yLOG_info    ("x_name"    , x_name);
   if (strcmp (x_name, "") == 0) {
      DEBUG_HFIX  yLOG_note    ("source file name not found");
      DEBUG_HFIX  yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(update marker)------------------*/
   if (x_style == 'r')  x_type = 'n';
   DEBUG_HFIX    yLOG_char    ("x_type"    , x_type);
   /*---(save-back)----------------------*/
   if (r_name   != NULL)  strcpy (r_name, x_name);
   if (r_style  != NULL)  *r_style = x_style;
   if (r_type   != NULL)  *r_type  = x_type;
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
ACTS__progress          (char c_action)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_ch        =  '-';
   FILE       *f           = NULL;
   char        x_recd      [LEN_RECD]  = "";
   char        x_check     =  '-';
   short       c           =    0;
   char        x_name      [LEN_TITLE] = "";
   char        x_off       =    0;
   char        x_bit       [LEN_TERSE] = "";
   char        x_type      =  '-';
   char        x_style     =  'r';
   char       *x_namish    = NULL;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_char    ("c_action"  , c_action);
   --rce;  if (c_action  == 0 || strchr ("cCuU", c_action) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(update style of run)------------*/
   if (strchr ("CU", c_action) != NULL)  x_style = 'm';
   /*---(quick-out)----------------------*/
   x_ch = s_compile [MAX_ENTRY - 1][13];
   DEBUG_HFIX  yLOG_char    ("recon"     , x_ch);
   --rce;  if (x_style == 'm' && x_ch == '-') {
      DEBUG_HFIX  yLOG_note    ("recon has not run first");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(open)---------------------------*/
   rc = BASE__open  (HFIX_OUT, NULL, NULL, &f);
   DEBUG_HFIX  yLOG_value   ("open"      , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle lines)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      rc = BASE__read (f, NULL, NULL, x_recd);
      DEBUG_HFIX  yLOG_value   ("read"      , rc);
      if (rc == 0) {
         DEBUG_HFIX  yLOG_note    ("hit end-of-file");
         break;
      }
      /*---(check ends)------------------*/
      rc = ACTS__find_ends (c_action, x_recd);
      DEBUG_HFIX  yLOG_value   ("ends"      , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      if (rc == 'b') {
         DEBUG_HFIX  yLOG_note    ("found beg, start capturing");
         x_check = 'y';
         continue;
      }
      if (rc == 'e' || rc == 'E') {
         DEBUG_HFIX  yLOG_note    ("found end line, completed");
         s_done = 'Y';
         if (rc == 'E')  s_error = 'y';
         ;
      }
      DEBUG_HFIX  yLOG_char    ("x_check"   , x_check);
      if (rc == 1 || x_check == '-') {
         DEBUG_HFIX  yLOG_note    ("ignoring input");
         continue;
      }
      /*---(filter)----------------------*/
      rc = ACTS__filter_gcc (c_action, x_recd, &x_namish);
      DEBUG_HFIX  yLOG_value   ("filter"    , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      if (rc == 0) {
         DEBUG_HFIX  yLOG_note    ("line not useful, skipping");
         continue;
      }
      if (rc == 'e') {
         DEBUG_HFIX  yLOG_note    ("found end line, completed");
         s_done = 'Y';
         break;
      }
      /*---(file name)-------------------*/
      rc = ACTS__filename (c_action, x_namish, x_name, NULL, &x_type);
      DEBUG_HFIX  yLOG_value   ("filename"  , rc);
      if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      if (rc == 0) {
         DEBUG_HFIX  yLOG_note    ("line not useful, skipping");
         continue;
      }
      /*---(capture)---------------------*/
      rc = COMP__mark (x_name, x_type);
      DEBUG_HFIX  yLOG_value   ("marked"    , rc);
      if (x_type != 'b')  ++c;
      /*---(done)------------------------*/
   }
   DEBUG_HFIX  yLOG_char    ("s_done"    , s_done);
   DEBUG_HFIX  yLOG_value   ("c"         , c);
   /*---(close)--------------------------*/
   rc = BASE__close (&f);
   DEBUG_HFIX  yLOG_value   ("close"     , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f != NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(update total)-------------------*/
   sprintf (x_bit, "%2d", c);
   if (x_bit [0] == ' ')  x_bit [0] = '·';
   if (x_bit [1] == ' ')  x_bit [1] = '·';
   if (c == 0)            x_bit [1] = '/';
   if (x_style == 'm')  x_off = 17;
   else                 x_off = 12;
   s_compile [MAX_ENTRY - 1][x_off + 0] = x_bit [0];
   s_compile [MAX_ENTRY - 1][x_off + 1] = x_bit [1];
   if (x_style == 'r')  s_compile [MAX_ENTRY - 1][x_off + 2] = 'n';
   else                 s_compile [MAX_ENTRY - 1][x_off + 2] = 'c';
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return c;
}

char
ACTS__progress_OLD      (char c_action)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_ch        =  '-';
   FILE       *f           = NULL;
   char        x_recd      [LEN_RECD]  = "";
   int         i           =    0;
   short       c           =    0;
   char        x_name      [LEN_TITLE] = "";
   char       *p           = NULL;
   char       *q           = NULL;
   char        x_off       =    0;
   char        x_bit       [LEN_TERSE] = "";
   char        x_type      =  '-';
   char        x_style     =  'r';
   char        x_beg       [LEN_LABEL] = "";
   char        x_end       [LEN_LABEL] = "";
   char        x_done      =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX  yLOG_char    ("c_action"  , c_action);
   --rce;  if (c_action  == 0 || strchr ("cCuU", c_action) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   switch (c_action) {
   case 'c' : case 'u' :  x_style = 'r';  break;  /* recon */
   case 'C' : case 'U' :  x_style = 'm';  break;  /* make  */
   }
   switch (c_action) {
   case 'c' : case 'C' :  /* c-sources    */
      strcpy (x_beg, ".c   ");
      strcpy (x_end, ".cs   ");
      break;
   case 'u' : case 'U' :  /* unit testing */
      strcpy (x_beg, "_unit.c   ");
      strcpy (x_end, "_unit.cs   ");
      break;
   }
   x_ch = s_compile [MAX_ENTRY - 1][13];
   DEBUG_HFIX  yLOG_char    ("recon"     , x_ch);
   --rce;  if (x_style == 'm' && x_ch == '-') {
      DEBUG_HFIX  yLOG_note    ("recon has not run first");
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(open)---------------------------*/
   rc = BASE__open  (HFIX_OUT, NULL, NULL, &f);
   DEBUG_HFIX  yLOG_value   ("open"      , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle lines)-------------------*/
   while (1) {
      /*---(read)------------------------*/
      rc = BASE__read (f, NULL, NULL, x_recd);
      DEBUG_HFIX  yLOG_value   ("read"      , rc);
      if (rc == 0) {
         DEBUG_HFIX  yLOG_note    ("hit end-of-file");
         break;
      }
      /*---(check for done)--------------*/
      if (strncmp ("make", x_recd, 4) == 0 && strstr  (x_recd, "Leaving directory ") != 0) {
         DEBUG_HFIX  yLOG_note    ("hit final gcc/make line in file");
         x_done = 'Y';
         break;
      }
      if (strncmp ("make", x_recd, 4) == 0 && strstr  (x_recd, " Error ")!= 0) {
         DEBUG_HFIX  yLOG_note    ("hit final fatal make error in file");
         x_done = 'Y';
         break;
      }
      /*---(filter)----------------------*/
      if (strncmp ("gcc -std=", x_recd,  9) != 0) {
         DEBUG_HFIX  yLOG_note    ("does not start with ¶gcc -std=¶");
         continue;
      }
      p = strstr (x_recd, " -c ");
      if (p == NULL)  {
         DEBUG_HFIX  yLOG_note    ("no ¶-c¶ option request");
         continue;
      }
      /*---(skip ahead for library)------*/
      q = strstr (x_recd, " -fPIC ");
      if (q != NULL)  {
         DEBUG_HFIX  yLOG_note    ("found ¶-fPIC¶ field");
         p = q + 7;
      }
      /*---(check source type)-----------*/
      x_type = '-';
      q = strstr (p, x_beg);
      if (q != NULL)  {
         DEBUG_HFIX  yLOG_note    ("found ¶.c¶ or ¶_unit.c¶ compile beginning line");
         x_type = 'b';
      } else {
         q = strstr (p, x_end);
         if (q != NULL)  {
            DEBUG_HFIX  yLOG_note    ("found ¶.cs¶ or ¶_unit.cs¶ compile ending line");
            x_type = 'e';
         } else {
            DEBUG_HFIX  yLOG_note    ("source extension is not ¶.c¶ or ¶.cs¶");
            continue;
         }
      }
      q [0] = '\0';
      p     = q;
      DEBUG_HFIX  yLOG_info    ("p"         , p);
      if (x_type == 'e' && x_style == 'r') {
         DEBUG_HFIX  yLOG_note    ("recon does not care about ends");
         continue;
      }
      /*---(parse)-----------------------*/
      for (i = -1; i > -30; --i) {
         --p;
         DEBUG_HFIX  yLOG_char    ("p [0]"     , p [0]);
         if (p [0] == ' ') {
            strlcpy (x_name, p + 1, LEN_TITLE);
            break;
         }
      }
      DEBUG_HFIX  yLOG_info    ("x_name"    , x_name);
      if (strcmp (x_name, "") == 0) {
         DEBUG_HFIX  yLOG_note    ("source file name not found");
         continue;
      }
      if (x_style == 'r')  x_type = 'n';
      rc = COMP__mark (x_name, x_type);
      DEBUG_HFIX  yLOG_value   ("marked"    , rc);
      if (x_type != 'b')  ++c;
      /*---(done)------------------------*/
   }
   DEBUG_HFIX  yLOG_value   ("c"         , c);
   /*---(close)--------------------------*/
   rc = BASE__close (&f);
   DEBUG_HFIX  yLOG_value   ("close"     , rc);
   DEBUG_HFIX  yLOG_point   ("f"         , f);
   --rce;  if (rc < 1 || f != NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(update total)-------------------*/
   sprintf (x_bit, "%2d", c);
   if (x_bit [0] == ' ')  x_bit [0] = '·';
   if (x_bit [1] == ' ')  x_bit [1] = '·';
   if (c == 0)            x_bit [1] = '/';
   if (x_style == 'm')  x_off = 17;
   else                 x_off = 12;
   s_compile [MAX_ENTRY - 1][x_off + 0] = x_bit [0];
   s_compile [MAX_ENTRY - 1][x_off + 1] = x_bit [1];
   if (x_style == 'r')  s_compile [MAX_ENTRY - 1][x_off + 2] = 'n';
   else                 s_compile [MAX_ENTRY - 1][x_off + 2] = 'c';
   /*---(real done)----------------------*/
   if (x_done == 'Y') {
      DEBUG_HFIX  yLOG_note    ("all data read including end marker");
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 'Y';
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return c;
}

char
ACTS_single             (char c_super, char c_action, char c_phase)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_bit       [LEN_LABEL] = "";
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_HFIX    yLOG_char    ("c_super"   , c_super);
   --rce;  if (c_super   == 0 || strchr (HFIX_SUPERS, c_super) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_action"  , c_action);
   --rce;  if (c_action  == 0 || strchr (HFIX_ACTION, c_action) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_HFIX    yLOG_char    ("c_phase"   , c_phase);
   --rce;  if (c_phase == 0 || strchr (HFIX_PHASES, c_phase) == NULL) {
      DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(beginning)----------------------*/
   if (c_phase == HFIX_BEG) {
      DEBUG_HFIX    yLOG_note    ("running a fork/start");
      rc = ACTS__begin (c_super, c_action, c_phase, '-', 0);
      DEBUG_HFIX    yLOG_value   ("begin"     , rc);
      --rce;  if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(checking)-----------------------*/
   else if (c_phase == HFIX_CHK) {
      DEBUG_HFIX    yLOG_note    ("running a check/progress");
      /*---(quick-out)-------------------*/
      DEBUG_HFIX    yLOG_char    ("s_done"    , s_done);
      if (s_done == 'Y') {
         DEBUG_HFIX    yLOG_note    ("nothing to do, already done");
         DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
         return s_done;
      }
      /*---(import)----------------------*/
      rc = EXIM_import     ("");
      DEBUG_HFIX    yLOG_value   ("import"    , rc);
      /*---(check process)---------------*/
      if (s_done != 'y') {
         DEBUG_HFIX    yLOG_note    ("process not complete, must check");
         rc = ACTS__check (c_super, c_action, c_phase, '-', '-', "");
         DEBUG_HFIX    yLOG_value   ("check"     , rc);
         --rce;  if (rc < 0) {
            DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
            return rce;
         }
      } else {
         DEBUG_HFIX    yLOG_note    ("process complete, do not check");
         s_cur  = time (NULL);
         DEBUG_HFIX    yLOG_value   ("s_cur"     , s_cur);
         usleep (500000);  /* 0.5s */
         ++s_cnt;
         DEBUG_HFIX    yLOG_value   ("s_cnt"     , s_cnt);
      }
      /*---(check results)---------------*/
      rc = ACTS__progress (c_action);
      DEBUG_HFIX    yLOG_value   ("progress"  , rc);
      --rce;  if (rc < 0) {
         DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      /*---(finalize)--------------------*/
      if (s_done == 'Y') {
         s_end  = time (NULL);
         strcpy (x_bit, HFIX_age (s_beg, s_end));
         for (i = 0; i < 3; ++i) s_compile [MAX_ENTRY - 1][23 + i] = x_bit [i];
         strcpy (s_label, "DONE");
      } else if (s_done == 'y') {
         strcpy (s_label, "processing");
      }
      rc = ACTS__result    (s_done, s_status, s_error, &s_result, s_label);
      rc = COMP__mark_done (s_status, s_label, s_cnt);
      /*---(export)----------------------*/
      rc = EXIM_export     (c_super, s_result, "");
      DEBUG_HFIX    yLOG_value   ("export"    , rc);
      /*---(done)------------------------*/
   }
   /*---(unknown phase)------------------*/
   else {
      DEBUG_HFIX    yLOG_note    ("unknown request");
      DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)------------------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return s_done;
}



