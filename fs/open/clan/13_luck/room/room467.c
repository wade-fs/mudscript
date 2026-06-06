inherit ROOM;
void create() {
	set( "short", "土靈塔房" );
	set( "owner", "mill" );
	set( "object", ([
		"amount4"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10376 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room469",
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
