#include "HFIX.h"



struct cGROUPS {
   char        g_type;                     /* wipe vs inst */
   char        g_col;
   char        g_act;                      /* actually wipe/remove them (y/-)          */
   char        g_name        [LEN_HUND];
   char        g_pre         [LEN_LABEL];
   char        g_suf         [LEN_LABEL];
   char        g_not         [LEN_LABEL];  /* string that can not be included in name */
   char        g_group       [LEN_LABEL];  /* only use 14 for screen formatting */
} const s_groups [LEN_FULL] = {
   /*cntr -type -act- --name------------------ ---prefix---- ----suffix----- ---not------- ---group---------*/
   { 'w' , 'u' , 'y' , "master.h"             , ""          , ""            , ""          , "unit·header"   },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_unit.c"     , ""          , "unit·src"      },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_munit.c"    , ""          , "unit·src"      },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_unit.cs"    , ""          , "unit·src·strp" },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_munit.cs"   , ""          , "unit·src·strp" },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_unit.o"     , ""          , "unit·obj"      },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_munit.o"    , ""          , "unit·obj"      },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_unit.os"    , ""          , "unit·obj·strp" },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_munit.os"   , ""          , "unit·obj·strp" },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_unit"       , ""          , "unit·exec"     },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_munit"      , ""          , "unit·exec"     },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_unit_debug" , ""          , "unit·debug"    },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , "_munit_debug", ""          , "unit·debug"    },
   { 'w' , 'u' , 'y' , ""                     , "(proj)"    , ".urun"       , ""          , "unit·output"   },
   { 'w' , 'u' , 'y' , "master.globals"       , ""          , ""            , ""          , "unit·work"     },
   /*cntr -type -act- --name------------------ ---prefix---- ----suffix----- ---not------- ---group---------*/
   { 'w' , 'c' , 'y' , ""                     , "(proj)"    , ".cs"         , ""          , "main·src·strp" },
   { 'w' , 'c' , 'y' , ""                     , "(proj)"    , ".Sc"         , ""          , "main·src·strp" },
   { 'w' , 'c' , 'y' , ""                     , "(proj)"    , ".o"          , ""          , "main·obj"      },
   { 'w' , 'c' , 'y' , ""                     , "(proj)"    , ".os"         , ""          , "main·obj·strp" },
   { 'w' , 'c' , 'y' , ""                     , "(proj)"    , ".So"         , ""          , "main·obj·strp" },
   { 'w' , 'c' , 'y' , "(PROJ)"               , ""          , ""            , ""          , "main·exec"     },
   { 'w' , 'c' , 'y' , ""                     , "(PROJ)"    , "_debug"      , ""          , "main·debug"    },
   { 'w' , 'c' , 'y' , ""                     , "(libPROJ)" , ".so"         , ""          , "main·shared"   },
   { 'w' , 'c' , 'y' , ""                     , "(libPROJ)" , ".a"          , ""          , "main·static"   },
   /*cntr -type -act- --name------------------ ---prefix---- ----suffix----- ---not------- ---group---------*/
   { 'w' , 't' , 'y' , ""                     , ""          , "~"           , ""          , "temp·files"    },
   { 'w' , 't' , 'y' , ""                     , ""          , ".tmp"        , ""          , "temp·files"    },
   { 'w' , 't' , '-' , ""                     , ""          , ".backup"     , ""          , "save·CAUTION"  },
   { 'w' , 't' , '-' , ""                     , ""          , ".old"        , ""          , "save·CAUTION"  },
   { 'w' , 't' , '-' , ""                     , ""          , ".save"       , ""          , "save·CAUTION"  },
   { 'w' , 't' , '-' , ""                     , ""          , ".swo"        , ""          , "swap·CAUTION"  },
   { 'w' , 't' , '-' , ""                     , ""          , ".swp"        , ""          , "swap·CAUTION"  },
   { 'w' , 't' , '-' , ""                     , ""          , ".swn"        , ""          , "swap·CAUTION"  },
   { 'w' , 't' , 'y' , "HFIX.log"             , ""          , ""            , ""          , "HFIX·working"  },
   { 'w' , 't' , 'y' , "HFIX.out"             , ""          , ""            , ""          , "HFIX·working"  },
   { 'w' , 't' , 'y' , "HFIX.buf"             , ""          , ""            , ""          , "HFIX·working"  },
   { 'w' , 't' , 'y' , "gcc.out"              , ""          , ""            , ""          , "HFIX·working"  },
   { 'w' , 't' , 'y' , ""                     , ""          , ".lcalls"     , ""          , "HTAG·working"  },
   { 'w' , 't' , 'y' , ""                     , ""          , ".gcalls"     , ""          , "HTAG·working"  },
   { 'w' , 't' , 'y' , ""                     , ""          , ".depth"      , ""          , "HTAG·working"  },
   { 'w' , 't' , 'y' , ""                     , ""          , ".htags"      , ""          , "polymnia·work" },
   { 'w' , 't' , 'y' , "htags.stats"          , ""          , ""            , ""          , "polymnia·work" },
   { 'w' , 't' , 'y' , "htags.code"           , ""          , ""            , ""          , "polymnia·work" },
   { 'w' , 't' , 'y' , ""                     , ""          , ".mystry"     , ""          , "polymnia·work" },
   { 'w' , 't' , 'y' , ""                     , ""          , ".ylid"       , ""          , "polymnia·work" },
   { 'w' , 't' , 'y' , ","                    , ""          , ""            , ""          , "fat·fingers"   },
   { 'w' , 't' , 'y' , ",q"                   , ""          , ""            , ""          , "fat·fingers"   },
   { 'w' , 't' , 'y' , ",qq"                  , ""          , ""            , ""          , "fat·fingers"   },
   { 'w' , 't' , 'y' , ":w"                   , ""          , ""            , ""          , "fat·fingers"   },
   { 'w' , 't' , 'y' , ":{"                   , ""          , ""            , ""          , "fat·fingers"   },
   /*cntr -type -act- --name------------------ ---prefix---- ----suffix----- ---not------- ---group---------*/
   { 'i' , 'm' , 'y' , ""                     , "(PROJ)"    , ".1"          , ""          , "man·1·cmdline" },
   { 'i' , 'm' , 'y' , ""                     , "(PROJ)"    , ".3"          , ""          , "man·3·library" },
   { 'i' , 'm' , 'y' , ""                     , "(PROJ)"    , ".4"          , ""          , "man·4·shared"  },
   { 'i' , 'm' , 'y' , ""                     , "(PROJ)"    , ".5"          , ""          , "man·5·files"   },
   { 'i' , 'm' , 'y' , ""                     , "(PROJ)"    , ".6"          , ""          , "man·6·using"   },
   { 'i' , 'm' , 'y' , ""                     , "(PROJ)"    , ".7"          , ""          , "man·7·purpose" },
   { 'i' , 'm' , 'y' , ""                     , "(PROJ)"    , ".8"          , ""          , "man·8·sysadm"  },
   { 'i' , 'm' , 'y' , ""                     , "(PROJ)"    , ".9"          , ""          , "man·9·gui-std" },
   /*cntr -type -act- --name------------------ ---prefix---- ----suffix----- ---not------- ---group---------*/
   { 'i' , 'e' , 'y' , "(PROJ)"               , ""          , ""            , ""          , "main·exec"     },
   { 'i' , 'e' , 'y' , ""                     , "(PROJ)"    , "_debug"      , "_unit_"    , "main·debug"    },
   { 'i' , 'e' , 'y' , ""                     , "(libPROJ)" , ".so"         , ""          , "main·shared"   },
   { 'i' , 'e' , 'y' , ""                     , "(libPROJ)" , ".so.¬.¬.¬"   , ""          , "main·shared"   },
   { 'i' , 'e' , 'y' , ""                     , "(libPROJ)" , ".a"          , ""          , "main·static"   },
   { 'i' , 'e' , 'y' , "----"                 , ""          , ""            , ""          , "main·LINKS"    },
   /*cntr -type -act- --name------------------ ---prefix---- ----suffix----- ---not------- ---group---------*/
   { 'i' , 'o' , 'y' , ""                     , "(PROJ)"    , ".sh"         , ""          , "bash·script"   },
   { 'i' , 'o' , 'y' , "----"                 , ""          , ""            , ""          , "script·LINKS"  },
   { 'i' , 'o' , 'y' , ""                     , "(PROJ)"    , ".vim"        , ""          , "vim·script"    },
   { 'i' , 'o' , 'y' , ""                     , "(proj)"    , "_solo.h"     , ""          , "solo·header"   },
   { 'i' , 'o' , 'y' , ""                     , "(proj)"    , "_uver.h"     , ""          , "uver·header"   },
   { 'i' , 'o' , 'y' , ""                     , "(proj)"    , ".h"          , ""          , "main·header"   },
   /*cntr -type -act- --name------------------ ---prefix---- ----suffix----- ---not------- ---group---------*/
   {  0  ,  0  ,  0  , "end-of-list"          , ""          , ""            , ""          , ""              },
   /*cntr -type -act- --name------------------ ---prefix---- ----suffix----- ---not------- ---group---------*/
};



