inherit ROOM;
void create() {
	set( "short", "停˙屍˙間" );
	set( "owner", "scsii" );
	set( "object", ([
		"file4"    : "/obj/gift/lingzhi",
		"amount9"  : 561,
		"amount2"  : 101,
		"file2"    : "/obj/stone/powder",
		"amount3"  : 1,
		"file3"    : "/obj/stone/jiao",
		"file1"    : "/obj/stone/suipian",
		"amount1"  : 9,
		"amount4"  : 1,
		"file9"    : "/open/doctor/pill/ice_pill",
	]) );
	set( "build", 10047 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room53",
		"north"     : "/open/clan/13_luck/room/room655",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
一股腥臭的味道撲鼻而來，環顧四周，盡是殘缺的屍塊，當中包
含了黃金甲龍的精元，焚天魔王的人頭，舞風揚的心臟，神秘飛賊的
雙手，火龍王的鱗片，火龜的殼。正當你看的出神，忽然！你發現有
個完整的屍體躺臥在你腳邊，你一看，就是你自己！嚇的你當場連尿
都飆出來了，結果你無法接受這樣的事實，當場昏死了過去！

你的眼前一黑﹐接著什麼也不知道了....





LONG);
	setup();
	replace_program(ROOM);
}
