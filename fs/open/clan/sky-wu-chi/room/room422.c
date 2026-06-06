inherit ROOM;
void create() {
	set( "short", "$HIW$第$HIR$八$HIW$號當舖$NOR$" );
	set( "owner", "yuki" );
	set( "build", 10264 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room423",
		"east"      : "/open/clan/sky-wu-chi/room/room421.c",
	]) );
	set( "long", @LONG
穿越了暗門經過漫長了路途終於發現了建築物，一看之下竟然是傳
說中的$HIW$第$HIR$八$HIW$號當舖$NOR$心中十分的驚訝，只見到高聳的塔和漆黑的大門，大
門的上方掛著一個古老的匾額，上面寫著第八號當舖，正當你心中遲疑
著是否要踏入這個傳說中能滿足的任何願望的地方，心中傳來一股聲音
告訴著你來吧進來吧！只要你付出因當的典當物你的任何願望都可以達
成，第八號當舖從不食言！
LONG);
	setup();
	replace_program(ROOM);
}
