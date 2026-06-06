inherit ROOM;
void create() {
	set( "short", "$HIW$∮$HIR$刀塚$HIY$˙$HIG$卦棺$HIW$∮$NOR$" );
	set( "owner", "hild" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "item_desc", ([
		"blade" : @ITEM
 $HIR$只見刀身泛出陣陣血光，腥氣撲鼻......$NOR$

 $HIY$苹芃轉頭大喊: 「你這個莫名其妙的傢伙,來餵我的刀吧。
 $HIR$看來苹芃想殺死你﹗$NOR$


 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 
 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 
 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 
 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 
 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 
 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 
 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 
 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 
 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 
 $HIG$只見$NOR$苹芃$HIG$把$BLU$魔刀$HIG$與$HIY$金刀$HIG$的刀法融匯貫通，使出$NOR$$HIW$『$BLU$魔性$HIY$狂刀$HIR$斬$HIW$』$HIG$向妳狂劈而至。$NOR$
 ( 你$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ 



$HIR$你的眼前一黑﹐接著什麼也不知道了.... $NOR$
你死了


$RED$陰曹入口$NOR$  -
你已經來到了陰間的入口。雖然距離地府還有一段距離，但是你已經
感受到陣陣刺骨的陰風。四周一片荒涼，但是卻鬼影幢幢，看來這邊的夜
總會蠻熱鬧的，應該不愁沒伴。南邊和上面好像是和人世間相通的管道，
不過好像有一股無形的力量隔開這兩個不同的世界，看來要從這兩個方向
回去不是那麼簡單的事情。

這裡明顯的出口是 chome
ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room262",
	]) );
	set( "object", ([
		"amount3"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount10" : 1,
		"file3"    : "/open/firedancer/npc/eq/r_boots",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/firedancer/npc/eq/r_pants",
		"amount4"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_finger",
	]) );
	set( "build", 10054 );
	set( "long", @LONG
只見此地$HIG$陰氣$NOR$縈繞，無數$HIW$妖影$NOR$浮現...地面被刮出近千條$BLU$刀痕$NOR$
地上放著一個詭異的$YEL$棺木$NOR$..$HIB$妖氣$NOR$橫生...幾近將這個$BMAG$$BLU$空間$NOR$扭取
而苹芃的愛刀$HIR$罪$HIY$˙$HIR$狩$HIW$(Blade)$NOR$正平放在$YEL$棺$NOR$中...邪意的$HIG$綠光$NOR$四射，
好像正為你的闖進來而不悅...$HIR$刀身$NOR$$HIW$震顫$NOR$，暴射出刺眼$HIR$紅光$NOR$...
只見一個$HIG$青面$HIW$獠牙$NOR$的$HIW$妖邪$NOR$朝你衝來...手中$HIG$刀$NOR$朝你直劈而下....
來勢雖慢，但你覺得好像怎麼也避不了‧‧‧‧‧‧‧‧‧‧‧
LONG);
	setup();
	replace_program(ROOM);
}
