
# all targets to run
program_SINGLY := singly
program_DOUBLY := doubly
program_TRY_ONE := try1
program_ALL := $(program_SINGLY) $(program_DOUBLY) $(program_TRY_ONE)

# all c source files
program_C_SRCS := $(wildcard *.c)

# names all .o files, deriving from .c file names
program_C_OBJS := $(program_C_SRCS:.c=.o)

# names of all programs objectfiles
program_OBJS := $(program_C_OBJS)

# individual object files
object_SINGLY = singly.o
object_DOUBLY = doubly.o
object_TRY_ONE = try1.o

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

$(program_SINGLY): $(object_SINGLY)

$(program_DOUBLY): $(object_DOUBLY)

$(program_TRY_ONE): $(run) $(object_TRY_ONE)
	$(LINK.cc) $(object_TRY_ONE) $(run).o -o $(program_TRY_ONE)

clean:
	@- $(RM) $(program_ALL)
	@- $(RM) $(program_OBJS)

distclean: clean