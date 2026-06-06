inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$HIB$魔$HIR$劍$WHT$藏$NOR$" );
	set( "object", ([
		"file5"    : "/open/gsword/obj1/blosword",
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/gsword/obj1/blosword",
		"file4"    : "/open/gsword/obj1/blosword",
		"amount5"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/gsword/obj1/blosword",
		"file2"    : "/open/gsword/obj1/sadsword",
		"amount1"  : 1,
	]) );
	set( "build", 12440 );
	set( "owner", "left" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room567",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
