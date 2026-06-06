inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$HIW$臥$HIC$劍$HIW$居$NOR$" );
	set( "object", ([
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/fire-ball",
		"file1"    : "/open/magic-manor/obj/water-ball",
		"amount4"  : 1,
		"amount2"  : 14,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 1,
		"file6"    : "/open/killer/obj/soul-hands",
		"file7"    : "/open/magic-manor/obj/golden-ball",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10004 );
	set( "owner", "left" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room185",
	]) );
	set( "long", @LONG
                                                                                
                                             ☆    ╱    ☆                 
      多情黃昏伴人行　飄緲雲跡孤鴻雁    ╱                                  
      酒醉無眠心袂定　一夜江湖聽雨聲...               ╱      ★            
      自古英雄無留名　只留風雨滿愁城        ╱                                        
      歸去來　任東西　漂泊是無奈
      就算英雄絕代　山也不曾改          ☆       ○        ╱               
      情悲哀　 恨似海　心事無了解               /▊/\                       
      刀劍生涯                     ...        ◥███◤                   
      有現在　無未來                      ﹏ ﹏﹋ ﹏﹋﹋﹏ ﹏               

LONG);
	setup();
	replace_program(ROOM);
}
