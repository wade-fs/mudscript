inherit ROOM;
void create() {
	set( "short", "木靈塔房" );
	set( "owner", "mill" );
	set( "object", ([
		"amount9"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10182 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room469",
		"east"      : "/open/clan/13_luck/room/room471.c",
	]) );
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
