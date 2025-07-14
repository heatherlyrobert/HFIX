""===[[ START HDOC ]]==========================================================#
""===[[ HEADER ]]==============================================================#

"   niche         : integrated development environment
"   application   : rsh_fix.vim
"   purpose       : provide simple, productive, effective quickfix replacement
"   base_system   : gnu/linux
"   lang_name     : vim script
"   created       : svq - long, long ago
"   author        : the_heatherlys
"   dependencies  : gcc (any version) and _rsh_fix.awk (custom)
"   permissions   : GPL-2 with no warranty of any kind
"
"
""===[[ PURPOSE ]]=============================================================#

"   rsh_fix is an integrated set of compile/fix services to make a painful,
"   repetitive, lengthy, tedious, and haphazard process into a clear, reliable,
"   consistent, automated, and smooth one.  why make something so frequent and
"   repetitive take up extra programmer cycles?
"
"   typically, the process entails
"      - creating/editing the source,
"      - compiling with suitable options,
"      - reading the compilier's complaints and warnings,
"      - identifying the top errors,
"      - jumping back to source file,
"      - finding the right the line/symbol,
"      - interpreting the error message,
"      - fixing the code,
"      - and then repeating until "clean enough" for gov't work
"   this is painful enough that programmers often ignore various warnings and
"   then don't then use additional static analysis tools to find more.  this
"   process is more or less efficient if multiple term sessions are used to
"   avoid getting in and out of applications and writing/printing error info
"
"   my goal with rsh_fix, is to provide...
"      - short cut to call up rsh_fix and compile in a side-by-side window
"      - enforced options/flags, such as "-Wall" and "-g"
"      - quick visual clue as to pass, fail, warning, or linker issues
"      - format the errors in a quick, one-line format each
"      - easy compile profiles, including pure ansi, c, c++, etc
"      - interface for using a make file or not
"      - sorting errors to the top, warnings lower
"      - select any error in listing and go to it in the source code
"      - toggle to see the original gcc output
"
"   many existing libraries and utilities have been built by better programmers
"   and are likely superior in speed, size, capability, and reliability; BUT,
"   i would not have learned nearly as much using them,  so follow the adage..
"
"  TO TRULY LEARN> do not seek to follow in the footsteps of the men of old;
"  seek what they sought ~ Matsuo Basho
"
"  ADVANTAGES, integrated compile/fix cycle...
"     - no window or terminal switches that slow down the process
"     - much less trivia about compiling to remember
"     - requires no finding and searching in source code
"     - forces the programmer to have the right compile switches/options
"     - is exactly repeatable and therefore dependable
"     - does not skip steps when under stress or time pressures
"     - supports refactoring for disciplined changes by speeding this process
"
"  DISADVANTAGES
"     - means that this module must be built and that takes time
"     - requires this module to be maintained and that takes more time too
"     - can cause the programmer to forget how to do it by hand
"
"
""===[[ DECISION ]]============================================================#

"  PROBLEM (pr)
"     programs are quite tedious to run through the compile/fix cycle nearly
"     continuously and therefore warnings get ignored, fixes come slower,
"     refactoring becomes more rare and dust/cobwebs grow
"
"  OBJECTIVES (o)
"     - make the compile/fix cycle as fast and automated as possible
"     - simple so that it does not require huge learning curve
"     - eleviate much of the pain so small changes get made more often
"
"  ALTERNATIVES and CONSEQUENCES (ac)
"
"     1) keep it manual from the command line
"        - everything is already in place, so no new work
"        - it will exist like this in any environment, so consistent
"        - requires more repetition, typing, and memory
"        - user spends most of the time identifying and finding, not fixing
"
"     2) use make files consistently
"        - this is also a common tool and standard format
"        - greatly eases the compilation task
"        - does not help in identifying and finding the errors
"        - still requires too much time away from fixing
"
"     3) standard vim quickfix
"        - tool is already built in and works
"        - has all the major features needed, and then some
"        - requires the programmer to remember command line commands
"        - still requires a fair amount of coding
"
"     4) use a generally available script
"        - already built and tested on vim
"        - someone else maintains it
"        - often requires other "script" elements that that programmer built
"        - will go out of support as it is freeware
"
"     5) build my own script based on the work of others
"        - will fit like a glove and fits into my development environment
"        - allows me to minimize the keystrokes based on my needs
"        - just one more thing i must maintain
"        - will have to move it between machines to have it where i need it
"
"  JUDGEMENT
"
"     only part-timers or newbees think that this should be done by hand as
"     they don't have to maintain software under time pressure.  as long as
"     an option is relatively simple and can speed this process it is a godsend
"
"     it is critical that i do everything i can to speed this cycle so i can
"     take on as many projects as maximally possible (and then some) to keep
"     the personal goals moving forward; therefore, automate early and often.
"
"     finally, without rapid compile/fix you can not refactor with any
"     confidence and therefore maintaining code becomes more of a hit-and-miss
"     which is completely unacceptable
"
"     i choose to build my own scripts at they will never exceed 500 code lines
"     and the results will be maximally tuned to speed and my needs.  also
"     the existing scripts are continuously being superceeded and outmoded
"     so that key features come and go and user interface changes which is
"     unexceptable, so i will build a consistent one
"
"  BOTTOM LINE : code like your life depends on it, because someday it will
"
"
""===[[ END HDOC ]]============================================================#



