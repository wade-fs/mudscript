inherit ROOM;
void create() {
	set( "short", "欣之屋" );
	set( "object", ([
		"amount8"  : 200,
		"amount4"  : 85,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount5"  : 166,
		"amount6"  : 180,
		"file2"    : "/open/mon/obj/mon-pill",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 11,
		"amount10" : 1170,
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file10"   : "/open/fire-hole/obj/k-pill",
		"amount9"  : 233,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 289,
		"amount3"  : 156,
		"amount2"  : 400,
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file4"    : "/open/fire-hole/obj/y-pill",
	]) );
	set( "owner", "lts" );
	set( "build", 14673 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room399",
		"west"      : "/open/clan/ou-cloud-club/room/room214",
	]) );
	set( "long", @LONG

--
  ｜ ‧   ●  ‧     ‧     ‧ ‧ ◢◣  ‧ ● ‧  ◢◣◥██◣
－‧－ ‧ ‧    ‧ ‧  ● ‧ ‧  ◢█◣‧ ‧    ◢██◣◥██◣ ● ‧
  ｜︿︿ ∩∩    ◢◣  ‧    ● ◢██◣ ●  ‧  ██▉████ 
  （  т）   ） ◢█◣  ●  ‧ ◢███◣ ‧  ● █│▉█┼┼█
  （  т）   ）◢██◣  ▁▂▄▅▇█▇▆▅▄▃▂█│▉█████▁▂▃
 ▔▔∫▔ ∫ ██████████████████小欣-溫暖ソ窩-████

LONG);
	setup();
	replace_program(ROOM);
}
