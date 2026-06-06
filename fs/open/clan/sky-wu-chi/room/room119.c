inherit ROOM;
void create() {
	set( "short", "$HIW$水無邊$NOR$" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount3"  : 1,
		"file1"    : "/obj/stone/suipian",
		"amount5"  : 1,
		"file3"    : "/obj/gift/karwan",
		"file2"    : "/obj/stone/powder",
		"file4"    : "/open/ping/obj/ra-head",
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount2"  : 1,
		"amount1"  : 2,
		"amount4"  : 1,
	]) );
	set( "build", 10113 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room271",
		"enter"     : "/open/clan/sky-wu-chi/room/room122.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
$HIC$大雪漫天，冰雪紛紛，這裡冰天雪地四面都是冰地，大雪一片片
的飄落，綻放出朦朧的景象，來到這裡感到冰冷刺骨，但附近有一間
小屋，裡面有著暖暖的火，更是興起了另一番景象，而旁邊立起一座
大冰塊上面並刻有字，正是「水無邊白龍居」。$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
