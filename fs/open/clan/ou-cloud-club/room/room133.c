inherit ROOM;
void create() {
	set( "short", "$HIW$OOQ大廳$NOR$" );
	set( "object", ([
		"file2"    : "/open/fire-hole/obj/w-pill",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/killer/weapon/k_torch",
		"amount1"  : 1,
		"file5"    : "/open/ping/obj/ring-2",
		"amount10" : 1,
		"file6"    : "/open/scholar/obj/icefan",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount2"  : 3,
		"amount9"  : 7,
		"file8"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "light_up", 1 );
	set( "build", 10226 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room191",
		"north"     : "/open/clan/ou-cloud-club/room/room448.c",
		"east"      : "/open/clan/ou-cloud-club/room/room163.c",
		"up"        : "/open/clan/ou-cloud-club/room/room355.c",
		"west"      : "/open/clan/ou-cloud-club/room/room436.c",
	]) );
	set( "long", @LONG
                                                                               
         ●---                                   ﹀                             
         ｜＼                                 ﹀     ﹀                         
                  ◢▓▓▓▓▓◤◥█                      ◢◣                  
    ▁▂▄▁▃▂◢▓▓▓▓▓◤ ⊕ ◥▂▃▃▂▄▆▅▃▂▄ ◢█◣▂               
    ▂▃▁▃▄▅▏田 田 田▕========▁▂▃▁▂▁◢◣▃▁◢██◣▁              
              ◢▓▓▓▓▓◤ ▕◥▓▓◣        ◢█◣   ◢██◣                
              ▏田 █ 田▕   ▕▕  田          ◢█◣  ◢███◣               
      ╰s┬┬▏   █   ▕   ▕▕      ┬┬┬┬┬█┬┬┬  █                   
    ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔              
                                                                                
                                                                                
                                                                         
LONG);
	setup();
	replace_program(ROOM);
}
