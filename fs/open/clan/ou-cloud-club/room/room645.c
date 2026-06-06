inherit ROOM;
void create() {
	set( "short", "$HIG$天靈草$NOR$" );
	set( "build", 10740 );
	set( "owner", "skyent" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room644.c",
		"west"      : "/open/clan/ou-cloud-club/room/room646.c",
		"south"     : "/open/clan/ou-cloud-club/room/room641",
	]) );
	set( "long", @LONG
此乃昆崙山上最為出名的三聖草之一$HIR$「$HIG$天靈草$HIR$」$NOR$的囤積之地，
傳說此草盡吸$HIC$天地$NOR$之$HIM$靈氣$NOR$，對於身受內創的人，能將其所受的內創
完全消除，但此物須經過醫者精湛的醫術配其特殊內功方可提煉。

LONG);
	setup();
	replace_program(ROOM);
}
