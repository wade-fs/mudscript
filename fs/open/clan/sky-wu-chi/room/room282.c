inherit ROOM;
void create() {
	set( "short", "白鶴泉" );
	set( "owner", "shih" );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/daemon/class/blademan/obj/shield",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount9"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/obj/gift/hobowdan",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount8"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 11436 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room244",
	]) );
	set( "long", @LONG
相傳從前這裏有一個白鶴泉，它的水清涼甘甜，為此山之最。
這泉水長年湧流不斷，噴出的水象仙鶴撲扇著翅膀洗澡一樣，因以
為名。可惜後來有一個自私自利的小官，獨霸了泉水，後來更因迷
信風水之說，把泉眼堵塞，白鶴泉從此便幹涸了。現在只剩下一座
刻著「白鶴泉」三字的石坊以為紀念。從這裏繼續北上，便是上山
之路。

LONG);
	setup();
	replace_program(ROOM);
}
