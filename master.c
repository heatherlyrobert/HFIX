



char       /*----: set up programgents/debugging -----------------------------*/
HFIX_unit_quiet    (void)
{
   char       *x_args [1]  = { "HFIX" };
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
HFIX_unit_loud     (void)
{
   char       *x_args [3]  = { "HFIX_unit","@@kitchen", "@@prog" };
   yURG_logger (3, x_args);
   yURG_urgs   (3, x_args);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
HFIX_unit_end      (void)
{
   yLOGS_end     ();
   return 0;
}


