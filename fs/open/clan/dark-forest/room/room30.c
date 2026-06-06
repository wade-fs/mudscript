inherit ROOM;
void create() {
	set( "short", "$HIY$硬的刀$NOR$" );
	set( "owner", "robo" );
	set( "object", ([
		"amount7"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
	]) );
	set( "build", 10176 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/dark-forest/room/room29",
	]) );
	set( "long", @LONG

刀刀刀刀刀　　中中中中中　　不不不不不　　二二二二二
刀刀刀刀刀　　中中中中中　　不不不不不　　二二二二二
刀刀刀刀刀　　中中中中中　　不不不不不　　二二二二二
刀刀刀刀刀　　中中中中中　　不不不不不　　二二二二二
刀刀刀刀刀　　中中中中中　　不不不不不　　二二二二二

LONG);
	setup();
	replace_program(ROOM);
}
