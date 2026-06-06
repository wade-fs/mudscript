inherit ROOM;
void create() {
	set( "short", "醉仙小道" );
	set( "owner", "mill" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room183",
		"south"     : "/open/clan/13_luck/room/room425",
	]) );
	set( "object", ([
		"amount8"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file1"    : "/obj/gift/lingzhi",
		"file8"    : "/open/magic-manor/obj/water-ball",
		"amount9"  : 1,
		"file10"   : "/open/mogi/castle/obj/seven4-dark-head",
		"file2"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"file3"    : "/daemon/class/fighter/armband",
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/obj/magic-sign",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file9"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 10227 );
	set( "light_up", 1 );
	set( "long", @LONG

    現在你位於醉仙居的長廊上，兩旁的假山假水十分地美麗，花園
之中百花盛開互相爭奇鬥豔。這些花全部都是星月堂主所親手栽培的
！這個美麗花園帶來的柔和之氣和星月堂所散發的陽剛之氣相對比，
簡直是將聖堂的氣場調和一番，看來星月堂堂主還真是有心！ 

LONG);
	setup();
	replace_program(ROOM);
}
