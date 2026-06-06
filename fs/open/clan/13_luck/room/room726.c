inherit ROOM;
void create() {
	set( "short", "武林大會中" );
	set( "owner", "tomorrow" );
	set( "object", ([
		"file5"    : "/obj/stone/jiao",
		"amount1"  : 700,
		"file3"    : "/open/mon/obj/mon-pill",
		"amount2"  : 65,
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount8"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 1,
		"amount5"  : 2,
		"file1"    : "/open/fire-hole/obj/k-pill",
		"file6"    : "/obj/gift/unknowdan",
		"amount3"  : 204,
	]) );
	set( "build", 10111 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room736",
		"south"     : "/open/clan/13_luck/room/room581",
	]) );
	set( "long", @LONG
掃地僧說道 阿彌陀佛~就讓天下罪業歸我吧!統統過來讓老衲一掌拍死，老僧趕著回去掃地!
獨孤求敗說道 老禿驢..當真要動手嗎?你還不夠格讓老子歡喜不盡咧!有種把破綻露出來啊!
石破天說道 晚輩現在試演俠客行武功，有膽就來邀戰，沒膽的站遠點免得被掌風給震酥了!
東方不敗說道 蓮亭啊~你明知道我不喜歡見人，還拉我這來做什麼??..啊!那壯漢好MAN吶!
金輪法王說道 嘿..幸虧今天在場都是生面孔，老夫苦練的龍象般若功總算可以天下無敵啦!
王重陽說道 師弟說最近江湖上出了不少硬爪子，但本人就不信有誰能比家裡那婆子還潑辣?


LONG);
	setup();
	replace_program(ROOM);
}
