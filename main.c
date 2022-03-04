#include "stream.h"
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

int main() {
	struct stream *st = new_stream();

	/* Create iterator which is invalid before addition of any region */
	struct stream_region_iterator *it = stream_region_iterator_new(st);
	assert(stream_region_iterator_is_valid(it) == -1 );

	for (size_t i =0; i< 10 ;i++){
		stream_region_allocate(st);
	}

	size_t regions_counter = 0;
	for(stream_region_iterator_seek_first(it); stream_region_iterator_is_valid(it) == 0; stream_region_iterator_next(it)){
		regions_counter++;
	}
	printf("counted regions: %ld\n", regions_counter);

	regions_counter = 0;
	struct stream_region_iterator *it2 = stream_region_iterator_new(st);

	stream_region_iterator_seek_first(it2);
	while(stream_region_iterator_is_valid(it) == 0){
		regions_counter++;
		stream_region_iterator_next(it);
	}

	stream_region_allocate(st);
	stream_region_allocate(st);

	while(stream_region_iterator_is_valid(it) == 0){
		regions_counter++;
		stream_region_iterator_next(it);
	}

	printf("counted regions: %ld\n", regions_counter);
	stream_region_iterator_delete(it);
	stream_region_iterator_delete(it2);
	stream_delete(st);
}
