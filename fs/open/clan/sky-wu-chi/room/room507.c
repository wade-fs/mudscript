inherit ROOM;
void create() {
	set( "short", "$HIG$妮文絲湖畔$NOR$" );
	set( "owner", "coling" );
	set( "light_up", 1 );
	set( "object", ([
		"amount6"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/killer/obj/k_ring",
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"file2"    : "/open/gblade/obj/sa-head",
		"amount5"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/killer/obj/k_ring",
		"amount1"  : 1,
		"file10"   : "/open/mogi/dragon/obj/dragon-head",
		"amount4"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"file9"    : "/open/mogi/dragon/obj/dragon-head",
		"amount9"  : 1,
	]) );
	set( "build", 10293 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room563",
		"east"      : "/open/clan/sky-wu-chi/room/room542",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"north"     : "/open/clan/sky-wu-chi/room/room564.c",
	]) );
	set( "long", @LONG
人工挖掘出來的湖畔用著相當巨大的石塊堆砌著。靠近水面的石
頭則是長滿了青苔。湖邊一棵棵的楊柳垂下枝條，迎風搖擺著，偶有
幾隻水鴨飛上岸整理羽翼，那可愛的模樣令人疼愛。風輕輕的吹拂著
整個景色美得像畫一般。

LONG);
	setup();
	replace_program(ROOM);
}
