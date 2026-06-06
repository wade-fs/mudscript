// Room : /open/clan/ou-cloud-club/room/room123.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG

小Ｐ每天下班後打滾玩 FS 的地方

不過小Ｐ已經很久沒來此房了

此房或許被小Ｐ下了許多的舞者咒術

也或許被小Ｐ擺了許多的機關吧

所以普通雜役也不敢隨便侵入打掃

再加上主人久不歸家無人打掃

所以此房看來雜亂不堪

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "short", "$HIG$『$HIC$小Ｐ之家$HIG$』$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file3"    : "/open/gsword/obj1/bpball",
		"amount10" : 2,
		"amount7"  : 1,
		"amount1"  : 303,
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"amount3"  : 1,
		"file4"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 172,
		"amount5"  : 34,
		"amount2"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 19,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file7"    : "/open/gsword/obj1/bpball",
		"amount9"  : 1,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file8"    : "/open/gsword/obj1/bpball",
	]) );
	set( "build", 10029 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 1 */
  "east" : "/open/clan/ou-cloud-club/room/room122",
]) );
	set( "light_up", 1 );
	setup();

	}
