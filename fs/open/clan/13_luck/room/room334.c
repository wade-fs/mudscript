inherit ROOM;
void create() {
	set( "short", "神風堂大門" );
	set( "owner", "smalloo" );
	set( "object", ([
		"amount6"  : 23,
		"file10"   : "/open/fire-hole/obj/p-pill",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file8"    : "/open/fire-hole/obj/y-pill",
		"amount5"  : 250,
		"file7"    : "/obj/stone/powder",
		"file4"    : "/open/fire-hole/obj/k-pill",
		"amount2"  : 159,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"file9"    : "/obj/gift/unknowdan",
		"amount4"  : 75,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 155,
		"amount7"  : 67,
		"amount9"  : 1,
		"amount1"  : 140,
		"amount3"  : 100,
		"amount10" : 30,
		"file6"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 10929 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room332",
		"north"     : "/open/clan/13_luck/room/room333",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    你收回內力，停了下來，看的前面，你換想種的地方到了，神風
堂大門乃堅固之極的梨木所製，鑲以鐵片，嵌以銅釘，大門還雕著傳
說中的神話人物----風神像，嚴肅寧靜，寒光閃耀，使你不禁的嚴肅
了起來。 


LONG);
	setup();
	replace_program(ROOM);
}
