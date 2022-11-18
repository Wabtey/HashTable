#
# Link
#

CFLAGS = -Wall -g

bin/main.c: obj/hash.o obj/file.o obj/main.o

	gcc $(CFLAGS) -o main obj/file.o obj/hash.o obj/main.o



#
# Objets of TP hash tables
#

#hash
obj/hash.o: src/hash.c include/functions.h

	mkdir -p obj
	gcc $(CFLAGS) -c src/hash.c -I./include -o obj/hash.o

#file
obj/file.o: src/file.c include/functions.h include/types.h

	gcc $(CFLAGS) -c src/file.c -I./include -o obj/file.o

#main
obj/main.o: src/main.c include/functions.h include/types.h

	gcc $(CFLAGS) -c src/main.c -I./include -o obj/main.o





#
# Listing creation in pdf
#

listing:
	a2ps -o listing.ps include/functions.h include/types.h src/file.c src/hash.c src/main.c
	ps2pdf listing.ps
	rm listing.ps





#
# Remove files
#

clean :
	rm obj/*.o main







#
# Test the functionality
#

test :
