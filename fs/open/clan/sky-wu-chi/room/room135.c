inherit ROOM;
void create() {
	set( "short", "青兒臥房" );
	set( "light_up", 1 );
	set( "object", ([
		"amount6"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/capital/guard/gring",
		"file10"   : "/open/magic-manor/obj/soil-ball",
		"file1"    : "/open/magic-manor/obj/fire-ball",
		"amount8"  : 1,
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"file9"    : "/open/magic-manor/obj/wood-ball",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/capital/guard/gring",
	]) );
	set( "build", 12000 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room136",
	]) );
	set( "long", @LONG
這裡是空瓶子的夫人『青兒』的臥室，當你一走進這裡時你聞到了
一股清淡的紫羅藍香味，在其臥室中間有一紅木的木雕圓桌，上面放著
一把看似有好長一段歷史的古箏，你撥了一撥箏弦，發出了一陣鏗的聲
音，你頓時覺得那真是一把好琴ㄚ，在看看其牆上掛有一把『寒蒼弓』
似也像有靈性般的發出冰冷的光線。整間房間裡頭有一些花花草草都好
像是你完全沒見過的一樣，讓你感到驚訝萬分。此時你的心裡頭想著空
瓶子的夫人看來也是萬中選一的好女子。

LONG);
	setup();
	replace_program(ROOM);
}
