inherit ROOM;
void create() {
	set( "short", "種族及國家1" );
	set( "object", ([
		"file3"    : "/obj/gift/xiandan",
		"file4"    : "/obj/gift/xiandan",
		"file5"    : "/obj/gift/xiandan",
		"file9"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"amount2"  : 1,
		"file10"   : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount10" : 1,
		"file6"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xiandan",
		"file2"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "dfyw" );
	set( "build", 10041 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room437.c",
		"east"      : "/open/clan/13_luck/room/room438.c",
		"north"     : "/open/clan/13_luck/room/room439.c",
		"up"        : "/open/clan/13_luck/room/room368",
		"south"     : "/open/clan/13_luck/room/room436",
	]) );
	set( "long", @LONG

被神所眷戀得大地、依著不同祝福，創照了五個種族。祈願能和平共存，互助
互利。

伊伯爾大陸上常見的種族，幾乎可以在任何一個角落看到人類對其他種族而言，
人類是一種唯利是圖的生物，他們幾乎將個人的需求當成了一切。

扥爾斯王國
數百年歷史的人類王國。十幾年前，正統王儲馬扥爾發動戰爭，誅殺所有王室兄
弟，奪回王位後，遂向獸人國家弗雷斯特發動侵略戰爭。

LONG);
	setup();
	replace_program(ROOM);
}
