inherit ROOM;
void create() {
	set( "short", "古代遺跡絕對零度" );
	set( "object", ([
		"file8"    : "/open/fire-hole/obj/g-pill",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/fire-hole/obj/b-pill",
		"file2"    : "/open/fire-hole/obj/y-pill",
		"amount1"  : 1,
		"file4"    : "/open/fire-hole/obj/p-pill",
		"amount8"  : 3,
		"file1"    : "/obj/stone/powder",
		"amount3"  : 1,
		"amount2"  : 2,
		"amount5"  : 2,
		"amount7"  : 10,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 2,
		"file3"    : "/obj/stone/suipian",
		"amount6"  : 2,
	]) );
	set( "build", 8021 );
	set( "owner", "shinny" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room655",
	]) );
	set( "long", @LONG
四周溫度猛然降至「絕對零度」，寒氣從四面八方不斷的侵蝕，內力
不足的人，將永遭冰封。
 
  ◤            ◥█
◤                ◥
                    
   ◢█◣  ◢█◣   
   ███  ███   
   ◥█◤  ◥█◤   
                    
  ◣◢◣◢◣◢◣◢  
  ◥◤◥◤◥◤◥◤  
                    
◣◢◣◢◣◢◣◢◣◢

 

LONG);
	setup();
	replace_program(ROOM);
}
