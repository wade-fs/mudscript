inherit ROOM;
void create() {
	set( "short", "我不像我" );
	set( "object", ([
		"amount4"  : 1,
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/mon/obj/mon-pill",
		"amount1"  : 109,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/gsword/obj1/kring",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/wu/obj/figring",
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/killer/obj/fire-knife",
		"file9"    : "/daemon/class/blademan/obj/shield",
		"file5"    : "/open/gsword/obj1/karmor",
		"amount9"  : 1,
		"amount8"  : 32,
		"amount10" : 1,
		"amount2"  : 1,
	]) );
	set( "owner", "iloveyou" );
	set( "build", 10942 );
	set( "light_up", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
  我　不像我　不像我自己　流一滴淚是為你哭泣 
      我　不像我　瘋狂愛上你　這一生只為一個人癡迷 

      愛上你的美麗　愛上你的狠心　那是一種我握不住的自信
      愛上你的任性　愛上你的固執　我卻不能忘記你從不是誰的唯一 

      我　不像我　不像我自己　流一滴淚是為你哭泣 
      我　不像我　瘋狂愛上你　這一生只為一個人癡迷 
LONG);
	setup();
	replace_program(ROOM);
}
