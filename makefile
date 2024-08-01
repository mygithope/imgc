cc=clang
dist=bin
src=./src/*.c
JSON=dmp.o.json
GTK_CFLAGS=`pkg-config --cflags gtk+-3.0`
GTK_LIBS=`pkg-config --libs gtk+-3.0`
build: $(src)
	@echo "compiling "$(src)" to "$(dist)""
	@$(cc) -o $(dist) $(src) -Iinclude $(GTK_CFLAGS) $(GTK_LIBS)
run:$(dist)
	@./$(dist)
commands:
	@$(cc) -MJ $(JSON) -o $(dist) $(src) -Iinclude $(GTK_CFLAGS) $(GTK_LIBS)
	@sed -e '1i [' -e '1a ]' $(JSON) > compile_commands.json && rm $(JSON)
clean:
	@rm $(dist)
