inherit ROOM;
void create() {
	set( "short", "$HIG$人靈草$NOR$" );
	set( "object", ([
		"amount6"  : 2000,
		"amount4"  : 2000,
		"amount3"  : 2000,
		"file6"    : "/open/doctor/item/human_item",
		"amount10" : 2000,
		"amount2"  : 2000,
		"file5"    : "/open/doctor/item/human_item",
		"amount5"  : 2000,
		"amount9"  : 1000,
		"file7"    : "/open/doctor/item/human_item",
		"file1"    : "/open/doctor/item/human_item",
		"file8"    : "/open/doctor/item/human_item",
		"file10"   : "/open/doctor/item/human_item",
		"file2"    : "/open/doctor/item/human_item",
		"file9"    : "/open/doctor/item/human_item",
		"file4"    : "/open/doctor/item/human_item",
		"file3"    : "/open/doctor/item/human_item",
		"amount1"  : 2000,
		"amount7"  : 2000,
		"amount8"  : 2000,
	]) );
	set( "light_up", 1 );
	set( "owner", "skyent" );
	set( "build", 10747 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room598",
		"west"      : "/open/clan/ou-cloud-club/room/room593.c",
		"south"     : "/open/clan/ou-cloud-club/room/room299.c",
	]) );
	set( "long", @LONG
此乃昆崙山上最為出名的三聖草之一$HIR$「$HIG$人靈草$HIR$」$NOR$的囤積之地，
傳說此草可儲存死於$YEL$大地$NOR$中$HIW$屍骸的精華，對於$HIW$病危$NOR$的人，具有$HIR$起死
回生$NOR$之能，但此物須經過醫者精湛的醫術配其特殊內功方可提煉。

LONG);
	setup();
	replace_program(ROOM);
}
