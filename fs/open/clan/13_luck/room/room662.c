inherit ROOM;
void create() {
	set( "short", "二樓FF" );
	set( "owner", "djlh" );
	set( "object", ([
		"amount7"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount5"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount8"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount10" : 1,
	]) );
	set( "build", 22847 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room699.c",
		"south"     : "/open/clan/13_luck/room/room700.c",
		"east"      : "/open/clan/13_luck/room/room698.c",
		"north"     : "/open/clan/13_luck/room/room701",
		"down"      : "/open/clan/13_luck/room/room663.c",
	]) );
	set( "long", @LONG

              心有所繫  魂也有所牽  寂寞染不上我心田                            
                                                                                
              回憶說著 萬語千言    未來原是碧海藍天                            
                                                                                
              苦澀酸甜  都化作纏綿  悠悠盤旋成預言                              
                                                                                
              妳的呼吸  妳的眉眼    裹住我的冰心一片                            
                                                                                
              我的祝福  你該了解    妳是我最想還的願                            
                                                                                
              月有盈缺  而愛自成圓  總有一天再相見                              
                                                                                
              我的依戀  你該了解    靈犀相通心相連                              
                                                                                
              千山萬水  如千絲萬線  一張相思網  織得好密延                      
  
  
LONG);
	setup();
	replace_program(ROOM);
}
