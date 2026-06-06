inherit ROOM;
void create() {
	set( "short", "沙灘" );
	set( "owner", "blur" );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room144",
		"west"      : "/open/clan/hell/room/room142.c",
	]) );
	set( "long", @LONG
越過岩石的那一邊到此,發現當初觸礁時的運氣真不是普通的差,此地已經完
全看不到岩石的影子,而是滿地平軟潔白的沙粒,潮退的痕跡清楚的印在沙上形成
一道美麗的弧線,沙岸的北邊似乎有一片防風林,看來不是很容易穿越,往東下去
也是沙岸,東北面更好像隱隱有幾道炊煙在空中飄緲.

LONG);
	setup();
	replace_program(ROOM);
}
