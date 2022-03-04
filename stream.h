#ifndef Cstream_H
#define Cstream_H
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct stream;

#define INVALID_REGION SIZE_MAX

struct stream_region_iterator{
	struct stream *st;
	size_t pos;
};

struct stream* new_stream();
void stream_print(struct stream *instance, const char *name);
void stream_delete(struct stream *stream_instance);
void stream_region_allocate(struct stream *stream_instance);

struct stream_region_iterator *stream_region_iterator_new(struct stream *st);
void stream_region_iterator_delete(struct stream_region_iterator *it);

void stream_region_iterator_next(struct stream_region_iterator *it);

int stream_region_iterator_is_valid(struct stream_region_iterator *it);

void stream_region_iterator_seek_first(struct stream_region_iterator *it);

#ifdef __cplusplus
}
#endif
#endif


