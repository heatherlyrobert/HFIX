/*============================----beg-of-source---============================*/

/*===[[ ONE_LINERS ]]=========================================================*/
/*                      ����������1���������2���������3���������4���������5���������6���������7*/
/*--------- 12345678901 �123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*��������� ����������� �����������������������������������������������������������������������*/
#define     P_FOCUS     "PS (programming support)"
#define     P_NICHE     "vi (vim/ide)"
#define     P_SUBJECT   "parsing make/compiler output"
#define     P_PURPOSE   "converting make/compiler output into useful tags"
/*��������� ����������� �����������������������������������������������������������������������*/
#define     P_NAMESAKE  "hephaestus-klytotekhnes (blacksmith)"
#define     P_PRONOUNCE ""
#define     P_HERITAGE  "olympian god of technology, tools, and blacksmiths"
#define     P_BRIEFLY   ""
#define     P_IMAGERY   "muscular, lame-footed, usually shown seated with a hammer and an anvil"
#define     P_REASON    ""
/*��������� ����������� �����������������������������������������������������������������������*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
/*��������� ����������� �����������������������������������������������������������������������*/
#define     P_HOMEDIR   "/home/system/HFIX.vimide_compiler_integration"
#define     P_BASENAME  ""
#define     P_FULLPATH  ""
#define     P_SUFFIX    ""
#define     P_CONTENT   ""
/*��������� ����������� �����������������������������������������������������������������������*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 5.3.0"
#define     P_CODESIZE  ""
/*��������� ����������� �����������������������������������������������������������������������*/
#define     P_DEPSTDC   ""
#define     P_DEPPOSIX  ""
#define     P_DEPCORE   "ySTR"
#define     P_DEPVIKEY  ""
#define     P_DEPGRAPH  ""
#define     P_DEPOTHER  "ySORT,yJOBS,yEXEC"
#define     P_DEPSOLO   ""
/*��������� ����������� �����������������������������������������������������������������������*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2009-06"
/*��������� ����������� �����������������������������������������������������������������������*/
#define     P_VERMAJOR  "2.--  moving from awk to c-language"
#define     P_VERMINOR  "2.0-"
#define     P_VERNUM    "2.0n"
#define     P_VERTXT    "wipe/WIPE are working stunningly (but very custom to me) ;))"
/*��������� ����������� �����������������������������������������������������������������������*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*��������� ����������� �����������������������������������������������������������������������*/
/*--------- 12345678901 �123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*                      ����������1���������2���������3���������4���������5���������6���������7*/
/*===[[ SRENIL_ENO ]]=========================================================*/

/*������� ������������������� �������������������������������������������������*/
#define   P_BACKGROUD         "background�" \
   "i solely maintain a large (500M+ lines), growing, and evolving c-language�" \
   "codebase; i roll-out frequent and sometimes sweeping changes, and must�"    \
   "quickly resolve issues while under pressure and in often unfamiliar code.�"

/*������� ������������������� �������������������������������������������������*/
#define   P_COREDRIVE          "core drive�" \
   "any speed or accuracy gain in identifying, diagnosing, remediating, and�"   \
   "certifying changes is worthy of great pro-active standards and tool�"       \
   "building effort.  without this, my codebase withers.�"

/*������� ������������������� �������������������������������������������������*/
/*> #define   P_ELEMENTS           "enements�" \                                        <* 
 *>    "1) absolutely rock-solid core system (GNU/linux) using gentoo�"             \   <* 
 *>    "2) limitless, hyper-efficient programming language (c-language)�"           \   <* 
 *>    "3) ubiquitous, technical, and powerful compilier (gcc/make)�"               \   <* 
 *>    "4) hyper efficient ascii-text editing (vim)�"                               \   <* 
 *>    "5) custom integrated developent environment (IDE)�"                         \   <* 
 *>    "�"                                                                              <*/


   /*> "any speed or accuracy gain in identifying, diagnosing, remediating, and�"   \   <* 
    *> "certifying changes is worthy of great pro-active standards and tool�"       \   <* 
    *> "building effort.  without this, my codebase withers.�"                          <*/


