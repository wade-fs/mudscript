inherit ROOM;
void create() {
	set( "short", "$HIC$冷  $HIY$月  $HIB$寒$NOR$" );
	set( "object", ([
		"file6"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/scholar/obj/icefan",
		"file8"    : "/obj/gift/xisuidan",
		"file2"    : "/open/dancer/obj/yuawaist",
		"file5"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"amount9"  : 1,
		"file10"   : "/open/main/obj/unarmed-b",
		"amount4"  : 1,
		"file1"    : "/open/prayer/obj/boris-cloth",
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"amount1"  : 1,
		"file9"    : "/obj/gift/lingzhi",
		"amount5"  : 1,
	]) );
	set( "owner", "back" );
	set( "build", 10007 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room215",
	]) );
	set( "long", @LONG
願思念是並沒盡頭 沒有依附現在過去或以後
即使這軀殼有一朝化做塵垢 仍能跟您纏綿於宇宙
                                                                                
霓虹上有雪 灑得多撇脫 像向天地萬物作最後告別
分不清季節 這冰冷四月 眼前的世界景色淒迷決絕
                                                                                
抓一把細雪 放於手灼熱 但願不再怕北風深寒刺裂
緊緊擁抱您再一次吻別 我願不要說再見 免得心更酸

LONG);
	setup();
	replace_program(ROOM);
}
