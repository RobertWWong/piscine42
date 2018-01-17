n=0;
m=0;
max=23;
while [ "$max" -gt 0 ]; do
  mkdir "ex$n$m"
  m=`expr "$m" + 1`;
  if [ "$m" -eq 9 ]
  then
	n=`expr "$n" + 1`;
	m=`expr "$m" = 0`;
   fi
   max=`expr "$max" - 1`;
done
