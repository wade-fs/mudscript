inherit ROOM;
void create() {
	set( "short", "$HIW$練功\房$NOR$" );
	set( "owner", "cong" );
	set( "object", ([
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/wu/obj/figring",
		"file4"    : "/open/gblade/obj/sa-head",
		"amount1"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"file6"    : "/open/gblade/obj/sa-head",
		"amount10" : 1,
		"amount5"  : 1,
		"file9"    : "/open/quests/snake/npc/obj/snake-3",
		"file10"   : "/open/quests/snake/npc/obj/snake-3",
		"amount8"  : 1,
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file8"    : "/open/quests/snake/npc/obj/snake-1",
		"amount2"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10719 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room242",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此地為$HIW$霹靂貓$NOR$專屬的練功區，裡面住著超強的怪物供其練功，
突然之間，眼前出現了傳說中火龍幻界裡的白光火龍，聽聞其龍極為兇惡
只要敢出現在他眼前的人，他將殺無赦，若不是擁有$HIR$貓王神功$HIW$九重天$NOR$者
或是沒有三頭六臂之人，切勿進來此地～～～～～

LONG);
	setup();
	replace_program(ROOM);
}
