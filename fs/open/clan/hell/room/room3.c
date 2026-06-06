inherit ROOM;
void create() {
	set( "short", "$HIW$奈何橋頭$NOR$" );
	set( "object", ([
		"file3"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/mon/obj/ghost-claw",
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount1"  : 1,
		"file2"    : "/open/mon/obj/ghost-claw",
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
	]) );
	set( "build", 10689 );
	set( "light_up", 1 );
set( "exits", ([        
		"south"     : "/open/clan/hell/room/hall.c",
		"north"     : "/open/clan/hell/room/room2.c",
	]) );
	set( "long", @LONG
再往前去就是奈何橋了，過了奈何橋就不能再回頭了，難道果真人生
沒有不死的傳說嗎！？只見一團團的鬼影往奈何橋上走去，似乎除了轉世
投胎之外，已經無路可走了。每個鬼同志的臉色又恐慌又匆忙，彷彿害怕
接受死後的審判，又怕太晚去輪迴找不到好位置，還是趕快上路吧！！

  白無常(White gargoyle)

LONG);
	setup();
	replace_program(ROOM);
}
