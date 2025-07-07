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
EDIT_TOO   = HFIX.vim



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
	@cp -f HFIX.vim /home/machine/vim/plugin
	@sha1sum   /home/machine/vim/plugin/HFIX.vim

#remove_post        :



#================================[[ end-code ]]================================#
