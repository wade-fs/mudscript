inherit ROOM;
void create() {
	set( "short", "$HIR$佾$HIC$雲$HIW$居" );
	set( "owner", "coling" );
	set( "light_up", 1 );
	set( "object", ([
		"amount4"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/gsword/obj/dragon-sword",
	]) );
	set( "build", 10104 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
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
