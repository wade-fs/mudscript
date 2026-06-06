inherit ROOM;
void create() {
	set( "short", "空瓶子武器室2" );
	set( "object", ([
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount10" : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"amount1"  : 9,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
	]) );
	set( "build", 10073 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room125.c",
		"east"      : "/open/clan/sky-wu-chi/room/room129",
	]) );
	set( "long", @LONG
這裡的武器也沒有什麼不一樣的,只是一些比較好的兵器,每一樣
的兵器有很能夠讓人家來玩味的,只要你對兵器有所了解,你就會發現
在這裡看到的兵器,說不定有的都還是你沒看過的呢..所以你才知到
這個房子的主人是多麼的對兵器有多愛護...
你現在可以在這裡看到的兵器有 邪刀(shi-blade)魚龍(ublade)
赤焰絕炎針(fire needle)火龍劍(fire dragon sword)

LONG);
	setup();
	replace_program(ROOM);
}
