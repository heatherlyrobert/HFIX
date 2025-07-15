declare  s_logger="HFIX.log"
declare  s_output="HFIX.out"


echo "who  HFIX_master"                               >  "$s_logger"
echo "arg  $0 "                                       >> "$s_logger"
echo "pid  $!"                                        >> "$s_logger"
echo "pwd  $(pwd)"                                    >> "$s_logger"

##===[[ CLEANING ]]============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_clean" ]]; then
   echo "dtl  conduct basic temp file cleaing"        >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make clean                        > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_bigclean" ]]; then
   echo "dtl  conduct complete temp file cleaing"     >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make bigclean                     > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ PROGRAM ]]=============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_reconc" ]]; then
   echo "dtl  conduct recon on c-language recomp"     >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make --recon                      > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_make"   ]]; then
   echo "dtl  recompile c-language files"             >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make                              > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ UNIT TESTING ]]========================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_reconu" ]]; then
   echo "dtl  conduct recon on unit-test recomp"      >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make --recon units                > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_units"  ]]; then
   echo "dtl  recompile unit-test files (unit/munit)" >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make units                        > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ MANUALS ]]=============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_mans" ]]; then
   echo "dtl  install manual files"                   >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make install_man                  > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ TESTING ]]=============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_unittest" ]]; then
   echo "dtl  run unit_daemon to track"               >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   unit_daemon --nodaemon --long     > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   
fi

echo "BOOM, fell through to end"                      >> "$s_logger"

