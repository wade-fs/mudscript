inherit ROOM;
void create() {
	set( "short", "女子宿舍的大門" );
	set( "owner", "djlh" );
	set( "object", ([
		"amount7"  : 1,
		"file5"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file3"    : "/open/magic-manor/obj/sun-heart",
		"file6"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file9"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"file10"   : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file8"    : "/open/capital/obj/blade2",
		"file7"    : "/open/ghost-hole/obj/dark-spirit",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10187 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room594.c",
		"enter"     : "/open/clan/13_luck/room/room663",
	]) );
	set( "long", @LONG

      Well I wonder could it be.   When I was dreaming `bout you baby           
      You were dreaming on me.     Call me crazy,call me blind.                 
      To still be suffering is stupid after all of this time                    
      Did I lose my love to someone better                                      
      And does she love you like I do. I do,you know I really really do         
      Well hey,So much I need to say,Been lonely since the day                  
                         The day you went away                                  
      So sad but true.For me there's only you.Been crying since the day         
                         The day you went away                                  
  I remember date and time.September twenty second Sunday twenty after nine     
      In the doorway with your case.No longer shouting at each other            
  There were tears on our faces.And we were letting go of something special     
      Something we'll never have again.I know,I guess I really really know      
      Why do we never know what we've got 'til it's gone                        
      How could I carry on  The day you went away     Sing by M2M               
      Cause I've been missing you so much I have to say                         
      Been crying since the day  The day you went away                         

LONG);
	setup();
	replace_program(ROOM);
}
