inherit ROOM;
void create() {
	set( "short", "小豬頭的練氣房" );
	set( "owner", "pighead" );
	set( "object", ([
		"amount10" : 1,
		"file4"    : "/open/beggar/obj/feather",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/capital/obj/blade2",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10434 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room241",
	]) );
	set( "long", @LONG

             ◤ ◤                
        ▁▅◤    ▂▄▅▁▁▁▄▂
         ◢◢▁▄ ◢▇        ▇▅
        ◤◤   ▇                 
        ◢        ▁▁            
             ◤▁▃▄▃▂▆▅▄▂ 
        ◢◢▃                ▆▄
        ▕▍                      
        ▄▏▁▁                  
         ▍▄▅▅    ▃▅▄       
        ▊▏     ▂       ▄▂◥  
         ◣▃    ▄      ▁   ▇  
            ▅▅▄▅▄▄▂▄▆▆▆

LONG);
	setup();
	replace_program(ROOM);
}
