inherit ROOM;
void create() {
	set( "short", "【秘密花園】" );
	set( "owner", "working" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1300,
		"file1"    : "/open/killer/obj/hate_knife",
		"file3"    : "/open/killer/obj/s_pill",
		"amount1"  : 11440906,
		"file2"    : "/open/killer/obj/fire-knife",
	]) );
	set( "build", 10235 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room398",
		"south"     : "/open/clan/sky-wu-chi/room/room415.c",
		"north"     : "/open/clan/sky-wu-chi/room/room415",
		"east"      : "/open/clan/sky-wu-chi/room/room416.c",
	]) );
	set( "long", @LONG

   陽炎臂環 (Sun Fire Armband)
   幸運草環(Lucky-grasslink)
   混沌腰帶(Chaos belt)
   夕霞紅紗(Sun_red_cloth)
   魔法盾(Magic shield)
   羅剎女飾(Gem)
   寒梅指戒(May ring)
   狂龍翔天破(Crazy dragon)
   妖幻披掮(Ghost cloak)
   妖幻護膝(Ghost legging)
   妖幻頭帶(Ghost helmet)

LONG);
	setup();
	replace_program(ROOM);
}
