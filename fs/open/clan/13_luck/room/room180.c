inherit ROOM;
void create() {
	set( "short", "萬里長征樓" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/prayer/obj/crystal2",
		"amount1"  : 1,
		"file2"    : "/open/prayer/obj/crystal1",
	]) );
	set( "build", 10068 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room181.c",
		"north"     : "/open/clan/13_luck/room/room246.c",
	]) );
	set( "long", @LONG

　　此樓為記錄著小東邪、狂影二代幫主、狂龍、風魔浪子、此四人
的英勇事蹟，東攪蛇寨、西征風雨、南討鏡月、北亂京城、得龍元、
取冰蠶、斬天子、挑武聖、取的鬼王頭、凱旋勝利歸。之後此四人就
成為幫派的重要角色、也被歸為吉祥八煞中。 

LONG);
	setup();
	replace_program(ROOM);
}
