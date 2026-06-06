inherit ROOM;
void create() {
	set( "short", "桃花江" );
	set( "owner", "asfd" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room84.c",
		"east"      : "/open/clan/13_luck/room/room262.c",
	]) );
	set( "long", @LONG

    桃花江畔，桃花劫，這個對子在這個桃花島上是赫赫有名的詞句，當
年的桃花島主，更把此處設為禁地不準任何人走進來，傳說這裡到半夜的
時後，隱隱會聽到有人哭泣的聲音，難道就有如此江之名般，有人為了桃
花劫的關係，被詛咒於此地，終身不能離開，所以只能夜夜哭泣。

LONG);
	setup();
	replace_program(ROOM);
}
