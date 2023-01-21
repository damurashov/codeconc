// Replace multispaces w/ a single space;

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void string_compress_whitespaces(char *string)
{
	char *it_insert = string;
	char *it_fetch = string;
	const char whitespace = ' ';
	const char eos = '\0';
	int n_whitespaces = 0;
	assert(string != NULL);
	it_insert = it_fetch;

	for (; *it_fetch != eos; ++it_fetch) {
		*it_insert = *it_fetch;

		if (*it_fetch == whitespace) {
			++n_whitespaces;

			if (n_whitespaces < 2) {
				++it_insert;
			}
		} else {
			n_whitespaces = 0;
			++it_insert;
		}

	}

	*it_insert = eos;
}

char *malloc_string(const char *string)
{
	char *allocated = calloc(strlen(string) + 1, 1);
	assert(allocated != NULL);
	strcpy(allocated, string);

	return allocated;
}

int main()
{
	char *whitespaced_strings[] = {
		malloc_string("some string"),
		malloc_string("some  string"),
		malloc_string("some    string    "),
		malloc_string("  some string"),
		malloc_string("    some   string    "),
		malloc_string("   some  string "),
	};
	const int n_whitespaced_strings = sizeof(whitespaced_strings) / sizeof(whitespaced_strings[0]);

	for (int i = 0; i < n_whitespaced_strings; ++i) {
		string_compress_whitespaces(whitespaced_strings[i]);
		printf("\"%s\"\n", whitespaced_strings[i]);
		free(whitespaced_strings[i]);
	}
}
