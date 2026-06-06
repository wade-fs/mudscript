inherit ROOM;
void create() {
	set( "short", "魔劍丹藥室3" );
	set( "owner", "mekyn" );
	set( "build", 10008 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room455",
		"east"      : "/open/clan/ou-cloud-club/room/room457",
	]) );
	set( "long", @LONG


                              ┌────┐
                              │        │
                              │  ┌┐  │
                              │ ▕※   │
                             o└─O║\─┘
                        o    O〉  |║ \0//  |
                        O〉 |/   /╰  /  \O/
      0/o    0    /\0   |/   /╮/ /║/〉 / /  |
      @/   //\_    /\_  /╮ / /    ║    |\\O/  O_,~耶！
      $     L o   /\ o / /         ║       |  )'
  ──#  ─/ L ─/ /────────────|\ / >──────────
  ══════════════════════════════════


LONG);
	setup();
	replace_program(ROOM);
}
