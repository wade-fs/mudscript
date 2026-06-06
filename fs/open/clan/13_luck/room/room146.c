inherit ROOM;
void create() {
	set( "short", "劍不離身" );
	set( "object", ([
		"amount4"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount8"  : 1,
		"file8"    : "/open/prayer/obj/boris-boots",
		"file6"    : "/daemon/class/blademan/obj/shield",
		"file7"    : "/open/prayer/obj/boris-hat",
		"file4"    : "/daemon/class/fighter/figring",
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount1"  : 1,
		"file2"    : "/daemon/class/fighter/figring",
		"amount3"  : 1,
		"amount10" : 1,
		"file3"    : "/open/capital/guard/gring",
		"amount9"  : 6,
		"amount5"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "build", 10191 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room98",
		"enter"     : "/open/clan/13_luck/room/room145",
	]) );
	set( "long", @LONG
畫中一條大漢身負寶劍，單掌斜立，護住門面，含胸拔
背，氣凝如嶽，這便是甘溫拿年輕時，行走江湖習武所留之
自畫像；劍不出鞘，寶劍一出，便得嗜血方休，因此造了不
少殺業；十年前，被武林中邀齊的十大高手所敗，在此閉關
不出，立誓要苦思出一門當世無人能敵之劍法。

LONG);
	setup();
	replace_program(ROOM);
}
