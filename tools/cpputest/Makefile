CXX = arm-none-eabi-g++

ROOT_PATH = $(CURDIR)/../..
CPPUTEST_PATH = $(ROOT_PATH)/third_party/cpputest
CPPUTEST_OBJS_PATH = $(CURDIR)/obj

UTEST_SRC = $(wildcard $(CPPUTEST_PATH)/src/CppUTest/*.cpp)
UTESTEXT_SRC = $(wildcard $(CPPUTEST_PATH)/src/CppUTestExt/*.cpp)
PLATFORM_SRC = $(wildcard $(CPPUTEST_PATH)/src/Platforms/armcc/*.cpp)

UTEST_OBJS_NAME = $(patsubst %.cpp, %.o, $(notdir $(UTEST_SRC) $(UTESTEXT_SRC) $(PLATFORM_SRC)))
UTEST_OBJS = $(addprefix $(CPPUTEST_OBJS_PATH)/, $(UTEST_OBJS_NAME))

MACHINE = -mthumb -mcpu=cortex-m4
CXX_FLAGS = -c -g3 $(MACHINE) -O0

INC = -I$(CPPUTEST_PATH)/include/

.SILENT: $(UTEST_OBJS) all clean

$(UTEST_OBJS): $(UTEST_SRC) $(UTESTEXT_SRC) $(PLATFORM_SRC)
	@echo start to compiling cpputest sources...
	$(CXX) $(CXX_FLAGS) $(INC) $^
	@echo done
	mkdir -p obj
	@echo moving objects to $(CPPUTEST_OBJS_PATH)...
	mv $(UTEST_OBJS_NAME) obj 
	@echo done

all: $(UTEST_OBJS)

clean:
	rm -rf obj *.o