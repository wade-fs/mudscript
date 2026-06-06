inherit ROOM;
void create() {
	set( "short", "LEON 武器房" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/fire-hole/obj/y-pill",
		"amount10" : 1,
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 17,
		"amount7"  : 56,
		"amount6"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file5"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "build", 10700 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room545.c",
		"south"     : "/open/clan/13_luck/room/room750.c",
		"east"      : "/open/clan/13_luck/room/room733.c",
	]) );
	set( "long", @LONG
這裡似乎只是一個入口， 再進去可以看到各種不同的武器陳列
有刀、劍、爪、弓箭、扇子，只要是任何你想像的到的東西幾乎
在這裡都有。疑, 這不是折凳嗎？沒錯，連折凳都是主人的收藏
品不愧是七武器之首。現在讓你對主人收集的能力,沒有任何質疑
。因為連這樣平凡的東西，居然也是他收集的對象，這未免太誇
張了吧。


LONG);
	setup();
	replace_program(ROOM);
}
