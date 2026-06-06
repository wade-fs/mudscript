// Room : /open/clan/ou-cloud-club/room/room89.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIG$懸崖$NOR$" );
	set( "object", ([
		"file4"    : "/open/gsword/obj1/bpball",
		"file8"    : "/open/gsword/obj1/bpball",
		"amount8"  : 1,
		"file6"    : "/open/gsword/obj1/bpball",
		"amount10" : 1,
		"file1"    : "/open/gsword/obj1/bpball",
		"amount5"  : 1,
		"file7"    : "/open/gsword/obj1/bpball",
		"amount6"  : 1,
		"file9"    : "/open/gsword/obj1/bpball",
		"file2"    : "/open/gsword/obj1/bpball",
		"file10"   : "/open/gsword/obj1/bpball",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/gsword/obj1/bpball",
		"amount9"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/gsword/obj1/bpball",
		"amount3"  : 1,
	]) );
	set( "owner", "filia" );
	set( "build", 10023 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "eastdown" : "/open/clan/ou-cloud-club/room/room76",
]) );
	set( "long", @LONG
啊！！！只見你腳下撲了一個空，差點跌落山下，幸好你輕功了得，
以腿踏空，運氣往上一跳，及時將自身拉回山崖邊，才保住一命，以防落
得粉身碎骨的下場，沒想到$HIR$四極$HIY$天山$NOR$徑的五行八卦陣如此恐怖，只要選錯
一步，竟是如此駭人可怕的。

LONG);
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "no_transmit", 1 );
	setup();

	}
