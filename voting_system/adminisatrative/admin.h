#ifndef ADMIN_H
#define ADMIN_H

/*tells if a function is to be used out of file or not*/
#define PUBLIC
#define PRIVATE static

PUBLIC int checkadminlogin(void);
PUBLIC void changeadminname(void);
PUBLIC void changeadminpasswd(void);

#endif