inherit ROOM;
void create() {
	set( "short", "幻世錄故事簡介1" );
	set( "object", ([
		"amount5"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "owner", "dfyw" );
	set( "build", 10056 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room443",
	]) );
	set( "long", @LONG

戰爭--並不是每個人所希望的，
人人都期待和平的降臨，瘸遙不可及，
整個世界擁有人類、獸人、翼人、妖精、兩棲五大種族，
五個種族不論長相、外型、習性、思想和生活方式皆無異，
危一相同的是自我意識、慾望以及無法掩飾得好戰之心。

擁有伊伯爾大陸最大勢力的扥爾斯王國，
其領導者*馬扥爾王*統一長期游封建勢力歌劇的扥爾斯國家。

LONG);
	setup();
	replace_program(ROOM);
}
