inherit ROOM;
void create() {
	set( "short", "一天門" );
	set( "owner", "poll" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room605",
		"east"      : "/open/clan/13_luck/room/room603",
	]) );
	set( "long", @LONG
從岱宗坊上山大約走四裏，便來到一天門。北面有一座天階坊
，過了此坊便進入了登泰山的盤道。南面有一座更衣亭，士大夫們
及其隨從，都會在這裏換上輕便的服裝，才繼續登山。從一天門向
北眺望，南天門與十八盤在雲霧明滅間或隱或現，登泰山的人到此
已有觀止之嘆。附近有一牌坊，上寫「孔子登臨處」，相傳為「孔
子過泰山側」的故事發生的地方。
LONG);
	setup();
	replace_program(ROOM);
}
