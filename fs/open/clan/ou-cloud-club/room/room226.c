inherit ROOM;
void create() {
	set( "short", "懶蟲俑" );
	set( "owner", "scs" );
	set( "object", ([
		"file3"    : "/open/killer/obj/atman_pill",
		"amount1"  : 795,
		"amount4"  : 1,
		"amount3"  : 61,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount10" : 1,
		"file8"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"file4"    : "/open/gsword/obj1/bbladeball",
		"amount7"  : 1,
		"file9"    : "/open/gsword/obj1/bpball",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount8"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"file2"    : "/open/mogi/dragon/obj/dragon-head",
		"amount6"  : 1,
		"file6"    : "/obj/stone/suipian",
	]) );
	set( "build", 10177 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room523.c",
		"south"     : "/open/clan/ou-cloud-club/room/room518",
		"west"      : "/open/clan/ou-cloud-club/room/room166.c",
	]) );
	set( "long", @LONG
           ▃▄▅                                                          
               ｜≡│
               │▁▂
               ▍   ▍
                     
  ▄▅▆             
  ▁▂▃                                      ︿  ︿
▂ ▁    ▁▂                         ︿ ︿◢      ◣︿ ︿
        ∕▂▂                   ︿︿◢     ◣      ◤     ◣︿︿
▇▇▇▇▍= =                  ◢    ◣  ▔ ◤ ▆▆ ◥  ▔ ◤    ◣
 | | |  ▍= =                  ◥▆▆◤         ○         ◥▆▆◤︿
 | | |  ▍= =    ▂  ▏    ││▄▆▆▅◢ ▂                         ◣     ▂
▂▅▅▆▍                ▄           ◣ ▄ ▃▄▄▇        ◣      ◤        
    ▂▂  ▇▂▂▇▆▂▂▂                     ▅▅            ◣▁▁■■■■■
    ──▂▃──▃▄───                                       ◢◣▄▄      
▇▃▅▇           ▆▄▂              ▂▂▄              ▆▄▂  ▂▂▄▄▆▆
                           ▄▄▄▆           
  ▇▇▇▇▆▆▆▆▅▅▅▅ ▄▄▃▃▂▂▁▁     ▁▁▂▂▃▃▄▄▅▅▅▆▆▇▇ 
           ▄▄▄▄▄▄▄▃                  ▆                                
         ◢◤  ▌ ◥◣\▁▁◣_                                                 
         ▃▅▂  ▂ ▇▆▅▃  ▆▅▄                             
LONG);
	setup();
	replace_program(ROOM);
}
