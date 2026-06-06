inherit ROOM;
void create() {
	set( "short", "東長廊" );
	set( "owner", "roarii" );
	set( "object", ([
		"amount2"  : 120,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/killer/obj/hate_knife",
		"amount6"  : 21000,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount7"  : 1,
	]) );
	set( "build", 10065 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room574",
		"west"      : "/open/clan/13_luck/room/room576",
	]) );
	set( "long", @LONG
你現在正在東長廊上，橡木所鋪的地板，感覺起來一塵不染。
陽光由窗上灑落了下來，使得長廊特別的明亮。兩旁還掛了許多的
字畫，全是名家手筆，還真令你想細細琢摹。不忍離去呢。
你現在正在東長廊上，橡木所鋪的地板，感覺起來一塵不染。
陽光由窗上灑落了下來，使得長廊特別的明亮。兩旁還掛了許多的
字畫，全是名家手筆，還真令你想細細琢摹。不忍離去呢。
LONG);
	setup();
	replace_program(ROOM);
}
