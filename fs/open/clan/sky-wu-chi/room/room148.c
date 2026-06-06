inherit ROOM;
void create() {
	set( "short", "仙雲居" );
	set( "owner", "herozero" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room150",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "object", ([
		"amount7"  : 1,
		"file5"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/obj/gift/unknowdan",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/obj/gift/lingzhi",
		"file1"    : "/obj/stone/jiao",
		"amount8"  : 1,
		"file4"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"file8"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11440 );
	set( "long", @LONG
穿過一陣雲霧後，你眼前出現一間不起眼的小屋，只見門前有幅對
聯『家在此山中，雲深不知處』，你忽然驚覺到，有莫測高深的隱士住
在這裡，推門入內，裡面只有簡單的陳設，爐上正煮著茶水，案上的香
煙嬝嬝升起，望著窗外緊臨的湖泊，你的內心充滿了一片寧靜。
LONG);
	setup();
	replace_program(ROOM);
}
