/* ftpdsupp.h: ftpd support _code_ */

#ifndef _FTPDSUPP_H
#define _FTPDSUPP_H

#define directory_exists(p) (file_size(p)==-2)
#define file_exists(p) (file_size(p)>0)

/*
 * debugging macros
 */
#define TP(STR)
#define DEBUG_SEND

#define CHECK_LOGIN() \
    if ( !socket_info[ fd ][ LOGGED_IN ] ) { \
        socket_write( fd, "530 Please login with USER and PASS.\n" ); \
        break; \
    }

#define CHECK_CMD(x) \
    if ( sizeof(command) == x) { \
        socket_write( fd, sprintf("500 '%s': command not understood.\n", \
              command[ 0 ]) ); \
        break; \
    }
   
/*
 * check_access determines who is allowed to use ftp (assuming the correct
 * password is known).  if check_access() returns 0 then the user is
 * disallowed even if the user knows the password.
 */
int check_access(string name)
{
  string file;

    if ( name == "anonymous" )
        return 1;

	return wizhood(name) != "(player)";
}

/*
 * return 1 if user named 'name' has password of 'plaintext'
 */
int check_password(string name, string plaintext)
{
    string fancytext, cpass;
    object login_ob;

    if ( name == "anonymous" ) {
        // Currently guest's email address is not verified from USITE;
        // consider supporting:
        //   name@some.ip.dot.address (from USITE and/or socket_address(fd))
        //   name@some.domain.name (from USITE)
        //   name@some-mud (reverse DNS lookup)
        if (!plaintext || plaintext == "")
            return 0;
        else if (member_array(plaintext, ({ "none", "guest", "anon",
              "anonymous", "none@none"}) ) != -1)
            return 0;
        else
            return 1;
    }

    /*
     * This is a good example of differences in mudlib design
     *   1) export_uid() vs creator_file() on setting a new object's uid
     *   2) query_password() vs query("password")
     */
    // get login object's password
    seteuid(getuid());
    login_ob = new(LOGIN_OB);

    // set login object's uid
    seteuid(name);
    export_uid(login_ob);

    // now set login object's name
    seteuid( getuid() );
    login_ob->set("id", name);

    // get login object's password
    login_ob->restore();
    fancytext = (string)login_ob->query("password");

    reload_object(login_ob);
    destruct(login_ob);

    if (!fancytext || !plaintext) {
        return 0;
    }

    cpass = crypt(plaintext, fancytext);

    return (cpass == fancytext);
}

/*
 * determines if "who" is allowed to connect from this site
 * by using the same args used by the user in his/her .login file for
 * the sitecheck command
 */
// Check site logic is enabled as per ftpdconf.h
static int dot_match(string *site, string *pattern, int flag) {
// ...
}

int check_site(string who, int fd) {
// ...
    return 1;
}



#endif /* _FTPDSUPP_H */
