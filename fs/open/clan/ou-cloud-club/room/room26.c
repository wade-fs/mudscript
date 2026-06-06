// Room : /open/clan/ou-cloud-club/room/room26.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$YEL$絲綢之路$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"amount10" : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10009 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
黃沙滾滾,烈日當空,你現在正處在一片金黃色的大沙漠之中,
依稀可以看到的一條小路呈東西走向,這就是我國與西域各國通商
來往的必經道路,看來自唐僧之後已很久沒有人走過了,想到千百年
前高人所經之路,竟然就在你腳下,不禁豪氣陡生.
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room25",
  "southwest" : "/open/clan/ou-cloud-club/room/room27.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
