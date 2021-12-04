#include <stdio.h>
#include <wayland-server.h>

struct my_state {
	int data;
};

static void
wl_output_handle_bind(struct wl_client *client, void *data,
				uint32_t version, uint32_t id)
{
	struct my_state *state = data;
	// TODO
}


int
main(int argc, char *argv[])
{
	struct my_state state;
	state.data = 10;

	struct wl_display *display = wl_display_create();
	if (!display) {
		fprintf(stderr, "Unable to create Wayland display.\n");
		return 1;
	}
	const char *socket = wl_display_add_socket_auto(display);
	if (!socket) {
		fprintf(stderr, "Unable to add socket to Wayland display.\n");
		return 1;
	}
	fprintf(stderr, "Running Wayland display on %s\n", socket);

	//ljlj create global
	wl_global_create(display, &wl_output_interface,
					2, &state, wl_output_handle_bind);



	wl_display_run(display);
	wl_display_destroy(display);
	return 0;
}
