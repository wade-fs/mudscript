inherit ROOM;
void create() {
	set( "short", "指令測試房" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/new_heaven/room/room9",
		"south"     : "/open/clan/new_heaven/room/room4",
	]) );
	set( "long", @LONG
    這裡是祈晴娃娃的工作室, 裡面擺著他心愛的長古川 天
的大照片,還有一部大電腦, 聽說可以看看舊的狂想的檔案,
是個不錯的設備,不過進來得要梅絳雪允許喔,因為梅絳雪最
討厭有人隨便進祈晴娃娃的房間了。
新增加檢舉(accuse)功能, 如果你覺得有人在run tin你可以用
accuse <id>來把他送去冰判官那去問問題。

LONG);
	setup();
	replace_program(ROOM);
}
