inherit ROOM;
void create() {
	set( "short", "維修室" );
	set( "owner", "icute" );
	set( "object", ([
		"amount5"  : 1,
		"amount2"  : 655,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount6"  : 1,
		"file1"    : "/open/mon/obj/mon-pill",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount9"  : 1870,
		"amount1"  : 254,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 158,
		"amount7"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10363 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room94.c",
		"east"      : "/open/clan/13_luck/room/room234.c",
		"enter"     : "/open/clan/13_luck/room/room235",
		"west"      : "/open/clan/13_luck/room/room233.c",
	]) );
	set( "long", @LONG
   這裡是維修專家為了造福有困難所開闢的維修室，看到房間內滿滿的工具
與破舊的材料，你心想有此地方維修太好了，你專注的看著維修仙人，努力的
製造一隻強而有利的武器，讓你心動的想請維修仙人幫你製造一把
  
LONG);
	setup();
	replace_program(ROOM);
}