/*������� ������������������� �������������������������������������������������*/
#define   P_SITUATION         "itch�" \
   "in even moderate sized programs; compiler, make, and linker output can�"    \
   "be overwhelming, especially since many issues, optionally identified�"      \
   "and ignored, often lead to problems at inconvienent times.�"

/*������� ������������������� �������������������������������������������������*/
#define   P_SUMMARY           "summary�"\
   "HFIX (heatherly fix) is my VIM/IDE service to accelerate the painful,�"     \
   "repetitive, tedious, and error-prone cycle of compiling, linking,�"         \
   "debugging, and installing software into a more smooth and targeted one.�"

#define   P_HARDREQS          "hard requirements�"\
   "1) gentoo gnu/linux as the base�" \
   "2) vim (vi) as the editor, no desire to move to integrated toolsets�" \
   "3) gnu gcc as the compiler (obviously)�" \
   "4) gnu make and ld (linker) (also obviously)�"

#define   P_ARCHITECTURE      "architecture�"\
   "1) vim-script which provides user-interface and quarter-backing�" \
   "2) c-language program to convert gcc/make/ld output into usable tags�" \
   "3) standardized makefile content across all programs (zeno)�"



typedef     unsigned long long      ullong;
typedef     struct      dirent      tDIRENT;
typedef     struct      stat        tSTAT;






/*============================[[ beg-of-code ]]===============================*/
#ifndef HFIX
#define HFIX yes



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>          /* opendir() */
#include <sys/syscall.h>
#include <dirent.h>          /* readdir() */
#include <sys/types.h>
#include <time.h>            /* time() */

#include <yLOG.h>
#include <yURG.h>
#include <yENV.h>
#include <ySTR_solo.h>
#include <yCOLOR_solo.h>



#define     HFIX_LOG       "/tmp/HFIX.log"
#define     HFIX_OUT       "/tmp/HFIX.out"
#define     HFIX_BUF       "/tmp/HFIX.buf"
#define     HFIX_LST       "/tmp/HFIX.lst"

#define     HFIX_SUPERS    "wWcCiIuUrRmMqQfF"
#define     HFIX_ACTION    "wWcCuUiIrRmM"
#define     HFIX_BEG       '['
#define     HFIX_CHK       '>'
#define     HFIX_PHASES    "[>"



extern char   g_print  [LEN_RECD];
extern char   g_file   [LEN_HUND];
extern char   g_filter [LEN_LABEL];
extern char   g_color;
extern char   g_break  [LEN_FULL];
extern char   g_ylog;

extern long   s_rpid;
extern long   s_cnt;
extern long   s_beg;
extern long   s_cur;
extern long   s_end;

extern char   s_whoami      [LEN_LABEL];
extern char   s_ext         [LEN_TERSE];
extern char   s_done;
extern char   s_status;
extern char   s_label       [LEN_LABEL];
extern char   s_result;
extern char   s_error;

extern char   g_action;
extern char   g_phase;
extern char   g_data   [LEN_FULL];



#define MAX_ENTRY     27
#define MAX_LINES     12
extern char   s_compile     [MAX_ENTRY][LEN_DESC];
extern char   s_ncount;



#define    HFIX_CRITICAL   "!E"

#define    HFIX_ERRORS     "!Ee"
#define    HFIX_ERROR      "Ee"

#define    HFIX_WARNINGS   "!EeWw"
#define    HFIX_WARNING    "Ww"

#define    HFIX_WASTE      "Uu"

#define    HFIX_EVERYTHING "!EeWwUu"


/*===[[ HFIX_prog ]]==========================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        PROG__urgs              (int argc, char *argv[]);
char        PROG__args              (int a_argc, char *a_argv[]);
char        PROG_handler            (char a_action);
/*��������� ���(done))������������� ������������������������������������������*/



