cc=clang
dist=a.out
src=main.c
JSON=dmp.o.json
CFLAGS=`sdl2-config --cflags --libs`
build: $(src)
	@echo "compiling "$(src)" to "$(dist)""
	@$(cc) -o $(dist) $(src) $(CFLAGS)
run:a.out
	@clear && ./a.out
commands:
	@$(cc) -MJ $(JSON) -o $(dist) $(src) $(CFLAGS)
	@sed -e '1i [' -e '1a ]' $(JSON) > compile_commands.json && rm $(JSON)
clean:
	@rm $(dist)
