inherit ROOM;
void create() {
	set( "short", "煙雨樓十樓" );
	set( "build", 57 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room97.c",
		"east"      : "/open/clan/13_luck/room/room118.c",
		"down"      : "/open/clan/13_luck/room/room90.c",
		"west"      : "/open/clan/13_luck/room/room113.c",
		"south"     : "/open/clan/13_luck/room/room723",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官歡迎您來到煙雨樓十樓，您所定下的廂房已經清理乾淨了。
從房內的窗戶往外看可以將十三吉祥的全貌盡收眼底，從這終於可以
看清楚北方的宮殿，藍色的屋簷多麼美麗，從天上還有一道白色的光
線攏照著此宮殿，想必這一定是十三吉祥的總壇了。

LONG);
	setup();
	replace_program(ROOM);
}
