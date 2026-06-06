inherit ROOM;
void create() {
	set( "short", "維克中庭" );
	set( "owner", "vicker" );
	set( "object", ([
		"file6"    : "/open/ping/obj/ring-2",
		"amount7"  : 58,
		"amount4"  : 66,
		"amount2"  : 1,
		"amount3"  : 13,
		"amount6"  : 1,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/obj/gift/hobowdan",
		"amount5"  : 3,
		"file2"    : "/obj/gift/lingzhi",
		"file7"    : "/open/fire-hole/obj/g-pill",
		"file3"    : "/open/fire-hole/obj/p-pill",
		"file5"    : "/open/ping/obj/poison_pill",
		"amount1"  : 1,
	]) );
	set( "build", 10073 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room444",
		"south"     : "/open/clan/ou-cloud-club/room/room411",
	]) );
	set( "long", @LONG
    
                ▲
     ˙ˍ▂◢███◣  
  ☆     ◢███◣█
     ·◢█◢███◣     
   ★    ◤ ▍ ◥██◣
      ·       〞 █ ◣    
           ◣－  ◥█◣ ˙
        ‧  ◢   █◤   ★    ‧   ﹒
         ◢█  ◤██◣     ☆    ‧ ☆
       ◢██●██◥█◣  ‥ ﹒   ‧

LONG);
	setup();
	replace_program(ROOM);
}
