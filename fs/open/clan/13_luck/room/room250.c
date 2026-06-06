inherit ROOM;
void create() {
	set( "short", "『山路』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount5"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"amount10" : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"amount4"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"amount6"  : 1,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"file4"    : "/open/killer/headkill/obj/world_dag",
	]) );
	set( "build", 10737 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room78.c",
		"north"     : "/open/clan/13_luck/room/room252",
	]) );
	set( "long", @LONG
從剛剛熱鬧的街道往北邊走了過來，不禁覺得精神氣爽。抬頭一看，只
見到一座雄偉的山矗立在你的眼前，讓你覺得心胸開闊了起來。而剛剛街道
的熱鬧感也似乎消失了，取而代之的卻是一股平心靜氣的感覺，彷彿居住在
世外桃源一般，即使是條漫長的道路，但是當作是健身的散步、爬山等等的
運動，對你自己的身體也是有幫助的。
LONG);
	setup();
	replace_program(ROOM);
}
