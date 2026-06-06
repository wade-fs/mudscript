inherit ROOM;
void create() {
	set( "short", "$HIG$人靈草$NOR$" );
	set( "object", ([
		"file7"    : "/open/doctor/item/human_item",
		"amount7"  : 2000,
		"file8"    : "/open/doctor/item/human_item",
		"amount2"  : 2000,
		"amount5"  : 2000,
		"file1"    : "/open/doctor/item/human_item",
		"amount3"  : 2000,
		"file10"   : "/open/doctor/item/human_item",
		"amount1"  : 2000,
		"amount6"  : 2000,
		"file5"    : "/open/doctor/item/human_item",
		"amount8"  : 2000,
		"file6"    : "/open/doctor/item/human_item",
		"amount10" : 2000,
		"file3"    : "/open/doctor/item/human_item",
		"amount4"  : 2000,
		"file9"    : "/open/doctor/item/human_item",
		"amount9"  : 2000,
		"file2"    : "/open/doctor/item/human_item",
		"file4"    : "/open/doctor/item/human_item",
	]) );
	set( "owner", "skyent" );
	set( "light_up", 1 );
	set( "build", 10178 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room300.c",
		"north"     : "/open/clan/ou-cloud-club/room/room595",
	]) );
	set( "long", @LONG
此乃昆崙山上最為出名的三聖草之一$HIR$「$HIG$人靈草$HIR$」$NOR$的囤積之地，
傳說此草可儲存死於$YEL$大地$NOR$中$HIW$屍骸的精華，對於$HIW$病危$NOR$的人，具有$HIR$起死
回生$NOR$之能，但此物須經過醫者精湛的醫術配其特殊內功方可提煉。

LONG);
	setup();
	replace_program(ROOM);
}
