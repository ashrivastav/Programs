for($i=0;$i<10;$i++){$string[$i]=<STDIN>;}for($i=0; $i<10; $i++){$count=$string[$i]=~tr/[T,D,L,F]/[K,G,R,R]/;print 2**$count, "\n";}
