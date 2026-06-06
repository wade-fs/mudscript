inherit ROOM;
void create() {
	set( "short", "$HIG$藥材囤積室$NOR$" );
	set( "object", ([
		"amount5"  : 2000,
		"file7"    : "/open/doctor/item/ff_item",
		"amount3"  : 2000,
		"amount1"  : 2000,
		"amount10" : 2000,
		"file3"    : "/open/doctor/item/sick_item",
		"amount6"  : 2000,
		"amount9"  : 2000,
		"amount7"  : 2000,
		"file4"    : "/open/doctor/item/sick_item",
		"file2"    : "/open/doctor/item/sick_item",
		"file9"    : "/open/doctor/item/ff_item",
		"file8"    : "/open/doctor/item/ff_item",
		"file5"    : "/open/doctor/item/ff_item",
		"amount8"  : 2000,
		"amount2"  : 2000,
		"file6"    : "/open/doctor/item/sick_item",
		"file10"   : "/open/doctor/item/ff_item",
		"file1"    : "/open/doctor/item/sick_item",
		"amount4"  : 2000,
	]) );
	set( "build", 19095 );
	set( "light_up", 1 );
	set( "owner", "skyent" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room596",
		"down"      : "/open/clan/ou-cloud-club/room/room209",
		"east"      : "/open/clan/ou-cloud-club/room/room301.c",
	]) );
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
