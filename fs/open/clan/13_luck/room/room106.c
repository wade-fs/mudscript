inherit ROOM;
void create() {
	set( "short", "ζζζmill用之2ζζζζ" );
	set( "owner", "mill" );
	set( "object", ([
		"amount8"  : 1428,
		"amount5"  : 662,
		"amount9"  : 146,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount10" : 12,
		"amount3"  : 169,
		"amount4"  : 1627,
		"amount2"  : 555,
		"file7"    : "/open/fire-hole/obj/p-pill",
		"amount7"  : 166,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"file2"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 633,
		"file1"    : "/open/killer/obj/s_pill",
		"amount1"  : 1155,
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file10"   : "/open/killer/obj/black",
		"file4"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "build", 10137 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room85.c",
		"west"      : "/open/clan/13_luck/room/room60.c",
		"south"     : "/open/clan/13_luck/room/room247",
	]) );
	set( "long", @LONG
　　　◢　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　◣
　　║◥　　　　◥▇▆▄▃▁◣　　　　　　　　　　　◢▁▃▄▆▇◤　　　　◤║
　　║║◥　　◥████▆██　　　　　▂▂　　　　██▆████◤　　◤║║
　　║║║◥　◢█ ███　 ◤　　　◢□□□　　　　◥　 ███ █◣　◤║║║
　　║║║║◥██▅ ██◤         ◤◥██　　　　　 ◥██ ▅██◤║║║║
　　║║║║◢███▅ ◤　　　　　　　 ██　　　　　　 ◥ ▅███◣║║║║
　　║║║║◢████◣　　　　　　　　██　　　　　　　◢████◣║║║║
　　║║║╰  ◥████◣　　　　　　　██　　　　　　◢████◤  ╯║║║
　　║║╰      ◥████◣　　　　　◢██　　 ▊　 ◢████◤      ╯║║
　　║╰            ◥███　　　　◢███◣▂█　　███◤            ╯║
　　╰         ）（   ███　　　███████　　　███   ）（         ╯
              ）（   ██◤　　　◥□□□██◤　　　◥██   ）（  
             （●）◢█◤　　　　　□◤  ◥█　　　　　◥█◣（●）
               ◥██◤　　　　　　□  卍  █　　　　　　◥██◤
　　　　　　　　　　　　　　　　　 □◣  ◢█
　　　　　　　　　　　　　　　　　 ◥□██◤
　　　　　　　　　　　　　　　　　　 ███
　　　　　　　　　　　　　　　　　　 █╤□
　　　　　　　　　　　　　　　　　　 □｜□
　　　　　　　　　　　　　　　　　　 □  □
　　　　　　　　　　　　　　　　　　 □卍□
　　　　　　　　　　　　　　　　　　 □Π□
LONG);
	setup();
	replace_program(ROOM);
}
