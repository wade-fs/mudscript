inherit ROOM;
void create() {
	set( "short", "CDROM的狩獵房" );
	set( "owner", "cdrom" );
	set( "object", ([
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount4"  : 1,
		"file2"    : "/open/snow/obj/stone",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount5"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file6"    : "/open/mogi/mountain/obj/frog-pill",
		"file10"   : "/open/capital/obj/book",
		"amount7"  : 1,
		"amount6"  : 2,
		"amount1"  : 114,
		"amount3"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/magic_palace/obj/magic_book",
		"file4"    : "/open/common/obj/liz_meat",
		"file1"    : "/open/mogi/dragon/obj/power",
		"amount10" : 1,
	]) );
	set( "build", 10047 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room237",
	]) );
	set( "long", @LONG

---------------------------------------------------------------
    焚天魔王人頭   7500兩黃金      獨孤嵊人頭    750兩黃金
    蛇郎君人頭     3000兩黃金    聖火教主林宏昇  750兩黃金
    黃金甲龍龍頭    650兩黃金          七魔將    500兩黃金
    黑白雙剎        600兩黃金    風林大頭目雷霸  200兩黃金  
    風林三頭目張繼   40兩黃金      二頭目劉信     60兩黃金
    黑風雙剎梅超風  120兩黃金       平南獨角獸    10兩黃金    
-------------------------------------------------------------
全力追殺者的人頭：千古恨1000把，殺意魔錐1000把，殺手密藥100顆，殺氣500
仙劍七子的人頭  ：轉換5點內力最大值，成為5點靈力最大值  
苗王    ：殺意魔錐1000把，殺氣100                    張淵    ：殺意魔錐1000把，殺氣100
完顏宏烈：定水珠一顆，殺意魔錐1000把，殺氣100        東瀛忍者：殺意魔錐1000把，殺手密藥25顆，殺氣100 
葉雙    ：幽冥系列的裝備一套，殺手密藥10顆，殺氣100  獨角獸  ：千古恨1000把，殺手密藥30顆，殺氣100
鳳姑    ：千古恨1000把，殺手密藥30顆，殺氣100        張繼    ：千年靈芝仙丹5 顆，殺氣200
劉信    ：千年靈芝仙丹5 顆，殺氣200                  雷霸    ：千年靈芝仙丹10顆，殺氣200
梅超風  ：殺手密藥100顆，殺氣300                     林宏昇  ：千古恨10000把，殺氣300
蛇郎君  ：噬魂手套一件，殺氣300                      黃金甲龍：六色龍元1顆，殺氣300
七魔將  ：聚靈丹15顆，殺氣300                        黑白雙剎：聚靈丹30顆，殺氣300
焚天魔王：烈燄手裏劍一把，殺氣300                    獨孤嵊  ：未定
---------------------------------------------------------------
LONG);
	setup();
	replace_program(ROOM);
}
