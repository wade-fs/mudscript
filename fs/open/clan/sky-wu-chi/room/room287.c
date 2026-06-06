inherit ROOM;
void create() {
	set( "short", "小花園" );
	set( "owner", "yuki" );
	set( "light_up", 1 );
	set( "build", 10361 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room122",
	]) );
	set( "long", @LONG
這裡是一個小花園種滿了鮮花和樹木，充滿了芬芳的味道令人不經想
多呆這裡一會，中間還有個小水塘裡面還有幾隻天鵝正在游水令人賞心悅
目，這裡的主人看起來很愛這個地方，把它們照顧的很好很漂亮，陽光透
過葉縫灑在你的身上暖洋洋的不禁讓你想打個盹！
LONG);
	setup();
	replace_program(ROOM);
}
