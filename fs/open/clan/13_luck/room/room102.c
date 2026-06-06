inherit ROOM;
void create() {
	set( "short", "鳳凰樓三樓" );
	set( "build", 168 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room579",
		"east"      : "/open/clan/13_luck/room/room602",
		"down"      : "/open/clan/13_luck/room/room98.c",
		"up"        : "/open/clan/13_luck/room/room101.c",
		"north"     : "/open/clan/13_luck/room/room422.c",
		"south"     : "/open/clan/13_luck/room/room549.c",
	]) );
	set( "long", @LONG

    在店小二的引領，你沿著燈火照亮的樓梯往上爬，來到了鳳凰樓
三樓的通道，往你的廂房走去。從窗口往外望去，西邊有一座森林，
可惜被一片迷霧隴照，看不清全貌。天色漸漸變暗，只見滿天的飛鳥
，也都要飛回巢穴去休息了。

LONG);
	setup();
	replace_program(ROOM);
}
