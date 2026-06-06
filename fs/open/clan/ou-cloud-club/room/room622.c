inherit ROOM;
void create() {
	set( "short", "$HIW$虎王窟$NOR$" );
	set( "owner", "taa" );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room316",
		"south"     : "/open/clan/ou-cloud-club/room/room619.c",
	]) );
	set( "long", @LONG



                      _ __..-;''`--/'/ /.',-`-.
                   (`/' ` |  \ \ \\ / / / / .-'/`,_
                  /'`\ \   |  \ | \| // // / -.,/_,'-,
                 /<7' ;  \ \  | ; ||/ /| | \/    |`-/,/-.,_,/')
                /  _.-, `,-\,__|  _-| / \ \/|_/  |    '-/.;.\'
                `-`  f/ ;      / __/ \__ `/ |__/ |
                     `-'      |  -| =|\_  \  |-' |
                           __/   /_..-' `  ),'  //
                          ((__.-'((___..-'' \__.'

LONG);
	setup();
	replace_program(ROOM);
}
