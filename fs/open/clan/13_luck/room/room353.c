inherit ROOM;
void create() {
	set( "short", "正廳" );
	set( "owner", "kaien" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/mon/obj/ghost-claw",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room349",
		"south"     : "/open/clan/13_luck/room/room352.c",
	]) );
	set( "build", 10884 );
	set( "light_up", 1 );
	set( "long", @LONG

    廳門口掛著一塊橫匾，上書「鐵面無私」四個大字，看來還是御筆
親書。幾個家將站立兩旁。秦將軍坐在當中的太師椅上，不怒自威。看
到你進來，他對你點頭笑了笑。將軍就很威武的坐在那，不發一語因為
沒有人說話，廳上的氣氛很嚴肅。

LONG);
	setup();
	replace_program(ROOM);
}