""===[[ GLOBALS ]]=============================================================#
let   g:hfix_title    = "HFIX_buffer"
let   g:hfix_locked   = "n"
let   g:hfix_curbuf   = -1
let   g:hfix_sources  = ""

let   s:hfix_bufname  = ""
let   s:hfix_size     = 15

let   s:hfix_curr     = 0
let   s:hfix_maxx     = 0
let   s:hfix_tagn     = ""
let   s:hfix_file     = ""
let   s:hfix_line     = 0
let   s:hfix_coln     = 0

let   s:gcc_call      = "make --silent install"
let   s:gcc_std       = " "



""=========================-------------------------==========================##
""===----             standard initialization fuctions (6)             ----===##
""=========================-------------------------==========================##
""  ...._init        :: prepare script/window at vim startup
""  ...._syntax      :: setup syntax rules
""  ...._keys        :: setup key mappings
""  ...._unkeys      :: remove key mappings
""  ...._auto        :: setup auto commands
""  ...._unauto      :: remove auto commands
func! s:o___STD_INIT________o()
endf


func! s:HFIX_init()
   sil!  exec  'split ' . g:hfix_title
   call  HFIX_resize   ("o")
   call  HALL_start    ()
   call  s:HFIX_prefix ()
   call  s:HFIX_syntax ()
   call  HFIX_keys     ()
   hide
   retu
endf


