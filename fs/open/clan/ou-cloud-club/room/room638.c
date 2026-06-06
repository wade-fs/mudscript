inherit ROOM;
void create() {
	set( "short", "$HIG$人靈草$NOR$" );
	set( "owner", "skyent" );
	set( "build", 10884 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room637",
		"north"     : "/open/clan/ou-cloud-club/room/room639.c",
		"south"     : "/open/clan/ou-cloud-club/room/room598.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此乃昆崙山上最為出名的三聖草之一$HIR$「$HIG$人靈草$HIR$」$NOR$的囤積之地，
傳說此草可儲存死於$YEL$大地$NOR$中$HIW$屍骸的精華，對於$HIW$病危$NOR$的人，具有$HIR$起死
回生$NOR$之能，但此物須經過醫者精湛的醫術配其特殊內功方可提煉。

LONG);
	setup();
	replace_program(ROOM);
}
