inherit ROOM;
void create() {
	set( "short", "吉祥廣場一" );
	set( "object", ([
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 1,
		"file2"    : "/open/gblade/obj/dragon_book",
		"file1"    : "/open/capital/obj/blade2",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount10" : 1,
		"amount5"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/quests/snake/npc/obj/snake-key-2",
		"amount2"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"file9"    : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "owner", "mwf" );
	set( "build", 10871 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room102",
		"north"     : "/open/clan/13_luck/room/room421.c",
	]) );
	set( "long", @LONG

    這兒就是吉祥郡村民的集會場所了，廣場並不很大，也沒有甚麼裝飾
品，應該是純集合用的，正北面有個高台，但這裡沒有路可以過去，從那
個高臺上應該可以俯瞰全郡吧，路旁有武者模樣的清道夫在打掃著。你可
以感覺已經踏入十三吉祥的勢力範圍了。

LONG);
	setup();
	replace_program(ROOM);
}
