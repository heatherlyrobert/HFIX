



char       /*----: set up programgents/debugging -----------------------------*/
HFIX_unit_quiet    (void)
{
   char       *x_args [1]  = { "HFIX" };
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
HFIX_unit_loud     (void)
{
   char       *x_args [4]  = { "HFIX_unit","@@kitchen", "@@prog" , "@@hfix"};
   yURG_logger (4, x_args);
   yURG_urgs   (4, x_args);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
HFIX_unit_end      (void)
{
   yLOGS_end     ();
   return 0;
}


