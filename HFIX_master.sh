echo "$0"

##===[[ CLEANING ]]============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_clean" ]]; then
   echo "conduct cleaing"
   make clean                > HFIX.out 2>&1
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_bigclean" ]]; then
   echo "conduct big cleaing"
   make bigclean             > HFIX.out 2>&1
   exit
fi

##===[[ PROGRAM ]]=============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_reconc" ]]; then
   echo "conduct recon on c-language recompilation"
   make --recon              > HFIX.out 2>&1
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_make"   ]]; then
   echo "recompile c-language files"
   make                      > HFIX.out 2>&1
   exit
fi

##===[[ UNIT TESTING ]]========================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_reconu" ]]; then
   echo "conduct recon on unit-test recompilation"
   make --recon units        > HFIX.out 2>&1
   exit
fi
if   [[ "$0" == "/usr/local/bin/HFIX_units"  ]]; then
   echo "recompile unit-test files (unit/munit)"
   make units                > HFIX.out 2>&1
   exit
fi

##===[[ MANUALS ]]=============================================================#
if   [[ "$0" == "/usr/local/bin/HFIX_mans" ]]; then
   echo "install manual files"
   make install_man          > HFIX.out 2>&1
   exit
fi

echo "fell through to end"
