inherit ROOM;
void create() {
	set( "short", "殿內大道二" );
	set( "object", ([
		"amount2"  : 500,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 500,
		"amount10" : 500,
		"amount1"  : 250,
		"amount3"  : 1,
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/obj/gift/bingtang",
		"amount6"  : 1,
		"file6"    : "/obj/gift/lingzhi",
		"amount5"  : 500,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 500,
		"file4"    : "/obj/gift/bingtang",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 500,
		"amount4"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10767 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room365.c",
		"north"     : "/open/clan/13_luck/room/room389",
	]) );
	set( "long", @LONG

    走在殿前大道上的你似乎感覺左邊的寒氣一波波向你襲來，而右邊則
是一股股的熱流刺痛著你的皮膚。原來左邊是幽冥殿的右殿而右邊是極火
殿的左殿，兩股極陰及極陽的氣流不斷的在這亂竄。心想還是往前進吧，
不然等下又不知道會惹上什麼大麻煩。

LONG);
	setup();
	replace_program(ROOM);
}
