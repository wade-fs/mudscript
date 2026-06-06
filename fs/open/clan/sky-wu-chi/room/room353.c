inherit ROOM;
void create() {
	set( "short", "世界末日" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "object", ([
		"file7"    : "/open/killer/outsea/dstone",
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"file6"    : "/open/capital/guard/gring",
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"file8"    : "/open/capital/room/king/obj/km-cloak",
		"amount10" : 1,
		"file9"    : "/open/wu/npc/obj/armband",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 10692 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room278",
	]) );
	set( "long", @LONG
想笑 來偽裝掉下的眼淚 點點頭 承認自己會怕黑 
我只求 能借一點的時間來陪 你卻連同情都不給 ;想哭 來試探自己麻痹了沒 全世界 好象只有我疲憊 ;無所謂 反正難過就敷衍走一回 但願絕望和無奈遠走高飛 ;天灰灰 會不會 讓我忘了你是誰 ;夜越黑 夢違背 難追難回味 ;我的世界將被摧毀 也許事與願違 ;累不累 睡不睡 單影無人相依偎 ;夜越黑 夢違背 有誰肯安慰 ;我的世界將被摧毀 或許頹廢也是另一種美 ;天灰灰 會不會 讓我入睡 夜越黑 夢違背 有誰安慰
LONG);
	setup();
	replace_program(ROOM);
}
