inherit ROOM;
void create() {
	set( "short", "阿涼壽司" );
	set( "owner", "super" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/sspill",
		"amount8"  : 1,
		"amount9"  : 2,
		"amount5"  : 8,
		"file9"    : "/open/mogi/dragon/obj/power",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount10" : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"file8"    : "/open/capital/guard/gring",
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10183 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room129.c",
	]) );
	set( "long", @LONG
豆皮壽司、海苔壽司、味僧湯
這邊的特色就是30鑽石吃到飽
無限暢飲，不醉不歸
還有特製的龍蝦壽司，更是遠近馳名
腔棘魚生魚片也是老饕的最愛
如果你來拜訪涼，一定要留在這兒吃飯的
遠遠望去，排隊的人潮已經延伸到隔壁村
LONG);
	setup();
	replace_program(ROOM);
}
