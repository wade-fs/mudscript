inherit ROOM;
void create() {
	set( "short", "醉仙三樓" );
	set( "object", ([
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount8"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "light_up", 1 );
	set( "build", 10726 );
	set( "exits", ([
		"down"      : "/open/clan/nine-sky-dragon/room/room14.c",
		"east"      : "/open/clan/nine-sky-dragon/room/room41",
		"up"        : "/open/clan/nine-sky-dragon/room/room35.c",
	]) );
	set( "long", @LONG

　　你繞過一道淡綠綢屏風，順著樓梯來到醉仙樓三樓的走郎上，心
情愉悅地走著。往外望去，只見湖面上映照著醉仙樓樓臺的倒影，水
波蕩漾，顯得格外的美麗。一陣南風吹過，拂動了水晶的窗簾，相互
碰撞發出那清脆悅耳的聲響。

LONG);
	setup();
	replace_program(ROOM);
}