func! s:HFIX_syntax()
   setlo modifiable
   syn   clear
   "---(syntax highlighting = headers)-----------#
   syn   match rsh_fix_lsum     '^HFIX·gcc.*\[!\]$'
   syn   match rsh_fix_esum     '^HFIX·gcc.*\[E\]$'
   syn   match rsh_fix_wsum     '^HFIX·gcc.*\[W\]$'
   syn   match rsh_fix_psum     '^HFIX·gcc.*\[p\]$'
   syn   match rsh_fix_msum     '^HFIX·gcc.*\[m\]$'
   high  rsh_fix_lsum     cterm=none   ctermbg=7     ctermfg=none
   high  rsh_fix_esum     cterm=none   ctermbg=1     ctermfg=none
   high  rsh_fix_wsum     cterm=none   ctermbg=3     ctermfg=none
   high  rsh_fix_psum     cterm=none   ctermbg=2     ctermfg=none
   high  rsh_fix_msum     cterm=none   ctermbg=0     ctermfg=none
   "---(syntax highlighting = footers)-----------#
   syn   match rsh_fix_lend     '^end-of-data .*\[!\]$'
   syn   match rsh_fix_eend     '^end-of-data .*\[E\]$'
   syn   match rsh_fix_wend     '^end-of-data .*\[W\]$'
   syn   match rsh_fix_pend     '^end-of-data .*\[p\]$'
   high  rsh_fix_lend     cterm=none   ctermbg=7     ctermfg=none
   high  rsh_fix_eend     cterm=none   ctermbg=1     ctermfg=none
   high  rsh_fix_wend     cterm=none   ctermbg=3     ctermfg=none
   high  rsh_fix_pend     cterm=none   ctermbg=2     ctermfg=none
   "---(syntax highlighting = lines)-------------#
   syn   match rsh_fix_fail     '^[A-Z][A-Z]·.*\[[!]\]$'
   syn   match rsh_fix_error    '^[A-Z][A-Z]·.*\[E\]$'
   syn   match rsh_fix_error2   '^[A-Z][A-Z]·.*\[e\]$'
   syn   match rsh_fix_warn     '^[A-Z][A-Z]·.*\[W\]$'
   syn   match rsh_fix_warn2    '^[A-Z][A-Z]·.*\[w\]$'
   syn   match rsh_fix_waste    '^[A-Z][A-Z]·.*\[[Uu]\]$'
   syn   match rsh_fix_curr     '^[A-Z][A-Z]°.*$'
   high  rsh_fix_fail     cterm=bold   ctermbg=none  ctermfg=7
   high  rsh_fix_error    cterm=bold   ctermbg=none  ctermfg=1
   high  rsh_fix_error2   cterm=bold   ctermbg=none  ctermfg=6
   high  rsh_fix_warn     cterm=bold   ctermbg=none  ctermfg=3
   high  rsh_fix_warn2    cterm=bold   ctermbg=none  ctermfg=5
   high  rsh_fix_waste    cterm=bold   ctermbg=none  ctermfg=4
   high  rsh_fix_curr     cterm=bold   ctermbg=none  ctermfg=0
   "---(syntax highlighting = headers)-----------#
   syn   match rsh_fix_help1    '^HFIX·gcc.*\[?\]$'
   syn   match rsh_fix_help2    '^....[^·].*\[?\]$'
   syn   match rsh_fix_help3    '^·.*\[?\]$'
   high  rsh_fix_help1    cterm=none   ctermbg=7     ctermfg=none
   high  rsh_fix_help2    cterm=bold   ctermbg=none  ctermfg=7
   high  rsh_fix_help3    cterm=bold   ctermbg=none  ctermfg=7
   "
   "
   " syn   match rsh_fix_file     '^sources :: .*$'
   " syn   match rsh_fix_opt      '^options :: .*$'
   " syn   match rsh_fix_end      '^beginning of .*$'
   " syn   match rsh_fix_end      '^end of .*$'
   " syn   match rsh_fix_recomp   '^recompile .*$'
   " syn   match rsh_fix_relink   '^and link .*$'
   " syn   match rsh_fix_help     '^gcc/make (help).*$'
   " syn   match rsh_fix_clean    '^CLEANING >>.*$'
   " syn   match rsh_fix_note     '^no .*'
   " syn   match rsh_fix_prog     '^compilation.*$'
   " high  rsh_fix_file     cterm=bold   ctermbg=none  ctermfg=5
   " high  rsh_fix_opt      cterm=bold   ctermbg=none  ctermfg=5
   "high  rsh_fix_end      cterm=bold,reverse  ctermbg=none  ctermfg=5
   " high  rsh_fix_end      cterm=reverse  ctermbg=none  ctermfg=5
   " high  rsh_fix_recomp   cterm=reverse  ctermbg=none  ctermfg=5
   " high  rsh_fix_relink   cterm=reverse  ctermbg=none  ctermfg=5
   " high  rsh_fix_help     cterm=none   ctermbg=2     ctermfg=none
   " high  rsh_fix_clean    cterm=none   ctermbg=1     ctermfg=0
   " high  rsh_fix_note     cterm=none   ctermbg=4     ctermfg=0
   " high  rsh_fix_prog     cterm=bold   ctermbg=none  ctermfg=5
   "---(syntax highlighting = tags)--------------#
   " syn   match hfix_mtag     '^[A-Z-][A-Z-]  '
   "          \ containedin=rsh_fix_eone, rsh_fix_wone
   " high  hfix_mtag     cterm=bold   ctermbg=none  ctermfg=4
   " syn   match hfix_ftag     ' \[[a-z-][a-z-]\] '
   "          \ containedin=rsh_fix_eone, rsh_fix_wone
   " high  hfix_ftag     cterm=bold   ctermbg=none  ctermfg=4
   "---(syntax highlighting = numbers)-----------#
   " syn   match rsh_fix_num      ' : [0-9 ][0-9 ][0-9 ][0-9] : '
   "          \ containedin=rsh_fix_eone, rsh_fix_wone
   " high  rsh_fix_num   cterm=bold   ctermbg=none  ctermfg=5
   "---(syntax highlighting = lines)-------------#
   " syn   match rsh_fix_lone     '^.*[L]$'
   " syn   match rsh_fix_eone     '^.*[E]$'
   " syn   match rsh_fix_wone     '^.*[-]$'
   " syn   match rsh_fix_pone     '^.*[*]$'
   " high  rsh_fix_lone  cterm=bold   ctermbg=none  ctermfg=1
   " high  rsh_fix_eone  cterm=bold   ctermbg=none  ctermfg=1
   " high  rsh_fix_wone  cterm=bold   ctermbg=none  ctermfg=3
   " high  rsh_fix_pone  cterm=bold   ctermbg=none  ctermfg=2
   "---(syntax highlighting = current line)------#
   "syntax match rsh_fix_ecur      '^>>'
   "         \ containedin=rsh_fix_eline, rsh_fix_wline
   "hi rsh_fix_ecur  cterm=bold,reverse  ctermbg=none ctermfg=5
   setlo  nomodifiable
   retu
endf

function! HFIX_help  ()
   call   HFIX_unkeys()
   setlo  modifiable
   sil!   exec   ":silent 0,$!HFIX --vim-help"
   normal _0
   setlo  nomodifiable
   call   HFIX_keys()
   call   HBUF_restore ()
   return
endfunction

function! HFIX_reset   ()
   call   HFIX_unkeys  ()
   call s:HFIX_prefix  ()
   call   HFIX_keys    ()
   call   HBUF_restore ()
endfunction

