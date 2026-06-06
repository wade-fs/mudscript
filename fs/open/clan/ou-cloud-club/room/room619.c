inherit ROOM;
void create() {
	set( "short", "$HIY$獅王道$NOR$" );
	set( "owner", "taa" );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room620.c",
		"south"     : "/open/clan/ou-cloud-club/room/room621.c",
		"west"      : "/open/clan/ou-cloud-club/room/room623.c",
		"up"        : "/open/clan/ou-cloud-club/room/room431.c",
		"east"      : "/open/clan/ou-cloud-club/room/room624",
		"north"     : "/open/clan/ou-cloud-club/room/room622.c",
	]) );
	set( "long", @LONG

     .   .....
    ............┌██══════════════════════════◥＼
     ...........│█║                                                     ║│╮
       .........└██══════════════════════════◢／ 
         .....                                                  
LONG);
	setup();
	replace_program(ROOM);
}
