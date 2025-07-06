/*============================----beg-of-source---============================*/

/*===[[ ONE_LINERS ]]=========================================================*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*········· ··········· ´·····························´········································*/
#define     P_FOCUS     "PS (programming support)"
#define     P_NICHE     "vi (vim/ide)"
#define     P_SUBJECT   "parsing make/compiler output"
#define     P_PURPOSE   "converting make/compiler output into useful tags"
/*········· ··········· ´·····························´········································*/
#define     P_NAMESAKE  "hephaestus-klytotekhnes (the blacksmith)"
#define     P_PRONOUNCE ""
#define     P_HERITAGE  "olympian god of technology, tools, and blacksmiths"
#define     P_BRIEFLY   ""
#define     P_IMAGERY   ""
#define     P_REASON    ""
/*········· ··········· ´·····························´········································*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
/*········· ··········· ´·····························´········································*/
#define     P_HOMEDIR   "/home/system/HFIX.vimide_compiler_integration"
#define     P_BASENAME  ""
#define     P_FULLPATH  ""
#define     P_SUFFIX    ""
#define     P_CONTENT   ""
/*········· ··········· ´·····························´········································*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 5.3.0"
#define     P_CODESIZE  ""
/*········· ··········· ´·····························´········································*/
#define     P_DEPSTDC   ""
#define     P_DEPPOSIX  ""
#define     P_DEPCORE   "ySTR"
#define     P_DEPVIKEY  ""
#define     P_DEPGRAPH  ""
#define     P_DEPOTHER  "ySORT,yJOBS,yEXEC"
#define     P_DEPSOLO   ""
/*········· ··········· ´·····························´········································*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2009-06"
/*········· ··········· ´·····························´········································*/
#define     P_VERMAJOR  "2.--  moving from awk to c-language"
#define     P_VERMINOR  "2.0-"
#define     P_VERNUM    "2.0c"
#define     P_VERTXT    "main loop and display mechanics stabilizing/unit-tested"
/*········· ··········· ´·····························´········································*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*········· ··········· ´·····························´········································*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*===[[ SRENIL_ENO ]]=========================================================*/

/*······´ ´·················´ ´················································*/
#define   P_BACKGROUD         "background¦" \
   "i have a large, growing, and evolving c-language code-base.  so, i need¦" \
   "to roll-out changes and quickly identify, test, and resolve issues in¦" \
   "often now-unfamiliar source code.  anything that can help is golden.¦"

/*······´ ´·················´ ´················································*/
#define   P_SITUATION         "itch¦" \
   "in even moderate sized programs; compiler, make, and linker output can¦" \
   "be overwhelming, especially since many issues, optionally identified¦" \
   "and ignored, often lead to problems at inconvienent times.¦"

/*······´ ´·················´ ´················································*/
#define   P_SUMMARY           "summary¦"\
   "HFIX (heatherly fix) is a support tool for my VIM/IDE environment¦" \
   "to summarize and present gnu make, gcc compilation, and ld linking¦" \
   "output as clear, filtered, and easily followed tags.¦"











/*============================[[ beg-of-code ]]===============================*/
#ifndef HFIX
#define HFIX yes



#include <stdio.h>
#include <string.h>
#include <yLOG.h>
#include <yURG.h>
#include <yENV.h>
#include <ySTR_solo.h>
#include <yCOLOR_solo.h>



extern char   g_print  [LEN_RECD];
extern char   g_file   [LEN_HUND];
extern char   g_filter [LEN_LABEL];
extern char   g_color;
extern char   g_break  [LEN_FULL];



#define    HFIX_CRITICAL   "!"

#define    HFIX_ERRORS     "!Ee"
#define    HFIX_ERROR      "Ee"

#define    HFIX_WARNINGS   "!EeWw"
#define    HFIX_WARNING    "Ww"

#define    HFIX_WASTE      "Uu"

#define    HFIX_EVERYTHING "!EeWwUu"


/*===[[ HFIX_prog ]]==========================================================*/
/*········´ ´·····················´ ´·········································*/
char        PROG__args              (int a_argc, char *a_argv[]);
/*········´ ´··(done))············´ ´·········································*/



/*===[[ HFIX_base ]]==========================================================*/
/*········´ ´·····················´ ´·········································*/
char        BASE__open              (char a_name [LEN_HUND], short *r_lines, short *r_accept, FILE **r_file);
char        BASE__close             (FILE **r_file);
char        BASE__read              (FILE *f, short *b_lines, short *b_accept, char r_recd [LEN_RECD]);
char        BASE__handle            (char c_pass, char c_filter [LEN_LABEL], char c_color, char a_recd [LEN_RECD], short *b_handled, short *b_shown, short *b_hidden, char *r_level, char r_show [LEN_FULL]);
char        BASE_pass               (char c_pass, char c_filter [LEN_LABEL], char c_color);



/*===[[ HFIX_gcc ]]===========================================================*/
/*········´ ´·····················´ ´·········································*/
char        GCC__file               (char *b_beg, char **r_next, char *r_type, char r_file [LEN_HUND]);
char        GCC__num                (char *b_beg, char **r_next, short *r_num);
char        GCC__level              (char *b_beg, char **r_next, char *r_type);
char        GCC__msg                (char *b_beg, short *b_count, char r_msg [LEN_RECD], char r_flag [LEN_HUND]);
char        GCC__regrade            (char a_msg [LEN_RECD], char *b_level);
char        GCC_parse               (char a_recd [LEN_RECD], short *b_count, char r_file [LEN_HUND], char *r_type, short *r_line, short *r_col, char *r_level, char r_msg [LEN_RECD], char r_flag [LEN_HUND]);
/*········´ ´··(done))············´ ´·········································*/



/*===[[ HFIX_show ]]==========================================================*/
/*········´ ´·····················´ ´·········································*/
char*       SHOW_hint               (int n);
char        SHOW_num                (int a_num, int a_max, char r_out [LEN_TERSE]);
char*       SHOW_totals             (char c_pass, char c_color, short a_show, short a_fail, short a_errs, short a_warn, short a_waste, short a_msgs, short a_total);
/*········´ ´··(done))············´ ´·········································*/



/*===[[ HFIX_make ]]==========================================================*/
/*········´ ´·····················´ ´·········································*/
char        MAKE_parse              (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, int *r_col, char *r_type, char r_msg [LEN_RECD], char r_flag [LEN_HUND]);
char        MAKE_collect            (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, char *r_type, char r_msg [LEN_RECD]);
/*········´ ´··(done))············´ ´·········································*/



/*===[[ HFIX_ld ]]============================================================*/
/*········´ ´·····················´ ´·········································*/
char        LD_parse                (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, int *r_col, char *r_type, char r_msg [LEN_RECD], char r_flag [LEN_HUND]);
/*········´ ´··(done))············´ ´·········································*/



#endif