func! HFIX_keys()
   setlo  modifiable
   "---(compile)-------------------------------------#
   nmap            ,q      :call HFIX_show    ()<cr>
   nmap  <buffer>   q      :call HFIX_compile ("q")<cr>
   nmap  <buffer>   f      :call HFIX_compile ("f")<cr>
   nmap  <buffer>   w      :call HFIX_compile ("w")<cr>
   nmap  <buffer>   b      :call HFIX_compile ("b")<cr>
   nmap  <buffer>   a      :call HFIX_compile ("a")<cr>
   nmap  <buffer>   c      :call HFIX_compile ("c")<cr>
   nmap  <buffer>   C      :call HFIX_compile ("C")<cr>
   nmap  <buffer>   E      :call HFIX_compile ("E")<cr>
   nmap  <buffer>   W      :call HFIX_compile ("W")<cr>
   nmap  <buffer>   *      :call HFIX_compile ("*")<cr>
   nmap  <buffer>   i      :call HFIX_compile ("i")<cr>
   nmap  <buffer>   I      :call HFIX_compile ("I")<cr>
   nmap  <buffer>   u      :call HFIX_compile ("u")<cr>
   nmap  <buffer>   m      :call HFIX_compile ("m")<cr>
   nmap  <buffer>   r      :call HFIX_c_recon ()<cr>
   "---(presentation/size)---------------------------#
   nmap  <buffer>   -      :call HFIX_resize  ("-")<cr>
   nmap  <buffer>   +      :call HFIX_resize  ("+")<cr>
   nmap  <buffer>   h      :call HFIX_hide    ()<cr>
   "---(moves)---------------------------------------#
   nmap  <buffer>   [      :call HFIX_cursor  ("[")<cr>
   nmap  <buffer>   >      :call HFIX_cursor  (">")<cr>
   nmap  <buffer>   .      :call HFIX_cursor  (".")<cr>
   nmap  <buffer>   <      :call HFIX_cursor  ("<")<cr>
   nmap  <buffer>   ]      :call HFIX_cursor  ("]")<cr>
   "---(configuration)-------------------------------#
   " nmap  <buffer>   E      :call HFIX_config  ("E")<cr>
   " nmap  <buffer>   W      :call HFIX_config  ("W")<cr>
   " nmap  <buffer>   U      :call HFIX_config  ("U")<cr>
   "---(other)---------------------------------------#
   nmap  <buffer>   Z      :call HFIX_unkeys  ()<cr>
   nmap  <buffer>   ?      :call HFIX_help    ()<cr>
   nmap  <buffer>   !      :call HFIX_reset   ()<cr>
   "---(complete)------------------------------------#
   setlo  nomodifiable
   retu
endf


func! HFIX_unkeys()
   setlo  modifiable
   "---(compile)-------------------------------------#
   nunm  <buffer>   q
   nunm  <buffer>   f
   nunm  <buffer>   w
   nunm  <buffer>   b
   nunm  <buffer>   a
   nunm  <buffer>   c
   nunm  <buffer>   C
   nunm  <buffer>   E
   nunm  <buffer>   W
   nunm  <buffer>   *
      nunm  <buffer>   i
   nunm  <buffer>   I
   nunm  <buffer>   u
   nunm  <buffer>   m
   nunm  <buffer>   r
   "---(presentation/size)---------------------------#
   nunm  <buffer>   +
      nunm  <buffer>   -
      nunm  <buffer>   h
   "---(moves)---------------------------------------#
   nunm  <buffer>   [
      nunm  <buffer>   >
      nunm  <buffer>   <
      nunm  <buffer>   ]
   "---(other)---------------------------------------#
   nmap  <buffer>   Z      :call HFIX_keys  ()<cr>
   nunm  <buffer>   ?
      nunm  <buffer>   !
   "---(complete)------------------------------------#
   setlo  nomodifiable
   retu
endf


func! s:HFIX_auto()
endf


func! s:HFIX_unauto()
endf



""=========================-------------------------==========================##
""===----             standard window action fuctions (4)              ----===##
""=========================-------------------------==========================##
""  ...._on          :: display the window without entering it
""  ...._show        :: enter the window
""  ...._hide        :: take the window off the display
""  ...._resize      :: change the width/height of the window
func! s:o___STD_ACTIONS_____o()
endf

function! HFIX_show()
   "---(do not allow recursion)------------------#
   if (g:hfix_locked == "y")
      return
   endif
   "---(save working win/buf/loc)----------------#
   if (HBUF_save("HBUF_show()         :: ") < 1)
      return
   endif
   "---(lock her down)---------------------------#
   call HALL_lock()
   "---(verify the buffer)-----------------------#
   let buf_num         = bufnr(g:hfix_title)
   if (buf_num < 1)
      call s:HFIX_init()
   endif
   "---(close the existing window)---------------#
   let buf_win = bufwinnr(buf_num)
   if (buf_win > 0)
      silent exec buf_win.' wincmd w'
      hide
   endif
   "---(check for the window)--------------------#
   "if (HBUF_by_name(g:hbuf_title) > 0)
   "   hide
   "endif
   "---(open the buffer window)------------------#
   sil!  exec 'split ' . g:hfix_title
   call  HFIX_resize("c")
   "---(create the autocommands)-----------------#
   call s:HFIX_auto()
   "---(update)----------------------------------#
   "call HBUF_restore()
   call HALL_unlock()
   "---(complete)--------------------------------#
   return
endfunction

func! HFIX_hide()
   ""---(defense)--------------------------------#
   if    (bufname("%") != g:hfix_title)
      retu  -1
   endi
   ""---(process)--------------------------------#
   call  s:HFIX_unauto()
   hide
   call  HBUF_restore()
   ""---(complete)-------------------------------#
   retu
endf

