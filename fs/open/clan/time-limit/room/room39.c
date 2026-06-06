inherit ROOM;
void create() {
	set( "short", "$BRED$四年級$BGRN$黑魔法$BBLU$防禦課$BMAG$教室$NOR$" );
	set( "owner", "wateribbon" );
	set( "object", ([
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10244 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room58",
	]) );
	set( "long", @LONG
四年級生的黑魔法防禦術是由穆敵教授來教導,他曾是魔法世界最有名的正氣師,
也就是負責追補黑巫師的人,退休後被鄧不利多延攬到學校教書,他擅長教授黑魔咒,
曾有一次在課堂上當著學生面前施展不赦咒,不赦咒包括蠻橫咒.酷刑咒及索命咒,
只要對麻瓜施展任何一個咒語,就足以讓人在阿茲卡班待上一輩子

LONG);
	setup();
	replace_program(ROOM);
}
