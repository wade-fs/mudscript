inherit ROOM;
void create() {
	set( "short", "$HIG$地靈草$NOR$" );
	set( "owner", "skyent" );
	set( "build", 10393 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room639.c",
		"north"     : "/open/clan/ou-cloud-club/room/room644",
		"west"      : "/open/clan/ou-cloud-club/room/room641.c",
		"south"     : "/open/clan/ou-cloud-club/room/room637.c",
	]) );
	set( "long", @LONG
此乃昆崙山上最為出名的三聖草之一$HIR$「$HIG$地靈草$HIR$」$NOR$的囤積之地，
傳說此草盡吸$YEL$大地$NOR$之$HIW$精華$NOR$，對於身受毒害之人，能將其所受的$HIM$百毒$NOR$
完全消除，但此物須經過醫者精湛的醫術配其特殊內功方可提煉。

LONG);
	setup();
	replace_program(ROOM);
}
