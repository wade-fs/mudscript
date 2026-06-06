inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$武技之間$NOR$" );
	set( "owner", "rayk" );
	set( "object", ([
		"amount3"  : 1,
		"file2"    : "/open/capital/obj/4-4",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount8"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10002 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room430",
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
