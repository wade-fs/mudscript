inherit ROOM;
void create() {
	set( "short", "『大牢入口』" );
	set( "build", 24 );
	set( "owner", "joy" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room446",
		"south"     : "/open/clan/13_luck/room/room444",
	]) );
	set( "long", @LONG

     你走著走著發現這裡的燈光明顯的比前面暗很多，透露著一股陰冷黑暗
 的感覺，地上偶而有一兩隻老鼠跑過，更添其詭異的氣氛，旁邊的石牌寫著
 「墨教大牢」四個大字，原來這是墨教的大牢，只要觸犯規定經過執法堂決
 定為情節重大者，都必需被關到這裡，越裡面越是不見天日，表示情節重大
 ，你心想，自己可千不萬不能道此處來。

LONG);
	setup();
	replace_program(ROOM);
}