/*====================------------------------------------====================*/
/*===----                    creating base for work                    ----===*/
/*====================------------------------------------====================*/
static void  o___BASE____________o () { return; }

char
MAINT__base             (char c_maintset)
{
   /*---(locals)-----------+-----+-----+-*/
   int         rc          =    0;
   char        rce         =  -10;
   int         i           =    0;
   char        x_col       =    0;
   char        x_rows      [LEN_SHORT] = "";
   int         n           =    0;
   char        x_pos       =    0;
   char        x_name      [LEN_TITLE] = "";
   char        x_full      [LEN_TITLE] = "";
   int         x_total     =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(prepare type)-------------------*/
   DEBUG_HFIX   yLOG_char    ("c_maintset" , c_maintset);
   --rce; if (c_maintset == 0 || strchr ("wi", c_maintset) == NULL) {
      DEBUG_HFIX   yLOG_note    ("c_maintset not valid");
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   /*---(clear rows)---------------------*/
   for (i = 0; i < LEN_SHORT; ++i)  x_rows [i] = 0;
   /*---(process entries)----------------*/
   DEBUG_HFIX   yLOG_note    ("processing entries");
   for (i = 0; i < LEN_FULL; ++i) {
      /*---(check end-of-list)-----------*/
      if (s_groups [i].g_type == 0) {
         DEBUG_HFIX   yLOG_note    ("hit end-of-list");
         break;
      }
      /*---(check type)------------------*/
      if (s_groups [i].g_type != c_maintset) {
         DEBUG_HFIX   yLOG_note    ("wrong type, skipping");
         continue;
      }
      /*---(find entry)------------------*/
      strlcpy (x_name, s_groups [i].g_group, LEN_TITLE);
      DEBUG_HFIX   yLOG_info    ("x_name"     , x_name);
      n = BASE_exist (c_maintset, x_name);
      DEBUG_HFIX   yLOG_value   ("n"         , n);
      --rce;  if (n > 0) {
         DEBUG_HFIX   yLOG_note    ("already exists");
         continue;
      }
      /*---(assign column)---------------*/
      DEBUG_HFIX   yLOG_char    ("g_col"      , s_groups [i].g_col);
      switch (s_groups [i].g_col) {
      case 'u' :  case 'm' :  x_col = 0;  break;
      case 'c' :  case 'e' :  x_col = 1;  break;
      case 't' :  case 'o' :  x_col = 2;  break;
      default  :  x_col = 0;  break;
      }
      /*---(figure position)-------------*/
      DEBUG_HFIX   yLOG_value   ("x_col"     , x_col);
      DEBUG_HFIX   yLOG_value   ("x_row"     , x_rows [x_col]);
      if (x_rows [x_col] > 8) {
         yLOG_note    ("too many rows in the column, skipping");
         continue;
      }
      x_pos = (x_rows [x_col] * 3) + x_col;
      DEBUG_HFIX   yLOG_value   ("x_pos"     , x_pos);
      ++(x_rows [x_col]);
      /*---(place)-----------------------*/
      rc = BASE_entry ('m', x_pos, x_name);
      DEBUG_HFIX   yLOG_value   ("entry"     , rc);
      ++x_total;
      /*---(done)------------------------*/
   }
   DEBUG_HFIX   yLOG_value   ("x_total"   , x_total);
   /*---(complete)------------------------------*/
   DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
   return x_total;
}



/*====================------------------------------------====================*/
/*===----                     matching file names                      ----===*/
/*====================------------------------------------====================*/
static void  o___MATCHING________o () { return; }

char
MAINT__not              (char a_name [LEN_TITLE], char a_not [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        l           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_HFIX   yLOG_point   ("a_not"      , a_not);
   if (a_not == NULL || a_not [0] == '\0') {
      DEBUG_HFIX    yLOG_note    ("no not match requested");
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 1;
   }
   DEBUG_HFIX   yLOG_info    ("a_not"      , a_not);
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   if (strstr (a_name, a_not) == NULL)   return 1;
   return 0;
}

char
MAINT__prefix           (char a_name [LEN_TITLE], char a_whoami [LEN_LABEL], char a_prefix [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        l           =    0;
   char        x_prefix    [LEN_LABEL] = "";
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_HFIX   yLOG_point   ("a_prefix"   , a_prefix);
   if (a_prefix == NULL || a_prefix [0] == '\0') {
      DEBUG_HFIX    yLOG_note    ("no prefix match requested");
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 1;
   }
   DEBUG_HFIX   yLOG_info    ("a_prefix"   , a_prefix);
   /*---(check literal)------------------*/
   if (a_prefix [0] != '(') {
      DEBUG_HFIX    yLOG_note    ("literal match");
      l = strlen (a_prefix);
      DEBUG_HFIX   yLOG_value   ("l"          , l);
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      if (strncmp (a_name, a_prefix, l) == 0)   return 1;
      return 0;
   }
   /*---(check whoami)-------------------*/
   if (strcmp (a_prefix, "(proj)") == 0) {
      DEBUG_HFIX    yLOG_note    ("whoami match");
      l = strlen (a_whoami);
      DEBUG_HFIX   yLOG_value   ("l"          , l);
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      if (strncmp (a_name, a_whoami, l) == 0)   return 1;
      return 0;
   }
   /*---(check trunc'd whoami)-----------*/
   if (strcmp (a_prefix, "(PROJ)") == 0) {
      DEBUG_HFIX    yLOG_note    ("truncated whoami match");
      l = strlen (a_whoami) - 1;
      DEBUG_HFIX   yLOG_value   ("l"          , l);
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      if (strncmp (a_name, a_whoami, l) == 0)   return 1;
      return 0;
   }
   /*---(check lib whoami)---------------*/
   if (strcmp (a_prefix, "(libPROJ)") == 0) {
      DEBUG_HFIX    yLOG_note    ("library truncated whoami match");
      l = strlen (a_whoami);
      DEBUG_HFIX   yLOG_value   ("l"          , l);
      sprintf (x_prefix, "lib%*.*s", l - 1, l - 1, a_whoami);
      DEBUG_HFIX   yLOG_info    ("x_prefix"   , x_prefix);
      l = strlen (x_prefix);
      DEBUG_HFIX   yLOG_value   ("l"          , l);
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      if (strncmp (a_name, x_prefix, l) == 0)   return 1;
      return 0;
   }
   /*---(complete)-----------------------*/
   --rce;
   DEBUG_HFIX    yLOG_note    ("prefix matching method not understood");
   DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
   return rce;
}

char
MAINT__suffix           (char a_name [LEN_TITLE], char a_suffix [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        ln          =    0;
   char        ls          =    0;
   char        x_off       =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_HFIX   yLOG_point   ("a_suffix"   , a_suffix);
   if (a_suffix == NULL || a_suffix [0] == '\0') {
      DEBUG_HFIX    yLOG_note    ("no suffix match requested");
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 1;
   }
   DEBUG_HFIX   yLOG_info    ("a_suffix"   , a_suffix);
   /*---(check literal)------------------*/
   if (a_suffix [0] != '(') {
      DEBUG_HFIX    yLOG_note    ("literal match");
      ln = strlen (a_name);
      DEBUG_HFIX   yLOG_value   ("ln"         , ln);
      ls = strlen (a_suffix);
      DEBUG_HFIX   yLOG_value   ("ls"         , ls);
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      if (strcmp (a_name + ln - ls, a_suffix) == 0)   return 1;
      return 0;
   }
   /*---(complete)-----------------------*/
   --rce;
   DEBUG_HFIX    yLOG_note    ("suffix matching method not understood");
   DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
   return rce;
}

char
MAINT__expect           (char a_name [LEN_TITLE], char a_whoami [LEN_LABEL], char a_expect [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        ln          =    0;
   char        ls          =    0;
   char        x_off       =    0;
   char        x_whoami    [LEN_LABEL] = "";
   char        l           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_HFIX   yLOG_point   ("a_expect"   , a_expect);
   if (a_expect == NULL || a_expect [0] == '\0') {
      DEBUG_HFIX    yLOG_note    ("no expect match requested");
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 1;
   }
   DEBUG_HFIX   yLOG_info    ("a_expect"   , a_expect);
   /*---(check literal)------------------*/
   if (a_expect [0] != '(') {
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      if (strcmp (a_name, a_expect) == 0)   return 1;
      return 0;
   }
   /*---(check whoami)-------------------*/
   if (strcmp (a_expect, "(PROJ)") == 0) {
      DEBUG_HFIX    yLOG_note    ("truncated whoami match");
      l = strlen (a_whoami);
      DEBUG_HFIX   yLOG_value   ("l"          , l);
      strlcpy (x_whoami, a_whoami, l);
      DEBUG_HFIX   yLOG_info    ("x_whoami"   , x_whoami);
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      if (strcmp (a_name, x_whoami) == 0)   return 1;
      return 0;
   }
   /*---(complete)-----------------------*/
   --rce;
   DEBUG_HFIX    yLOG_note    ("expect matching method not understood");
   DEBUG_HFIX    yLOG_exitr   (__FUNCTION__, rce);
   return rce;
}

char
MAINT__identify         (char c_type, char a_name [LEN_TITLE], char a_whoami [LEN_LABEL], char r_rule [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          =    0;
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_rule   != NULL)   strcpy (r_rule, "");
   /*---(defense)------------------------*/
   DEBUG_HFIX   yLOG_point   ("a_name"     , a_name);
   --rce;  if (a_name == NULL || a_name [0] == '\0') {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_info    ("a_name"     , a_name);
   DEBUG_HFIX   yLOG_point   ("a_whoami"   , a_whoami);
   --rce;  if (a_whoami == NULL || a_whoami [0] == '\0') {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_info    ("a_whoami"   , a_whoami);
   /*---(prepare)------------------------*/
   DEBUG_HFIX   yLOG_char    ("c_type"     , c_type);
   --rce;  switch (c_type) {
   case 'W' : case 'w' :
      c_type = 'w';
      break;
   case 'I' : case 'i' : case 'R' : case 'r' :
      c_type = 'i';
      break;
   default  :
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   DEBUG_HFIX   yLOG_char    ("c_type"     , c_type);
   /*---(find)---------------------------*/
   for (i = 0; i < LEN_FULL; ++i) {
      /*---(check group)-----------------*/
      if (s_groups [i].g_type == 0) {
         DEBUG_HFIX   yLOG_note    ("hit end-of-list");
         break;
      }
      /*---(check for end)---------------*/
      DEBUG_HFIX   yLOG_value   ("g_type"     , s_groups [i].g_type);
      if (s_groups [i].g_type != c_type) {
         DEBUG_HFIX   yLOG_note    ("wrong type, skipping");
         continue;
      }
      /*---(check not)-------------------*/
      rc = MAINT__not    (a_name, s_groups [i].g_not);
      DEBUG_HFIX   yLOG_value   ("not"        , rc);
      if (rc <= 0) {
         DEBUG_HFIX   yLOG_note    ("not not blank and matches");
         continue;
      }
      /*---(check prefix)----------------*/
      rc = MAINT__prefix (a_name, a_whoami, s_groups [i].g_pre);
      DEBUG_HFIX   yLOG_value   ("prefix"     , rc);
      if (rc <= 0) {
         DEBUG_HFIX   yLOG_note    ("prefix not blank and does not match");
         continue;
      }
      /*---(check suffix)----------------*/
      rc = MAINT__suffix (a_name, s_groups [i].g_suf);
      DEBUG_HFIX   yLOG_value   ("suffix"     , rc);
      if (rc <= 0) {
         DEBUG_HFIX   yLOG_note    ("suffix not blank and does not match");
         continue;
      }
      /*---(check suffix)----------------*/
      rc = MAINT__expect (a_name, a_whoami, s_groups [i].g_name);
      DEBUG_HFIX   yLOG_value   ("expect"     , rc);
      if (rc <= 0) {
         DEBUG_HFIX   yLOG_note    ("expect not blank and does not match");
         continue;
      }
      /*---(save-back)-------------------*/
      if (r_rule   != NULL)   strlcpy (r_rule, s_groups [i].g_group, LEN_LABEL);
      /*---(return match)----------------*/
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 1;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

