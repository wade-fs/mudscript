inherit ROOM;
void create() {
	set( "short", "$HIY$月亮$HIC$惹的禍$NOR$" );
	set( "owner", "lts" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room450",
	]) );
	set( "long", @LONG


                               ‧            .                
              ‧       ☆        ‧                       
         ★          ‧         ·    ●                      
            ·            ★                ‧      
                    ◢               .                   
       ▇▆▄▃▂                                ▁▂▃▄▅▆▇
       ██████▇▆▆▅▄▄▄▃▃▄▄▆▆▇████████



LONG);
	setup();
	replace_program(ROOM);
}
