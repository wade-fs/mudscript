inherit ROOM;
void create() {
	set( "short", "$HIW$皇族禁兵庫$NOR$" );
	set( "owner", "empire" );
	set( "object", ([
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 1,
		"file3"    : "/open/mon/obj/mon-pill",
		"amount2"  : 1,
		"file6"    : "/obj/stone/suipian",
		"amount3"  : 4,
		"amount7"  : 5,
		"file7"    : "/obj/stone/jiao",
		"file5"    : "/obj/stone/powder",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/open/killer/obj/soul-hands",
		"amount9"  : 43,
		"amount6"  : 7,
		"amount5"  : 5,
		"file10"   : "/open/fire-hole/obj/b-pill",
		"amount10" : 5,
	]) );
	set( "build", 10140 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/dark-forest/room/room7",
	]) );
	set( "long", @LONG
這裡滿地散佈遠古時期由$YEL$西方皇族$NOR$所打造的神兵，其中最耀眼
的，莫過於面前這把劍。劍身上介於日月的花紋之間有著七枚$HIW$星辰$NOR$
，劍身上刻有許多帶著神秘力量的符文，它曾是$YEL$人皇$HIW$伊蘭迪爾$NOR$的配
劍--$HIB$『$HIM$納希爾聖劍$HIB$』$NOR$，不幸在與索倫的最後戰役中斷折。當聖劍重
鑄時，它發出刺眼的光芒，$RED$太陽$NOR$的符號隱隱閃出紅光，$HIW$月亮$NOR$則是發
出柔順的銀光，劍鋒顯得無比銳利。新生的$YEL$人皇$NOR$為這把聖劍命名為
$HIB$『$HIC$安都瑞爾x$HIR$西方之炎$HIB$』$NOR$。劍旁是人皇繼承人才有資格穿戴的皇冠
$HIB$『$HIW$伊蘭迪爾之星$HIB$』$NOR$，其他稀世神兵，如：$HIY$敵擊劍$NOR$、$HIB$獸咬劍$NOR$、$HIG$針刺$NOR$等
，亦散落一地，發出耀眼光芒。

LONG);
	setup();
	replace_program(ROOM);
}
