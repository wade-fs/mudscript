inherit ROOM;
void create() {
	set( "short", "煙雨樓" );
	set( "build", 57 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room40.c",
		"up"        : "/open/clan/13_luck/room/room53.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

                                煙雨樓
          
    水泠泠，兩岸斜橋煙澤。柳陰舟渡縈古堰，少年空數日昨。月沉笛緲波浪綠，寺
樓鐘響碧山泊。照影檀郎，年年誰喚，雁飛天遠飲寂寞。倚樓望去荷鴛睡，還羨藕中
雀。驚鴻四更春雨作，蕩蕩雷魄。 

    棹歌夜船魚躍戲，晚來星亮風綽。玉纖遙指蒹葭深處，漫漫伊人水雲閣？暗裡回
眸，情深逐賦，相思愁似萬重幕。待曦起瞰南景，行曲且歌託。銷魂處覺荳蔻香，夢
裡花落。 

LONG);
	setup();
	replace_program(ROOM);
}
