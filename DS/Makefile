
# all targets to run
program_SINGLY := singly
program_DOUBLY := doubly
program_TRY_LIST := trylist
program_ALL := $(program_SINGLY) $(program_DOUBLY) $(program_TRY_LIST)

# c source directories
source_IMPL_DIR := ./impl
source_ADAPTER_DIR := ./adapter
source_DIR := $(source_IMPL_DIR) $(source_ADAPTER_DIR)

# all c source files
program_C_SRCS := $(wildcard *.c)
program_C_SRCS += $(foreach sourcedir, $(source_DIR), $(wildcard $(sourcedir)/*.c))

# names all .o files, deriving from .c file names
program_C_OBJS := $(program_C_SRCS:.c=.o)

# names of all programs objectfiles
program_OBJS := $(program_C_OBJS)

# individual object files
object_SINGLY = singly.o
object_DOUBLY = doubly.o
object_TRY_LIST = trylist.o

## include header files for different runs

header_DIR := ./include

# include all header dirs
program_INCLUDE_DIRS := $(header_DIR)

# link all library dirs
program_LIBRARY_DIRS := 

# link individual dirs
program_LIBRARIES := 

# CPPFLAGS
CFLAGS += $(foreach includedir, $(program_INCLUDE_DIRS), -I$(includedir))

# LDFLAGS
LDFLAGS += $(foreach librarydir, $(program_LIBRARY_DIRS), -L$(librarydir))

# CPPFLAGS
LDFLAGS += $(foreach library, $(program_LIBRARIES), -l$(library))

.PHONY: all clean distclean $(program_ALL)

$(object_SINGLY):
	$(COMPILE.c) $(source_DIR)/$(program_SINGLY).c

$(program_SINGLY): $(program_SINGLY).o

$(program_DOUBLY): $(program_SINGLY).o

$(program_TRY_LIST): $(run) $(object_TRY_LIST)
	$(LINK.c) $(object_TRY_LIST) $(run).o -o $(program_TRY_LIST)

clean:
	@- $(RM) $(program_ALL)
	@- $(RM) $(program_OBJS)

distclean: clean

show:
	@- echo $(program_C_SRCS)