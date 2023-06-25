#!/bin/bash

for file in *; do
	if [[ -f $file ]]; then
		echo "Title: $file"
		echo "Content:"
		cat "$file"
		echo "------------------------"
	fi
done

