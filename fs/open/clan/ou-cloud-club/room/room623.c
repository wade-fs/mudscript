inherit ROOM;
void create() {
	set( "short", "$MAG$龍王窟$NOR$" );
	set( "owner", "taa" );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room5",
		"east"      : "/open/clan/ou-cloud-club/room/room619.c",
	]) );
	set( "long", @LONG


                             /           /
                            /' .,,,,  ./
                           /';'     ,/
                          / /   ,,//,`'`
                         ( ,, '_,  ,,,' ``
                         |    /@  ,,, ;  `
                        /    .   ,' /' `,``
                       /   .     ./, `,, ` ;
                    ,./  .   ,-,',` ,,/''\,'
                    |   /; ./,,'`,,'' |   |
                    |     /   ','    /    |
                     \___/'   '     |     |
                       `,,'  |      /     `\
                            /      |        ~\
                           '       (
                           :
                          ; .         \--\----


LONG);
	setup();
	replace_program(ROOM);
}
