// Room : /open/clan/ou-cloud-club/room/room115.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIG$懸崖$NOR$" );
	set( "owner", "miles" );
	set( "object", ([
		"file6"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount10" : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount5"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount9"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount6"  : 1,
	]) );
	set( "build", 10041 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "eastdown" : "/open/clan/ou-cloud-club/room/room78",
]) );
	set( "long", @LONG
啊！！！只見你腳下撲了一個空，差點跌落山下，幸好你輕功了得，
以腿踏空，運氣往上一跳，及時將自身拉回山崖邊，才保住一命，以防落
得粉身碎骨的下場，沒想到$HIR$四極$HIY$天山$NOR$徑的五行八卦陣如此恐怖，只要選錯
一步，竟是如此駭人可怕的。

LONG);
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
