#include "HFIX.h"



char
INST__prepare           (char c_super, char c_pass, char c_unit)
{
}




char
INST_pass               (char c_super, char c_pass, char c_unit)
{
   /*> /+---(locals)-----------+-----+-----+-+/                                                                       <* 
    *> char        rce         =  -10;                                                                                <* 
    *> char        rc          =    0;                                                                                <* 
    *> FILE       *f           = NULL;                                                                                <* 
    *> char        x_recd      [LEN_RECD]  = "";                                                                      <* 
    *> short       x_total     =    0;                                                                                <* 
    *> short       x_accept    =    0;                                                                                <* 
    *> short       x_handled   =    0;                                                                                <* 
    *> short       x_shown     =    0;                                                                                <* 
    *> short       x_hidden    =    0;                                                                                <* 
    *> char        x_level     =  '-';                                                                                <* 
    *> char        x_show      [LEN_FULL]  = "";                                                                      <* 
    *> int         x_fail      =    0;                                                                                <* 
    *> int         x_errs      =    0;                                                                                <* 
    *> int         x_warn      =    0;                                                                                <* 
    *> int         x_waste     =    0;                                                                                <* 
    *> int         x_msgs      =    0;                                                                                <* 
    *> /+---(header)-------------------------+/                                                                       <* 
    *> DEBUG_HFIX  yLOG_enter   (__FUNCTION__);                                                                       <* 
    *> /+---(open)---------------------------+/                                                                       <* 
    *> rc = FILE_open (my.m_file, &x_total, &x_accept, &f);                                                             <* 
    *> DEBUG_HFIX  yLOG_value   ("open"      , rc);                                                                   <* 
    *> DEBUG_HFIX  yLOG_point   ("f"         , f);                                                                    <* 
    *> --rce;  if (rc < 1 || f == NULL) {                                                                             <* 
    *>    DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);                                                               <* 
    *>    return rce;                                                                                                 <* 
    *> }                                                                                                              <* 
    *> /+---(handle lines)-------------------+/                                                                       <* 
    *> while (1) {                                                                                                    <* 
    *>    /+---(read)------------------------+/                                                                       <* 
    *>    rc = FILE_read (f, &x_total, &x_accept, x_recd);                                                           <* 
    *>    DEBUG_HFIX  yLOG_value   ("read"      , rc);                                                                <* 
    *>    if (rc == 0)   break;                                                                                       <* 
    *>    /+---(handle)----------------------+/                                                                       <* 
    *>    rc = BASE__handle (c_pass, c_filter, c_color, x_recd, &x_handled, &x_shown, &x_hidden, &x_level, x_show);   <* 
    *>    DEBUG_HFIX  yLOG_value   ("handle"    , rc);                                                                <* 
    *>    if (rc == 1)  printf ("%s\n", x_show);                                                                      <* 
    *>    /+---(statistics)------------------+/                                                                       <* 
    *>    DEBUG_HFIX  yLOG_char    ("level"     , x_level);                                                           <* 
    *>    switch (x_level) {                                                                                          <* 
    *>    case '!' :            ++x_fail;   break;                                                                    <* 
    *>    case 'E' : case 'e' : ++x_errs;   break;                                                                    <* 
    *>    case 'W' : case 'w' : ++x_warn;   break;                                                                    <* 
    *>    case 'U' : case 'u' : ++x_waste;  break;                                                                    <* 
    *>    case 'm' :            ++x_msgs;   break;                                                                    <* 
    *>    }                                                                                                           <* 
    *>    /+---(done)------------------------+/                                                                       <* 
    *> }                                                                                                              <* 
    *> /+---(close)--------------------------+/                                                                       <* 
    *> rc = FILE_close (&f);                                                                                         <* 
    *> DEBUG_HFIX  yLOG_value   ("close"     , rc);                                                                   <* 
    *> DEBUG_HFIX  yLOG_point   ("f"         , f);                                                                    <* 
    *> --rce;  if (rc < 1 || f != NULL) {                                                                             <* 
    *>    DEBUG_HFIX  yLOG_exitr   (__FUNCTION__, rce);                                                               <* 
    *>    return rce;                                                                                                 <* 
    *> }                                                                                                              <* 
    *> /+---(totals)-------------------------+/                                                                       <* 
    *> printf ("%s\n", SHOW_totals (c_pass, c_color, x_shown, x_fail, x_errs, x_warn, x_waste, x_msgs, x_total));     <* 
    *> /+---(complete)-----------------------+/                                                                       <* 
    *> DEBUG_HFIX  yLOG_exit    (__FUNCTION__);                                                                       <* 
    *> return 0;                                                                                                      <*/
}

