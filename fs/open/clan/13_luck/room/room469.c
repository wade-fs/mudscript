inherit ROOM;
void create() {
	set( "short", "金靈塔房" );
	set( "owner", "mill" );
	set( "object", ([
		"amount9"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10197 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room467",
		"east"      : "/open/clan/13_luck/room/room470",
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
