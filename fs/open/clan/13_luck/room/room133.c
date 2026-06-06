inherit ROOM;
void create() {
	set( "short", "影火傲" );
	set( "owner", "mill" );
	set( "object", ([
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount3"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10059 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room134.c",
		"east"      : "/open/clan/13_luck/room/room72",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    傲氣霸天，影火隨行。眼前的八大字，充滿了超乎常人的傲氣，周圍
的氣息有如這八大字般產生了一股威影名名的振奮精神的空氣，光是站在
這，就讓人覺得似乎世上並沒有任何一件事可以難得倒你，心裡面一直重
覆著一個聲音，我要不斷修練，成為世上首屈一指的強人。


LONG);
	setup();
	replace_program(ROOM);
}
