// Room : /open/clan/ou-cloud-club/room/room95.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
啊！！！只見你腳下撲了一個空，差點跌落山下，幸好你輕功了得，
以腿踏空，運氣往上一跳，及時將自身拉回山崖邊，才保住一命，以防落
得粉身碎骨的下場，沒想到$HIR$四極$HIY$天山$NOR$徑的五行八卦陣如此恐怖，只要選錯
一步，竟是如此駭人可怕的。

LONG);
	set( "no_clean_up", 0 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	set( "short", "$HIG$懸崖$NOR$" );
	set( "owner", "miles" );
	set( "object", ([
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount10" : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount8"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount3"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
	]) );
	set( "build", 10162 );
	set( "exits", ([ /* sizeof() == 2 */
		"southdown" : "/open/clan/ou-cloud-club/room/room78",
]) );
	set( "no_transmit", 1 );
	setup();

	}
