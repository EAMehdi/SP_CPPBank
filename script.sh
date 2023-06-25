#!/bin/bash

# Clean output file if it exists
if [[ -f output.txt ]]; then
	rm output.txt
fi

for file in *; do
	if [[ -f $file ]]; then
		echo "Title: $file" >> output.txt
		echo "Content:" >> output.txt
		cat "$file" >> output.txt
		echo "------------------------" >> output.txt
	fi
done

