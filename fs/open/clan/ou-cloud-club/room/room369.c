inherit ROOM;
void create() {
	set( "short", "$HIR$≡冥魔羽靴≡$NOR$" );
	set( "build", 11256 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room379",
		"north"     : "/open/clan/ou-cloud-club/room/room359",
	]) );
	set( "long", @LONG
羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴
冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴
冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴
冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴
冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴
冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴冥魔羽靴
LONG);
	setup();
	replace_program(ROOM);
}
