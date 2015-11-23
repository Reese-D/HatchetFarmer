for i in $( ls );
do
  cat $i | grep 'TODO'
  echo $i
done
