inherit ROOM;
void create() {
	set( "short", "天涯" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"amount5"  : 2,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file7"    : "/open/killer/obj/atman_pill",
		"amount2"  : 134,
		"amount6"  : 256,
		"amount8"  : 47,
		"amount3"  : 155,
		"amount7"  : 104,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount1"  : 139,
		"amount4"  : 10,
		"file5"    : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 11341 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/nine-sky-dragon/room/room20",
		"north"     : "/open/clan/nine-sky-dragon/room/room14",
	]) );
	set( "long", @LONG
昏天又暗地 忍不住的流星 燙不傷被冷藏一顆死心
苦苦的追尋 茫茫然失去 可愛的 可恨的 多可惜
夢中的夢中 夢中人的夢中 夢不到被吹散往事如風
空空的天空 容不下笑容 傷神的 傷人的 太傷心
何必想 何必問 何處是我家 愛也罷 算了吧 問天涯
望斷了天涯 贏得了天下 輸了她
夢中的夢中 夢中人的夢中 夢不到被吹散往事如風
空空的天空 容不下笑容 傷神的 傷人的 太傷心
也掙扎 也牽掛 也不是辦法 走也罷 留也罷 錯了嗎
今天涯 明天又天涯 狠狠一巴掌忘了吧
揮別的種種 揮不去的種種 毀不了被淹沒一往情深
忍已無可忍 恨不得別人 害人的 迷人的 痴情人
也掙扎 也牽掛 也不是辦法 走也罷 留也罷 錯了嗎
今天涯 明天又天涯 狠狠一巴掌忘了吧

LONG);
	setup();
	replace_program(ROOM);
}
