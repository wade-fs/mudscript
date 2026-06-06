inherit ROOM;
void create() {
	set( "short", "$HIR$風 $MAG$雨 $MAG$飄 $HIR$搖" );
	set( "object", ([
		"amount3"  : 4,
		"file4"    : "/open/fire-hole/obj/b-pill",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 5,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 5,
		"file7"    : "/open/fire-hole/obj/p-pill",
		"file2"    : "/open/mon/obj/flower-claw",
		"amount4"  : 4,
		"amount5"  : 1,
		"file1"    : "/open/killer/obj/bellstar",
		"amount2"  : 1,
		"amount6"  : 5,
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 240,
		"file3"    : "/obj/stone/powder",
	]) );
	set( "build", 10085 );
	set( "owner", "legendpker" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room403",
		"south"     : "/open/clan/ou-cloud-club/room/room442",
	]) );
	set( "long", @LONG
                  ◢◣◢◣◢█◣◢◣◢◣
      ███◣◢█████████████◣◢███
      █████◤　◢███████◣　◥█████
      ████◤◥◣█風  雨  飄  搖█◢◤◥████
      ███◤　　█◤███████◥█　　◥███
      ██◤  　你走到這裡，抬頭一望，風雨飄搖◥██
      ██  四個大字，出現眼前，一座拱門就呈獻  ██
      ██  在您眼前，精緻的雕刻，華麗的外觀，  ██
      ██  一直吸引著你的目光。                ██
      ██◣                                  ◢██

LONG);
	setup();
	replace_program(ROOM);
}
