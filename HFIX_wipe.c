#include "HFIX.h"


/*>                                                                                                                                                                    <* 
 *> HFIX∑gcc/make∑(----)∑∑chosen∑∑(w:wipe)∑=∑recon∑c-files∑to∑be∑compilied∑∑∑∑∑∑∑∑∑∑(2.0m)∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑[p]   <* 
 *> source∑cleaned∑∑-∑∑∑-∑∑∑-∑  Å HFIX∑working∑∑∑∑-∑∑∑-∑∑∑-∑  Å tmps∑∑∑∑∑∑∑∑∑∑∑∑-∑∑∑-∑∑∑-∑  Å                                                                    [p]   <* 
 *> object∑∑∑∑∑∑∑∑∑∑-∑∑∑-∑∑∑-∑  Å HTAG∑working∑∑∑∑-∑∑∑-∑∑∑-∑  Å fat∑fingers∑∑∑∑∑-∑∑∑-∑∑∑-∑  Å                                                                    [p]   <* 
 *> object∑cleaned∑∑-∑∑∑-∑∑∑-∑  Å polymnia∑work∑∑∑-∑∑∑-∑∑∑-∑  Å swaps∑∑∑∑∑∑∑∑∑∑∑-∑∑∑-∑∑∑-∑  Å                                                                    [p]   <* 
 *> unit∑code∑∑∑∑∑∑∑-∑∑∑-∑∑∑-∑  Å git∑working∑∑∑∑∑-∑∑∑-∑∑∑-∑  Å more∑∑∑∑∑∑∑∑∑∑∑∑-∑∑∑-∑∑∑-∑  Å                                                                    [p]   <* 
 *> unit∑output∑∑∑∑∑-∑∑∑-∑∑∑-∑  Å ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å                                                                    [p]   <* 
 *> executable∑∑∑∑∑∑-∑∑∑-∑∑∑-∑  Å ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å                                                                    [p]   <* 
 *> unit∑obj∑strp∑∑∑-∑∑∑-∑∑∑-∑  Å ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å                                                                    [p]   <* 
 *> ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å                                                                    [p]   <* 
 *> ∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  Å ∑∑∑∑  running       1  ∑∑∑  Å WIPE∑∑∑∑∑∑-∑∑∑-∑∑∑-∑∑∑∑∑1s  Å                                                                    [p]   <* 
 *> pid=0             cnt=1             beg=1753346980    cur=1753346981    end=1753346981                                                                       [p]   <* 
 *> who=HFIX_         ext=.c            don=Y ∑∑∑∑∑∑∑∑ sta=# ∑∑∑∑∑∑∑∑ res=p ∑∑∑∑∑∑∑∑ err=-                                                                       [p]   <* 
 *>                                                                                                                                                                    <*/

