inherit ROOM;
void create() {
	set( "short", "西練武場" );
	set( "owner", "roarii" );
	set( "object", ([
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10269 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room562",
	]) );
	set( "long", @LONG
這裡的練習弟子武功有些底子，只見他們舞的一手好功夫，也
有弟子在練習拳法，只見一套拳打的虎虎生風，有些弟子在練習腿
法，看來他們不光是練習兵器，更有拳腳上的修養，使你忍不住要
向他們討教個兩三招。
LONG);
	setup();
	replace_program(ROOM);
}
