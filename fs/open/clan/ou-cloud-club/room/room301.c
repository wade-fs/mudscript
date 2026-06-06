inherit ROOM;
void create() {
	set( "short", "$HIG$天靈草$NOR$" );
	set( "object", ([
		"file2"    : "/open/doctor/item/sky_item",
		"amount8"  : 2000,
		"amount2"  : 2000,
		"file5"    : "/open/doctor/item/sky_item",
		"amount1"  : 2000,
		"amount4"  : 2000,
		"file10"   : "/open/doctor/item/sky_item",
		"file3"    : "/open/doctor/item/sky_item",
		"file8"    : "/open/doctor/item/sky_item",
		"amount5"  : 2000,
		"file6"    : "/open/doctor/item/sky_item",
		"amount9"  : 2000,
		"amount6"  : 2000,
		"file1"    : "/open/doctor/item/sky_item",
		"file4"    : "/open/doctor/item/sky_item",
		"amount7"  : 2000,
		"file7"    : "/open/doctor/item/sky_item",
		"file9"    : "/open/doctor/item/sky_item",
		"amount3"  : 2000,
		"amount10" : 2000,
	]) );
	set( "owner", "skyent" );
	set( "build", 10028 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room297.c",
		"east"      : "/open/clan/ou-cloud-club/room/room300.c",
		"north"     : "/open/clan/ou-cloud-club/room/room594",
	]) );
	set( "long", @LONG
此乃昆崙山上最為出名的三聖草之一$HIR$「$HIG$天靈草$HIR$」$NOR$的囤積之地，
傳說此草盡吸$HIC$天地$NOR$之$HIM$靈氣$NOR$，對於身受內創的人，能將其所受的內創
完全消除，但此物須經過醫者精湛的醫術配其特殊內功方可提煉。

LONG);
	setup();
	replace_program(ROOM);
}