struct cWIPE {
   char        w_type;
   char        w_wipe;                     /* actually wipe them (y/-)          */
   char        w_name        [LEN_HUND];
   char        w_pre         [LEN_LABEL];
   char        w_suf         [LEN_LABEL];
   char        w_group       [LEN_LABEL];  /* only use 14 for screen formatting */
} const s_wipes [LEN_HUND] = {
   /*type -wipe --name------------------ ---prefix---- ----suffix----- ---group---------*/
   { 'u' , 'y' , "master.h"             , ""          , ""            , "unit∑header"   },
   { 'u' , 'y' , ""                     , "(proj)"    , "_unit.c"     , "unit∑src"      },
   { 'u' , 'y' , ""                     , "(proj)"    , "_munit.c"    , "unit∑src"      },
   { 'u' , 'y' , ""                     , "(proj)"    , "_unit.cs"    , "unit∑src∑strp" },
   { 'u' , 'y' , ""                     , "(proj)"    , "_munit.cs"   , "unit∑src∑strp" },
   { 'u' , 'y' , ""                     , "(proj)"    , "_unit.o"     , "unit∑obj"      },
   { 'u' , 'y' , ""                     , "(proj)"    , "_munit.o"    , "unit∑obj"      },
   { 'u' , 'y' , ""                     , "(proj)"    , "_unit.os"    , "unit∑obj∑strp" },
   { 'u' , 'y' , ""                     , "(proj)"    , "_munit.os"   , "unit∑obj∑strp" },
   { 'u' , 'y' , ""                     , "(proj)"    , "_unit"       , "unit∑exec"     },
   { 'u' , 'y' , ""                     , "(proj)"    , "_munit"      , "unit∑exec"     },
   { 'u' , 'y' , ""                     , "(proj)"    , "_unit_debug" , "unit∑debug"    },
   { 'u' , 'y' , ""                     , "(proj)"    , "_munit_debug", "unit∑debug"    },
   { 'u' , 'y' , ""                     , "(proj)"    , ".urun"       , "unit∑output"   },
   { 'u' , 'y' , "master.globals"       , ""          , ""            , "unit∑work"     },
   /*type -wipe --name------------------ ---prefix---- ----suffix----- ---group---------*/
   { 'c' , 'y' , ""                     , "(proj)"    , ".cs"         , "main∑src∑strp" },
   { 'c' , 'y' , ""                     , "(proj)"    , ".Sc"         , "main∑src∑strp" },
   { 'c' , 'y' , ""                     , "(proj)"    , ".o"          , "main∑obj"      },
   { 'c' , 'y' , ""                     , "(proj)"    , ".os"         , "main∑obj∑strp" },
   { 'c' , 'y' , ""                     , "(proj)"    , ".So"         , "main∑obj∑strp" },
   { 'c' , 'y' , "(PROJ)"               , ""          , ""            , "main∑exec"     },
   { 'c' , 'y' , ""                     , "(PROJ)"    , "_debug"      , "main∑debug"    },
   { 'c' , 'y' , ""                     , "(libPROJ)" , ".so"         , "main∑shared"   },
   { 'c' , 'y' , ""                     , "(libPROJ)" , ".a"          , "main∑static"   },
   /*type -wipe --name------------------ ---prefix---- ----suffix----- ---group---------*/
   { 't' , 'y' , ""                     , ""          , "~"           , "temp∑files"    },
   { 't' , 'y' , ""                     , ""          , ".tmp"        , "temp∑files"    },
   { 't' , '-' , ""                     , ""          , ".backup"     , "temp∑CAUTION"  },
   { 't' , '-' , ""                     , ""          , ".old"        , "temp∑CAUTION"  },
   { 't' , '-' , ""                     , ""          , ".save"       , "temp∑CAUTION"  },
   { 't' , '-' , ""                     , ""          , ".swo"        , "swap∑CAUTION"  },
   { 't' , '-' , ""                     , ""          , ".swp"        , "swap∑CAUTION"  },
   { 't' , '-' , ""                     , ""          , ".swn"        , "swap∑CAUTION"  },
   { 't' , 'y' , "HFIX.log"             , ""          , ""            , "HFIX∑working"  },
   { 't' , 'y' , "HFIX.out"             , ""          , ""            , "HFIX∑working"  },
   { 't' , 'y' , "HFIX.buf"             , ""          , ""            , "HFIX∑working"  },
   { 't' , 'y' , "gcc.out"              , ""          , ""            , "HFIX∑working"  },
   { 't' , 'y' , ""                     , ""          , ".lcalls"     , "HTAG∑working"  },
   { 't' , 'y' , ""                     , ""          , ".gcalls"     , "HTAG∑working"  },
   { 't' , 'y' , ""                     , ""          , ".depth"      , "HTAG∑working"  },
   { 't' , 'y' , ""                     , ""          , ".htags"      , "polymnia∑work" },
   { 't' , 'y' , "htags.stats"          , ""          , ""            , "polymnia∑work" },
   { 't' , 'y' , "htags.code"           , ""          , ""            , "polymnia∑work" },
   { 't' , 'y' , ""                     , ""          , ".mystry"     , "polymnia∑work" },
   { 't' , 'y' , ""                     , ""          , ".ylid"       , "polymnia∑work" },
   { 't' , 'y' , ","                    , ""          , ""            , "fat∑fingers"   },
   { 't' , 'y' , ",q"                   , ""          , ""            , "fat∑fingers"   },
   { 't' , 'y' , ",qq"                  , ""          , ""            , "fat∑fingers"   },
   { 't' , 'y' , ":w"                   , ""          , ""            , "fat∑fingers"   },
   { 't' , 'y' , ":{"                   , ""          , ""            , "fat∑fingers"   },
   /*type -wipe --name------------------ ---prefix---- ----suffix----- ---group---------*/
   {  0  , '-' , "end-of-list"          , ""          , ""            , ""              },
   /*type -wipe --name------------------ ---prefix---- ----suffix----- ---group---------*/
};

