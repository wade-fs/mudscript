inherit ROOM;
void create() {
	set( "short", "天旋堂修練場" );
	set( "object", ([
		"amount6"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"file5"    : "/obj/gift/xiandan",
		"file7"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"file6"    : "/open/quests/snake/npc/obj/snake_gem",
		"file10"   : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
	]) );
	set( "build", 11245 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room506",
	]) );
	set( "long", @LONG
耳邊傳來的盡是絡繹不絕的吆喝聲，每一個弟子為了能在武林江湖
中揚名立萬每個人莫不辛勤的練習，不管是劍法、拳法、刀法、棍法都
有人在練習，不過你也發現在比武場邊也有幾個累得滿身大汗的弟子坐
在樹蔭下乘涼休息，不過看他們的神情似乎很緊張，看來是怕被發現在
偷懶吧。
LONG);
	setup();
	replace_program(ROOM);
}
