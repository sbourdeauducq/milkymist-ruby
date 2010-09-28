CC=lm32-rtems4.11-gcc
LD=lm32-rtems4.11-gcc
AR=lm32-rtems4.11-ar
STRIP=lm32-rtems4.11-strip
OBJCOPY=lm32-rtems4.11-objcopy

CFLAGS=-mbarrel-shift-enabled -mmultiply-enabled -mdivide-enabled -msign-extend-enabled -O3 -g -Wextra -Wno-unused-parameter -Wno-parentheses -Wpointer-arith -Wwrite-strings -Wno-missing-field-initializers -Wno-long-long -I. -I.. -I../include -DRUBY_EXPORT

COMMONOBJS =    array.o \
		bignum.o \
		class.o \
		compar.o \
		complex.o \
		dir.o \
		dln_find.o \
		enum.o \
		enumerator.o \
		error.o \
		encoding.o \
		eval.o \
		dln.o \
		load.o \
		proc.o \
		file.o \
		gc.o \
		hash.o \
		inits.o \
		io.o \
		marshal.o \
		math.o \
		node.o \
		numeric.o \
		object.o \
		pack.o \
		parse.o \
		process.o \
		random.o \
		range.o \
		rational.o \
		re.o \
		regcomp.o \
		regenc.o \
		regerror.o \
		regexec.o \
		regparse.o \
		regsyntax.o \
		ruby.o \
		safe.o \
		signal.o \
		sprintf.o \
		st.o \
		strftime.o \
		string.o \
		struct.o \
		time.o \
		transcode.o \
		util.o \
		variable.o \
		compile.o \
		debug.o \
		iseq.o \
		vm.o \
		vm_dump.o \
		thread.o \
		cont.o \
		crypt.o \
		flock.o \
		version.o

MINIRUBYOBJS = main.o dmyext.o miniprelude.o newline.o

all: miniruby miniruby.bin

%.o: ../%.c
	$(CC) $(CFLAGS) -c -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

crypt.o: ../missing/crypt.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
flock.o: ../missing/flock.c
	$(CC) $(CFLAGS) -c -o $@ $<

libruby-static.a: $(COMMONOBJS)
	$(AR) cru $@ $(COMMONOBJS)

miniruby: libruby-static.a $(MINIRUBYOBJS)
	$(LD) $(LDFLAGS) -o $@ $(MINIRUBYOBJS) -L. -lruby-static -lm -B$(RTEMS_MAKEFILE_PATH)/lib -specs bsp_specs -qrtems

%.bin: %
	$(OBJCOPY) -O binary $< $@

load: miniruby.bin
	flterm --port /dev/ttyUSB0 --kernel $<

clean:
	rm -f $(COMMONOBJS) $(MINIRUBYOBJS) miniruby libruby-static.a main.o

.PHONY: clean load
