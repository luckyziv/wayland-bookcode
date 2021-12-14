WAYLAND = -lwayland-client
CFLAGS = -lrt
FF = client.c xdg-shell-protocol.c
CC = gcc

client: $(FF)
	$(CC) -o client $(FF) $(WAYLAND) $(CFLAGS)

.PHONY: clean
clean:
	$(RM) *.o client
