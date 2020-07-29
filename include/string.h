#ifndef INCLUDE_STRING_H__
#define INCLUDE_STRING_H__

static inline void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len)
{
	while(len--)
		*dest++ = *src++;
}

static inline void memset(void *dest, uint8_t val, uint32_t len)
{
	while(len--)
		*(uint8_t)dest++ = val;
}

static inline void bzero(void *dest, uint32_t len)
{
	memset(dest, 0, len);
}

static inline int strcmp()
{

	return 0;
}

static inline char *strcpy(char *dest, const char *src)
{
	char *tmp = dest;
	
	while(*src)
			*dest++ = *src++;

	*dest = '\0';

	return tmp;
}

static inline char *strcat()
{

	return NULL;
}

static inline int strlen(const char *src)
{
	const char *eos = src;

	while(*eos++)
		;

	return (eos - src + 1);
}
#endif