inherit ROOM;
void create() {
	set( "short", "$HIG$藥材囤積室$NOR$" );
	set( "owner", "skyent" );
	set( "build", 10473 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room641.c",
		"north"     : "/open/clan/ou-cloud-club/room/room646",
		"south"     : "/open/clan/ou-cloud-club/room/room635.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
大內御醫〔$HIW$風$HIR$火$HIM$山$HIG$林$NOR$〕放置藥材的所在，也是傲雲山莊內
的重要機秘地點，據江湖上流傳，風火山林乃當今武林醫術最
高的一人，只因他備有許多的神奇秘藥，也因此遭受到武林上
所有同好的眼紅，而他的秘藥藥材據說藏在此處，但入眼所見
並沒有任何奇特之物．

LONG);
	setup();
	replace_program(ROOM);
}
