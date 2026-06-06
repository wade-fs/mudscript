inherit ROOM;
void create() {
	set( "short", "$HIR$獵頭櫃$HIY$Ⅱ$HIC$３$NOR$" );
	set( "owner", "mekyn" );
	set( "object", ([
		"file10"   : "/open/center/obj/mechoufen-head",
		"file1"    : "/open/center/obj/mechoufen-head",
		"amount5"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/center/obj/mechoufen-head",
		"file5"    : "/open/center/obj/mechoufen-head",
		"file4"    : "/open/center/obj/mechoufen-head",
		"file3"    : "/open/center/obj/mechoufen-head",
		"file8"    : "/open/center/obj/mechoufen-head",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/center/obj/mechoufen-head",
		"amount6"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
	]) );
	set( "build", 27641 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room708.c",
		"west"      : "/open/clan/ou-cloud-club/room/room710.c",
		"north"     : "/open/clan/ou-cloud-club/room/room705",
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
