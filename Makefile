CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -pedantic

SRCS =
OBJS = $(SRCS:.c=.o)

TEST_SRCS =
TEST_OBJS = $(TEST_SRCS:.c=.o)

LIB =
TESTSUITE =

all: $(LIB)

check: $(TESTSUITE)
	@./$(TESTSUITE)

$(TESTSUITE): LDLIBS += -lcriterion
$(TESTSUITE): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

test: CFLAGS += -fsanitize=address -g
test: LDFLAGS = -fsanitize=address
test: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) -so $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(LIB)
