inherit ROOM;
void create() {
	set( "short", "翠柳亭" );
	set( "object", ([
		"file5"    : "/open/capital/obj/fist_book",
		"file6"    : "/open/capital/obj/force_book",
		"amount4"  : 1,
		"amount6"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file10"   : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"file3"    : "/open/capital/obj/steps_book",
		"file4"    : "/open/capital/obj/sword_book",
		"file1"    : "/open/ghost-hole/obj/fire-spirit",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/capital/obj/blade_book",
		"amount8"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10335 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/nine-sky-dragon/room/room37",
		"north"     : "/open/clan/nine-sky-dragon/room/hall.c",
	]) );
	set( "long", @LONG

　　翠柳亭是一座造景相當講究的涼亭，四根亭柱是用花崗石雕刻而
成的，亭柱上分別雕刻著龍、鳳、龜和麒麟四大祥獸的圖騰。亭內擺
著一張小石桌以及幾張石椅，石桌上放著一壺茶水和幾個茶杯，以供
人在此休息時可以飲用。由這裡向外望去可將九天蒼龍的景致盡收眼
底。

LONG);
	setup();
	replace_program(ROOM);
}
