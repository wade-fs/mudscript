inherit ROOM;
void create() {
	set( "short", "蟻窩" );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room167",
		"down"      : "/open/clan/13_luck/room/room191",
	]) );
	set( "long", @LONG

　　洞穴裡工蟻忙進忙出的搬著牠們的勝利品，往裡頭走去，看樣子
似乎是要搬到蟻王巢去給蟻王食用的。血淋淋的動物屍體，血跡一直
往內沿伸，使的空氣中充滿著一股難聞的腥味。突然，好幾隻工蟻充
滿敵意的瞪著你，你感到一股殺氣包圍在你的四周圍。

LONG);
	setup();
	replace_program(ROOM);
}
