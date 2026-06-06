inherit ROOM;
void create() {
	set( "short", "$HIR$≡冥魔羽靴Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "build", 11949 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room369",
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
