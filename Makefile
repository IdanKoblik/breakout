CC = gcc
CFLAGS = -Wall -Wextra -g
LIBS = -lraylib -lm

SRCDIR = .
OBJDIR = obj
BINDIR = .

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

EXEC = breakout

all: $(OBJDIR) $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(BINDIR)/$@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(EXEC)