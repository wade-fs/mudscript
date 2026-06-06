inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIC$３$NOR$" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount6"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount3"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file2"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file1"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount2"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven2-dark-head",
	]) );
	set( "build", 11245 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room704.c",
		"west"      : "/open/clan/ou-cloud-club/room/room706.c",
		"south"     : "/open/clan/ou-cloud-club/room/room709.c",
		"north"     : "/open/clan/ou-cloud-club/room/room713",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

   ( 1) 藍衣魔將的人頭(seven-dark-head)
   ( 2) 赤衣魔將的人頭(seven-dark-head)
   ( 3) 墨衣魔將的人頭(seven-dark-head)
   ( 4) 灰衣魔將的人頭(seven-dark-head)
   ( 5) 碧衣魔將的人頭(seven-dark-head)
   ( 6) 青衣魔將的人頭(seven-dark-head)
   ( 7) 紫衣魔將的人頭(seven-dark-head)

LONG);
	setup();
	replace_program(ROOM);
}
