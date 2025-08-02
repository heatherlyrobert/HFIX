



char
HFIX_unit_quiet    (void)
{
   char        x_argc = 1;
   char       *x_args [1]  = { "HFIX" };
   PROG_debugging (x_argc, x_args);
   PROG_startup   (x_argc, x_args);
   return 0;
}

char
HFIX_unit_loud     (void)
{
   char        x_argc = 4;
   char       *x_args [4]  = { "HFIX_unit","@@kitchen", "@@prog" , "@@hfix"};
   PROG_debugging (x_argc, x_args);
   PROG_startup   (x_argc, x_args);
   return 0;
}

char
HFIX_unit_end      (void)
{
   PROG_shutdown  ();
   return 0;
}


