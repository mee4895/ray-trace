#
# Main makefile
#

CC        := g++
CFLAGS    := -Wall

TARGET    := code
LIB       := 

SRCDIR    := src
SRCEXT    := cpp
OUTDIR    := out
OUTEXT    := o
BINDIR    := bin
INCDIR    := inc
DOCDIR    := doc

SOURCES   := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS   := $(patsubst $(SRCDIR)/%,$(OUTDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OUTEXT)))


all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) $^ $(LIB) -o $@

$(OUTDIR)/%.$(OUTEXT): $(SRCDIR)/%.$(SRCEXT)
	@dirname $@ | xargs mkdir -p
	$(CC) $(CFLAGS) -I ./$(SRCDIR) -I ./$(INCDIR) -c $< -o $@

clean:
	rm -r $(OUTDIR)/* $(BINDIR)/$(TARGET)
