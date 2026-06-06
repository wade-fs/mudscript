inherit ROOM;
void create() {
	set( "short", "金字塔密室" );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room115",
	]) );
	set( "long", @LONG
你被傳送到密室裡來,前方有著炫目的金光不斷傳來,你興奮的衝向前,卻有著一面石門擋住你
的去路,你用力一推,發現無法以外力打開它,仔細搜索後發現有著太陽(sun),月亮(moon)和星
星(star)的圖案,難道這就是開啟石門的關鍵嗎

LONG);
	setup();
	replace_program(ROOM);
}
