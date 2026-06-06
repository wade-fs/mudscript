inherit ROOM;
void create() {
	set( "short", "朝聖之路" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room58",
	]) );
	set( "long", @LONG
    這是一條筆直的長廊，四周充斥著明亮的聖火，沿途的牆壁上刻滿著
        各式各樣封魔的武功以及紀錄歷來神魔大戰的重要記事，而經由詳細
        的紀錄中發現，歷來成功除魔的勇者都是依賴神聖的裝備或道具，因
        人類很少有能夠完全修練完整的神之技能。
LONG);
	setup();
	replace_program(ROOM);
}
