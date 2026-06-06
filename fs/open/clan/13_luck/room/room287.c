inherit ROOM;
void create() {
	set( "short", "小賢家" );
	set( "owner", "romi" );
	set( "object", ([
		"amount5"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/gsword/obj1/blosword",
		"amount7"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/capital/guard/gring",
		"amount2"  : 84,
		"amount1"  : 39,
		"amount6"  : 39,
		"file9"    : "/open/gsword/obj1/blosword",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/snow/obj/sky_lin_stone",
	]) );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room231",
	]) );
	set( "build", 10326 );
	set( "light_up", 1 );
	set( "long", @LONG

    你一進到這個神秘洞穴，馬上被四道兇狠的目光所驚嚇，小心一
看，原來是四隻守護聖獸，分別是青龍，白虎，朱雀，玄武守住洞穴
的四周，小心的守護著正在練功的主人，當你想回頭時，已經太晚了
，四隻聖獸已經把你包圍住了。


LONG);
	setup();
	replace_program(ROOM);
}