"" PURPOSE : update window size
func! HFIX_resize(height)
   ""---(get current state)----------------------#
   "let   s:hfix_size  = winheight(0)
   ""---(process change)-------------------------#
   if    (a:height == "+")
      let   s:hfix_size +=  5
   elsei (a:height == "-")
      let   s:hfix_size -=  5
   elsei (a:height == "c")
      let   s:hfix_size  = 10
   endi
   ""---(test size values)-----------------------#
   if    (s:hfix_size > 30)
      let   s:hfix_size = 30 
   elsei (s:hfix_size < 10)
      let   s:hfix_size = 10
   endi
   ""---(resize)---------------------------------#
   sil!  exec  "resize ".s:hfix_size
   ""---(complete)-------------------------------#
   return
endf



""=========================-------------------------==========================##
""===----                 specific gcc/make functions                  ----===##
""=========================-------------------------==========================##
func! s:o___SPECIFIC________o()
endf

function! HFIX_c_recon ()
   call   s:HFIX_prepare ("r")
   sil!   exec   ":silent 0,$!HFIX --c_recon_beg"
   norm   0_
   let    x_rc   = strpart (getline (12), 40,  1)
   while (x_rc != 'Y')
       sil!   exec   ":silent 0,$!HFIX_debug @@hfix --c_recon_chk"
       norm   0_
       let    x_rc   = strpart (getline (12), 40,  1)
   endwhile
   norm  _0
   setlo nomodifiable
   let   g:hfix_locked = "n"
   call  HFIX_keys()
   call  HBUF_restore()
endfunction

func! s:HFIX_prefix  ()
   setlo  modifiable
   " sil!   exec   ":silent 0,$d"
   " sil!   exec   printf ("normal i%s", "HFIX·gcc/make·····,qw·wipe··,qc·comp··,qi·inst··,qu·unit··,qm·manu··,q?·help······HFIX·······································································[?]")
   sil!   exec   ":silent 0,$!HFIX --vim-simple"
   normal _0
   setlo  nomodifiable
endf

func! s:HFIX_prepare (a_opt)
   let    g:hfix_locked = "y"
   call   HFIX_unkeys()
   setlo  modifiable
   sil!   exec   ":silent 0,$d"
   sil!   exec   ":silent 0,$!HFIX --vim-action ".a:a_opt
endf

func! s:HFIX_clean   (a_opt)
   normal _0
   if     (stridx ("w", a:a_opt) >= 0)
      sil!   exec   ":silent 0,$!HFIX --clean"
      norm  0_
   " sil!   exec   ":!make --silent clean"
   " sil!   exec   printf ("normal _o%s", "small clean done >> erased primary working files (will cause FULL recompile later)                                                                           [?]")
   " sil!   exec   ":0,$!uwait "
   " norm   _0
   " redraw!
   elseif (stridx ("b", a:a_opt) >= 0)
      sil!   exec   ":!make -silent bigclean"
      sil!   exec   printf ("normal _o%s\n", "big clean done >> erased ALL working files (will cause FULL recompile later)                                                                                 [?]")
      redraw!
   endif
endf

func! s:HFIX_make     (a_opt)
   let    x_msg   = ""
   normal GG
   if     (stridx ("qcaCEW*", a:a_opt) >= 0)
      sil!   exec   ":!make  > gcc.out  2>&1"
      if     (a:a_opt == 'q')
         let   x_msg  = "--errors"
      elseif (a:a_opt == 'c')
         let   x_msg  = "--errors"
      elseif (a:a_opt == 'C')
         let   x_msg  = "--criticals"
      elseif (a:a_opt == 'E')
         let   x_msg  = "--errors"
      elseif (a:a_opt == 'W')
         let   x_msg  = "--warnings"
      elseif (a:a_opt == '*')
         let   x_msg  = "--all"
      endif
      sil!   exec   ":silent 0,$!HFIX gcc.out ".x_msg
      redraw!
   elseif (stridx ("u"  , a:a_opt) >= 0)
      sil!   exec   ":!make units > gcc.out  2>&1"
      sil!   exec   ":silent 0,$!HFIX gcc.out"
      redraw!
   elseif (stridx ("r"  , a:a_opt) >= 0)
      sil!   exec   ":silent 0,$!HFIX --c_recon_beg"
      norm  0_
   endi
endf

func! s:HFIX_install  (a_opt)
   if     (stridx ("q"  , a:a_opt) >= 0)
      normal _0
      let  x_status    = strpart (getline('.'), 15, 4)
      if     (x_status == "FAIL")
         return 0
      elseif (x_status == "ERRS")
         return 0
      endif
      sil!   exec   ":2,$!make --silent install"
      redraw!
   elseif (stridx ("i"  , a:a_opt) >= 0)
      sil!   exec   ":2,$!make --silent install"
      redraw!
   elseif (stridx ("Iq" , a:a_opt) >= 0)
      sil!   exec   ":2,$!make --silent install"
      norm   G
      let    x_curr    = line ('.') + 1
      sil!   exec ":".x_curr.",$!make --silent install_man"
      redraw!
   elseif (stridx ("m"  , a:a_opt) >= 0)
      sil!   exec   ":2,$!make --silent install_man"
      redraw!
   endif
