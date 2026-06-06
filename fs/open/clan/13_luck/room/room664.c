inherit ROOM;
void create() {
	set( "short", "廚房" );
	set( "object", ([
		"file9"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount4"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount7"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount5"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount9"  : 1,
	]) );
	set( "build", 10068 );
	set( "owner", "djlh" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room665",
		"east"      : "/open/clan/13_luck/room/room663",
		"south"     : "/open/clan/13_luck/room/room669",
	]) );
	set( "long", @LONG

我無法幫你預言‧委曲求全有沒有用‧可是我多麼不捨‧朋友愛的那麼苦痛‧愛可以不問  
對錯‧至少有喜悅感動‧如果他總為別人撐傘‧妳何苦非為他等在雨中‧泡咖啡讓妳暖手  
想擋擋妳心口裡的痛‧妳卻想上街走走‧吹吹冷風會清醒的多‧妳說妳不怕分手‧只有點  
遺憾難過‧情人節就要來了剩自己一個‧其實愛對了人情人節每天都過※※※※※※※※  
分手快樂‧祝妳快樂‧妳可以找到更好的‧    ╭═╮  ╭═╦╯╭╣╬╗╭╠═╗╮    
不想過冬‧厭倦沉重‧就飛去熱帶的島嶼游泳  ╭╯  ╰╮╭═╬╯║╠║║╠╠═╣╣  
分手快樂‧請妳快樂‧揮別錯的才能和對的相逢╯╦═╗╰╭═╬╯╯║╬╩╚╚╦╝╝  
離開舊愛‧像坐慢車‧看透車了心就會是晴朗的  ║  ║○    ║  ○║╠╮╰╦╬╦╯  
沒人能把誰的幸福沒收‧妳發誓妳會活的有笑容╰╯  ╯▲︽╰╯︽▲╯╯╰╰╯║╰╯  
※※※※※※※※※※※※※※※※※※※※※※※靜茹※※佩蓉※※嘉千※※ㄚ鳳※※  
  
  
LONG);
	setup();
	replace_program(ROOM);
}