char
WIPE__base              (void)
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
   /*---(clear rows)---------------------*/
   for (i = 0; i < LEN_SHORT; ++i)  x_rows [i] = 0;
   /*---(process entries)----------------*/
   DEBUG_HFIX   yLOG_note    ("processing entries");
   for (i = 0; i < LEN_HUND; ++i) {
      /*---(check group)-----------------*/
      if (s_wipes [i].w_type == 0) {
         DEBUG_HFIX   yLOG_note    ("hit end-of-list");
         break;
      }
      /*---(find entry)------------------*/
      strlcpy (x_name, s_wipes [i].w_group, LEN_TITLE);
      DEBUG_HFIX   yLOG_info    ("x_name"     , x_name);
      n = COMP__exist ('w', x_name);
      DEBUG_HFIX   yLOG_value   ("n"         , n);
      --rce;  if (n > 0) {
         DEBUG_HFIX   yLOG_note    ("already exists");
         continue;
      }
      /*---(assign column)---------------*/
      DEBUG_HFIX   yLOG_char    ("w_type"     , s_wipes [i].w_type);
      switch (s_wipes [i].w_type) {
      case 'u' :  x_col = 0;  break;
      case 'c' :  x_col = 1;  break;
      case 't' :  x_col = 2;  break;
      default  :  x_col = 0;  break;
      }
      /*---(figure position)-------------*/
      DEBUG_HFIX   yLOG_value   ("x_col"     , x_col);
      DEBUG_HFIX   yLOG_value   ("x_row"     , x_rows [x_col]);
      if (x_rows [x_col] > 8) {
         DEBUG_HFIX   yLOG_note    ("too many rows in the column, skipping");
         continue;
      }
      x_pos = (x_rows [x_col] * 3) + x_col;
      DEBUG_HFIX   yLOG_value   ("x_pos"     , x_pos);
      ++(x_rows [x_col]);
      /*---(place)-----------------------*/
      DEBUG_HFIX   yLOG_note    ("accepted and placing");
      snprintf (x_full , 16, "%s∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑", x_name);
      DEBUG_HFIX   yLOG_info    ("x_full"     , x_full);
      sprintf  (s_compile [x_pos], "%s∑-∑∑∑-∑∑∑-∑  Å ", x_full);
      ++x_total;
      /*---(done)------------------------*/
   }
   DEBUG_HFIX   yLOG_value   ("x_total"   , x_total);
   /*---(complete)------------------------------*/
   DEBUG_HFIX   yLOG_exit    (__FUNCTION__);
   return x_total;
}

