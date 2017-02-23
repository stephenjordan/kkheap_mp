#-----------------------------------------------------------------#
# This software implements the Karmarkar-Karp algorithm for the   #
# number partitioning problem. It was written by Stephen Jordan   #
# in 2017 as part of a collaboration with Brad Lackey and         #
# Ning Bao.                                                       #
#-----------------------------------------------------------------#

CC=g++

all: kkheap_mp

kkheap_mp: kkheap_mp.cpp
	$(CC) -std=c++11 kkheap_mp.cpp -lgmpxx -lgmp -o kkheap_mp

clean:
	rm -f kkheap_mp *~
