inherit ROOM;
void create() {
	set( "short", "天樞堂比武場" );
	set( "build", 10483 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room508",
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
