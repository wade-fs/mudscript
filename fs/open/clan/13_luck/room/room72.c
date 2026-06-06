inherit ROOM;
void create() {
	set( "short", "狂人居" );
	set( "owner", "mill" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room133",
	]) );
	set( "object", ([
		"amount7"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount3"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"amount10" : 1,
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
	]) );
	set( "item_desc", ([
		"n" : @ITEM
,
ITEM,
	]) );
	set( "build", 10643 );
	set( "light_up", 1 );
	set( "long", @LONG

    往前一走，你發現眼前一亮，四周大火雄雄燃起，已經不能再往前
了。但在大火之中好像有個坐立其中，往四周一看在石壁上刻著種種心
法，分別有一到十層的心法，難道這是震古曜今的渾天心法，難不成這
個男人是百年前的聖火狂人，但看起來卻又那麼年輕，種種疑問浮上了
心頭。

LONG);
	setup();
	replace_program(ROOM);
}
