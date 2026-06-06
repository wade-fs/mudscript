inherit ROOM;
void create() {
	set( "short", "晨之境光明之鎮" );
	set( "object", ([
		"amount6"  : 1,
		"amount3"  : 7,
		"file9"    : "/open/killer/obj/atman_pill",
		"amount10" : 1763,
		"amount8"  : 1,
		"file6"    : "/obj/gift/hobowdan",
		"file3"    : "/obj/stone/jiao",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/doctor/pill/nine_pill",
		"file4"    : "/obj/stone/powder",
		"amount5"  : 1763,
		"amount9"  : 60,
		"file7"    : "/open/doctor/pill/human_pill",
		"file2"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"file5"    : "/open/doctor/pill/taii_pill",
		"amount7"  : 56,
		"amount2"  : 1,
	]) );
	set( "build", 10017 );
	set( "owner", "shinny" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room656.c",
		"west"      : "/open/clan/13_luck/room/room657.c",
		"south"     : "/open/clan/13_luck/room/room57.c",
		"up"        : "/open/clan/13_luck/room/room659",
		"north"     : "/open/clan/13_luck/room/room658.c",
	]) );
	set( "long", @LONG
潺潺的溪水聲從遠方若有似無的慢慢傳來，藉此使你判斷附近應該有水
源。森林中隨著柔風而片片飛舞的紅楓葉，令人覺得有如置身於詩情畫意的
景象之中。身處在紅楓構成的巨大森林內，尋覓著正確道路的你，猶如失魂
般的為四周環境所羈絆。位在這巨大的森林內，彷彿一切都在倒轉著，連匆
匆流逝的時間也離開不了。這裡有一個超大型的魔法陣(battle)，似乎是光
ソ咒文的五十倍擴大陣，讓人不禁打起寒顫來！


LONG);
	setup();
	replace_program(ROOM);
}
