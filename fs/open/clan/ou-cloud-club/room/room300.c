inherit ROOM;
void create() {
	set( "short", "$HIG$地靈草$NOR$" );
	set( "object", ([
		"amount2"  : 2000,
		"amount3"  : 2000,
		"file1"    : "/open/doctor/item/ground_item",
		"file10"   : "/open/doctor/item/ground_item",
		"file6"    : "/open/doctor/item/ground_item",
		"file2"    : "/open/doctor/item/ground_item",
		"amount10" : 2000,
		"amount1"  : 2000,
		"amount7"  : 2000,
		"file4"    : "/open/doctor/item/ground_item",
		"amount9"  : 2000,
		"file8"    : "/open/doctor/item/ground_item",
		"file3"    : "/open/doctor/item/ground_item",
		"amount5"  : 2000,
		"file5"    : "/open/doctor/item/ground_item",
		"amount6"  : 2000,
		"amount4"  : 2000,
		"file7"    : "/open/doctor/item/ground_item",
		"file9"    : "/open/doctor/item/ground_item",
		"amount8"  : 2000,
	]) );
	set( "owner", "skyent" );
	set( "build", 10416 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room301.c",
		"east"      : "/open/clan/ou-cloud-club/room/room299.c",
		"north"     : "/open/clan/ou-cloud-club/room/room593",
	]) );
	set( "long", @LONG
此乃昆崙山上最為出名的三聖草之一$HIR$「$HIG$地靈草$HIR$」$NOR$的囤積之地，
傳說此草盡吸$YEL$大地$NOR$之$HIW$精華$NOR$，對於身受毒害之人，能將其所受的$HIM$百毒$NOR$
完全消除，但此物須經過醫者精湛的醫術配其特殊內功方可提煉。

LONG);
	setup();
	replace_program(ROOM);
}
