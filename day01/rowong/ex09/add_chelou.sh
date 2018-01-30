#!/bin/sh
echo $FT_NBR1 + $FT_NBR2 | tr "'\"\?\!\\" "02341" | tr "mrdoc" "01234" | xargs echo "obase=13; ibase=5;" | bc | tr "0123456789ABC" "gtaio luSnemf"
#obase = output base, i = etc.  xargs allows us t convert previous stream buffer into mathematical operations
#We also cannot do "' \\ \" ... etc  for the FT_NBR1, due to special character adjacency. At least I didn't know how to. 