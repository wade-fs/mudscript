inherit ROOM;
void create() {
	set( "short", "$HIW$『$HIY$星$HIW$願$HIC$池$HIW$』$NOR$" );
	set( "build", 24 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/hall",
	]) );
	set( "long", @LONG




               .                ． ☆　　　　　　　　　　　.
    .         ☆       . .                       *              *  .
                   ☆                           ．  ☆                         
                            <  星  願  池  >
                          

把錢丟向星星  ~~~~~   妳的願望一定可以實現的...................
LONG);
	setup();
	replace_program(ROOM);
}
