
# For python linking (require f2py part of numpy)
ifeq ($(origin MENUM),undefined)
  MENUM=2
endif
P1_gg_ttxttx/matrix$(MENUM)py.so:
	cd P1_gg_ttxttx;make matrix$(MENUM)py.so
P1_uux_ttxttx/matrix$(MENUM)py.so:
	cd P1_uux_ttxttx;make matrix$(MENUM)py.so
all:  P1_gg_ttxttx/matrix$(MENUM)py.so  P1_uux_ttxttx/matrix$(MENUM)py.so 
	echo 'done'