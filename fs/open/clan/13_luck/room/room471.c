inherit ROOM;
void create() {
	set( "short", "火靈塔房" );
	set( "owner", "mill" );
	set( "object", ([
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10085 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room470",
		"east"      : "/open/clan/13_luck/room/room60.c",
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
