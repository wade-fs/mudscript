inherit ROOM;
void create() {
	set( "short", "紅塵閣二樓" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room96",
		"up"        : "/open/clan/13_luck/room/room135",
	]) );
	set( "long", @LONG

　　從一樓大廳你用絕妙輕功走下來到二樓，以自己十年前的功力，
飛岩走壁已如行平地般自然，何況現在。想想不過莞爾，紅塵居樓層
之間不設梯階剛剛提氣而上真的有走下來的感覺，這裡果真是高手封
塵之處，剛才壁間似有人題字
           
           人若多情  憔悴憔悴...
          　人若無情  活著還有何滋味？
           　不如濁酒紅塵居

LONG);
	setup();
	replace_program(ROOM);
}
