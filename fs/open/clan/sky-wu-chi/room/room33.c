inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$EQ室二$NOR$" );
	set( "owner", "salicili" );
	set( "build", 12555 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room24.c",
		"east"      : "/open/clan/sky-wu-chi/room/room99",
	]) );
	set( "long", @LONG

乘著風　遊盪在籃天邊　一片雲掉落在我面前;捏成你的形狀　隨風跟著我　一口一口吃掉憂愁;;載著你　彷彿載著陽光　不管到哪裡都是晴天;蝴蝶自在飛　花也佈滿天　一朵一朵因你而香;試圖讓夕陽飛翔　帶領你我環繞大自然;迎著風　開始共渡每一天;;手牽手　一步兩步三步四步　望著天;看星星　一顆兩顆三顆四顆　連成線;;背對背默默許下心願;看遠方的星是否聽的見;;手牽手　一步兩步三步四步　望著天;看星星　一顆兩顆三顆四顆　連成線;背對背默默許下心願;看遠方的星如果聽的見;它一定實現

LONG);
	setup();
	replace_program(ROOM);
}
