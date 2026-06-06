inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIY$Ⅱ$HIC$２$NOR$" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/center/obj/mechoufen-head",
		"file2"    : "/open/center/obj/mechoufen-head",
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount2"  : 1,
		"file9"    : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount9"  : 1,
		"amount10" : 1,
		"file4"    : "/open/center/obj/mechoufen-head",
		"file8"    : "/open/center/obj/mechoufen-head",
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount8"  : 1,
		"file1"    : "/open/center/obj/mechoufen-head",
		"file3"    : "/open/center/obj/mechoufen-head",
		"amount1"  : 1,
	]) );
	set( "build", 10882 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room707.c",
		"west"      : "/open/clan/ou-cloud-club/room/room709.c",
		"north"     : "/open/clan/ou-cloud-club/room/room704",
	]) );
	set( "long", @LONG

   ( 1) 梅超風的人頭(mechoufen-head)
   ( 2) 梅超風的人頭(mechoufen-head)
   ( 3) 梅超風的人頭(mechoufen-head)
   ( 4) 梅超風的人頭(mechoufen-head)
   ( 5) 梅超風的人頭(mechoufen-head)
   ( 6) 梅超風的人頭(mechoufen-head)
   ( 7) 梅超風的人頭(mechoufen-head)
   ( 8) 梅超風的人頭(mechoufen-head)
   ( 9) 梅超風的人頭(mechoufen-head)
   (10) 梅超風的人頭(mechoufen-head)

LONG);
	setup();
	replace_program(ROOM);
}
