inherit ROOM;
void create() {
	set( "short", "藍夢組織總部" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file5"    : "/obj/gift/shenliwan",
		"amount1"  : 375,
		"file8"    : "/obj/stone/suipian",
		"amount8"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/obj/soil-ball",
		"file4"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/obj/golden-ball",
		"amount10" : 1,
		"amount4"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"file3"    : "/open/magic-manor/obj/fire-ball",
		"amount9"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/killer/obj/atman_pill",
		"file6"    : "/open/magic-manor/obj/wood-ball",
		"file7"    : "/open/magic-manor/obj/water-ball",
		"amount7"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10056 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room654",
		"north"     : "/open/clan/13_luck/room/room71.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
藍夢組織是十三吉祥裡最為神秘的一個集團, 暗中操縱著世界政經體系
的運作, 隨然僅僅是十三吉祥的一個支部, 然旗下會員三千多人, 遍布歐美,
個個都身懷異於常人的超級力量,尤其最頂級的幾個首腦人物, 更有鬼神般
的毀滅性力量, 可以自由操縱磁場, 改變大自然的定律. 然而, 這些都有同
樣的目標, 就是要重整這個混亂污穢的世界. 因此, 在最後審判到來之時, 
將會從宇宙軌道上降下天火, 毀滅所有生命, 使世界回復成為數億年前的
湛藍面貌, 實現藍色的夢想...
LONG);
	setup();
	replace_program(ROOM);
}
