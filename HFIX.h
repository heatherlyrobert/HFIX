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
#define     P_VERNUM    "2.0a"
#define     P_VERTXT    "porting to new project
/*········· ··········· ´·····························´········································*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*········· ··········· ´·····························´········································*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*===[[ SRENIL_ENO ]]=========================================================*/





/*============================[[ beg-of-code ]]===============================*/
#ifndef HFIX
#define HFIX yes



#include <stdio.h>
#include <string.h>
#include <yLOG.h>
#include <yURG.h>
#include <ySTR_solo.h>
#include <yCOLOR_solo.h>



extern char   g_print  [LEN_RECD];
extern char   g_file   [LEN_HUND];
extern char   g_filter;
extern char   g_break  [LEN_FULL];



/*===[[ HFIX_prog ]]==========================================================*/
/*········´ ´·····················´ ´·········································*/
char        PROG__args              (int a_argc, char *a_argv[]);
/*········´ ´··(done))············´ ´·········································*/



/*===[[ HFIX_base ]]==========================================================*/
/*········´ ´·····················´ ´·········································*/
char        BASE_pass               (char a_pass);



/*===[[ HFIX_gcc ]]===========================================================*/
/*········´ ´·····················´ ´·········································*/
char        GCC__file               (char *b_beg, char **r_next, char *r_type, char r_file [LEN_HUND]);
char        GCC_parse               (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, int *r_col, char *r_type, char r_msg [LEN_RECD], char r_flag [LEN_HUND]);
/*········´ ´··(done))············´ ´·········································*/



/*===[[ HFIX_show ]]==========================================================*/
/*········´ ´·····················´ ´·········································*/
char*       SHOW_hint               (int n);
char        SHOW_num                (int a_num, int a_max, char r_out [LEN_TERSE]);
char*       SHOW_totals             (char a_pass, int a_show, int a_fail, int a_errs, int a_warn, int a_waste, int a_msgs, int a_total);
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
