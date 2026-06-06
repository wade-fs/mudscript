inherit ROOM;
void create() {
	set( "short", "$HIC$天空之城$NOR$--$YEL$髓$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/xisuidan",
		"file7"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/xisuidan",
		"file3"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount4"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room210",
	]) );
	set( "owner", "del" );
	set( "build", 10030 );
	set( "long", @LONG
擰乾了溼透的衣衫，你發現自己站在一片樹林前面，四
周圍環繞著的是風的耳語，鳥囀蟲鳴，一瞬間讓你忘卻身上
的寒冷，不遠處有一與你身高差不多的草叢，隱約傳來流水
的聲音，甩了甩手上的水漬，重新緊握手上的武器，撥開草
叢向前慢慢走去。
ˉ
LONG);
	setup();
	replace_program(ROOM);
}
