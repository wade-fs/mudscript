inherit ROOM;
void create() {
	set( "short", "水靈塔房" );
	set( "owner", "mill" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room471",
		"east"      : "/open/clan/13_luck/room/room106.c",
	]) );
	set( "object", ([
		"amount5"  : 265,
		"amount10" : 112,
		"amount3"  : 1,
		"file5"    : "/open/mon/obj/mon-pill",
		"file8"    : "/open/killer/obj/hate_knife",
		"amount6"  : 163,
		"amount8"  : 91070,
		"file6"    : "/open/killer/obj/atman_pill",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 10146 );
	set( "light_up", 1 );
	set( "long", @LONG
               ◢▅▅▅▅▅▅◣▃▃▲▃▃◢▅▅▅▅▅▅◣
                   ◣┼┼┼┼┼◥◤ :┼┼┼: ◥◤┼┼┼┼┼◢
             ◢▅▅◥▅◣▔▔◥◣≡╲╰┼╯╱≡◢◤▔▔◢▅◤▅▅◣
             ◣┼┼┼┼◤    ◢◤╲▃◣┼◢▃╱◥◣    ◥┼┼┼┼◢
             ◥▅◣▔▔      ◥◢◥ ● mm ● ◤◣◤      ▔▔◢▅◤
                 ◥          ◢◤◢◥▅▃▅◤◣◥◣          ◤
               ╭═◢◣         ◥ ◥▅▃▅◤ ◤         ◢◣═╮
          ╭═◢◣ █◤       ◢◤◢◤◤◥◥◣◥◣       ◥█ ◢◣═╮
     ╭═◢◣ █◤ ◥             ╰╮ Ω ╭╯             ◤ ◥█ ◢◣═╮
    ◢◣ █◤ ◥      ◢◣           ◣▲◢           ◢◣      ◤ ◥█ ◢◣
    █◤ ◥           ◥█◣       ◢◤▼◥◣       ◢█◤           ◤ ◥█
    ◥              ◥██◤                        ◥██◤              ◤
LONG);
	setup();
	replace_program(ROOM);
}
