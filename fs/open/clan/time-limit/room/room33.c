inherit ROOM;
void create() {
	set( "short", "$BGRN$溫$BBLU$室$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room60",
	]) );
	set( "long", @LONG
溫室裡到處長滿植物,而這些都是魔藥的基本藥草,除了給醫院使用外,
也能提供學生上魔藥學時使用,更可以教導學生學習藥草的名稱與特性,
芽菜教授帶領一群學生在幫魔蘋果換盆,學生們全都帶起耳罩,用力的
將魔蘋果從盆裡拉出來,馬上聽到尖銳的叫聲,還有個學生被嚇暈了!

LONG);
	setup();
	replace_program(ROOM);
}
