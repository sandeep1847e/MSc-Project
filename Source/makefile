# Definitions

LIBDIR= ../lib/
BINDIR= ../bin/internal/
PDFDIR= ./PDF/
CUTTOOLSDIR= ./CutTools/
IREGIDIR= ./IREGI/src/

include make_opts

# Source files

PROCESS= hfill.o matrix.o myamp.o 
DSAMPLE = dsample.o ranmar.o DiscreteSampler.o StringCast.o 
HBOOK = hfill.o hcurve.o hbook1.o hbook2.o
GENERIC = $(alfas_functions).o transpole.o invarients.o hfill.o pawgraphs.o ran1.o \
          rw_events.o rw_routines.o kin_functions.o open_file.o basecode.o setrun.o \
          run_printout.o dgauss.o readgrid.o getissud.o
INCLUDEF= coupl.inc genps.inc hbook.inc DECAY/decay.inc psample.inc cluster.inc sudgrid.inc
COMBINE = combine_events.o  rw_events.o ranmar.o  kin_functions.o open_file.o rw_routines.o alfas_functions.o setrun.o
GENSUDGRID = gensudgrid.o is-sud.o setrun_gen.o rw_routines.o open_file.o

# Locally compiled libraries

LIBRARIES=$(LIBDIR)libdsample.$(libext) $(LIBDIR)libgeneric.$(libext)

# Binaries

BINARIES = $(BINDIR)gen_ximprove $(BINDIR)gensudgrid $(BINDIR)combine_runs

# Compile commands

all: $(LIBRARIES) $(LIBDIR)libdhelas.$(libext) $(LIBDIR)libpdf.$(libext) $(LIBDIR)libmodel.$(libext) $(LIBDIR)libcernlib.$(libext) $(LIBDIR)libbias.$(libext)


# Libraries

$(LIBDIR)libdsample.$(libext): $(DSAMPLE)
	$(call CREATELIB, $@, $^)
$(LIBDIR)libgeneric.$(libext): $(GENERIC)
	$(call CREATELIB, $@, $^)
$(LIBDIR)libdhelas.$(libext): DHELAS
	cd DHELAS; make
$(LIBDIR)libpdf.$(libext): PDF
	cd PDF; make	
$(LIBDIR)libcernlib.$(libext): CERNLIB
	cd CERNLIB; make
# The bias library is here the dummy by default; compilation of other ones specified in the run_card will be done by MG5aMC directly.
$(LIBDIR)libbias.$(libext): BIAS/dummy
	cd BIAS/dummy; make

$(LIBDIR)libmodel.$(libext): MODEL param_card.inc
	cd MODEL; make    
param_card.inc: ../Cards/param_card.dat
	../bin/madevent treatcards param


$(BINDIR)gen_ximprove: gen_ximprove.o ranmar.o rw_routines.o open_file.o 
	$(FC) $(LDFLAGS) -o $@ $^
#$(BINDIR)combine_events: $(COMBINE) $(LIBDIR)libmodel.$(libext) $(LIBDIR)libpdf.$(libext) run_card.inc $(LIBDIR)libbias.$(libext)
#			 $(FC) -o $@ $(COMBINE) -L$(LIBDIR) -lmodel -lpdf $(llhapdf) $(LDFLAGS) -lbias
$(BINDIR)gensudgrid: $(GENSUDGRID) $(LIBDIR)libpdf.$(libext) $(LIBDIR)libcernlib.$(libext)
	$(FC) -o $@ $(GENSUDGRID) -L$(LIBDIR) -lmodel -lpdf -lcernlib $(llhapdf) $(LDFLAGS)

# Dependencies

dsample.o: DiscreteSampler.o dsample.f genps.inc StringCast.o
DiscreteSampler.o: StringCast.o
invarients.o: invarients.f genps.inc
setrun.o: setrun.f nexternal.inc leshouche.inc genps.inc
gen_ximprove.o: gen_ximprove.f run_config.inc run_card.inc
#combine_events.o: combine_events.f run_config.inc run_card.inc
combine_runs.o: combine_runs.f run_config.inc run_card.inc
select_events.o: select_events.f run_config.inc
setrun.o: setrun.f nexternal.inc leshouche.inc run_card.inc run_config.inc
rw_events.o: rw_events.f run_config.inc

run_card.inc: ../Cards/run_card.dat
	../bin/madevent treatcards run

clean4pdf:
	rm -f ../lib/libpdf.$(libext)
	rm -f ../lib/libgeneric.$(libext)

cleanCT:
	cd $(CUTTOOLSDIR); make clean; cd ..

cleanIR:
	cd $(IREGIDIR); make clean; cd ..

libiregi: $(LIBDIR)libiregi.a

libcuttools: $(LIBDIR)libcts.a

treatCards:
	../bin/madevent treatcards all

treatCardsLoopNoInit:
	../bin/madevent treatcards loop --no_MadLoopInit

libmodel: $(LIBDIR)libmodel.$(libext)

libdhelas: $(LIBDIR)libdhelas.$(libext)

$(LIBDIR)libcts.a: $(CUTTOOLSDIR)
	cd $(CUTTOOLSDIR); make
	ln -sf ../Source/$(CUTTOOLSDIR)includects/libcts.a $(LIBDIR)libcts.a
	ln -sf ../Source/$(CUTTOOLSDIR)includects/mpmodule.mod $(LIBDIR)mpmodule.mod

$(LIBDIR)libiregi.a: $(IREGIDIR)
	cd $(IREGIDIR); make
	ln -sf ../Source/$(IREGIDIR)libiregi.a $(LIBDIR)libiregi.a

clean:
	$(RM) *.o $(LIBRARIES) $(BINARIES)
	cd PDF; make clean; cd ..
	cd DHELAS; make clean; cd ..
	cd CERNLIB; make clean; cd ..
	cd MODEL; make clean; cd ..
	cd BIAS/dummy; make clean; cd ../..
	cd BIAS/ptj_bias; make clean; cd ../..
	if [ -d $(CUTTOOLSDIR) ]; then cd $(CUTTOOLSDIR); make clean; cd ..; fi
	if [ -d $(IREGIDIR) ]; then cd $(IREGIDIR); make clean; cd ..; fi
	for i in `ls -d ../SubProcesses/P*`; do cd $$i; make clean; cd -; done;
