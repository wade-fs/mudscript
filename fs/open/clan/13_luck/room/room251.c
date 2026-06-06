inherit ROOM;
void create() {
	set( "short", "『觀眾台』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount5"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount10" : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount4"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/living-water",
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/obj/magic-sign",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 10062 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room253",
		"north"     : "/open/clan/13_luck/room/room78",
	]) );
	set( "long", @LONG
一層層的階梯形成了座位。從這邊可以清楚看到決鬥場上的比賽
。往決鬥場望去，似乎可以感覺到昔日比武的盛況。至於未來競爭的
精彩，或許就是坐在看台上的你要去努力的了。想到這邊，漸漸泛起
熱血，心中呼喊著：『加油！』。
LONG);
	setup();
	replace_program(ROOM);
}
