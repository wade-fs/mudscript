inherit ROOM;
void create() {
	set( "short", "$HIC$硬的帶$NOR$" );
	set( "owner", "robo" );
	set( "object", ([
		"amount7"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10092 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/dark-forest/room/room29",
	]) );
	set( "long", @LONG

五五五五五　　彩彩彩彩彩　　繽繽繽繽繽　　紛紛紛紛紛
五五五五五　　彩彩彩彩彩　　繽繽繽繽繽　　紛紛紛紛紛
五五五五五　　彩彩彩彩彩　　繽繽繽繽繽　　紛紛紛紛紛
五五五五五　　彩彩彩彩彩　　繽繽繽繽繽　　紛紛紛紛紛
五五五五五　　彩彩彩彩彩　　繽繽繽繽繽　　紛紛紛紛紛

LONG);
	setup();
	replace_program(ROOM);
}
