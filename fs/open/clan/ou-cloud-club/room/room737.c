inherit ROOM;
void create() {
	set( "short", "祈禱ソ間" );
	set( "object", ([
		"amount5"  : 182,
		"amount2"  : 340,
		"amount10" : 1,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file9"    : "/open/fire-hole/obj/w-pill",
		"amount6"  : 89,
		"amount8"  : 1,
		"file1"    : "/obj/stone/suipian",
		"file2"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file3"    : "/obj/stone/powder",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 45,
		"file5"    : "/open/fire-hole/obj/y-pill",
		"amount1"  : 12,
		"amount9"  : 83,
		"amount7"  : 186,
		"amount4"  : 338,
	]) );
	set( "build", 10633 );
	set( "light_up", 1 );
	set( "owner", "nafas" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room736",
	]) );
	set( "long", @LONG
                                                                                
        以絕整                                                                  
        那對的                                                                  
        飄的愛                                                                  
        風美與                                                                  
        、與殘                                                                  
        海相缺                                                                  
        水對的                                                                  
        、的即                                                                  
        塵可將                                                                  
        土拯被                                                                  
        構救宥                                                                  
        成的恕                                                                  
        的醜的                                                                  
        詩與恨                                                                  
        之卑。                                                                  
  －－－　　　                                                                  
  浩浩漫漫無邊廣大的和平，寧靜，超遠的同情和憐憫，自省。內斂，謙讓，退隱。      
        　　　－－－－－－－－－－－－－－－－－－－－－Soaring Spirit－－      
　　　　領下　                                                                  
        域，　                                                                  
        ，完　                                                                 


LONG);
	setup();
	replace_program(ROOM);
}
