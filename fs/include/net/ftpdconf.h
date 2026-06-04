/* ftpdconf.h: ftpd configuration */

/*
-----------------------------------------------
   standard defines.
-----------------------------------------------
*/

#define FTPD_PORT  8000
#define FTPD_TIMEOUT 900
#define MAX_FTPD_IDLE 7200
#define HOME_DIR(name)  user_cwd(name)
#define LOGIN_MSG       "/adm/etc/ftpd_welcome"
#define THE_MUD_NAME    "狂想空間"
#define FTPD_MAX_USERS 5
#define THE_VERSION __VERSION__
#define BLOCK_SIZE 8096
#define FTP_BUGS_EMAIL "robocoder@tmi-2 or annihilator@es2"

/*
-----------------------------------------------
   misc support defines.
-----------------------------------------------
*/

#define ANONYMOUS_FTP
#define GUEST_WIZARD_FTP
#define MESSAGE_FILES

#define READ_LEVEL 0
#define WRITE_LEVEL 1

#define PUB_DIR "/open"
#define FTP_DIR "/ftp"

