cc=clang
dist=a.out
src=./src/*.c
JSON=dmp.o.json
CFLAGS=`sdl2-config --cflags --libs`
build: $(src)
	@echo "compiling "$(src)" to "$(dist)""
	@$(cc) -o $(dist) $(src) $(CFLAGS) -Iinclude
run:a.out
	@clear && ./$(dist)
commands:
	@$(cc) -MJ $(JSON) -o $(dist) $(src) $(CFLAGS) -Iinclude
	@sed -e '1i [' -e '1a ]' $(JSON) > compile_commands.json && rm $(JSON)
clean:
	@rm $(dist)
