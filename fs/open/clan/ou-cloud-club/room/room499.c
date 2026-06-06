inherit ROOM;
void create() {
	set( "short", "總捅府" );
	set( "object", ([
		"file2"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file7"    : "/obj/gift/hobowdan",
		"file1"    : "/obj/gift/hobowdan",
		"file8"    : "/obj/gift/hobowdan",
		"file4"    : "/obj/gift/hobowdan",
		"amount5"  : 1,
		"amount3"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"file5"    : "/obj/gift/hobowdan",
		"file3"    : "/obj/gift/hobowdan",
		"file6"    : "/obj/gift/hobowdan",
		"file10"   : "/obj/gift/hobowdan",
		"amount7"  : 1,
	]) );
	set( "owner", "ctx" );
	set( "build", 10056 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room500",
	]) );
	set( "long", @LONG
想出氣嗎?那就來這裡吧,失業沒錢沒diamond就來這,這裡專
門給你出氣用的,只要記得自備棍子一個就好,門口有一個看起來
就很欠扁的傢伙,想出一口怨氣的話就用力的捅他吧,雖然扁完後
並不能完全洩發這3年多來的怨氣, 不過有氣就是要宣發出來,憋
在心理會憋出病的。

LONG);
	setup();
	replace_program(ROOM);
}
