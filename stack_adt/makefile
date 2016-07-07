PROJECT=paren_check
DEMO=stack_demo

CPPC=g++
CPPFLAGS=-Wall -std=c++14

OBJDIR=./obj
SRCDIR=./src
BINDIR=./bin

all: project demo

project: $(OBJDIR)/paren_check.o $(OBJDIR)/stack_adt.o
	$(CPPC) $(CPPFLAGS) $^ -o $(BINDIR)/$(PROJECT)

demo: $(OBJDIR)/stack_demo.o $(OBJDIR)/stack_adt.o
	$(CPPC) $(CPPFLAGS) $^ -o $(BINDIR)/$(DEMO)

$(OBJDIR)/stack_adt.o: $(SRCDIR)/stack_adt.cc
	$(CPPC) $(CPPFLAGS) -c $< -o $@

$(OBJDIR)/paren_check.o: paren_check.cc
	$(CPPC) $(CPPFLAGS) -c $< -o $@

$(OBJDIR)/stack_demo.o: stack_demo.cc
	$(CPPC) $(CPPFLAGS) -c $< -o $@

bdir:
	mkdir bin

objdir:
	mkdir obj

.PHONY: clean

clean:
	rm $(OBJDIR)/* $(BINDIR)/*
