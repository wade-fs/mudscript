inherit ROOM;
void create() {
	set( "short", "$HIB$千$HIG$邪$HIM$洞$NOR$" );
	set( "build", 10804 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room197",
	]) );
	set( "long", @LONG
原本是和血林及骷髏堡同為武林三大死境的千邪洞,由於主人蔭屍人的式微,如今成為秦
假仙的藏寶庫,不過千邪洞也曾經發生過大事件,事件之一就是秦假仙利用空城計智退鬼
王棺,另一事件就是一頁書在千邪洞內回復肉身,親手解決罪魁燈蝶修萬年,不過現在已為
人淡忘,而且秦假仙設計機關來保護寶物,已沒有人會來到千邪洞了

LONG);
	setup();
	replace_program(ROOM);
}