/*===[[ HFIX_acts ]]==========================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        ACTS__begin             (char c_super, char c_action, char c_phase, char c_unit, int a_rpid);
char        ACTS__result            (char a_done, char a_status, char a_error, char *r_result, char b_label [LEN_LABEL]);
char        ACTS__find_ends         (char c_action, char a_recd [LEN_RECD]);
char        ACTS__filter_gcc        (char a_action, char a_recd [LEN_RECD], char **r_namish);
char        ACTS__progress          (char a_action);
char        ACTS__check             (char c_super, char c_action, char c_phase, char c_unit, char a_status, char a_label [LEN_LABEL]);
char        ACTS__filename          (char c_action, char *a_start, char r_name [LEN_TITLE], char *r_style, char *r_type);
char        ACTS_single             (char c_super, char c_action, char c_phase);
/*��������� ����������������������� ������������������������������������������*/



/*===[[ HFIX_base ]]==========================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        BASE__open              (char a_name [LEN_HUND], short *r_lines, short *r_accept, FILE **r_file);
char        BASE__close             (FILE **r_file);
char        BASE__read              (FILE *f, short *b_lines, short *b_accept, char r_recd [LEN_RECD]);
char        BASE__handle            (char c_pass, char c_filter [LEN_LABEL], char c_color, char a_recd [LEN_RECD], short *b_handled, short *b_shown, short *b_hidden, char *r_level, char r_show [LEN_FULL]);
char        BASE_pass               (char c_pass, char c_filter [LEN_LABEL], char c_color);



/*===[[ HFIX_comp ]]==========================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        COMP__clear             (char a_ext [LEN_TERSE]);
char        COMP__base              (void);
char        COMP__exist             (char c_type, char a_name [LEN_TITLE]);
char        COMP__mark              (char a_name [LEN_TITLE], char a_mark);
char        COMP__mark_done         (char a_status, char a_label [LEN_LABEL], int a_cnt);
/*��������� ����������������������� ������������������������������������������*/
char        COMP_clean_0            (void);
char        COMP_clean_n            (void);
/*��������� ����������������������� ������������������������������������������*/
char        COMP__beg               (void);
char        COMP__chk               (void);
char        COMP_c_recon            (char a_phase);
/*��������� ����������������������� ������������������������������������������*/
char        COMP_u_prep             (void);
char        COMP_u_recon            (void);
/*��������� ����������������������� ������������������������������������������*/



/*===[[ HFIX_exim ]]==========================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        EXIM__import_time       (char a_line [LEN_FULL], long *r_rpid, long *r_cnt, long *r_beg, long *r_cur, long *r_end);
char        EXIM__import_whoami     (char a_line [LEN_FULL], char r_whoami [LEN_LABEL], char r_ext [LEN_TERSE], char *r_done, char *r_status, char *r_result, char *r_error);
char        EXIM__import_entries    (char a_line [LEN_FULL], char a_row, char r_table [MAX_ENTRY][LEN_DESC], char *b_count);
char        EXIM_import             (char a_file [LEN_PATH]);
/*��������� ����������������������� ������������������������������������������*/
char*       EXIM__export_time       (long a_rpid, long a_cnt, long a_beg, long a_cur, long a_end, char a_result);
char*       EXIM__export_whoami     (char a_whoami [LEN_LABEL], char a_ext [LEN_TERSE], char a_done, char a_status, char a_result, char a_error);
char        EXIM__export_list       (FILE *b_buf);
char        EXIM_export             (char a_super, char a_result, char a_file [LEN_PATH]);
char        EXIM_trouble            (char a_file [LEN_PATH], char a_message [LEN_HUND]);
/*��������� ����������������������� ������������������������������������������*/