char
WIPE__inc_single        (char n, char a_slot, char a_off)
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
   if (x_bit [0] == '∑')  x_bit [0] = ' ';
   if (x_bit [1] == '∑')  x_bit [1] = ' ';
   if (x_bit [1] == '-')  x_bit [1] = ' ';
   if (x_bit [2] == '∑')  x_bit [2] = ' ';
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
   if (x_bit [0] == ' ')  x_bit [0] = '∑';
   if (x_bit [1] == ' ')  x_bit [1] = '∑';
   DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
   for (i = 0; i < l; ++i)  s_compile [n - 1][a_off + i] = x_bit [i];
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
WIPE__increment         (char a_name [LEN_TITLE], char a_slot)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        n           =    0;
   char        x_col       =    0;
   char        x_tot       =    0;
   char        x_caution   =  '-';
   /*---(header)-------------------------*/
   DEBUG_HFIX    yLOG_enter   (__FUNCTION__);
   /*---(find)---------------------------*/
   n = COMP__exist ('w', a_name);
   DEBUG_HFIX   yLOG_value   ("n"         , n);
   --rce;  if (n < 0) {
      DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
      return  rce;
   }
   if (strstr (a_name, "CAUTION") != NULL)  x_caution = 'y';
   /*---(find)---------------------------*/
   --rce; switch (a_slot) {
   case 'r'  :  x_col = 15;  x_tot =  6;  break;
   case 'w'  :  x_col = 19;  x_tot = 11;  break;
   case 'v'  :  x_col = 23;  x_tot = 16;  break;
   default   :
                DEBUG_HFIX   yLOG_note    ("unknown slot");
                DEBUG_HFIX   yLOG_exitr   (__FUNCTION__, rce);
                return  rce;
   }
   DEBUG_HFIX   yLOG_value   ("x_col"     , x_col);
   /*---(get existing)-------------------*/
   if (x_caution == '-' || a_slot == 'r') {
      WIPE__inc_single (n        , a_slot, x_col);
      WIPE__inc_single (MAX_ENTRY, a_slot, x_tot);
   } else {
      s_compile [n - 1][x_col + 1] = 'œ';
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
WIPE__prefix            (char a_name [LEN_TITLE], char a_whoami [LEN_LABEL], char a_prefix [LEN_LABEL])
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
WIPE__suffix            (char a_name [LEN_TITLE], char a_suffix [LEN_LABEL])
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
WIPE__expect            (char a_name [LEN_TITLE], char a_whoami [LEN_LABEL], char a_expect [LEN_TITLE])
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
WIPE__identify          (char a_name [LEN_TITLE], char a_whoami [LEN_LABEL], char r_rule [LEN_LABEL])
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
   /*---(find)---------------------------*/
   for (i = 0; i < LEN_HUND; ++i) {
      /*---(check for end)---------------*/
      DEBUG_HFIX   yLOG_value   ("w_type"     , s_wipes [i].w_type);
      if (s_wipes [i].w_type == 0) {
         DEBUG_HFIX   yLOG_note    ("hit end-of-list");
         break;
      }
      /*---(check prefix)----------------*/
      rc = WIPE__prefix (a_name, a_whoami, s_wipes [i].w_pre);
      DEBUG_HFIX   yLOG_value   ("prefix"     , rc);
      if (rc <= 0) {
         DEBUG_HFIX   yLOG_note    ("prefix not blank and does not match");
         continue;
      }
      /*---(check suffix)----------------*/
      rc = WIPE__suffix (a_name, s_wipes [i].w_suf);
      DEBUG_HFIX   yLOG_value   ("suffix"     , rc);
      if (rc <= 0) {
         DEBUG_HFIX   yLOG_note    ("suffix not blank and does not match");
         continue;
      }
      /*---(check suffix)----------------*/
      rc = WIPE__expect (a_name, a_whoami, s_wipes [i].w_name);
      DEBUG_HFIX   yLOG_value   ("expect"     , rc);
      if (rc <= 0) {
         DEBUG_HFIX   yLOG_note    ("expect not blank and does not match");
         continue;
      }
      /*---(save-back)-------------------*/
      if (r_rule   != NULL)   strlcpy (r_rule, s_wipes [i].w_group, LEN_LABEL);
      /*---(return match)----------------*/
      DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
      return 1;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_HFIX    yLOG_exit    (__FUNCTION__);
   return 0;
}

char
WIPE__prepare           (char c_super, char c_action, char *r_export, FILE **b_file)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   FILE       *f           = NULL;
   char        x_export    =  '-';
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
   DEBUG_HFIX   yLOG_char    ("x_export"   , x_export);
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
      rc = WIPE__base  ();
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
   char        x_check     [LEN_TERSE] = "∑€∑";
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   DEBUG_HFIX   yLOG_char    ("c_super"    , c_super);
   DEBUG_HFIX   yLOG_char    ("c_action"   , c_action);
   DEBUG_HFIX   yLOG_char    ("a_export"   , a_export);
   /*---(show remaining------------------*/
   if (c_action == 'r') {
      sprintf (x_bit, "%4db∑%4s∑ å ", a_total - a_count - x_caution, HFIX_size (a_all - a_wipe));
      if (x_bit [0] == ' ')  x_bit [0] = '∑';
      if (x_bit [1] == ' ')  x_bit [1] = '∑';
      if (x_bit [2] == ' ')  x_bit [2] = '∑';
      if (x_bit [3] == ' ')  x_bit [3] = '∑';
      DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
      for (i = 0; i < 14; ++i)  s_compile [MAX_ENTRY - 2][ 1 + i] = x_bit [i];
   }
   /*---(show total)---------------------*/
   if (c_action == 'r') {
      sprintf (x_bit, "%4dt∑%4s", a_total, HFIX_size (a_all));
      if (x_bit [0] == ' ')  x_bit [0] = '∑';
      if (x_bit [1] == ' ')  x_bit [1] = '∑';
      if (x_bit [2] == ' ')  x_bit [2] = '∑';
      if (x_bit [3] == ' ')  x_bit [3] = '∑';
      DEBUG_HFIX   yLOG_info    ("x_bit"     , x_bit);
      for (i = 0; i < 10; ++i)  s_compile [MAX_ENTRY - 2][15 + i] = x_bit [i];
   }
   /*---(check each one)-----------------*/
   if (c_action == 'w') {
      DEBUG_HFIX    yLOG_note    ("compare recon, wipe, and verify details");
      strcpy (x_check, "∑€∑");
      for (i = 0; i < MAX_ENTRY - 2; ++i) {
         /*---(check)--------------------*/
         DEBUG_HFIX    yLOG_value   ("i"         , i);
         if (s_compile [i][0] == '∑')  continue;
         /*---(get recon)----------------*/
         strlcpy (x_key, s_compile [i] + 15, 3);
         DEBUG_HFIX    yLOG_info    ("x_key"     , x_key);
         /*---(check wipe)---------------*/
         strlcpy (x_cmp, s_compile [i] + 19, 3);
         DEBUG_HFIX    yLOG_info    ("x_cmp"     , x_cmp);
         if (strcmp (x_cmp, "∑œ") != 0) {
            if (strcmp (x_key, x_cmp) != 0)  x_result = 'E';
            else { for (x = 0; x < 3; ++x)  s_compile [i][19 + x] = x_check [x]; }
            DEBUG_HFIX    yLOG_char    ("x_result"  , x_result);
         }
         /*---(check verify)-------------*/
         strlcpy (x_cmp, s_compile [i] + 23, 3);
         DEBUG_HFIX    yLOG_info    ("x_cmp"     , x_cmp);
         if (strcmp (x_cmp, "∑œ") != 0) {
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
      strcpy (x_check, "∑∑€∑");
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
   /*---(header)-------------------------*/
   DEBUG_HFIX   yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   rc = WIPE__prepare (c_super, c_action, &x_export, &f);
   DEBUG_HFIX   yLOG_value   ("prepare"    , rc);
   DEBUG_HFIX   yLOG_char    ("x_export"   , x_export);
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
      rc = WIPE__identify (x_file->d_name, s_whoami, x_rule);
      DEBUG_HFIX   yLOG_value   ("identify"  , rc);
      if (rc <= 0) {
         DEBUG_HFIX   yLOG_note    ("file not identified for removal");
         if (x_export == 'y') {
            DEBUG_HFIX   yLOG_note    ("export non-selected to list");
            fprintf (f, "%3d ---  ∑  %-30.30s  ----------\n", x_total, x_file->d_name);
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
         rc = WIPE__increment (x_rule, 'r');
         DEBUG_HFIX   yLOG_value   ("increment" , rc);
      }
      /*----(wipe)-----------------------*/
      if (c_action == 'w') {
         if (strstr (x_rule, "CAUTION") == NULL) {
            DEBUG_HFIX   yLOG_note    ("wipe removes");
            rc = WIPE__increment (x_rule, 'w');
            rc = yENV_rm (x_file->d_name);
            if (rc == '-')   rc = WIPE__increment (x_rule, 'v');
         } else {
            DEBUG_HFIX   yLOG_note    ("CAUTION item, must be hand deleted");
            rc = WIPE__increment (x_rule, 'w');
            rc = WIPE__increment (x_rule, 'v');
            --x_count;
            x_wipe -= x_size;
            ++x_caution;
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



