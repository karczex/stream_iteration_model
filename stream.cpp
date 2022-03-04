#include "stream.h"
#include <string>
#include <iostream>
#include <vector>

class stream {
	using entry = std::string;
	using region = std::vector<entry>;
	using container = std::vector<region>;
public:
	void print(std::string message);

	container data;

};

void stream::print(std::string message){
		std::cout << message  << std::endl;
}

extern "C" {

struct stream *new_stream() {
	return new stream();
}

void stream_delete(struct stream *stream_instance){
	delete stream_instance;
}
void stream_region_allocate(struct stream *stream_instance) {
	stream_instance->data.emplace_back();
}

void stream_print(struct stream *stream_instance, const char *name) {
	stream_instance->print(name);
}

struct stream_region_iterator *stream_region_iterator_new(struct stream *st){
	auto *it = new stream_region_iterator();
	it->st = st;
	it->pos = INVALID_REGION;
	return it;
}


void stream_region_iterator_delete(struct stream_region_iterator *it){
	delete it;
}

void stream_region_iterator_seek_first(struct stream_region_iterator *it){
	if(it->st->data.size() > 0){
		it->pos = 0;
	}
}

void stream_region_iterator_next(struct stream_region_iterator *it){
	/* points to element which would be allocated next, so it's possible to
	 * continue iteration after region allocation */
	if (it->pos != INVALID_REGION){
		it->pos++;
	}
}

int stream_region_iterator_is_valid(struct stream_region_iterator *it){
	auto current_position = it->pos;
	try{
		it->st->data.at(current_position);
	}catch(std::out_of_range){
		return -1;
	}
	return 0;
}

}


