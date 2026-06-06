inherit ROOM;
void create() {
	set( "short", "東邪居" );
	set( "owner", "asfd" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic_palace/obj/magic_book",
		"file8"    : "/open/killer/obj/s_pill",
		"amount3"  : 1,
		"file9"    : "/open/killer/obj/dagger",
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount8"  : 8,
		"file3"    : "/open/capital/obj/blade2",
	]) );
	set( "build", 10112 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room83.c",
		"east"      : "/open/clan/13_luck/room/room263",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    大雪漫天，冰雪紛紛，這裡冰天雪地四面都是冰地，大雪一片片
的飄落，綻放出朦朧的景象，來到這裡感到冰冷刺骨，但附近有一間
小屋，裡面有著暖暖的火，更是興起了另一番景象，而旁邊立起一座
大冰塊上面並刻有字，正是「東邪居」。

LONG);
	setup();
	replace_program(ROOM);
}
