inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$靜坐之房$NOR$" );
	set( "owner", "rayk" );
	set( "object", ([
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"file10"   : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"file9"    : "/obj/gift/lingzhi",
		"file5"    : "/obj/gift/xiandan",
		"file1"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"file6"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10002 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room430",
	]) );
	set( "long", @LONG

    牆上一個個的拳印，磨損不堪的地板，這裡就是Ｒａｙｋ的家。
Ｒａｙｋ常常在這裡習武練氣，所以房子裡面到處是打鬥的痕跡。房
間裡擺飾極少，僅一床一桌，顯示出Ｒａｙｋ一貧如洗，但他卻怡然
自得，一點都不以這種簡陋簡陋的生活為苦。

LONG);
	setup();
	replace_program(ROOM);
}