endf

func! HFIX_compile  (a_opt)
   "---(defenses)--------------------------------#
   if    bufwinnr(g:HTAG_title) < 1
      call   s:HFIX_prefix ()
      echon  "HFIX_compile()           :: tag window must be open (returning)..."
      retu
   endi
   if    (g:hfix_locked == "y")
      call   s:HFIX_prefix ()
      echon  "HFIX_compile()   :: already compiling, locked!"
      retu
   endi
   "---(prepare)---------------------------------#
   call   s:HFIX_prepare (a:a_opt)
   call   s:HFIX_clean   (a:a_opt)
   call   s:HFIX_make    (a:a_opt)
   call   s:HFIX_install (a:a_opt)
   "---(get the function names)------------------#
   call   HFIX_count ()
   let   x_curr = 2
   normal _ 0 j
   while (line ('.') <= s:hfix_maxx)
      "    "       "echo  "tagn=".s:hfix_tagn.", file=".s:hfix_file.", line=".s:hfix_line
      let   x_buf  = HFIX_buf ()
      if x_buf < 0
         let  x_buf = "-"
      elseif (x_buf > 9)
         let x_buf = printf("%c", 65 - 10 + x_buf)
         exec "normal 0 4l R".x_buf
      else
         exec "normal 0 4l R".x_buf
      endif
      normal 0 j
   endwhile

   norm  _0
   setlo nomodifiable
   let   g:hfix_locked = "n"
   call  HFIX_keys()
   call  HBUF_restore()
   retu


   "---(clean)-----------------------------------#
   " let   g:hfix_locked = "y"
   " echon "HFIX_compile()    :: compiling ".g:hfix_sources."..."
   " call  HFIX_unkeys()
   " setlocal modifiable
   " sil!  exec ":silent 1,$d"
   " sil!  exec  printf("normal i%-86.86s\n", "compilation in progress...")
   " redraw!
   "---(cleaning)-------------------s------------#
   " if    a:std == "a"
   "    sil!  exec ":silent 1,$!make --silent clean"
   " endi
   " if    a:std == "x" || a:std == "X"
   "    sil!  exec ":silent 1,$!make --silent clean"
   "    if (a:std == "X")
   "       sil!  exec ":silent $!make --silent bigclean"
   "    endif
   "    normal _
   "    exec "normal O"
   "    exec printf("normal i%-86.86s", "gcc/make (pass) | temporary file clean request")
   "    normal GG
   "    exec "normal o"
   "    exec printf("normal i%-86.86s", "end of installation feedback")
   " endi
   "---(compliation)-----------------------------#
   " if    a:std == "q" || a:std == "c" || a:std == "a"
   "    sil!  exec ":silent 1,$!make -s"
   "    "---(eliminate wide-characters)---------------#
   "    sil!  exec ':silent 1,$:s/\%u2018/"/ge'
   "    sil!  exec ':silent 1,$:s/\%u2019/"/ge'
   "    "---(format the results)----------------------#
   "    sil!  exec ":silent 1,$!HFIX.awk"
   "    "---(add a footer)----------------------------#
   "    normal GG
   "    exec "normal o"
   "    exec printf("normal i%-86.86s", "end of compiler feedback")
   " endi
   " if    a:std == "u"
   "    sil!  exec ":silent 1,$!make --silent units"
   "    "---(eliminate wide-characters)---------------#
   "    sil!  exec ':silent 1,$:s/\%u2018/"/ge'
   "    sil!  exec ':silent 1,$:s/\%u2019/"/ge'
   "    "---(format the results)----------------------#
   "    sil!  exec ":silent 1,$!HFIX.awk"
   "    "---(add a footer)----------------------------#
   "    normal GG
   "    exec "normal o"
   "    exec printf("normal i%-86.86s", "end of compiler feedback")
   " endi
   "---(installation)----------------------------#
   " if    a:std == "m"
   "    sil!  exec ":silent 1,$!make --silent install_man"
   "    normal _
   "    exec "normal O"
   "    exec printf("normal i%-86.86s", "gcc/make (pass) | manual installation request")
   "    normal GG
   "    exec "normal o"
   "    exec printf("normal i%-86.86s", "end of installation feedback")
   " endif
   " if    a:std == "i"
   "    sil!  exec ":silent 1,$!make --silent install"
   "    normal _
   "    exec "normal O"
   "    exec printf("normal i%-86.86s", "gcc/make (pass) | executable installation request")
   "    normal GG
   "    exec "normal o"
   "    exec printf("normal i%-86.86s", "end of installation feedback")
   " endif
   " if    a:std == "q" || a:std == "a"
   "    sil!  exec ":silent $!make --silent install"
   "    normal GG
   "    exec "normal o"
   "    exec printf("normal i%-86.86s", "end of installation feedback")
   " endif
   " norm   _


   "---(prepare for return)----------------------#
   norm  _j
   setlo nomodifiable
   let   g:hfix_locked = "n"
   call  HFIX_keys()
   call  HBUF_restore()
   retu
