inherit ROOM;
void create() {
	set( "short", "$HIG$地靈草$NOR$" );
	set( "object", ([
		"amount1"  : 1108,
		"file1"    : "/open/doctor/item/ground_item",
	]) );
	set( "owner", "skyent" );
	set( "build", 11235 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room638",
		"north"     : "/open/clan/ou-cloud-club/room/room640.c",
		"west"      : "/open/clan/ou-cloud-club/room/room636.c",
		"south"     : "/open/clan/ou-cloud-club/room/room599.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此乃昆崙山上最為出名的三聖草之一$HIR$「$HIG$地靈草$HIR$」$NOR$的囤積之地，
傳說此草盡吸$YEL$大地$NOR$之$HIW$精華$NOR$，對於身受毒害之人，能將其所受的$HIM$百毒$NOR$
完全消除，但此物須經過醫者精湛的醫術配其特殊內功方可提煉。

LONG);
	setup();
	replace_program(ROOM);
}
