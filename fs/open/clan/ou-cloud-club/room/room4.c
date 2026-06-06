// Room : /open/clan/ou-cloud-club/room/room4.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG

$HIY$                                 ▂ ▃ ▄ ▅ ▆ ▅ ▄ ▃ ▂ ▁
                               ◢ ▋▋▋▋▋▋▋▋▋▋▋▋▋▋◣
                               ◥▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋◣
                              ◢███◣▋▋▋▋▋▋▋▋▋▋▋▋▋◣
              ╭▃▃▃▃▃▃◢◤θ◢██ ▋▋▋▋▋▋▋▋▋▋▋▋▋▋◣
               █████████████ ▋▋▋▋▋▋▋▋▋▋▋▋▋▋◣
               ◥███████████▌▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋◣
                  ▼      ◥██████▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋◣
                            ██████ ▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋◤
                            █████◤▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋◤
                          ◢████◤ ▋▋▋▋▋▋▋▋▋▋▋▋▋▋◤
                     ▲ ◢████◤▋▋▋▋▋▋▋▋▋▋▋▋▋▋▋◤
                    ◥█████◤ ▋▋▋▋▋▋▋▋▋▋▋▋▋▋◤
                               ◥ ▋▋▋▋▋▋▋▋▋▋▋▋▋▋◤
                                 ◥  ◥  ◤  ◥  ◤  ◥  ◥$NOR$

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"north"     : "/open/clan/ou-cloud-club/room/room209.c",
		"pill"      : "/open/clan/ou-cloud-club/room/room601.c",
		"ghost"     : "/open/clan/ou-cloud-club/room/room668.c",
		"west"      : "/open/clan/ou-cloud-club/room/room101.c",
		"east"      : "/open/clan/ou-cloud-club/room/room119.c",
		"south"     : "/open/clan/ou-cloud-club/room/room656.c",
		"weapon"    : "/open/clan/ou-cloud-club/room/room681",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIG$俠谷$HIC$幽心$NOR$" );
	set( "owner", "skyent" );
	set( "object", ([
		"file10"   : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount10" : 1,
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"amount6"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"file4"    : "/open/wu/npc/obj/armband",
		"amount9"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file2"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount3"  : 1,
		"amount5"  : 1,
		"file7"    : "/obj/gift/xiandan",
	]) );
	set( "build", 12436 );
	set( "light_up", 1 );
	setup();

	}
