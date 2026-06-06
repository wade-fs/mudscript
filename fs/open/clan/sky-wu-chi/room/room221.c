inherit ROOM;
void create() {
	set( "short", "$HIC$達摩室$NOR$" );
	set( "object", ([
		"amount4"  : 50,
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"file2"    : "/open/snow/obj/figring",
		"amount3"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount6"  : 19,
		"file4"    : "/open/killer/obj/bellstar",
		"file1"    : "/open/killer/memory/static",
		"amount1"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/obj/fire-ball",
	]) );
	set( "build", 10223 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room271.c",
		"east"      : "/open/clan/sky-wu-chi/room/room246.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
 穿過門簾來到一間寂靜的空曠密室，牆上掛著一幅達摩祖師的面壁畫像
 ，莊嚴的氣息佈滿四周，一個英俊挺拔的劍士盤膝打坐於密室中央，一副慈
 祥的面容彷彿靈魂早已出竅悠遊於九天雲外，如果你對修禪有所興趣，或許
 可以就地打坐，等待劍士醒來再跟他請教一番。

LONG);
	setup();
	replace_program(ROOM);
}
