inherit ROOM;
void create() {
	set( "short", "魔法盾室" );
	set( "object", ([
		"amount6"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room313",
		"south"     : "/open/clan/13_luck/room/room302.c",
	]) );
	set( "build", 10137 );
	set( "light_up", 1 );
	set( "long", @LONG

    此為魔刀二代掌門莫無愁的身上寶物，魔刀的變態是狂想空間中出
名的，何況是師傅級的，常常被他的魔龍訣打到不能動而死，魔刀連擊
更是暴力中的狠角色，三斬歸元，被斬的亂七八糟，等級低的玩家，可
別找他領教不然吃不完就去找小黑小白泡茶了..

LONG);
	setup();
	replace_program(ROOM);
}
