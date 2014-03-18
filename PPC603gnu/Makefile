# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/RevereRobot2014



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = RevereRobot2014/$(MODE_DIR)/RevereRobot2014.out \
	 RevereRobot2014_partialImage/$(MODE_DIR)/RevereRobot2014_partialImage.o


#Rules

# RevereRobot2014
ifeq ($(DEBUG_MODE),1)
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
RevereRobot2014/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
RevereRobot2014/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
RevereRobot2014/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
RevereRobot2014/$(MODE_DIR)/% : IDE_DEFINES = 
RevereRobot2014/$(MODE_DIR)/% : PROJECT_TYPE = DKM
RevereRobot2014/$(MODE_DIR)/% : DEFINES = 
RevereRobot2014/$(MODE_DIR)/% : EXPAND_DBG = 0
RevereRobot2014/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
RevereRobot2014/$(MODE_DIR)/% : CPU = PPC603
RevereRobot2014/$(MODE_DIR)/% : TOOL_FAMILY = gnu
RevereRobot2014/$(MODE_DIR)/% : TOOL = gnu
RevereRobot2014/$(MODE_DIR)/% : TOOL_PATH = 
RevereRobot2014/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
RevereRobot2014/$(MODE_DIR)/% : LIBPATH = 
RevereRobot2014/$(MODE_DIR)/% : LIBS = 
RevereRobot2014/$(MODE_DIR)/% : OBJ_DIR := RevereRobot2014/$(MODE_DIR)

OBJECTS_RevereRobot2014 = RevereRobot2014_partialImage/$(MODE_DIR)/RevereRobot2014_partialImage.o

RevereRobot2014/$(MODE_DIR)/RevereRobot2014.out : $(OBJECTS_RevereRobot2014)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_RevereRobot2014) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_RevereRobot2014) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

RevereRobot2014/$(MODE_DIR)/RevereRobot2014_compile_file : $(FILE) ;

_clean :: RevereRobot2014/$(MODE_DIR)/RevereRobot2014_clean

RevereRobot2014/$(MODE_DIR)/RevereRobot2014_clean : 
	$(TRACE_FLAG)if [ -d "RevereRobot2014" ]; then cd "RevereRobot2014"; rm -rf $(MODE_DIR); fi


# RevereRobot2014_partialImage
ifeq ($(DEBUG_MODE),1)
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
RevereRobot2014_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
RevereRobot2014_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
RevereRobot2014_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
RevereRobot2014_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
RevereRobot2014_partialImage/$(MODE_DIR)/% : DEFINES = 
RevereRobot2014_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
RevereRobot2014_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
RevereRobot2014_partialImage/$(MODE_DIR)/% : CPU = PPC603
RevereRobot2014_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
RevereRobot2014_partialImage/$(MODE_DIR)/% : TOOL = gnu
RevereRobot2014_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
RevereRobot2014_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
RevereRobot2014_partialImage/$(MODE_DIR)/% : LIBPATH = 
RevereRobot2014_partialImage/$(MODE_DIR)/% : LIBS = 
RevereRobot2014_partialImage/$(MODE_DIR)/% : OBJ_DIR := RevereRobot2014_partialImage/$(MODE_DIR)

RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/2014AutonModeTickerTask.o : $(PRJ_ROOT_DIR)/2014AutonModeTickerTask.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/DebugTickerTask.o : $(PRJ_ROOT_DIR)/DebugTickerTask.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/DriveSystem.o : $(PRJ_ROOT_DIR)/DriveSystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/Logger.o : $(PRJ_ROOT_DIR)/Logger.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/MyRobot.o : $(PRJ_ROOT_DIR)/MyRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/RobotInput.o : $(PRJ_ROOT_DIR)/RobotInput.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/RobotMaster.o : $(PRJ_ROOT_DIR)/RobotMaster.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/RobotUtils.o : $(PRJ_ROOT_DIR)/RobotUtils.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/Ticker.o : $(PRJ_ROOT_DIR)/Ticker.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/WinchTickerTask.o : $(PRJ_ROOT_DIR)/WinchTickerTask.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_RevereRobot2014_partialImage = RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/2014AutonModeTickerTask.o \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/DebugTickerTask.o \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/DriveSystem.o \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/Logger.o \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/MyRobot.o \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/RobotInput.o \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/RobotMaster.o \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/RobotUtils.o \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/Ticker.o \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/WinchTickerTask.o

RevereRobot2014_partialImage/$(MODE_DIR)/RevereRobot2014_partialImage.o : $(OBJECTS_RevereRobot2014_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_RevereRobot2014_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

RevereRobot2014_partialImage/$(MODE_DIR)/RevereRobot2014_partialImage_compile_file : $(FILE) ;

_clean :: RevereRobot2014_partialImage/$(MODE_DIR)/RevereRobot2014_partialImage_clean

RevereRobot2014_partialImage/$(MODE_DIR)/RevereRobot2014_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "RevereRobot2014_partialImage" ]; then cd "RevereRobot2014_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/2014AutonModeTickerTask.d RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/DebugTickerTask.d RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/DriveSystem.d \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/Logger.d RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/MyRobot.d RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/RobotInput.d \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/RobotMaster.d RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/RobotUtils.d RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/Ticker.d \
	 RevereRobot2014_partialImage/$(MODE_DIR)/Objects/RevereRobot2014/WinchTickerTask.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
