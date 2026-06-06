inherit ROOM;
void create() {
	set( "short", "$HIR$硬的扇$NOR$" );
	set( "owner", "robo" );
	set( "object", ([
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10314 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/dark-forest/room/room29",
	]) );
	set( "long", @LONG

風風風風風　　行行行行行　　萬萬萬萬萬　　里里里里里
風風風風風　　行行行行行　　萬萬萬萬萬　　里里里里里
風風風風風　　行行行行行　　萬萬萬萬萬　　里里里里里
風風風風風　　行行行行行　　萬萬萬萬萬　　里里里里里
風風風風風　　行行行行行　　萬萬萬萬萬　　里里里里里

LONG);
	setup();
	replace_program(ROOM);
}
