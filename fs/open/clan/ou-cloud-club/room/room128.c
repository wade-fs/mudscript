// Room : /open/clan/ou-cloud-club/room/room128.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
面前的高牆上有不少拳頭般大小的坑洞,一路直上,通往
上方,腳下踩的水塘,是地下水脈的分支,水流方向是由東向
西若順著水勢而行,應該可以回到惡魔城入口吧,否則令一條
通路就是按著牆上的坑洞飛躍而上嘍~~輕功可得罩著點啊!!
LONG);
	set( "cmkroom", 1 );
	set( "short", "$RED$惡魔城$NOR$藥局" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"amount2"  : 515,
		"amount1"  : 1651,
		"amount7"  : 541,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 368,
		"amount4"  : 246,
		"amount8"  : 71,
		"file8"    : "/open/fire-hole/obj/p-pill",
		"amount3"  : 305,
	]) );
	set( "light_up", 1 );
	set( "build", 10120 );
	set( "exits", ([ /* sizeof() == 1 */
		"west"      : "/open/clan/ou-cloud-club/room/room127.c",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
