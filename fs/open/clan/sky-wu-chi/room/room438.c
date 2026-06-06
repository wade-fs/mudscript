inherit ROOM;
void create() {
	set( "short", "$HIR$玫瑰花床$NOR$" );
	set( "object", ([
		"file1"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1470,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/clan/area/home/hae_bag",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file8"    : "/open/capital/obj/blade2",
		"amount8"  : 1,
		"amount4"  : 8,
		"file7"    : "/open/gblade/obj/sa-head",
	]) );
	set( "build", 11201 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room451",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG

千年花床千年夢，千絲情扣夢雨涵；
一朵玫瑰心始開，一生一願見最愛。
爭何？多風多雲多月。尋何？至真至善至美。
貪何？有權有勢有名。留何？命也樂也長也。
塵世浮沉近千秋，獨少一年九九九。 
千年情緣今朝盡，留下久久一英名；
愁天不禁落星淚，紅了雲霞染故人。

LONG);
	setup();
	replace_program(ROOM);
}
