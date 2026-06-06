inherit ROOM;
void create() {
	set( "short", "曲終人散" );
	set( "owner", "woan" );
	set( "object", ([
		"file7"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"file4"    : "/obj/gift/lingzhi",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file3"    : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/lingzhi",
		"file6"    : "/obj/gift/lingzhi",
		"file8"    : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/lingzhi",
		"amount7"  : 1,
		"file5"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10926 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room329",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
    你讓他用戒指把你套上的時候，我察覺到你臉上復雜的笑
容。那原本該是我，付予你的承諾，現在我只能隱身熱鬧中。
我跟著所有人向你祝賀的時候，只有你知道我多喝了幾杯酒。
我不能再看你，多一眼都是痛，即使知道暗地里你又回頭。我
終于知道曲終人散的寂寞，只有傷心人才有，你最後一身紅，
殘留在我眼中，我沒有再依戀的藉口。原來這就是曲終人散的
寂寞。我還想等你什麼，你緊緊拉住我衣袖，又放開讓我走，
這一次跟我徹底分手。 


LONG);
	setup();
	replace_program(ROOM);
}
