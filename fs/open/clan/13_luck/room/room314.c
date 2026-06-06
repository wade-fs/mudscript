inherit ROOM;
void create() {
	set( "short", "吉祥置物櫃癸" );
	set( "object", ([
		"amount5"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount4"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 10851 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room302",
	]) );
	set( "long", @LONG

    這裡是吉祥置物櫃癸，專門為還沒有房間的新進幫眾所設立的，此
環境優雅舒適，讓新進的幫眾有個可以去的地方跟休息的地方，使他們
快點成為十三吉祥的戰力，一起為幫派的未來而努力，一同打拼，萬里
風雲重此起，總有一天成大器，希望能為天下第一大幫而邁進。

LONG);
	setup();
	replace_program(ROOM);
}
