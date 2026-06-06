inherit ROOM;
void create() {
	set( "short", "$BCYN$九$BBLU$又$BRED$四$BGRN$分$BYEL$之$BWHT$三$NOR$$HIM$月台$NOR$" );
	set( "owner", "firefan" );
	set( "object", ([
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10113 );
	set( "exits", ([
		"down"      : "/open/clan/time-limit/room/room28.c",
		"up"        : "/open/clan/time-limit/room/room26",
	]) );
	set( "long", @LONG
通過漆黑的通道後,終於來到九又四分之三月台,
前方的霍格華茲特快車正冒著濃濃的蒸氣,看來就快要開車了,
一旁的家長忙著提孩子的行李,也有和火車上的孩子道別,
一副又忙又亂的景象,為的是讓自己的孩子到霍格華茲學習魔法,
將來成為一位偉大的巫師,尤其現任校長更是當代公認最
偉大的巫師'阿不思-鄧不利多',讓家長放心將子女送到學校就學

LONG);
	setup();
	replace_program(ROOM);
}
