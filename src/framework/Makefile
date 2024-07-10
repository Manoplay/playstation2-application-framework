# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.

EE_INCS += -I$(GSKIT)/include

EE_CXXFLAGS +=                \
	-O2                       \
	-Wno-undef				  \
	-funroll-loops            \
	-fexpensive-optimizations \
	-fno-exceptions           \
	-fno-rtti                 \
	-Wall                     \
	-Wformat=2                \
	-Wmissing-braces          \
	-Wparentheses             \
	-Wpointer-arith           \
	-Wreturn-type             \
	-Wsequence-point          \
	-Wswitch                  \
	-Wuninitialized           \
	-Wunknown-pragmas         \
	-Wwrite-strings           \
	$(GLOBAL_DEFINES)

EE_LIB_DIRS += -L$(GSKIT)/lib -L$(PS2SDK)/ports/lib

EE_LIB = libpaf.a
EE_OBJS =  $(patsubst %.cpp,%.o,$(shell find . -type f -name "*.cpp"))
EE_LDFLAGS += $(EE_LIB_DIRS)
EE_LIBS = -ldebug -lgskit -ldmakit -lcdvd -lpatches -lgskit_toolkit -ltiff -ljpeg -lpng -lz -lpad

all: $(EE_LIB)

install: all
	mkdir -p $(PS2SDK)/paf/lib
	mkdir -p $(PS2SDK)/paf/include
	cp $(EE_LIB) $(PS2SDK)/paf/lib
	rsync -rv --include '*/' --include '*.h' --exclude '*' --prune-empty-dirs ./ $(PS2SDK)/paf/include


clean:
	rm -rf $(EE_LIB)
	find . -type f -name "*.o" -delete


include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal_cpp