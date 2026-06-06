inherit ROOM;
void create() {
	set( "short", "鎖龍塔大門" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/obj/gift/unknowdan",
	]) );
	set( "owner", "amdxp" );
	set( "build", 10066 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room229.c",
		"enter"     : "/open/clan/13_luck/room/room226.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

　　走了一小段路你來到了鎖龍塔，鎖龍塔高九層，九龍各自守衛一
層，因此除非你有三頭六臂，否則想進入是比登天還難，入口的龍頭
開裂的大口就是大門了( door )，整座塔好似一條龍盤倨，龍身更是鐵
鍊交錯，這就是鎖龍塔的由來吧。

LONG);
	setup();
	replace_program(ROOM);
}
