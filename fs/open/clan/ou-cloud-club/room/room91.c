// Room : /open/clan/ou-cloud-club/room/room91.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIG$懸崖$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/gsword/obj1/bpball",
		"amount4"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/gsword/obj1/bpball",
		"file4"    : "/open/gsword/obj1/bbladeball",
	]) );
	set( "owner", "filia" );
	set( "build", 10203 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "northdown" : "/open/clan/ou-cloud-club/room/room76",
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
