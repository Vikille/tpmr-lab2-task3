CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11
TARGET = bin/program
OBJDIR = obj
SRCDIR = src

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

$(TARGET): $(OBJECTS) | bin
	$(CC) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) bin:
	mkdir -p $@

.PHONY: clean run

clean:
	rm -rf $(OBJDIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)
