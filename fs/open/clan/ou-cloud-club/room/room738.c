inherit ROOM;
void create() {
	set( "short", "流星ソ畔" );
	set( "object", ([
		"amount1"  : 1,
		"file6"    : "/open/capital/obj/4-2",
		"amount6"  : 1,
		"amount9"  : 3,
		"amount4"  : 107,
		"amount5"  : 1000,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/fire-hole/obj/k-pill",
		"file5"    : "/open/killer/obj/atman_pill",
		"amount2"  : 118,
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file4"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "build", 10063 );
	set( "light_up", 1 );
	set( "owner", "nano" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room773.c",
		"east"      : "/open/clan/ou-cloud-club/room/room736.c",
		"south"     : "/open/clan/ou-cloud-club/room/room772",
	]) );
	set( "long", @LONG

                                                                                
                                                                                
                 .                .                                     .       
             .                                .                                 
                         .                             （              .        
                      .        夏天。綠島。星沙。       .         .             
       .              .                .          .                  .          
          .                                            .                    .   
▁▂▂▁▂▁▂▂▃▂▁▁▂▂▃▃▂▂▂▁▁▁▂▂▂▁▁▂▃▃▂▂▃▂▁▂▁▂▃  
▁▂▂▁▂▁▂▂▃▂▁▁▂▂▃▃▂▂▂▁▁▁▂▂▁▂▁▂▂▁▁▂▁▃▂▁▁▂▂  
▁▁▂▂▁▂▁▂▂▃▂▁▁▂▂▃▃▂▂▂▁▁▁▂▂▁▂▁▂▂▃▃▂▂▂▁▁▂▁  
                                                                               
LONG);
	setup();
	replace_program(ROOM);
}
