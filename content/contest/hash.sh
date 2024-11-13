# This is heavily modified from the original version

#!/bin/bash
# Create a temporary file with a unique name
TMPFILE=$(mktemp)

# Read the input file and process it
cat $1 | tr -d '\r' | tr '\n' '|' > "$TMPFILE"

# First hash
cat "$TMPFILE" | md5sum | cut -c-6

# Second hash with preprocessing
g++-14 -E -P -fpreprocessed -x c++ "$TMPFILE" | md5sum | cut -c-6

# Clean up
rm "$TMPFILE"