inherit ROOM;
void create() {
	set( "short", "風月大陸" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file3"    : "/obj/gift/shenliwan",
		"file2"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount1"  : 1,
		"file4"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file5"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
	]) );
	set( "build", 14312 );
	set( "owner", "ctx" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room514.c",
		"down"      : "/open/clan/ou-cloud-club/room/room517",
		"north"     : "/open/clan/ou-cloud-club/room/room512.c",
		"west"      : "/open/clan/ou-cloud-club/room/room513.c",
		"south"     : "/open/clan/ou-cloud-club/room/room515.c",
		"up"        : "/open/clan/ou-cloud-club/room/room506.c",
	]) );
	set( "long", @LONG
一片傳說中的大陸 ,一個傳奇人物的路程。大陸諸國爭霸的
時代, 是群雄並起施展才華的舞臺。一個出身平民卻有著無比運
氣的男人出現在這個大舞臺的一角。身為帝國騎士，但更像個好
鬥貪色混混的他，在不經意之間踏出了改變歷史的第一步。

LONG);
	setup();
	replace_program(ROOM);
}
