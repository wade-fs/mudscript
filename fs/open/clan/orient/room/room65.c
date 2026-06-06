inherit ROOM;
void create() {
	set( "short", "陽台" );
	set( "owner", "cdrom" );
	set( "object", ([
		"file6"    : "/open/gblade/obj/sa-head",
		"amount5"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file10"   : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"amount10" : 1,
		"file5"    : "/open/capital/guard/gring",
		"amount6"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/capital/guard/gring",
		"file7"    : "/open/gblade/obj/sa-head",
		"amount3"  : 1,
	]) );
	set( "item_desc", ([
		"windows" : @ITEM
有小鳥有小鳥
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10791 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room42",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