endf


function! HFIX_hints (tag)
   "---(switch to tag window)-----------------#
   let   buf_cur = bufnr('%')
   let   win_num = HBUF_by_name(g:hfix_title)
   if    win_num < 1
      echon "  -- FIX not open, can not process..."
   endi
   sil   exec win_num.' wincmd w'
   sil!  call HFIX_unkeys()        " get the key mappings off
   norm  _
   "---(find the tag)-------------------------#
   call  HFIX_curr_clear ()
   call  search("^".a:tag.". ")
   if    line(".") < 2
      echon "  -- tag å".a:tag."æ not found, can not process..."
      sil!  call HFIX_keys()
      retu
   endi


   norm  0
   call  s:HFIX__list_entry()

   let   s:hfix_curr   = line ('.')
   call  HFIX_curr_set   ()
   " return

   "---(get the keys back on)-----------------#
   sil!  call HFIX_keys()
   "---(get back to the original window)------#
   norm  ,a
   let   buf_num = bufnr(s:hfix_file)
   if    buf_num == -1
      echon "HCSC_hints()          :: buffer not open in wim..."
      retu
   else
      sil   exec('b! ' . buf_num)
   endi
   "---(get to the right line)----------------# make sure to show comments above
   norm  _
   if (s:hfix_line > 1)
      sil!  exec "normal ".(s:hfix_line - 1)."j"
   endif
   sil!  exec "normal 0"
   if (s:hfix_coln > 1)
      sil!  exec "normal ".(s:hfix_coln - 1)."l"
   endif
   sil!  exec "normal z."
   echon "TAG å".s:hfix_tagn."æ in å".s:hfix_file."æ at (".s:hfix_line."/".s:hfix_coln.")"
   "---(complete)-----------------------------#
   retu
endf

""===[[ UTILITY ]]=============================================================#

function! HFIX_parse()
   "---(clear out old information)---------------#
   let l:efull    = ""
   let l:etype    = ""
   let l:ebuff    = ""
   let l:efile    = ""
   let l:eline    = 0
   let l:emesg    = ""
   let l:esymb    = ""
   "---(get the current error)-------------------#
   let l:efull = getline('.')
   if strpart(l:efull,0,2) != "  "
      echon "HFIX_parse()     :: not a valid error line..."
      silent! normal ,a
      return
   endif
   "---(parse the error message)-----------------#
   let l:efile = matchstr(l:efull, "  #1#  .\*  #2#  ")
   let l:efile = strpart(l:efile,7,strlen(l:efile)-14)
   let l:ebuff = matchstr(l:efull, "  #2#  .\*  #3#  ")
   let l:ebuff = strpart(l:ebuff,7,strlen(l:ebuff)-14)
   let l:eline = matchstr(l:efull, "  #3#  [1-9][0-9]\*  #4#  ")
   let l:eline = strpart(l:eline,7,strlen(l:eline)-14) + 0
   let l:emesg = matchstr(l:efull, "  #4#  .\*  #5#  ")
   let l:emesg = strpart(l:emesg,7,strlen(l:emesg)-14)
   let l:esymb = matchstr(l:efull, "  #5#  .\*  #6#  ")
   let l:esymb = strpart(l:esymb,7,strlen(l:esymb)-14)
   let l:efull = matchstr(l:efull, "  #6#  .\*  #7#  ")
   let l:efull = strpart(l:efull,7,strlen(l:efull)-14)
   "---(mark this error)-------------------------#
   setlocal modifiable
   silent! normal 0R>>
   setlocal nomodifiable
   silent! normal ,a
   silent! exec 'b! ' . l:ebuff
   silent! norm  _
   silent! exec ":normal " . l:eline . "jk"
   silent! normal z.
   "let  [x_row,x_col] = searchpos(l:identifier,"",l:destline)
   "execute "silent! syntax clear rsh_fix_identifier"
   "execute "highlight link rsh_fix_identifier error"
   "execute "syntax match rsh_fix_identifier '" . l:identifier . "' containedin=ALL"
   echon "HFIX_parse()     :: ".l:emesg
   return
endfunction



""=============================================================================#
""===[[ WINDOW UPDATE CODE ]]==================================================#
""=============================================================================#



""=========================-------------------------==========================##
""===----                   standard list handling                     ----===##
""=========================-------------------------==========================##
""  ...._head        :: go to the first entry
""  ...._next        :: go to the next entry
""  ...._entry       :: parse the current entry
""  ...._goto        :: show the source at the current entry
""  ...._update      :: add tags and buffer numbers to current entry
func! s:o___STD_LIST________o()
endf


let  s:hfix_lhead       = 1
let  s:hfix_lcurr       = 0

function! HFIX_count  ()
   exec  "normal G"
   let   s:hfix_maxx   = line ('.')
   let   s:hfix_curr   = 2
   let   l:count       = 2
   call  search("^end-of_data")
   if    (line(".") > 2)
      let   s:hfix_maxx   = line ('.') - 1
   else
      let   s:hfix_maxx   = 0
   endif
   exec  "normal ".l:count."G"
   echon "l:count = ".l:count.", s:hfix_maxx = ".s:hfix_maxx
