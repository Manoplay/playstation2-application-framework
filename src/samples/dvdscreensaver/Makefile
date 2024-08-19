# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.

EE_INCS += -I$(GSKIT)/include -I$(PS2SDK)/paf/include

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

EE_LIB_DIRS += -L$(GSKIT)/lib -L$(PS2SDK)/ports/lib -L$(PS2SDK)/paf/lib

EE_BIN = dvdscreensaver.elf
EE_OBJS =  $(patsubst %.cpp,%.o,$(shell find . -type f -name "*.cpp"))
EE_LDFLAGS += $(EE_LIB_DIRS)
EE_LIBS = -lpaf -ldebug -lgskit -ldmakit -lcdvd -lpatches -lgskit_toolkit -ltiff -ljpeg -lpng -lz -lpad

all: $(EE_BIN)

clean:
	rm -rf $(EE_BIN)
	find . -type f -name "*.o" -delete


include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal_cpp