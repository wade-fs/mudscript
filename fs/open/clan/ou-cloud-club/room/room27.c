// Room : /open/clan/ou-cloud-club/room/room27.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$YEL$絲綢之路$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10030 );
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
  "west" : "/open/clan/ou-cloud-club/room/room29",
  "northeast" : "/open/clan/ou-cloud-club/room/room26",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
