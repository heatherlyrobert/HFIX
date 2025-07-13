#include "HFIX.h"



char
HFIX_whoami              (char r_name [LEN_LABEL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_home      [LEN_HUND]  = "";
   char        x_work      [LEN_HUND]  = "";
   char        x_name      [LEN_LABEL] = "";
   char       *p           = NULL;
   char       *q           = NULL;
   int         l           =    0;
   /*---(default)------------------------*/
   if (r_name == NULL)   strcpy (r_name, "");
   /*---(get the home)-------------------*/
   p = getcwd (x_home, LEN_HUND);
   --rce;  if (p == NULL)   return rce;
   l = strlen (x_home);
   /*> printf ("%3då%sæ\n", l, x_home);                                               <*/
   /*---(check valid areas)--------------*/
   --rce; if (l > 16 && strncmp ("/home/system/"         , x_home, 13) == 0) ;
   else if   (l > 19 && strncmp ("/home/keepsake/"       , x_home, 15) == 0) ;
   else if   (l > 25 && strncmp ("/home/member/p_gvskav/", x_home, 22) == 0) ;
   else if   (l >  8 && strncmp ("/tmp/"                 , x_home,  5) == 0) ;
   else return rce;
   /*---(prepare name)-------------------*/
   strlcpy (x_work, x_home, LEN_HUND);
   l = strlen (x_work);
   if (x_work [l - 1] == '/')  x_work [--l] = '\0';
   /*> printf ("%3då%sæ\n", l, x_work);                                               <*/
   /*---(get the project)----------------*/
   p = strrchr (x_work, '/');
   if (p == NULL)   p = x_work;
   else             ++p;
   /*> printf ("%3då%sæ\n", strlen (p), p);                                           <*/
   q = strchr  (p, '.');
   if (q != NULL)  q [0] = '\0';
   /*> printf ("%3då%sæ\n", strlen (p), p);                                           <*/
   snprintf (x_name, LEN_LABEL, "%s_", p);
   /*> printf ("%3då%sæ\n", strlen (x_name), x_name);                                 <*/
   /*---(save back)----------------------*/
   if (r_name != NULL)  strlcpy (r_name, x_name, LEN_LABEL);
   /*---(complete)-----------------------*/
   return 0;
}


