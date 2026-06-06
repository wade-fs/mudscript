inherit ROOM;
void create() {
	set( "short", "$HIG$天靈草$NOR$" );
	set( "object", ([
		"amount4"  : 2000,
		"file4"    : "/open/doctor/item/sky_item",
		"amount8"  : 2000,
		"file9"    : "/open/doctor/item/sky_item",
		"amount3"  : 2000,
		"amount10" : 1053,
		"file10"   : "/open/doctor/item/sky_item",
		"amount9"  : 2000,
		"file8"    : "/open/doctor/item/sky_item",
		"file5"    : "/open/doctor/item/sky_item",
		"file7"    : "/open/doctor/item/sky_item",
		"amount2"  : 2000,
		"file6"    : "/open/doctor/item/sky_item",
		"amount6"  : 2000,
		"amount7"  : 2000,
		"file2"    : "/open/doctor/item/sky_item",
		"file3"    : "/open/doctor/item/sky_item",
		"amount5"  : 2000,
		"amount1"  : 2000,
		"file1"    : "/open/doctor/item/sky_item",
	]) );
	set( "owner", "skyent" );
	set( "build", 10022 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room636",
		"west"      : "/open/clan/ou-cloud-club/room/room597",
		"south"     : "/open/clan/ou-cloud-club/room/room594.c",
		"east"      : "/open/clan/ou-cloud-club/room/room599.c",
	]) );
	set( "long", @LONG
此乃昆崙山上最為出名的三聖草之一$HIR$「$HIG$天靈草$HIR$」$NOR$的囤積之地，
傳說此草盡吸$HIC$天地$NOR$之$HIM$靈氣$NOR$，對於身受內創的人，能將其所受的內創
完全消除，但此物須經過醫者精湛的醫術配其特殊內功方可提煉。

LONG);
	setup();
	replace_program(ROOM);
}
