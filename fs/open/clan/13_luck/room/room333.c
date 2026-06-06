inherit ROOM;
void create() {
	set( "short", "神風之道" );
	set( "owner", "smalloo" );
	set( "object", ([
		"amount9"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/xiandan",
		"file6"    : "/open/capital/obj/chen_dagger",
		"file3"    : "/open/capital/obj/chen_dagger",
		"file10"   : "/open/killer/obj/hate_knife",
		"amount10" : 1000,
		"file4"    : "/open/scholar/obj/icefan",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file5"    : "/open/capital/obj/chen_dagger",
		"file2"    : "/open/capital/obj/chen_dagger",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10374 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room334",
		"north"     : "/open/clan/13_luck/room/room335.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    你的直覺告訴你，就快到神風堂了。你心中沖滿了期待和幻想。
陰風吹襲的愈來愈強烈，彷彿像你說道，想到神風堂，輕功不夠等於
死路一條，此時你被陰風吹的你快穩不住腳步。你運起內元，不停的
加快腳步向前走去。此時厚厚黑黑的雲層吹過來，壓得你喘不過氣來
，連忙運功自保。


LONG);
	setup();
	replace_program(ROOM);
}
