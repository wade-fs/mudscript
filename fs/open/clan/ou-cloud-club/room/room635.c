inherit ROOM;
void create() {
	set( "short", "$HIG$藥材囤積室$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file9"    : "/open/doctor/item/sick_item",
		"file7"    : "/open/doctor/item/ff_item",
		"amount6"  : 2000,
		"amount9"  : 45,
		"file4"    : "/open/doctor/item/sick_item",
		"file3"    : "/open/killer/memory/static",
		"amount4"  : 2000,
		"amount5"  : 2000,
		"file6"    : "/open/doctor/item/sick_item",
		"amount8"  : 2000,
		"file5"    : "/open/doctor/item/sick_item",
		"file8"    : "/open/doctor/item/sick_item",
		"amount1"  : 1,
		"amount3"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"file2"    : "/open/killer/memory/static",
		"amount7"  : 1093,
	]) );
	set( "owner", "skyent" );
	set( "build", 12426 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room636",
		"north"     : "/open/clan/ou-cloud-club/room/room642.c",
		"south"     : "/open/clan/ou-cloud-club/room/room597.c",
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
