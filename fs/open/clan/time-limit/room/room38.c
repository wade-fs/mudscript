inherit ROOM;
void create() {
	set( "short", "$HIR$符咒學$HIC$教室$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room61",
	]) );
	set( "long", @LONG
符咒學是學生最喜愛的一門學科,因為在課堂上可以學到很多有趣又好用
的魔法,學生們正在練習飄浮咒,成功的話就可以讓物品飄浮在半空中,
這對需要搬運重物的人可是一大福音,但是魔法部有規定未成年的巫師
不得在外界使用魔法,只限於在學校內使用,讓學生們抱怨不已

LONG);
	setup();
	replace_program(ROOM);
}
