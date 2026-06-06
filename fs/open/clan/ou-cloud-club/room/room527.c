inherit ROOM;
void create() {
	set( "short", "獵豔江湖夢" );
	set( "owner", "ctx" );
	set( "object", ([
		"file3"    : "/obj/gift/bingtang",
		"file4"    : "/obj/gift/lingzhi",
		"amount4"  : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"file7"    : "/obj/gift/lingzhi",
		"file9"    : "/obj/gift/lingzhi",
		"amount9"  : 1,
		"amount10" : 1,
		"file8"    : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/lingzhi",
		"file10"   : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/lingzhi",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 17570 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room517",
	]) );
	set( "long", @LONG
一個善良的無賴，有著孩童般的心性,卻有著魔神般的戰鬥
力和對異性強大的吸引力。一個虛構的國度,並不是真實的中國
古代，這是一部輕松搞笑的荒唐小說,文中所有的地理、皇朝、
故事、人物都屬于虛構，因為是虛構武俠,所以用輕松的筆調來
寫，造就一個男人的夢,這樣的夢很多男人都做過----就是對強
大和美女的擁有！ 

LONG);
	setup();
	replace_program(ROOM);
}
