inherit ROOM;
void create() {
	set( "short", "吉祥池塘" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room431",
		"east"      : "/open/clan/13_luck/room/room6.c",
	]) );
	set( "long", @LONG

    池塘裡的蓮花散發著噗鼻的清香，令人心懭神怡‧步過小橋草地上
滿是百合花草，其中更有幾株奇花異草，似乎使人覺得此處的主人樸實
中隱藏不凡的氣度‧再往北走額面上『綺玉門』三字，是此地主人找尋
全國最好的木工及世界上最優良的檜木所雕刻而成的。

LONG);
	setup();
	replace_program(ROOM);
}
