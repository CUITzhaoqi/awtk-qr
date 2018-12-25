#!/usr/bin/awk -f

# Problem one: wrong useage of the getline function
# Problem two: What is the argc and argv really representing?

BEGIN {
 	 if (ARGC != 4) {
    	   printf("Usage: caculate.sh filename screen_length screen_width\n")
     	   exit
     }

     while (getline < ARGV[1] > 0) {
     	if ($0 ~ /^$/) {
     		continue
     	}
     	printf("%d = %.2f%%, %d = %.2f%%\n", $1, $1 * 100 / ARGV[2], $2, $2 * 100 / ARGV[3]);
     }

     exit 
}
