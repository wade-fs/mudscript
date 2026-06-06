inherit ROOM;
void create() {
	set( "short", "十三拳堂" );
	set( "owner", "roar" );
	set( "object", ([
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount1"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount6"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount2"  : 1,
	]) );
	set( "build", 10074 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room397",
		"north"     : "/open/clan/13_luck/room/room371.c",
	]) );
	set( "long", @LONG

    走到十三拳堂，你不驚一聲唏噓。高聳的大理石拱門之下的拳堂弟子，
各個高大強壯，練起堂主所教的拳法更是有聲有色，所揮出的每一拳都挾帶
著強烈的拳勁，拳勁所至之處均在大理石壁上留下一道深且長的刮痕，可見
拳堂拳勁的兇猛完全不輸給左側十三刀堂的兇悍。

LONG);
	setup();
	replace_program(ROOM);
}
