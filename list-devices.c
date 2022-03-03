#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <alloca.h>

#include <alsa/asoundlib.h>

int main()
{
	void **hints;
	/* Find names associated with PCM devices */
	int err = snd_device_name_hint(-1, "pcm", (void ***)&hints);

	if (err < 0) {
		return -1;
	}

	char **n = (char **)hints;
	while (*n != NULL) {
		/* Get there actual name */
		char *name = snd_device_name_get_hint(*n, "NAME");
		if (name != NULL) {
			printf("%s\n", name);
			free(name);
		}
		n++;
	}
	snd_device_name_free_hint(hints);
}
