inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$WHT$仙劍$NOR$" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/obj/fon-sky-sword",
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/fon-sky-sword",
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount9"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/obj/fon-sky-sword",
		"file8"    : "/open/magic-manor/obj/fon-sky-sword",
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount1"  : 1,
	]) );
	set( "build", 10606 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room87",
		"north"     : "/open/clan/time-limit/room/room89",
	]) );
	set( "long", @LONG
楓映天蓮劍(Fon-sky-sword),凌方真所使用的武器,為一神秘鑄將精心鑄造的
「八色靈器」之一，劍身黝黑,隱隱透出黑色的氣勁,凌方真會使用連陽七訣斬,
因此很容易被他封住特功,不過他的威力並不強,比起其他八傑的成員算是比較
好打,而楓映天蓮劍除了當武器使用外,也是聚靈道裡通行的鑰匙

LONG);
	setup();
	replace_program(ROOM);
}