/*===[[ HFIX_gcc ]]===========================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        GCC__file               (char c_conf, char *b_beg, char **r_next, char *r_type, char r_file [LEN_HUND]);
char        GCC__num                (char *b_beg, char **r_next, short *r_num);
char        GCC__level              (char *b_beg, char **r_next, char *r_type);
char        GCC__msg                (char c_conf, char *b_beg, short *b_count, char r_msg [LEN_RECD], char r_flag [LEN_HUND]);
char        GCC__regrade            (char c_ylog, char b_msg [LEN_RECD], char *b_level);
char        GCC_parse               (char a_recd [LEN_RECD], short *b_count, char r_file [LEN_HUND], char *r_type, short *r_line, short *r_col, char *r_level, char r_msg [LEN_RECD], char r_flag [LEN_HUND]);
/*��������� ���(done))������������� ������������������������������������������*/



/*===[[ HFIX_show ]]==========================================================*/
/*��������� ����������������������� ������������������������������������������*/
char*       SHOW_hint               (int n);
char        SHOW_num                (int a_num, int a_max, char r_out [LEN_TERSE]);
char*       SHOW_line               (char a_color, short a_shown, char a_type, char a_file [LEN_HUND], short a_line, short a_col, char a_level, char a_msg [LEN_RECD], char a_flag [LEN_HUND]);
char*       SHOW_totals             (char c_pass, char c_color, short a_show, short a_fail, short a_errs, short a_warn, short a_waste, short a_msgs, short a_total);
char*       SHOW_action             (char a_opt, char a_result);
char        SHOW_vim_help           (void);
/*��������� ���(done))������������� ������������������������������������������*/



/*===[[ HFIX_make ]]==========================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        MAKE__msg               (char a_type, char *b_beg, short *b_count, char r_msg [LEN_RECD], char r_flag [LEN_HUND]);
char        MAKE_parse              (char a_recd [LEN_RECD], short *b_count, char r_file [LEN_HUND], char *r_type, short *r_line, short *r_col, char *r_level, char r_msg [LEN_RECD], char r_flag [LEN_HUND], char *r_nada);
char        MAKE_collect            (char a_recd [LEN_RECD], int *b_count, char r_file [LEN_HUND], int *r_line, char *r_type, char r_msg [LEN_RECD]);
/*��������� ���(done))������������� ������������������������������������������*/



/*===[[ HFIX_ld ]]============================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        LD__wasted              (char *b_beg, char **r_next);
char        LD_parse                (char a_recd [LEN_RECD], short *b_count, char r_file [LEN_HUND], char *r_type, short *r_line, short *r_col, char *r_level, char r_msg [LEN_RECD], char r_flag [LEN_HUND]);
/*��������� ���(done))������������� ������������������������������������������*/



/*===[[ HFIX_ld ]]============================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        HFIX_whoami             (char r_name [LEN_LABEL]);
char*       HFIX_age                (ullong a_beg, ullong a_end);
char*       HFIX_size               (ullong a_bytes);
char        HFIX__sort_mods         (char a_phase);
char        HFIX_sort               (void);
/*��������� ����������������������� ������������������������������������������*/



/*===[[ HFIX_wipe ]]==========================================================*/
/*��������� ����������������������� ������������������������������������������*/
char        WIPE__base              (void);
char        WIPE__inc_single        (char n, char a_slot, char a_off);
char        WIPE__increment         (char a_name [LEN_TITLE], char a_slot);
char        WIPE__prefix            (char a_name [LEN_TITLE], char a_whoami [LEN_LABEL], char a_prefix [LEN_LABEL]);
char        WIPE__suffix            (char a_name [LEN_TITLE], char a_suffix [LEN_LABEL]);
char        WIPE__expect            (char a_name [LEN_TITLE], char a_whoami [LEN_LABEL], char a_expect [LEN_TITLE]);
char        WIPE__identify          (char a_name [LEN_TITLE], char a_whoami [LEN_LABEL], char r_rule [LEN_LABEL]);
char        WIPE__prepare           (char c_super, char c_action, char *r_export, FILE **b_file);
char        WIPE__finalize          (char c_super, char c_action, int a_total, int a_count, int x_caution, llong a_all, llong a_wipe, char c_unit, char a_export, FILE **b_file);
char        WIPE_pass               (char c_super, char c_action, char c_unit);
/*��������� ����������������������� ������������������������������������������*/



#endif
