#include <stdio.h>
struct ele {
	char *data;
};

struct ring_buf {
	int size;
	int start;
	int count;
	struct buffer *ele;
};

struc ring_buf main_buf;
int buf_size;

void ring_init(struct ring_buf *buf, int size)
{
	buf->size = size;
	buf->start = 0;
	buf->count = 0;
	ele = (struct ele *)malloc(sizeof(struct ele), size);
}

int ring_full(struct ring_buf *buf)
{
	if(buf->count == buf->size)
		return 1;
	else 
		return 0;
		
}

int ring_empty(struct ring_buf *buf)
{
	if(!buf->count)
		return 1;
	else 
		return 0;	
}

void add_to_ring(struct ring_buf *buf, char *data)
{
	if(!ring_full(buf)) {
	
	}
		
}

int main (void) 
{
	int i;
	char temp_buf[BUFSIZ];

	buf_size = 10;
	ring_init(&main_buf, buf_size);

	for(i = 0; i < size; i++) {
		memset(temp_buf, 0, BUFSIZ);
		sprintf(temp_buf, "string%d",i)
		add_to_ring(&main_buf, temp_buf);
	}
	return 0;

}
