###########################################################################
## Makefile generated for component 'Intel_Realsense'. 
## 
## Makefile     : Intel_Realsense.mk
## Generated on : Tue Jan 11 09:07:38 2022
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/Intel_Realsense.rt-linux_nvidia
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = Intel_Realsense
MAKEFILE                  = Intel_Realsense.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2021a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2021a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/TP_QCAR/TP_21_22/Dahmane-Jacquot/1_Explore
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 1
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          QUARC linux_nvidia | gmake (64-bit Windows)
# Supported Version(s):    7.4
# ToolchainInfo Version:   R2019a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# MINGW_DIR
# ldebug

#-----------
# MACROS
#-----------

TOOL_ROOT           = $(MINGW_DIR)/nvidia/7.4.0/aarch64-linux-gnu
TOOL_BIN            = $(TOOL_ROOT)/bin
GCC_WARN_OPTS       = -Wc,-Wall -Wc,-W -Wc,-Wwrite-strings -Wc,-Winline -Wc,-Wstrict-prototypes -Wc,-Wnested-externs -Wc,-Wpointer-arith -Wc,-Wcast-align
GCC_WARN_OPTS_MAX   = $(GCC_WARN_OPTS) -Wc,-Wcast-qual -Wc,-Wshadow
REQ_OPTS            = -c -mfix-cortex-a53-843419 -Wall -fmessage-length=0 -MMD -MP -fpic -feliminate-unused-debug-types
QUARC_REQ_OPTS      = -DVXWORKS -DQUARC -D_GNU_SOURCE -DTARGET_TYPE=linux_nvidia -D_NVIDIA
CFLAGS_ADDITIONAL   = $(ANSI_OPTS)
CPPFLAGS_ADDITIONAL = $(CPP_ANSI_OPTS)
QUARC_LDFLAGS       = -Wl,--hash-style=gnu -Wl,--as-needed -L$(QUARC)/lib/linux_nvidia -L$(TOOL_ROOT)/usr/lib/aarch64-linux-gnu/tegra -L$(TOOL_ROOT)/usr/local/cuda/lib64 -Wl,-rpath-link=$(TOOL_ROOT)/usr/lib/aarch64-linux-gnu/tegra -Wl,-rpath-link=$(TOOL_ROOT)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link=$(TOOL_ROOT)/lib/aarch64-linux-gnu
QUARC_LIBS          = -lextmode_quarc_r2013b -lquanser_communications -lquanser_runtime -lquanser_common
QUARC_SYS_LIBS      = -lfreenect -lasound -lsndfile -lnveglstream_camconsumer -lnvargus_socketclient -lnvjpeg -lnvbuf_utils -lcudart_static -lcuda -lEGL -lrt -lpthread -ldl -lm

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = $(QUARC_LIBS) $(QUARC_SYS_LIBS)

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: MinGW QUARC C Cross-Compiler
CC_PATH = $(TOOL_BIN)
CC = "$(CC_PATH)/aarch64-linux-gnu-gcc"

# Linker: MinGW QUARC C/C++ Linker
LD_PATH = $(TOOL_BIN)
LD = "$(LD_PATH)/aarch64-linux-gnu-g++"

# C++ Compiler: MinGW QUARC C++ Cross-Compiler
CPP_PATH = $(TOOL_BIN)
CPP = "$(CPP_PATH)/aarch64-linux-gnu-g++"

# C++ Linker: MinGW QUARC C/C++ Linker
CPP_LD_PATH = $(TOOL_BIN)
CPP_LD = "$(CPP_LD_PATH)/aarch64-linux-gnu-g++"

# Archiver: MinGW QUARC C/C++ Archiver
AR_PATH = $(TOOL_BIN)
AR = "$(AR_PATH)/aarch64-linux-gnu-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = $(REQ_OPTS) $(QUARC_REQ_OPTS) $(CFLAGS_ADDITIONAL) \
                       -O  -DNDEBUG
CPPFLAGS             = $(REQ_OPTS) $(QUARC_REQ_OPTS) $(CPPFLAGS_ADDITIONAL) \
                       -O  -DNDEBUG
CPP_LDFLAGS          = $(ldebug) $(QUARC_LDFLAGS)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(QUARC_LDFLAGS) \
                         -shared
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(QUARC_LDFLAGS)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(QUARC_LDFLAGS) \
                       -shared



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/Intel_Realsense.rt-linux_nvidia
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/Intel_Realsense_quarc_linux_nvidia -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -IC:/PROGRA~1/Quanser/QUARC/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=1 -DALLOCATIONFCN=0 -DEXT_MODE=1 -DMAT_FILE=0 -DONESTEPFCN=0 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=0
DEFINES_QUARC = -DASSERTIONS=1 -DDOASSERTS
DEFINES_STANDARD = -DMODEL=Intel_Realsense -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_QUARC) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/Intel_Realsense.c $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/Intel_Realsense_data.c $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/Intel_Realsense_main.c $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/rtGetInf.c $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/rtGetNaN.c $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/rt_nonfinite.c $(MATLAB_ROOT)/rtw/c/src/rt_sim.c C:/PROGRA~1/Quanser/QUARC/quarc/src/ext_svr.c C:/PROGRA~1/Quanser/QUARC/quarc/src/updown.c C:/PROGRA~1/Quanser/QUARC/quarc/src/ext_work.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = Intel_Realsense.o Intel_Realsense_data.o Intel_Realsense_main.o rtGetInf.o rtGetNaN.o rt_nonfinite.o rt_sim.o ext_svr.o updown.o ext_work.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~3/LI8DF1~1.A C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~3/LI2456~1.A C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~3/LIBQUA~4.A C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~3/LI5A2F~1.A

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


include $(QUARC)/include/gcc_c_dialect.mk


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o$(PRODUCT) $(OBJS) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


Intel_Realsense.o : $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/Intel_Realsense.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Intel_Realsense_data.o : $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/Intel_Realsense_data.c
	$(CC) $(CFLAGS) -o"$@" "$<"


Intel_Realsense_main.o : $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/Intel_Realsense_main.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rtGetInf.o : $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/rtGetInf.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rtGetNaN.o : $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/rtGetNaN.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rt_nonfinite.o : $(START_DIR)/Intel_Realsense_quarc_linux_nvidia/rt_nonfinite.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rt_sim.o : $(MATLAB_ROOT)/rtw/c/src/rt_sim.c
	$(CC) $(CFLAGS) -o"$@" "$<"


ext_svr.o : C:/PROGRA~1/Quanser/QUARC/quarc/src/ext_svr.c
	$(CC) $(CFLAGS) -o"$@" "$<"


updown.o : C:/PROGRA~1/Quanser/QUARC/quarc/src/updown.c
	$(CC) $(CFLAGS) -o"$@" "$<"


ext_work.o : C:/PROGRA~1/Quanser/QUARC/quarc/src/ext_work.c
	$(CC) $(CFLAGS) -o"$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


