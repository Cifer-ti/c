#ifndef ADMIN_H
#define ADMIN_H

/*tells if a function is to be used out of file or not*/
#define PUBLIC
#define PRIVATE static

/*checkadminlogin: checks if the username and password provided
                    are those of the admin for login*/
PUBLIC int checkadminlogin(void);

/*changeadminname: changes the admin name from the current one to 
                    one provide by the user*/
PUBLIC void changeadminname(void);

/*changeadminpasswd: changes the admin password from the
                        current one to one provided by the user*/
PUBLIC void changeadminpasswd(void);

#endif