#================================[[ beg-code ]]================================#
include /usr/local/sbin/make_prepare



#===(user defined)=========================================#
# basename of executable, header, and all code files
NAME_BASE  = HFIX
# additional standard and outside libraries
LIB_STD    = 
# all heatherly libraries used, debug versions whenever available
LIB_MINE   = -lyENV_debug
# directory for production code, no trailing slash
INST_DIR   = /usr/local/bin



#===(optional)=============================================#
# extra include directories required
INC_MINE   = 
# utilities generated, separate from main program
NAME_UTIL  = 
# libraries only for the utilities
LIB_UTIL   =
# files to be included in editing session (maybe conf, data, ...)
EDIT_TOO   = HFIX.vim HFIX_master.sh



#===(post-processing)======================================#
# create a rule for...
#
#install_prep       :

#remove_prep        :



#===(master template)======================================#
include /usr/local/sbin/zeno_make



#===(post-processing)======================================#
# create a rule for...

install_post       :
	# add HFIX.vim to plugin directory
	@cp -f HFIX.vim       /home/machine/vim/plugin
	@sha1sum              /home/machine/vim/plugin/HFIX.vim
	# add HFIX_master shell script to install directory
	@cp -f HFIX_master.sh /usr/local/bin/HFIX_master
	@chmod +x             /usr/local/bin/HFIX_master
	@sha1sum              /usr/local/bin/HFIX_master
	# add HFIX_master links that allow it to be forked
	ln --force --physical /usr/local/bin/HFIX_master   /usr/local/bin/HFIX_clean
	ln --force --physical /usr/local/bin/HFIX_master   /usr/local/bin/HFIX_bigclean
	ln --force --physical /usr/local/bin/HFIX_master   /usr/local/bin/HFIX_reconc
	ln --force --physical /usr/local/bin/HFIX_master   /usr/local/bin/HFIX_make
	ln --force --physical /usr/local/bin/HFIX_master   /usr/local/bin/HFIX_reconu
	ln --force --physical /usr/local/bin/HFIX_master   /usr/local/bin/HFIX_units
	ln --force --physical /usr/local/bin/HFIX_master   /usr/local/bin/HFIX_mans
	ln --force --physical /usr/local/bin/HFIX_master   /usr/local/bin/HFIX_unittest
	# done --------------------------------

#remove_post        :



#================================[[ end-code ]]================================#
