inherit ROOM;
void create() {
	set( "short", "$HIC$欣$HIR$ソ$HIY$防具所$HIB$III$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"amount1"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/bingtang",
	]) );
	set( "build", 10210 );
	set( "exits", ([
		"love"      : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room169.c",
		"east"      : "/open/clan/sky-wu-chi/room/room109.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
當你一走近這個地區的時候...有一陣陣的微風吹來...
打從心底感到一振涼意...讓你在彷彿徜徉在大海般的感覺...
正當你想離開這地方的時候你發現你突然全身出不了力了...
你這時才恍然大悟lts這小子居然為了防止eq被偷
居然在這房間下了迷藥...心想他真是狠毒...


LONG);
	setup();
	replace_program(ROOM);
}
