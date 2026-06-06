inherit ROOM;
void create() {
	set( "short", "$HIW$霧$HIM$谷$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room196",
	]) );
	set( "long", @LONG
霧谷裡四周都是濃霧,伸手不見五指,一不小心就會撞上石壁,你不禁抱怨起有誰會住在這
種鬼地方,但是心念一轉,這不也是個藏身的好地方嗎,能夠避開仇家的追殺,聽說魔域大
將千里不留行叛逃多年,始終沒人能找到他,難道就藏身在霧谷裡,一位老人從前方走來
,親切地詢問你是否迷路,並將你帶到入口處,這慈祥的老人會是殺人不眨眼的千里不留行
嗎?真是難以想像

LONG);
	setup();
	replace_program(ROOM);
}
