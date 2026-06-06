inherit ROOM;
void create() {
	set( "short", "$HIY$劍心殿$NOR$之$HIY$問劍堂$NOR$" );
	set( "owner", "vatsu" );
	set( "object", ([
		"file7"    : "/open/gsword/obj1/bbladeball",
		"file6"    : "/open/gsword/obj1/bbladeball",
		"file2"    : "/open/gsword/obj1/bbladeball",
		"amount3"  : 1,
		"file10"   : "/open/gsword/obj1/bbladeball",
		"amount9"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"file3"    : "/open/gsword/obj1/bbladeball",
		"file4"    : "/open/gsword/obj1/bbladeball",
		"file9"    : "/open/gsword/obj1/bbladeball",
		"amount2"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/gsword/obj1/bbladeball",
		"amount8"  : 1,
		"file8"    : "/open/gsword/obj1/bbladeball",
		"amount7"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 12522 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room13.c",
		"west"      : "/open/clan/hell/room/room98",
	]) );
	set( "long", @LONG
走進問劍堂只見一名身著灰衣面帶憂容的中年人佇立在
窗口他的眼神沉著而機敏，且隱隱透著光芒，露在衣服外的
皮膚泛起一種奇異的光澤，那是長期修練內家真氣的現象，
他正不厭其煩的對劍宗弟子講解著劍道的奧義。
  「護宗劍奴」紫屠殺(Sword guard)
  劍宗第二代宗主 虛若空(Master sky)

LONG);
	setup();
	replace_program(ROOM);
}
