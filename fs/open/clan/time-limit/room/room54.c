inherit ROOM;
void create() {
	set( "short", "$BRED$三年級$BGRN$黑魔法$BBLU$防禦課$BMAG$教室$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
	]) );
	set( "build", 10266 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room60",
	]) );
	set( "long", @LONG
三年級生的黑魔法防禦術是由路平教授來教導,主要著重在黑魔獸的部份,
之前路平教授帶著學生對付變形怪,讓學生面對自己內心所恐懼的東西
並且克服它,上了一節非常精彩的課,因而受到學生的擁戴,但是他最近
身體不適,並沒有出現在教室裡,學生們對於路平教授所恐懼的東西
是個銀白色的球很感興趣

LONG);
	setup();
	replace_program(ROOM);
}
