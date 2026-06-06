inherit ROOM;
void create() {
	set( "short", "$BYEL$雷文克勞$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room78.c",
		"north"     : "/open/clan/time-limit/room/room24.c",
		"south"     : "/open/clan/time-limit/room/room183",
	]) );
	set( "long", @LONG
雷文克勞的代表動物是鷹,出身峽谷,公正無私的雷文克勞,創辦了雷文克勞學
院,那裡的人心思敏捷,追求無盡的智慧,機智與好學之士將可以在此找到自己
的同好,雷文克勞只挑選聰明機智的學生,期望她的學生都能以智慧來化解所
面臨的危機

LONG);
	setup();
	replace_program(ROOM);
}
