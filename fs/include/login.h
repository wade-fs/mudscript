#ifndef __LOGIN__
#define __LOGIN__

#define LOGIN_TIMEOUT			300

#define WELCOME				"/adm/etc/welcome"
#define NEWS				"/doc/help/news"
#define NEW_PLAYER_INFO			"/adm/etc/new_player"
#define MOTD				"/adm/etc/motd"
#define WIZ_MOTD			"/adm/etc/motd.wiz"
#define WIZLIST				"/adm/etc/wizlist"
#define WIZBOSS				"/adm/etc/wizboss"
#define COP_HEAD                        "/open/common/npc/cop"
#define CHECK_MAIL		        "/adm/etc/check_mail"
#define BANNED_IP           		"/adm/etc/banned_ip"
#define STARTROOM           		"/open/newhand/newhand"
#define DEATHROOM			"/open/death/start"
#define REVIVEROOM                      "/open/common/room/inn"

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)
//#define MAX_USERS    500 // 平時人數上限
//#define MAX_USERS_2  500 // tintin人數上限

// multi login 人數限制 by ACKY
// multi login 人數限制 fix by frequency
#define MAX_MULTI_USUAL     10 // 平常時段
#define MAX_MULTI_UNUSUAL   10 // 非平時時段
#define MAX_MULTI_SPECIAL	10 // 特殊IP (例如:雄專全部共用同一IP)

// This defines the robot checker room. All susspecious robot player
// will be transfered to this room. You should give a chance for those
// non-robot player to return to the world.
// By Annihilator (05-26-95)
#define ROBOT_CHECK			"/open/wiz/courthouse"

// 想要不讓玩家上線, 可以把 undef 改成 define, 然後 update /adm/daemons/logind
// 反之, 要取消則把 define 改成 undef, 當然也要 update /adm/daemons/logind
// 或者想限制總上線人數, 則改 MAX_USERS 的數值.
#define WIZ_LOCK  "\n\nsorry. 現在修理中\n\n\n"
#undef LOCK_WIZARD "\n\n巫師請連往 140.122.77.123 1234 開發新區域.\n\n\n"

// this is magic word for some connection.
#define MAGIC_WORD "FS_MAGIC_WORD"

#endif