endfunction

function! HFIX_curr_clear ()
   setlo  modifiable
   exec   "normal ".s:hfix_curr."G"
   exec   "normal 0 2l r·"
   setlo  nomodifiable
endfunction

function! HFIX_curr_set   ()
   setlo  modifiable
   normal _0
   exec   "normal ".s:hfix_curr."G"
   exec   "normal 0 2l r°"
   normal 0
   setlo  nomodifiable
   return strpart (getline ('.'), 0, 2)
endfunction

function! HFIX_cursor (dir)
   "--(remove existing mark)-------------"
   call HFIX_curr_clear ()
   "--(update cursor)--------------------"
   if     (a:dir == "[")
      let   s:hfix_curr   = 2
      echo  "HFIX_cursor (head)  :: new line = ".s:hfix_curr.", maxx = ".s:hfix_maxx
   elseif (a:dir == ">")
      let   s:hfix_curr  += 1
      echo  "HFIX_cursor (next)  :: new line = ".s:hfix_curr.", maxx = ".s:hfix_maxx
   elseif (a:dir == ".")
      echo  "HFIX_cursor (curr)  :: new line = ".s:hfix_curr.", maxx = ".s:hfix_maxx
   elseif (a:dir == "<")
      let   s:hfix_curr  -= 1
      echo  "HFIX_cursor (prev)  :: new line = ".s:hfix_curr.", maxx = ".s:hfix_maxx
   elseif (a:dir == "]")
      let   s:hfix_curr   = 5000
      echo  "HFIX_cursor (tail)  :: new line = ".s:hfix_curr.", maxx = ".s:hfix_maxx
   endif
   "--(enforce limits)-------------------"
   if (s:hfix_curr < 2)
      let   s:hfix_curr   = 2
   endif
   if (s:hfix_curr > s:hfix_maxx)
      let   s:hfix_curr   = s:hfix_maxx
   endif
   "--(add new mark)---------------------"
   let  x_tagn =  HFIX_curr_set   ()
   "--(return to last window)------------"
   call  HBUF_restore()
   call  HFIX_hints (x_tagn)
endfunction

function!  HFIX_atoi  (str)
   if     (strpart (a:str, 3, 1) == "·")
      return  0
   elseif (strpart (a:str, 2, 1) == "·")
      return strpart (a:str, 3, 1) + 0
   elseif (strpart (a:str, 1, 1) == "·")
      return strpart (a:str, 2, 2) + 0
   elseif (strpart (a:str, 0, 1) == " ")
      return strpart (a:str, 1, 3) + 0
   elseif (strpart (a:str, 0, 1) == "·")
      return strpart (a:str, 1, 3) + 0
   else
      return a:str + 1
   endif
endfunction

function! HFIX_buf        ()
   let   l:x_text   = getline ('.')
   "   "---(check for null)--------------------------#
   if (strpart (x_text, 0, 4) !~ '^[A-Z][A-Z][·°] ')
      return -1
   endi 
   "---(file name)-------------------------------#
   norm   0
   norm   9l
   let    l:x_beg  = col('.') - 1
   norm   E
   let    l:x_end  = col('.')
   norm   0
   let    l:x_name = strpart (x_text, l:x_beg, l:x_end - l:x_beg)
   let    l:x_num  = bufnr (l:x_name) - 1
   return l:x_num
endfunction

func! s:HFIX__list_entry()
   "echo "HFIX__list_entry()"
   "---(initialize)------------------------------#
   let   s:hfix_tagn    = ""
   let   s:hfix_file    = ""
   let   s:hfix_line    = 0
   let   s:hfix_coln    = 0
   "---(check for null)--------------------------#
   let   l:full_line = getline('.')
   if    (strpart (l:full_line, 0, 4) !~ '^[A-Z][A-Z][·°] ')
      retu   -1        " bad line
   endi 
   "---(tag number)------------------------------#
   let   s:hfix_tagn    = strpart(l:full_line, 0, 2)
   "---(file name)-------------------------------#
   norm  0
   norm  9l
   let   l:word_beg = col('.') - 1
   norm  E
   let   l:word_end = col('.')
   let   s:hfix_file    = strpart(l:full_line, l:word_beg, l:word_end - l:word_beg)
   "---(line number)-----------------------------#
   norm  0
   let   l:text         = strpart (l:full_line, 40, 4)
   let   s:hfix_line    = HFIX_atoi (l:text)
   "---(column number)---------------------------#
   norm  0
   let   l:text         = strpart (l:full_line, 44, 4)
   let   s:hfix_coln    = HFIX_atoi (l:text)
   "---(complete)--------------------------------#
   retu  0
endf




""=============================================================================#
""===[[ WINDOW UPDATE CODE ]]==================================================#
""=============================================================================#



call s:HFIX_init()
""===[[ END ]]=================================================================#
