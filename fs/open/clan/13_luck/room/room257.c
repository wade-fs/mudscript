inherit ROOM;
void create() {
	set( "short", "『桃雲小築』 " );
	set( "owner", "mill" );
	set( "object", ([
		"amount2"  : 1477,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 41,
		"amount10" : 1,
		"file7"    : "/open/magic-manor/obj/lunar-heart",
		"amount5"  : 15,
		"amount4"  : 42,
		"amount9"  : 1,
		"file9"    : "/obj/stone/suipian",
		"file3"    : "/obj/stone/suipian",
		"file6"    : "/obj/stone/powder",
		"file5"    : "/obj/stone/jiao",
		"file2"    : "/obj/stone/powder",
		"file4"    : "/obj/stone/powder",
		"amount3"  : 148,
		"amount7"  : 1,
	]) );
	set( "build", 10386 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room258",
	]) );
	set( "long", @LONG
走進桃雲小築裡，看到了居住在這邊的兩位隱士，沒有想到住在這裡的
這兩位隱士，竟然是這麼的年輕，你也很佩服他們兩位，可以看破江湖上面
的恩恩怨怨，獨自的隱居在這片無人的桃花林裡。看起來那兩位隱士，好像
是一對夫妻，讓人感覺起來鶼鰈情深。
隱士 崔楓(Sue fo)
隱士 冷芸(Le yu)
LONG);
	setup();
	replace_program(ROOM);
}
