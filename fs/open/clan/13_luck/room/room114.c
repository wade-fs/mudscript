inherit ROOM;
void create() {
	set( "short", "望月樓" );
	set( "object", ([
		"amount9"  : 1,
		"amount10" : 1,
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"file8"    : "/open/dancer/obj/yuawaist",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/wu/npc/obj/armband",
		"amount7"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/ping/obj/gold_hand",
		"file7"    : "/daemon/class/bonze/puty_pullium",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/dancer/obj/maple_ribbon",
		"amount1"  : 1,
		"file3"    : "/open/scholar/obj/icefan",
	]) );
	set( "build", 10872 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room42.c",
		"up"        : "/open/clan/13_luck/room/room594.c",
	]) );
	set( "long", @LONG

    這裡是十三吉祥的客棧右廳，入口的大門上面高高懸著一塊琉璃黃
金匾，上頭寫著『望月樓』三個斗大的字，陽光照耀下，反射出耀眼的
金光，朱紅色的大門開著，門上兩個門環俱做獅頭狀，顯的氣派非凡，
門兩旁各蹲著一個雕的栩栩如生的石獅子。

LONG);
	setup();
	replace_program(ROOM);
}
