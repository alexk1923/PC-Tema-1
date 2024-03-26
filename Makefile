build: ninel vectsecv codeinvim nomogram
all: ninel vectsecv codeinvim nomogram

ninel:ninel.c
	gcc -Wall -Wextra ninel.c -o ninel
	
vectsecv:vectsecv.c
	
	gcc -Wall -Wextra vectsecv.c -o vectsecv
	
codeinvim:codeinvim.c
	gcc -Wall -Wextra codeinvim.c -o codeinvim
	
nomogram:nomogram.c
	gcc -Wall -Wextra nomogram.c -o nomogram

clean:
	rm -rf all
