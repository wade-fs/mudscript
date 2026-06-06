inherit ROOM;
void create() {
	set( "short", "遊龍廳" );
	set( "owner", "mill" );
	set( "build", 10130 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room544",
		"south"     : "/open/clan/13_luck/room/room543",
		"west"      : "/open/clan/13_luck/room/room542",
		"east"      : "/open/clan/13_luck/room/room531.c",
	]) );
	set( "long", @LONG

    此廳內檀香撲鼻，華光刺目，一具巨大的水晶虹色琉璃燈垂掛於
頂，炫爛光彩奪目，紫檀木雕龍椅，雙列望外，檜木雙燕三腳几隔在
椅間，一僮一婢隨伺在旁，鯨皮地毯直直往裡鋪設，直至垂紗珠簾之
後，廳內輝煌不可睨，乃真大堂也。

LONG);
	setup();
	replace_program(ROOM);
}
