inherit ROOM;
void create() {
	set( "short", "西側走道一" );
	set( "owner", "roar" );
	set( "object", ([
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount6"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
	]) );
	set( "build", 10041 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room392",
		"east"      : "/open/clan/13_luck/room/room372.c",
	]) );
	set( "long", @LONG

    通過長長的走道後，發現四周的裝飾也已經完全改變為以刀為主，牆
壁上掛著大大小小不同長短的刀刃，每口都泛著青光，看來都是當年逃難
進來的武林人士所曾經使用過的兵刃，有幾名巡邏的弟子正在非常專注的
警戒著，因為這裡再往西邊過去就是十三吉祥裡神祕強悍的十三刀堂了。

LONG);
	setup();
	replace_program(ROOM);
}
