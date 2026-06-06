inherit ROOM;
void create() {
	set( "short", "尋刀" );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file7"    : "/open/mon/obj/thousand-nectar",
		"amount1"  : 8,
		"amount5"  : 44,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount6"  : 7,
		"file3"    : "/open/area/fortress/npc/obj/token",
		"amount4"  : 7,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 3,
		"amount7"  : 3,
		"file6"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "owner", "dfyw" );
	set( "build", 10121 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room368",
		"north"     : "/open/clan/13_luck/room/room101",
	]) );
	set( "long", @LONG

    你，自詡為名鑄刀師的後代，卻有著超越常人般非凡得宿命，揹
負著歷代祖先所未完成的重大使命，有異於現實洪流裡沉重的身軀，
心卻在狂想空間中四處遊蕩，找到一些可靠的伙伴共組十三吉祥，只
為了找尋先祖遺失在無窮黑暗魔道中唯一的一把妖刀。

LONG);
	setup();
	replace_program(ROOM);
}
