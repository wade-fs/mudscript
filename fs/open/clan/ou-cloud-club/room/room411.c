inherit ROOM;
void create() {
	set( "short", "維克的家" );
	set( "owner", "vicker" );
	set( "object", ([
		"file8"    : "/obj/stone/powder",
		"amount6"  : 18,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 9,
		"amount2"  : 4,
		"amount3"  : 27,
		"file7"    : "/open/mon/obj/thousand-nectar",
		"file10"   : "/open/fire-hole/obj/y-pill",
		"amount5"  : 37,
		"amount9"  : 1,
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount10" : 5,
		"file2"    : "/obj/stone/jiao",
		"file4"    : "/obj/stone/suipian",
		"file3"    : "/open/fire-hole/obj/k-pill",
		"file9"    : "/open/clan/area/home/hae_bag",
		"amount1"  : 72,
		"amount8"  : 9,
		"amount4"  : 5,
		"file6"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "build", 10034 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room420",
		"south"     : "/open/clan/ou-cloud-club/room/room417",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
            ◢◣
    ★    ◥▄▄◤  王者風範
         █◤▼◥█              ★
       ◢◤︿  ︿◥◣  隨即呈現        ★ 
      ◢█        █◣        
      ◢█◣ ﹀ ◢█◣    ★  王      皇  ︻ 
   ◥██◢◣  ◢◣██◤     者  驚  氣  破  
     ◣╲◣███◢ ╲◣      現  天  降  千
      ◣◆   ▲   ◆  ╲◣    世  動  臨  軍
   ★ ◣◢████◣ ╲ ╲◣      地 ★   ︼

LONG);
	setup();
	replace_program(ROOM);
}
