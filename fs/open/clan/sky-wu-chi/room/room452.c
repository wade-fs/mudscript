inherit ROOM;
void create() {
	set( "short", "$HIW$英雄居$NOR$" );
	set( "object", ([
		"amount10" : 1,
		"amount2"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/light-spirit",
		"file2"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"amount3"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"file10"   : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10105 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room451",
	]) );
	set( "long", @LONG

北國風光 千里冰封 萬里雪飄
望長城內外 惟餘莽莽 大河上下 頓失滔滔
山舞銀蛇 原馳蠟象 欲與天公試比高
須晴日 看紅裝素裹 分外妖嬈

江山如此多嬌 引無數英雄競折腰
惜秦皇漢武 略輸文采 唐宗宋祖 稍遜風騷
一代天驕 成吉思汗 只識彎弓射大鵰
俱往矣 數風流人物 還看今朝

LONG);
	setup();
	replace_program(ROOM);
}
