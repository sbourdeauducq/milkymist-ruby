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
		eval.o \
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
		cont.o

all: libruby-static.a

%.o: ../%.c
	$(CC) $(CFLAGS) -c -o $@ $<

libruby-static.a: $(COMMONOBJS)
	$(AR) cru libruby-static.a $(COMMONOBJS)

clean:
	rm -f $(COMMONOBJS)

.PHONY: clean
