inherit ROOM;
void create() {
	set( "short", "劍聖的無" );
	set( "owner", "world" );
	set( "object", ([
		"file7"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"amount4"  : 1,
		"file5"    : "/obj/gift/hobowdan",
		"amount2"  : 1,
		"file6"    : "/obj/gift/hobowdan",
		"file4"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
	]) );
	set( "build", 10346 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room315",
		"east"      : "/open/clan/ou-cloud-club/room/room198.c",
		"south"     : "/open/clan/ou-cloud-club/room/room303.c",
		"west"      : "/open/clan/ou-cloud-club/room/room305",
		"north"     : "/open/clan/ou-cloud-club/room/room237.c",
	]) );
	set( "long", @LONG
房間內的布置相當別致有品味，一張發出淡淡幽香的桌子，聞到此
香氣，頓時內息運行的特別順暢，看來此種木材並不是易得之物，桌上
擺著幾本武功密笈，仔細上一瞧，赫然發現是現今獨步武林的劍法$HIR$連陽
七訣劍法$NOR$，牆上掛著一幅字畫，上面有個偌大的劍字，每個筆畫之間暗
藏莫測高深得劍意在，看來屋子的主人愛劍成癡阿。

LONG);
	setup();
	replace_program(ROOM);
}
