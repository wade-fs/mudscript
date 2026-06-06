inherit ROOM;
void create() {
	set( "short", "$HIM$≡冥魔帝冠≡$NOR$" );
	set( "build", 10073 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room367.c",
		"up"        : "/open/clan/ou-cloud-club/room/room378",
	]) );
	set( "long", @LONG
帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠

LONG);
	setup();
	replace_program(ROOM);
}
