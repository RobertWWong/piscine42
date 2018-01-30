#!/bin/sh
find . -name "*.sh" | sed 's/.\///g' | rev |cut -c 4- | rev
