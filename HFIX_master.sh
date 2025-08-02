declare  s_logger="/tmp/HFIX.log"
declare  s_output="/tmp/HFIX.out"


echo "who  HFIX_master"                               >  "$s_logger"
echo "arg  $0 "                                       >> "$s_logger"
echo "pid  $!"                                        >> "$s_logger"
echo "pwd  $(pwd)"                                    >> "$s_logger"

##===[[ CLEANING ]]============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_wipe"  ]]; then
   echo "dtl  conduct basic temp file cleaing"        >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make clean                        > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_WIPE"  ]]; then
   echo "dtl  conduct complete temp file cleaing"     >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make bigclean                     > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ PROGRAM ]]=============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_comp"  ]]; then
   echo "dtl  conduct recon on c-language recomp"     >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make --recon                      > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_COMP"  ]]; then
   echo "dtl  recompile c-language files"             >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make  base                        > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ INSTALL ]]=============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_inst"  ]]; then
   echo "dtl  conduct recon on install"               >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make --recon  install             > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_INST"  ]]; then
   echo "dtl  recompile install"                      >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make  install                     > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ UNIT TESTING ]]========================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_unit"  ]]; then
   echo "dtl  conduct recon on unit-test recomp"      >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make --recon units                > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_UNIT"  ]]; then
   echo "dtl  recompile unit-test files (unit/munit)" >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make units                        > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ MANUALS ]]=============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_mans"  ]]; then
   echo "dtl  install manual files"                   >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make --recon install_man          > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_MANS"  ]]; then
   echo "dtl  install manual files"                   >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make install_man                  > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ REMOVAL ]]=============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_remv"  ]]; then
   echo "dtl  conduct recon on installed files"       >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make --recon install_man          > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_REMV"  ]]; then
   echo "dtl  remove installed files"                 >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make install_man                  > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ GIT/SCCS ]]============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_git"   ]]; then
   echo "dtl  conduct recon on git push"              >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make --recon install_man          > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_GIT"   ]]; then
   echo "dtl  conduct git push"                       >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   make install_man                  > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi

##===[[ TESTING/CERT ]]========================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_test"  ]]; then
   echo "dtl  conduct recon on testing/cert"          >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   # make --recon install_man          > "$s_output" 2>&1
   echo "rcc  $?"                                     >> "$s_logger"
   echo "end  $(date)"                                >> "$s_logger"
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_TEST"  ]]; then
   echo "dtl  conduct testing/cert"                   >> "$s_logger"
   echo "beg  $(date)"                                >> "$s_logger"
   # make install_man                  > "$s_output" 2>&1
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

