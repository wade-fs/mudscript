inherit ROOM;
void create() {
	set( "short", "$HIY$破釜$HIC$酒吧$NOR$" );
	set( "owner", "firefan" );
	set( "object", ([
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10176 );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room52",
		"east"      : "/open/clan/time-limit/room/room26",
	]) );
	set( "long", @LONG
路旁一間絲毫不起眼的酒吧,好像刻意隱藏自己的存在,不仔細看還真難發現這間酒吧,
一走進酒吧裡,裡頭各式各樣的人都有,有的人披著巫師斗篷,有的人則穿著一般人的服裝,
有位老女巫點了一盤生內臟正在享用大餐,酒保湯姆正拿著奶油啤酒到處招呼客人,十分熱鬧,
而破釜酒吧也是進入倫敦最大的巫師市場'斜角巷'的入口,不過不知道門路的人則無法進去

LONG);
	setup();
	replace_program(ROOM);
}
