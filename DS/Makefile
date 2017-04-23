
# all targets to run
program_SINGLY := singly
program_SINGLY_INT := singly.int
program_DOUBLY := doubly
program_DOUBLY_INT := doubly.int
program_STACK := stack
program_STACK_INT := stack.int
program_TRY_LIST := trylist
program_TRY_SECOND := trysecond
program_ALL := $(program_SINGLY) $(program_SINGLY_INT) $(program_DOUBLY) $(program_DOUBLY_INT) $(program_STACK) $(program_STACK_INT) $(program_TRY_LIST) $(program_TRY_SECOND)

# c source directories
source_IMPL_DIR := ./impl
source_ADAPTER_DIR := ./adapter
source_DIR := $(source_IMPL_DIR) $(source_ADAPTER_DIR)

# individual source files
source_SINGLY = $(source_IMPL_DIR)/$(program_SINGLY).c
source_SINGLY_INT = $(source_ADAPTER_DIR)/$(program_SINGLY_INT).c
source_DOUBLY = $(source_IMPL_DIR)/$(program_DOUBLY).c
source_DOUBLY_INT = $(source_ADAPTER_DIR)/$(program_DOUBLY_INT).c
source_STACK = $(source_IMPL_DIR)/$(program_STACK).c
source_STACK_INT = $(source_ADAPTER_DIR)/$(program_STACK_INT).c
source_TRY_LIST = $(program_TRY_LIST).c
source_TRY_SECOND = $(program_TRY_SECOND).c

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
object_DOUBLY_INT = $(program_DOUBLY_INT).o
object_STACK = $(program_STACK).o
object_STACK_INT = $(program_STACK_INT).o
object_TRY_LIST = $(program_TRY_LIST).o
object_TRY_SECOND = $(program_TRY_SECOND).o

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
	$(COMPILE.c) $(source_SINGLY) -o $(source_IMPL_DIR)/$(object_SINGLY)

$(object_SINGLY_INT): $(object_SINGLY)
	$(COMPILE.c) $(source_SINGLY_INT) -o $(source_ADAPTER_DIR)/$(object_SINGLY_INT)

$(object_DOUBLY):
	$(COMPILE.c) $(source_DOUBLY) -o $(source_IMPL_DIR)/$(object_DOUBLY)

$(object_DOUBLY_INT): $(object_DOUBLY)
	$(COMPILE.c) $(source_DOUBLY_INT) -o $(source_ADAPTER_DIR)/$(object_DOUBLY_INT)

$(object_STACK):
	$(COMPILE.c) $(source_STACK) -o $(source_IMPL_DIR)/$(object_STACK)

$(object_STACK_INT): $(object_SINGLY) $(object_STACK)
	$(COMPILE.c) $(source_STACK_INT) -o $(source_ADAPTER_DIR)/$(object_STACK_INT)

$(program_SINGLY): $(object_SINGLY)

$(program_DOUBLY): $(object_DOUBLY)

$(program_TRY_LIST): $(run).$(type).o $(object_TRY_LIST)
	$(LINK.c) $(object_TRY_LIST) $(source_ADAPTER_DIR)/$(run).$(type).o $(source_IMPL_DIR)/$(run).o -o $(program_TRY_LIST)

$(program_TRY_SECOND): $(run).$(type).o $(object_SINGLY_INT) $(object_TRY_SECOND)
	$(LINK.c) $(object_TRY_SECOND) $(source_ADAPTER_DIR)/$(run).$(type).o $(source_IMPL_DIR)/$(run).o $(source_IMPL_DIR)/$(object_SINGLY) $(source_ADAPTER_DIR)/$(object_SINGLY_INT) -o $(program_TRY_SECOND)

clean:
	@- $(RM) $(program_ALL)
	@- $(RM) $(program_OBJS)
	@- $(RM) ./*.o

distclean: clean

show:
	@- echo $(program_C_SRCS)