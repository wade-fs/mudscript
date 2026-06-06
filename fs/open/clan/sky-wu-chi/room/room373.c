inherit ROOM;
void create() {
	set( "short", "gk eq-pants" );
	set( "object", ([
		"amount6"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
	]) );
	set( "build", 16260 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room94",
	]) );
	set( "long", @LONG

日出東南隅 照我秦氏樓

秦氏有好女 自名為羅敷

羅敷善蠶桑 採桑城南隅

青絲為籠係 桂枝為籠鉤

頭上倭墮髻 耳中明月珠

緗綺為下裙 紫綺為上襦

行者見羅敷 下擔捋髭鬚

少年見羅敷 脫帽著帩頭

耕者忘其犁 鋤者忘其鋤

來歸相怨怒 但坐觀羅敷

LONG);
	setup();
	replace_program(ROOM);
}
