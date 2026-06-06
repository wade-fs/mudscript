inherit ROOM;
void create() {
	set( "short", "我是一隻魚" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount10" : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10659 );
	set( "exits", ([
		"up"        : "/open/clan/nine-sky-dragon/room/room20.c",
		"west"      : "/open/clan/nine-sky-dragon/room/room31.c",
		"east"      : "/open/clan/nine-sky-dragon/room/room32.c",
		"north"     : "/open/clan/nine-sky-dragon/room/room33.c",
		"south"     : "/open/clan/nine-sky-dragon/room/room34",
	]) );
	set( "long", @LONG
可不可以不想你 我需要振作一下
7 8 9 月的天氣 像我和你需要一場雨
需要你 我是一隻魚
水裡的空氣 是你小心眼和壞脾氣
沒有你 像離開水的魚
快要活不下去 不能在一起游來游去
能不能讓你清醒 愛是快樂的事情
我只有真心而已 世界末日我都不會離去
為什麼不能在一起 我是一隻站在岸上的魚
如何能忘記曾經活在海裡 曾經你活在我的生命
LONG);
	setup();
	replace_program(ROOM);
}
