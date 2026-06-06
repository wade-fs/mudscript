inherit ROOM;
void create() {
	set( "short", "$HIY$陰間金紙存放處$NOR$" );
	set( "object", ([
		"amount3"  : 4,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 1,
		"file1"    : "/open/killer/headkill/obj/e_dag",
		"file2"    : "/open/killer/obj/dagger",
		"amount2"  : 1,
	]) );
	set( "owner", "neun" );
	set( "build", 12306 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/hall",
	]) );
	set( "long", @LONG
這裡是地府的大鬼中鬼小鬼們放金紙的地方,仔細看四周的牆壁,全都是用紙
錢做成的,地府的金庫就在此處,如果想要死的時候過的快樂點,就沒事過來捐點
錢吧,閻羅王收夠了錢自然會多關照你的,可別想從這偷錢喔,逃到地獄也會把你
偷的錢追回來的

LONG);
	setup();
	replace_program(ROOM);
}
