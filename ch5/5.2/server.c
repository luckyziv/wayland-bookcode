#include <stdio.h>
#include <wayland-server.h>

struct my_state {
	int data;
};

#if 0
static void
wl_output_handle_resource_destroy(struct wl_resource *resource)
{
    struct my_output *client_output = wl_resource_get_user_data(resource);

    // TODO: Clean up resource

    remove_to_list(client_output->state->client_outputs, client_output);
}

static void
wl_output_handle_release(struct wl_client *client, struct wl_resource *resource)
{
    wl_resource_destroy(resource);
}

static const struct wl_output_interface
wl_output_implementation = {
    .release = wl_output_handle_release,
};
#endif

static void
wl_output_handle_bind(struct wl_client *client, void *data,
				uint32_t version, uint32_t id)
{
	struct my_state *state = data;
	// TODO

#if 0
    struct my_output *client_output = calloc(1, sizeof(struct client_output));

    struct wl_resource *resource = wl_resource_create(
        client, &wl_output_implementation, wl_output_interface.version, id);

    wl_resource_set_implementation(resource, wl_output_implementation,
        client_output, wl_output_handle_resource_destroy);

    client_output->resource = resource;
    client_output->state = state;

    wl_output_send_geometry(resource, 0, 0, 1920, 1080,
        WL_OUTPUT_SUBPIXEL_UNKNOWN, "Foobar, Inc",
        "Fancy Monitor 9001 4K HD 120 FPS Noscope",
        WL_OUTPUT_TRANSFORM_NORMAL);

    add_to_list(state->client_outputs, client_output);
#endif
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

	//ljlj create a global
	wl_global_create(display, &wl_output_interface,
					2, &state, wl_output_handle_bind);



	wl_display_run(display);
	wl_display_destroy(display);
	return 0;
}
