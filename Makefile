CC       = gcc
# --------------------------------------------------
# Flag sets
CFLAGS_RELEASE = -std=c17 -Wall -Wextra -O2
CFLAGS_DEBUG   = -std=c17 -Wall -Wextra -O0 -g
# --------------------------------------------------
TARGET   = hash
SRC      = hash_table.c main.c

# ---------- default (release) build ---------------
CFLAGS   ?= $(CFLAGS_RELEASE)      # pick release flags unless caller overrides

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# ---------- debug build ---------------------------
.PHONY: debug
debug: CFLAGS=$(CFLAGS_DEBUG)      # temporarily substitute flags
debug: clean $(TARGET)             # force a clean rebuild

# ---------- utility targets -----------------------
.PHONY: clean

clean:
	rm -f $(TARGET)
