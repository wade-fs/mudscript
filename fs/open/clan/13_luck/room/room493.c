inherit ROOM;
void create() {
	set( "short", "石橋" );
	set( "owner", "evonne" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file10"   : "/open/mogi/castle/obj/black-ghost-head",
		"file6"    : "/open/capital/obj/4-4",
		"amount10" : 1,
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount3"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount6"  : 1,
	]) );
	set( "build", 12262 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room492.c",
		"south"     : "/open/clan/13_luck/room/room495",
		"east"      : "/open/clan/13_luck/room/room494.c",
	]) );
	set( "long", @LONG

    你現在正站在一座長滿青苔的古橋上，橋下是一條清澈的山澗，
幾股清泉在亂石之中向山下奔流，不遠處那有一個瀑布，從山壁上猶
如一條白練般垂了下來，瀑布兩旁的石壁十分陡峭，高度和山澗旁的
松林相差了近三、四十丈。

LONG);
	setup();
	replace_program(ROOM);
}
