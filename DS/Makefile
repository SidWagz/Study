
# all targets to run
program_SINGLY := singly
program_SINGLY_INT := singly.int
program_DOUBLY := doubly
program_TRY_LIST := trylist
program_ALL := $(program_SINGLY) $(program_DOUBLY) $(program_TRY_LIST)

# c source directories
source_IMPL_DIR := ./impl
source_ADAPTER_DIR := ./adapter
source_DIR := $(source_IMPL_DIR) $(source_ADAPTER_DIR)

# individual source files
source_SINGLY = $(source_IMPL_DIR)/$(program_SINGLY).c
source_SINGLY_INT = $(source_ADAPTER_DIR)/$(program_SINGLY_INT).c
source_DOUBLY = $(source_IMPL_DIR)/$(program_DOUBLY).c
source_TRY_LIST = $(program_TRY_LIST).c

# all c source files
program_C_SRCS := $(wildcard *.c)
program_C_SRCS += $(foreach sourcedir, $(source_DIR), $(wildcard $(sourcedir)/*.c))

# names all .o files, deriving from .c file names
program_C_OBJS := $(program_C_SRCS:.c=.o)

# names of all programs objectfiles
program_OBJS := $(program_C_OBJS)

# individual object files
object_SINGLY = $(program_SINGLY).o
object_SINGLY_INT = $(program_SINGLY_INT).o
object_DOUBLY = $(program_DOUBLY).o
object_TRY_LIST = $(program_TRY_LIST).o

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
	$(COMPILE.c) $(source_SINGLY) -o $(source_IMPL_DIR)//$(object_SINGLY)

$(object_SINGLY_INT): $(object_SINGLY)
	$(COMPILE.c) $(source_SINGLY_INT) -o $(source_ADAPTER_DIR)/$(object_SINGLY_INT)

$(program_SINGLY): $(object_SINGLY)

$(program_DOUBLY): $(object_DOUBLY)

$(program_TRY_LIST): $(run).$(type).o $(object_TRY_LIST)
	$(LINK.c) $(object_TRY_LIST) $(source_ADAPTER_DIR)/$(run).$(type).o $(source_IMPL_DIR)/$(run).o -o $(program_TRY_LIST)

clean:
	@- $(RM) $(program_ALL)
	@- $(RM) $(program_OBJS)
	@- $(RM) ./*.o

distclean: clean

show:
	@- echo $(program_C_SRCS)