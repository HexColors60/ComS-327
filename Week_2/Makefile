all: clean save_load run

save_load: save_load.c 
	gcc -Wall save_load.c -o save_load -ggdb

clean:
	rm -rf save_load test.bin

run: 
	./save_load w ; echo
	hexdump -C test.bin ; echo ; echo
	./save_load r ; echo

# CC = gcc
# CXX = g++
# ECHO = echo
# RM = rm -f

# CFLAGS = -Wall -Werror -ggdb -funroll-loops -pg
# CXXFLAGS = -Wall -Werror -ggdb -funroll-loops                                           
# LDFLAGS = 

# BIN = rlg327
# OBJS = rlg327.o heap.o

# all: $(BIN) etags

# $(BIN): $(OBJS)
# 	@$(ECHO) Linking $@
# 	@$(CC) $^ -o $@ $(LDFLAGS)

# -include $(OBJS:.o=.d)

# %.o: %.c
# 	@$(ECHO) Compiling $<
# 	@$(CC) $(CFLAGS) -MMD -MF $*.d -c $<

# %.o: %.cpp
# 	@$(ECHO) Compiling $<
# 	@$(CXX) $(CXXFLAGS) -MMD -MF $*.d -c $<

# .PHONY: all clean clobber etags

# clean:
# 	@$(ECHO) Removing all generated files
# 	@$(RM) *.o $(BIN) *.d TAGS core vgcore.* gmon.out

# clobber: clean
# 	@$(ECHO) Removing backup files
# 	@$(RM) *~ \#* *pgm

# etags:
# 	@$(ECHO) Updating TAGS
# 	@etags *.[ch]
