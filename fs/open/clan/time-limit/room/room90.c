inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$BLU$惡人$NOR$ " );
	set( "object", ([
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/obj/evil-kill-claw",
		"amount5"  : 1,
		"amount10" : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"file9"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/obj/evil-kill-claw",
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount2"  : 1,
	]) );
	set( "build", 10044 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room91",
		"south"     : "/open/clan/time-limit/room/room89",
	]) );
	set( "long", @LONG
魔爪混天殺(Evil-kill-claw),莫道子所使用的武器,為一神秘鑄將精心鑄造的
「八色靈器」之一,爪身散出極強的殺氣,莫道子最致命的招式莫過於天魔混殺
吼,有時被擊中當場就去見閻王了,他還會騎駱駝以及用冰雪神戒定人,是個危險
的對手,而魔爪混天殺除了當武器使用外,也是聚靈道裡通行的鑰匙

LONG);
	setup();
	replace_program(ROOM);
}
