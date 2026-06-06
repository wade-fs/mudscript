inherit ROOM;
void create() {
	set( "short", "五行陣入口" );
	set( "object", ([
		"file6"    : "/obj/gift/unknowdan",
		"amount1"  : 240,
		"amount7"  : 33,
		"amount10" : 5,
		"amount2"  : 1,
		"file8"    : "/open/killer/memory/static",
		"file7"    : "/obj/stone/suipian",
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
		"amount8"  : 1,
		"file2"    : "/open/killer/obj/fire-knife",
		"file4"    : "/open/magic-manor/obj/sun-heart",
		"file1"    : "/open/mon/obj/mon-pill",
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/obj/lunar-heart",
		"amount5"  : 1,
		"file3"    : "/obj/stone/powder",
		"amount9"  : 1,
		"amount3"  : 292,
		"amount6"  : 1,
		"file10"   : "/obj/stone/jiao",
	]) );
	set( "build", 10444 );
	set( "light_up", 1 );
	set( "owner", "soul" );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room647",
		"north"     : "/open/clan/13_luck/room/room645",
	]) );
	set( "long", @LONG

    進入宏偉的大門之後，來到天地五行陣入口。由金、木
、水、火、土五行構成的陣法，正是通往『驚雲閣』的必經
之路，只有勇者才能順利闖關通過，見到驚雲閣的主人──
──────────────────────步驚雲。

LONG);
	setup();
	replace_program(ROOM);
}
