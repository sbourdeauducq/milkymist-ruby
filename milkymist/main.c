/**********************************************************************

  main.c -

  $Author: akr $
  created at: Fri Aug 19 13:19:58 JST 1994

  Copyright (C) 1993-2007 Yukihiro Matsumoto

**********************************************************************/

#undef RUBY_EXPORT
#include "ruby.h"
#include "debug.h"
#ifdef HAVE_LOCALE_H
#include <locale.h>
#endif
#include <bsp.h>

RUBY_GLOBAL_SETUP

int
main(int argc, char **argv)
{
#ifdef RUBY_DEBUG_ENV
    ruby_set_debug_option(getenv("RUBY_DEBUG"));
#endif
#ifdef HAVE_LOCALE_H
    setlocale(LC_CTYPE, "");
#endif

printf("main starting\n");
    ruby_sysinit(&argc, &argv);
    {
	RUBY_INIT_STACK;
	ruby_init();
	return ruby_run_node(ruby_options(argc, argv));
    }
}

char *example[] = {"ruby"};
rtems_task Init(rtems_task_argument argument)
{
	main(0, example);
}

#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_EXECUTIVE_RAM_SIZE (16*1024*1024)

#define CONFIGURE_LIBIO_MAXIMUM_FILE_DESCRIPTORS 16
#define CONFIGURE_MAXIMUM_TASKS 2
#define CONFIGURE_MAXIMUM_POSIX_THREADS 32
#define CONFIGURE_MAXIMUM_POSIX_MUTEXES 32
#define CONFIGURE_MAXIMUM_POSIX_MUTEXES 32
#define CONFIGURE_MAXIMUM_POSIX_CONDITION_VARIABLES  32
#define CONFIGURE_MAXIMUM_POSIX_KEYS 32

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_INIT_TASK_STACK_SIZE (512*1024)
#define CONFIGURE_INIT_TASK_PRIORITY 120
#define CONFIGURE_INIT_TASK_ATTRIBUTES RTEMS_FLOATING_POINT
#define CONFIGURE_INIT_TASK_INITIAL_MODES \
	(RTEMS_PREEMPT | RTEMS_NO_TIMESLICE | RTEMS_NO_ASR | \
	RTEMS_INTERRUPT_LEVEL(0))

//#define CONFIGURE_ZERO_WORKSPACE_AUTOMATICALLY TRUE
#define CONFIGURE_STACK_CHECKER_ENABLED

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
