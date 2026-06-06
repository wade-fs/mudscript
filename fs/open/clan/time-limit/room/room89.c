inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$HIB$魔刀$NOR$ " );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file5"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file6"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount9"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file8"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount1"  : 1,
	]) );
	set( "build", 11238 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room97",
		"south"     : "/open/clan/time-limit/room/room88",
		"north"     : "/open/clan/time-limit/room/room90",
	]) );
	set( "long", @LONG
刀斬邪元歸(Evil-gwe-blade),封圓真所使用的武器,為一神秘鑄將精心鑄造的
「八色靈器」之一,刀身隱隱綻放著一點點的邪光,封圓真會使用邪靈制刀術,
除了必殺型,每一招都會用在你身上,尤其是毀器型更會破壞你的武器,是個需
小心對手,而刀斬邪元歸除了當武器使用外,也是聚靈道裡通行的鑰匙

LONG);
	setup();
	replace_program(ROOM);
}
